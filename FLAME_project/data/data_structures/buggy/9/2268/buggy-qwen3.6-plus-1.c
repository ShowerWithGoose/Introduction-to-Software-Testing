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
        temp=0; // @@ The variable 'temp' is reset to 0 at the end of every outer loop iteration. However, 'temp' is initialized to 1 before the loops and incremented when a connection is found. Resetting it to 0 means that for the next segment, the count starts from 0 instead of 1 (the segment itself). This leads to incorrect counting. It should be reset to 1 to represent the current segment being the start of a new potential chain, or the logic for initializing temp needs to be adjusted relative to how ans is calculated. More critically, because temp is reset to 0, and ans is updated based on temp, the final printf adds 1 to ans. If a chain of 2 segments is found, temp becomes 2 (1 initial + 1 increment). ans becomes 2. Then temp resets to 0. The next iteration starts with temp 0. If no further connections, ans remains 2. Output is ans+1 = 3. This explains the wrong answer. The initialization of temp should be inside the outer loop before the inner loop, set to 1.
    }
    printf("%d %d %d",ans+1,spot[pos].x1,spot[pos].y1); // @@ Because 'temp' was incorrectly managed (starting at 1, incrementing, but then 'ans' stores the max 'temp' value which includes the initial 1), adding 1 here double-counts the starting segment or misinterprets the count. If temp correctly counted the number of segments in the chain (starting at 1), ans would hold the correct count. Adding 1 makes it wrong. If the intention was that temp counts *additional* segments, then temp should start at 0. Given the reset error above, this line is also logically flawed in conjunction with the previous error. The primary fix is resetting temp to 1 inside the loop and removing the +1 here, OR keeping temp reset to 0 and not adding 1 if ans tracks total segments. The most standard fix is: initialize temp=1 inside the loop, update ans=max(ans, temp), and print ans.
    return 0;
}
int cmp(const void *p1,const void *p2){
    struct data *a=(struct data*)p1;
    struct data *b=(struct data*)p2;
    if(a->x1!=b->x1) return a->x1-b->x1;
    else return a->y1-b->y1;
}