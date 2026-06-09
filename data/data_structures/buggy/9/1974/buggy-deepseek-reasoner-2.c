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
        line.num[i]=line.num[j]+1; // @@ Invalid syntax: should be line[i].num = line[j].num + 1; Also line.num[i] is not a valid member access.

        break;

}}}
for(i=n-1;i>=0;i--){
    c=0;
    if(line.num[i]>c){ // @@ Invalid syntax: line.num[i] should be line[i].num. Also variable c is reset each iteration, causing logical error.
        c=line[i]; // @@ Invalid assignment: cannot assign struct to int. Should be c = line[i].num;
        d=i;
    }
    
}
pf("%d %d %d",c,line.x1[i],line.y1[i]); // @@ Invalid: line.x1[i] should be line[d].x1; variable i is out of scope (not defined here).
    return 0;
}