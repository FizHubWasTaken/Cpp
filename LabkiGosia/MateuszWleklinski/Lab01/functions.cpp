#include "headers.hpp"
#include <iostream>
#include <string>
#include <vector>

void fill_with_randoms(int * &table, int Size, std::vector<int> &sum_digits, std::vector<int> &number_of_digits)
{
  int sum = 0;  
  int number = 0;
  for (int i = 0; i < Size; i++)
  {
    sum = 0;
    number = 0;
    table[i] = rand() % 10000;
    digits(table[i], sum, number);
    sum_digits.push_back(sum);
    number_of_digits.push_back(number);
  }
}

void digits(int number, int &sum, int &amount)
{
  //std::cout << "Number: " << number << "\n";
  int digit;
  for (int i = 10; i <= 10000; i = i * 10)
  {
    digit = (number % i) / (i/10);
    // std::cout << digit << std::endl;
    sum += digit;
    if (number != 0) amount++;
    number -= number % i;
    
  }
  // std::cout << "Digits: " << amount << "\n" << "Sum: " << sum << "\n\n";
}

void print2d(int **tab, int Size)
{
  for (int i = 0, j = 0; i < Size; i++)
  {
    j = 0;
    while (j != Size)
      std::cout << tab[i][j++] << "\t";
    std::cout << "\n";
  }
}

void clear(int ** &tab, int Size)
{
  std::cout << "\n\nClearing table... \n";
  for (int i = 0, j = 0; i < Size; i++)
  {
    j = 0;
    while (j != Size) {
      tab[i][j] = 0;
      j++;
    }
  }
}

void fill_square(int ** &tab, int Size)
{
  std::cout << "Adding a square inside: \n\n";
  for (int i = 0, j = 0; i < Size; i++)
  {
    j = 0;
    while (j != Size) {
      if (i != 0 and i != Size-1 and j != 0 and j != Size-1)
        tab[i][j] = 1;
      j++;
    }

  }
}

void left_diagonal(int ** &tab, int Size)
{
  std::cout << "Adding left diagonal: \n\n";
  for (int i = 0, j = 0; i < Size; i++)
  {
    j = 0;
    while (j != Size) {
      if (i == j)
        tab[i][j] = 1;
      j++;
    }
  }
}

void right_diagonal(int ** &tab, int Size)
{
  std::cout << "Adding right diagonal: \n\n";
  for (int i = 0, j = 0; i < Size; i++)
  {
    j = 0;
    while (j != Size) {
      if (i == Size - 1 - j)
        tab[i][j] = 1;
      j++;
    }
  }
}


void chess_board(int ** &tab, int Size)
{
  std::cout << "Adding chess board: \n\n";
  for (int i = 0, j = 0; i < Size; i++)
  {
    j = 0;
    while (j != Size) {
      if (i % 2 == j % 2)
        tab[i][j] = 1;
      j++;
    }
  }
}