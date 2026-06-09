#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
    char a[500]={};
int p(int wz,int w)
{
	int i;
  for (i=w;i>=wz+1;i--)
   if (a[i]>'0') return 1;
   return -1;	
}
int main()
{
    int z=0,l=0;
    int i,cd,pd,t,wz,zbj,ybj,cbj;
    scanf("%s",a);
    cd=strlen(a);
    pd=0;
    cbj=-1;
    zbj=-1;ybj=100;
    for (i=0;i<cd;i++)
        if (a[i]=='.') {pd=1;wz=i;}

    if (pd==0)
    {
        t=1;
        for (i=0;i<cd;i++)
        if ((a[i]-'0')>0) {zbj=i;break;}
        if (zbj==-1) printf("0");
        else {
       for (i=zbj;i<cd;i++)
       {
        z=z*10+a[i]-'0';
        t*=10;
       }
       l=z;
       printf("%d",z/(t/10));
       if (z!=0) {
       z=z-z/(t/10)*(t/10);
          t/=10;
       if (z%t>0) printf(".");
      while (z>0)
      {
          printf("%d",z/(t/10));
          z=z-z/(t/10)*(t/10);
          t/=10;
      }
      printf("e");
      if (l>10) printf("%d",cd-zbj-1);

      }
        }
    }
    else {t=1;
    for (i=0;i<wz;i++)
        if ((a[i]-'0')>0) {zbj=i;break;}
       for (i=zbj;i<wz;i++)
       {
        z=z*10+a[i]-'0';
        t*=10;
       }
       l=z;
       for (i=cd-1;i>wz;i--)
        if ((a[i]-'0')>0) {ybj=i;break;}
       if (zbj>=0&&ybj==100) {
        printf("%d",z/(t/10));
       z=z-z/(t/10)*(t/10);
          t/=10;
       if (z%t>0) printf(".");
      while (z>0)
      {
          printf("%d",z/(t/10));
          z=z-z/(t/10)*(t/10);
          t/=10;
      }
      printf("e");
      if (l>10) printf("%d",wz-zbj-1);

    }
      if (zbj==-1&&ybj==100) printf("0");
      if (zbj==-1&&ybj<100)
      {
          for (i=wz+1;i<=ybj;i++)
          if ((a[i]-'0')>0) {cbj=i;break;}
          printf("%c",a[cbj]);
          if (p(cbj,ybj)==1) printf(".");
          for (i=cbj+1;i<=ybj;i++)
            printf("%c",a[i]);
          printf("e-%d",cbj-wz);
      }
      if (zbj>-1&&ybj<100)
      {
          printf("%c.",a[zbj]);
          for (i=zbj+1;i<wz;i++)
            printf("%c",a[i]);
          for (i=wz+1;i<=ybj;i++)
            printf("%c",a[i]);
          printf("e%d",wz-zbj-1);
      }
    }
    return 0;
}

