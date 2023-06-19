#include<iostream>
#include<vector>


class MyClass
{
public:
	explicit MyClass(int a) { // explicit - запрещает компилятору неявное использование конструктора

		if (a >= 0) {
			data.reserve(a);
			this->init();
		}
	}



	int operator + (const MyClass obj)const {
		int result{};
		for (size_t i = 0; i < obj.data.size(); i++) {
			result += obj.data[i];
		}
		for (size_t i = 0; i < this->data.size(); i++) {
			result += this->data[i];
		}
		return result;
	}

private:

	void init() {
		for (size_t i = 0; i < data.capacity(); i++) {
			data.push_back(i + 1);
		}
	}

	std::vector<int> data;


};

class Integer {

	public:
		int units;
		Integer operator ++() {
			units += 1;
			return *this;

		}

		Integer operator ++(int) { // постфиксные операторы в ручной реализации...................используют доп объём памяти,чем префиксные
			Integer result;
			result.units = units;
			units += 1;
			return result;

		}

		Integer operator --() {
			units -= 1;
			return *this;

		}


};


class Shot {
private:
	int _Numerator;
	int _Denominator;

public:
	Shot(int numerator, int denominator) : _Numerator(numerator), _Denominator(denominator) {}

	void SetNumerator(int numerator) {
		_Numerator = numerator;
	}
	void SetDenominator(int denominator) {
		_Denominator = denominator;
	}

	int WholePart() {
		return (_Numerator / _Denominator);
	}
	int Fraction() {
		return (_Numerator % _Denominator);
	}
	void Reciprocal() {
		int Re_numerator, Re_denominator;
		Re_numerator = _Denominator;
		Re_denominator = _Numerator;
		std::cout << "Re_numerator:" << Re_numerator << '\n' << "Re_denominator:" << Re_denominator << '\n';
	}

};

int main()
{
	/*MyClass a(5);
	MyClass b(7);
	std::cout << a + b;*/

	/*int num;
	num = 9;
	int r1 = num++;
	int r2 = --num;
	Integer a;
	a.units = 9;
	Integer r3(a++);
	Integer r4(--a);*/

	// задача Дробь

	Shot a(13, 5);
	std::cout << "WholePart:" << a.WholePart() << '\n';
	std::cout << "Fraction:" << a.Fraction() << '\n';
	a.Reciprocal();



	return 0;
}
