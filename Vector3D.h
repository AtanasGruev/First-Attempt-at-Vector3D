#ifndef VECTOR3D_VECTOR3D_H_
#define VECTOR3D_VECTOR3D_H_

class Vector3D
{
private:
	/**
	*����� ������ ��������� ��� ���������� � ������������ ������������, ���������� � x, y � z
	* x, y � z �� �������� ������ ����������� ����������� �������
	*/
	double x, y, z;
public:
	/**
	* ����������� �� ������������
	* ������� ����� ������ (0, 0, 0)
	*/
	Vector3D();
	/**
	* ������� ������ �� ���������� ��������� �� ������������ x, y � z
	* @param xVal
	* @param yVal
	* @param zVal
	*/
	Vector3D(double xVal, double yVal, double zVal);
	/**
	* ����������
	*/
	~Vector3D();
	/**
	* ����� ���������� �� x
	* @return x
	*/
	double getX() const;
	/**
	* ����� ���������� �� y
	* @return y
	*/
	double getY() const;
	/**
	* ����� ���������� �� z
	* @return z
	*/
	double getZ() const;
	/**
	* ���������� ���������� �� �������� �� �������
	* @param secondVector ������
	* @return ��� ������
	*/
	Vector3D operator+(const Vector3D & secondVector) const;
	/**
	* ���������� ���������� �� ��������� �� �������
	* @param secondVector ������
	* @return ��� ������
	*/
	Vector3D operator-(const Vector3D & secondVector) const;
	/**
	* ����� ��� ������ � �������� ����
	* @return ��� ������ � �������� ����
	*/
	Vector3D operator-() const;
	/**
	* �������� �������� � ������� number
	* @param number - ����� � ����� �� �������� ��������
	* @return ��� ������
	*/
	Vector3D operator*(double number) const;
	/**
	* �������� ����� � ������
	* @param number - �����
	* @param vector - ������
	* @return ��� ������
	*/
	friend Vector3D operator*(double number, const Vector3D & vector);
	/**
	* ���������� ���������� �� ��������� �� ����� �� ������ �� ����������� ����, ���� ������
	* �� ���� ������ ������� ������:
	* (x,y,z)
	*/
	friend std::istream & operator>>(std::istream & iStream, Vector3D & vector);
	/**
	* ���������� ���������� �� ������������� (���������) �� ����������� � �������
	������:
	* (x, y, z)
	*/
	friend std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector);
};

void readVector(int n, Vector3D* vector);
void writeVector(int n, Vector3D* vector);
void readInput(char input);

#endif //!VECTOR3D_VECTOR3D_H_