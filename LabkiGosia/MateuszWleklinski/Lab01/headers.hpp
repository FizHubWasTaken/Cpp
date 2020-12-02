#include <iostream>
#include <vector>

/* template <typename T>
void print(T item, std::string end="\n")
{
    std::cout << item << end;
} */

void fill_with_randoms(int * &table, int Size, std::vector<int> &sum_digits, std::vector<int> &number_of_digits);
void digits(int number, int &sum, int &amount);

void print2d(int **tab, int Size);
void fill_square(int ** &tab, int Size);
void clear(int ** &tab, int Size);
void left_diagonal(int ** &tab, int Size);
void right_diagonal(int ** &tab, int Size);
void chess_board(int ** &tab, int Size);