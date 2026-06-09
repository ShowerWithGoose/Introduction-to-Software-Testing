#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<ctype.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int count;
};struct line table[1000];
int i,n,j,q=0,o,z,xa,xb,ya,yb,max=0;
int main()
{
	
	scanf("%d",&n);	
while(n--)
{ o=0;
	scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
	for(i=0;i<q;i++)  
        {
            if(xa==table[i].x2 && ya==table[i].y2) 
            {
                table[i].x2 = xb;
                table[i].y2 = yb;
                table[i].count++;
                o = 1;
                break;
            }
            if(xb==table[i].x1 && yb==table[i].y1)
            {
                table[i].x1 = xa;
                table[i].y1 = ya;
                table[i].count++;
                o= 1;
                break;
            }
        }
       oo();
        }
			
  	 for(i=0;i<q;i++)  
    {
        for(j=i;j<q;j++)
        {
            if(table[j].x2==table[i].x1 && table[j].y2==table[i].y1) 
            {
                table[i].x1= table[j].x1;
                table[i].y1 =table[j].y1;
                table[i].count = table[i].count+table[j].count;
                i--;
                break;
            }
            if(table[j].x1==table[i].x2 && table[j].y1==table[i].y2) 
            {
                table[i].x2 = table[j].x2;
                table[i].y2 = table[j].y2;
                table[i].count = table[i].count+table[j].count;
                i--;
                break;
            }
        }
    if(table[i].count> max)
        {
            z = i;
            max= table[i].count;
        }
		}
    printf("%d %d %d",table[z].count,table[z].x1,table[z].y1);
    return 0;
}
void oo()
{
 if (o==0) 
        {
            table[q].x1= xa;
            table[q].y1 = ya;
           table[q].x2 = xb;
            table[q].y2 = yb;
            table[q].count = 1;
            q++;	
}
}


