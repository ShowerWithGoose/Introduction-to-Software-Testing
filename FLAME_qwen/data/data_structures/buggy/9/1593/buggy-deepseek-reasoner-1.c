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
        }
        if(startline.left[0] == l[j].right[0]&&startline.left[1] == l[j].right[1]){ // @@ [Backward extension incorrectly allows the chain to grow to the left. This can cause the length to be counted for both the leftmost and rightmost segments, and the program may output the wrong starting point (the rightmost segment's left endpoint instead of the true start of the chain). Only forward extensions (right endpoint to left endpoint) should be considered to maintain increasing x-coordinates.]
            startline = l[j];
            num[j] = num[flag]+1;
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
        flag = i; // @@ [When starting a new chain, the count for this starting segment should be reset to 1, but num[i] may have been changed by a previous chain. The line lacks a statement like `num[i] = 1;` to ensure the count starts fresh.]
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
    printf("%d %d %d",max,l[flag].left[0],l[flag].left[1]);
    
    return 0;
}