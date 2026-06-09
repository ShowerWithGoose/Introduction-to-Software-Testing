#include <stdio.h>
#include <stdlib.h>

int main()
{
    char b[2000];
    int a[2000],i=0,j=0,k,x;
    char y;
    while(scanf("%c",&y)!='='){
        if(y>='0'&&y<='9'){
                int s=0;
                while(y>='0'&&y<='9'){
                    s*=10;
                    s+=y-'0';
                    scanf("%c",&y);

            }
            //printf("%d\n",s);
            a[i]=s;
            i++;
        }
        if(y=='+'||y=='-'||y=='*'||y=='/'){
            b[j]=y;
            j++;
        }
        if(y=='=')
            break;
    }
    for(k=0;k<j;k++){
        if(b[k]=='*'){
            a[k]=a[k]*a[k+1];
            for(x=k;x<i-2;x++)
                a[x+1]=a[x+2];
            for(x=k;x<j-1;x++)
                b[x]=b[x+1];
                i--;
                j--;
                k--;
        }
        if(b[k]=='/'){
            a[k]=a[k]/a[k+1];
            for(x=k;x<i-2;x++)
                a[x+1]=a[x+2];
            for(x=k;x<j-1;x++)
                b[x]=b[x+1];
                i--;
                j--;
                k--;
        }
        //for(int o = 0;o<j;o++)printf("%c",b[o]);
        //printf("%d\n",k);
        //printf("%d\n",a[k]);
    }
    //for(int o = 0;o<i;o++)printf("%d",a[o]);
    int m=a[0];
    for(k=0;k<j;k++){
        if(b[k]=='+')
            m+=a[k+1];
        else
            m-=a[k+1];
    }
    printf("%d",m);
    return 0;
}

