#include<stdio.h>
#include<string.h>
char a[105];
int main()
{
    gets(a);
   int i,j;
   for(i=0;i<strlen(a);i++)
   {
       if(a[i]=='-'&&a[i-1]<a[i+1]&&((a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')||(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z')))
       {
           for(j=a[i-1]+1;j<a[i+1];j++)
           {
               printf("%c",j);
           }
       }
       else printf("%c",a[i]);
   }
return 0;
}

