#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxV  1000

int s[MaxV][MaxV];
int t1[MaxV];
int t2[MaxV];
int n;
int x,y,flag,i,a,b;

void DfS(int p){int i=1;
if(flag==0){
    printf("%d",p);
    flag=1;
}
else{
    printf(" %d",p);
}t1[p]=1;
for(i=1;i<=n;i++){
    if(s[p][i]==1&&t1[i]==0){
        DfS(i);
    }
}

}int j = 1, k = 1;
void BfS(int p){
    int z;
    t2[1] = p;
    for ( j=1,k=1;j <= k;)
    {
        z= t2[j++];
        if (t1[z] == 1)
        {
            continue;
        }
if(flag==0){
    printf("%d",z);
    flag=1;
}else{printf(" %d",z);
}
t1[z]=1;
for(i=0;i<=n;i++){
 if(s[z][i]==1&&t1[i]!=1){

    t2[++k]=i;
 }

}}
}
int main(){
scanf("%d %d",&n,&x);
for(i=0;i<=x-1;i++){
    scanf("%d %d",&a,&b);
    s[a][b]=1;
    s[b][a]=1;
}scanf("%d",&y);
DfS(0);
printf("\n");
memset(t1,0,sizeof(t1));
flag=0;
BfS(0);printf("\n");
memset(t1,0,sizeof(t1));


t1[y]=1;flag=0;
DfS(0);
printf("\n");memset(t1,0,sizeof(t1));
flag=0;

t1[y]=1;
BfS(0);
printf("\n");



return 0;}

