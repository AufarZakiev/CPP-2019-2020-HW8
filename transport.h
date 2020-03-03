#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <region.h>

namespace transport
{
enum Transports
{
  NULL_ = 0,
  SEA = 1,
  GROUND = 2,
  AIR = 3
};

class Transport
{
public:
  virtual QString getName() = 0;
  virtual int calculatePrice(region::Region* from, region::Region* to) = 0;
  virtual ~Transport()
  {
  }
};

class Sea : public Transport
{
public:
  QString getName()
  {
    return QString::fromStdString("Sea");
  }
  virtual int calculatePrice(region::Region* from, region::Region* to)
  {
    return (from->getRegionRadius() + to->getRegionRadius()) * 2;
  }
  ~Sea() = default;
};
class Ground : public Transport
{
public:
  QString getName()
  {
    return QString::fromStdString("Ground");
  }
  virtual int calculatePrice(region::Region* from, region::Region* to)
  {
    return (from->getRegionRadius() + to->getRegionRadius()) * 3;
  }
  ~Ground() = default;
};
class Air : public Transport
{
public:
  QString getName()
  {
    return QString::fromStdString("Air");
  }
  virtual int calculatePrice(region::Region* from, region::Region* to)
  {
    return (from->getRegionRadius() + to->getRegionRadius()) * 4;
  }
  ~Air() = default;
};

class TransportSetter
{
  Transport* transports[4];

public:
  TransportSetter()
  {
    transports[Transports::NULL_] = nullptr;
    transports[Transports::AIR] = new Air();
    transports[Transports::SEA] = new Sea();
    transports[Transports::GROUND] = new Ground();
  }

  ~TransportSetter()
  {
    for (int i = 0; i < 4; i++)
    {
      delete transports[i];
    }
  }

  Transport* getTransport(Transports arg)
  {
    return transports[arg];
  }

  Transport* getTransport(int arg)
  {
    return transports[arg];
  }
};
}

#endif  // TRANSPORT_H
