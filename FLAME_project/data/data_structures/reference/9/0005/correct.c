#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int n,i,j,k,length,max=0;
int line[101][5],first[2];
int flength(int num,int l);
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&line[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{	
		length=flength(i,1);
		if(length>max)
		{
		first[0]=line[i][0];
		first[1]=line[i][1];			
			max=length;
		}
	}

	printf("%d %d %d",max,first[0],first[1]);

return 0;
}

int flength(int num,int l){
	int check=0;
	for(k=0;k<n;k++)
	{
		if(k!=num)
		{
				if((line[num][2]==line[k][0])&&(line[num][3]==line[k][1]))
		{
			check=1;
			return flength(k,++l);
		
		}	
		}
		
	}
	if(check==0)
	return l;
	
}

