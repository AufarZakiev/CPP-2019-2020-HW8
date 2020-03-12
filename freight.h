#ifndef FREIGHT_H
#define FREIGHT_H
#include "enums.h"
#include <QString>

class Freight
{
public:
  virtual int GetPrice() = 0;
  virtual QString SetFreight() = 0;

protected:
  int price_;
  virtual ~Freight() = default;
};

class Options : public Freight
{
public:
  int GetPrice();
  QString SetFreight();
  void SetContinentFrom(Continent from);
  void SetContinentTo(Continent to);
  void SetTransport(Transport transport);

protected:
  Continent from_;
  Continent to_;
  Transport transport_;
};

#endif  // FREIGHT_H
