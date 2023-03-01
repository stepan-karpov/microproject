#include <algorithm>
#include <iostream>
#include <vector>

class Shape;
class Color;

// Colors

class Color {
 public:
  virtual int getColotID() const = 0;
  virtual void printColorName() const = 0;
};

class NoColor : public Color {
 public:
  int getColotID() const final {
    return 0;
  }
  void printColorName() const final {
    std::cout << "I have no color!\n";
  }
};

class Red : public Color {
 public:
  int getColotID() const final {
    return 1;
  }
  void printColorName() const final {
    std::cout << "I am red!\n";
  }
};

class Blue : public Color {
 public:
  int getColotID() const final {
    return 2;
  }
  void printColorName() const final {
    std::cout << "I am blue!\n";
  }
};

// Shapes

class Shape {
 public:
  const double PI = 3.1415;
  virtual double perimeter() const = 0;
};

class Square : public Shape {
 public:
  double a;
  Red my_color;

 Square(double a) : a(a) {}

 double perimeter() const final {
  return a * 4;
 }
};

class Circle : public Shape {
 public:
  double r;
  Blue my_color;

 Circle(double r) : r(r) {}

 double perimeter() const final {
  return 2 * Shape::PI * r;
 }
 
};

int main() {

  // an example of factory method pattern

  Square square(5);
  Circle circle(5);

  // both object has the same function
  // but they were created in a two different ways
  std::cout << square.perimeter() << "\n";
  std::cout << circle.perimeter() << "\n";
  std::cout << "\n";

  // an example of bridge pattern

  Red red;
  Blue blue;
  NoColor blank;

  red.printColorName();
  blue.printColorName();
  blank.printColorName();

  std::cout << "\ncalling functions from shapes:\n";

  square.my_color.printColorName();
  circle.my_color.printColorName();

  return 0;
}