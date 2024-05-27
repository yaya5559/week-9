//
// Created by Arias Arevalo, Carlos on 4/22/20.
//

#include "square.h"
#include "rectangle.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Square::Square(double length) : Rectangle(length, length){

}

string Square::ToString() const {
	stringstream retVal;
	retVal << "{Square " << Rectangle::ToString() << "}";
	return retVal.str();
}
