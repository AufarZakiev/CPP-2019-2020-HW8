#include "delivery.h"

void ContinentDelivery::SetFrom(Continent from)
{
  _from = from;
}

void ContinentDelivery::SetTo(Continent to)
{
  _to = to;
}

void ContinentDelivery::SetTransport(Transport transport)
{
  _transport = transport;
}

QString ContinentDelivery::Freight()
{
  switch (_transport)
  {
    case Transport::Air:
      return "Plane is ready";
    case Transport::Sea:
      return "Ship is ready";
    case Transport::Ground:
      return "Truck is ready";
  }
  return "Undefined";
}

int ContinentDelivery::GetThePrice()
{
  if (_to == _from)
    _price = 0;
  else
    _price = (int(_to) * 100 + int(_from) * 10) * (1 + int(_transport));
  return _price;
}
int Delivery::GetThePrice()
{
  return _price;
}
