#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
     //part1: make a postfix
     char ori[400],realf[100],n[10],f[100],zhan[100];
     int i,j,k = 0,p,o = 0,top=-1,top1=-1,y;
     int num1[100],num2[100],cal[100],zh;
     gets(ori);
     for(i = 0,j = 0;ori[i]!='\0';i++)
     {
         if(ori[i]!=' ')
         {
             ori[j] = ori[i];
             j++;
         }
     }
     ori[j]='\0';
 //    printf("%s\n\n",ori);
     while(ori[k]!='\0')
     {
         if(isdigit(ori[k])==0)
         {
             f[o] = ori[k];
             k++;
             o++;
             continue;
         }
         if(isdigit(ori[k])>0)
         {
             p = 0;
             for(int q = k;isdigit(ori[q])>0;p++,q++)
             {
                 n[p]=ori[q];
             }
             n[p] = '\0';
             num1[o] = atof(n);
             f[o]='a';
             o++;
             k+=p;
         }
     }
     k = 0;
     for(i = 0;i<o-1;i++)
     {
         if(f[i]=='a')
         {
             num2[k] = num1[i];
             realf[k] = 'a';
   //          printf("%d ",num2[k]);
             k++;
         }
         else
         {
             if(f[i]=='+'||f[i]=='-'||f[i]=='*'||f[i]=='/')
             {
                 if(f[i]=='+'||f[i]=='-')
                 {
                     for(int u = top;u>-1&&zhan[u]!='(';u--)
                     {
                         if(zhan[u]=='*'||zhan[u]=='/'||zhan[u]=='-'||zhan[u]=='+')
                         {
                             realf[k] = zhan[u];
                     //        printf("%c ",realf[k]);
                             top--;
                             k++;
                         }
                     }
                 }
                 if(f[i]=='*')
                 {
                     for(int u = top;u>-1&&zhan[u]!='+'&&zhan[u]!='-'&&zhan[u]!='*'&&zhan[u]!='(';u--)
                     {
                         if(zhan[u]=='/')
                         {
                             realf[k] = zhan[u];
               //              printf("%c ",realf[k]);
                             top--;
                             k++;
                         }
                     }
                 }
                 if(f[i]=='/')
                 {
                     for(int u = top;u>-1&&zhan[u]!='+'&&zhan[u]!='-'&&zhan[u]!='/'&&zhan[u]!='(';u--)
                     {
                         if(zhan[u]=='*')
                         {
                             realf[k] = zhan[u];
                //             printf("%c ",realf[k]);
                             top--;
                             k++;
                         }
                     }
                 }
                 if(zhan[top]==f[i])
                 {
                     realf[k] = f[i];
   //                  printf("%c ",realf[k]);
                     k++;
                     continue;
                 }
                 top++;
                 zhan[top] = f[i];
             }

             if(f[i]=='(')
             {
                 top++;
                 zhan[top] = f[i];
             }

             if(f[i]==')')
             {
                 for(y = top;zhan[y]!='('&&y>-2;y--)
                {
                    realf[k] = zhan[y];
    //                printf("%c ",realf[k]);
                    top--;
                    k++;
                 }
                 top--;
             }
         }
     }
     for(;top>-1;top--)
     {
         realf[k] = zhan[top];
   //      printf("%c ",realf[k]);
         k++;
     }

 //    printf("\n");
//then we get the postfix,we can du the calculation right now.

    for(int w = 0;w<k;w++)
    {
        if(realf[w] == 'a')
        {
            top1++;
            cal[top1] = num2[w];
  //          printf("%d ------ number,and top1 is %d\n",cal[top1],top1);
        }
        else
        {
            if(realf[w]=='+')
            {
                zh = cal[top1-1]+cal[top1];
                top1--;
                cal[top1] = zh;
   //             printf("%d ------ + ,and top1 is %d\n",cal[top1],top1);
            }
            if(realf[w]=='-')
            {
                zh = cal[top1-1]-cal[top1];
                top1--;
                cal[top1] = zh;
    //            printf("%d ------ - ,and top1 is %d\n",cal[top1],top1);
            }
            if(realf[w]=='*')
            {
                zh = cal[top1-1]*cal[top1];
                top1--;
                cal[top1] = zh;
    //            printf("%d ------ * ,and top1 is %d\n",cal[top1],top1);
            }
            if(realf[w]=='/')
            {
                zh = cal[top1-1]/cal[top1];
                top1--;
                cal[top1] = zh;
   //             printf("%d ------ / ,and top1 is %d\n",cal[top1],top1);
            }
        }
    }

    printf("%d",cal[0]);





     return 0;
}

