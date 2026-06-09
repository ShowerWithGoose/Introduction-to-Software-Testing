#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void bubble(int a[],int n){
    int i,j,hold,flag;
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-1-i;j++){
            if(a[j]<a[j+1]){
                hold=a[j];
                a[j]=a[j+1];
                a[j+1]=hold;
                flag=1;
            }
        }if(flag==0)break;
    }
}
int main()
{
    int aa[105],nn[105],i=0,a,n,c;
    int fa[105],fn[105];
    char ch;

    do{
        scanf("%d%d%c",&aa[i],&nn[i],&ch);
        i++;
    }while(ch!='\n');
    int k=0,kk=0;
    do{
        scanf("%d%d%c",&a,&n,&ch);
        for(int j=0;j<i;j++){
            fa[k++]=a*aa[j];
            fn[kk++]=n+nn[j];
        }
    }while(ch!='\n');


    int j,hold,flag;
    for(i=0;i<k-1;i++){
        flag=0;
        for(j=0;j<k-1-i;j++){
            if(fn[j]<fn[j+1]){
                hold=fn[j];
                fn[j]=fn[j+1];
                fn[j+1]=hold;
                hold=fa[j];
                fa[j]=fa[j+1];
                fa[j+1]=hold;
                flag=1;
            }
        }if(flag==0)break;
    }

    for(i=0;i<k;i++){
        if(fa[i]==0)continue;
        for(j=i+1;j<k;j++){
            if(fa[j]==0)continue;
            if(fn[i]==fn[j]){
                fa[i]+=fa[j];
                fa[j]=0;
            }
        }
    }
    for(i=0;i<k;i++){
        if(fa[i]!=0)
        printf("%d %d ",fa[i],fn[i]);
    }
}

