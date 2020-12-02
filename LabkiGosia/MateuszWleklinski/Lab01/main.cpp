#include <iostream>
#include "headers.hpp"
#include <ctime>
#include <vector>

#define N 1e6
#define N2 10

int main()
{

  //print("Hello World!");

  std::srand(std::time(nullptr));
  int *tab = new int[N]{};
  std::vector<int> digits_sum;
  std::vector<int> number_of_digits;

  fill_with_randoms(tab, N, digits_sum, number_of_digits);

  std::string ind, placeholder;
  std::cout << "Type the index you want to check: ";
  std::cin >> ind;

  int idx = stoi(ind);
  std::cout <<"Number: " << tab[idx] << std::endl 
            << "digits: "<< number_of_digits[idx] << std::endl
            << "Sum of digits: " << digits_sum[idx] << "\n\n";

  std::cout << "type any button (an confirm with enter) to continue...";
  std::cin >> placeholder;
  // std::cout << sum_of_digits(6624) << std::endl;

  delete [] tab;


  int** tab2d=new int*[N2];
  for(int i=0;i<N2;i++)
	  tab2d[i]=new int[N2]{};

  print2d(tab2d, N2); // function to print out a 2d table


  std::cout << "1. ";
  fill_square(tab2d, N2);

  print2d(tab2d, N2);

  clear(tab2d, N2);


  std::cout << "2. ";

  left_diagonal(tab2d, N2);

  print2d(tab2d, N2);

  clear(tab2d, N2);


  std::cout << "3. ";

  right_diagonal(tab2d, N2);

  print2d(tab2d, N2);


  std::cout << "4. ";

  left_diagonal(tab2d, N2);

  print2d(tab2d, N2);

  clear(tab2d, N2);

  std::cout << "5. ";

  chess_board(tab2d, N2);

  print2d(tab2d, N2);
  



for(int i=0; i<N2; i++)
    delete [] tab2d[i];
  delete [] tab2d;


}