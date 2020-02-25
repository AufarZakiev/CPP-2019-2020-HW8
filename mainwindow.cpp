#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "delivery.h"
#include "DeliveryEnums.h"
#include <QDebug>
#include <memory>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

static ContinentDelivery delivery;

void MainWindow::on_PricePushButton_clicked()
{
  delivery.SetFrom(Continent(ui->FromComboBox->currentIndex()));
  delivery.SetTo(Continent(ui->ToComboBox->currentIndex()));
  delivery.SetTransport(Transport(ui->TransportComboBox->currentIndex()));

  ui->PriceLabel->setNum(delivery.GetThePrice());
}

void MainWindow::on_FreightPushButton_clicked()
{
  delivery.SetTransport(Transport(ui->TransportComboBox->currentIndex()));

  ui->FreightLabel->setText(delivery.Freight());
}
