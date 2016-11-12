// Lab_6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#define SIZE 6



using namespace std;

void wypelnienie(double *l, double *d, double *u, double *b)
{
	u[0] = 1.0 / 2.0; u[1] = 1.0 / 4.0; u[2] = 1.0 / 6.0; u[3] = 1.0 / 8.0; u[4] = 1.0 / 10.0;

	d[0] = 10.0; d[1] = 20.0; d[2] = 30.0; d[3] = 30.0; d[4] = 20.0; d[5] = 10.0;

	l[0] = 1.0 / 3.0; l[1] = 1.0 / 5.0; l[2] = 1.0 / 7.0; l[3] = 1.0 / 9.0; l[4] = 1.0 / 11.0;

	b[0] = 31.0; b[1] = 165.0/4.0; b[2] = 917.0 / 30.0; b[3] = 851.0 / 28.0; b[4] = 3637.0 / 90.0; b[5] = 332.0 / 11.0;
}

void wypiszWek(double *wek)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "| ";
		cout.width(4);
		cout << wek[i];
		cout.width(4);
		cout << "| ";
		cout << endl;
	}
}


void thomasAlgorithm(double *l, double *d, double *u) {
	for (int i = 1; i<SIZE; i++) {
		d[i] = d[i] - l[i - 1] * (u[i - 1] / d[i - 1]);
	}
}

void solveEquation(double *l, double *d, double *u, double *b) {
	for (int i = 1; i<SIZE; i++) {
		b[i] = b[i] - l[i - 1] * b[i - 1] / d[i - 1];
	}

	b[SIZE - 1] = b[SIZE - 1] / d[SIZE - 1];

	for (int i = SIZE - 2; i >= 0; i--) {
		b[i] = (b[i] - u[i] * b[i + 1]) / d[i];
	}
}

void roziwazanie()
{
	double *l, *d, *u, *b;
	

	l = new double[SIZE];
	d = new double[SIZE];
	u = new double[SIZE];
	b = new double[SIZE];
	

	wypelnienie(l, d, u, b);

	cout << endl << "Wektor l " << endl;
	wypiszWek(l);
	cout << endl << "Wektor d " << endl;
	wypiszWek(d);
	cout << endl << "Wektor u " << endl;
	wypiszWek(u);
	cout << endl << "Wektor b " << endl;
	wypiszWek(b);
	cout << endl;

	thomasAlgorithm(l, d, u);
	cout << endl << "Wektor l " << endl;
	wypiszWek(l);
	cout << endl << "Wektor d " << endl;
	wypiszWek(d);
	cout << endl << "Wektor u " << endl;
	wypiszWek(u);

	solveEquation(l, d, u, b);

	cout << endl << "Wektor x " << endl;
	wypiszWek(b);
	cout << endl;

	delete[] l;
	delete[] d;
	delete[] u;
	delete[] b;

}


int _tmain(int argc, _TCHAR* argv[])
{
	roziwazanie();
	system("pause");
	return 0;
}



