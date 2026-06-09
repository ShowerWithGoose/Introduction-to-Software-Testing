#include <stdio.h>
char line[10000];
void del_space(char s[])
{
    int i=0,j=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            s[j]=s[i];
            j++;
        }
    }
    s[j]='\0';
}
int judge(char s)
{
    if(s=='+'||s=='-') return 1;
    else if(s=='*'||s=='/') return 1;
    else if('0'<=s&&'9'>=s) return 0;
    else if(s=='=') return 2;
}

int main()
{
    gets(line);
    del_space(line);
    int i,num_work=0,num_num=0,numtemp=0,sum=0;
    int number[10000];
    char work[10000];
    for(i=0;line[i]!='\0';i++)
    {
        if(line[i]=='=') break;
        if(judge(line[i])==0)
        {
            numtemp=0;
            while(judge(line[i])==0)
            {
                numtemp=10*numtemp+line[i]-'0';
                i++;
            }
            number[num_num++]=numtemp;
            i--;
        }
        else if(judge(line[i])==1)
        {
            work[num_work++]=line[i];
        }
        if((num_work==(num_num-1))&&(num_work>0))
        {
            if(work[num_work-1]=='*')
            {
                number[num_num-2]*=number[num_num-1];
                num_num--;
                num_work--;
            }
            else if(work[num_work-1]=='/')
            {
                number[num_num-2]=number[num_num-2]/number[num_num-1];
                num_num--;
                num_work--;
            }
        }
    }
    sum=number[0];
    for(i=0;i<num_work;i++)
    {
        if(work[i]=='+') sum=sum+number[i+1];
        else if(work[i]=='-') sum=sum-number[i+1];
    }
    printf("%d",sum);





}

