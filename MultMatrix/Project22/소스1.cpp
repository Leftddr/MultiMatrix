#include<iostream>

using namespace std;

#define MIN(A, B) ((A)>(B)?(B):(A))
#define MAX_VALUE 9999999
#define MAX_SIZE 101

int M[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE];

int main()
{
	int size = 4;

	d[0] = 20, d[1] = 1, d[2] = 30, d[3] = 10, d[4] = 10;

	for (int diagonal = 0; diagonal < size; diagonal++)
	{
		for (int i = 1; i <= size - diagonal; i++)
		{
			int j = i + diagonal;
			if (j == i)
			{
				M[i][j] = 0;
				continue;
			}
			M[i][j] = MAX_VALUE;
			for (int k = i; k <= j - 1; k++)
				M[i][j] = MIN(M[i][j], M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]);

		}
	}

	/*결과 출력*/
	cout << M[1][size] << endl;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			cout << M[i][j] << "            ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
