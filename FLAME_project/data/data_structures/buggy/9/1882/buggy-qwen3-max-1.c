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
            if (point[j].x[0] < point[i].x[0]) { @@ // The array 'point' is uninitialized when read here; comparing garbage values leads to incorrect sorting.
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
            if(point[k].x[1]==point[j].x[0]&&point[k].y[1]==point[j].y[0]) @@ // This only checks forward from index i, but the next segment might appear before index i due to incomplete sorting or unsorted input; also, it doesn't chain beyond one connection properly because 'k=j' doesn't guarantee continuity in a single pass.
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
    printf("%d %d %d",max,x0,y0); @@ // 'max' is initialized to -11, but if no segments connect, it should be at least 1 (each segment is length 1). Also, input reading is missing: the program never reads the actual segment coordinates into 'point', so all data is garbage.
    return 0;
}