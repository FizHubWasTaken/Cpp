#include "headers.h"

void Tests()
{
  TestVectorLen();
  TestScalingVectors();
  TestAddingVectors();
  TestDotProduct();
  TestCrossProduct();
  TestInduction();
  TestLorentzForce();
  TestAmpereWork();
}

void Result(bool condition)
{
  if (condition)
    print("\tTest Passed!\n");
  else
    print("\tTest Failed!\n");
}

void TestVectorLen()
{
  print("1. Testing Length of a vector...");

  print("\t Creating a vector [1, 0, 0]");
  Vector3 i;
  print(i);
  print("\tthis vector has a length: ", "");
  std::cout << i.magnitude() << std::endl;

  bool test1 = i.magnitude() == 1;

  print("\t Creating a vector [3, 4, 0]");
  Vector3 u(3, 4, 0);
  print(u);
  print("\tthis vector has a length: ", "");
  std::cout << u.magnitude() << std::endl;

  bool test2 = u.magnitude() == 5;

  Result(test1 && test2);

}

void TestScalingVectors()
{
  print("2. Testing multipling vector by a number:");
  print("\tCreating vector: [3, 4, 0]");
  Vector3 v(3, 4, 0);
  print(v);
  print("\tOriginal length: ", "");
  print(v.magnitude());
  print("\tVector after scaling by a factor 2: ", "");
  print(v*2);

  Vector3 output(6, 8, 0);
  bool test1 = v*2 == output;
  Result(test1);
}

void TestAddingVectors()
{
  print("3. Testing adding vectors");
  print("\tCreating vector u and v:");
  print("\tu:");
  Vector3 u(3, 4, 0);
  print(u);
  Vector3 v(1, 1, 1);
  print("\tv:");
  print(v);
  print("\tu + v = ", "");
  print(v + u);

  Vector3 output(4, 5, 1);
  bool test = v + u == output;
  Result(test);
}

void TestDotProduct()
{
  print("4. Testing Dot Product");
  print("\tCreating vector u and v:");
  print("\tu:");
  Vector3 u(3, 4, 0);
  print(u);
  Vector3 v(1, 1, 1);
  print("\tv:");
  print(v);
  print("\tu * v = ", "");
  print(v.dot(u)); // można też v * u

  bool test = v * u == 7;
  Result(test);

}

void  TestCrossProduct()
{
  print("5. Testing Cross Product");
  print("\tCreating vector u and v:");
  print("\tu:");
  Vector3 u(1, 0, 0);
  print(u);
  Vector3 v(0, 1, 0);
  print("\tv:");
  print(v);
  print("\tu * v = ", "");
  print(v.cross(u)); // można też v % u

  Vector3 output(0, 0, 1);
  bool test = v % u == output;
  Result(test);
}

void TestInduction()
{
  print("6. Testing Induction");

  Vector3 B(0, 0, 1), S(2, 4, 3);
  print("\tCreating vector B:");
  print(B);
  print("\tand Creating Vector S");
  print(S);

  print("Vector of magnetic Induction is equal to: ", "");
  print(induction(B,S));
  bool test = induction(B, S) == B * S;
  Result(test);
  
}

void TestLorentzForce()
{
  print("7. Testing Lorentz Force");

  Vector3 B(0, 0, 1), v(2000, 4000, 3000), E(25, 73, 120);
  print("\tCreating vector B:");
  print(B);
  print("\tand Creating Vector v");
  print(v);
  print("\tCreating vector E");
  print(E);
  print("and let q be the elementary charge e");

  double e = 1.6e-19;
  print("Lorentz Force is equal to: ");
  print(LorentzForce(e, E, v, B));
  bool test = LorentzForce(e, E, v, B) == (E + v % B) * e;
  Result(test);
  
}

void TestAmpereWork()
{
  print("8. Testing Ampere Work");

  Vector3 B(1, 1, 1), dl(0, 0, 1e-3), dr(-2e-2, 1e-4, 4e-3);
  print("\tCreating vector B:");
  print(B);
  print("\tand Creating Vector dl");
  print(dl);
  print("\tCreating vector dr");
  print(dr);
  print("\tand Generating current I = ", "");
  double I = 2;
  print(I);
  
  print("\tAmpere Work is equal to: ", "");
  print(AmpereWork(I, dr, dl, B));
  Vector3 output;
  bool test = AmpereWork(I, dr, dl, B) == dr * (dl % B) * I;
  Result(test); 
  
}