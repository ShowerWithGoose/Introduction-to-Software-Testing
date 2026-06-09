#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <tgmath.h>
#include <complex.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

struct node{
	int Sx;
	int Sy;
	int Fx;
	int Fy;
}line[105]; 

int length=1;
int n;
int numnode;

int Find(int aim)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(line[aim].Fx==line[i].Sx&&line[aim].Fy==line[i].Sy)
		{
			numnode++;
			return Find(i);	
		}	
	}	
	return numnode;
}


int main (void)
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&line[i].Sx,&line[i].Sy,&line[i].Fx,&line[i].Fy);
	int Maxx;
	int Maxy;
	for(i=0;i<n;i++)
	{
		numnode=1;
		int len=Find(i);
		if(len>length)
		{
			length=len;
			Maxx=line[i].Sx;
			Maxy=line[i].Sy;
		}
	}
	printf("%d %d %d",length,Maxx,Maxy);
    return 0;
}


