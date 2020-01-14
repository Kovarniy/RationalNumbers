//
//Реализовать класс для работы с рациональными числами (числа вида 𝑝/𝑞). //Перегрузить арифметические операторы, операторы сравнения, ввода и вывода.//Написать программу для демонстрации возможностей класса.
//
//@autor Schemelinin Evgeniy

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class rational
{
private:
	int p;
	unsigned int q;

public:
	rational() { p = q = 0; };
	rational(int p, int q) {
		if (q == 0 && p != 0) 
			throw exception("denominator entered incorrectly");
			
		if (q < 0 && p >0) {
			q *= -1;
			p *= -1;
		}
		this->p = p;
		this->q = q;
	}

	int getP() { return p; };
	int getQ() { return q; };
	void setP(int p) { this->p=p; };
	void setQ(int q) { this->q = q; };

	rational operator +(rational& other) {
		rational tmp;
		if (this->q == other.getQ())
		{
			tmp.p = this->p + other.p;
			tmp.q = this->q;
		}
		else {
			tmp.p = this->p * other.q + this->q * other.p;
			tmp.q = this->q * other.q;
		}
		if (tmp.p == 0)
			tmp.q = 0;
		return tmp;
	}

	rational operator -(rational& other) {
		rational tmp;
		if (this->q == other.getQ())
		{
			tmp.p = this->p - other.p;
			tmp.q = this->q;
			
		}
		else {
			tmp.p = this->p * other.q - this->q * other.p;
			tmp.q = this->q * other.q;
		}
		if (tmp.p == 0)
			tmp.q = 0;
		return tmp;
	}

	rational operator *(rational& other) {
		rational tmp;
		tmp.p = this->p * other.p;
		tmp.q = this->q * other.q;
		return tmp;
	}

	rational operator /(rational& other) {
		/*TODO exceptions devide by 0 */
		rational tmp;
		tmp.p = this->p * other.q;
		if (other.p < 0)
		{
			tmp.q = this->q * (other.p * -1);
			tmp.p *= -1;
		}
		else {
			tmp.q = this->q * other.p;
		}

		return tmp;
	}

	bool operator ==(rational& other) {
		toEqualDenominator(*this, other);
		return this->p == other.p;
	}

	bool operator !=(rational& other) {
		toEqualDenominator(*this, other);
		return this->p != other.p;
	}

	bool operator <(rational& other) {
		toEqualDenominator(*this, other);
		return this->p < other.p;
	}

	bool operator >(rational& other) {
		toEqualDenominator(*this, other);
		return this->p > other.p;
	}

	bool operator <=(rational& other) {
		toEqualDenominator(*this, other);
		return this->p <= other.p;
	}

	bool operator >=(rational& other) {
		toEqualDenominator(*this, other);
		return this->p >= other.p;
	}

	void toEqualDenominator(rational& left, rational& right) {
		if (left.q == right.q) return;

		int tmp1 = right.q;
		int tmp2 = left.q;
		right.q *= tmp2;
		right.p *= tmp2;
		left.q *= tmp1;
		left.p *= tmp1;
	}

};

ostream& operator <<(ostream& stream, rational& obj) {
	if (obj.getP() == 0)
		stream << 0;
	else
		stream << obj.getP() << "/" << obj.getQ();
	return stream;
}

istream& operator >>(istream& stream, rational& obj) {
	int p,q;
	stream >> p;
	stream.ignore(1);
	stream >> q;
	obj.setP(p);
	obj.setQ(q);
	return stream; 
}

int main()
{
	rational n1(1,-2), n2(3,-3);
	cout << "num1 = " << n1 << "\nnum2 = " << n2 << endl;
	cout << "*************************" << endl;
	rational sub = n1 - n2;
	cout << "sub = num1 - num2 \nsub = " << sub << endl;
	cout << "*************************" << endl;
	rational sum = sub + n1;
	cout << "sum = sub + num1 \nsum = " << sum << endl;

	cout << "*************************" << endl;
	rational n3(1, 5), n4(4, 3);
	cout << "num3 = " << n3 << "\nnum4 = " << n4 << endl;
	cout << "*************************" << endl;
	rational mul = n3 * n4;
	cout << "mul = num3 * num4 \nmul = " << mul << endl;
	cout << "*************************" << endl;
	rational div = n3 / n4;
	cout << "div = num3 * num4 \ndiv = " << div << endl;

	cout << "*************************" << endl;
	cout << "num1 = " << n1 << "\nnum2 = " << n2 << endl;
	cout << "num1 == num2 = " << (n1 == n2) << endl;
	cout << "num1 != num2 = " << (n1 != n2) << endl;
	cout << "num1 < num2 = " << (n1 < n2) << endl;
	cout << "num1 > num2 = " << (n1 > n2) << endl;

	cout << "*************************" << endl;
	rational num5(1, 4), num6(1,4);
	cout << "num5 = " << n1 << "\nnum6 = " << n2 << endl;
	cout << "num5 == num6 = " << (num5 == num6) << endl;
	cout << "num5 != num6 = " << (num5 != num6) << endl;
	cout << "num5 < num6 = " << (num5 < num6) << endl;
	cout << "num5 > num6 = " << (num5 > num6) << endl;
	cout << "num5 <= num6 = " << (num5 <= num6) << endl;
	cout << "num5 >= num6 = " << (num5 >= num6) << endl;

	try
	{
		rational num5(1, 0);
	}
	catch (const exception &ex)
	{
		cout << ex->what() << endl;
	}

}
