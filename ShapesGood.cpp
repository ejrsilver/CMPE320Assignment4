#include <iostream>
#include <string>
#include "ShapesGood.h"

// Base Shape class
Shape::Shape() : length(0), width(0), outline_colour("none") {}
Shape::Shape(const int len, const int wid, const std::string outline) : length(len), width(wid), outline_colour(outline) {}
Shape::~Shape() {}
int Shape::getLength() {
  return length;
}
int Shape::getWidth() {
  return width;
}
std::string Shape::getOutline() {
  return outline_colour;
}

// Base Fillable implementation
Fillable::Fillable() : fill_colour("none") {}
Fillable::Fillable(const std::string fill) : fill_colour(fill) {}
Fillable::~Fillable() {}
std::string Fillable::getFill() {
  return fill_colour;
}

// Base Labellable implementation
Labellable::Labellable() : label_text("none") {}
Labellable::Labellable(const std::string text) : label_text(text) {}
Labellable::~Labellable() {}
std::string Labellable::getLabel() {
  return label_text;
}

// Square implementation
Square::Square(const int l, const int w, const std::string border) : Shape(l, w, border) {}
void Square::draw() {
  outline();
}
void Square::outline() {
  std::cout << "\nDrawing a " + outline_colour + " square.";
}
// FilledSquare implementation
FilledSquare::FilledSquare(const int l, const int w, const std::string border, const std::string fill) : Square(l,w,border), Fillable(fill) {}
void FilledSquare::draw() {
  outline();
  fill();
}
void FilledSquare::fill() {
  std::cout << " With " + fill_colour + " fill.";
}
// FilledTextSquare implementation
FilledTextSquare::FilledTextSquare(const int l, const int w, const std::string border, const std::string fill, const std::string text) : FilledSquare(l,w,border,fill), Labellable(text) {}
void FilledTextSquare::draw() {
  outline();
  fill();
  label();
}
void FilledTextSquare::fill() {
  std::cout << " With " + fill_colour + " fill.";
}
void FilledTextSquare::label() {
  std::cout << " Containing the text: \"" << label_text << "\".";
}

// Circle implementation
Circle::Circle(const int l, const int w, const std::string border) : Shape(l, w, border) {}
void Circle::draw() {
  outline();
}
void Circle::outline() {
  std::cout << "\nDrawing a " + outline_colour + " circle.";
}
// FilledCircle implementation
FilledCircle::FilledCircle(const int l, const int w, const std::string border, const std::string fill) : Circle(l, w, border), Fillable(fill) {}
void FilledCircle::draw() {
  outline();
  fill();
}
void FilledCircle::fill() {
  std::cout << " With " + fill_colour + " fill.";
}

// Arc implementation
Arc::Arc(const int l, const int w, const std::string border) : Shape(l, w, border) {}
void Arc::draw() {
  outline();
}
void Arc::outline() {
  std::cout << "\nDrawing a " + outline_colour + " arc.";
}
