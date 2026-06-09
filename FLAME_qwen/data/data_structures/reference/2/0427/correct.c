#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{

   char a[1000];
   gets(a);
   int i,j;
   for(i=j=0;a[i]!='\0';i++){
    if(a[i]!=' '){
        a[j++]=a[i];
    }
   }
   a[j]='\0';
   int b[1000]={-1};
   int d[1000]={0};
   int k=1;
   for(i=0;a[i]!='\0';i++){
    if(a[i]<'0'||a[i]>'9')
        b[k++]=i;
    else
        d[i]=a[i]-'0';
   }
   int c[1000]={0};
   for(j=0;j<k-1;j++){
        for(int n=1;n<(b[j+1]-b[j]);n++){
            c[j]+=(d[b[j+1]-n])*pow(10,n-1);
        }
   }
   for(j=1;j<k-1;j++){
        if(a[b[j]]=='*'){
            c[j]=c[j]*c[j-1];
        }
        if(a[b[j]]=='/'){
            c[j]=c[j-1]/c[j];
        }
   }
    for(j=k-2;j>0;j--){
        if(a[b[j]]=='/'||a[b[j]]=='*'){
            c[j-1]=c[j];
        }
    }
   int x=c[0];
   for(j=1;j<k-1;j++){
        if(a[b[j]]=='+'){
            x+=c[j];
        }
        if(a[b[j]]=='-'){
            x-=c[j];
        }
   }
   printf("%d",x);
   return 0;
}



