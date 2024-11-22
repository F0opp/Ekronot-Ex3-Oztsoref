#include "Vector.h"

#include <iostream>

//A
Vector::Vector(int n)
{
	if (n < 2)
	{
		n = 2;
	}

	_capacity = n;
	_size = 0;
	_resizeFactor = n;
	_elements = new int[_capacity];
}

Vector::~Vector()
{
	delete[] _elements;
}

int Vector::size() const
{
	return _size;
}

int Vector::capacity() const
{
	return _capacity;
}

int Vector::resizeFactor() const
{
	return _resizeFactor;
}
bool Vector::empty() const
{
	return _size == 0;
}

//B
void Vector::push_back(const int& val)
{
	if (_size == _capacity)
	{
		reserve(_capacity);
	}
	_elements[_size] = val;
	_size++;
}

int Vector::pop_back()
{
	if (_size == 0)
	{
		std::cout << "error: pop from empty vector" << std::endl;
		return -9999;
	}
	
	_size--;
	return _elements[_size];
}

void Vector::reserve(const int n)
{
	int i = 0;

	int newCapacity = _capacity;
	while (newCapacity <= n)
	{
		newCapacity += _resizeFactor;
	}

	int* newElements = new int[newCapacity];//Allocate memory for newElements

	//copy old elements
	for (i = 0; i < _size; i++)
	{
		newElements[i] = _elements[i];
	}

	//free old memory
	delete[] _elements;
	
	_elements = newElements;
	_capacity = newCapacity;
}

void Vector::resize(const int n)
{
	int i = 0;

	if (n > _capacity)
	{
		reserve(n);
	}

	for (i = _size; i < n; i++)
	{
		_elements[i] = 0;
	}
	_size = n;
}

void Vector::assign(const int val)
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		_elements[i] = val;
	}
}

void Vector::resize(const int n, const int& val)
{
	int i = 0;

	if (n > _capacity)
	{
		reserve(n);
	}

	for (i = _size; i < n; i++)
	{
		_elements[i] = val;
	}
	_size = n;
}

Vector::Vector(const Vector& other)
{
	int i = 0;
	_size = other._size;
	_capacity = other._capacity;
	_resizeFactor = other._resizeFactor;
	_elements = new int[_capacity];

	for (i = 0; i < _size; i++)
	{
		_elements[i] = other._elements[i];
	}
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other) 
	{
		int i = 0;
		delete[] _elements;

		_size = other._size;
		_capacity = other._capacity;
		_resizeFactor = other._resizeFactor;

		_elements = new int[_capacity];

		for (i = 0; i < _size; ++i)
		{
			_elements[i] = other._elements[i];
		}
	}
	return *this;
}

int& Vector::operator[](int n) const
{
	if (n < 0 || n >= _size)
	{
		std::cout << "error: index out of bounds" << std::endl;
		return _elements[0];
	}
	return _elements[n];
}