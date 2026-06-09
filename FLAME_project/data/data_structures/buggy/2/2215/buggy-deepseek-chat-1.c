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
            num[count1+1]*=num[count1]; // @@ [Error: This incorrectly multiplies num[count1+1] by num[count1], but num[count1] may not be the correct operand. The logic for handling multiplication and division is flawed because it doesn't properly track the sequence of operations and operands.]
        }
        else if(s[i]=='/')
        {
            num[count1+1]/=num[count1]; // @@ [Error: Similar to multiplication, this incorrectly divides num[count1+1] by num[count1] without proper operand tracking, leading to wrong results.]
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='=')
        {
            count2++;//记出现的大数 
            NUM[count2]=num[count1]; // @@ [Error: This assigns num[count1] to NUM[count2], but num[count1] may have been modified by previous multiplication/division operations, and the indexing is incorrect because count1 is incremented for every operator, not just for numbers.]
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
            NUM[count+1]+=NUM[count]; // @@ [Error: This incorrectly adds NUM[count] to NUM[count+1], but the addition should be applied to the accumulated result, not to the next element. The logic for addition and subtraction is flawed.]
        }
        else if(s[i]=='-')
        {
            NUM[count+1]-=NUM[count]; // @@ [Error: Similar to addition, this incorrectly subtracts NUM[count] from NUM[count+1], leading to wrong results.]
        }
    }
    printf("%d",NUM[record2]); // @@ [Error: The final output uses NUM[record2] which may not hold the correct final result due to the flawed logic in the loops above.]
    return 0;
}