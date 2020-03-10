#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include "delivery.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

static Delivery delivery;

void MainWindow::on_calculatePushButton_clicked()
{
  delivery.setDeparture(Continent(ui->fromComboBox->currentIndex()));
  delivery.setDestination(Continent(ui->toComboBox->currentIndex()));
  delivery.setTransport(Transport(ui->transportComboBox->currentIndex()));

  auto res = delivery.getPice();
  ui->priceLabel->setNum(res);
}

void MainWindow::on_freightPushButton_clicked()
{
  ui->statusLabel->setText(delivery.freight());
}
