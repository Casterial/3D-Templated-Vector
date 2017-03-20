#include "Vector.h"
#include <iostream>
#include <cassert>



//def ctor
template <class T>
Vector<T>::Vector<T>()
{
	//set all elements to 0
	for (int x = 0; x < sizeX; x++) 
	{
		for (int y = 0; y < sizeY; y++)
		{
			for (int z = 0; z < sizeZ; z++)
			{
				arr[x][y][z] = 0;
			}
		}
	}
}

//copy ctor
template <class T>
Vector<T>::Vector<T>(const Vector<T>& v)
{
	//use the assignment operator to do this
	*this = v;
}

//dtor
template <class T>
Vector<T>::~Vector<T>()
{

}

//memory access
//setter
template <class T>
void Vector<T>::setValAtPos(int val, int x, int y, int z)
{
	//check bounds on attempted access
	boundChecking(x, 1);
	boundChecking(y, 2);
	boundChecking(z, 3);

	//if it hasnt asserted then the location exist
	arr[x][y][z] = val;
}

//getter
template <class T>
int Vector<T>::getValAtPos(int x, int y, int z)
{
	boundChecking(x, 1);
	boundChecking(y, 2);
	boundChecking(z, 3);

	//if it hasn't asserted then the location exist
	return arr[x][y][z];
}

//bound checking
template <class T>
void Vector<T>::boundChecking(int n, int dimension)
{
	//switch statement for which bound to check
	switch (dimension)
	{
		//if first dimension, check x
	case 1:
		assert(n < sizeX);
		break;
		//if second dimension, check y
	case 2:
		assert(n < sizeY);
		break;
		//if third dimension, check z
	case 3:
		assert(n < sizeZ);
		break;
		//if neither, break case;
	default:
		break;
	}
}

//assignment operator =
template <class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& v) {
	//copy each individual element
	for (int x = 0; x < sizeX; x++) 
	{
		for (int y = 0; y < sizeY; y++) 
		{
			for (int z = 0; z < sizeZ; z++)
			{
				this->arr[x][y][z] = v.arr[x][y][z];
			}
		}
	}
	return *this;
}

//overloading operator ==
template <class T>
bool Vector<T>::operator==(const Vector<T>& v)
{
	//cycle through all elements
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			for (int z = 0; z < sizeZ; z++)
			{
				//if a non-identical encounter happens, it is not equal
				if (this->arr[x][y][z] != v.arr[x][y][z])
				{
					return false;
				}
			}
		}
	}
	//if all the elements pass the check, the vectors are equal
	return true;
}

//overloading operator +
template <class T>
Vector<T>& Vector<T>::operator+(const Vector<T>& v)
{
	//create a new memory space to return;
	Vector<T> *result = new Vector<T>;
	//cycle through all elements
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			for (int z = 0; z < sizeZ; z++)
			{
				//add each individual element
				result->arr[x][y][z] = this->arr[x][y][z] + v.arr[x][y][z];
			}
		}
	}
	return *result;
}

//overloading operator -
template <class T>
Vector<T>& Vector<T>::operator-(const Vector<T>& v)
{
	//create a new memory space to return
	Vector<T> *result = new Vector<T>;
	//cycle through all elements
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			for (int z = 0; z < sizeZ; z++)
			{
				result->arr[x][y][z] = this->arr[x][y][z] - v.arr[x][y][z];
			}
		}
	}
	return *result;
}

//overloading operator *
template <class T>
Vector<T>& Vector<T>::operator*(T scalar)
{
	Vector<T> *result = new Vector<T>;
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			for (int z = 0; z < sizeZ; z++)
			{
				result->arr[x][y][z] = this->arr[x][y][z] * scalar;
			}
		}
	}
	return *result;
}

//template instantiations
template class Vector<int>;
template class Vector<double>;