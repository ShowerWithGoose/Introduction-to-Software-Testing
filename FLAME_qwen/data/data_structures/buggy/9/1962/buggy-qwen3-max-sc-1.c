#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line{
    int datax;
    int datay;
};
int main(){
    struct line a[100],b[100],c[100];//a为前端点，b为后端点，c为连续线段的后端点； 
    int i,n,itemx,itemy,sum[100],data,line;
    int j,k;
    scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d%d%d%d",&a[i].datax,&a[i].datay,&b[i].datax,&b[i].datay);

for(i=0;i<n;i++){
    if(a[i].datax>=b[i].datax){
        itemx=a[i].datax;
        a[i].datax=b[i].datax;
        b[i].datax=itemx;
        itemy=a[i].datay;
        a[i].datay=b[i].datay;
        b[i].datay=itemy;
    }
}//将一组线段中横坐标小的坐标放在a组中； 
//for(i=0;i<n;i++)
//printf("%d %d %d %d\n",a[i].datax,a[i].datay,b[i].datax,b[i].datay);调整顺序后值未出现问题 
    for(j=0;j<n;j++){
        sum[j]=1;
        c[j].datax=b[j].datax;
        c[j].datay=b[j].datay;
    
        for(k=0;k<n;k++){
            if(c[j].datax==a[k].datax&&c[j].datay==a[k].datay){
                sum[j]+=1;
                c[j].datax=b[k].datax;c[j].datay=b[k].datay;//连接点变为连接线断的厚点 
                k=0; // @@ [Resetting k to 0 inside the loop causes reprocessing of already checked segments and may lead to infinite loops or incorrect counts because it interferes with the natural loop progression. Additionally, it doesn't mark used segments as consumed, so the same segment might be reused multiple times.]
            }//在找到下一个可连接点后，将数据清空，再次从第一位数开始判断,如果已经用过的那么不会再连接，但是防备前者有可以链接的线段 
        }
    }
    data=sum[0];
    for(i=0;i<n;i++){
        if(sum[i]>=data){
            data=sum[i];
            line=i;
        }
    }
    printf("%d %d %d",data,a[line].datax,a[line].datay);
    return 0;
}