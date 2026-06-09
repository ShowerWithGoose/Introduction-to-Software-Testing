#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct s1
{
	int zhishu;
	int xishu;
}s1[100];
struct s2
{
	int zhishu;
	int xishu;
}s2[100];
struct s3
{
	int zhishu;
	int xishu;
}s3[100];
int main()
{
	int len1=0,len2=0,i=0,j,k=0,len3=0,flag,temp,hold=0;
	char c;
	while(1)
	{
		scanf("%d",&s1[i].xishu);
		scanf("%d",&s1[i].zhishu);
		i++;
		if((c=getchar()=='\n'))
		break;
	}
	len1=i;
	i=0;
	while(1)
		{
			scanf("%d",&s2[i].xishu);
			scanf("%d",&s2[i].zhishu);
			i++;
			if((c=getchar()=='\n'))
			break;
		}
		len2=i;
 for(i=0;i<len1;i++)
 {
 	for(j=0;j<len2;j++)
 	{
	 	s3[k].xishu=s2[j].xishu*s1[i].xishu;
	 	s3[k].zhishu=s2[j].zhishu+s1[i].zhishu;
	 	k++;
		}
 }
 len3=k;
 for(i=0;i<len3;i++)
 {
 	for(j=i+1;j<len3;j++)
 	{
	 	if(s3[j].zhishu==s3[i].zhishu)
	 	{
		 	s3[i].xishu+=s3[j].xishu;
		 	s3[j].xishu=0;
		 }
	 }
 }
 	for(i=0; i<len3-1; i++) {
 		flag=0;
 		for(j=0; j<len3-1-i; j++)
 			if(s3[j].zhishu<s3[j+1].zhishu) 
			 {
 				hold=s3[j].zhishu;
 				s3[j].zhishu=s3[j+1].zhishu;
 				s3[j+1].zhishu=hold;
				temp=s3[j].xishu;
  				s3[j].xishu=s3[j+1].xishu;
				s3[j+1].xishu=temp;		
 				flag=1;
 			}
 		if(0==flag)
 			break;
 	}
 	for(i=0;i<len3;i++)
 	{
	 	if(s3[i].xishu!=0)
	 	{
		 	printf("%d %d ",s3[i].xishu,s3[i].zhishu);
		 }
	 }
	 return 0;
}

