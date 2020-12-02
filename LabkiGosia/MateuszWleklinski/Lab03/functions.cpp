#include "headers"

void print_tab(int *table, int Size)
{
  std::cout << "[";
  for (int i = 0; i < Size; i++)
  {
    std::cout << table[i];
    if ( i == Size-1)
      std::cout << "]\n\n";
    else
      std::cout << ", ";
  }
}

void reset(int *table, int *orig, int Size)
{
  std::cout << "reseting table...\n\n";
  for (int i = 0; i < Size; i++)
    table[i] = orig[i];
}

void sort1(int *table, int Size)
{
  int placeholder;
  while (!is_sorted(table))
  {
    for (int i = 0; i < Size; i++)
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

void sort2(int *table, int Size)
{
  int placeholder;
  while (!is_sorted(table))
  {
    for (int i = 1; i < Size; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (table[j] > table[i])
        {
          placeholder = table[i];
          table[i] = table[j];
          table[j] = placeholder;
          break;
        }
      }
    }
  }
}

void sort3(int *table, int Size)
{
  int placeholder;
  int max_idx;
  for (int i = 0; i < Size; i++)
  {
    if (is_sorted(table))
      break;
    max_idx = greatest_index(table, N - i);
    placeholder = table[Size-i-1];
    table[Size-i-1] = table[max_idx];
    table[max_idx] = placeholder;
  }

}

bool is_sorted(int *table, int Size)
{
  for (int i = 0; i < Size - 1; i++)
  {
    if (table[i+1] < table[i])
      return false;
  }
  return true;
}

int greatest_index(int *table, int Size)
{
  int output = 0;
  int value = table[0];
  //print_tab(table);
  for (int i = 0; i < Size; i++)
  {
    if  (value < table[i])
    {
      value = table[i];
      //std::cout << "new value: " << value;
      output = i;
    }
      
  }
  return output;
}

int binary(int decimal, int *binary)
{
  int mod;
  int i = 0;
  while (decimal != 1)
  {
    mod = decimal % 2;
    decimal = (decimal - mod) / 2;
    binary[i] = mod;
    i++;
  }
  binary[i] = 1;
  reverse(binary, i+1);
  return i+1;
}

int decimal(int *binary, int Size)
{
  int output = 0;
  for (int i = 0; i < Size; i++)
  {
    output += binary[Size - i - 1] * std::pow(2, i);
  }
  return output;
}

void reverse(int *table, int Size)
{
  int placeholder;
  for (int i = 0; i < (Size - (Size % 2)) / 2; i++)
  {
    placeholder = table[Size - i-1];
    table[Size-i-1] = table[i];
    table[i] = placeholder;
  }
}