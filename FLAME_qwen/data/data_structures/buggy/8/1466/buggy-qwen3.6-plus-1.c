#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int v; 
typedef struct Tutu{
    int bian[105];
    int shu;
    int jilu;
}hu;

hu tu[20]; // @@ Array size 20 is too small for n up to 100, causing out-of-bounds access when n > 20.
int dui[105],tou,wei,shan;

int pai(const void*e1,const void*e2){
    return *(int*)e1-*(int*)e2;
    }
    
void xun(int a){
    int i;
    if(tu[a].jilu==0 && a!=shan){
        printf("%d ",a);
        tu[a].jilu=1;
        v++;
    }
    for(i=0;i<tu[a].shu;i++){
        if(tu[tu[a].bian[i]].jilu==0 && tu[a].bian[i]!=shan){
            xun(tu[a].bian[i]);
        }
    }
}

void guang(int a){
    int i;
    if(tu[a].jilu==1 && a!=shan){ // @@ jilu is initialized to 0 for unvisited vertices, should check ==0 instead of ==1.
        printf("%d ",a);
        tu[a].jilu=0; // @@ Should mark vertex as visited by setting jilu to 1, not 0.
        v++;
    }
    for(i=0;i<tu[a].shu;i++){
        if(tu[tu[a].bian[i]].jilu==1 && tu[a].bian[i]!=shan){ // @@ Should check for unvisited neighbors (jilu==0), not visited.
        printf("%d ",tu[a].bian[i]);
        dui[wei++]=tu[a].bian[i];
        tu[tu[a].bian[i]].jilu=0; // @@ Should mark neighbor as visited by setting jilu to 1.
        v++;
        }
    }
    if(tou==wei) return;
    guang(dui[tou++]);
}

int main(){
    int i,d,b,a,n,j;
    scanf("%d %d",&d,&b);
    for(i=0;i<d;i++){
        tu[i].shu=0;
        tu[i].jilu=0;
    }
    for(i=0;i<b;i++){
        scanf("%d %d",&a,&n);
        tu[a].bian[tu[a].shu++]=n;
        tu[n].bian[tu[n].shu++]=a;
    }
    scanf("%d",&a);
    for(i=0;i<d;i++){
        qsort(tu[i].bian,tu[i].shu,sizeof(tu[i].bian[0]),pai);
    }
    shan=-1;
    for(i=0,v=0;i<d && v!=d;i++){
        xun(i);
    }
    printf("\n");
    tou=wei=0;
    for(i=0,v=0;i<d && v!=d;i++){
        guang(i);
    }
    printf("\n");
    shan=a;
    for(i=0,v=0;i<d && v!=d;i++){
        xun(i);
    }
    printf("\n");
    memset(dui,0,sizeof(dui));
    tou=wei=0;
    for(i=0,v=0;i<d && v!=d;i++){
        guang(i);
    }
    return 0;
}