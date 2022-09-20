#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int lengthByAttenuation(
        double exitLvl,
        double recievedLvl,
        int connectionsCount,
        double avgConnectionLoss,
        double extraLoss,
        double systemBuffer,
        double kmAttenuation,
        double avgSpliceLoss,
        double constructionLength
)
{
    const double connectionsLoss = connectionsCount * avgConnectionLoss;
    const double spliceLoss = avgSpliceLoss / constructionLength;

    return (exitLvl - recievedLvl - connectionsLoss - extraLoss - systemBuffer)/(kmAttenuation + spliceLoss);
}

void MainWindow::on_pushButton_calc_clicked()
{ 
    const double kmAttenuation = 0.205; // 0.19 - 0.22

    double exitLvl = ui->lineEdit_exitLvl->text().toDouble();
    double recievedLvl = 1;
    int connectionsCount = 1;
    double avgConnectionLoss = 1;
    double avgSpliceLoss = 1;
    double extraLoss = 1;
    double systemBuffer = 1;
    double constructionLength = 100;

    lengthByAttenuation(
        exitLvl,
        recievedLvl,
        connectionsCount,
        avgConnectionLoss,
        extraLoss,
        systemBuffer,
        kmAttenuation,
        avgSpliceLoss,
        constructionLength
    );
}

