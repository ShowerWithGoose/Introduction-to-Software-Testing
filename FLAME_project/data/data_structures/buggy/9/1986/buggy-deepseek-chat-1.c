#include <stdio.h>
#include <stdlib.h>
struct Line{
    int x1;
    int y1;
    int x2;
    int y2;
    struct Line *link;
}line[101];
int cmp(const void* a, const void* b){
    return (*(struct Line*)a).x1-(*(struct Line*)b).x1;
}
int main(){
    int n=0,cnt=0,i=0,j=0,k=0,t[2][3]={0};
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    
    qsort(line,n,sizeof(struct Line),cmp);
    
    
    for(i=0;i<n;i++){
        t[1][0]=line[i].x1;
        t[1][1]=line[i].y1;
        t[1][2]=1;
        k=i;
        for(j=i+1;j<n;j++){
            if(line[k].x2==line[j].x1&&line[k].y2==line[j].y1){
                k=j;
                t[1][2]++;
                if(t[1][2]>t[0][2]){
                t[0][0]=t[1][0];
                t[0][1]=t[1][1];
                t[0][2]=t[1][2];
                printf("%d %d\n",i,t[0][2]); // @@ This debug print statement should be removed; it outputs intermediate results that interfere with the final output format.
                }
            }else if(line[k].x2<line[j].x1){
                break;
            }
        }
    }
    printf("%d %d %d",t[0][2],t[0][0],t[0][1]); // @@ This line prints the final result, but due to the debug print above, the output contains extra lines, causing a mismatch with the expected output format.

    return 0;
}