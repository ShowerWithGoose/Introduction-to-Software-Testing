#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef struct{
    int x1;
    int y1;
    int x2;
    int y2;
}coordinate;
coordinate coor[105];
void digui(int *len,coordinate mem,int n){
    for(int j=0;j<n;j++){
        if(mem.x2==coor[j].x1&&mem.y2==coor[j].y1){
            (*len)++;
            mem=coor[j];
            digui(len,mem,n); // @@ After the recursive call returns, the loop continues with the updated `mem`, which can cause the same segment (or another segment that also matches the new `mem`) to be counted again in this recursion level. Additionally, there is no mechanism to mark segments as already used, leading to overcounting because segments may be included multiple times in the chain.
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&coor[i].x1,&coor[i].y1,&coor[i].x2,&coor[i].y2);
    }
    int max=1;
    coordinate result;
    for(int i=0;i<n;i++){
        int count=1;
        digui(&count,coor[i],n);
        if(count>max){
            max=count;
            result=coor[i];
        }
    }
    printf("%d %d %d\n",max,result.x1,result.y1);
    return 0;
}