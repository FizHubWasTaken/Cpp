#include "headers.h"

Vector3::Vector3(double x0, double y0, double z0)
{
  x = x0;
  y = y0;
  z = z0;
}

double Vector3::magnitude()
{
  return sqrt(pow(x,2) + pow(y, 2) + pow(z,2));
}

Vector3 Vector3::operator+(Vector3 v)
{
  double i = x + v.x;
  double j = y + v.y;
  double k = z + v.z;
  Vector3 output(i, j, k);
  return output;
}

std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
  os<<"\n\t[\t"<< v.x << "\n\t\t" << v.y << "\n\t\t" << v.z << "\t]\n";
  return os;
}

double Vector3::dot(Vector3 v) // metoda zgodnie z poleceniem
{
  return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::cross(Vector3 v)
{
  double i = y * v.z - z * v.y;
  double j = z * v.x - x * v.z;
  double k = x * v.y + y * v.x;
  Vector3 output(i, j, k);
  return output;
}

double Vector3::operator*(Vector3 v) // dla wygody
{
  return dot(v);
}

Vector3 Vector3::operator*(double scalar)
{
  Vector3 output(scalar * x, scalar * y, scalar * z);
  return output;
}



bool Vector3::operator==(Vector3 v)
{
  bool i = x == v.x;
  bool j = y == v.y;
  bool k = z == v.z;
  if (i && j && k)
    return true;
  else
    return false;
}

Vector3 Vector3::operator%(Vector3 v)
{
  return cross(v);
}

double Vector3::mixed(Vector3 v, Vector3 w)
{
  Vector3 cross_p = v.cross(w);
  return dot(cross_p);
}