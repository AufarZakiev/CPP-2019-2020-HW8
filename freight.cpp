#include "freight.h"

QString Freight::freight()
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

void Freight::setTransport(Transport transport)
{
  transport_ = transport;
}
