#include <stdio.h>
struct point
{
    int x[2];
    int y[2];
}point[114],temp;
int arr[114];
int main() {
    int n,max=-11,x0,y0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) // @@ [Compilation error: C89 does not allow declaration inside for loop; also logical error: point array not initialized, missing input reading]
    {
        int flag=0;
        for (int j = i; j < n; j++) {
            if (point[j].x[0] < point[i].x[0]) { // @@ [Logical error: point array uninitialized, sorting on garbage values]
                temp = point[j];
                point[j] = point[i];
                point[i] = temp;
                flag=1;
            }
        }
        if(flag==0) break; // @@ [Logical error: premature break, does not complete bubble sort]
    }
    for(int i=0;i<n;i++)
        printf("%d %d\n",point[i].x[0],point[i].y[0]); // @@ [Logical error: prints uninitialized data]
    for(int i=0;i<n;i++) // @@ [Compilation error: C89 does not allow declaration inside for loop; also logical error: point array uninitialized]
    {
        int k=i;
        int len=1;
        for(int j=i;j<n;j++)
        {
            if(point[k].x[1]==point[j].x[0]&&point[k].y[1]==point[j].y[0]) // @@ [Logical error: uninitialized data, algorithm incorrect for finding longest continuous segment]
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