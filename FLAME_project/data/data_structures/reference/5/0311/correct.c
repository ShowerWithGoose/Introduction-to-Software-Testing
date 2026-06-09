#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct f{
    int a,n;
};
int main(){
    struct f a[100],b[100],x[1000];
    int i,j,cota=0,cotb=0;
    char aa[1000],bb[1000];
    gets(aa);gets(bb);
    int la=strlen(aa),lb=strlen(bb),tmp,k;
    for(i=0;i<100;i++){
        a[i].a=0;a[i].n=0;b[i].a=0;b[i].n=0;
    }
    for(i=0,k=1,tmp=1;i<=la;i++){
        if(aa[i]==' '||aa[i]=='\0'){
            int cot=0;
            if(tmp==1){
                for(j=i-1;j>=0&&aa[j]!=' ';j--){
                    a[k].a=a[k].a+(aa[j]-'0')*pow(10,cot);
                    cot++;
                }
                tmp=2;
            }
            else if(tmp==2){
                for(j=i-1;j>=0&&aa[j]!=' ';j--){
                    a[k].n=a[k].n+(aa[j]-'0')*pow(10,cot);
                    cot++;
                }
                k++;
                tmp=1;
            }
        }
    }
    cota=k;
    for(i=0,k=1,tmp=1;i<=lb;i++){
        if(bb[i]==' '||bb[i]=='\0'){
            int cot=0;
            if(tmp==1){
                for(j=i-1;j>=0&&bb[j]!=' ';j--){
                    b[k].a=b[k].a+(bb[j]-'0')*pow(10,cot);
                    cot++;
                }
                tmp=2;
            }
            else if(tmp==2){
                for(j=i-1;j>=0&&bb[j]!=' ';j--){
                    b[k].n=b[k].n+(bb[j]-'0')*pow(10,cot);
                    cot++;
                }
                k++;
                tmp=1;
            }
        }
    }
    cotb=k;
    for(i=1,k=1;i<=cota;i++){
        for(j=1;j<=cotb;j++){
            x[k].a=a[i].a*b[j].a;
            x[k].n=a[i].n+b[j].n;
            k++;
        }
    }
    k--;
    int cot=k;
    for(i=1;i<k;i++){
        for(j=i+1;j<=k;j++){
            if(x[i].n==x[j].n){
                int m;
                x[i].a+=x[j].a;
                for(m=j;m<k;m++){
                    x[m]=x[m+1];
                }
                k--;
                j--;
            }
        }
    }
    for(i=1;i<=k;i++){
        if(x[i].a==0){
            for(j=i;j<k;j++)
                x[j]=x[j+1];
            i--;
            k--;
        }
    }
    struct f t;
    for(i=1;i<k;i++){
        for(j=i+1;j<=k;j++){
            if(x[i].n<x[j].n){
                t=x[i];
                x[i]=x[j];
                x[j]=t;
            }
        }
    }
    for(i=1;i<=k;i++)
        printf("%d %d ",x[i].a,x[i].n);
    return 0;
}

