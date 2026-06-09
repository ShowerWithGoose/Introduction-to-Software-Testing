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
                dian[i].pty=&dian[j]; // @@ This assignment overwrites previous connections; if a segment can connect to multiple segments, only the last one is stored, but the problem implies each segment has at most one successor (no three share an endpoint), so this is acceptable. However, the pointer is not initialized to NULL, causing undefined behavior when checking p!=NULL later.
            }    
        }
    }
    xianpyt p,q;
    int chang=0;
    for(i=0;i<n;i++){
        chang=0;
        for(p=&dian[i],j=0;p!=NULL;p=p->pty){ // @@ The pointer pty is not initialized to NULL for all segments; if a segment has no successor, pty contains garbage, causing the loop to continue incorrectly or crash.
            if(i!=j){
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