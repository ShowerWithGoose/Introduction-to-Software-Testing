#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char s1[10000],s2[10000];
    gets(s1);
    int i1,i2=0,i3,len=strlen(s1);
    for(i1=0;i1<len;i1++)
    {
        if(s1[i1]=='-' && i1!=0 && i1!=len-1)
        {
            if(s1[i1-1]>='0' && s1[i1-1]<='9' && s1[i1+1]>='0' && s1[i1+1]<='9')
            {
                for(i3=s1[i1-1]+1;i3<s1[i1+1];i3++)
                {
                    s2[i2]=i3;
                    i2++;
                }
            }
            else if (s1[i1-1]>='A' && s1[i1-1]<='Z' && s1[i1+1]>='A' && s1[i1+1]<='Z')
            {
                for(i3=s1[i1-1]+1;i3<s1[i1+1];i3++)
                {
                    s2[i2]=i3;
                    i2++;
                }
            }
            else if (s1[i1-1]>='a' && s1[i1-1]<='z' && s1[i1+1]>='a' && s1[i1+1]<='z')
            {
                for(i3=s1[i1-1]+1;i3<s1[i1+1];i3++)
                {
                    s2[i2]=i3;
                    i2++;
                }
            }
            else
            {
                s2[i2]=s1[i1];
                i2++;
            }
        }
        else
        {
            s2[i2]=s1[i1];
            i2++;
        }
    }
    puts(s2);
    return 0;
}
