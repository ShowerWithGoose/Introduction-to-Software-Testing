#include <stdio.h>
struct line{
    int x0;
    int y0;
    int x2;
    int y2;
}l[110];
int k=0;
int mark=0;
int a[110][10]={0};
void search(int ,int ,int ,int);
int main()
{
    int num,max,b;
    scanf("%d",&num);//输入线段数目
    getchar();
    for(int i=0;i<num;i++){
         scanf("%d %d %d %d",&l[i].x0,&l[i].y0,&l[i].x2,&l[i].y2);//输入各段线段坐标
        getchar();
    }
    for(int i=0;i<num;i++){
        int x,y,m,n;
        x=l[i].x0;
        y=l[i].y0;
        m=l[i].x2;
        n=l[i].y2; 
        search(m,n,i,num); // @@ The variable 'k' is used inside 'search' to index array 'a', but 'k' is only incremented after 'search' returns. This means all recursive calls within one chain overwrite the same row 'a[k]', failing to count the length correctly or causing logic errors. Furthermore, 'search' does not reset 'a[k][0]' to 0 before starting a new chain, leading to accumulation errors if not handled carefully (though here it seems intended to accumulate, the indexing logic is flawed because 'k' doesn't advance during recursion).
        a[k][1]=x;
        a[k][2]=y;
        k++;
        
    }
    max=a[0][0];
    for(int i=1;i<k;i++){
        if(a[i][0]>max){
            max=a[i][0];
            b=i;
        }
    }
    printf("%d %d %d",max+1,a[b][1],a[b][2]);
    return 0;
}
search(int p,int q,int f,int up){
    for(int j=0;j<up;j++){
        //printf("i=%d,j=%d,m=%d,n=%d\n",f,j,p,q);
        if(j==f){
                continue;
            }
        if(p==l[j].x0&&q==l[j].y0){
                a[k][0]++;
                p=l[j].x2;
                q=l[j].y2;
                mark=1;
            }
    }
    if(mark==1){
        mark=0;
        search(p,q,f,up); // @@ The variable 'f' (the index of the starting segment of the current chain) is passed down recursively. However, the check 'if(j==f) continue;' prevents re-using the *starting* segment. It does NOT prevent re-using segments already visited in the current chain (other than the start). This can lead to infinite loops or incorrect counts if the line segments form a cycle or if the logic intends to traverse a simple path. More critically, since 'a[k][0]' is global and static for the current 'k', and 'k' doesn't change, this counts the depth. But without marking visited nodes, it might count incorrectly if branches exist (though problem says no 3+ segments share endpoint, so it's a line/cycle). The main issue is that 'f' stays constant, so only the very first segment is excluded from being matched as a "next" segment, allowing potential backtracking or cycles if not strictly increasing X.
    } else{
        return 0;
    }
}