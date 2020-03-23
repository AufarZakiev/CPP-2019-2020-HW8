#ifndef NEWTRANSFER_H
#define NEWTRANSFER_H

#include <exception>

#include <region.h>
#include <transport.h>

using namespace region;
using namespace transport;

class NewTransfer
{
  Regions to = Regions::NULL_;
  Regions from = Regions::NULL_;
  Transports transport = Transports::NULL_;

public:
  NewTransfer();
  void setTo(int index);
  void setFrom(int undex);
  void setTransport(int index);
  int getPrice();
  QString getInfo();
};

#endif  // NEWTRANSFER_H
