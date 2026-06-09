#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

struct line{
	int x1;
	int x2;
	int y1;
	int y2;
	int count;
}line[101];

void rank(int n,struct line line[101]){
	int k=0,i=0,hold;
	for(i=0;i<n;i++)
	for(k=i;k<n;k++){
		if(line[i].x1>line[k].x1)
		{
			hold=line[i].x1;
			line[i].x1=line[k].x1;
			line[k].x1=hold;
			hold=line[i].y1;
			line[i].y1=line[k].y1;
			line[k].y1=hold;
			hold=line[i].x2;
			line[i].x2=line[k].x2;
			line[k].x2=hold;
			hold=line[i].y2;
			line[i].y2=line[k].y2;
			line[k].y2=hold;
		}
	}
}

int main()
{
	int i=0,n,j=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);	
	    line[i].count=1;}
	
	rank(n,line); 
	int max=0,flag=0;
	for(i=n-1;i>=0;i--){
	for(j=i-1;j>=0;j--){
		if(line[i].x1==line[j].x2&&line[i].y1==line[j].y2)
		{
			line[j].count+=line[i].count;
			
		}
		}

	}
	
	
	for(i=0;i<n;i++)
	{
		if(line[i].count>max){
			max=line[i].count;
			flag=i;
		}
		
	}
	printf("%d %d %d",max,line[flag].x1,line[flag].y1);
	
	return 0;
	
}

