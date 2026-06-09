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
            if (point[j].x[0] < point[i].x[0]) {
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
    printf("%d %d %d",max,x0,y0); // @@ [The variable 'max' is initialized to -11, but if no chain is found (e.g., single segment), it may not be updated correctly. Also, the logic for chaining segments only checks forward from each starting point but does not ensure that the next segment is the immediate continuation; it may skip over valid continuations or include invalid ones due to unsorted input and incomplete traversal. Additionally, the input reading is missing: the program never reads the actual segment coordinates into the 'point' array, so all values are uninitialized (zero), leading to wrong comparisons and output.]
    return 0;
}