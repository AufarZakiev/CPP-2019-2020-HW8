#ifndef REGION_H
#define REGION_H
#include <QString>
#include <QDebug>

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
<<<<<<< HEAD
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
=======
  virtual QString getName() = 0;
  virtual int getRegionRadius() = 0;
  virtual ~Region() {}
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
};

class Asia : public Region {
public:
<<<<<<< HEAD
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
=======
  Asia() {}
  QString getName() { return QString::fromStdString("Asia"); }
  int getRegionRadius() { return 12; }
  ~Asia() {}
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
};

class Africa : public Region {
public:
<<<<<<< HEAD
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
=======
  Africa() {}
  QString getName() { return QString::fromStdString("Africa"); }
  int getRegionRadius() { return 10; }
  ~Africa() {}
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
};

class Australia : public Region {
public:
<<<<<<< HEAD
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
=======
  Australia() {}
  QString getName() { return QString::fromStdString("Australia"); }
  int getRegionRadius() { return 4; }
  ~Australia() {}
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
};

class Europe : public Region {
public:
<<<<<<< HEAD
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
=======
  Europe() {}
  QString getName() { return QString::fromStdString("Europe"); }
  int getRegionRadius() { return 3; }
  ~Europe() {}
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
};

class SouthAmerica : public Region {
public:
<<<<<<< HEAD
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
=======
  SouthAmerica() {}
  QString getName() { return QString::fromStdString("South America"); }
  int getRegionRadius() { return 5; }
  ~SouthAmerica() {}
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
};

class NorthAmerica : public Region {
public:
<<<<<<< HEAD
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
=======
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
>>>>>>> 02db93341ff37e9ac16ec4a631b6c4b26cc1e686
  }
};
}

#endif // REGION_H
