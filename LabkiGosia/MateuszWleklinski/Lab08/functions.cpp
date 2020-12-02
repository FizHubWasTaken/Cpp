#include "headers.h"

double induction(Vector3 B, Vector3 S)
{
  // return B * S;
  return B.dot(S);
}

Vector3 LorentzForce(double q, Vector3 E, Vector3 v, Vector3 B)
{

  return (E + v % B) * q;
}

double AmpereWork(double I, Vector3 dr, Vector3 dl, Vector3 B)
{
  return I * dr.mixed(dl, B);
}