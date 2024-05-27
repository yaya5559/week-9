#include "shape.h"
#include "triangle.h"
#include "isosceles.h"
#include "ellipse.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"

#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;

size_t Menu();
void DeleteShapes(vector<Shape*>& shapes);

int main() {
	vector<Shape*> shapes;
	int menuOption;
	while ( (menuOption = Menu()) != 11){
		if (menuOption == 1){ // Ellipse
			double a, b;
			cout << "Input major semi-axis length: ";
			cin >> a;
			cout << "Input minor semi-axis length: ";
			cin >> b;
			shapes.push_back(new Ellipse(a, b));
			cout << "Inserted... " << endl << endl;
		}else if (menuOption == 2){ // Circle
			double radius;
			cout << "Input radius length: ";
			cin >> radius;
			shapes.push_back(new Circle(radius));
			cout << "Inserted... " << endl << endl;
		}else if (menuOption == 3){ // Triangle
			double a, b, c;
			cout << "Input length of three sides: ";
			cin >> a >> b >> c;
			shapes.push_back(new Triangle(a, b, c));
			cout << "Inserted... " << endl << endl;
		}else if (menuOption == 4){ // Isosceles
			double equalSidesLength, otherSideLength;
			cout << "Input equal side length: ";
			cin >> equalSidesLength;
			cout << "Input other side length: ";
			cin >> otherSideLength;
			shapes.push_back(new Isosceles(equalSidesLength, otherSideLength));
			cout << "Inserted... " << endl << endl;
		}else if (menuOption == 5){ // Rectangle
			double base, height;
			cout << "Input base length: ";
			cin >> base;
			cout << "Input height length: ";
			cin >> height;
			shapes.push_back(new Rectangle(base, height));
			cout << "Inserted... " << endl << endl;
		}else if (menuOption == 6){ // Square
			double length;
			cout << "Input side length: ";
			cin >> length;
			shapes.push_back(new Square(length));
			cout << "Inserted... " << endl << endl;
		}else if (menuOption == 7){ // List all Ellipses
			cout << "Only Ellipses" << endl;
			for (Shape* shape: shapes){
				if (dynamic_cast<Ellipse*>(shape) != nullptr) {
					Ellipse* ellipse = dynamic_cast<Ellipse*>(shape);
					cout << shape->ToString() << endl;
					cout << "\tPerimeter:    " << shape->Perimeter() << endl;
					cout << "\tArea:         " << shape->Area() << endl;
					cout << "\tEccentricity: " << ellipse->Eccentricity() << endl;
					cout << endl;
				}
			}
		}else if (menuOption == 8){ // List all Triangles
            cout << "Only triangles" << endl;
            for (Shape* shape: shapes){
                if (dynamic_cast<Triangle*>(shape) != nullptr){
                    Triangle* tr= dynamic_cast<Triangle*>(shape);
                    cout << shape->ToString() << endl;
                    cout << "\tPerimeter:    " << shape->Perimeter() << endl;
                    cout << "\tArea:         " << shape->Area() << endl;
                    cout << "\tAngle AB: " << tr->AngleAB() << endl;
                    cout << "\tAngleAC: " << tr->AngleAC() << endl;
                    cout << "\tAngleBC: " << tr->AngleBC() << endl;
                    cout << "\tHyptenuse: " << tr->Hypotenuse() << endl;

                    cout << endl;

                }
            }


		}else if (menuOption == 9){ // List all Rectangles
            cout << "Only Rectangles" << endl;
            for (Shape* shape: shapes){
                if (dynamic_cast<Rectangle*>(shape) != nullptr){
                    Rectangle* rec = dynamic_cast<Rectangle*>(shape);
                    cout << shape->ToString() << endl;
                    cout << "\tPerimeter:    " << shape->Perimeter() << endl;
                    cout << "\tArea:         " << shape->Area() << endl;

                }
            }

		}else if (menuOption == 10){ // List all shapes
			for (Shape* shape: shapes){
				cout << shape->ToString() << endl;
				cout << "\tPerimeter:    " << shape->Perimeter() << endl;
				cout << "\tArea:         " << shape->Area() << endl;
				cout << endl;
			}
		}else{
			cerr << "This should never happen!" << endl;
			break;
		}
	}
	DeleteShapes(shapes);
	return 0;
}

size_t Menu(){
	int option = 0;
	while(true){
		cout << "1. Add an Ellipse" << endl;
		cout << "2. Add a Circle" << endl;
		cout << "3. Add a Triangle" << endl;
		cout << "4. Add an Isosceles Triangle" << endl;
		cout << "5. Add a Rectangle" << endl;
		cout << "6. Add a Square" << endl;
		cout << "7. List all Ellipses" << endl;
		cout << "8. List all Triangles" << endl;
		cout << "9. List all Rectangles" << endl;
		cout << "10. List all Shapes" << endl;
		cout << "11. Exit" << endl;

		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Incorrect input!" << endl;
			continue;
		}
		if (option < 1 || option > 11){
			cerr << "Incorrect menu option!" << endl;
			continue;
		}
		break;
	}
	return static_cast<size_t>(option);
}
void DeleteShapes(vector<Shape*>& shapes){
	for (Shape* shape : shapes)
		delete shape;
}
