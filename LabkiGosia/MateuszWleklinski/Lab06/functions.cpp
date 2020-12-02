#include "headers.h"

void SumTest()
{
  Debug("1. Testing summing parameters..");
  bool test1 = sum(1.0, 2.0, 5.0) == 1.0 + 2.0 + 5.0;
  Debug("\t1.0 + 2.0 + 5.0 = ", "");
  Debug(1.0+2.0+5.0);
  bool test2 = sum(3.14, 9.81, 21.37, 7.0) == 3.14+9.81+21.37+7;
  Debug("\t3.14 + 9.81 + 21.37 + 7.0 = ", "");
  Debug(3.14+9.81+21.37+7);
  if (test1 && test2)
    Debug("\tTest Passed!\n");
  else
    Debug("\tTest Failed!\n");
}

void OperationTest()
{
  Debug("2. Testing different operators...");
  bool test1 = (operation<int>(1))(1, 2) == -1;
  bool test2 = (operation<int>(2))(1, 2) == 2;
  bool test3 = (operation<int>(3))(4, 2) == 2;
  if (test1 && test2 && test3)
    Debug("\tTest Passed!\n");
  else
    Debug("\tTest Failed!\n");
}

void FunctionCallsTest()
{
  Debug("3. Test multiple functionCalls");
  int tab[7] = {1, 2, 3, 4, 5, 6, 7};
  bool test1 = functionCalls(tab, 7) == 7;
  if (test1)
  {
    Debug("\t Test Passed!\n");
  }
}

void CompareTableTest()
{
  Debug("4. Test comparing Tables");
  int tab[5] = {1, 1, 2, 3, 5};
  bool ltab[5] = {1, 1, 0, 1, 0};
  int newtab[5];
  //newtab = compareTables(tab, ltab, 5);
}

void MaxValueTest()
{
  Debug("5. Test max value...");
  bool test1 = max(1, 3.14, 9.81, 2.88, 4) == 9.81;
  Debug("\tmax of: 1, 3.14, 9.81, 2.88, 4 is ", "");
  Debug(max(1, 3.14, 9.81, 2.88, 4));
  bool test2 = max(-5, -9.4, 12, 3.14, 3) == 12;
  Debug("\tmax of: -5, -9.4, 12, 3.14, 3 is ", "");
  Debug(max(-5, -9.4, 12, 3.14, 3));
  if (test1 && test2)
    Debug("\tTest Passed!\n");
  else
    Debug("\tTest Failed\n");
  
}