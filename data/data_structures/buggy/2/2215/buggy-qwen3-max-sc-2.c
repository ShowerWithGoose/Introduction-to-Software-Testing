#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s0[200]={'\0'},s[200]={'\0'};
    int record1=0,record2=0;
    gets(s0); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers.]
    for(int i=0,j=0;s0[i]!='\0';i++)
    {
        if(s0[i]!=' ')
        {
            s[j]=s0[i];
            if(s[j]=='+'||s[j]=='-'||s[j]=='='||s[j]=='*'||s[j]=='/'||s[j]=='=') // @@ [Redundant check: 's[j]=='=' appears twice in the condition. This doesn't cause a logic error but is poor style; however, the real issue is elsewhere.]
                record1++; 
            if(s[j]=='+'||s[j]=='-'||s[j]=='=')
                record2++;
            j++;
        }
    }
    int NUM[200]={0},num[200]={0},i=0;
    for(int j=1;j<=record1;j++) // @@ [Loop starts at j=1 but num[] indexing assumes numbers start at index 1; however, parsing logic below may skip or misalign numbers due to incorrect tokenization.]
    {
        int flag=0;
        for(;s[i]!='=';i++) // @@ [This loop condition may run past valid data if '=' is not found early; also, inner break only exits one level, leading to potential out-of-bound reads.]
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
                i++; // @@ [Incrementing 'i' here causes skipping of the next character after an operator, which may be a digit, leading to missed digits or incorrect parsing.]
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
            num[count1+1]*=num[count1]; // @@ [Incorrect operand order: should be num[count1] *= num[count1+1], but more fundamentally, this modifies future operands prematurely and breaks left-to-right evaluation for * and /. Also, uses unverified indices that may be out of sync.]
        }
        else if(s[i]=='/')
        {
            num[count1+1]/=num[count1]; // @@ [Same as above: wrong order (should be num[count1] / num[count1+1]) and modifies later value incorrectly. Also integer division truncation is okay per spec, but logic is flawed.]
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='=')
        {
            count2++;//记出现的大数 
            NUM[count2]=num[count1]; // @@ [Uses 'count1' as index into 'num', but 'count1' counts operators, not numbers; number of numbers = number of operators + 1, so indexing is off.]
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
            NUM[count+1]+=NUM[count]; // @@ [Wrong accumulation direction: should add current term to running total, not overwrite future terms. Also, NUM[count+1] may be uninitialized.]
        }
        else if(s[i]=='-')
        {
            NUM[count+1]-=NUM[count]; // @@ [Same issue: modifies future element instead of accumulating result correctly.]
        }
    }
    printf("%d",NUM[record2]); // @@ [Final result is taken from NUM[record2], but due to incorrect accumulation and indexing throughout, this value is not the correct expression result.]
    return 0;
}