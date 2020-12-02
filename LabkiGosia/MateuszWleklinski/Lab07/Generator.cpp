
#include "headers.h"

Generator::Generator(int seed) 
{
  a = 444485709377909;
  x = seed;
  m = pow(2, 48);
  c = 0;
  /*
  print(a);
  print(x);
  print(m);
  */
}

void Generator::generate()
{
  //print(x * a + c);
  
  x = (x * a + c) % m;
  while (x < 0)
  {
    x = (x * a + c) % m;
  }
}

long int Generator::randint()
{
  generate();
  return x;
}

int Generator::randint(int range)
{
  generate();
  //print(x);
  return x % long(range);
}

double Generator::randfloat()
{
  generate();
  return x * double(x) / double(a);
}

double Generator::randfloat(double range)
{
  generate();
  return range * double(x) / double(a);
}