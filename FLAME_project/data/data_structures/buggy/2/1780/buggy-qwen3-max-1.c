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
            num++;
            j++;
            flag=0;
        }
        i++;   //跳过符号 @@ [This increment causes skipping of the next character after a number, which may be part of another number or an operator; it incorrectly assumes every number is followed by exactly one non-digit character. For example, in "10+20", after reading '10', i points to '+', then i++ moves to '2', but then the loop skips '2' because the outer while increments i again. This leads to incorrect parsing of numbers.]
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
            num[i+1]=num[i+1]*num[i]; @@ [The operands are in the wrong order: it should be num[i] * num[i+1], not num[i+1] * num[i]. Although multiplication is commutative, this becomes critical for division. Also, setting num[i]=0 breaks subsequent addition logic.]
            opera[i]='+';
            num[i]=0;
            i++; 
        }
        else if(opera[i]=='/')
        {
            num[i+1]=num[i]/num[i+1]; @@ [Division operands are reversed: it should be num[i] / num[i+1], not num[i] / num[i+1] as written — wait, actually the code says num[i]/num[i+1], which is correct order, BUT the assignment is to num[i+1], and then num[i] is set to 0. However, the bigger issue is that this approach processes operators left-to-right without respecting operator precedence correctly across the entire expression. Moreover, the algorithm tries to convert everything to additions by modifying signs and values, but fails because it doesn't handle precedence properly when multiple * or / appear, and also because it overwrites num[i] with 0, which affects later accumulation.]
            opera[i]='+';
            num[i]=0;
            i++;
        }
        else
        i++;

    }
    int ans; @@ [Variable 'ans' is uninitialized. It should be initialized to 0 before the loop.]
    for(j=0;j<n;j++)
    {
        ans=ans+num[j];
    }
    return ans;
    
}