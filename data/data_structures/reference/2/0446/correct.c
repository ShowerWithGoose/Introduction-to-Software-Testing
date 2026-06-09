#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[1000],c[1000]={0},g[1000];
    int b=0,h=0,m[1000]={0},k=0,f[1000],j=0,sum=0,i;
    gets(a);

     for(i=0;i<=strlen(a);i++){
            if(a[i]<='9'&&a[i]>='0'){
                b=b*10+a[i]-'0';
            }
            if(a[i]=='-'||a[i]=='+'||a[i]=='*'||a[i]=='/'){
                m[k]=b;
                k++;
                b=0;
                c[h]=a[i];
                h++;
            }
            if(a[i]=='='){
                c[h]=a[i];
                m[k]=b;
            k++;
                break;
            }

     }

        for(i=0;i<=h;i++){
            if(c[i]=='*'){
                m[i+1]=m[i]*m[i+1];
            }
            if(c[i]=='/'){
                m[i+1]=m[i]/m[i+1];
            }
            if(c[i]=='+'||c[i]=='-'||c[i]=='='){
                g[j]=c[i];
                f[j]=m[i];
                j++;
            }

        }
        sum=f[0];
        for(i=0;i<j;i++){
            if(g[i]=='+'){
                sum=sum+f[i+1];
            }
            if(g[i]=='-'){
                sum=sum-f[i+1];
            }
            if(g[i]=='='){
                printf("%d",sum);
            }
        }


}

