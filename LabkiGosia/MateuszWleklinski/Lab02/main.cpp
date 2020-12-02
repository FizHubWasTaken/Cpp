#include "headers"

int main() 
{
  // 1a
  std::cout << "Exercise 1:\nType range in which you want to check for primes: ";
  int number;
  std::cin >> number;
  std::cout << "1a Divisibility:\n";
  writePrimeNumbers(number);

  // 1b
  std::cout << "\n 1b Eratosthenes Sieve:\n";
  Eratosthenes(number);

  // 1c
  std::cout << "\n 1c Linear Sieve: \n";
  linear_sieve(number);
  

  // 2
  std::cout << "\n\nExercise 2: \nIntegral of f: \n";

  bool run = true;
  std::string answer;
  while (run)
  {
    std::cout << "Parameter a = ";
    double a, b, dx;
    std::cin >> a;
    std::cout << "Parameter b = ";
    std::cin >> b;
    do 
    {
      std::cout << "dx = ";
      std::cin >> dx;
      if (dx > std::abs(b - a))
        std::cout << "dx has to be smaller than |a-b|\n";
    } while(dx > std::abs(b - a) || dx < 0);
    
    std::cout << "I = " << integral(a, b, dx) << std::endl; // agrees with WolframAlpha
    std::cout << "Do you wish to change the parameters? [y/n]" << std::endl;
    std::cin >> answer;
    if (answer != "y")
      break;
  }
}