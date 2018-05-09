#include "Vector3D.h"

Vector3D::Vector3D() : x(0), y(0), z(0)
{}

Vector3D::Vector3D(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal)
{}

Vector3D::~Vector3D()
{
	/**std::cout << "Destrcuting object...\n";
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
	Vector3D resultVector = *this;
	if (x != 0)
	{
		resultVector.x = -x;
	}
	if (y != 0)
	{
		resultVector.y = -y;
	}
	if (z != 0)
	{
		resultVector.z = -z;
	}
	return resultVector;
}

Vector3D Vector3D::operator*(double number) const
{
	Vector3D resultVector;
	if (number != 0)
	{
		resultVector.x = -x;
		resultVector.y = -y;
		resultVector.z = -z;
	}
	return resultVector;
}

Vector3D operator*(double number, const Vector3D & vector)
{
	Vector3D resultVector(number*vector.x, number*vector.y, number*vector.z);
	return resultVector;
}

std::istream & operator>>(std::istream & iStream, Vector3D & vector)
{
	char otherSymbol;
	iStream >> otherSymbol >> vector.x >> otherSymbol >> vector.y >> otherSymbol >> vector.z >> otherSymbol;
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
	if (n == 1) std::cout << vector[0];
	else
	{
		for (int i = 0; i < n-1; i++)
		{
			std::cout << vector[i] << " ";
		}
		std::cout << vector[n-1];
	}
}

void readInput(char input)
{
	int numVectors;
	double NUM = 0.0;
	char firstSymbol;

	if (input == '+' || input == '-')
	{
		std::cin >> firstSymbol;
		std::cin >> numVectors;
		if (numVectors == 0) return;
		Vector3D* vector = new Vector3D[numVectors];
		assert(vector != NULL);
		readVector(numVectors, vector);

		Vector3D resultVector = vector[0];
		if (input == '+')
		{
			for (int i = 1; i < numVectors; i++)
			{
				resultVector = resultVector + vector[i];
			}
			std::cout << resultVector << std::endl;
		}
		else
		{
			for (int i = 1; i < numVectors; i++)
			{
				resultVector = resultVector - vector[i];
			}
			std::cout << resultVector << std::endl;
		}

		delete[] vector;
	}

	else if (input == 'N')
	{
		std::cin >> firstSymbol;
		std::cin.ignore(2);
		std::cin >> numVectors;
		if (numVectors == 0) return;
		Vector3D* vector = new Vector3D[numVectors];
		assert(vector != NULL);
		readVector(numVectors, vector);

		Vector3D* resultVector = new Vector3D[numVectors];
		assert(resultVector != NULL);
		for (int i = 0; i < numVectors; i++)
		{
			resultVector[i] = -vector[i];

		}
		writeVector(numVectors, resultVector);

		delete[] resultVector;
		delete[] vector;
	}

	else if (input == '*')
	{
		std::cin >> firstSymbol;
		std::cin >> NUM;
		std::cin >> numVectors;
		if (numVectors == 0) return;

		Vector3D* vector = new Vector3D[numVectors];
		assert(vector != NULL);
		readVector(numVectors, vector);

		Vector3D* resultVector = new Vector3D[numVectors];
		assert(resultVector != NULL);
		for (int i = 0; i < numVectors; i++)
		{
			resultVector[i] = vector[i] * NUM;
		}
		writeVector(numVectors, resultVector);

		delete[] resultVector;
		delete[] vector;
	}

	else
	{
		std::cin >> NUM;
		std::cin >> numVectors;
		if (numVectors == 0) return;

		Vector3D* vector = new Vector3D[numVectors];
		assert(vector != NULL);
		readVector(numVectors, vector);

		Vector3D* resultVector = new Vector3D[numVectors];
		assert(resultVector != NULL);
		for (int i = 0; i < numVectors; i++)
		{
			resultVector[i] = vector[i] * NUM;
		}
		writeVector(numVectors, resultVector);

		delete[] resultVector;
		delete[] vector;
	}
}