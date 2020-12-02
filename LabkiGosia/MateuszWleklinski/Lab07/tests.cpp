#include "headers.h"

void Tests()
{
  //Here will be all the test:
  print("Testing started...\n");

  // randintTest();
  // randfloatTest();
  lenTest();
}

void randintTest()
{
  Generator Randomizer(SEED);
  print("Test 1: randint");
  print("\tGenerating random integer: ", "");
  long int lz1 = Randomizer.randint();
  print(lz1);

  print("\tGenerating random number between 1 and 100: ", "");
  int z1 = Randomizer.randint(100);
  print(z1);

  print("\n\tChecking if next values will be different...");
  long int lz2 = Randomizer.randint();
  int z2 = Randomizer.randint(100);
  bool test1 = lz1 != lz2;
  bool test2 = z1 != z2;
  if (test1 && test2)
    print("\tTest passed!\n");
  else
    print("\tTest FAILED!\n");

}

void randfloatTest()
{
  Generator Random(SEED);
  print("Test 2: randfloat");
  print("\tGenerating random real number: ", "");
  double n1 = Random.randfloat();
  print(n1);

  print("\tGenerating random number between 1 and 100: ", "");
  double m1 = Random.randfloat(100.0);
  print(m1);

  print("\n\tChecking if next values will be different...");
  double n2 = Random.randfloat();
  double m2 = Random.randfloat(100.0);
  bool test1 = n1 != n2;
  bool test2 = m1 != m2;
  if (test1 && test2)
    print("\tTest passed!\n");
  else
    print("\tTest FAILED!\n");

}

void lenTest()
{
  Generator Random(SEED);
  print("Test 3: number of digits");
  long int number = 14568237236523;
  print("Number of digits of number: ", "");
  print(number, "");
  print(" is: ", "");
  print(len(number));
}