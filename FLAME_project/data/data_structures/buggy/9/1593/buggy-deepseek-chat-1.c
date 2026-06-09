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
            num[flag]++; // @@ The count is updated for the original flag index, but when extending to the right, the segment count should be associated with the starting segment's index, not the current flag. This causes incorrect counting when multiple segments are chained.
            x = 1;
        }
        if(startline.left[0] == l[j].right[0]&&startline.left[1] == l[j].right[1]){
            startline = l[j];
            num[j] = num[flag]+1; // @@ When extending to the left, the count for the new starting segment (index j) is set based on the previous flag's count, but the flag is then updated to j. This logic is flawed because it doesn't properly track the chain length for the original starting segment.
            flag = j;
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
        while(succeed() != 0){
        
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
    printf("%d %d %d",max,l[flag].left[0],l[flag].left[1]); // @@ The starting point is taken from l[flag].left, but flag may have been changed during the left extension process, so it may not correspond to the original starting segment of the longest chain.
    
    return 0;
}