#include "delivery.h"
#include "freight.h"

void Delivery::setDeparture(Continent departure)
{
  departure_ = departure;
}

void Delivery::setDestination(Continent destination)
{
  destination_ = destination;
}

int Delivery::getPice()
{
  if (departure_ == destination_)
    price_ = 0;
  else
    price_ = (((int)departure_ + 1) * 200 + ((int)destination_ + 1) * 3000) * ((int)Freight::transport_ + 1);
  return price_;
}

int Price::getPice()
{
  return price_;
}
