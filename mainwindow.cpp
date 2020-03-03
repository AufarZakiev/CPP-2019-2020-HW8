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

void MainWindow::on_calculatePushButton_clicked()
{
  delivery.setFrom(Continent(ui->fromComboBox->currentIndex()));
  delivery.setTo(Continent(ui->toComboBox->currentIndex()));
  delivery.setTransport(Transport(ui->transportComboBox->currentIndex()));

  ui->priceLabel->setNum(delivery.getPrice());
}

void MainWindow::on_freightPushButton_clicked()
{
  ui->statusLabel->setText(delivery.freight());
}
