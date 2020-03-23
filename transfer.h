#ifndef TRANSFER_H
#define TRANSFER_H
#include <QString>
#include <QtDebug>
#include <transport.h>

class Transfer {
  transport::TransportSetter trs;
  region::RegionSetter rgs;
<<<<<<< HEAD
  region::Region from;
  region::Region to;
  transport::Transport transport;
=======
  region::Region *from = nullptr;
  region::Region *to = nullptr;
  transport::Transport *transport = nullptr;
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686

public:
  Transfer() {
    trs = transport::TransportSetter();
    rgs = region::RegionSetter();
  }
<<<<<<< HEAD
  ~Transfer()
  {
=======
  ~Transfer() {
    delete from;
    delete to;
    delete transport;
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
  }

  void updateFrom(int arg) { from = rgs.getRegion(arg); }

  void updateTo(int arg) { to = rgs.getRegion(arg); }

  void updateTransport(int arg) { transport = trs.getTransport(arg); }

  void updateFrom(region::Regions arg) { from = rgs.getRegion(arg); }

  void updateTo(region::Regions arg) { to = rgs.getRegion(arg); }

  void updateTransport(region::Regions arg) {
    transport = trs.getTransport(arg);
  }

<<<<<<< HEAD
  QString getTransferInf()
  {
    QString response = "From " + from.getName() + " to " + to.getName() + " by " + transport.getName() + ". Price: " +
                       QString::number(transport.calculatePrice(from, to));
    return response;
  }

  bool isDataValid(transport::Transport& transport, region::Region& from, region::Region& to)
  {
    return transport.isValid() && from.isValid() && to.isValid();
  }

  int getPrice()
  {
    // qDebug() << transport.getName() << " " << from.getName() << " " << to.getName();
    if (this->isDataValid(transport, from, to))
    {
      return transport.calculatePrice(from, to);
=======
  QString getTransferInf() {
    QString response = "From " + from->getName() + " to " + to->getName() +
                       " by " + transport->getName() + ". Price: " +
                       QString::number(transport->calculatePrice(from, to));
    return response;
  }

  int getPrice() {
    qDebug() << transport << " " << from << " " << to;
    if (transport && from && to) {
      return transport->calculatePrice(from, to);
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
    }
    return 0;
  }
};

#endif // TRANSFER_H
