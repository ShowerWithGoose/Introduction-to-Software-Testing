#include <stdio.h>
#include<string.h>
    int temp[100][5];
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};
int main() {
    int n,i,j,flag=0,m=0,count=1,max=1,x0,y0;
    struct line array[101];
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&temp[i][0],&temp[i][1],&temp[i][2],&temp[i][3]);
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j) continue;
            else if(temp[i][0]==temp[j][2]&&temp[i][1]==temp[j][3]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            array[m].x1=temp[i][0];
            array[m].y1=temp[i][1];
            array[m].x2=temp[i][2];
            array[m].y2=temp[i][3];
            m++;
        }
        flag=0;
    }    
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(temp[j][0]==array[i].x2 && temp[j][1]==array[i].y2){
                array[i].x2=temp[j][2];
                array[i].y2=temp[j][3];
                count++;
                j=-1;
            }
        }
        array[i].num=count; // @@ [The variable 'count' is not reset properly for each new chain. It should be initialized inside the outer loop before the inner loop starts, but currently it's only reset after processing each chain. However, the real issue is that 'count' starts at 1 globally and is reused without being reset to 1 at the beginning of each i-loop iteration. This causes incorrect counts when multiple chains are processed.]
        count=1;
    }
    for(i=0;i<m;i++){
        if(array[i].num > max){
        x0= array[i].x1;
        y0= array[i].y1;
        max=array[i].num;
        }
    }
            for(i=0;i<m;i++){
        printf("%d %d %d %d    %d\n",array[i].x1,array[i].y1,array[i].x2, array[i].y2,array[i].num);
    }
    printf("%d %d %d",max,x0,y0); // @@ [The variables x0 and y0 are only assigned if a chain longer than 1 is found (since max starts at 1). If the longest chain has length 1, x0 and y0 remain uninitialized, leading to undefined behavior. They should be initialized with the starting point of the first segment or updated even when max == 1.]
    return 0;
}