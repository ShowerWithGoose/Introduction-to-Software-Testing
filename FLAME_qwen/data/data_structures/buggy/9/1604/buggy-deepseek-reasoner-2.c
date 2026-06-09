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
                dian[i].pty=&dian[j]; // @@ Pointer left uninitialized when condition fails; must set to NULL otherwise chain traversal will crash.
            }    
        }
    }
    xianpyt p,q;
    int chang=0;
    for(i=0;i<n;i++){
        chang=0;
        for(p=&dian[i],j=0;p!=NULL;p=p->pty){
            if(i!=j){ // @@ Condition is logically wrong; j is a step counter, not a segment index; this incorrectly skips or includes segments. Should just always increment chang.
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