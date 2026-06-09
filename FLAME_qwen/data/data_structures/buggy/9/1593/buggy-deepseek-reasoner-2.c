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
    for(int j = 0;j < n;j++)
    {
        if(lastline.right[0] == l[j].left[0]&&lastline.right[1] == l[j].left[1]){
            lastline = l[j];
            num[flag]++;
            x = 1;
        } // @@ Error: Forward match found but does not break after a match; also does not mark segment as used, can cause multiple matches per call and potential infinite loop.
        if(startline.left[0] == l[j].right[0]&&startline.left[1] == l[j].right[1]){
            startline = l[j];
            num[j] = num[flag]+1; // @@ Error: Backward matching is incorrect – chain must have increasing x; updating num[j] in this way corrupts chain length tracking.
            flag = j;
            x = 1;
        } // @@ Error: Backward matching violates the requirement of increasing x coordinates in a continuous line segment.
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
        while(succeed() != 0){
        
        } // @@ Error: No mechanism to mark used segments, leading to infinite loops or incorrect counting because same segment may be matched repeatedly.
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