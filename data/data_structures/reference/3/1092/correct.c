#include<stdio.h>
#include<string.h>
#define M 105
char a[M];
int main()
{
    gets(a);
    char *p,*q;
    int i,j;
    p=a;q=a;
    while((*p!='.')&&(*p!='\0'))
    p++;
    while((*q=='0'||*q=='.')&&(*q!='\0'))
    q++;
    if(q-p<0)
    {
        printf("%d.",*q-'0');
        *p='\0';
        strcat(q+1,p+1);
        for(i=q+1-a;a[i]!='\0';i++)
        printf("%d",a[i]-'0');
        printf("e%d\n",p-q-1);
    }
    else
    {
    	if(*(q+1)=='\0')
        printf("%d",*q-'0');
        else printf("%d.",*q-'0');
        for(i=q+1-a;a[i]!='\0';i++)
        printf("%d",a[i]-'0');
        printf("e-%d\n",q-p);
    }
    return 0;
}

