#include<stdio.h>
int st[105],tp;

int main(){
    int k;scanf("%d",&k);
    while(k!=-1){
        if(k==1){
            scanf("%d",&k);
            st[++tp]=k;
            if(tp>100){printf("error "); --tp;}
        }else if(k==0){
            if(tp==0) printf("error ");
            else printf("%d ",st[tp--]);
        }
        scanf("%d",&k);
    }
    return 0;;
}
