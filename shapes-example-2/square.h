//
// Created by Arias Arevalo, Carlos on 4/22/20.
//

#ifndef SHAPES_EXAMPLE_1_SQUARE_H
#define SHAPES_EXAMPLE_1_SQUARE_H

#include "rectangle.h"

#include <string>
using std::string;

class Square : public Rectangle{
public:
	Square(double length);
	virtual string ToString()const;
};


#endif //SHAPES_EXAMPLE_1_SQUARE_H
