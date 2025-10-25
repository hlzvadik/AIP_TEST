#include <iostream>
#include <cstddef>

bool is_Pyth(size_t a, size_t b, size_t c)
{
  bool p = (a*a == b*b + c*c);
  p = p || (b*b == a*a + c*c);
  p = p || (c*c == a*a + b*b);
  return p;
}

int main()
{
  size_t a = 0, b = 0, c = 0;
  std::cin >> c >> b;
  size_t count = 0;
  while (std::cin >> a){
    count += is_Pyth(a,b,c)? 1:0;
    c = b;
    b = a;
  }
  if (std::cin.eof()){
    std::cout << count << '\n';
  }
  else if (std::cin.fail()){
    std::cout << "Error\n";
    return 1;
  }
}
