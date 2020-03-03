#ifndef TRANSFER_H
#define TRANSFER_H
#include <transport.h>
#include <QString>
#include <QtDebug>

class Transfer
{
  transport::TransportSetter trs;
  region::RegionSetter rgs;
  region::Region* from = nullptr;
  region::Region* to = nullptr;
  transport::Transport* transport = nullptr;

public:
  Transfer()
  {
    trs = transport::TransportSetter();
    rgs = region::RegionSetter();
  };
  ~Transfer()
  {
    delete from;
    delete to;
    delete transport;
  }

  void updateFrom(int arg)
  {
    from = rgs.getRegion(arg);
  }

  void updateTo(int arg)
  {
    to = rgs.getRegion(arg);
  }

  void updateTransport(int arg)
  {
    transport = trs.getTransport(arg);
  }

  void updateFrom(region::Regions arg)
  {
    from = rgs.getRegion(arg);
  }

  void updateTo(region::Regions arg)
  {
    to = rgs.getRegion(arg);
  }

  void updateTransport(region::Regions arg)
  {
    transport = trs.getTransport(arg);
  }

  QString getTransferInf()
  {
    QString response = "From " + from->getName() + " to " + to->getName() + " by " + transport->getName() +
                       ". Price: " + QString::number(transport->calculatePrice(from, to));
    return response;
  }

  int getPrice()
  {
    qDebug() << transport << " " << from << " " << to;
    if (transport && from && to)
    {
      return transport->calculatePrice(from, to);
    }
    return 0;
  }
};

#endif  // TRANSFER_H
