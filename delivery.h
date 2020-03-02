#ifndef DELIVERY_H
#define DELIVERY_H
#include "QString"
#include "continent.h"
#include "transport.h"

class Price
{
public:
  virtual int getPice();

protected:
  int price_;
};

class Delivery : public Price
{
  Continent from_;
  Continent to_;
  Transport transport_;

public:
  void setFrom(Continent from);
  void setTo(Continent to);
  void setTransport(Transport transport);
  int getPice();
  QString freight();
};

#endif  // DELIVERY_H
