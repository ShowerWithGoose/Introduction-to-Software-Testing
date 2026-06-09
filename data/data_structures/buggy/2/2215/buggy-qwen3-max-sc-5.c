#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s0[200]={'\0'},s[200]={'\0'};
    int record1=0,record2=0;
    gets(s0); // @@ [Using `gets` is unsafe and deprecated; it was removed from C11 standard and may cause compilation errors or warnings in modern compilers. Use `fgets` instead.]
    for(int i=0,j=0;s0[i]!='\0';i++)
    {
        if(s0[i]!=' ')
        {
            s[j]=s0[i];
            if(s[j]=='+'||s[j]=='-'||s[j]=='='||s[j]=='*'||s[j]=='/'||s[j]=='=') // @@ [Duplicate check for '='; harmless but redundant. Not a compilation error.]
                record1++; 
            if(s[j]=='+'||s[j]=='-'||s[j]=='=')
                record2++;
            j++;
        }
    }
    int NUM[200]={0},num[200]={0},i=0;
    for(int j=1;j<=record1;j++) // @@ [Loop logic is flawed: assumes number of operators equals number of numbers, which is incorrect. Also, parsing numbers incorrectly by skipping characters with `i++` inside loop causing misalignment. This leads to logical errors, but not compilation errors.]
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
                i++; // @@ [Incrementing `i` here skips the next character (often an operator), leading to incorrect parsing. This causes logical errors, not compilation errors.]
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
            num[count1+1]*=num[count1]; // @@ [Accessing `num[count1+1]` before it's properly parsed; also uses wrong order for multiplication (should be left-to-right). Logical error, not compilation.]
        }
        else if(s[i]=='/')
        {
            num[count1+1]/=num[count1]; // @@ [Same as above: division order is reversed (should be `num[count1] / num[count1+1]`). Also integer division direction is wrong. Logical error.]
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
            NUM[count+1]+=NUM[count]; // @@ [Incorrect accumulation: should start from first number and apply operations sequentially. This logic overwrites and misuses indices. Logical error.]
        }
        else if(s[i]=='-')
        {
            NUM[count+1]-=NUM[count]; // @@ [Same issue as above: wrong order and indexing for subtraction. Logical error.]
        }
    }
    printf("%d",NUM[record2]); // @@ [Outputting `NUM[record2]` which may be uninitialized or incorrect due to prior logic errors. Logical error.]
    return 0;
}