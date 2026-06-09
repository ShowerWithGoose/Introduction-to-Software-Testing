#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line{
    int x1;
    int y1;//start
    int x2;
    int y2;//end
    int num;//含线段数 
}list[120]; 
int s=0;//现有线段总数 

void renew(int a, int b, int c, int d, struct line list[]){
    int sign=0;//重复次数
    int i;
    int s1, s2;//记录i位置 
    for(i=0;i<s;i++){
        if(list[i].x1==c&&list[i].y1==d){
            sign++;
            s1=i;//应更新i起点 
        }
        if(list[i].x2==a&&list[i].y2==b){
            sign+=2;
            s2=i;//应更新i终点 
        }
    }//sign判断p可更新端点数 
    
    
    switch(sign){
        case 0:
            list[i].x1=a;
            list[i].y1=b;
            list[i].x2=c;
            list[i].y2=d;
            list[i].num=1;
            s++;
            break;//无法合并 
        case 1:
            list[s1].x1=a;
            list[s1].y1=b;
            list[s1].num++;
            break;//更新起点 
        case 2:
            list[s2].x2=c;
            list[s2].y2=d;
            list[s2].num++;
            break;//更新终点 
        case 3:
            list[s1].x1=list[s2].x1;
            list[s1].y1=list[s2].y1;
            list[s1].num+=2;
            
            list[s2].x1=list[i-1].x1;
            list[s2].y1=list[i-1].y1;
            list[s2].x2=list[i-1].x2;
            list[s2].y2=list[i-1].y2;
            list[s2].num=list[i-1].num;
            s--;
            //起点与终点均需要更新 
            //删除s2，补充s1 
            break;
    }
}

int main(){
    int sum;
    scanf("%d", &sum);
    
    int a,b,c,d;
    int i;
    for(i=0;i<sum;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        
        renew(a,b,c,d,list);//更新list 
    }
    
    
    int result=0;//最多线段数 
    int set;//最多线段的位置
    
     
    for(i=0;i<s;i++){
        if(list[i].num>result){
            result=list[i].num;
            set=i;
        }
    }
    printf("%d %d %d\n", result, list[set].x1, list[set].y1); // @@ [The output should be the number of segments in the continuous line, which is 'result', but according to the problem and reference program, 'result' already counts the number of segments correctly. However, the real issue is in the 'renew' function logic, particularly in case 3 where merging two chains is handled incorrectly by copying from 'list[i-1]' which may not be valid after deletions or during iteration. Also, the algorithm does not properly handle chaining in all directions because it only checks immediate connections without building a graph or using DP like the reference. The core error is that the merging logic in 'case 3' uses 'i-1' which is undefined behavior since 'i' is equal to 's' after the loop, leading to reading garbage data and incorrect chain lengths.]
    //输出 
    
    return 0;
}