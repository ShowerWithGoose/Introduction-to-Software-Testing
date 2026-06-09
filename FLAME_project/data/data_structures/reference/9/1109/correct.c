#include <stdio.h>
struct lines{
    int p1;int p2;int p3;int p4;
}line[100],temp,final;
// int linesort(struct lines pp,int n,int time,int i){
//     for(;i<n;i++){
//        if(line[i+1].p1==line[i].p3&&line[i+1].p2==line[i].p2)int hh;
//   }
    
// return 1;
// }
void replace(struct  lines li[100],int n)
{for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(li[i].p1>li[j].p1){
            temp=li[i];
            li[i]=li[j];
            li[j]=temp;
        }
    }
}
   
};


int main (){
    int n,i,j,max=0;scanf("%d",&n);
 for(i=0;i<n;i++){
    scanf("%d%d%d%d",&line[i].p1,&line[i].p2,&line[i].p3,&line[i].p4);
 }
replace(line,n);
for(i=0;i<n;i++){int z=i;int sum=1;
    for(j=i+1;j<n;j++){
        if(line[z].p3==line[j].p1&&line[z].p4==line[j].p2){
            sum++;z=j;
        }
    }
    if(sum>max){
        max=sum;
        final=line[i];
    }
}
printf("%d %d %d",max,final.p1,final.p2);
return 0;

}
