#include<stdio.h>
#include<stdlib.h>
int cmp(const void *p,const void *q);
typedef struct link{
    int xi,zhi;
    int sign;
    struct link *next;
}link;

int main(){
    link *head1 = (link*)malloc(sizeof(link)),*head2 = (link*)malloc(sizeof(link));    
    link *ahead = NULL,*tail = NULL;
    link l[10000],l2[10000];
    int il = 0,lock = 0;
    for(il = 0;il < 10000;il++) l[il].sign = 0,l2[il].xi = 0;
    il = 0;
    char lock1 = 0,lock2 = 0,c = 0;
    int i,j,k = 0;
    ahead = tail = head1;

    while(scanf("%d%d",&tail->xi,&tail->zhi)){

        if((c = getchar()) == '\n'){
            tail->next = NULL;
            break;
        }
        ahead = (link*)malloc(sizeof(link));
        tail->next = ahead;
        tail = ahead;
    }
    
    ahead = tail = head2;
    while(scanf("%d%d",&tail->xi,&tail->zhi)){
        
        if((c = getchar()) == '\n'){
            tail->next = NULL;
            break;
        }
        
        
        ahead = (link*)malloc(sizeof(link));
        tail->next = ahead;
        tail = ahead;
        
    }
    ahead = head1;
    tail = head2;




    while(lock1 == 0){
        if(ahead->next == NULL){
            lock1++;
        }
        while(lock2 == 0){
            if(tail->next == NULL){
                lock2++;
            }
            //ahead*tail
            l[il].xi = (ahead->xi)*(tail->xi);
            l[il++].zhi = (ahead->zhi)+(tail->zhi);
            //printf("ahead->xi:%d ->zhi:%d\n",ahead->xi,ahead->zhi);
            //printf("tail->xi:%d ->zhi:%d\n",tail->xi,tail->zhi);
            //printf("l[%d].xi:%d .zhi:%d\n",il-1,l[il-1].xi,l[il-1].zhi);
            tail = tail->next;        
        }
        ahead = ahead->next;
        tail = head2;
        lock2 = 0;
    }

    /*for(i = 0;i < il;i++){
        printf("l[%d].xi:%d .zhi:%d\n",i,l[i].xi,l[i].zhi);
    }

return 0;*/


    for(i = 0;i < il;i++){
        if(l[i].sign == 0){
            l2[k].xi += l[i].xi;
            l2[k++].zhi = l[i].zhi;

            //printf("%d:l2xi:%d l2zhi:%d\n",k-1,l2[k-1].xi,l2[k-1].zhi);


            l[i].sign = 1;
            for(j = 0;j < il;j++){
                if(l[j].sign == 0 && l[j].zhi == l[i].zhi){
                    l2[k-1].xi += l[j].xi;
                    l[j].sign = 1;
                }
            }
            //printf("%d:l2xi:%d l2zhi:%d\n",k-1,l2[k-1].xi,l2[k-1].zhi);
        }
    }

    qsort(l2,k,sizeof(link),cmp);
    for(i = 0;i < k;i++){
        printf("%d %d ",l2[i].xi,l2[i].zhi);
    }

    printf("\n");
    return 0;
}

int cmp(const void *p,const void *q){
    link *m = (link*)p,*n = (link*)q;
    return (m->zhi > n->zhi)?-1:1;
}


