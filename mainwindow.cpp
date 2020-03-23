#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <qstring.h>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_FromComboBox_currentIndexChanged(int index)
{
  qDebug() << index;
  tra.setFrom(index);
}

void MainWindow::on_TransportComboBox_currentIndexChanged(int index)
{
  qDebug() << index;
  tra.setTransport(index);
}

void MainWindow::on_ToComboBox_currentIndexChanged(int index)
{
  qDebug() << index;
  tra.setTo(index);
}

void MainWindow::on_PricePushButton_clicked()
{
  ui->PriceLabel->setNum(tra.getPrice());
}
