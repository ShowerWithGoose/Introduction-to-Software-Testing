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
    gets(exp); // @@ [Using `gets` is unsafe and deprecated; may cause buffer overflow. However, the immediate error is likely due to uninitialized `ans` in `cal` and incorrect parsing logic.]
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
        i++;   //跳过符号 // @@ [This unconditionally increments `i`, which may skip digits or go out of bounds when the number is at the end before '='. Also, it fails to handle negative numbers correctly.]
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
            num[i+1]=num[i+1]*num[i]; // @@ [Incorrect operand order: should be `num[i] * num[i+1]`, but more critically, this modifies future operands incorrectly due to left-to-right without precedence handling. Also, `num[i]` is set to 0, breaking accumulation.]
            opera[i]='+';
            num[i]=0;
            i++; 
        }
        else if(opera[i]=='/')
        {
            num[i+1]=num[i]/num[i+1]; // @@ [Division operands reversed: should be `num[i] / num[i+1]`. Also, integer division truncates toward zero, but logic is flawed due to incorrect indexing and mutation.]
            opera[i]='+';
            num[i]=0;
            i++;
        }
        else
        i++;

    }
    int ans; // @@ [Variable `ans` is used uninitialized in the loop below, leading to undefined behavior.]
    for(j=0;j<n;j++)
    {
        ans=ans+num[j]; // @@ [Reading uninitialized `ans` causes undefined behavior. Should initialize `ans = 0;`]
    }
    return ans;
    
}