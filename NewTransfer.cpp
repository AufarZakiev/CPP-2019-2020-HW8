#include "NewTransfer.h"

NewTransfer::NewTransfer()
{
}

void NewTransfer::setTo(int index)
{
  this->to = (Regions)index;
}
void NewTransfer::setFrom(int index)
{
  this->from = (Regions)index;
}
void NewTransfer::setTransport(int index)
{
  this->transport = (Transports)index;
}

QString NewTransfer::getInfo()
{
  if (!to || !from || !transport)
    return "-";
  QString info = "From ";
  switch (from)
  {
    case Regions::ASIA:
      info += "Asia ";
      break;
    case Regions::AUSTRALIA:
      info += "Australia ";
      break;
    case Regions::AFRICA:
      info += "Africa ";
      break;
    case Regions::EUROPE:
      info += "Europe ";
      break;
    case Regions::SOUTH_AMERICA:
      info += "South America ";
      break;
    case Regions::NORTH_AMERICA:
      info += "South America ";
      break;
  }

  info += "to ";

  switch (to)
  {
    case Regions::ASIA:
      info += "Asia ";
      break;
    case Regions::AUSTRALIA:
      info += "Australia ";
      break;
    case Regions::AFRICA:
      info += "Africa ";
      break;
    case Regions::EUROPE:
      info += "Europe ";
      break;
    case Regions::SOUTH_AMERICA:
      info += "South America ";
      break;
    case Regions::NORTH_AMERICA:
      info += "South America ";
      break;
  }

  info += " by ";

  switch (transport)
  {
    case Transports::GROUND:
      info += "Ground ";
      break;
    case Transports::SEA:
      info += "SEA ";
      break;
    case Transports::AIR:
      info += "Air ";
      break;
  }
}

int NewTransfer::getPrice()
{
  return ((to + 1) - from) * transport;
}
