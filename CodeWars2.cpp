#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long determinant(vector< vector<long long> > a)
{
	int n = a.size();
	if (n == 1)
		return a[0][0];
	else if (n == 2)
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	else {
		int d = 0;
		vector<vector<long long>> m(n - 1, vector<long long>(n - 1));
		for (int k = 0; k < n; k++)
		{
			for (int i = 1; i < n; i++) {
				int t = 0;
				for (int j = 0; j < n; j++) {
					if (j == k)
						continue;
					m[i - 1][t] = a[i][j];
					t++;
				}
			}
			d += pow(-1, k + 2) * a[0][k] * determinant(m);
		}
		return d;
	}