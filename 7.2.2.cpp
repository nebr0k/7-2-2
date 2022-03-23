#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int high, const int low, int kNo);
void Print(int** a, const int k, const int n, int kNo);
void Creates(int** a, const int kNo, const int n, const int high, const int low, int nNo);
void Calcs(int** a, int& S, const int kNo, const int n, int k, int nNo, int& max);
void Prints(int** a, const int kNo, const int n, int nNo);
void Calc(int** a, int& S, const int k, const int n, int kNo);




void Create(int** a, const int k, const int n, const int high, const int low, int kNo)
{
	Creates(a, kNo, n, high, low, 0);
	if (kNo < k - 1)
	{
		Create(a, k, n, high, low, kNo + 1);
	}
	else
	{
		return;
	}
}

void Creates(int** a, const int kNo, const int n, const int high, const int low, int nNo)
{
	a[kNo][nNo] = low + rand() % (high - low + 1);
	if (nNo < n - 1)
	{
		Creates(a, kNo, n, high, low, nNo + 1);
	}
	else
	{
		return;
	}
}

void Print(int** a, const int k, const int n, int kNo)
{
	Prints(a, kNo, n, 0);
	if (kNo < k - 1)
	{
		Print(a, k, n, kNo + 1);
	}
	else
	{
		cout << endl;
	}

}

void Prints(int** a, const int kNo, const int n, int nNo)
{
	cout << setw(4) << a[kNo][nNo];
	if (nNo < n - 1)
	{
		Prints(a, kNo, n, nNo + 1);
	}
	else
	{
		cout << endl;
	}

}


void Calc(int** a, int& S, const int k, const int n, int kNo)
{

	if (kNo >= k)
	{
		return;
	}
	int min = a[kNo][0];
	Calcs(a, S, kNo, n, k, 0, min);
	if (kNo < k - 1)
	{
		Calc(a, S, k, n, kNo + 2);
	}
	else
	{
		return;
	}
}

void Calcs(int** a, int& S, const int kNo, const int n, int k, int nNo, int& max)
{
	if (a[kNo][nNo] > max)
	{
		max = a[kNo][nNo];
	}
	if (nNo == n - 1)
	{
		S += max;
	}
	if (nNo < n - 1)
	{
		Calcs(a, S, kNo, n, k, nNo + 1, max);
	}
	else
	{
		return;
	}
}
int main()
{
	srand((unsigned)time(NULL));

	int high = 30;
	int low = 1;
	int S = 0;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;


	int** a = new  int* [k];
	for (int i = 0; i < k; i++)
	{
		a[i] = new int[n];
	}

	Create(a, k, n, high, low, 0);
	Print(a, k, n, 0);
	Calc(a, S, k, n, 1);

	cout << "S = " << S << endl;

	for (int i = 0; i < k; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}