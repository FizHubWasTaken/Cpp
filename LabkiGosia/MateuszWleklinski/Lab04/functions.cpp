#include "headers"

void deletingTable(double **table)
{
  for (int i = 0; i < N; i++)
    delete [] table[i];

  delete[] table;
}

void printTable(double **table)
{
  std::cout << "\n[ ";
  for (int row=0; row < N; row++)
  {
    //std::cout << "debug: " << row << "\n";
    std::cout <<"\t" << table[row][0] << "\t" << table[row][1];
    if (row != N-1)
      std::cout << std::endl;
  }
  std::cout << "\t]\n\n";
}

void fillTable(double **table, double (*func)(int), bool isExact)
{
  double noise{};
  for (int row=0; row < N; row++)
  {
    if (!isExact)
    {
      noise = std::rand() / double(RAND_MAX) - 0.5;
      // std::cout << noise << std::endl;
    }
    table[row][0] = double(row);
    table[row][1] = func(row) + noise;
  }
}

double myFunction(int x)
{
  return 2 * x -5;
}

double getAverage(double **table, int col)
{
  double output = 0;
  if (col!= 1 && col!=0)
  {
    std::cout << "[ERROR]:: invalid column number\n\n";
    return 0;
  }

  for (int row=0; row < N; row++)
    output += table[row][col];

  return output / N;
}

double D(double ** table)
{
  double output = 0;
  double av = getAverage(table, 0);
  for (int row = 0; row < N; row++)
  {
    output += pow(table[row][0] - av, 2);
  }
  //std::cout << output;
  return output;
}

double a(double ** table)
{
  double output = 0;
  double av = getAverage(table, 0);
  for (int row=0; row < N; row++)
  {
    output += table[row][1] * (table[row][0] - av);
  }
  return output / D(table);
}

double b(double ** table)
{
  return getAverage(table, 1) - a(table) * getAverage(table, 0); // b = y - ax
}

double dy(double **table)
{
  double output = 0;
  for (int row = 0; row < N; row++)
  {
    output += pow(table[row][1] - (a(table) * table[row][0] + b(table)), 2);
    output = output / (N-2);
    //std::cout << output << std::endl;
  }
  return sqrt(output);
}

double da(double ** table)
{
  
  return dy(table) / sqrt(D(table));
}

double db(double **table)
{
  double output = 1 / double(N) + pow(getAverage(table, 0), 2) / D(table);
  return dy(table) * sqrt(output);
}

void getCoefficients(double ** table)
{
  std::cout << "Linear Regression coefficients: \n"
            << "a = " << a(table) << "\n"
            << "b = " << b(table) << "\n"
            << "da = " << da(table) << "\n"
            << "db = " << db(table) << "\n\n";

}



bool is_sorted(double *table)
{
  for (int i = 0; i < N - 1; i++)
  {
    if (table[i+1] < table[i])
      return false;
  }
  return true;
}

void sort(double *table)
{
  double placeholder;
  while (!is_sorted(table))
  {
    for (int i = 0; i < N; i++)
    {
      if (table[i+1] < table[i])
      {
        placeholder = table[i];
        table[i] = table[i+1];
        table[i+1] = placeholder;
      }
    }
  }
}

int naive(double value, double *table)
{
  for (int i = 0; i < N; i++)
  {
    if (std::abs(value - table[i]) < epsilon)
    {
      return i;
    }
  }
  return -1; // return -1 if not found
}

int bisection(double value, double *table)
{
  int n = N;
  double halfValue;
  for (int i = 0; i < N; i++)
  {
    halfValue = table[n/2];
    if (std::abs(value - halfValue) < epsilon)
    {
      return i;
    }
    if (value > halfValue)
      n = n * 3 / 4;
    else
      n = n / 4;
  }
  return -1;
}

void getRandomData(double *table)
{
  for (int i = 0; i < N; i++)
  {
    
    table[i] = rand() % 101;
    std::cout << table[i];
  }
}