#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int x1 , y1 , x2 , y2 ;
}line;
int cmp(const void *a , const void *b){
    line *p1 = (line*)a;
    line *p2 = (line*)b;
    return p1->x1 - p2->x1;
}
void read_and_sort(line *a , int n){
    for(int i = 0 ; i <  n ; i++)   scanf("%d %d %d %d" , &a[i].x1 , &a[i].y1 , &a[i].x2 , &a[i].y2);
    qsort(a , n , sizeof(line), cmp);
}
int line_connect(line a , line b){
    if(a.x2 == b.x1 && a.y2 == b.y1)
        return 1;
    return 0;
}
int judge(line *a , int n , line head){
    int flag = 1;
    for(int i = 0 ; i < n ; i++)
        if(line_connect(head , a[i])){
            flag++;
            head = a[i];
        }
    return flag;
}
int find_max(int *a , int n){
    int i , max = a[0] , flag = 0;
    for(i = 0 ; i < n ; i++)
        if(a[i] > max){
            flag = i;
            max = a[i];
        }
    return flag;
}
int main(){
    int n , flag[110];
    line a[110];
    memset( a , 0 , sizeof(a));
    scanf("%d",&n);
    read_and_sort( a , n );
    for(int i = 0 ; i < n ; i++)    flag[i] = judge( a , n , a[i] );
    int res = find_max(flag , n);
    printf("%d %d %d" , flag[res] , a[res].x1 , a[res].y1);
    return 0;
}


/*10
80 75 125 75
60 40 80 55
80 55 90 20
140 120 195 205
10 111 70 165
22 35 43 43
22 175 80 205
43 43 60 40
90 20 125 60
70 165 140 120*/

