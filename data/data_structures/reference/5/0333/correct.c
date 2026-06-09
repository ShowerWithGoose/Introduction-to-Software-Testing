#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct multi{
    int c;
    int p;
};

typedef struct multi mul;

mul poly1[1000];
mul poly2[1000];
mul poly[1000000]; 
int main()
{
    int i,j;
	int cnt1=0,cnt2=0,cnt=0;
	
    for(i=0;;i++)
    {
        scanf("%d %d",&poly1[i].c,&poly1[i].p);
        cnt1++;
        if(getchar()=='\n')
            break;
    }
    for(i=0;;i++)
    {
        scanf("%d %d",&poly2[i].c,&poly2[i].p);
        cnt2++;
        if(getchar()=='\n')
            break;
    }
    
    int flag=0;
	int temp1,temp2;
	
    for(i=0;i<cnt1;i++)
    {
        for(j=0;j<cnt2;j++)
        {
            poly[flag].c=poly1[i].c*poly2[j].c;
            poly[flag].p=poly1[i].p+poly2[j].p;
            flag++;
        }
    }
    cnt=flag;
    
    for(i=0;i<cnt;i++)
    {
        for(j=i+1;j<cnt;j++)
        {
            if(poly[i].p<poly[j].p)
            {
                temp1=poly[i].p;
                poly[i].p=poly[j].p;
                poly[j].p=temp1;
                
                temp2=poly[i].c;
                poly[i].c=poly[j].c;
                poly[j].c=temp2;
            }
            else if(poly[i].p==poly[j].p)
            {
                poly[i].c+=poly[j].c;
                poly[j].c=0;
            }
        }
    }
    for(i=0;i<cnt;i++)
    {
    	if(poly[i].c!=0)
        printf("%d %d ",poly[i].c,poly[i].p);
    }
    
    return 0;
}
