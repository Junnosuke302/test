#include <iostream>
#include <ctime>
#define N 10
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
using namespace std;

//選択ソート
void sel(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int x = a[i];
		for (int j = i + 1; j < n) {
			if (x > a[j])
				x = a[j];
		}
		swap(int, x, a[i]);
	}
}

//バブルソート
void bub(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1])
				swap(int, a[j], a[j + 1]);
		}
	}
}

//フィッシャーイエーツのシャッフル
void shuffle(int a[], int n)
{
	int i = n - 1;
	while (i > 1) {
		int j = rand() % i;
		swap(int, a[i], a[j]);
		i--;
	}
}

//表示
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

	/*bub(arr, N);
	cout << "After sorting(bub): ";
	print(arr, N);*/

	sel(arr, N);
	cout << "After sorting(sel): ";
	print(arr, N);
}