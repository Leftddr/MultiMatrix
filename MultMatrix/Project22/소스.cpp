#include <stdio.h>
#include <Windows.h>
#pragma warning (disable:4996)
#define MAX_VALUE 999999
int minmult(int *,int);
int m[100][100];
int p[100][100] = { 0, };

void order(int, int);

int main() {
	int d[6] = { 10,4,5,20,2,50 };
	int n;
	int a, b;
	printf("n의 크기를 입력하시오 : ");
	scanf("%d", &n);
	int result = minmult(d, n);
	printf("%d\n", result);
	printf("시작할 지점 입력 :");
	scanf("%d", &a);
	printf("끝날 지점 입력:");
	scanf("%d", &b);
	order(a, b);
	system("pause");
	return 0;
}

int minmult(int *d,int n) {
	int i, j, k, diagonal;
	for (diagonal = 0; diagonal < n; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			if (i == j) { m[i][j] = 0; continue; }
			m[i][j] = MAX_VALUE;
			for (k = i; k <= j - 1; k++) {
				if (m[i][j] >= m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j]) {
					m[i][j] = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
					p[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=n; j++) {
			printf("%7d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%7d ", p[i][j]);
		}
		printf("\n");
	}
	return m[1][n];
}

void order(int i, int j) {
	int k;
	if (i == j) printf("A%d", i);
	else {
		k = p[i][j];
		printf("(");
		order(i, k);
		order(k + 1, j);
		printf(")");
	}
}