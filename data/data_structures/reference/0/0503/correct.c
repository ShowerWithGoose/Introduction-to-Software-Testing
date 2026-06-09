#include<stdio.h>
 int main()
 {
     char str[100] = "\0";
     int i,j;

     gets(str);

     for(i = 0;str[i] != '\0';i ++)
     {
         if(str[i]=='-'&&i>0)
         {
             if(str[i-1]>='0'&&str[i+1]<='9')
             {
                 for (j = 1;j < str[i+1]-str[i-1];j ++)
                    printf("%c", str[i-1]+j);
             }
             else if(str[i-1]>='A'&&str[i+1]<='Z')
             {
                 for (j = 1;j < str[i+1]-str[i-1];j ++)
                    printf("%c", str[i-1]+j);
             }
             else if(str[i-1]>='a'&&str[i+1]<='z')
             {
                 for (j = 1;j < str[i+1]-str[i-1];j ++)
                    printf("%c", str[i-1]+j);
             }
             else printf("-");
         }
         else printf("%c", str[i]);
     }

     return 0;
 }



