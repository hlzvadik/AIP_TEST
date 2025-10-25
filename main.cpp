#include <iostream>
#include <cstddef>

int main()
{
  size_t count = 0;
  size_t a = 0;
  while (std::cin >> a){
    count += a*a;
  }
  if (std::cin.eof()){
    std::cout << count << '\n';
  }
  else if (std::cin.fail()){
    std::cout << "Error\n";
    return 1;
  }
}
