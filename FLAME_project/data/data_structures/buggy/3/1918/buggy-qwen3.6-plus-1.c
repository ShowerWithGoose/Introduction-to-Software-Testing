#include<stdio.h>
#include<string.h>
#include<ctype.h>
char chinput[1000],choutput[1000];
int main()
{
    gets(chinput);
    int len=strlen(chinput),point=0;
    int flag=0,sum=0;
    int i=0,j=0,k=0;
    if(chinput[0]=='0') flag=1; //判断位数正负 
    if(flag==0)
    {
        for(;i<len;i++)
        {
            if(chinput[i]=='.')
            {
                point=i-1;//记录小数点在哪里 
            }
            else if(isdigit(chinput[i]))
            {
                choutput[j]=chinput[i];
                j++;//输入有多少个数字 
            }
        }
        int lenth=j;
        while(choutput[j-1]=='0')
        {
            j--;
            lenth--;//lenth为有效数字个数 
        }
        if(lenth==1)
        {
            printf("%ce%d\n",choutput[0],point);
        }
        else
        {
            printf("%c%c",choutput[0],'.');//输出科学计数法 
            for(k=1;k<lenth;k++)
            {
                printf("%c",choutput[k]);
            }
            printf("%c%d\n",'e',point);
        }
    }
    else if(flag==1)//小于零的整数位数为负数 
    {
        j=0;
        for(i=0;i<len;i++)
        {
            if(chinput[i]=='0')//找小数点后有几个零 
            {
                sum++;
            }
            else if(chinput[i]!='0'&&chinput[i]!='.')
            {
                break;
            }
        }
        for(i=sum+1;i<len;i++)
        {            
            choutput[j]=chinput[i];
            j++;
        }
        int lenth1=j;
        while(choutput[j-1]=='0')
        {
            j--;
            lenth1--;//lenth为有效数字个数 
        }
        if(lenth1==0)
        {
            printf("0e0\n");
        }
        else if(lenth1==1)
        {
            printf("%ce-%d\n",choutput[0],sum);
        }
        else
        {
            for(k=0;k<j;k++) // @@ The code prints all significant digits without inserting a decimal point after the first digit, violating the scientific notation format (e.g., prints "9123..." instead of "9.123..."). It should print choutput[0], then '.', then the rest.
               {
                printf("%c",choutput[k]);
            }
            printf("%c-%d\n",'e',sum);
        }
        
    }
    return 0;
}