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
        search(m,n,i,num);
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
        search(p,q,f,up);
    } else{
        return 0;
    }
} // @@ [The function 'search' is not properly tracking the chain of connected segments because it uses a global variable 'k' which is shared across all starting segments. Each call to 'search' from a different starting segment should maintain its own count and path, but instead all results are written to a[k] where 'k' is incremented in main after each search, causing mismatched counts and coordinates. Additionally, the recursive call does not pass an updated index for the result array, so multiple chains overwrite or interfere with each other's data. Also, the base case doesn't reset 'mark' correctly in all paths, and the recursion may miss longer chains due to early termination.]