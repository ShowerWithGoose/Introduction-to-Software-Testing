#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

char s[10000], e[10000];
int i=0, j=0, k=0, num=0;
int main()
{
	gets(s);
	for(i=0,j=0;s[i]!='\0';i++)
    {
        num=0;
        if(s[i]!='-')
        {
            e[j]=s[i];
            j++;
        }
        else
        {
            if((s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z') || (s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z') || (s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'))
            {
                num=s[i+1]-s[i-1]-1;
                if(num<0)
                {
                    e[j]=s[i];
                    j++;
                }
                else
                {
                    while(num)
                    {
                        e[j]=s[i+1]-num;
                        j++;
                        num--;
                    }
                }
            }
            else
            {
                e[j]=s[i];
                j++;
            }
        }
    }
    printf("%s", e);
	return 0;
}

