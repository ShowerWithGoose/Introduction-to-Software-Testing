#include<stdio.h>





 int main()
 {
     char s[1000],t[1000];
     char *p=s,i=0,j=0;
     gets(s);
     while(*p!='\0')
     {
         if(*p=='-')
         {
             if((*(p-1)>='0'&&*(p-1)<='9') && (*(p+1)>='0'&&*(p+1)<='9'&&*(p+1)>*(p-1)))
             {
                 int temp1=*(p-1)-'0';
                 for(int k=0;k<(*(p+1)-*(p-1))-1;k++)
                 {
                     temp1++;
                     t[i++]='0'+temp1;
                 }
             }
             else if((*(p-1)>='a'&&*(p-1)<='z') && (*(p+1)>='a'&&*(p+1)<='z'&&(*(p+1)-*(p-1)>0)))
                {
                    char temp1=*(p-1);
                    for(int k=0;k<(*(p+1)-*(p-1))-1;k++)
                    {
                        temp1=temp1+1;
                        t[i++]=temp1;
                    }
                }
             else if((*(p-1)>='A'&&*(p-1)<='Z') && (*(p+1)>='A'&&*(p+1)<='Z'&&(*(p+1)-*(p-1)>0)))
                {
                    char temp1=*(p-1);
                    for(int k=0;k<(*(p+1)-*(p-1))-1;k++)
                    {
                        temp1=temp1+1;
                        t[i++]=temp1;
                    }
                }
            else t[i++]=*p;

         }
         else t[i++]=*p;
         p++;

     }
     t[i]='\0';
     puts(t);
 }

