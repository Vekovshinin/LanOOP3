#include <iostream>

using namespace std;

class PairOfNumbers {
	int firstNumber;
	double secondNumber;

public:
	PairOfNumbers();
	PairOfNumbers(int, double);
	PairOfNumbers(const PairOfNumbers&);
	double diff();
	void addConst(int);
	void addConst(double);
	void getInfo();
	~PairOfNumbers();
	void setFirstNumber(int);
	void setSecondNumber(double);
	void operator = (const PairOfNumbers&);
	void operator + (int);
	void operator + (double);
	void operator - (const PairOfNumbers&);
	int returnFirstNumber();
	double returnSecondNumber();
private:
	int FirstNumber;
	double SecondNumber;
};

PairOfNumbers::PairOfNumbers() {
	cout << "Вызвался конструктор с параметрами" << '\t' << this << endl;
	firstNumber = 0;
	secondNumber = 0;
	this->firstNumber = 0;
	this->secondNumber = 0;
}

PairOfNumbers::PairOfNumbers(int first, double second) {
	cout << "Вызвался конструктор с параметрами" << '\t' << this << endl;
	this->firstNumber = first;
	this->secondNumber = second;
	this->FirstNumber = first;
	this->SecondNumber = second;
}
PairOfNumbers::PairOfNumbers(const PairOfNumbers& a) {
	cout << "Вызвался конструктор копирования" << '\t' << this << endl;
	this->firstNumber = a.FirstNumber;
	this->secondNumber = a.SecondNumber;
}

double PairOfNumbers::diff() {
	return this->firstNumber - this->secondNumber;
}
void PairOfNumbers::addConst(int number) {
	this->firstNumber += number;
}

void PairOfNumbers::addConst(double number) {
	this->secondNumber += number;
}

void PairOfNumbers::getInfo() {
	cout << this->firstNumber << " : " << this->secondNumber;
}
PairOfNumbers::~PairOfNumbers() {
	cout << "Вызвался деструктор" << '\t' << this << endl;
}
void PairOfNumbers::setFirstNumber(int a) {
	this->firstNumber = a;
	this->FirstNumber = a;
}

void PairOfNumbers::setSecondNumber(double a) {
	this->secondNumber = a;
	this->SecondNumber = a;
}

void PairOfNumbers:: operator = (const PairOfNumbers& a) {
	cout << "Вызвался оператор = " << endl;
	this->firstNumber = a.FirstNumber;
	this->secondNumber = a.SecondNumber;
}
void PairOfNumbers:: operator + (int x) {
	cout << "Вызвался оператор + " << endl;
	firstNumber += x;
}

void PairOfNumbers:: operator + (double x) {
	cout << "Вызвался оператор + " << endl;
	secondNumber += x;
}

void PairOfNumbers:: operator - (const PairOfNumbers& a) {
	firstNumber -= a.firstNumber;
	secondNumber -= a.secondNumber;
}

int PairOfNumbers::returnFirstNumber() {
	return firstNumber;
}
double PairOfNumbers::returnSecondNumber() {
	return secondNumber;
}


ostream& operator << (ostream& os, PairOfNumbers& b);
istream& operator >> (istream& in, PairOfNumbers& c);

ostream& operator<<(ostream& os, PairOfNumbers& b) {
	cout << "вызвалась перегрузка оператора << " << endl;
	os << b.returnFirstNumber() << " : " << b.returnSecondNumber();
	return os;
}
istream& operator >> (istream& in, PairOfNumbers& c) {
	cout << "Вызвалась перегрузка оператора >>" << endl;
	int first; double second;
	in >> first >> second;
	c.setFirstNumber(first);
	c.setSecondNumber(second);
	return in;
}

int main() {
	system("chcp 1251 > null");
	PairOfNumbers example(5, 6);
	example.getInfo();
	cout << endl;

	cout << "Разность чисел: " << example.diff();
	cout << endl;

	example.addConst(5);
	example.getInfo();
	cout << endl;

	example.addConst(5.5);
	example.getInfo();
	cout << endl << endl;

	PairOfNumbers example2;
	example2.getInfo();

	cout << endl << endl;

	PairOfNumbers example3(example);
	example3.getInfo();
	cout << endl << endl;

	cin >> example;
	cout << example << endl << endl;

	example2 - example;
	cout << example2 << endl << endl;

	example + 5;
	example + 6.5;
	cout << example;
	cout << endl << endl;
	return 0;
}