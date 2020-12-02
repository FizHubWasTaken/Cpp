#include <cmath>
#include <iostream>
#include <ctime>

void checkPrinting();
void checkSwaping();
void checkInversing();
void checkPalindromic();
void checkChangeValues();
int power(int x);
void checkFilterTable();
bool isPositive(int number);
void checkSplitTable();

template <class T>
void Debug(T item, std::string ending="\n")
{
  std::cout << item << ending;
}

template <class T>
void printTable(T table, int Size)
{
  std::cout << "\t[  ";
  for (int i = 0; i < Size; i++)
  {
    if (i != 0)
      std::cout << "\t";
    std::cout  <<"\t" << table[i];
    if (i == Size - 1)
      std::cout << "\t";
    else
      std::cout << "\n";
  }
  std::cout << "]\n";
}

template <class T>
void swap(T &item1, T &item2)
{
  T placeholder = item1;
  item1 = item2;
  item2 = placeholder;
}

template <class T>
void inverseTable(T table, int Size)
{
  for (int i = 0; i < Size / 2; i++)
    swap(table[i], table[Size-1-i]);
}

template <class T>
bool isPalindrom(T table, int Size)
{
  for (int i = 0; i <Size / 2; i++)
  {
    if (table[i] != table[Size - 1 - i])
      return false;
  }
  return true;
}


template <class T, class U>
void changeValues(T table,  T finalTable, U (*func)(U), int Size)
{
  for (int i = 0; i < Size; i++)
  {
    finalTable[i] = func(table[i]);
  }
}

template <class T, class U>
int filterTable(T table, T results, bool (*func)(U), int Size, bool ifTrue=true)
{
  int output = 0;
  for (int i = 0; i < Size; i++)
  {
    bool ifPass = ifTrue == func(table[i]); // depends on if we want to pass values which agree with the condition or not
    if (ifPass)
    {
      results[output] = table[i];
      output++;
    }
  }
  return output;
}


template <class T, class U>
int splitTable(T table, T results, bool (*func)(U), int Size)
{
  int output = filterTable(table, results, func, Size);
  T end = new U[output];
  filterTable(table, end, func, Size, false);
  for (int i = 0; i < Size - output; i++)
    results[output + i] = end[i];

  delete [] end;
  return output;
}
