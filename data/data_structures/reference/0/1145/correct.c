#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char str[1000];
gets(str);
int sl=strlen(str);
char str2[1000];
int j=0;
for (int i = 0; i < sl; i++)
{
    if (str[i]!='-')
    {
       str2[j]=str[i];
       j++;
    }
    if (str[i]=='-')
    {
        if ((str[i-1]<str[i+1])&&(str[i-1]>='a'&&str[i+1]<='z'))
        {
           for (int x = 1; x+str[i-1] < str[i+1] ; x++)
           {
               str2[j]=str[i-1]+x;
               j++;
           }
           
        }
        else if ((str[i-1]<str[i+1])&&(str[i-1]>='A'&&str[i+1]<='Z'))
        {
            for (int x = 1; x+str[i-1] < str[i+1] ; x++)
           {
               str2[j]=str[i-1]+x;
               j++;
           }
        }
        else if ((str[i-1]<str[i+1])&&(str[i-1]>='0'&&str[i+1]<='9'))
        {
            for (int x = 1; x+str[i-1] < str[i+1] ; x++)
           {
               str2[j]=str[i-1]+x;
               j++;
           }
        }
        else {str2[j]=str[i];j++;}
    }
}

puts(str2);
return 0;


}
