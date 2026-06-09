#include<stdio.h>
struct duos1{
	int xi;
	int zhi;
}duo1[1000]; 
struct duos2{
	int xi;
	int zhi;
}duo2[1000];
struct duos3{
	int xi;
	int zhi;
}duo3[1000],s;
void paixu(int n,struct duos3 duo3[1000],struct duos3 s) 
{
 int i,j,flag;
 for(i=0;i<n-1;i++)
 {
  flag=0;
  for(j=0;j<n-1-i;j++)
  {
   if(duo3[j].zhi<duo3[j+1].zhi)
   {
    s=duo3[j];
    duo3[j]=duo3[j+1];
    duo3[j+1]=s;
    flag=1;
   }
  }
  if(flag==0)
   {
    break;
   }
 }
}
int main()
{
	int i=0,j,cnt,num,flag=0;
	char ch;
	do
	{
		scanf("%d%d%c",&duo1[i].xi,&duo1[i].zhi,&ch);
		i++;
	}while(ch!='\n');
	cnt=i;
	i=0;
	do
	{
		scanf("%d%d%c",&duo2[i].xi,&duo2[i].zhi,&ch);
		i++;
	}while(ch!='\n');
	num=i;
	for(i=0;i<cnt;i++)
	{
		for(j=0;j<num;j++)
		{
			duo3[flag].xi=duo1[i].xi*duo2[j].xi;
			duo3[flag].zhi=duo1[i].zhi+duo2[j].zhi;
			flag++;
		}
   }
   for(i=0;i<flag;i++)
   {
   		for(j=i+1;j<flag;j++)
   		{
   		if(duo3[i].zhi==duo3[j].zhi)	
   		{
   			duo3[i].xi=duo3[i].xi+duo3[j].xi;
   			duo3[j].xi=0;
	   	}
	   	else if(duo3[j].xi==0)
	   	continue;
		}
   }
   paixu(flag,duo3,s);
   for(i=0;i<flag;i++)
   {
   	if(duo3[i].xi!=0)
   	printf("%d %d ",duo3[i].xi,duo3[i].zhi);
   }
	
 } 

