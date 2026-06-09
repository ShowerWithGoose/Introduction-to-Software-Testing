#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
    struct line{
        int x1;
        int y1;
        int x2;
        int y2;
        int time;
}num[1000];
int n,head=0,a,b,c,d;
scanf("%d",&n);
scanf("%d %d %d %d",&a,&b,&c,&d);
num[head].x1=a;
num[head].y1=b;
num[head].x2=c;
num[head].y2=d;
num[head++].time=1;
while(--n)
{
    int f1=0,f2=0,n1,n2;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    for(int i=0;i<head;i++)
    {
        
       
        if(a==num[i].x2&&b==num[i].y2)
        {
            num[i].x2=c;num[i].y2=d;
            num[i].time++;
            f1=1;
            n1=i;
        } 
		else if(c==num[i].x1&&d==num[i].y1){
            num[i].x1=a;num[i].y1=b;
            num[i].time++;
            f2=1;
            n2=i;
        }
    }    
            
        
    
    if(f1==0&&f2==0)
    {
        num[head].x1=a;
        num[head].y1=b;
        num[head].x2=c;
        num[head].y2=d;
        num[head++].time=1;
    }
    else if(f1==1&&f2==1)
    {
    	num[n1].x2=num[n2].x2;
    	num[n1].y2=num[n2].y2;
    	num[n1].time+=num[n2].time-1;
	}
    
}
int max=0,node;
    for(int i=0;i<head;i++)
    {
        if(max<num[i].time)
        {
            max=num[i].time;
            node=i;
        }
        //printf("%d\n",num[i].time);
    }
    printf("%d %d %d",max,num[node].x1,num[node].y1);
    
    

    return 0;
}

