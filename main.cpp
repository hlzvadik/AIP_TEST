#include <iostream>
#include <cstddef>
#include <limits>

size_t max = std::numeric_limits< size_t >::max();

size_t summa(size_t a, size_t b)
{
  if (a <= max-b){
    return a + b;
  }
  throw
    std::logic_error("out_of_range");
}

size_t pow_to_2(size_t a)
{
  if (a<=max/a){
    return a*a;
  }
  throw
    std::logic_error("out_of_range");
}

int is_Pyth(size_t a, size_t b, size_t c)
{
  size_t p1 = 0, p2 = 0, p3 = 0;
  try{
    a = pow_to_2(a);
    b = pow_to_2(b);
    c = pow_to_2(c);
  } catch(...){
    return -1;
  }
  try{
    p1 = summa(a,b);
    p2 = summa(b,c);
    p3 = summa(a,c);
  } catch(...){
    return -1;
  }
  bool p = (a == p2);
  p = p || (b == p3);
  p = p || (c == p1);
  if (p){
    return 1;
  }
  return 0;
}

int main()
{
  size_t a = 0, b = 0, c = 0;
  std::cin >> c >> b;
  size_t count = 0;
  while (std::cin >> a){
    int p = is_Pyth(a,b,c);
    if (p == -1){
      std::cerr << "Exceeding the allowed value" << '\n';
      return 2;
    }
    count += p;
    c = b;
    b = a;
  }
  if (std::cin.eof()){
    std::cout << count << '\n';
  }
  else if (std::cin.fail()){
    std::cerr << "Error\n";
    return 1;
  }
}
