#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{char a[110];
int x,y;
gets(a);
if(a[0]=='0'&&a[1]=='.'){
for(int n=2;n<strlen(a);n++){
if(a[n]!='0')
{y=n;
break;
}}
if(a[y+1]=='\0')
{printf("%c",a[y]);
printf("e-");
printf("%d",y-1);

}
else{
printf("%c",a[y]);
printf(".");
for(int w=y+1;w<strlen(a);w++)
printf("%c",a[w]);
printf("e");
printf("-");
printf("%d",y-1);
}}
if(a[0]!='0'&&a[1]=='.')
   {for(int j=0;j<strlen(a);j++)
   printf("%c",a[j]);
   printf("e0");}
for(int i=0;i<strlen(a);i++)
{if(a[i]=='.')
x=i;
}
if(x>1){
printf("%c",a[0]);
printf(".") ;
for(int k=1;k<x;k++)
printf("%c",a[k]);
for(int m=x+1;m<strlen(a);m++)
printf("%c",a[m]);
printf("e");
printf("%d",x-1);
}

return 0;
}



















