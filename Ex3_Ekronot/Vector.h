#pragma once

#include <iostream>

class Vector
{
private:
	//Fields
	int* _elements;
	int _size;
	int _capacity;
	int _resizeFactor;

public:
	//A
	Vector(int n);//constructor
	~Vector();//destructor
	int size() const;//return size of vector
	int capacity() const;//return capacity of vector
	int resizeFactor() const; //return vector's resizeFactor
	bool empty() const; //returns true if size = 0

	//Modifiers
	void push_back(const int& val);//adds element at the end of the vector
	int pop_back();//removes and returns the last element of the vector
	void reserve(const int n);//change the capacity
	void resize(const int n);//change _size to n, unless n is greater than the vector's capacity
	void assign(const int val);//assigns val to all elemnts
	void resize(const int n, const int& val);//same as above, if new elements added their value is val

	Vector(const Vector& other); //copy constructor
	Vector& operator=(const Vector& other); //copy assignment operator

	int& operator[](int n) const;
};