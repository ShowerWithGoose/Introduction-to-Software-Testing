#include <stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define arraynum(x)  (sizeof(x)/sizeof(x[o])
#define eps (1*10^-9)
int list[100];
int num,top=-1;
void rujian(int n);
void chujian(int choice);
int main()
{
int a=0,i,choice;
while (1)
{
    scanf("%d", &choice);
    switch (choice)
    {
        case 1: scanf("%d",&a); rujian(a); break;
        case 0: chujian(choice); break;
        case -1: goto end;
    }

}

end:
return 0;
}


void rujian(int n)
{
    if(top==99)
    {
        printf("error ");
    }
    else
    {
        list[++top]=n;
    }

}
void chujian(int choice)
{
    if(top==-1)
    {
        printf("error ");
    }
    else
    {
        printf("%d ",list[top]);
        top--;
    }
}

