#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    char ori[114],output[514];
    int dotPosition=-1,numPositiion=-1,scan=0,level=0,write=0;
    gets(ori);
    while(ori[scan]!=0)
    {
        if(ori[scan]<='9'&&ori[scan]>='1'&&numPositiion==-1)
            numPositiion=scan;
        if(ori[scan]=='.')
            dotPosition=scan;
        scan++;
    }
    if(dotPosition==-1)
        dotPosition=scan;
    if(dotPosition<numPositiion)
        level=dotPosition-numPositiion;
    else
        level=dotPosition-numPositiion-1;
    scan=numPositiion;
    while(ori[scan]!=0)
    {
        if(ori[scan]=='.')
            scan++;
        ori[write++]=ori[scan++];
    }
    ori[write]=0;
    if(write>1)
    {
        scan=1;
        write=2;
        output[0]=ori[0];
        output[1]='.';
        while(ori[scan]!=0)
        {
            output[write++]=ori[scan++];
        }
        printf("%se%d",output,level);
    }
    else
    {
        printf("%se%d",ori,level);
    }
    return 0;
}
