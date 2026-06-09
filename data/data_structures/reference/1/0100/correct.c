#include<stdio.h>
int table[11]={0},des[10]={0},n;
void func(int i)
{
	int j,k;
	if(i==n){
	for(j=0;j<i;j++)
	printf("%d ",des[j]);
	printf("\n");}
	else{
		for(k=1;k<=n;k++)
		{
			if(!table[k]){
				table[k]=1;
				des[i]=k;
				func(i+1);
				table[k]=0;
				des[i]=0;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	func(0);
    return 0;
}



