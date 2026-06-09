#include <stdio.h>
#include<math.h>
#include<string.h>
void transform(char*,int*,int*);
void getoperator(char *,char *);
int cal(char *,int *,int);
int main()
{
    char exp[50];
    char opera[50];    //存运算符 
    int num[50]={0};  //存数字 
    int n=0;
    gets(exp); // @@ gets() is removed in the C11 standard and causes a compilation error in modern compilers. It should be replaced with fgets(exp, 50, stdin);
    getoperator(exp,opera);   //提取运算符exp到opera 
    transform(exp,&n,num);   //提取数字exp到num 
    int ans=cal(opera,num,n);   //结果 
    printf("%d",ans);
    return 0;

}
void transform(char *exp,int *n,int *num)
{
    int i=0,j=0,temp=0;
    int flag=0;
    while(i<strlen(exp))
    {
        while(exp[i]==' ')
        {
            i++;
        }
        while((i<strlen(exp))&&(exp[i]>='0')&&(exp[i]<='9'))
        {
            temp=temp*10+(exp[i]-'0');
            flag=1;
            i++;
        }
        
        if(flag==1)
        {
            *num=temp;
            num++;
            j++;
            flag=0;
        }
        i++;   //跳过符号 
        temp=0;
    }
    *n=j;
}
void getoperator(char *exp,char *opera)
{
    int i,j=0;
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
        {
            opera[j]=exp[i];
            j++;
        }
    }
}
int cal(char *opera,int *num,int n)
{
    int i=0,j;
    while(i<n)
    {
        if(opera[i]=='+')
        i++;
        else if(opera[i]=='-')
        {
            num[i+1]=-num[i+1];
            opera[i]='+';
            i++;
        }
        else if(opera[i]=='*')
        {
            num[i+1]=num[i+1]*num[i];
            opera[i]='+';
            num[i]=0;
            i++; 
        }
        else if(opera[i]=='/')
        {
            num[i+1]=num[i]/num[i+1];
            opera[i]='+';
            num[i]=0;
            i++;
        }
        else
        i++;

    }
    int ans; // @@ The variable 'ans' is uninitialized, leading to undefined behavior when used in accumulation. It should be initialized to 0.
    for(j=0;j<n;j++) // @@ The loop condition 'j<n' misses the last operand. With n operators, there are n+1 numbers. It should be 'j<=n' or 'j<n+1'.
    {
        ans=ans+num[j];
    }
    return ans;
    
}