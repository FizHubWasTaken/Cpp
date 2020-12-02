#include "headers.h"

void histogram(int number, int range)
{
  Generator rand(SEED);
  std::vector<int> n, m;
  for (int i = 0; i < number; i++)
  {
    long int n0 = rand.randint();
    int m0 = rand.randint(range);
    n.push_back(len(n0));
    m.push_back(len(m0));
    if (i == 2) print(m0);
  }
  //print(m[2]);

  print("number of digits with max range: ");
  printHist(n);
  print("\nnumber of digits in range(0, ", "");
  print(range, "):\n");
  printHist(m);
}

void numbersSquare(int n, double range)
{
  Generator rand(SEED);
  std::vector<double> x, y;
  for (int i = 0; i < n; i++)
  {
    x.push_back(rand.randfloat(range));
    y.push_back(rand.randfloat(range));
  }

  for (int i = 1; i <= 10; i++ )
  {
    print("percentage of points in a square of a side: ", "");
    print(i, " is: ");
    print(percent(x, y, i), "%\n");
  }

  print("pi: ", "");
  print(piValue(x, y));
}

double percent(std::vector<double> x, std::vector<double> y, int a)
{
  int outcome = 0;
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] < a && y[i] < a)
      outcome++;
  }
  return 100 * double(outcome) / x.size();
}

double piValue(std::vector<double> x, std::vector<double> y)
{
  int circle = 0;
  int square = 0;
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] < 2 && y[i] < 2)
    {
      square++;
      bool inCircle = pow(x[i] - 1, 2) + pow(y[i] - 1, 2) < 1;
      if (inCircle)
      {
        circle++;
      }
    }
  }
  double k = double(square) / circle;
  return 4.0 / k;
}