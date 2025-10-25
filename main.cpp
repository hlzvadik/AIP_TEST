#include <iostream>
#include <cstddef>

int main()
{
  size_t a = 0;
  std::cin >> a;
  if (std::cin.eof()){
    std::cout << 0 << '\n';
  }
  else if (std::cin.fail()){
    std::cout << "Error\n";
    return 1;
  }
}
