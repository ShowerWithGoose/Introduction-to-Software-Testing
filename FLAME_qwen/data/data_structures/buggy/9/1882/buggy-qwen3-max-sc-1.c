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
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for (int j = i; j < n; j++) {
            if (point[j].x[0] < point[i].x[0]) { @@ [Uninitialized memory access: 'point' array is used before being populated with input values, leading to undefined behavior during sorting]
                temp = point[j];
                point[j] = point[i];
                point[i] = temp;
                flag=1;
            }
        }
        if(flag==0) break;
    }
    for(int i=0;i<n;i++)
        printf("%d %d\n",point[i].x[0],point[i].y[0]);
    for(int i=0;i<n;i++)
    {
        int k=i;
        int len=1;
        for(int j=i;j<n;j++)
        {
            if(point[k].x[1]==point[j].x[0]&&point[k].y[1]==point[j].y[0]) @@ [Incorrect chaining logic: only checks forward from current segment but doesn't ensure continuous chain; also fails to account for segments that may connect in arbitrary order due to prior flawed sorting]
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
    printf("%d %d %d",max,x0,y0); @@ [Potential use of uninitialized variables: if no valid chain is found (e.g., n=0), 'max', 'x0', 'y0' may be printed uninitialized]
    return 0;
}