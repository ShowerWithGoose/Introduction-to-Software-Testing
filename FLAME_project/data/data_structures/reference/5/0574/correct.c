#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct xiang
{
    int an;
    int cs;
};
struct xiang x1[50000],x2[50000],answer[50000];
int main()
{
    char dxs1[5000],dxs2[5000];
    int i,j,k,m,l,sz,n1,n2,n3,hold,flag;
    gets(dxs1);
    l=strlen(dxs1);
    dxs1[l]=' ';
    for(i=0,j=0,sz=0,k=0,m=0,flag=1;i<=l;i++){
        if(dxs1[i]>='0'&&dxs1[i]<='9'){
            sz=sz*10+(dxs1[i]-'0');
        }
        else if(dxs1[i]!='-'){
            if(k==m){
                x1[k].an=sz*flag;
                sz=0;
                k++;
                flag=1;
            }
            else if(k==m+1){
                x1[m].cs=sz;
                sz=0;
                m++;
            }
        }
        else if(dxs1[i]=='-'){
            flag=-1;
        }
    }
    n1=m;
    gets(dxs2);
    l=strlen(dxs2);
    dxs2[l]=' ';
    for(i=0,j=0,sz=0,k=0,m=0,flag=1;i<=l;i++){
        if(dxs2[i]>='0'&&dxs2[i]<='9'){
            sz=sz*10+(dxs2[i]-'0');
        }
        else if(dxs2[i]!='-'){
            if(k==m){
                x2[k].an=sz*flag;
                sz=0;
                k++;
                flag=1;
            }
            else if(k==m+1){
                x2[m].cs=sz;
                sz=0;
                m++;
            }
        }
        else if(dxs2[i]=='-'){
            flag=-1;
        }

    }
    n2=m;
    /*for(i=0;i<=m;i++){
        printf("%d %d\n",x2[i].an,x2[i].cs);
    }*/
    for(i=0,k=0;i<=n1;i++){
        for(j=0;j<=n2;j++){
            answer[k].an=x1[i].an*x2[j].an;
            answer[k].cs=x1[i].cs+x2[j].cs;
            k++;
        }
    }

    n3=k;
    /*for(i=0;i<n3;i++){
        printf("%d %d ",answer[i].an,answer[i].cs);
    }
    printf("\n");*/
    for(i=0;i<n3;i++){
        for(j=i+1;j<n3;j++){
            if(answer[i].cs<answer[j].cs){
                hold=answer[i].cs;
                answer[i].cs=answer[j].cs;
                answer[j].cs=hold;
                hold=answer[i].an;
                answer[i].an=answer[j].an;
                answer[j].an=hold;
            }
        }
    }
    /*for(i=0;i<n3;i++){
        if(answer[i].an==0){
            continue;
        }
        else printf("%d %d ",answer[i].an,answer[i].cs);
    }printf("\n");*/
    for(i=1;i<n3;i++){
        if(answer[i].cs==answer[i-1].cs){//printf("%d ",answer[i-1].an);
            answer[i-1].an=answer[i-1].an+answer[i].an;//printf("%d\n",answer[i].an);
            for(j=i;j<n3-1;j++){
                answer[j].cs=answer[j+1].cs;
                answer[j].an=answer[j+1].an;
            }
            n3--;
            i--;
        }
    }
    for(i=0;i<n3;i++){
        if(answer[i].an==0){
            continue;
        }
        else printf("%d %d ",answer[i].an,answer[i].cs);
    }
    return 0;
}

