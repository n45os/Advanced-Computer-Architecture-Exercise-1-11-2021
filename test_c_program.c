#include <stdio.h>
#include <stdlib.h>

#define N 20

int main() {
	unsigned short i, j, k;
	long int matrix[N][N];
	long int res[N][N];
	int n = N;
	for(i = 0; i < n;i++) {
		for(j = 0; j < n;j++) {
		matrix[i][j] = 1;
		}
	}
	for(i = 0 ; i < n; i++){
		for(j = 0 ; j < n; j++){
			res[i][j] = 0;
			for ( k = 0; k < n; k++) {
				res[i][j] += matrix[i][k] * matrix[k][j];
				printf("%ld\n",res[i][j]);
      }
		}
	}
	printf("%ld",res[n-1][n-1]);
	return 0;

}
