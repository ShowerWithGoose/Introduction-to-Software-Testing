#include<stdio.h>
int pointjudge(char[]);
int main()
{
    char s[105];
    int i,j,g;
    gets(s);
    if(pointjudge(s)<0)
    {
        printf("%c",s[1-pointjudge(s)]);
        if(s[-pointjudge(s)+2]!='\0')printf(".");
        for(i=-pointjudge(s)+2;s[i]!='\0';i++)
        {
            printf("%c",s[i]);
        }
        printf("e%d",pointjudge(s));
        return 0;
    }
    else
    {
        printf("%c",s[0]);
        if(s[1]!='\0')printf(".");
        for(i=1;s[i]!='\0';i++)
        {
            if(s[i]!='.')
            printf("%c",s[i]);
            else
            continue;
        }
        printf("e%d",pointjudge(s));
        return 0;
    }
}
int pointjudge(char s[])
{
    int k;
    for(k=0;s[k]!='\0';k++)
    {
        if(s[k]=='.')
        {
            if(k==1)//含小数点且小数点前只有一位数字的情况→原数e...
            {
                if(s[2]!='0')
                {
                    if(s[3]!='\0')return 0;
                    else return -1; 
                }
                else
                {
                while(s[k+1]=='0')k++;
                return -k;
                }
            }
            else return k-1;//含小数点且小数点前有k个数字→s[0].for(s[i],去'.')e(k-1)
        }
        else continue;
    }
    return k-1;//不含小数点的k+1位整数→s[0].for(s[i])ek
}


