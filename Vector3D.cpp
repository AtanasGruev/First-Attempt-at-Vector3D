#include <iostream>
#include "Vector3D.h"
#include <string>
#include <cmath>
#include <cassert>

Vector3D::Vector3D() : x(0), y(0), z(0)
{}

Vector3D::Vector3D(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal)
{}

Vector3D::~Vector3D()
{
	/**std::cout << "Destructing object...\n";
	*/
}

double Vector3D::getX() const
{
	return x;
}

double Vector3D::getY() const
{
	return y;
}

double Vector3D::getZ() const
{
	return z;
}

Vector3D Vector3D::operator+(const Vector3D & secondVector) const
{
	Vector3D resultVector(x + secondVector.x, y + secondVector.y, z + secondVector.z);
	return resultVector;
}

Vector3D Vector3D::operator-(const Vector3D & secondVector) const
{
	Vector3D resultVector(x - secondVector.x, y - secondVector.y, z - secondVector.z);
	return resultVector;
}

Vector3D Vector3D::operator-() const
{
	Vector3D resultVector(-x, -y, -z);
	return resultVector;
}

Vector3D Vector3D::operator*(double number) const
{
	Vector3D resultVector(x*number, y*number, z*number);
	return resultVector;
}

Vector3D operator*(double number, const Vector3D & vector)
{
	Vector3D resultVector(number*vector.x, number*vector.y, number*vector.z);
	return resultVector;
}

std::istream & operator>>(std::istream & iStream, Vector3D & vector)
{
	char symbol;
	iStream >> symbol >> vector.x >> symbol >> vector.y >> symbol >> vector.z >> symbol;
	return iStream;
}

std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector)
{
	oStream << "(" << vector.x << "," << vector.y << "," << vector.z << ")";
	return oStream;
}

void readVector(int n, Vector3D* vector)
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> vector[i];
	}
}

void writeVector(int n, Vector3D* vector)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << vector[i];
	}
}

void readInput(char input)
{
	/** n представлява броя вектори
	*/
	int n;
	/** NUM представлява числото, с което умножаваме вектора
	*/
	int NUM = 0;

	/** Ако първият символ е +, функцията събира n вектора, започвайки от първия
	*/
	if (input == '+')
	{
		std::cin >> n;
		if (n != 0)
		{
			Vector3D* vector = new Vector3D[n];
			assert(vector != NULL);
			readVector(n, vector);
			Vector3D resultVector = vector[0];

			for (int i = 1; i < n; i++)
			{
				resultVector = resultVector + vector[i];
			}
			std::cout << resultVector << std::endl;
			delete[] vector;
		}
		else { std::cout << ""; }
	}

	/** Ако първият символ е -, функцията изважда n вектора, започвайки от първия
	*/
	else if (input == '-')
	{
		std::cin >> n;
		if (n != 0)
		{
			Vector3D* vector = new Vector3D[n];
			assert(vector != NULL);
			readVector(n, vector);
			Vector3D resultVector = vector[0];

			for (int i = 1; i < n; i++)
			{
				resultVector = resultVector - vector[i];
			}
			std::cout << resultVector << std::endl;
			delete[] vector;
		}
		else { std::cout << ""; }
	}

	/** Ако първият символ е N, функцията започва с NEG
	* В съответствие с това, функцията принтира n противоположни вектора
	*/
	else if (input == 'N')
	{
		std::cin.ignore(256, ' ');
		std::cin >> n;
		if (n != 0)
		{
			Vector3D* vector = new Vector3D[n];
			assert(vector != NULL);
			readVector(n, vector);
			Vector3D* resultVector = new Vector3D[n];
			assert(resultVector != NULL);
			for (int i = 0; i < n; i++)
			{
				resultVector[i] = -vector[i];
			}
			writeVector(n, resultVector);
			delete[] vector;
			delete[] resultVector;
		}
		else { std::cout << ""; }
	}

	/** Ако първият символ е *, функцията умножава NUM  с n вектора
	*/
	else if (input == '*')
	{
		std::cin >> NUM;
		std::cin.ignore();
		std::cin >> n;
		if (n != 0)
		{
			Vector3D* vector = new Vector3D[n];
			assert(vector != NULL);
			readVector(n, vector);
			Vector3D* resultVector = new Vector3D[n];
			assert(resultVector != NULL);
			for (int i = 0; i < n; i++)
			{
				resultVector[i] = vector[i] * NUM;
			}
			writeVector(n, resultVector);
			delete[] vector;
			delete[] resultVector;
		}
		else { std::cout << ""; }
	}

	/** Ако функцията започва с число, първо проверяваме кое е то
	* След това го умножаваме с n вектора
	*/
	else if (input >= 48 && input <= 57)
	{
		/** В масив ще съхраним остатъка от числото NUM, който може да се състои от 0, 1 или 2 цифри
		* Това установяваме с цикъл и брояч, който после се използва, за да определим порядъка на NUM
		*/
		char numLeft[3];
		int counter = 0;
		for (int i = 0; i < 3; i++)
		{
			std::cin >> numLeft[i];
			counter++;
			if (numLeft[i] == '*')
			{
				break;
			}
		}
		int numRemainder = atoi(numLeft);
		NUM = (int)(input - 48) * pow(10, counter - 1) + numRemainder;

		std::cin >> n;
		if (n != 0)
		{
			Vector3D* vector = new Vector3D[n];
			assert(vector != NULL);
			readVector(n, vector);
			Vector3D* resultVector = new Vector3D[n];
			assert(resultVector != NULL);
			for (int i = 0; i < n; i++)
			{
				resultVector[i] = NUM * vector[i];
			}
			writeVector(n, resultVector);
			delete[] vector;
			delete[] resultVector;
		}
		else { std::cout << ""; }
	}
}