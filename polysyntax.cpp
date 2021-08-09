// Compile with
//     g++ -std=c++17 polysyntax.cpp -o polysyntax

// clang-format off
#include <iostream>

class Base {
public:
  virtual void poly()     { std::cout << "Base::poly() \n"; }
          void non_poly() { std::cout << "Base::non_poly() \n"; }
};

class Derived : public Base {
public:
  virtual void poly()     override { std::cout << "Derived::poly() \n"; }
          void non_poly()          { std::cout << "Derived::non_poly() \n"; }
};


void use_through_base(Base &b) {
  b.poly();
  b.non_poly();
}

// Write down the output, before running the executable it :)
int main() {
  Base b;
  Derived d;

  b.poly();
  b.non_poly();

  d.poly();
  d.non_poly();

  std::cout << "----------------------------------------\n";

  use_through_base(b);
  use_through_base(d);

  return 0;
}
