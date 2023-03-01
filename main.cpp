#include <algorithm>
#include <iostream>
#include <vector>

class Shape {
 public:
  const double PI = 3.1415;
  virtual double perimeter() const = 0;
};

class Square : public Shape {
 public:
  double a;

 Square(double a) : a(a) {}

 double perimeter() const final {
  return a * 4;
 }
};

class Circle : public Shape {
 public:
  double r;

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



  // an example of bridge pattern

   

  return 0;
}