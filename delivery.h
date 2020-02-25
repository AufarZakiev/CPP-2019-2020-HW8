#ifndef DELIVERY_H
#define DELIVERY_H
#include <QtWidgets>
#include "DeliveryEnums.h"

class Delivery
{
public:
  virtual int GetThePrice();

  virtual QString Freight() = 0;

protected:
  int _price;
  virtual ~Delivery() = default;
};

class ContinentDelivery : public Delivery
{
  Continent _from;
  Continent _to;
  Transport _transport;

public:
  void SetFrom(Continent from);

  void SetTo(Continent to);

  void SetTransport(Transport transport);

  int GetThePrice();

  QString Freight();
};

#endif  // DELIVERY_H
