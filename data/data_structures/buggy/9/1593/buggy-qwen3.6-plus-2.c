#include<stdio.h>
#define MAX 105

typedef struct line{
    int left[2];
    int right[2];
}Line;

Line l[MAX],startline,lastline;
int num[MAX];
int max,flag;
int n;

int succeed()
{
    int x = 0;
    for(int j = 0;j < n;j++) // @@ C89 standard does not allow variable declaration inside for-loop initialization, causing a compilation error in strict environments. Logically, scanning all segments repeatedly without tracking visited ones can lead to infinite loops or incorrect chaining.
    {
        if(lastline.right[0] == l[j].left[0]&&lastline.right[1] == l[j].left[1]){
            lastline = l[j];
            num[flag]++;
            x = 1;
        }
        if(startline.left[0] == l[j].right[0]&&startline.left[1] == l[j].right[1]){
            startline = l[j];
            num[j] = num[flag]+1; // @@ Logical error: incorrectly assigns the chain length to num[j] instead of accumulating it in num[flag], breaking the count tracking for the continuous line.
            flag = j; // @@ Logical error: updating flag during backward extension changes the reference index for the chain count, leading to incorrect accumulation and final result.
            x = 1;
        }
    }
    return x;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        num[i] = 1;
        scanf("%d%d%d%d",&l[i].left[0],&l[i].left[1],&l[i].right[0],&l[i].right[1]);
    }
    for(int i = 0;i < n;i++)
    {
        startline = l[i];
        lastline = l[i];
        flag = i;
        while(succeed() != 0){ // @@ Logical error: succeed() lacks a mechanism to mark visited segments, which can cause infinite loops or overcounting. Additionally, without sorting the segments first, the chaining logic is unreliable for arbitrary input order.
        
        }
    }
    max = num[0];
    for(int i = 0;i < n;i++)
    {
        if(max < num[i]){
            max = num[i];
            flag = i;
        }
    }
    printf("%d %d %d",max,l[flag].left[0],l[flag].left[1]);
    
    return 0;
}