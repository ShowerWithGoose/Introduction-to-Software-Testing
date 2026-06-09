#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char s[100];
    char p[200];
    int t=0;
    int i;
    scanf("%s",s);
    for(i=0;s[i+1]!='\0';i++)
    {
        if(s[i]=='-'&& i!=0)
        {

        if(s[i-1]>='0' && s[i-1]<='9' && s[i+1]>s[i] && s[i+1]<='9')
        {
            int K=s[i+1]-s[i-1];
            for(int k=1;k<K;k++)
            {
                p[t]=s[i-1]+k;t++;
            }
        }
        else if(s[i-1]>='a' && s[i-1]<='z' && s[i+1]>s[i] && s[i+1]<='z')
        {
            int K=s[i+1]-s[i-1];
            for(int k=1;k<K;k++)
            {
                p[t]=s[i-1]+k;t++;
            }
        }
        else if(s[i-1]>='A' && s[i-1]<='Z' && s[i+1]>s[i] && s[i+1]<='Z')
        {
            int K=s[i+1]-s[i-1];
            for(int k=1;k<K;k++)
            {
                p[t]=s[i-1]+k;t++;
            }
        }
        else {p[t]=s[i];t++;}
        }
        else {p[t]=s[i];t++;}
    }
    p[t]=s[i];p[t+1]='\0';
    puts(p);
    return 0;
}

