#ifndef TEST_H_
#define TEST_H_
#include <cmath>
#include <iostream>
#include <ctime>
#include <functional>
#include <vector> 
#define SEED 20


//Tests:
void Tests();
void randintTest();
void randfloatTest();
void lenTest();

// Functions:
void histogram(int number, int range);
double percent(std::vector<double> x, std::vector<double> y, int a);
void numbersSquare(int n, double range);
double piValue(std::vector<double> x, std::vector<double> y);

template <class T>
void print(T item, std::string ending="\n")
{
  std::cout << item << ending;
}

template <class T>
void printHist(std::vector<T> hist)
{
  print("_________");
  for (auto i = hist.begin(); i != hist.end(); i++)
  {
    print("|", "\t");
    print(*i, " \t|\n");
  }
  print("_________");
}

template <class T>
int len(T number)
{
  std::string sint = std::to_string(number);
  return sint.length();
}




class Generator {
  signed long a;
  signed long long x;
  long c;
  signed long m;
  void generate();
  public:
    Generator(int seed);
    long int randint();
    int randint(int range);
    double randfloat();
    double randfloat(double range);
};
#endif


