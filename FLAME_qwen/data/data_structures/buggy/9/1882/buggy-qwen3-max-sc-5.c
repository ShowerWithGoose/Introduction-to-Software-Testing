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
            if (point[j].x[0] < point[i].x[0]) { @@ // The array 'point' is uninitialized when first accessed; comparing and swapping garbage values leads to undefined behavior.
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
            if(point[k].x[1]==point[j].x[0]&&point[k].y[1]==point[j].y[0]) @@ // This greedy chaining assumes segments are sorted and only checks forward, but the initial sort is broken and doesn't guarantee connectivity; also fails to handle cases where a segment connects to a previous one not at index >= i.
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
    printf("%d %d %d",max,x0,y0); @@ // If no valid chain is found (e.g., all segments isolated), 'max' remains -11, leading to invalid output; also, the problem expects the number of segments in the chain, but 'len' starts at 1 and increments per connection, which actually counts segments correctly, but the logic to build chains is flawed.
    return 0;
}