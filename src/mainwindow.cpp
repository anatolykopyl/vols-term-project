#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

int lengthByAttenuation(double exitLvl, double recievedLvl,
                        int connectionsCount, double avgConnectionLoss,
                        double extraLoss, double systemBuffer,
                        double kmAttenuation, double avgSpliceLoss,
                        double constructionLength) {
  const double connectionsLoss = connectionsCount * avgConnectionLoss;
  const double spliceLoss = avgSpliceLoss / constructionLength;

  return (exitLvl - recievedLvl - connectionsLoss - extraLoss - systemBuffer) /
         (kmAttenuation + spliceLoss);
}

void MainWindow::on_pushButton_calc_clicked() {
  const double kmAttenuation =
      ui->lineEdit_kmAttenuation->text().toDouble(); // 0.19 - 0.22

  const double exitLvl = ui->lineEdit_exitLvl->text().toDouble();
  const double recievedLvl = ui->lineEdit_recievedLvl->text().toDouble();
  const uint connectionsCount = ui->lineEdit_connectionsCount->text().toUInt();
  const double avgConnectionLoss =
      ui->lineEdit_avgConnectionLoss->text().toDouble();
  const double avgSpliceLoss = ui->lineEdit_avgSpliceLoss->text().toDouble();
  const double extraLoss = ui->lineEdit_extraLoss->text().toDouble();
  const double systemBuffer = ui->lineEdit_systemBuffer->text().toDouble();
  const double constructionLength =
      ui->lineEdit_constructionLength->text().toDouble();

  const double result = lengthByAttenuation(
      exitLvl, recievedLvl, connectionsCount, avgConnectionLoss, extraLoss,
      systemBuffer, kmAttenuation, avgSpliceLoss, constructionLength);

  ui->lineEdit_result->setText(QString::number(result));
}
