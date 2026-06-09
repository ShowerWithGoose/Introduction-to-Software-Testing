#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[2000];
    int b[2000],i=0,j=0,k,x;
    char y;
    while(scanf("%c",&y)!='='){
        if(y>='0'&&y<='9'){
                int x=0;
                while(y>='0'&&y<='9'){
                    x*=10;
                    x+=y-'0';
                    scanf("%c",&y);

            }
            //printf("%d\n",s);
            b[i]=x;
            i++;
        }
        if(y=='+'||y=='-'||y=='*'||y=='/'){
            a[j]=y;
            j++;
        }
        if(y=='=')
            break;
    }
    for(k=0;k<j;k++){
        if(a[k]=='*'){
            b[k]=b[k]*b[k+1];
            for(x=k;x<i-2;x++)
                b[x+1]=b[x+2];
            for(x=k;x<j-1;x++)
                a[x]=a[x+1];
                i--;
                j--;
                k--;
        }
        if(a[k]=='/'){
            b[k]=b[k]/b[k+1];
            for(x=k;x<i-2;x++)
                b[x+1]=b[x+2];
            for(x=k;x<j-1;x++)
                a[x]=a[x+1];
                i--;
                j--;
                k--;
        }
        //for(int o = 0;o<j;o++)printf("%c",b[o]);
        //printf("%d\n",k);
        //printf("%d\n",a[k]);
    }
    //for(int o = 0;o<i;o++)printf("%d",a[o]);
    int result=b[0];
    for(k=0;k<j;k++){
        if(a[k]=='+')
            result+=b[k+1];
        else
            result-=b[k+1];
    }
    printf("%d",result);
    return 0;
}

