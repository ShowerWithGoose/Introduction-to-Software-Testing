#include <stdio.h>
#include<math.h>
#include<string.h>
void transform(char*,int*,int*);
void getoperator(char *,char *);
int cal(char *,int *,int);
int main()
{
    char exp[50];
    char opera[50];    //存运算符 @@ opera array is not initialized, leading to garbage values when accessed in cal function.
    int num[50]={0};  //存数字 
    int n=0;
    gets(exp); @@ gets is deprecated and removed in C11, causing compilation error in modern environments. Use fgets instead.
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
    while(i<n) @@ Loop condition i<n accesses opera out of bounds since there are only n-1 operators. Should be i<n-1 or check for null terminator.
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
    int ans; @@ ans is uninitialized, causing undefined behavior when accumulating the sum. Should be int ans=0;
    for(j=0;j<n;j++)
    {
        ans=ans+num[j];
    }
    return ans;
    
}