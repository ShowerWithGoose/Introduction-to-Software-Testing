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
    for(int i=0;i<n;i++) // @@ The program never reads the segment coordinates after this line; the point array remains uninitialized, and all subsequent operations use garbage values.
    {
        int flag=0;
        for (int j = i; j < n; j++) {
            if (point[j].x[0] < point[i].x[0]) { // @@ Accessing uninitialized point array; the condition compares garbage values.
                temp = point[j];
                point[j] = point[i];
                point[i] = temp;
                flag=1;
            }
        }
        if(flag==0) break;
    }
    for(int i=0;i<n;i++)
        printf("%d %d\n",point[i].x[0],point[i].y[0]); // @@ Prints uninitialized point data; this debug output is not part of the required output and disturbs the result.
    for(int i=0;i<n;i++)
    {
        int k=i;
        int len=1;
        for(int j=i;j<n;j++)
        {
            if(point[k].x[1]==point[j].x[0]&&point[k].y[1]==point[j].y[0]) // @@ Uses uninitialized point data; the chain counting is based on garbage values.
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