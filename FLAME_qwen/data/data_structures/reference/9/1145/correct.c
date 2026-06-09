#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 100
int x1[M]={0};
int y1[M]={0};
int x2[M]={0};
int y2[M]={0};
int n;
int i;
int shengdu[M]={0};
void bubbleSort(int x1[],int y1[],int x2[],int y2[], int n)//单关键字x1快排//
{
int i, j, holdx1,holdx2,holdy1,holdy2;
for(i = 0; i < n - 1; i++)
for(j = 0; j < n-1-i; j++)
if(x1[j] > x1[j + 1])
{
holdx1 = x1[j];
x1[j] = x1[j + 1];
x1[j + 1] = holdx1;
holdx2 = x2[j];
x2[j] = x2[j + 1];
x2[j + 1] = holdx2;
holdy1 = y1[j];
y1[j] = y1[j + 1];
y1[j + 1] = holdy1;
holdy2 = y2[j];
y2[j] =y2[j + 1];
y2[j + 1] = holdy2;
}
}
void cengshu(int cen,int x){
int dui=0;
for (int j = x+1; j < n; j++)
{
   if (x2[x]==x1[j]&&y2[x]==y1[j])
   {
       cen++;
       dui++;
       cengshu(cen,j);
   }
}
if (dui==0)
{
    shengdu[i]=cen;
    return;
}

}
int main(){
scanf("%d",&n);
for (i = 0; i < n; i++)
{
scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
}
bubbleSort(x1,y1,x2,y2,n);

for ( i = 0; i < n; i++)
{
    cengshu(1,i);
}
int max=1;
int maxone=0;
for (int k = 0; k < n; k++)
{
   if (shengdu[k]>max)
   {
       max=shengdu[k];
       maxone=k;
   }
}
printf("%d %d %d",max,x1[maxone],y1[maxone]);
return 0;






}
