#include "headers"


// Exercise 1a
bool isPrime(int num)
{
  for (int i = 2; i <= sqrt(num); i++)
  {
    if (num % i == 0)
      return false;
  }
  return true;
}


void writePrimeNumbers(int range)
{ 
  for (int i = 2; i < range; i++)
  {
    if (isPrime(i))
      std::cout << "prime number: " << i << std::endl;
  }
    
    
}

//Exercise 1b

void Eratosthenes(int num)
{
  int tab[num-2];
  for (int i = 2; i <= num; i++)
  {
    tab[i-2] = i;
    // std::cout << i << std::endl;
  }
    

  int multiple = 2;
  bool end = false;

  while (!end)
  {
    for (int p = multiple * 2; p < num; p += multiple)
    {
        for (int i = 0; i < num-2; i++)
        {
          if (tab[i] == p)
            tab[i] = 0; // let zero be non-primes
        }
    }
    for (int i: tab)
    {
      if (i > multiple)
      {
        multiple = i;
        // std::cout << multiple << std::endl;
        break;
      }
      else if (i == tab[num-3])
        end = true;
    }

  if (end)
  {
  for (int i: tab)
        {
          if (i != 0)
            std::cout << "prime number: " << i << std::endl;
        }
        return;
  }
  }
}


// Exercise 1c

void linear_sieve(int num)
{
  int primes[num-2];
  for (int i=2;i <=num; i++)
  {
    primes[i-2] = i;
  }
  int p = 2;
  while (p * p <= num)
  {
    int q = p;
    while (p * q <= num)
    {
      int x = p * q;
      while (x <= num)
      {
        primes[table_index(&primes[0], num-2, x)] = 0;
        x = p * x;
      }
      int idx = table_index(&primes[0], num-2, q);

      do idx++;
      while(primes[idx] == 0);

      q = primes[idx];
    }
    int idx = table_index(&primes[0], num-2, p);

    do idx++; 
    while(primes[idx] == 0);
      
    p = primes[idx];
  }
  for (int i: primes)
  {
    if (i != 0)
      std::cout << "prime number: " << i << std::endl;
  }
}

int table_index(int *tab, int range, int value)
{
  for (int i=0; i < range; i++)
  {
    if (*(tab+i) == value)
    {
      return i;
    }
  }
  return -1;
}

// Exercise 2:
double integral(double a, double b, double dx)
{
  double output = 0;
  for (double i = a; i < b; i += dx)
  {
    output += (f(i) + f(i+dx)) * dx / 2;
  }
  return output;
}

double f(double x)
{
  return pow(x, 3) - pow(x, 2) + 24;
}