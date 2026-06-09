//
//  main.c
//  DS3-1
//
//  Created by  on 2022/3/24.
//
// 求最大连续线段条数  结构的排序

//问题
//用快速排序只排了前n项，其他的完全没有动  (qsort里sizeof的长度传错了，要传一整个结构的长度，不能只传一个int）
//如何用结构体进行快速排序  (cmp里用结构体定义a,b;)
//考虑到如果有头坐标x1相同，但是y1不同的情况 (必须遍历所有横坐标相同的点;)
//记得更新最后一个点的坐标

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int n;    //线段数目
struct line{ //存储2个坐标
    int x1;  //起点坐标
    int y1;
    int x2;  //终点坐标
    int y2;
    
};

int cmp(const void *p,const void *q){  //快速排序
    struct line *a=(struct line*)p;
    struct line *b=(struct line*)q;
    return ((*a).x1-(*b).x1);
    
 //   return((*(struct line*)p).x1-(*(struct line*)q).x1);
    
//    int *a=(int*)p,*b=(int*)q;   //与非结构体情况对比，学习结构体的快排
//    return (*a-*b);
     }

int main() {
    struct line l[105];
    int i=0,j=0,k=0;
    int num[105];   //以i开头的连续线段的条数
    int max=0;      //目前最长线段条数
    int max_n=0;    //最长线段起点下标
   // int judge=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
    }
    
    qsort(l,n,sizeof(l[0]),cmp);   //快速排序
    
//    for(i=0;i<n;i++){
//        printf("%d %d %d %d %d\n",i,l[i].x1,l[i].y1,l[i].x2,l[i].y2);
//    }
    
    for(i=0;i<n-1;i++){
        num[i]=1;
        for(j=i;j<n-1;j++){
            
            for(k=j+1;k<n;k++){
                if(l[j].x2==l[k].x1&&l[j].y2==l[k].y1){
                    num[i]++;
                    break; //找到了，跳出k
                }
            }
            if(k==n)
                break; //跳出j
            else{
                j=k-1;
            }

        }
    }
    
    
    max=num[0];
    for(i=1;i<n-1;i++){
        if(num[i]>max){
            max=num[i];
            max_n=i;
        }
    }

    printf("%d %d %d",max,l[max_n].x1,l[max_n].y1);



    
    return 0;
}


//对于连续线段来说，在此满足xi<xi+1（i=1...n-1，n为连续线段中的端点数，xi为相应端点的X轴坐标）
//编程计算出连续线段中包含最多线段数的线段，输出相应的线段数和起点位置





