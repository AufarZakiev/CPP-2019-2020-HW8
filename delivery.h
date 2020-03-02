#ifndef DELIVERY_H
#define DELIVERY_H
#include "QString"
#include "continent.h"
#include "transport.h"
#include "freight.h"

class Price
{
public:
  virtual int getPice();

protected:
  int price_;
};

class Delivery : public Price, public Freight
{
  Continent from_;
  Continent to_;

public:
  void setFrom(Continent from);
  void setTo(Continent to);
  int getPice();
};

#endif  // DELIVERY_H
