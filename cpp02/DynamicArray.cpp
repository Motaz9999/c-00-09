/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DynamicArray.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 12:03:12 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/25 13:19:51 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DynamicArray.hpp"
#include <string>

// class DynamicArray
// {
//     public:
DynamicArray::DynamicArray() : _data(NULL), _size(0)
{
	std::cout << "[DynamicArray] Default constructor" << std::endl;
	_data = new int[1]; // must at least have one element
	_data[0] = 0;       // and must have init value
}

DynamicArray::DynamicArray(int size, int fillValue) : _data(NULL),
	_size((size > 0) ? size : 0)
{
	std::cout << "[DynamicArray] Parameterized constructor (size=" << _size << ",fill=" << fillValue << ")" << std::endl;
	_data = new int[(_size > 0) ? _size : 1];
	for (int i = 0; i < _size; i++)
	{
		_data[i] = fillValue;
	}
}
 DynamicArray::DynamicArray(int size) : _data(NULL),
	_size((size > 0) ? size : 0)
{
	std::cout << "[DynamicArray] Parameterized constructor (size=" << _size << ")" << std::endl;
	_data = new int[_size > 0 ? _size : 1];
	for (int i = 0; i < _size; ++i)
		_data[i] = 0;
}

// copy array
DynamicArray::DynamicArray(DynamicArray const &other) : _data(NULL),
	_size(other._size)
{
	std::cout << "[DynamicArray] Copy constructor (size=" << _size << ")" << std::endl;
	_data = new int[_size > 0 ? _size : 1];
	for (int i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
}
// assign ops  we will use swap
DynamicArray &DynamicArray::operator=(DynamicArray const &other)
{
	std::cout << "[DynamicArray] operator= (canonical four-step)" << std::endl;
	// Step 1: Self-assignment guard.
	// If left and right are the same object, releasing _data would corrupt the
	// source we are about to copy from. Return immediately.
	if (this == &other)
	{
		std::cout << "  (self-assignment — no-op)" << std::endl;
		return (*this);
	}
	// Step 2: Release the resource *this currently owns.
	// Without this step: the old array leaks every time assignment occurs.
	// _data = NULL immediately: if new (Step 3) throws, destructor sees NULL safely.
	std::cout << "  Step 2: delete[] _data (was size=" << _size << ")" << std::endl;
	delete[] _data;
	_data = NULL;
	// Step 3: Deep copy from other.
	// New, independent allocation — this->_data != other._data after this.
	_size = other._size;
	_data = new int[_size > 0 ? _size : 1];
	for (int i = 0; i < _size; ++i)
		_data[i] = other._data[i];
	std::cout << "  Step 3: deep copied " << _size << " elements" << std::endl;
	// Step 4: Return *this by reference — enables a = b = c.
	return (*this);
}
DynamicArray::~DynamicArray()
{
	std::cout << "[DynamicArray] Destructor (size=" << _size << ")" << std::endl;
	delete[] _data;
	_data = NULL; // very important
}
// this make sure that the comp dont auto con to Dynamic array and its taking as int
//
// this mean itexplicit DynamicArray(int size); so this mean DynamicArray obj =10 ; is not working and must  write as()
int DynamicArray::getAt(int index) const
{
	if (index < 0 || index >= _size)
		return (-1); // not from the range
	return (_data[index]);
}
void DynamicArray::setAt(int index, int value)
{
	if (index >= 0 && index < _size) // same as up
		_data[index] = value;
}
int DynamicArray::getSize() const
{
	return (_size);
}

// this fun used to swap the data of other obj with this obj so its taking
// usefule info from copy and use it
void DynamicArray::swapWith(DynamicArray &other)
{
	int	*tmpData;
	int	tmpSize;

	std::cout << "  swapWith: exchanging internals" << std::endl;
	tmpData = _data;
	tmpSize = _size;
	_data = other._data;
	_size = other._size;
	other._data = tmpData;
	other._size = tmpSize;
}
//print its data with label 
void	DynamicArray::print(std::string const &label) const
{
      std::cout << "  " << label << ":" <<*this<< "] (adder: " <<  static_cast<void const*>(_data) << ")" << std::endl; 
}
std::ostream &operator<<(std::ostream &os, DynamicArray const &arr)
{
	os << "[";
	for (int i = 0; i < arr._size; i++)
	{
		os << arr._data[i];
		if (i < arr._size - 1)
			os << ", ";
	}
	os << "]" ;
	return (os);
}
//     private:
//     int *_data;
//     int size;
// };