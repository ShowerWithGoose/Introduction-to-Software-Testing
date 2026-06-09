#include<stdio.h>
#include<string.h>
char a[10000];
char b[10000];
char f[10000];
int  s[10000];

int main()
{
    gets(a);
    int i=0;
    int j=0;
    int len=strlen(a);
    for(i=0; i<=len-1; i++)
    {
        if(a[i]!=' ') b[j++]=a[i];
    }
    b[j]='\0';
    len=strlen(b);
    int k=0;
    int lens=0;
    for(i=0,j=0,k=0; i<=len-1; i++)
    {
        int sum=0;
        if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/'||b[i]=='=')   f[j++]=b[i];
        else  if(b[i]<='9'&&b[i]>='0')
        {
            for(i; b[i]<='9'&&b[i]>='0'; i++)  sum=sum*10+(b[i]-'0');
            i=i-1;
            s[k++]=sum;
        }

    }


    f[j]='\0';
    int lenf=strlen(f);
    if(b[0]=='-'){
     s[0]=0-s[0];
     for(i=0;i<=lenf-2;i++){
      char h=f[i+1];
      f[i]=h;

     }
          lenf-=1;

    }

    lens = k;
    int ji=0;
    int he=0;
    int m=0,n=0;

    if(f[0]=='=') {
        printf("%d",s[0]);
        return 0;
    }
    for(i=0; i<=lenf-1; i++)
    {

        if(f[i]=='*'||f[i]=='/')
        {

            m=i;

            for(i; f[i]=='*'||f[i]=='/'; i++);

            n=i-1;

            ji=s[m];
            for(j=m; j<=n; j++)
            {

                if(f[j]=='*') ji=ji*s[j+1];
                else  ji=ji/s[j+1];
            }


            s[m]=ji;
            s[n+1]=ji;


            i=i-1;

        }






    }
    int gg=0;
    for(i=0; i<=lenf-1; i++)
        if(f[i]=='+'||f[i]=='-')
        {
         gg=s[i];
         break;
        }


     for(i=0;i<=lenf-1;i++){
        if(f[i]=='+') gg=gg+s[i+1];
        else if(f[i]=='-') gg=gg-s[i+1];
     }
    if(n-m+1==lenf-1&&(f[0]!='+')&&(f[0]!='-')) gg=s[0];

   printf("%d",gg);


 return 0 ;


}


