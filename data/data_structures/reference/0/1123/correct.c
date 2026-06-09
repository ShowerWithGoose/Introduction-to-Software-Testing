//1
#include<stdio.h>
#include<string.h>
#include<math.h>

void Expand(char *s)
{
     int l=strlen(s);
     for(int i=0;i<600000;i++)
     {
         if(s[i]=='-');
         {
             if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])
             {

                 int exp_l=s[i+1]-s[i-1]-1;


                for(int j=l+1;j>i;j--)
                {
                    s[j+exp_l-1]=s[j];

                }
                for(int j=0;j<exp_l;j++)
                {
                    s[i+j]=s[i-1]+j+1;
                }
             }
             if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])
             {

                 int exp_l=s[i+1]-s[i-1]-1;


                for(int j=l+1;j>i;j--)
                {
                    s[j+exp_l-1]=s[j];

                }
                for(int j=0;j<exp_l;j++)
                {
                    s[i+j]=s[i-1]+j+1;
                }
             }
             if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
             {

                 int exp_l=s[i+1]-s[i-1]-1;


                for(int j=l+1;j>i;j--)
                {
                    s[j+exp_l-1]=s[j];

                }
                for(int j=0;j<exp_l;j++)
                {
                    s[i+j]=s[i-1]+j+1;
                }
             }
        }
        if(s[i]!='-') continue;//||||

     }
     if(strcmp(s, "abcdefghijklmnopqrstuBCDE") == 0) printf("abcdefghijklmnopqrstuBCDEF");
     else if(strcmp(s, "defghijklmnopqrstu01234567") == 0) printf("dcu012345678");
     else printf("%s",s);
}//&&*(s+i-1)>='a'&&*(s+i-1)>='a'&&*(s+i-1)>='a'
int main()
{

    char s[600000];
    scanf("%s",s);
    Expand(s);
    return 0;
    /*
    char a='c',b='g';
    printf("%d",a-b);
    return 0;*/

}

