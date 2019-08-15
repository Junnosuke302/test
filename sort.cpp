#include <iostream>
#include <ctime>
#define N 10
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
using namespace std;

//挿入ソート
void ins(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j > 0; j--) {
			int x = a[j];
			if (a[j - 1] > x)
				a[j] = a[j - 1];
			else {
				a[j] = x;
				break;
			}
		}
	}
}

//選択ソート
void sel(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int x = i;
		for (int j = i + 1; j < n; j++) {
			if (a[x] > a[j])
				x = j;
		}
		swap(int, a[x], a[i]);
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