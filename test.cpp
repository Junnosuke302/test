#include <iostream>
#include <ctime>
#define N 10
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
using namespace std;

void sel(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int x;
		for (int j = i + 1; j < n)
	}
}

void bub(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1])
				swap(int, a[j], a[j + 1]);
		}
	}
}

void shuffle(int a[], int n)
{
	int i = n - 1;
	while (i > 1) {
		int j = rand() % i;
		swap(int, a[i], a[j]);
		i--;
	}
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int main()
{
	int arr[N];

	for (int i = 0; i < N; i++)
		arr[i] = i;

	cout << "Before shuffle: ";
	print(arr, N);

	srand(time(NULL));

	shuffle(arr, N);
	cout << "After shuffle: ";
	print(arr, N);

	bub(arr, N);
	cout << "After sorting: ";
	print(arr, N);
}