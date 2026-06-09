#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int f(int a,char b,int c)
{
    switch(b)
    {
        case '+':
            return a+c;
        case '-':
            return a-c;
        case '*':
            return a*c;
        case '/':
            return a/c;
        default:
            return 0;
    }
}

int main()
{
    int num[1000],cnum=0,cop=0,i,j,k,sum=0,tem=0;
    char e[1000],op[1000],temp[1000];
    gets(e); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments (like those with strict compiler settings), `gets` is not available, leading to a compilation error.]
    for(i=0,k=0;i<=strlen(e)-1;i++)
    {
        if(e[i]!=' ')
        {
            e[k]=e[i];
            k++;
        }
    }
    e[k]='\0';
    for(i=0;i<=k-1;)
    {
        if(e[i]=='+'||e[i]=='-'||e[i]=='/'||e[i]=='*')
        {
            op[cop++]=e[i];    
            i++;
        }
        if(e[i]=='=')
        {
            break;
        }
        if(e[i]>='0'&&e[i]<='9')
        {
            while(e[i]>='0'&&e[i]<='9')
            {
               tem=tem*10+e[i++]-'0';
            }
            num[cnum++]=tem;
            tem=0;
        }
    }
    
    for(i=0;i<=cnum-1;i++)
    {
        printf("%d ",num[i]);
    }
    for(i=0;i<=cop-1;i++)
    {
        printf("%c ",op[i]);
    }
    printf("\n");
    //okay
    
    for(i=0;;i++)
    {
        if(i==cop)
        {
            break;
        }
        if(op[i]=='*'||op[i]=='/')
        {
            num[i]=f(num[i],op[i],num[i+1]);
            cnum--;
            cop--;
            for(j=i+1;j<=cnum-1;j++)
            {
                num[j]=num[j+1];
            }
            for(j=i;j<=cop-1;j++)
            {
                op[j]=op[j+1];
            }
            i--;
        }
            
    }
    sum=num[0];
    for(i=0;i<=cop-1;i++)
    {
        sum=f(sum,op[i],num[i+1]);
    }
    printf("%d",sum);
    return 0;

}