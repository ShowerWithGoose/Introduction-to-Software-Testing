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
            list[i].x1=a; // @@ Error: After the loop, i equals s, but list[s] is uninitialized; this writes beyond the current valid entries. Should use list[s] instead.
            list[i].y1=b; // @@ Error: Same issue as above; should use list[s].
            list[i].x2=c; // @@ Error: Same issue as above; should use list[s].
            list[i].y2=d; // @@ Error: Same issue as above; should use list[s].
            list[i].num=1; // @@ Error: Same issue as above; should use list[s].
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
            
            list[s2].x1=list[i-1].x1; // @@ Error: When sign==3, i equals s after the loop, so list[i-1] is list[s-1], which is the last valid element. However, this logic incorrectly copies the last element to s2, but s2 might be the same as i-1, causing data loss. Also, the deletion logic is flawed; it should shift elements properly.
            list[s2].y1=list[i-1].y1; // @@ Error: Same issue as above.
            list[s2].x2=list[i-1].x2; // @@ Error: Same issue as above.
            list[s2].y2=list[i-1].y2; // @@ Error: Same issue as above.
            list[s2].num=list[i-1].num; // @@ Error: Same issue as above.
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