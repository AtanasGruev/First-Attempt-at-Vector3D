#ifndef VECTOR3D_VECTOR3D_H_
#define VECTOR3D_VECTOR3D_H_

class Vector3D
{
private:
	/**
	*Всеки вектор притежава три координати в триизмерното пространство, означаваме с x, y и z
	* x, y и z са зададени спрямо правоъгълна координатна система
	*/
	double x, y, z;
public:
	/**
	* Конструктор по подразбиране
	* Създава нулев вектор (0, 0, 0)
	*/
	Vector3D();
	/**
	* Създава вектор по зададените стойности за компонентите x, y и z
	* @param xVal
	* @param yVal
	* @param zVal
	*/
	Vector3D(double xVal, double yVal, double zVal);
	/**
	* Деструктор
	*/
	~Vector3D();
	/**
	* Връща стойността за x
	* @return x
	*/
	double getX() const;
	/**
	* Връща стойността за y
	* @return y
	*/
	double getY() const;
	/**
	* Връща стойността за z
	* @return z
	*/
	double getZ() const;
	/**
	* Предоставя възможност за събиране на вектори
	* @param secondVector вектор
	* @return Нов вектор
	*/
	Vector3D operator+(const Vector3D & secondVector) const;
	/**
	* Предоставя възможност за изваждане на вектори
	* @param secondVector вектор
	* @return Нов вектор
	*/
	Vector3D operator-(const Vector3D & secondVector) const;
	/**
	* Връща нов вектор с променен знак
	* @return Нов вектор с променен знак
	*/
	Vector3D operator-() const;
	/**
	* Умножава векторът с числото number
	* @param number - число с което се умножава векторът
	* @return Нов вектор
	*/
	Vector3D operator*(double number) const;
	/**
	* Умножава число с вектор
	* @param number - число
	* @param vector - вектор
	* @return Нов вектор
	*/
	friend Vector3D operator*(double number, const Vector3D & vector);
	/**
	* Предоставя възможност за въвеждане на данни за вектор от стандартния вход, като трябва
	* да бъде спазен следния формат:
	* (x,y,z)
	*/
	friend std::istream & operator>>(std::istream & iStream, Vector3D & vector);
	/**
	* Предоставя възможност за визуализиране (извеждане) на стойностите в следния
	формат:
	* (x, y, z)
	*/
	friend std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector);
};

void readVector(int n, Vector3D* vector);
void writeVector(int n, Vector3D* vector);
void readInput(char input);

#endif //!VECTOR3D_VECTOR3D_H_