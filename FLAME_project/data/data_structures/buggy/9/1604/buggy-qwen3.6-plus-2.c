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
                dian[i].pty=&dian[j]; // @@ The pointer pty is not initialized to NULL for segments that do not have a successor, leading to undefined behavior or infinite loops when traversing. It should be initialized to NULL before the loop or explicitly set here if no match is found.
            }    
        }
    }
    xianpyt p,q;
    int chang=0;
    for(i=0;i<n;i++){
        chang=0;
        for(p=&dian[i],j=0;p!=NULL;p=p->pty){
            if(i!=j){ // @@ The condition i!=j is incorrect for counting segments in the chain. 'j' is a local counter for the current chain traversal, while 'i' is the index of the starting segment. This logic fails to correctly count the segments because j is incremented every step, but the comparison with i (the start index) doesn't make sense for filtering valid links. More importantly, the first segment (where p points to dian[i]) is skipped because j starts at 0 and i might be 0, or simply because the logic is flawed. The count should include the starting segment.
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