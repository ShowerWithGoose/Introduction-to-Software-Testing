#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include <ctype.h> 
int count;int sign[105]={0};int bcombo;
typedef struct{
    int x1,y1,x2,y2;
}XD;
int qian(XD xd[105],int num){
    sign[num]=1;
    for(int i=num+1;i<count;i++){
        if(sign[i]==0){
            if(xd[i].x2==xd[num].x1&&xd[i].y2==xd[num].y1){
                sign[i]=1;
                bcombo++;
                qian(xd,i);
            }
        }
    }
    return bcombo;
}
int hou(XD xd[105],int num){
    sign[num]=1;
    for(int i=num+1;i<count;i++){
        if(sign[i]==0){
            if(xd[i].x1==xd[num].x2&&xd[i].y1==xd[num].y2){
                sign[i]=1;
                bcombo++;
                hou(xd,i);
            }
        }
    }
    return bcombo;
}
int main()
{
    XD xd[105];
    int n,re;
    int combo=0,maxcombo=0;
    scanf("%d",&n);
    
    for(count=0;count<n;count++){
        scanf("%d%d%d%d",&xd[count].x1,&xd[count].y1,&xd[count].x2,&xd[count].y2);
    }
    for(int i=0;i<count;i++){
        if(sign[i]==0){
            bcombo=0;
            combo+=qian(xd,i); // @@ The logic for finding the longest chain is flawed. It attempts to traverse backwards and forwards from an unvisited node, but `sign` array prevents revisiting nodes across different iterations of the outer loop correctly for independent chains, and `combo` accumulation is incorrect because it doesn't reset `sign` or handle disjoint components properly. More critically, the traversal only looks at indices `i > num`, missing connections to segments with lower indices that might be part of the same chain but were processed earlier or skipped.
            bcombo=0;
            combo+=hou(xd,i); // @@ Same issue as above. The directional traversal is restricted by index order (`i=num+1`), meaning it can only form chains where segment indices are increasing in the direction of the geometric connection. This fails if the geometric chain requires jumping back to a lower index.
            if(combo>maxcombo){
                re=i;
                maxcombo=combo;
            }
            combo=0;
        }
    }
    int rex1,rey1;
    int ree=re;
    A:for(int i=0;i<count;i++){
        if(xd[i].x2==xd[ree].x1&&xd[i].y2==xd[ree].y1){
            ree=i;
            goto A;
        }
    }
    rex1=xd[ree].x1,rey1=xd[ree].y1;
    printf("%d %d %d",maxcombo+1,rex1,rey1); // @@ Since `maxcombo` calculation is wrong (likely undercounting or counting incorrectly due to the visited/sign logic and index restriction), the output is wrong. For the test case, the chain is 1->2->3->4->5 (indices 3->1->4->0->2 roughly depending on input order). The code's `sign` array marks nodes as visited globally, so once a node is part of one "attempted" chain, it's ignored in others, breaking the ability to find the true longest path in a general graph sense, although here it's a line. The main error is that `qian` and `hou` only search forward in the array (`i=num+1`), so they miss predecessors/successors that appear earlier in the input array.

    return 0;
}