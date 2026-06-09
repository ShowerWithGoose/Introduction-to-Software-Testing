#include<stdio.h>
#include<ctype.h>
#include<assert.h>
int main()
{
   char a[1000],b[1000],c[1000],d[1000];
   int e[1000],f[1000];
   int i,j=0,n=0,m=0,k=0,h=0;
   char l;
   gets(a);
   for(i=0;a[i]!='\0';i++)
   {
      while(isdigit(a[i]))
      {
          m++;
          b[m]=a[i];
          i++;
      }
      while(isdigit(a[i])==0)
      {
          if(a[i]==' ')
          {
              break;
          }
          c[n]=a[i];
          n++;
          k=0;
          for(j=1;j<=m;j++)
          {
              k=10*k+b[j]-'0';
          }
          e[h]=k;
          h++;
          m=0;
          break;
      }
   }
   c[n]='\0';
   for(i=0;i<n;i++)
   {
       if(c[i]=='*')
       {
           e[i+1]=e[i]*e[i+1];
       }
       else if(c[i]=='/')
       {
           e[i+1]=e[i]/e[i+1];
       }

   }
   for(i=0;i<n;i++)
   {
       if(c[i]=='-'||c[i]=='+')
       {
           d[j]=c[i];
           f[j]=e[i];
           j++;
       }

   }
   d[j]='\0';
   f[j]=e[h-1];
   for(i=0;i<=j;i++)
   {
       if(d[i]=='-')
        f[i+1]=f[i]-f[i+1];
       else if(d[i]=='+')
        f[i+1]=f[i]+f[i+1];
   }
   printf("%d",f[j]);
return 0;
}

