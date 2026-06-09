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
    if(array[y1]=='-')    x1=-1;
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
    int sum=zhengshu(&b); // @@ [First term is incomplete: after reading the first number, the next operator (e.g., '*' or '/') should be combined with this number before entering the loop. Currently, it is incorrectly handled as a separate term.]
    while(array[b]!='=') // @@ [This loop assumes that the next character after the first number is always '+' or '-', but it could be '*' or '/'. The loop should only start after the first term (including its following '*' and '/' operations) is fully evaluated.]
        {sum+=chengchu(&b); // @@ [Calling chengchu here treats any operator as the sign of a new term, but if the operator is '*' or '/', it should instead be combined with the current term. This leads to incorrect calculations when the expression begins with multiplication or division.]
        }
    printf("%d",sum);
    return 0;
}