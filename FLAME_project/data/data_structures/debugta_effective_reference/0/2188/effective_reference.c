#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char s[100];
    char p[200];
    int j=0;
    int i;
    scanf("%s",s);
    for(i=0;s[i+1]!='\0';i++)
    {
        if(s[i]=='-'&& i!=0)
        {

        if(s[i-1]>='0' && s[i-1]<='9' && s[i+1]>s[i] && s[i+1]<='9')
        {
            int hc=s[i+1]-s[i-1];
            for(int k=1;k<hc;k++)
            {
                p[j]=s[i-1]+k;j++;
            }
        }
        else if(s[i-1]>='a' && s[i-1]<='z' && s[i+1]>s[i] && s[i+1]<='z')
        {
            int hc=s[i+1]-s[i-1];
            for(int k=1;k<hc;k++)
            {
                p[j]=s[i-1]+k;j++;
            }
        }
        else if(s[i-1]>='A' && s[i-1]<='Z' && s[i+1]>s[i] && s[i+1]<='Z')
        {
            int hc=s[i+1]-s[i-1];
            for(int k=1;k<hc;k++)
            {
                p[j]=s[i-1]+k;j++;
            }
        }
        else {p[j]=s[i];j++;}
        }
        else {p[j]=s[i];j++;}
    }
    p[j]=s[i];p[j+1]='\0';
    puts(p);
    return 0;
}

