#include <cmath>
#include <iostream>
#include <ctime>
#include <functional>


void SumTest();
void FunctionCallsTest();
void MaxValueTest();
void OperationTest();

template <class T>
void Debug(T item, std::string ending="\n")
{
  std::cout << item << ending;
}

template <class T, class ... Args>
T sum(T first, Args ... a)
{
  T output = first;
  int r = sizeof...(Args);
  T tab[] = {a...};
  for(int i = 0; i < r; i++)
  {
    output += tab[i];
    // Debug("Adding: ", "");
    // Debug(tab[i]);
  }
  return output;
}



template <class U>
std::function<U(U, U)> operation(int op)
{
  switch (op) {
   // case "add":
     // return [] (U a, U b) { return a+b; };
    case 1:
      return [] (U a, U b) {return a - b;};
    case 2:
      return [] (U a, U b) {return a * b;};
    case 3:
      return [] (U a, U b) {return a / b;};

    default:
  
    
    return [] (U a, U b) {return a+ b;};
  }
}

template <class T>
T example(T a, T b)
{
  if (a > b)
    return a;
  else
    return b;
}

template <class T>
T functionCalls(T tab[], int Size)
{
  T output = example(tab[0], tab[1]);
  for (int i=2; i < Size; i++)
  {
    output = example(output, tab[i]);
  }
  return output;
}

template <class T, class U>
T compareTables(T myTab, U logicTab, int Size)
{
  T output;
  int counter = 0;
  for (int i = 0; i < Size; i++)
  {
    if (logicTab[i])
    {
      output[counter] = myTab[i];
      counter++;
    }
  }
  return output;
}

template<class T>
double max(T n)
{
  return n;
}

template<class T1, class T2, class ...Ts>
double max(T1 n1, T2 n2, Ts ... ns) 
{
  double res = max(n2, ns...);
  return n1 > res ? n1 : res;
}