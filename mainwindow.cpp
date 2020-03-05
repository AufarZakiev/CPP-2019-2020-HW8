#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <qstring.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  trf = new Transfer();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_FromComboBox_currentIndexChanged(int index) {
  qDebug() << index;
  trf->updateFrom(index);
}

void MainWindow::on_TransportComboBox_currentIndexChanged(int index) {
  qDebug() << index;
  trf->updateTransport(index);
}

void MainWindow::on_ToComboBox_currentIndexChanged(int index) {
  qDebug() << index;
  trf->updateTo(index);
}

void MainWindow::on_PricePushButton_clicked() {
  ui->PriceLabel->setNum(trf->getPrice());
}
