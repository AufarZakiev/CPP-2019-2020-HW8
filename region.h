#ifndef REGION_H
#define REGION_H
#include <QString>
#include <QDebug>

namespace region
{
enum Regions
{
  NULL_ = 0,
  AFRICA = 5,
  ASIA = 1,
  AUSTRALIA = 6,
  EUROPE = 2,
  NORTH_AMERICA = 3,
  SOUTH_AMERICA = 4
};

class Region
{
public:
  virtual QString getName()
  {
    return "-";
  }
  virtual int getRegionRadius()
  {
    return -1;
  }
  virtual ~Region()
  {
  }

  virtual bool isValid()
  {
    return false;
  }
};

class Asia : public Region
{
public:
  Asia()
  {
  }
  QString getName()
  {
    return QString::fromStdString("Asia");
  }
  int getRegionRadius()
  {
    return 12;
  }
  ~Asia()
  {
  }

  virtual bool isValid()
  {
    return true;
  }
};

class Africa : public Region
{
public:
  Africa()
  {
  }
  QString getName()
  {
    return QString::fromStdString("Africa");
  }
  int getRegionRadius()
  {
    return 10;
  }
  ~Africa()
  {
  }

  virtual bool isValid()
  {
    return true;
  }
};

class Australia : public Region
{
public:
  Australia()
  {
  }
  QString getName()
  {
    return QString::fromStdString("Australia");
  }
  int getRegionRadius()
  {
    return 4;
  }
  ~Australia()
  {
  }

  virtual bool isValid()
  {
    return true;
  }
};

class Europe : public Region
{
public:
  Europe()
  {
  }
  QString getName()
  {
    return QString::fromStdString("Europe");
  }
  int getRegionRadius()
  {
    return 3;
  }
  ~Europe()
  {
  }

  virtual bool isValid()
  {
    return true;
  }
};

class SouthAmerica : public Region
{
public:
  SouthAmerica()
  {
  }
  QString getName()
  {
    return QString::fromStdString("South America");
  }
  int getRegionRadius()
  {
    return 5;
  }
  ~SouthAmerica()
  {
  }

  virtual bool isValid()
  {
    return true;
  }
};

class NorthAmerica : public Region
{
public:
  NorthAmerica()
  {
  }
  QString getName()
  {
    return QString::fromStdString("North America");
  }
  int getRegionRadius()
  {
    return 6;
  }
  ~NorthAmerica()
  {
  }

  virtual bool isValid()
  {
    return true;
  }
};

class RegionSetter
{
  Region regions[7];

public:
  RegionSetter()
  {
    regions[Regions::AFRICA] = Africa();
    regions[Regions::ASIA] = Asia();
    regions[Regions::AUSTRALIA] = Australia();
    regions[Regions::EUROPE] = Europe();
    regions[Regions::NORTH_AMERICA] = NorthAmerica();
    regions[Regions::SOUTH_AMERICA] = SouthAmerica();
    // regions[Regions::NULL_] = Region();
    // it's already had been initialized as Region(), but just for...
  }

  Region& getRegion(Regions arg)
  {
    return regions[arg];
  }
  Region& getRegion(int arg)
  {
    return regions[arg];
  }

  ~RegionSetter()
  {
  }
};
}

#endif  // REGION_H
