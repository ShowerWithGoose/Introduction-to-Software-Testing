#include <stdio.h>
struct point
{
    int x[2];
    int y[2];
}point[114],temp;
int arr[114];
int main() {
    int n,max=-11,x0,y0;
    scanf("%d",&n); // @@ The program fails to read the coordinates of the line segments from the input, leaving the 'point' array uninitialized.
    for(int i=0;i<n;i++) // @@ Attempts to sort the uninitialized 'point' array, resulting in undefined behavior.
    {
        int flag=0;
        for (int j = i; j < n; j++) {
            if (point[j].x[0] < point[i].x[0]) {
                temp = point[j];
                point[j] = point[i];
                point[i] = temp;
                flag=1;
            }
        }
        if(flag==0) break;
    }
    for(int i=0;i<n;i++) // @@ Prints uninitialized data instead of processing the actual input segments.
        printf("%d %d\n",point[i].x[0],point[i].y[0]);
    for(int i=0;i<n;i++) // @@ The logic for finding the longest continuous line segment is flawed as it assumes connected segments will be adjacent in the array after sorting, which is incorrect for arbitrary 2D connections.
    {
        int k=i;
        int len=1;
        for(int j=i;j<n;j++)
        {
            if(point[k].x[1]==point[j].x[0]&&point[k].y[1]==point[j].y[0])
            {
                len++;
                k=j;
            }
        }
        if(max<len)
        {
            max=len;
            x0=point[i].x[0];
            y0=point[i].y[0];
        }
    }
    printf("%d %d %d",max,x0,y0);
    return 0;
}