#include <stdio.h>
#include <string.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
int s,k,de,sum[105][105],top,op,x,jud,o[1001],q[105],i;
void dfs(int m){
	if (!jud)
		printf("%d", m), jud = 1;
	else
		printf(" %d", m);
		o[m]=1;
		int l;
	for(l=0;l<=s;l++){
		if (sum[m][l])
		{
			if (!o[l])
			{
				dfs(l);
			}
		}
	}
}
void bfs(int t)
{
	q[1] = t;

	int l = 1, r = 1, z;
	while (l <= r)
	{
		int qs = q[l];
		l++;
		if (o[qs])
			continue;
		if (!jud)
			printf("%d", qs), jud = 1;
		else
			printf(" %d", qs);

		o[qs] = 1;
		for (i = 1; i <= s; i++)
			if (sum[qs][i])
			{
				if (!o[i])
					q[++r] = i;
			}
	}
	memset(o, 0, sizeof(o));
}
int main(){
	scanf("%d%d",&s,&k);
	for(i=0;i<k;i++){
		scanf("%d%d",&top,&op);
		sum[top][op]=1;
		sum[op][top]=1;
	}
	scanf("%d",&de);
    jud=0;
    dfs(0);
	printf("\n");
	memset(o, 0, sizeof(o));
	jud= 0;
    bfs(0);
	printf("\n");
	o[de] = 1;
	jud = 0;
	dfs(0);
	printf("\n");
	memset(o, 0, sizeof(o));
	o[de] = 1;
	jud = 0;
    bfs(0);
	printf("\n");
}




