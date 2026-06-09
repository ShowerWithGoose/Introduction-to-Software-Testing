#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stack[100];

int main()
{
    int top=-1;
    char str[500];
    int s[500];
    int j=0;
    gets(str);
    char *p=str,*q=p;
    while(strchr(p,' ')!=NULL)
    {
        q=strchr(p,' ');
        *q='\0';
        s[j++]=atoi(p);
        p=q+1;
    }
    s[j]=atoi(p);
    int i;
    for(i=0;i<=j;i++)
    {
        if(s[i]==-1)
        return 0;
        else if(s[i]==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",stack[top--]);
            }
        }
        else if(s[i]==1)
        {
            i++;
            stack[++top]=s[i]; // @@ [Error: When s[i] is 1, the next element s[i+1] is the value to push. However, after incrementing i, the code accesses s[i] which is the value. But if the input ends with a push operation (e.g., "1 567 -1"), after incrementing i, i may become j+1, causing an out-of-bounds access. Additionally, there is no check for stack overflow (top >= 99) before pushing.]
        }
    }
    
    
    
    return 0;
 }