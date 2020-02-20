#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

enum class Destination
{
  Asia = 0,
  Europe,
  NorthAmerica,
  SouthAmerica,
  Africa,
  Australia
};

enum class Transport
{
  Sea = 0,
  Ground,
  Air
};

void MainWindow::on_PricePushButton_clicked()
{
  auto to = Destination(ui->FromComboBox->currentIndex());
  auto from = Destination(ui->ToComboBox->currentIndex());
  auto transport = Transport(ui->TransportComboBox->currentIndex());

  if (from == to)
    ui->PriceLabel->setNum(0);
  else
  {
    // allsolvingformula
    auto price = (int(to) * 10 + int(from) * 10) * (1 + int(transport));
    ui->PriceLabel->setNum(price);
  }
}

void MainWindow::on_FreightPushButton_clicked()
{
  switch (Transport(ui->TransportComboBox->currentIndex()))
  {
    case Transport::Air:
      ui->FreightLabel->setText("Plane is ready");
      break;
    case Transport::Sea:
      ui->FreightLabel->setText("Ship is ready");
      break;
    case Transport::Ground:
      ui->FreightLabel->setText("Truck is ready");
      break;
  }
}
