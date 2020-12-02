#include "headers"

int main() 
{

  //Exercise 1:

  int original_tab[N] = {18, 12, 27, 1, 0};
  int tab[N];
  reset(tab, original_tab);
  
  std::cout << "Your table: \n";
  print_tab(tab);
  //std::cout << "Smallest index: " << greatest_index(tab, N) << std::endl;
  

  //std::cout << is_sorted(tab) << std::endl;;
  sort1(tab);

  std::cout << "\nTable sorted first way: \n";
  print_tab(tab);

  reset(tab, original_tab);

  std::cout << "Your table: \n";
  print_tab(tab);

  sort2(tab);

  std::cout << "\nTable sorted second way: \n";
  print_tab(tab);
  //std::cout << "Smallest index: " << greatest_index(tab, N) << std::endl;

  reset(tab, original_tab);

  std::cout << "Your table: \n";
  print_tab(tab);

  sort3(tab);

  std::cout << "\nTable sorted third way: \n";
  print_tab(tab);

  // Exercise 2:
  std::cout << "\n\n\n";
  int binary_tab[Buffor];
  
  int dec_num;
  do
  {
    std::cout << "Type your decimal number: ";
    std::cin >> dec_num;
  } while(dec_num < 0 || dec_num > 1048576);

  std::cout << "\nYour number in binary: ";
  int b_digits = binary(dec_num, binary_tab);
  print_tab(binary_tab, b_digits);

  std::cout << "Converting back to decimal: ";
  std::cout << decimal(binary_tab, b_digits) << std::endl;

  /*
  reverse(binary_tab, b_digits);
  print_tab(binary_tab, b_digits);
  */
}