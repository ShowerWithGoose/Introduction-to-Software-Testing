#include<stdio.h>
#include<string.h>
typedef struct xianduan{
    int x1,x2,y1,y2;
    struct xianduan *pty;
}*xianpyt;
struct xianduan dian[100];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&dian[i].x1,&dian[i].y1,&dian[i].x2,&dian[i].y2);
    }
    int max=0,maxx,maxy;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
                if(dian[i].x2==dian[j].x1&&dian[i].y2==dian[j].y1)
                dian[i].pty=&dian[j]; // @@ The pointer pty is not initialized to NULL for segments that do not have a successor, leading to undefined behavior or garbage values when traversing the chain later. It should be initialized to NULL before the loop or explicitly set here if no match is found, but more critically, if multiple matches were possible (though constraint says max 2 share endpoint), this overwrites. However, the main issue is lack of initialization to NULL for non-matching cases.
            }    
        }
    }
    xianpyt p,q;
    int chang=0;
    for(i=0;i<n;i++){
        chang=0;
        for(p=&dian[i],j=0;p!=NULL;p=p->pty){
            if(i!=j){ // @@ This condition is logically incorrect for counting the length of the chain. 'j' is just a counter of steps in the traversal, not an index related to 'i'. The check 'i!=j' does not prevent counting the starting node itself if j happens to equal i (which it does at start if we consider step 0). More importantly, the logic for counting segments in the continuous line is flawed. The chain traversal counts nodes visited. If p starts at dian[i], the first iteration has j=0. The condition i!=j (0!=0) is false, so chang is not incremented for the first segment. This means the starting segment is never counted.
                chang++;
            }
            j++;
        }
        if(chang>max){
            max=chang;
            maxx=dian[i].x1;
            maxy=dian[i].y1;
        }
    }
    printf("%d %d %d",max,maxx,maxy);
    return 0;
}