#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[100];
int main()
{
 int a=0,b=0,t=0,l=0;
 int i;
 gets(s);
 if(s[0]=='-')
 {
    l++;
      for(i=0;i<strlen(s);i++)
       s[i]=s[i+1];}
 int m=1, k=strlen(s);
 for(i=0;i<k;i++)
 {
 if(s[i]=='.') b=i;
 if(t==0) { if(s[i]=='0'||s[i]=='.')a=i;
            else t++;}
 if(m){if(s[k-i-1]=='0')s[k-i-1]='\0';
            else m--;}
 }
// for(i=0;i<k;i++)printf(" %c ",s[i]);
if(l) printf("-");
m=(a>0)?a+1:0;
printf("%c",s[m]);
if(s[m+1])
{
    printf(".");
   for(i=1;s[m+i]!='\0'&&m+i!=b;i++) printf("%c",s[m+i]);
  if(a<b){for(i=1;s[b+i]!='\0';i++) printf("%c",s[b+i]);}
}
printf("e%d",b-a-1);
return 0;
}

