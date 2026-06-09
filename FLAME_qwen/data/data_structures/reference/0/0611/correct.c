#include<stdio.h>

int main()
{
 char s[100];
 scanf("%s",s);


 int i,k=0;
 printf("%c",s[0]);
 for(i=1;s[i]!='\0';i++)
 {
if(s[i]=='-'&&s[i-1]>='0'&&s[i-1]<=s[i+1]&&s[i+1]<='9')
   for(k=1;k<s[i+1]-s[i-1];k++)
     printf("%c",s[i-1]+k);

      else if(s[i]=='-'&&s[i-1]>='a'&&s[i-1]<=s[i+1]&&s[i+1]<='z')
   for(k=1;k<s[i+1]-s[i-1];k++)
     printf("%c",s[i-1]+k);

      else if(s[i]=='-'&&s[i-1]>='A'&&s[i-1]<=s[i+1]&&s[i+1]<='Z')
   for(k=1;k<s[i+1]-s[i-1];k++)
     printf("%c",s[i-1]+k);

     else

     printf("%c",s[i]);



}
return 0;
}



