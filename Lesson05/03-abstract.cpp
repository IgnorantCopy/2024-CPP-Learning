//
// Created by Ignorant on 2024/4/28.
//

#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846
#define MAX_NUM_OF_FIGURES 100
using namespace std;

// abstract class: has pure virtual function in it
class Figure {
public:
    /*
     * pure virtual function
     *   > not specified in base class
     *   > no implementation in base class
     *   > must be implemented in derived class
     */
    virtual double output() = 0;
    virtual void getData() = 0;
    
    virtual ~Figure() = default;
};

class Rectangle : public Figure {
    double width;
    double height;
public:
    Rectangle(): width(0), height(0) {}
    Rectangle(double w, double h): width(w), height(h) {}
    
    double getWidth() const { return width; }
    void setWidth(double w) { width = w; }
    double getHeight() const { return height; }
    void setHeight(double h) { height = h; }
    
    double output() override { return width * height; }
    void getData() override {
        cout << "Please enter the width and height of the rectangle: " << endl;
        cin >> width >> height;
    }
};

class Circle : public Figure {
    double radius;
public:
    Circle(): radius(0) {}
    explicit Circle(double r): radius(r) {}
    
    double getRadius() const { return radius; }
    void setRadius(double r) { radius = r; }
    
    double output() override { return PI * radius * radius; }
    void getData() override {
        cout << "Please enter the radius of the circle: " << endl;
        cin >> radius;
    }
};

class Line : public Figure {
    double x1;
    double y1;
    double x2;
    double y2;
public:
    Line(): x1(0), y1(0), x2(0), y2(0) {}
    Line(double x1, double y1, double x2, double y2): x1(x1), y1(y1), x2(x2), y2(y2) {}
    
    double getX1() const { return x1; }
    void setX1(double x) { x1 = x; }
    double getY1() const { return y1; }
    void setY1(double y) { y1 = y; }
    double getX2() const { return x2; }
    void setX2(double x) { x2 = x; }
    double getY2() const { return y2; }
    void setY2(double y) { y2 = y; }
    
    double output() override { return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); }
    void getData() override {
        cout << "Please enter the coordinate of the start point of the line: " << endl;
        cin >> x1 >> y1;
        cout << "Please enter the coordinate of the end point of the line: " << endl;
        cin >> x2 >> y2;
    }
};

int main() {
    Figure *figures[MAX_NUM_OF_FIGURES];
    int flag = 0;
    int index = 0;
    for (int i = 0; i < MAX_NUM_OF_FIGURES; i++) {
        int type;
        cout << "Please enter the type of the figure (1: rectangle, 2: circle, 3: line, 0: exit): " << endl;
        cin >> type;
        if (type == 0) {
            flag = 1;
            break;
        }
        switch (type) {
            case 1:
                figures[index] = new Rectangle();
                figures[index++]->getData();
                break;
            case 2:
                figures[index] = new Circle();
                figures[index++]->getData();
                break;
            case 3:
                figures[index] = new Line();
                figures[index++]->getData();
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }
    }
    if (flag == 0) {
        cout << "Sorry, you have exceeded the maximum number of figures." << endl;
    }
    for (int i = 0; i < index; i++) {
        cout << figures[i]->output() << endl;
    }
    return 0;
}
