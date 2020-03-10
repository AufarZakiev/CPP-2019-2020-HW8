#ifndef FREIGHT_H
#define FREIGHT_H
#include "transport.h"
#include "QString"

class Freight
{
protected:
  Transport transport_;

public:
  QString freight();
  void setTransport(Transport transport);
};

#endif  // FREIGHT_H
