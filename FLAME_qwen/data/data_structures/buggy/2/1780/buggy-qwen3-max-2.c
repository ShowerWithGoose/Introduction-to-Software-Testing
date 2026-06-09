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
    gets(exp); // @@ [Using `gets` is unsafe and deprecated; may cause buffer overflow. However, the immediate error is likely due to uninitialized `ans` in `cal` and incorrect parsing logic leading to wrong results, but the compilation error mentioned suggests missing includes or linking issues. Yet, given the test environment error "/bin/sh: 1: gcc: not found", that's external. The real bugs are logical: (1) In `transform`, skipping a character after digits even if it's '=' or end, causing miscount. (2) In `cal`, division uses `num[i]/num[i+1]` which is backward. (3) `ans` in `cal` is uninitialized. But per instructions, mark lines with errors.]
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
        i++;   //跳过符号 // @@ [This unconditionally increments `i`, which may skip past the '=' or go out of bounds, and also skips one extra character after number, possibly skipping a digit if no space. Also, when at last number followed by '=', this moves past '=' correctly, but if expression ends without operator, it may over-increment. However, main issue is that it assumes every number is followed by an operator, which fails for single number expressions.]
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
            num[i+1]=num[i]/num[i+1]; // @@ [Division operands are reversed; should be `num[i] / num[i+1]` but here it's written as `num[i]/num[i+1]` which is correct? Wait: current code says `num[i+1]=num[i]/num[i+1];` which is WRONG. It should be `num[i+1] = num[i] * num[i+1]` for multiplication (which is correct above), but for division it should be `num[i+1] = num[i] / num[i+1]` — however, the assignment is to `num[i+1]`, so the left operand is `num[i]` and right is `num[i+1]`, so `num[i]/num[i+1]` is correct order. BUT: the issue is that after processing, `num[i]` is set to 0, and later summed. However, the bigger issue is that the algorithm processes left-to-right without considering operator precedence properly in one pass. Also, note that `n` is count of numbers, so operators count is `n-1`, but loop runs `i < n` which may access `opera[n-1]` okay, but when `i = n-1`, `num[i+1]` is out of bounds. So this line may access invalid memory when `i == n-1`.]
            opera[i]='+';
            num[i]=0;
            i++;
        }
        else
        i++;

    }
    int ans; // @@ [`ans` is used uninitialized in the following loop. Should be initialized to 0.]
    for(j=0;j<n;j++)
    {
        ans=ans+num[j];
    }
    return ans;
    
}