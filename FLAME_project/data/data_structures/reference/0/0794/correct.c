#include<stdio.h>
#include<string.h>
int main()
{
char zu[500];
char xin[500];
gets(zu);

for(int i=0,j=0;i<=strlen(zu);i++){
    if(zu[i]=='-')
      { if((zu[i-1]>='a'&&zu[i-1]<='z')&&(zu[i+1]>='a'&&zu[i+1]<='z')&&((zu[i+1]-zu[i-1])>0))
       {for(int k=1;k<(zu[i+1]-zu[i-1]);k++)
          {xin[j]=xin[j-1]+1;j++;}}

       else if((zu[i-1]>='A'&&zu[i-1]<='Z')&&(zu[i+1]>='A'&&zu[i+1]<='Z')&&((zu[i+1]-zu[i-1])>0))
       {for(int k=1;k<(zu[i+1]-zu[i-1]);k++)
          {xin[j]=xin[j-1]+1;j++;}}

       else if((zu[i-1]>='0'&&zu[i-1]<='9')&&(zu[i+1]>='0'&&zu[i+1]<='9')&&((zu[i+1]-zu[i-1])>0))
       {for(int k=1;k<(zu[i+1]-zu[i-1]);k++)
          {xin[j]=xin[j-1]+1;j++;}}
       else
       {
           xin[j]=zu[i];j++;
       }


      }

    if(zu[i]!='-')
       {xin[j]=zu[i];j++;


}}

puts(xin);
return 0;


}

