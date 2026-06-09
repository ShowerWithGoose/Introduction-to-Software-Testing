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
            list[i].x1=a; // @@ Error: Variable i is out of bounds after the for loop; i equals s, but list has size 120, so this writes beyond the last valid element. Should use list[s] instead.
            list[i].y1=b; // @@ Same error: i is out of bounds.
            list[i].x2=c; // @@ Same error.
            list[i].y2=d; // @@ Same error.
            list[i].num=1; // @@ Same error.
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
            
            list[s2].x1=list[i-1].x1; // @@ Error: When sign==3, i equals s after the loop, so list[i-1] refers to list[s-1], which is the last valid element. However, this logic incorrectly uses the last element to overwrite s2, but the intention is to remove s2 by shifting elements. The code does not properly handle the removal and may cause data loss or incorrect merging.
            list[s2].y1=list[i-1].y1; // @@ Same error.
            list[s2].x2=list[i-1].x2; // @@ Same error.
            list[s2].y2=list[i-1].y2; // @@ Same error.
            list[s2].num=list[i-1].num; // @@ Same error.
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
    printf("%d %d %d\n", result, list[set].x1, list[set].y1);
    //输出 
    
    return 0;
}