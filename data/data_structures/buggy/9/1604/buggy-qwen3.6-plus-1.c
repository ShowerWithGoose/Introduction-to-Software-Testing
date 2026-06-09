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
    int max=0,maxx,maxy; // @@ [Logical error: maxx and maxy are uninitialized. If max is never updated, printing them results in undefined behavior. They should be initialized to valid coordinates.]
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
                if(dian[i].x2==dian[j].x1&&dian[i].y2==dian[j].y1)
                dian[i].pty=&dian[j]; // @@ [Logical error: dian[i].pty is not explicitly initialized to NULL before the linking loop. If a segment has no successor, pty may contain garbage values, causing the traversal loop to access invalid memory or run indefinitely.]
            }    
        }
    }
    xianpyt p,q;
    int chang=0;
    for(i=0;i<n;i++){
        chang=0; // @@ [Logical error: chang should be initialized to 1 because each segment itself counts as 1. Initializing to 0 causes the final count to be off by one.]
        for(p=&dian[i],j=0;p!=NULL;p=p->pty){
            if(i!=j){ // @@ [Logical error: j is a loop iteration counter, not an array index. This condition incorrectly skips counting when i equals the iteration count. It should be removed to correctly count all segments in the chain.]
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