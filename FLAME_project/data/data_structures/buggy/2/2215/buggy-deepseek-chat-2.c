#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s0[200]={'\0'},s[200]={'\0'};
    int record1=0,record2=0;
    gets(s0);
    for(int i=0,j=0;s0[i]!='\0';i++)
    {
        if(s0[i]!=' ')
        {
            s[j]=s0[i];
            if(s[j]=='+'||s[j]=='-'||s[j]=='='||s[j]=='*'||s[j]=='/'||s[j]=='=')
                record1++; 
            if(s[j]=='+'||s[j]=='-'||s[j]=='=')
                record2++;
            j++;
        }
    }
    int NUM[200]={0},num[200]={0},i=0;
    for(int j=1;j<=record1;j++)
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
            num[count1+1]*=num[count1]; // @@ [Error: This incorrectly multiplies num[count1+1] by num[count1], but the multiplication should be applied to the current number and the next number, and the result should be stored in the next number's position. However, the logic of indexing is flawed because count1 increments before this operation, so count1+1 and count1 do not correspond to the correct operands. Additionally, this approach does not handle operator precedence correctly; it attempts to process multiplication/division in a single pass without properly separating terms for addition/subtraction.]
        }
        else if(s[i]=='/')
        {
            num[count1+1]/=num[count1]; // @@ [Error: Same issue as multiplication; the division is applied to wrong indices due to count1 incrementing earlier, and the logic does not correctly handle integer division in the context of operator precedence.]
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='=')
        {
            count2++;//记出现的大数 
            NUM[count2]=num[count1]; // @@ [Error: This stores num[count1] into NUM, but count1 may not correspond to the correct number index because the previous loop increments count1 for every operator, including * and /, leading to misalignment. The term value should be the result of evaluating a sequence of * and / operations, but the current indexing is incorrect.]
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
            NUM[count+1]+=NUM[count]; // @@ [Error: This attempts to accumulate addition/subtraction but uses incorrect indexing. NUM[count+1] and NUM[count] do not correspond to the correct terms because the previous loop stored terms in NUM with count2, and here count is incremented separately, causing misalignment. The logic does not correctly compute the final result.]
        }
        else if(s[i]=='-')
        {
            NUM[count+1]-=NUM[count]; // @@ [Error: Same indexing issue as addition; the subtraction is applied to wrong elements, leading to incorrect final answer.]
        }
    }
    printf("%d",NUM[record2]); // @@ [Error: record2 counts only +, -, = operators, but the final result is stored in NUM[record2], which may not be the correct index due to the flawed accumulation logic above. The expected output is 602, but this outputs -610.]
    return 0;
}