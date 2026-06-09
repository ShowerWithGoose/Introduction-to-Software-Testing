#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
void f(int);
int N,n[11],a[11];
int main()
{
scanf("%d",&N);
f(1);

return 0;
}

void f(int cnt){
	if(cnt<N + 1)
	{
		for(int i = 1; i <= N; ++i)
			if(n[i] == 0){
				n[i] = 1;
				a[cnt] = i;
				f(cnt + 1);
				n[i] = 0;
			}
	}
	else{
		for(int i = 1; i <= N; ++i)
			printf("%d ", a[i]);
		printf("\n");
	}
	return ;
}




