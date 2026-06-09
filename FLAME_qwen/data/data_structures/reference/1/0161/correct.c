#include<stdio.h>
#include<string.h>

int flag[12],str[12],len;
void answer(int n){
	int i,j;
	if(n==0){
		for(i=0;i<len;i++)
		printf("%d ",str[i]);
		printf("\n");
		return ;
	}
	else{
		for(j=0;j<len;j++)
		{
			if(flag[j]==0)
			{
				flag[j]=1;
				str[len-n]=j+1;
				answer(n-1);
				flag[j]=0;
			}
		}
	}
}
int main()
{
	scanf("%d",&len);
	answer(len);
	return 0;
}

