/*
 * @Author: your name
 * @Date: 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void* a,const void * b)
{
return ( *(int*)a - *(int*)b );
}
struct line{
    int lx,rx,ly,ry;
};
struct line lines[500];
int main(){
    int n;
    int px,py;
    int fx,fy;
    int max=0;
    int tmp;
    int toDelet=-1;
    int tag[500]={};

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&lines[i].lx,&lines[i].ly,&lines[i].rx,&lines[i].ry);
    }
    qsort(lines,n,sizeof(lines[0]),cmp);
    for(int i=0;i<n;i++)
//    printf("%d %d %d %d\n",lines[i].lx,lines[i].ly,lines[i].rx,lines[i].ry);

    for(int i=0;i<n-1;i++)
    {
    	
        if(lines[i].lx==lines[i+1].lx&&lines[i].ry==lines[i+1].ry)
        toDelet=i;
    }
//    printf("%d   \n",toDelet);
     for(int i=0;i<n-1;i++)
     {
        px=lines[i].rx;
        py=lines[i].ry;
//        max=1;
        tmp=1;
     	for(int j=i+1;j<n;j++)
       {
          if(lines[j].lx==px&&lines[j].ly==py)
          {
          tmp++;
          px=lines[j].rx,py=lines[j].ry;
		  }
       }

       if(tmp>max)
       {
	       max=tmp;
       fx=lines[i].lx;
       fy=lines[i].ly;
       }
	 }
	 
	   if(toDelet!=-1)
	   {
	   	lines[toDelet].lx=0;
	   	lines[toDelet].ly=0;
	   	for(int i=0;i<n-1;i++)
     {
        px=lines[i].rx;
        py=lines[i].ry;
//        max=1;
        tmp=1;
     	for(int j=i+1;j<n;j++)
       {
          if(lines[j].lx==px&&lines[j].ly==py)
          {
          tmp++;
          px=lines[j].rx,py=lines[j].ry;
		  }
       }

       if(tmp>max)
       {
	       max=tmp;
       fx=lines[i].lx;
       fy=lines[i].ly;
       }
	 }
	   }
	 


     printf("%d %d %d",max,fx,fy);
}

