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
                a[k][0]++; // @@ [Error: This increments the count for the current starting segment, but the search function is called recursively and should track the count for the specific chain being built. Since a[k][0] is shared across all recursive calls for the same starting segment, it may be incremented multiple times incorrectly if the search backtracks or finds multiple paths, but more critically, the logic does not properly reset or handle the count for each starting point. Additionally, the function does not return the count, so the final value in a[k][0] may not reflect the true chain length.]
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
}