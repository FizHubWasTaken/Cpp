#include "headers.h"

void checkPrinting()
{
  Debug("\n1. Checking Table printing...\n");

  int *tab = new int[5] {1, 2, 3, 4, 5};
  printTable<int *>(tab, 5);

  delete [] tab;
  Debug("\n\tCheck complete!\n");
}

void checkSwaping()
{
  Debug("\n2. Checking value swaping...\n");
  int a = 5;
  int b = 10;
  Debug("\tinitial values: ");
  Debug("\ta = ", "");
  Debug(a);
  Debug("\tb = ", "");
  Debug(b, "\n");

  swap(a, b);
  Debug("\n\tfinal values: ");
  Debug("\ta = ", "");
  Debug(a);
  Debug("\tb = ", "");
  Debug(b);

  Debug("\n\tCheck complete!\n");
}

void checkInversing()
{
  Debug("\n3. Checking table inversing...\n");
  double *tab = new double[5];
  for (int i = 0; i < 5; i++)
  {
    tab[i] = float(10 * rand()) / RAND_MAX;
  }
  Debug("\treal table: \n");
  Debug("\tinitial table: \n");
  printTable(tab, 5);

  inverseTable(tab, 5);

  Debug("\n\tfinal table: \n");
  printTable(tab, 5);

  delete [] tab;

  int *tab2 = new int[5];
  for (int i = 0; i < 5; i++)
  {
    tab2[i] = rand() % 10;
  }
  Debug("\tinteger table: \n");
  Debug("\tinitial table: \n");
  printTable(tab2, 5);

  inverseTable(tab2, 5);

  Debug("\n\tfinal table: \n");
  printTable(tab2, 5);

  Debug("\n\tCheck complete!\n");
  delete [] tab2;
}

void checkPalindromic()
{
  Debug("\n4. Checking if table are palindromic...\n");
  char tab[5] = {'a', 'b', 'c', 'b', 'a'};
  Debug("\tchar table: \n");
  printTable(tab, 5);
  bool test1 = isPalindrom(tab, 5);
  tab[1] = 'a';
  bool test2 = isPalindrom(tab, 5);


  if (test1 && !test2)
    Debug("\tTest passed!\n");
  else
    Debug("\tTest failed!\n");

  Debug("\n\tCheck complete!\n");
}

void checkChangeValues()
{
  Debug("\n5. Checking changing values..\n");
  int *tab = new int[5]{1, 2, 3, 4, 5};
  int *ftab = new int[5];

  changeValues(tab, ftab, power, 5);

  bool success = true;
  for (int i = 0; i < 5; i++)
  {
    if (ftab[i] != tab[i] * tab[i])
      success = false;
  }
  Debug("\tOriginal table: ");
  printTable(tab, 5);
  Debug("\n\tFinal table: ");
  printTable(ftab, 5);

  if (success)
    Debug("\tTest Passed!\n");
  else
    Debug("\tTest Failed\n");
  
  Debug("\n\tCheck complete!\n");

  delete [] tab;
  delete [] ftab;
}

int power(int x)
{
  return x * x;
}

void checkFilterTable()
{
  Debug("\n6. Checking filtering table...\n");
  int *tab = new int[5]{-2, -1, 0, 1, 2};
  int *ftab = new int[5];
  bool test1 = filterTable(tab, ftab, isPositive, 5) == 2;
  bool test2 = ftab[0] == tab[3] && ftab[1] == tab[4];

  Debug("\tOriginal table: ");
  printTable(tab, 5);
  Debug("\n\tFinal table: ");
  printTable(ftab, 5);

  if (test1 && test2)
    Debug("\tTest Passed!\n");
  else
    Debug("\tTest Failed!\n");
  

  Debug("\n\tCheck Complete!\n");

  delete [] tab;
  delete [] ftab;
}

bool isPositive(int number)
{
  if (number > 0)
    return true;
  else
    return false;
}

void checkSplitTable()
{
  Debug("\n7. Checking splitting table...\n");
  int *tab = new int[5]{-1, -5, 1, 2, 3};
  int *ftab = new int[5];
  bool test1 = splitTable(tab, ftab, isPositive, 5);
  bool test2 = ftab[0] == 1 && ftab[1] == 2 && ftab[2] == 3;
  bool test3 = ftab[3] == -1 && ftab[4] == -5;

  Debug("\tOriginal table: ");
  printTable(tab, 5);
  Debug("\n\tFinal table: ");
  printTable(ftab, 5);

  if (test1 && test2 && test3)
    Debug("\tTest Passed!\n");
  else
    Debug("\tTest Failed!\n");
  
  Debug("\n\tCheck Complete!\n");

  delete [] tab;
  delete [] ftab;
}