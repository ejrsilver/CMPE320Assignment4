#pragma once

#include <string>

class Shape {
public:
  Shape();
  Shape(int, int, std::string);
  virtual ~Shape();
  virtual void draw() = 0;
  int getLength();
  int getWidth();
  std::string getOutline();
private:
  int length, width;
protected:
  std::string outline_colour;
};

class Fillable {
public:
  Fillable();
  Fillable(std::string);
  virtual ~Fillable();
  virtual void fill() = 0;
  std::string getFill();
protected:
  std::string fill_colour;
};

class Labellable {
public:
  Labellable();
  Labellable(std::string);
  virtual ~Labellable();
  virtual void label() = 0;
  std::string getLabel();
protected:
  std::string label_text;
};

class Square : public Shape {
public:
  Square(int l, int w, std::string border);
  void draw();
  void outline();
};

class FilledSquare : public Square, public Fillable {
public:
  FilledSquare(int l, int w, std::string border, std::string fill);
  void draw();
  void fill();
};

class FilledTextSquare : public FilledSquare, public Labellable {
public:
  FilledTextSquare(int l, int w, std::string border, std::string fill, std::string text);
  void draw();
  void fill();
  void label();
};

class Circle : public Shape {
public:
  Circle(int l, int w, std::string border);
  void draw();
  void outline();
};

class FilledCircle : public Circle, public Fillable {
public:
  FilledCircle(int l, int w, std::string border, std::string fill);
  void draw();
  void fill();
};

class Arc : public Shape {
public:
  Arc(int l, int w, std::string border);
  void draw();
  void outline();
};
