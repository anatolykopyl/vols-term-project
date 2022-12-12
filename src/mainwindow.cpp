#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>

#include "fiberline.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_calc_clicked() {
  double kmAttenuation =
      ui->lineEdit_kmAttenuation->text().toDouble(); // 0.19 - 0.22

  double exitLvl = ui->lineEdit_exitLvl->text().toDouble();
  double recievedLvl = ui->lineEdit_recievedLvl->text().toDouble();
  uint connectionsCount = ui->lineEdit_connectionsCount->text().toUInt();
  double avgConnectionLoss =
      ui->lineEdit_avgConnectionLoss->text().toDouble();
  double avgSpliceLoss = ui->lineEdit_avgSpliceLoss->text().toDouble();
  double extraLoss = ui->lineEdit_extraLoss->text().toDouble();
  double systemBuffer = ui->lineEdit_systemBuffer->text().toDouble();
  double constructionLength =
      ui->lineEdit_constructionLength->text().toDouble();
  double spectralWidth = ui->lineEdit_spectralWidth->text().toDouble();

  FiberLine *fiberLine =
      new FiberLine(exitLvl, recievedLvl, connectionsCount, avgConnectionLoss,
                    extraLoss, systemBuffer, kmAttenuation, avgSpliceLoss,
                    constructionLength, spectralWidth);

  ui->lineEdit_resultAttenuation->setText(
      QString::number(fiberLine->lengthByAttenuation()));
  ui->lineEdit_resultDispersion->setText(
      QString::number(fiberLine->lengthByDispersion()));

  ui->lineEdit_result->setText(QString::number(std::min(fiberLine->lengthByAttenuation(), fiberLine->lengthByDispersion())));
}
