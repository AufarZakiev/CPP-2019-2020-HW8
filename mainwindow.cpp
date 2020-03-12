#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "freight.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

void MainWindow::on_CalcPushButton_clicked()
{
  freight.SetContinentFrom(Continent(ui->FromComboBox->currentIndex()));
  freight.SetTransport(Transport(ui->TransportComboBox->currentIndex()));
  freight.SetContinentTo(Continent(ui->ToComboBox->currentIndex()));

  ui->PriceShowLabel->setNum(freight.GetPrice());
}

void MainWindow::on_FreightPushButton_clicked()
{
  freight.SetTransport(Transport(ui->TransportComboBox->currentIndex()));

  ui->FreightShowLabel->setText(freight.SetFreight());
}

MainWindow::~MainWindow()
{
  delete ui;
}
