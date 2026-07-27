#ifndef FIXED_HPP
# define FIXED_HPP
# include <cmath>
# include <iostream>
# include <string>
class Fixed
{
  private:
	int32_t _rawBits;                         // value we store as int (fixed)
	static const int32_t _fractionalBits = 8; // const for all classes
  public:
	Fixed();                  // constructor
	Fixed(int const value);   // value int to convert to fixed
	Fixed(float const value); // value float to convert to fixed
	// ocf
	// copy constructor
	Fixed(Fixed const &other);
	Fixed &operator=(Fixed const &other);
	~Fixed();

	// additional setter and getter if it required
	int getRawBits() const;
	void setRawBits(int const newRaw);
	static int getFractionalBits();
	// these are for conversion used
	int toInt() const; // returns raw bits to int to the one who asked
	float toFloat() const;
	//++ -- max min must be here
	// for ++ -- there is prefix and postfix
	// prefix add then return the original obj

	Fixed &operator++();
	Fixed &operator--();

	// here we need new obj
	Fixed operator++(int);
	Fixed operator--(int);

	// next is min and max are static bc i want them to be part from this class not obj
	static Fixed &min(Fixed &a, Fixed &b);
	// overload to take all
	static Fixed const &min(Fixed const &a, Fixed const &b);
	// overload to take all
	static Fixed const &max(Fixed const &a, Fixed const &b);
	// overload to take all
	static Fixed &max(Fixed &a, Fixed &b);
	// overload to take all

	// friend  here bc its easier to get to private data to print it
	friend std::ostream &operator<<(std::ostream &os, Fixed const &obj);
};
//+-*/ > < == != <= >=
// now are the + - * /
Fixed operator+(Fixed const&a, Fixed const&b) ;
Fixed operator-(Fixed const&a, Fixed const&b) ;
Fixed operator*(Fixed const&a, Fixed const&b) ;
Fixed operator/(Fixed const&a, Fixed const&b) ;
// and next is comparison ops
bool operator>(Fixed const &a, Fixed const &b);
bool operator==(Fixed const &a, Fixed const &b);
// from these 2 we make the remains
bool operator<(Fixed const &a, Fixed const &b);
bool operator!=(Fixed const &a, Fixed const &b);
bool operator>=(Fixed const &a, Fixed const &b);
bool operator<=(Fixed const &a, Fixed const &b);

#endif