#ifndef AREAS_H
#define AREAS_H

struct IValuable
{
  virtual int GetValue() = 0;

protected:
  virtual ~IValuable() = default;
};

struct Asia : public IValuable
{
  int GetValue();
};

struct Europe : public IValuable
{
  int GetValue();
};

struct NorthAmerica : public IValuable
{
  int GetValue();
};

struct SouthAmerica : public IValuable
{
  int GetValue();
};

struct Africa : public IValuable
{
  int GetValue();
};

struct Australia : public IValuable
{
  int GetValue();
};

#endif  // AREAS_H
