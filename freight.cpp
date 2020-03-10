#include "freight.h"

void Freight::setTransport(Transport transport)
{
  transport_ = transport;
}

QString Freight::freight()
{
  switch (transport_)
  {
    case Transport::AirPlane:
      return "Plane is ready";
    case Transport::Trucks:
      return "Truck is ready";
    case Transport::Ship:
      return "Ship is ready";
  }
}
