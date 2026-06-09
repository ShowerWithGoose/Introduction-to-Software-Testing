#include <stdio.h>
#include <stdlib.h>
struct factor
{
    int a;
    int x;
}n1[105],n2[105],n[5005];

int cmp(const void* pa,const void *pb){
    int res;
    struct factor* ppa=(struct factor*)pa;
    struct factor* ppb=(struct factor*)pb;
    res = ppa->x-ppb->x;
    if(res>0)
    return -1;
    else if(res<0)
    return 1;
    else
    return ppb->a-ppa->a;
}

int main(){
    int i=0;
    char sign;
    do{
        scanf("%d",&n1[i].a);
		scanf("%d",&n1[i].x);
		i++;
        scanf("%c",&sign);
    }while(sign==' ');
    int num1=i;
    i=0;
    do{
        scanf("%d",&n2[i].a);
		scanf("%d",&n2[i].x);
		i++;
        scanf("%c",&sign);
    }while(sign==' ');
    int num2=i;
    i=0;
    for(int k=0;k<num1;k++){
        for(int j=0;j<num2;j++){
            n[i].a=n1[k].a*n2[j].a;
            n[i].x=n1[k].x+n2[j].x;
            i++;
        }
    }
    int num=i;
    qsort(n,num,sizeof(n[0]),cmp);
    for(i=0;i<num;i++){
        if(n[i].x==n[i+1].x){
            n[i+1].a+=n[i].a;
        }
        else{
        	if(n[i].a)
            printf("%d %d ",n[i].a,n[i].x);
        }
    }
    if(n[i-1].a&&n[i-1].x==0)
    printf("%d %d ",n[i-1].a,n[i-1].x);
    return 0;
}



