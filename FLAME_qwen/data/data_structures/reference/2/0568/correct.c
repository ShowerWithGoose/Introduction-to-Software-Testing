#include <stdio.h>
#include <stdlib.h>
int main ()
{char s[205],b[205],second[205];
int a[205]={0},first[205]={0};
gets(s);
int i,j,k,m,p,le=strlen(s);
for(i=0;i<le;i++){

    while(s[i]==' '){
        for(j=i;j<le;j++){
            s[j]=s[j+1];
        }
        le--;
    }
}
//删去计算式中的空格符。
k=1;
for(i=0;i<le;i++){
    if(s[i]>='0'&&s[i]<='9'){
        for(j=i;s[j]>='0'&&s[j]<='9';j++){
            a[k]=(s[j]-'0')+a[k]*10;
        }
        i=j;
        b[k]=s[j];
        k++;
    }
}
//录入数字。

for(m=1;m<k;m++){
    if(b[m]=='*'){
       a[m]=a[m]*a[m+1];
        b[m]=b[m+1];
        for(p=m+1;p<k;p++){
            a[p]=a[p+1];
            b[p]=b[p+1];

        }k--;
        m--;
    }

    else if(b[m]=='/'){
       a[m]=a[m]/a[m+1];
        b[m]=b[m+1];
        for(p=m+1;p<k-1;p++){
            a[p]=a[p+1];
            b[p]=b[p+1];

        }k--;
        m--;
    }

}

for(m=1;m<k;m++){
    if(b[m]=='+'){
       a[m]=a[m]+a[m+1];
        b[m]=b[m+1];
        for(p=m+1;p<k;p++){
            a[p]=a[p+1];
            b[p]=b[p+1];

        }k--;
        m--;
    }

    else if(b[m]=='-'){
       a[m]=a[m]-a[m+1];
        b[m]=b[m+1];
        for(p=m+1;p<k-1;p++){
            a[p]=a[p+1];
            b[p]=b[p+1];

        }k--;
        m--;
    }

}
printf("%d",a[1]);
return 0;}

