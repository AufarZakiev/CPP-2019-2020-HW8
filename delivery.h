#ifndef DELIVERY_H
#define DELIVERY_H
#include "QString"
#include "Continent.h"
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
  Continent departure_;
  Continent destination_;

public:
  void setDeparture(Continent from);
  void setDestination(Continent to);
  int getPice();
};

#endif  // DELIVERY_H
