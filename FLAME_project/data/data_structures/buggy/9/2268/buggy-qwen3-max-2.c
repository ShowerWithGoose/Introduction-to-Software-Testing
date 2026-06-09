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
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&spot[i].x1,&spot[i].y1,&spot[i].x2,&spot[i].y2);
    }
    qsort(spot,n,sizeof(struct data),cmp);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;j++){
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
        temp=0; // @@ [Resetting temp to 0 after each outer loop iteration causes the count for the current chain to be lost before it's fully built. It should be reset to 1 (or appropriate initial value) at the start of each new chain attempt, not after processing all j for a given i. Also, the logic of modifying segments in-place and zeroing them breaks further connections.]
    }
    printf("%d %d %d",ans+1,spot[pos].x1,spot[pos].y1); // @@ [The answer is overcounted by 1 because 'ans' already includes the count of connected segments starting from 1, but then 1 is added again. For 2 connected segments, temp becomes 2, ans becomes 2, then output becomes 3. Should output 'ans', not 'ans+1'.]
    return 0;
}
int cmp(const void *p1,const void *p2){
    struct data *a=(struct data*)p1;
    struct data *b=(struct data*)p2;
    if(a->x1!=b->x1) return a->x1-b->x1;
    else return a->y1-b->y1;
}