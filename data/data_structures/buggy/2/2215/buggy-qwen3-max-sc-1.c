#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s0[200]={'\0'},s[200]={'\0'};
    int record1=0,record2=0;
    gets(s0); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers.]
    for(int i=0,j=0;s0[i]!='\0';i++)
    {
        if(s0[i]!=' ')
        {
            s[j]=s0[i];
            if(s[j]=='+'||s[j]=='-'||s[j]=='='||s[j]=='*'||s[j]=='/'||s[j]=='=') // @@ [The '=' is checked twice unnecessarily, but not a critical error. However, logic below relies on correct parsing which may be flawed due to other issues.]
                record1++; 
            if(s[j]=='+'||s[j]=='-'||s[j]=='=')
                record2++;
            j++;
        }
    }
    int NUM[200]={0},num[200]={0},i=0;
    for(int j=1;j<=record1;j++) // @@ [Loop assumes there are exactly 'record1' numbers, but number of numbers is actually 'record1 + 1' because operators separate numbers (e.g., "1+2" has 2 numbers and 1 operator). This leads to incorrect parsing and missing last number.]
    {
        int flag=0;
        for(;s[i]!='=';i++)
        {
            if(flag==0&&s[i]>='0'&&s[i]<='9')
            {
                num[j]=s[i]-'0';
                flag=1;
            }
            else if(s[i]>='0'&&s[i]<='9')
            {
                num[j]=10*num[j]+s[i]-'0';
            }
            else
            {
                i++;
                flag=0;
                break;
            }
        }
    }//记所有小数 
    int count1,count2,count;
    for(i=0,count1=0,count2=0;s[i]!='\0';i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
            count1++;//记现在出现的小数 
        if(s[i]=='*')
        {
            num[count1+1]*=num[count1]; // @@ [Incorrect order: should be num[count1] *= num[count1+1], but also indexing is off because count1 was just incremented before this check, leading to wrong operands.]
        }
        else if(s[i]=='/')
        {
            num[count1+1]/=num[count1]; // @@ [Same issue as multiplication: operands are reversed and indexing is incorrect. Should be num[count1] /= num[count1+1]. Also, integer division direction is wrong.]
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='=')
        {
            count2++;//记出现的大数 
            NUM[count2]=num[count1];
        }
    }
    for(i=0,count=0;s[i]!='=';i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='=')
        {
            count++;//记出现的大数
        }
        if(s[i]=='+')
        {
            NUM[count+1]+=NUM[count]; // @@ [Logic error: accumulates forward instead of backward. Should apply operation between current total and next operand, not overwrite future values. Also, NUM[count+1] may be uninitialized.]
        }
        else if(s[i]=='-')
        {
            NUM[count+1]-=NUM[count]; // @@ [Same accumulation error as '+'.]
        }
    }
    printf("%d",NUM[record2]); // @@ [May print uninitialized or incorrectly computed value due to multiple prior logic errors in parsing and evaluation order.]
    return 0;
}