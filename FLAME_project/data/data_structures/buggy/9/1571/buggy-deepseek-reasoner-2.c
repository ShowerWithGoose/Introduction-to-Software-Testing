#include <stdio.h>
#define maxn 1005
struct line{
    int x1,y1,x2,y2;
    int s1,s2,sum;
}a[maxn];
int i,j;
int res=0,resx,resy;
int jud[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d %d %d",&a[i].x1 ,&a[i].y1 ,&a[i].x2 ,&a[i].y2 );
        a[i].sum =1;//一条线段
        a[i].s1=a[i].x1 ;
        a[i].s2=a[i].s2 ; // @@ 错误：这里应该赋值为 a[i].y1，却赋给了自身（未初始化），导致后续起始点y坐标错误
    }
    while(j<n){
        j++;
        if(jud[j]!=0) continue;//表明线段已经合并过，跳过
        
        for(i=j+1;i<=n;i++){
            if(jud[i]!=0) continue;//不要忘记这里也要判断 
            if(a[i].x1 ==a[j].x2 &&a[i].y1 ==a[j].y2 ){
                n++;
                a[n].s1 =a[j].x1 ;
                a[n].s2 =a[j].y1 ;
                a[n].x1 =a[j].x1 ;
                a[n].y1 =a[j].y1 ;
                a[n].x2 =a[i].x2 ;
                a[n].y2 =a[i].y2 ;
                a[n].sum=a[i].sum + a[j].sum ;
                jud[i]=jud[j]=1; 
                break;//不会有三条线段共起点，所以直接用break减少运算 
            }
            else if(a[i].x2 ==a[j].x1 &&a[i].y2 ==a[j].y1 ){
                n++;
                a[n].s1=a[i].x1 ;
                a[n].s1=a[i].y1 ; // @@ 错误：这里应改为 a[n].s2 = a[i].y1，错误地将y坐标赋值给了s1，s2未被正确赋值
                a[n].x1 =a[i].x1 ;
                a[n].y1 =a[i].y1 ;
                a[n].x2 =a[j].x2 ;
                a[n].y2 =a[j].y2 ;
                a[n].sum =a[i].sum +a[j].sum ;
                jud[i]=jud[j]=1;
                
                break; 
            }
        } 
    }
    for(i=1;i<=n;i++){
        if(a[i].sum >res){
            res=a[i].sum ;
            resx=a[i].s1;
            resy=a[i].s2 ; 
        }
    } 
    printf("%d %d %d\n",res,resx,resy);
    
    return 0;
}