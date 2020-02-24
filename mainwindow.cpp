#include "mainwindow.h"
#include <QDebug>
#include <memory>
#include "Areas.h"
#include "DeliveryEnums.h"
#include "ui_mainwindow.h"

static std::vector<std::shared_ptr<IValuable>> area;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  area.push_back(std::shared_ptr<IValuable>(new Asia()));
  area.push_back(std::shared_ptr<IValuable>(new Europe()));
  area.push_back(std::shared_ptr<IValuable>(new NorthAmerica()));
  area.push_back(std::shared_ptr<IValuable>(new SouthAmerica()));
  area.push_back(std::shared_ptr<IValuable>(new Africa()));
  area.push_back(std::shared_ptr<IValuable>(new Australia()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

class Delivery
{
  std::shared_ptr<IValuable> _from;
  std::shared_ptr<IValuable> _to;
  const Transport& _transport;

public:
  Delivery(std::shared_ptr<IValuable> from, std::shared_ptr<IValuable> to, Transport& transport)
    : _from(from), _to(to), _transport(transport)
  {
  }

  int GetThePrice()
  {
    return (_to->GetValue() + _from->GetValue()) * (1 + int(_transport));
  }
};

void MainWindow::on_PricePushButton_clicked()
{
  auto to = area.at(size_t(ui->ToComboBox->currentIndex()));
  auto from = area.at(size_t(ui->FromComboBox->currentIndex()));
  auto transport = Transport(ui->TransportComboBox->currentIndex());

  auto delivery = Delivery(from, to, transport);

  if (ui->FromComboBox->currentIndex() == ui->ToComboBox->currentIndex())
    ui->PriceLabel->setNum(0);
  else
    ui->PriceLabel->setNum(delivery.GetThePrice());
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
