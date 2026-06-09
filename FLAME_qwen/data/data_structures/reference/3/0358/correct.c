#include<stdio.h>
//#include<windows.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[105]={'\0'};
    gets (a);
    //puts (a);
    int i=0,j=0,k=0,judge=-1;
    for(i=0;i<105;i++)
    {
        if(a[i]=='.')
            break;
    }
    i++;

    //printf("%c",a[0]);
    //printf(".");
    for(j=0;j<104;j++)
    {
        if(a[j]>'0')
        {
           printf("%c",a[j]);
           if(a[j+1]!='\0')
                judge=1;// no point
           break;
        }
    }
    j++;

    if(judge==1)
    {
        printf(".");
    }
  for(k=j;k<104;k++)
    {
        if(a[k]!='\0' && a[k]!='.')
        {
           printf("%c",a[k]);
        }
        else if(a[k]=='\0')
            break;
    }

    printf("e");
    //printf("\ni=%d\n",i);
    //printf("j=%d\n",j);
    if(-j+i-1>=0 && -j+i-1!=104)
        printf("%d",-j+i-1);
    else if(-j+i-1<0)
        printf("%d",-j+i);
    else
        printf("0");
    //system("pause");
    return 0;
}

