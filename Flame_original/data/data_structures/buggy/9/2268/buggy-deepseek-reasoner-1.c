#include<stdio.h>
#include<stdlib.h>
struct data{
    int x1;
    int y1;
    int x2;
    int y2;
}spot[1024];
int cmp(const void *p1,const void *p2);
int main(){
    int n;
    scanf("%d",&n);
    int ans=1,temp=1;
    int ansx=0,ansy=0;
    int pos=0; 
    for(int i=0;i<n;++i){ // @@ Declaration of loop variable inside for is not allowed in C89; causes compilation error.
        for(int j=0;j<n;j++){ // @@ Declaration of loop variable inside for is not allowed in C89; causes compilation error.
            if(j!=i&&((spot[j].x1!=0)||(spot[j].y1!=0)||(spot[j].x2!=0)||(spot[j].y2!=0))){
                if((spot[j].x1==spot[i].x2)&&(spot[j].y1==spot[i].y2)){
                                            spot[i].x2=spot[j].x2;
                                            spot[i].y2=spot[j].y2;
                                            temp++;
                                            if(ans<=temp){
                                            ans=temp;
                                            pos=i;
                                            }
                                            spot[j].x1=0;
                                            spot[j].y1=0;
                                            spot[j].x2=0;
                                            spot[j].y2=0;
                                        }
            }
        }
        temp=0;
    }
    printf("%d %d %d",ans+1,spot[pos].x1,spot[pos].y1);
    return 0;
}
int cmp(const void *p1,const void *p2){
    struct data *a=(struct data*)p1;
    struct data *b=(struct data*)p2;
    if(a->x1!=b->x1) return a->x1-b->x1;
    else return a->y1-b->y1;
}