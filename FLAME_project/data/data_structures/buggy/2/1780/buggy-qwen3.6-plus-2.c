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
            num++; // @@ The pointer 'num' is incremented locally, but the changes to the pointer address are not reflected in the caller's array effectively for subsequent accesses if intended as a base pointer update, however the critical error is that 'j' is used to count but 'num' pointer arithmetic is mixed. More importantly, the logic skips operators incorrectly.
            j++;
            flag=0;
        }
        i++;   //跳过符号  // @@ This line unconditionally increments 'i', skipping the next character regardless of whether it was an operator or part of the number parsing loop exit condition. If the previous while loop exited because of a non-digit (operator), this increment skips that operator, causing 'getoperator' to potentially miss it or misalign parsing if spaces aren't handled perfectly. However, the bigger issue is in 'cal'.
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
            num[i+1]=num[i+1]*num[i]; // @@ Logic Error: For multiplication, the result should replace the left operand or be accumulated correctly. Here it updates the right operand. Then it sets opera[i] to '+'. But in the final summation, num[i] is added. If we set num[i]=0 later, we lose the left operand? No, look at next line.
            opera[i]='+';
            num[i]=0; // @@ Logic Error: It sets the left operand to 0. So when summing, num[i] contributes 0. The result is stored in num[i+1]. This effectively shifts the result to the right. This works for a single pass IF the next operation doesn't interfere. However, standard precedence handling usually collapses the left side. Let's trace: 20 * 30. num[1]=20, num[2]=30. op[1]='*'. num[2] becomes 600. num[1] becomes 0. op[1] becomes '+'. Sum: 0 + 600... Correct so far.
            i++; 
        }
        else if(opera[i]=='/')
        {
            num[i+1]=num[i]/num[i+1]; // @@ Logic Error: Integer division order. num[i] / num[i+1] is correct for left/right.
            opera[i]='+';
            num[i]=0; // @@ Same logic as multiplication.
            i++;
        }
        else
        i++;

    }
    int ans; // @@ Variable 'ans' is uninitialized. It should be initialized to 0.
    for(j=0;j<n;j++)
    {
        ans=ans+num[j]; // @@ Using uninitialized variable 'ans' leads to undefined behavior (garbage value).
    }
    return ans;
    
}