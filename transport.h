#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <region.h>

namespace transport {
enum Transports { NULL_ = 0, SEA = 1, GROUND = 2, AIR = 3 };

class Transport {
public:
<<<<<<< HEAD
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
=======
  virtual QString getName() = 0;
  virtual int calculatePrice(region::Region *from, region::Region *to) = 0;
  virtual ~Transport() {}
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
};

class Sea : public Transport {
public:
<<<<<<< HEAD
  QString getName()
  {
    return QString::fromStdString("Sea");
  }
  virtual int calculatePrice(region::Region& from, region::Region& to)
  {
    qDebug() << this->getName() << " " << from.getName() << " " << to.getName();
    return (from.getRegionRadius() + to.getRegionRadius()) * 2;
=======
  QString getName() { return QString::fromStdString("Sea"); }
  virtual int calculatePrice(region::Region *from, region::Region *to) {
    return (from->getRegionRadius() + to->getRegionRadius()) * 2;
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
  }
  ~Sea() = default;

  virtual bool isValid()
  {
    return true;
  }
};
class Ground : public Transport {
public:
<<<<<<< HEAD
  QString getName()
  {
    return QString::fromStdString("Ground");
  }
  virtual int calculatePrice(region::Region& from, region::Region& to)
  {
    qDebug() << this->getName() << " " << from.getName() << " " << to.getName();
    return (from.getRegionRadius() + to.getRegionRadius()) * 3;
=======
  QString getName() { return QString::fromStdString("Ground"); }
  virtual int calculatePrice(region::Region *from, region::Region *to) {
    return (from->getRegionRadius() + to->getRegionRadius()) * 3;
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
  }
  ~Ground() = default;

  virtual bool isValid()
  {
    return true;
  }
};
class Air : public Transport {
public:
<<<<<<< HEAD
  QString getName()
  {
    return QString::fromStdString("Air");
  }
  virtual int calculatePrice(region::Region& from, region::Region& to)
  {
    qDebug() << this->getName() << " " << from.getName() << " " << to.getName();
    return (from.getRegionRadius() + to.getRegionRadius()) * 4;
=======
  QString getName() { return QString::fromStdString("Air"); }
  virtual int calculatePrice(region::Region *from, region::Region *to) {
    return (from->getRegionRadius() + to->getRegionRadius()) * 4;
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
  }
  ~Air() = default;

  virtual bool isValid()
  {
    return true;
  }
};

<<<<<<< HEAD
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
=======
class TransportSetter {
  Transport *transports[4];

public:
  TransportSetter() {
    transports[Transports::NULL_] = nullptr;
    transports[Transports::AIR] = new Air();
    transports[Transports::SEA] = new Sea();
    transports[Transports::GROUND] = new Ground();
  }

  ~TransportSetter() {
    for (int i = 0; i < 4; i++) {
      delete transports[i];
    }
  }

  Transport *getTransport(Transports arg) { return transports[arg]; }

  Transport *getTransport(int arg) { return transports[arg]; }
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
};
}

#endif // TRANSPORT_H
