#ifndef _VECTOR_H
#define _VECTOR_H
/* 
SUMMARY
This is a templated 3D Vector class.
*/
template<class T>
class Vector
{
private:
	const int sizeX = 3;
	const int sizeY = 3;
	const int sizeZ = 3;

	T arr[3][3][3];

public:
	//ctor
	Vector();
	//copy ctor
	Vector(const Vector& v);
	//dtor
	~Vector();
	//memory access
	void setValAtPos(int val, int x, int y, int z);
	int getValAtPos(int x, int y, int z);
	//assignment operator =
	Vector& operator = (const Vector& v);
	//operator overloading ==
	bool operator == (const Vector& v);
	//operator overloading +
	Vector& operator + (const Vector& v);
	//operator overload -
	Vector& operator - (const Vector& v);
	//operator overload *
	Vector& operator * (T scalar);

	//bounds checking
	void boundChecking(int n, int dimension);
};

#endif