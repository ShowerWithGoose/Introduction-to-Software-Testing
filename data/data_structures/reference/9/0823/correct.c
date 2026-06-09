#include<stdio.h>
#include<string.h>
#include<math.h>
int line_Sx[110],line_Ex[110];
int line_Sy[110],line_Ey[110];
int line_Num[110],line_Link[110];
void check(int,int);
int main()
{
	int n,i,j,max=0,max_Num;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++){
		scanf("%d %d %d %d",&line_Sx[i],&line_Sy[i],&line_Ex[i],&line_Ey[i]);
	}
	for(i=0;i<=n-1;i++){
		for(j=0;j<=n-1;j++){
			if(i==j)
			continue;
			if(line_Ex[i]==line_Sx[j]&&line_Ey[i]==line_Sy[j]){
			    line_Num[i]++;
			    line_Link[i]=j;
			    break;
			}
		}
	}
	for(i=0;i<=n-1;i++)
	check(i,i);
	for(i=0;i<=n-1;i++){
		if(line_Num[i]>=max)
		{
			max=line_Num[i];
			max_Num=i;
		}
	}
	printf("%d %d %d",max,line_Sx[max_Num],line_Sy[max_Num]);
}
void check(int l,int k){
	if(line_Num[l]!=0){
		line_Num[k]++;
		check(line_Link[l],k);
		return ;
	}
	return ;
}


