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
            list[s1].x1=list[s2].x1; // @@ The logic for merging two segments is flawed. When segment A's start connects to segment B's end, we should merge them into one. The new segment should have B's start and A's end. Here it incorrectly assigns s2's start to s1's start (which is effectively keeping s2's start if s1 was the tail, but s1 is the head of the new incoming segment? No, s1 is the existing segment whose START matches the new segment's END? Wait. The new segment is (a,b) to (c,d). s1 is where list[s1].x1==c && list[s1].y1==d. So new segment's END matches s1's START. This means New -> s1. s2 is where list[s2].x2==a && list[s2].y2==b. So s2's END matches New's START. This means s2 -> New -> s1. The merged segment should start at s2's start and end at s1's end. The code sets list[s1].x1 = list[s2].x1. This updates s1's start to s2's start. Correct so far for the merged head. But it leaves s1's end as is (which is correct, s1's end is the tail). However, it then tries to "delete" s2 by overwriting it with list[i-1], which is invalid because i is out of scope or refers to garbage after the loop. Also, it doesn't correctly handle the count. It adds 2 to s1.num, but s1 and s2 already had counts. The total count should be s2.num + 1 (new) + s1.num. The current code does list[s1].num += 2, which is incorrect. It should be list[s1].num = list[s2].num + 1 + list[s1].num. And s2 needs to be removed from the array properly.
            list[s1].y1=list[s2].y1;
            list[s1].num+=2;
            
            list[s2].x1=list[i-1].x1; // @@ Invalid index access. 'i' is equal to 's' after the loop finishes. Accessing list[i-1] is accessing the last valid element, but copying it to s2 to "delete" s2 is not a standard or correct way to remove an element from an unsorted array without shifting. More importantly, if s2 > s1, this might overwrite data needed. If s2 < s1, it corrupts the array structure. The standard way is to swap s2 with the last element and decrement s, or shift elements. Given the constraint "No three or more segments share a single endpoint", simple merging might work if implemented correctly, but this specific deletion logic is broken.
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
    printf("%d %d %d\n", result, list[set].x1, list[set].y1);
    //输出 
    
    return 0;
}