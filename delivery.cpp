#include "delivery.h"
#include "freight.h"

void Delivery::setFrom(Continent from)
{
  from_ = from;
}

void Delivery::setTo(Continent to)
{
  to_ = to;
}

int Delivery::getPice()
{
  if (from_ == to_)
    price_ = 0;
  else
    price_ = (((int)from_ + 1) * 5 + ((int)to_ + 1) * 2) * ((int)Freight::transport_ + 1);
  return price_;
}

int Price::getPice()
{
  return price_;
}
