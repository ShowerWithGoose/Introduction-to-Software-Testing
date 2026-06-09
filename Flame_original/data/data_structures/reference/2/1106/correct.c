#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int i,j,l,num[512];
    char line[512],op[512];
    memset(num,0,sizeof(num));
    fgets(line,sizeof(line),stdin);
    l=strlen(line);
    while(line[l-1]=='\n'||line[l-1]=='\r'||line[l-1]=='=') line[--l]='\0';
    for(i=0,j=0;i<l;i++)
        if(line[i]!=' ') 
            line[j++]=line[i];
    l=j;
    for(i=0,j=0;i<l;i++)
    {
        if(isdigit(line[i]))
            num[j]=num[j]*10+line[i]-'0';
        else
            op[j++]=line[i];
    }//Now j is the last number
    for(i=0;i<j;i++)
    {
        if(op[i]=='*')
        {
            num[i]*=num[i+1];
            for(int k=i;k<j;k++)
            {
                num[k+1]=num[k+2];
                op[k]=op[k+1];
            }
            j--;
            i--;
        }
        if(op[i]=='/')
        {
            num[i]/=num[i+1];
            for(int k=i;k<j;k++)
            {
                num[k+1]=num[k+2];
                op[k]=op[k+1];
            }
            j--;
            i--;
        }
    }
    for(i=0;i<j;i++)
    {
        if(op[i]=='+')
        {
            num[i]+=num[i+1];
            for(int k=i;k<j;k++)
            {
                num[k+1]=num[k+2];
                op[k]=op[k+1];
            }
            j--;
            i--;
        }
        if(op[i]=='-')
        {
            num[i]-=num[i+1];
            for(int k=i;k<j;k++)
            {
                num[k+1]=num[k+2];
                op[k]=op[k+1];
            }
            j--;
            i--;
        }
    }
    printf("%d",num[0]);
}
