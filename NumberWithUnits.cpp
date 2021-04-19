
#include "NumberWithUnits.hpp"

using namespace ariel;

NumberWithUnits::NumberWithUnits(double _value, std::string _type):value(_value),type(_type){}
NumberWithUnits::NumberWithUnits(int _value, std::string _type):value(_value),type(_type){}
const NumberWithUnits ariel::NumberWithUnits::operator+(const NumberWithUnits& n2) const {
    return NumberWithUnits(this->value+n2.value, n2.type);
}

NumberWithUnits& ariel::NumberWithUnits::operator+=(const NumberWithUnits& n2){
    this->value += n2.value;
    return *this;
}

const NumberWithUnits ariel::NumberWithUnits::operator-(const NumberWithUnits& n2) const{
    return NumberWithUnits(this->value-n2.value, n2.type);
}

NumberWithUnits& ariel::NumberWithUnits::operator-=(const NumberWithUnits& n2){
    this->value -= n2.value;
    return *this;
}
bool ariel::NumberWithUnits::operator==(const NumberWithUnits& n2){
    return true;
}
bool ariel::NumberWithUnits::operator<=(const NumberWithUnits& n2){
    return true;
}
bool ariel::NumberWithUnits::operator>=(const NumberWithUnits& n2){
    return true;
}
bool ariel::NumberWithUnits::operator!=(const NumberWithUnits& n2){
    return true;
}
bool ariel::NumberWithUnits::operator>(const NumberWithUnits& n2){
    return true;
}
bool ariel::NumberWithUnits::operator<(const NumberWithUnits& n2){
    return true;
}
std::ostream& ariel::operator<< (std::ostream& os, const NumberWithUnits& n) {
    os << n.value;
    os << "[";
    os << n.type;
    os << "]";
    return os;
}

const NumberWithUnits ariel::operator*(const double num, const NumberWithUnits& n1){
    return NumberWithUnits(n1.value*num, n1.type);
}

const NumberWithUnits ariel::operator*(const NumberWithUnits& n1, const double num){
    return NumberWithUnits(n1.value*num, n1.type);
}

static std::istream& getAndCheckNextCharIs(std::istream& input, char expectedChar) {
    char actualChar;
    input >> actualChar;
    if (!input) return input;

    if (actualChar!=expectedChar) 
        // failbit is for format error
        input.setstate(ios::failbit);
    return input;
}


std::istream& ariel::operator>> (istream& input, NumberWithUnits& n) {


    double _value;
    string _type;

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if ( (!(input >> _value))                 ||
         (!getAndCheckNextCharIs(input,'['))  ||
         (!(input >> _type))                 ||
         (!(getAndCheckNextCharIs(input,']'))) ) {

        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear(); // clear error so seekg will work
        input.seekg(startPosition); // rewind
        input.clear(errorState); // set back the error flag
    } else {
        n.value = _value;
        n.type = _type;
    }

    return input;
    //---------------------------------------------
}


