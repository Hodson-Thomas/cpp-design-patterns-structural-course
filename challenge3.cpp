//
// Created by thoma on 14/02/2025.
//

#include <iostream>
#include <vector>
using namespace std;

class IShape {
public:
    void virtual draw() const;

    virtual ~IShape() = default;
};

class CompositeShape : public IShape {
    vector<IShape *> shapes;

public:
    void add_shape(IShape &shape) {
        shapes.push_back(&shape);
    }

    void remove_shape(const IShape &shape) {
        for (auto it = shapes.begin(); it != shapes.end(); ++it) {
            if (*it == &shape) {
                shapes.erase(it);
                break;
            }
        }
    }

    void draw() const override {
        cout << "Drawing composite shape : " << endl;
        for (auto i = shapes.begin(); i != shapes.end(); ++i) {
            (*i)->draw();
        }
    }
};

class Circle : public IShape {
public:
    Circle(double radius) : m_Radius(radius) {
    }

    void draw() const override {
        cout << "Drawing a circle with radius " << m_Radius << endl;
    }

private:
    double m_Radius;
};

class Rectangle : public IShape {
public:
    Rectangle(double width, double height) : m_Width(width), m_Height(height) {
    }

    void draw() const override {
        cout << "Drawing a rectangle with width " << m_Width << " and height " << m_Height << endl;
    }

private:
    double m_Width;
    double m_Height;
};

class Triangle : public IShape {
public:
    Triangle(double side1, double side2, double side3) : m_Side1(side1), m_Side2(side2), m_Side3(side3) {
    }

    void draw() const override {
        cout << "Drawing a triangle with sides " << m_Side1 << ", " << m_Side2 << ", and " << m_Side3 << endl;
    }

private:
    double m_Side1;
    double m_Side2;
    double m_Side3;
};
