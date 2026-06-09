#include<stdio.h>
#include<math.h>
int main(){
int a[105],b[100],c[100];
int i=0,m=0,n=0,p=0;
while(scanf("%d",&a[i])!=EOF)
    i++;
i=0;
while(a[i]!=-1){
    if(a[i]==1){
        m++;
        b[n]=a[i+1];
        i+=2;
        n++;
    }
    else if(a[i]==0){
        if(m==0){
            c[p]=6666;
            p++;
        }
        else{
            c[p]=b[n-1];
            m--;
            p++;
            n--;
        }
        i++;
    }
}
for(i=0;i<p;i++){
    if(c[i]==6666)
        printf("error ");
    else
        printf("%d ",c[i]);
}
return 0;
}

