#ifndef REGION_H
#define REGION_H
#include <QString>

namespace region {
enum Regions {
  NULL_ = 0,
  AFRICA = 5,
  ASIA = 1,
  AUSTRALIA = 6,
  EUROPE = 2,
  NORTH_AMERICA = 3,
  SOUTH_AMERICA = 4
};

class Region {
public:
  virtual QString getName() = 0;
  virtual int getRegionRadius() = 0;
  virtual ~Region() {}
};

class Asia : public Region {
public:
  Asia() {}
  QString getName() { return QString::fromStdString("Asia"); }
  int getRegionRadius() { return 12; }
  ~Asia() {}
};

class Africa : public Region {
public:
  Africa() {}
  QString getName() { return QString::fromStdString("Africa"); }
  int getRegionRadius() { return 10; }
  ~Africa() {}
};

class Australia : public Region {
public:
  Australia() {}
  QString getName() { return QString::fromStdString("Australia"); }
  int getRegionRadius() { return 4; }
  ~Australia() {}
};

class Europe : public Region {
public:
  Europe() {}
  QString getName() { return QString::fromStdString("Europe"); }
  int getRegionRadius() { return 3; }
  ~Europe() {}
};

class SouthAmerica : public Region {
public:
  SouthAmerica() {}
  QString getName() { return QString::fromStdString("South America"); }
  int getRegionRadius() { return 5; }
  ~SouthAmerica() {}
};

class NorthAmerica : public Region {
public:
  NorthAmerica() {}
  QString getName() { return QString::fromStdString("North America"); }
  int getRegionRadius() { return 6; }
  ~NorthAmerica() {}
};

class RegionSetter {
  Region *regions[7];

public:
  RegionSetter() {
    regions[Regions::AFRICA] = new Africa();
    regions[Regions::ASIA] = new Asia();
    regions[Regions::AUSTRALIA] = new Australia();
    regions[Regions::EUROPE] = new Europe();
    regions[Regions::NORTH_AMERICA] = new NorthAmerica();
    regions[Regions::SOUTH_AMERICA] = new SouthAmerica();
    regions[Regions::NULL_] = nullptr;
  }

  Region *getRegion(Regions arg) { return regions[arg]; }
  Region *getRegion(int arg) { return regions[arg]; }

  ~RegionSetter() {
    for (int i = 0; i < 7; i++)
      delete regions[i];
  }
};
}

#endif // REGION_H
