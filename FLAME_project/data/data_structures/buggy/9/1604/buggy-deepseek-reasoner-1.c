#include<stdio.h>
#include<string.h>
typedef struct xianduan{
    int x1,x2,y1,y2;
    struct xianduan *pty;
}*xianpyt;
struct xianduan dian[100]; // @@ pty member is not initialized to NULL for all elements, causing undefined behavior when accessed later.
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
                dian[i].pty=&dian[j];
            }    
        }
    }
    xianpyt p,q;
    int chang=0;
    for(i=0;i<n;i++){
        chang=0; // @@ Should be initialized to 1 to count the starting segment itself; currently only counts links, not total segments.
        for(p=&dian[i],j=0;p!=NULL;p=p->pty){ // @@ pty may be uninitialized (not NULL) for endpoints without successor, leading to undefined behavior.
            if(i!=j){ // @@ This condition incorrectly excludes the first segment from the count; should increment for every visited segment.
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