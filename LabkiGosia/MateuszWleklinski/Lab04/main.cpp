#include "headers"

int main() 
{
  std::srand(std::time(0));

  double **table = new double*[N];
  //std::cout << "debug";
  for (int i = 0; i < N; i++)
  {
    //std::cout << "debug" << i;
    table[i] = new double[2];
  }
  
  printTable(table);

  double (*func)(int) = myFunction;

  std::cout << "Table without noise:\n";
  fillTable(table, func, true);
  printTable(table);

  getCoefficients(table);


  std::cout << "Table with noise:\n";
  fillTable(table, func, false);
  printTable(table);

  getCoefficients(table);

  // double av = getAverage(table, 1);
  // std::cout << av << "\n";
  // std::cout << D(table) << "\n";
  // std::cout << a(table) << "\n";


  deletingTable(table);

  double *table2 = new double[N];
  getRandomData(table2);

  std::cout << "looking for item: "<<naive(table2[3], table2) << "\n";
  std::cout << "another way: "<< bisection(table2[3], table2) << "\n";

  delete [] table2;

}