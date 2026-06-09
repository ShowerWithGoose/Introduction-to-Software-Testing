#include <stdio.h>
#include <string.h>
char array[6000]={0};
int zhengshu(int *a)
{
    int x=0,y=*a;
    for(;array[y]>='0'&&array[y]<='9';y++)
        x=10*x+array[y]-'0';
    *a=y;
    return x;
}
int chengchu(int *a)
{
    int x1=1,y1=*a;
    if(array[y1]=='-')    x1=-1; // @@ Only handles '-' sign, fails to handle '*' or '/' as the starting operator, leading to incorrect precedence evaluation.
    *a=*a+1;
    x1*=zhengshu(a);
    while(array[*a]=='*'||array[*a]=='/')
    {
        switch(array[*a])
        {
            case'*':*a=*a+1;x1*=zhengshu(a);break;
            case'/':*a=*a+1;x1/=zhengshu(a);break;
        }
    }
    return x1;
}
int main()
{
    gets(array);
    int b=0;
    int i,j;
    for(i=0,j=0;array[i]!=0;i++)
    {
        if(array[i]!=' ')    array[j++]=array[i]; 
    }
    array[j]=0;
    int sum=zhengshu(&b);
    while(array[b]!='=')
        {sum+=chengchu(&b); // @@ Unconditionally adds the result to sum, failing to handle '*' and '/' operators which should modify the previous term instead of adding a new one.
        }
    printf("%d",sum);
    return 0;
}