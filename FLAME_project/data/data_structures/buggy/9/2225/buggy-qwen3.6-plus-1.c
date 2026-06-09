#include<stdio.h>
#include<stdlib.h>
int main()
{    
    int x[205]={0};
    int y[205]={0};
    int n;
    int sign=1;
    int k=0;
    int a=0;
    int max=1;
    int len=1;
    int l=0;
    int r=0;
    int lm=0;
    int rm=0;
    scanf("%d",&n);
    for(int i=0;i<2*n;i+=2)
    {
        scanf("%d%d%d%d",&x[i],&y[i],&x[i+1],&y[i+1]);
    }
    //输入

    for(int i=0;i<2*n;i+=2)
    {
        for(int j=i+1;j<2*n;j+=2)
        {
            
            if(x[i]==x[j]&&y[i]==y[j])
            {
                len++;
                l=x[j-1]; @@ The logic for determining the start point is flawed. When segment i connects to segment j at their start points (x[i], y[i]) == (x[j], y[j]), the continuous line extends backwards from segment i. The new start point should be the start of segment j (x[j], y[j]) or potentially further back if j connects to others. However, `x[j-1]` accesses the y-coordinate of the previous point in the flat array structure if interpreted as pairs, but here x and y are separate arrays. `x[j-1]` is actually the y-coordinate of the *previous* segment's end point if j is an index into the flat array? No, `x` stores x-coordinates. `x[j]` is the x-coord of the start of segment j/2. `x[j-1]` is invalid logic for finding the other endpoint of segment j. The other endpoint of segment j (which starts at j) is at index j+1. So `l` should be updated to `x[j+1]`? No, if they connect at start, the line goes from j's end to i's end? Or j's start to i's end? The problem says x1 < x2. If start of i equals start of j, they diverge or overlap? Problem says "share an endpoint... form a continuous line". Usually this implies End of one matches Start of another. If Start matches Start, they don't form a single continuous line in increasing x order unless one is reversed, but input guarantees x1<x2. So Start-Start connection usually doesn't extend the line in the forward direction. However, if we consider the chain, maybe i is connected to something before it? The code assumes i is the "current" head. This entire block logic is suspect for standard chain building. But specifically, `l=x[j-1]` accesses memory incorrectly relative to the segment structure. Segment j has start `(x[j], y[j])` and end `(x[j+1], y[j+1])`. If they connect at start, the "other" end of j is `x[j+1]`. But since x increases, connecting starts means they go in same direction from same point, not a continuous line segment end-to-end.
                r=y[j-1]; @@ Same error as above. `y[j-1]` is not the corresponding y-coordinate for the other end of segment j.
                sign=1;
                k=j-1; @@ `k` is used as an index to find next connections. If we connected at `x[j]`, the next search should likely start from the other end of segment j, which is index `j+1`. Setting `k=j-1` is incorrect.
                while(sign==1)
                {
                
                sign=0;
                    for( a=0;a<2*n;a++)
                    {
                    if(k==a)
                    {
                        a++;
                    }
                    if(x[k]==x[a]&&y[k]==y[a])
                    {
                        len++;
                        l=x[a-1]; @@ Similar logic error. If we are at endpoint `k` and find a match at `a` (start of another segment), the new endpoint becomes the end of that segment (`a+1`). The start point `l` shouldn't change if we are extending forwards. If we are extending backwards, `l` updates. The variable `l` is supposed to be the global start. In this `while` loop, we are traversing forward from `j`. The start point `l` was set before the loop. It should not be updated inside the forward traversal loop unless we are prepending. Here we seem to be appending. So `l` should remain unchanged.
                        r=y[a-1]; @@ Same error.
                        k=a-1; @@ Should move to the other end of the matched segment. If `a` is the start index, the other end is `a+1`.
                        sign++;
                        a=0;
                        break;
                    }
                    }
                    a=0;
                }
            }
            

            if(x[i+1]==x[j+1]&&y[i+1]==y[j+1])
            {
                len++;
                k=j+2;
                sign=1;
                while(sign==1)
                {
                    sign=0;
                    for(a=0;a<2*n;a++)
                    {
                        if(k==a)
                        {
                            a++;
                        }
                        if(x[k]==x[a]&&y[k]==y[a])
                        {
                            len++;
                            k=a+1;
                            sign++;
                            a=0;
                            break;
                        }
                    }
                    
                }
                
            }
            
        }    
        if(max<len)
        {
            max=len;
            lm=l;
            rm=r;
        }
        len=1;

    }
    printf("%d %d %d\n",max,lm,rm);

    system("pause");
    return 0;
}