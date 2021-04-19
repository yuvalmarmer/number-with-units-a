#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <string>

using namespace std;


namespace ariel{
    class NumberWithUnits{
        public:
            //Read units from file
            static void read_units(ifstream& file){
                string line;
                if (file.is_open())
                {
                    while (getline(file,line) )
                    {
                        //cout << line << '\n';
                    }
                    file.close();
                }
                else cout << "Unable to open file"; 
            }

            NumberWithUnits(double value, std::string type);
            NumberWithUnits(int value, std::string type);
            //For + operators
            const NumberWithUnits operator+(const NumberWithUnits& other) const;
            NumberWithUnits& operator+=(const NumberWithUnits& other);
            const NumberWithUnits operator+() const{
                return NumberWithUnits(this->value, this->type);
            }

            //For - operator
            const NumberWithUnits operator-(const NumberWithUnits& other) const;
            NumberWithUnits& operator-=(const NumberWithUnits& other);
            const NumberWithUnits operator-() const{
                return NumberWithUnits(this->value*(-1.0), this->type);
            }

            //For < operator 
            bool operator<(const NumberWithUnits& other);
            bool operator<=(const NumberWithUnits& other);

            //For > operator
            bool operator>(const NumberWithUnits& other);
            bool operator>=(const NumberWithUnits& other);

            bool operator==(const NumberWithUnits& other);
            bool operator!=(const NumberWithUnits& other);


            NumberWithUnits& operator++() {
                value++;
                return *this;
            }

            // postfix increment:
            const NumberWithUnits operator++(int dummy_flag_for_postfix_increment) {
                NumberWithUnits copy = *this;
                value++;
                return copy;
            }

            NumberWithUnits& operator--() {
                value--;
                return *this;
            }

            // postfix increment:
            const NumberWithUnits operator--(int dummy_flag_for_postfix_increment) {
                NumberWithUnits copy = *this;
                value--;
                return copy;
            }


            friend std::ostream& operator<< (std::ostream& os, const NumberWithUnits& n);
            friend std::istream& operator>> (istream& input, NumberWithUnits& n) ;

            friend const NumberWithUnits operator*(const NumberWithUnits& n1, const double num);
            friend const NumberWithUnits operator*(const double num,const NumberWithUnits& n1);

            double value;
            string type;

            
        private:
            static map<string, string> map;

    };
}