#include<stdio.h>
void print(int *, int);
int main()
{
	int N;
	int fact[15];
	int line[15];
	int i, j, t, idx;
	int r_min, tmp, l, r;
	scanf("%d", &N);
	fact[1] = 1;
	line[1] = 1;
	for( i=2; i<=N; i++ ) {
		fact[i] = i * fact[i-1];
		line[i] = i;
	}
	print( line, N);
	for( t=1; t<fact[N]; t++ ) {
		for( i=N-1; line[i]>line[i+1]; i-- );
		r_min = line[i+1];
		for( idx=j=i+1; j<N; j++ ) 
			if( line[j+1]<r_min && line[j+1]>line[i] ) {
				r_min = line[j+1];
				idx = j+1;
			}
		tmp = line[i];
		line[i] = r_min;
		line[idx] = tmp;
		for( l=i+1,r=N; l<r; l++,r-- ) {
			tmp = line[l];
			line[l] = line[r];
			line[r] = tmp;
		}
		print( line, N);
	}
	return 0;
}

void print(int *a, int len)
{
	int i;
	for( i=1; i<len; i++)
		printf("%d ", *(a+i));
	printf("%d\n", *(a+i));
}






