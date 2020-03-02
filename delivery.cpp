#include "delivery.h"

void Delivery::setFrom(Continent from)
{
  from_ = from;
}

void Delivery::setTo(Continent to)
{
  to_ = to;
}

void Delivery::setTransport(Transport transport)
{
  transport_ = transport;
}

int Delivery::getPice()
{
  if (from_ == to_)
    price_ = 0;
  else
    price_ = (((int)from_ + 1) * 5 + ((int)to_ + 1) * 2) * ((int)transport_ + 1);
  return price_;
}

int Price::getPice()
{
  return price_;
}

QString Delivery::freight()
{
  switch (transport_)
  {
    case Transport::Ground:
      return "Truck is ready";
    case Transport::Sea:
      return "Ship is ready";
    case Transport::Air:
      return "Plane is ready";
  }
}
