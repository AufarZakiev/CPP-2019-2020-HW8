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
  virtual QString getName()
  {
    return "-";
  }
  virtual int calculatePrice(region::Region& from, region::Region& to)
  {
    qDebug() << this->getName() << " " << from.getName() << " " << to.getName();
    return -1;
  }
  virtual ~Transport()
  {
  }

  virtual bool isValid()
  {
    return false;
  }
};

class Sea : public Transport
{
public:
  QString getName()
  {
    return QString::fromStdString("Sea");
  }
  virtual int calculatePrice(region::Region& from, region::Region& to)
  {
    qDebug() << this->getName() << " " << from.getName() << " " << to.getName();
    return (from.getRegionRadius() + to.getRegionRadius()) * 2;
  }
  ~Sea() = default;

  virtual bool isValid()
  {
    return true;
  }
};
class Ground : public Transport
{
public:
  QString getName()
  {
    return QString::fromStdString("Ground");
  }
  virtual int calculatePrice(region::Region& from, region::Region& to)
  {
    qDebug() << this->getName() << " " << from.getName() << " " << to.getName();
    return (from.getRegionRadius() + to.getRegionRadius()) * 3;
  }
  ~Ground() = default;

  virtual bool isValid()
  {
    return true;
  }
};
class Air : public Transport
{
public:
  QString getName()
  {
    return QString::fromStdString("Air");
  }
  virtual int calculatePrice(region::Region& from, region::Region& to)
  {
    qDebug() << this->getName() << " " << from.getName() << " " << to.getName();
    return (from.getRegionRadius() + to.getRegionRadius()) * 4;
  }
  ~Air() = default;

  virtual bool isValid()
  {
    return true;
  }
};

class TransportSetter
{
  Transport transports[4];

public:
  TransportSetter()
  {
    // not needed, but i'll leave it here just to be shuer i
    // didn't forget aboun "NULL"-value

    // transports[Transports::NULL_] = Transport();
    transports[Transports::AIR] = Air();
    transports[Transports::SEA] = Sea();
    transports[Transports::GROUND] = Ground();
  }

  ~TransportSetter()
  {
  }

  Transport& getTransport(Transports arg)
  {
    return transports[arg];
  }

  Transport& getTransport(int arg)
  {
    return transports[arg];
  }
};
}

#endif  // TRANSPORT_H
