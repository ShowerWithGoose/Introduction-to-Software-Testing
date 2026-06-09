#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
long long num[500]={0};
char str[1000],sym[500];
int main(void)
{   
    gets(str);
    int j=0,k=0;
    /*get all characters stored*/
    for (int i = 0; str[i]!='\0'; i++)
    {
        if(str[i]<='9'&&str[i]>='0')
        {
            while (str[i]<='9'&&str[i]>='0')
            {
                num[j]=num[j]*10+(str[i]-'0');
                i++;
            }
            j++;
        }
        
        if ((str[i]<=47&&str[i]>=42)||str[i]=='=')
        {
            sym[k]=str[i];
            k++;
        }                   
    }
    for (int i = 0; sym[i] != '='; i++)
    {
        for (int m = i; sym[m] == '*'||sym[m]=='/'; m++)
        {
            if (sym[m]=='*')
            {
                num[i]*=num[m+1];
            }
            else
            {
                num[i]/=num[m+1];
                
            }
            num[m+1]=0;
            sym[m]='+';
        }

        
    }
    long long sum=num[0];    
    for (int i = 0; sym[i] != '='; i++)
    {
        if(sym[i]=='+')
            sum+=num[i+1];
        else
            sum-=num[i+1];
    }
    printf("%lld",sum);
 
    return 0;
}



