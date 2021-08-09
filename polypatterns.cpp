// Compile with
//     g++ -std=c++17 polypatterns.cpp -o polypatterns

#include <iostream>

// The simple pattern is to have an abstract base class, aka interface. You'll
// then implement the interface, but any code using your classes will only deal
// with the pointers or references to the interface.

class Interface {
public:
  // Virtual `virtual` and abstract `= 0`.
  virtual void method() = 0;
};

class PartialImplementation : public Interface {
public:
  // Optionally `virtual` and definitely `override` (in modern C++).
  virtual void method() override {
    std::cout << "PartialImplementation: " << message() << "\n";
  }

protected:
  // We can keep playing this game...
  virtual std::string message() = 0;
};

class FullImplementation : public PartialImplementation {
protected:
  // here the variety comes in.
  virtual std::string message() { return "FullImplementation"; }
};

class SmileyImplementation : public PartialImplementation {
protected:
  // here the variety comes in.
  virtual std::string message() { return ":)"; }
};

// -----------------------------------------------------------------------------
// Variant 2: This is something Herb Sutter likes; and it kinda does make sense.
//
class SutterInterface {
public:
  // Not virtual!
  void method() {
    // Usually only does:
    do_method();

    // but now you have a method where you could put timeing or profiling
    // instructions if you ever needed to.

    // Furthermore, you can make more changes without changing the public part
    // of the API of the class. (I don't know how useful this is.)
  }

protected:
  // Here is where the abstract method goes, i.e. it's protected.
  virtual void do_method() = 0;
};

class SutterImplementation : public SutterInterface {
protected:
  virtual void do_method() override { std::cout << "do something\n"; }
};

int main() {}
