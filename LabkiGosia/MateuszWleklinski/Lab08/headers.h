#ifndef TEST_H_
#define TEST_H_
#include <cmath>
#include <iostream>
#include <functional>




template <class T>
void print(T item, std::string ending="\n")
{
  std::cout << item << ending;
}



class Vector3 {
  public:
    double x, y, z;
    // Vector3();
    Vector3(double x0=1, double y0=0, double z0=0);
    double magnitude();
    public:
      Vector3 operator*(double);
     
      friend std::ostream& operator<<(std::ostream&, const Vector3&);
      double dot(Vector3);
      Vector3 cross(Vector3);
      double operator*(Vector3); // dot product
      Vector3 operator%(Vector3); //cross product
      Vector3 operator+(Vector3);
      bool operator==(Vector3);
      double mixed(Vector3, Vector3);


};

// Tests
void Tests();
void Result(bool condition);
void TestVectorLen();
void TestScalingVectors();
void TestDotProduct();
void TestAddingVectors();
void  TestCrossProduct();
void TestInduction();
void TestLorentzForce();
void TestAmpereWork();

//Functions
double induction(Vector3 B, Vector3 S);
Vector3 LorentzForce(double q, Vector3 E, Vector3 v, Vector3 B);
double AmpereWork(double I, Vector3 dr, Vector3 dl, Vector3 B);

#endif


