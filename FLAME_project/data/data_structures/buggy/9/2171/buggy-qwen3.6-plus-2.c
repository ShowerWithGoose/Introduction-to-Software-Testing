#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};
typedef struct line lin;
lin str[105];
int main(void){
    int i,j,n,max = 1,flag = 0;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        scanf("%d%d%d%d",&str[i].x1,&str[i].y1,&str[i].x2,&str[i].y2);
        str[i].num = 1;
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(i != j) 
            {
                if(str[i].x2 == str[j].x1&&str[i].y2 == str[j].y1)
                {
                    str[i].x2 = str[j].x2;        
                    str[i].y2 = str[j].y2;    
                    str[i].num += str[j].num; 
                    j = 0; // @@ The logic modifies the endpoint of segment i to merge with segment j, but it does not invalidate segment j. In subsequent iterations, segment j (which is now effectively "used" or part of segment i) can still be matched by other segments or even segment i again if the loop resets incorrectly, leading to double counting or incorrect chain formation. More critically, this greedy merging without marking used segments or handling the topology correctly fails to build the longest chain properly because it mutates the segments in place without ensuring a valid topological order or preventing reuse of segments in multiple chains. The reference solution uses a DP-like approach on sorted segments. This approach tries to extend segment i by appending segment j. However, simply resetting j=0 and continuing allows re-scanning, but since str[j] is not marked as used, it might be appended to another segment later, or if str[i] grows, it might match new segments. The fundamental flaw is that this local mutation doesn't guarantee finding the global longest path in the DAG of segments. Specifically, for the test case, it fails to chain 3 segments correctly.
                }
            }
        }
        if(str[i].num > max)
        {
            max = str[i].num;
            flag = i;
        }
    }
    printf("%d %d %d",max,str[flag].x1,str[flag].y1);
    return 0;
}