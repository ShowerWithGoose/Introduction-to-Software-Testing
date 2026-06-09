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
    gets(exp);
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
            num++; // @@ The pointer 'num' is incremented locally, but the changes are not reflected in the caller's array effectively for subsequent accesses if intended to act as an iterator, however the main issue is that 'num' is passed by value (as a pointer copy). While *num writes to the correct location, incrementing the local copy 'num' means the next write *num=temp will overwrite the same memory location if the caller didn't advance their pointer. But here 'num' in main is an array base address. In transform, 'num' is a local pointer variable. 'num++' advances this local pointer. The next iteration writes to the NEW location. This part is actually logically okay for filling the array sequentially IF the caller passes the base address. However, the variable 'j' is used to count. The real bug is usually operator precedence handling. Let's look closer at 'cal'.
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
            num[i+1]=num[i+1]*num[i]; // @@ Logic Error: When handling '*', the result should replace the left operand or be accumulated correctly. Here it updates num[i+1]. Then num[i] is set to 0. This effectively shifts the value to the right. This is a valid strategy IF subsequent additions sum everything up. However, check division.
            opera[i]='+';
            num[i]=0;
            i++; 
        }
        else if(opera[i]=='/')
        {
            num[i+1]=num[i]/num[i+1]; // @@ Logic Error: Integer division order. The expression is A / B. num[i] is A, num[i+1] is B. The code does num[i]/num[i+1], which is correct for A/B. But it stores it in num[i+1]. Then sets num[i]=0. This matches the multiplication strategy.
            opera[i]='+';
            num[i]=0;
            i++;
        }
        else
        i++;

    }
    int ans; // @@ Uninitialized Variable: 'ans' is declared but not initialized to 0. Adding to an uninitialized variable leads to undefined behavior (garbage value).
    for(j=0;j<n;j++)
    {
        ans=ans+num[j];
    }
    return ans;
    
}