#include <stdio.h>
#define sf scanf
#define pf printf
#define ll long long 
#include <math.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>
typedef struct student{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
    int record;
}student;
student line[104];
int compare(const void *a,const void *b){
    struct student *c=(student *)a;
    struct student *d=(student *)b;
    if(c->x1!=d->x1) return c->x1-d->x1;
    else 
    return d->y1-c->y1;
}
int main(){

int a,b,c,d,e,f,i,n,flag=0,j;
sf("%d",&n);

for(i=0;i<n;i++){
    sf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    line[i].num=0;
    line[i].record=-1;
}
qsort(line,n,sizeof(line[0]),compare);

for(i=n-1;i>=0;i--){

    for(j=i-1;j>=0;j--){
            if((line[i].x1==line[j].x2)&&(line[i].y1==line[j].y2)){
        line.num[i]=line.num[j]+1; // @@ [Using dot operator on array name 'line' which is treated as pointer; should use line[i].num instead of line.num[i]]

        break;

}}}
for(i=n-1;i>=0;i--){
    c=0;
    if(line.num[i]>c){ // @@ [Same error: line.num[i] should be line[i].num]
        c=line[i]; // @@ [Incompatible assignment: trying to assign struct student to int variable 'c']
        d=i;
    }
    
}
pf("%d %d %d",c,line.x1[i],line.y1[i]); // @@ [line.x1[i] and line.y1[i] are incorrect; should be line[i].x1 and line[i].y1. Also 'c' is a struct but used as int in format specifier %d]
    return 0;
}