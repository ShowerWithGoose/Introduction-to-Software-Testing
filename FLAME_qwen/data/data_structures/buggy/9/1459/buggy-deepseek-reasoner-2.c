#include <stdio.h>
#include<string.h>
    int temp[100][5]; // @@ Potential buffer overflow if n > 100. Use a larger dynamic size or ensure n <= 100.
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};
int main() {
    int n,i,j,flag=0,m=0,count=1,max=1,x0,y0; // @@ x0 and y0 are uninitialized; if the longest chain has length 1, they remain uninitialized leading to undefined behavior.
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
        array[i].num=count;
        count=1;
    }
    for(i=0;i<m;i++){
        if(array[i].num > max){ // @@ Should use >= or initialize x0,y0 to the first segment's start to handle the case where the longest chain has length 1.
        x0= array[i].x1;
        y0= array[i].y1;
        max=array[i].num;
        }
    }
            for(i=0;i<m;i++){ // @@ This debug loop prints extra output that is not part of the required output format.
        printf("%d %d %d %d    %d\n",array[i].x1,array[i].y1,array[i].x2, array[i].y2,array[i].num);
    }
    printf("%d %d %d",max,x0,y0);
    return 0;
}