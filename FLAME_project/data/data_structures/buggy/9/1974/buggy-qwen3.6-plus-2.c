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
        line.num[i]=line.num[j]+1; // @@ Error: 'line' is an array of structs, not a struct itself. Should use line[i].num and line[j].num. Also, logic seems reversed for building chain length from start to end or vice versa depending on sort order. Given x1 < x2 and sorted by x1, if line[i] connects to line[j] where j < i, it means line[j] ends where line[i] starts. So line[i] extends the chain ending at j. Thus line[i].num should be line[j].num + 1.

        break;

}}}
for(i=n-1;i>=0;i--){
    c=0;
    if(line.num[i]>c){
        c=line[i]; // @@ Error: 'c' is an int, but 'line[i]' is a struct. Should likely store the index or the num value. Based on final print, c is intended to be the max count. So it should be c = line[i].num. And we need to track the index of the start of this longest chain.
        d=i;
    }
    
}
pf("%d %d %d",c,line.x1[i],line.y1[i]); // @@ Error: 'i' is out of scope or holds the last value from the loop (which is -1 or 0 depending on loop exit). Should use the index stored in 'd' (if corrected above) to access the starting point of the longest chain. Also, line.x1[i] syntax is wrong, should be line[d].x1.
    return 0;
}