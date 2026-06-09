#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char s[500];
int dat[300];
char cal[300];
int i=0;
char fuhao[6]={'+','-','*','/','(',')'};

int main()
{
    int top1=-1;
    int top2=-1;
    int a;
    while(1)
    {
      scanf("%c",&s[i]);
      if (s[i]=='=')
      {
          break;
      }
      i++;
    }
    for (int j = 0; j <= i; j++)
    {
       if (s[j]>='0'&&s[j]<='9')
       {
           a=s[j]-'0';
           for (int i = 1; ; i++)
           {
               if (s[j+i]>='0'&&s[j+i]<='9')
               {
                 a=a*10+(s[j+i]-'0');
                 
               }
               else
               {
                   j=j+i-1;
                   break;
               }
           }
           dat[++top1]=a;
       }
       else if (s[j]!=' '&&s[j]!='=')
       {
           if (s[j]=='+'||s[j]=='-')
           {
               if (top2==-1)
               {
                   cal[++top2]=s[j];
               }
               else if(cal[top2]!='(')
               {
                 if (cal[top2]=='+')
                 {
                     dat[top1-1]=dat[top1]+dat[top1-1];
                     top1--;
                 }
                 if (cal[top2]=='-')
                 {
                     dat[top1-1]=dat[top1-1]-dat[top1];
                     top1--;
                 }
                 if (cal[top2]=='*')
                 {
                     dat[top1-1]=dat[top1]*dat[top1-1];
                     top1--;
                 }
                 if (cal[top2]=='/')
                 {
                     dat[top1-1]=dat[top1-1]/dat[top1];
                     top1--;
                 }
                  cal[top2]=s[j];

               }
               else if(cal[top2]=='(')
               {
                   cal[++top2]=s[j];
               }
               
           }
           else if(s[j]=='*'||s[j]=='/')
           {
              if (top2==-1)
               {
                   cal[++top2]=s[j];
               }
               else if(cal[top2]!='(')
               {
                 if(cal[top2]=='+'||cal[top2]=='-')
                  {
                      cal[++top2]=s[j];
                  }
                  else
                  {
                      if (cal[top2]=='*')
                    {
                     dat[top1-1]=dat[top1]*dat[top1-1];
                     top1--;
                    }
                   if (cal[top2]=='/')
                   {
                     dat[top1-1]=dat[top1-1]/dat[top1];
                     top1--;
                   }
                  cal[top2]=s[j];
                  }
               }
               else if(cal[top2]=='(')
               {
                   cal[++top2]=s[j];
               }

           }
           else if(s[j]=='(')
           {
                cal[++top2]=s[j];
           }
           else if(s[j]==')')
           {
               while (cal[top2]!='(')
               {
                   if (cal[top2]=='+')
                 {
                     dat[top1-1]=dat[top1]+dat[top1-1];
                     top1--;
                 }
                 if (cal[top2]=='-')
                 {
                     dat[top1-1]=dat[top1-1]-dat[top1];
                     top1--;
                 }
                 if (cal[top2]=='*')
                 {
                     dat[top1-1]=dat[top1]*dat[top1-1];
                     top1--;
                 }
                 if (cal[top2]=='/')
                 {
                     dat[top1-1]=dat[top1-1]/dat[top1];
                     top1--;
                 }
                 top2--;
               }
               top2--;
           }
           
       }
       else if(s[j]=='=')
       {
         while (top1>0)
         {
            if (top2>=0)
            {
                if (cal[top2]=='+')
                 {
                     dat[top1-1]=dat[top1]+dat[top1-1];
                     top1--;
                 }
                 if (cal[top2]=='-')
                 {
                     dat[top1-1]=dat[top1-1]-dat[top1];
                     top1--;
                 }
                 if (cal[top2]=='*')
                 {
                     dat[top1-1]=dat[top1]*dat[top1-1];
                     top1--;
                 }
                 if (cal[top2]=='/')
                 {
                     dat[top1-1]=dat[top1-1]/dat[top1];
                     top1--;
                 }
                 top2--;
            }
            else
              break;

         }
         

       }


    }
    printf("%d",dat[0]);

    return 0;
}
