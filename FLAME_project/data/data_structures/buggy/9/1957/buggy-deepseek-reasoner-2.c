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
    printf("%d %d %d",max+1,a[b][1],a[b][2]); // @@ b may be uninitialized if the loop never executes (e.g., k==1) or if max is never updated.
    return 0;
}
search(int p,int q,int f,int up){ // @@ missing return type; conflict with forward declaration 'void search(int,int,int,int)'
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
        search(p,q,f,up); // @@ after recursive call, there is no return statement; function is non-void leading to undefined behavior
    } else{
        return 0;
    }
}