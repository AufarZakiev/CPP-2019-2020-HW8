#include "freight.h"
#include "enums.h"
#include <QString>
#include <QDebug>

void Options::SetContinentFrom(Continent from)
{
  from_ = from;
}

void Options::SetContinentTo(Continent to)
{
  to_ = to;
}

void Options::SetTransport(Transport transport)
{
  transport_ = transport;
}

int Options::GetPrice()
{
  if (from_ == to_)
    price_ = 0;
  else
    price_ = (((int)from_ + (int)to_ + 10) * 3 + 11) + (int)transport_;
  return price_;
}

QString Options::SetFreight()
{
  switch (transport_)
  {
    case Transport::Air:
      return "Plane is ready!";
    case Transport::Sea:
      return "Ship is ready!";
    case Transport::Ground:
      return "Truck is ready!";
  }
}
