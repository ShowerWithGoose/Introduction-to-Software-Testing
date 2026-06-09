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
            num[flag]++; // @@ [The logic incorrectly updates the count for the starting segment 'flag' instead of the current chain being built. When extending the chain, the count should be associated with the new end or tracked separately, but here it pollutes the count of the original start index 'flag'. More critically, this function is called in a loop for each 'i', but it modifies global state 'num' and 'flag' in a way that doesn't correctly isolate the chain length for each starting segment 'i'. The variable 'flag' is updated inside the second 'if', changing which index's count is incremented in subsequent iterations or calls, leading to incorrect counts.]
            x = 1;
        }
        if(startline.left[0] == l[j].right[0]&&startline.left[1] == l[j].right[1]){
            startline = l[j];
            num[j] = num[flag]+1; // @@ [This logic attempts to transfer the count to the new segment 'j', but 'num[flag]' might have been inflated by previous incorrect increments. Also, updating 'flag = j' changes the target for future increments in this while loop iteration, mixing up the counts for different potential chains. The fundamental issue is that 'succeed' tries to grow a chain bidirectionally using global variables that persist across checks for different 'j's in a single pass, but the loop structure 'for(int j...)' combined with modifying 'startline'/'lastline' and 'flag' leads to double counting or incorrect association of segments to chains.]
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
    printf("%d %d %d",max,l[flag].left[0],l[flag].left[1]);
    
    return 0;
}