#include<stdio.h>
#include<string.h>
#include<math.h>
void sequence(int a[110][4],int x){
for(int i=0;i<x;i++){
    for(int j=i+1;j<x;j++){
        if(a[j][0]<a[i][0]){
            int b[4];
            for(int m=0;m<4;m++)
                {b[m]=a[i][m];
                a[i][m]=a[j][m];
                a[j][m]=b[m];}
        }
    }
}
}
//这个函数的目的是给二维数组排序，因为初始数据很乱但对数据顺序没有要求，不排序的话需要更多次循环,这里采用冒泡排序
int main()
{
int flat[110][4];
int n;//线段条数
int num,maxer=0;
int stop=0,xzb=0,yzb=0;
scanf("%d",&n);

for(int i=0;i<n;i++){
    for(int j=0;j<4;j++)
        scanf("%d",&flat[i][j]);
}

sequence(flat,n);//使用排序函数


for(int k=0;k<n;k++){
        stop=k;
        num=0;//清零操作是重中之重！！！！
   for(int r=k+1;r<n;r++){
      if(flat[stop][2]==flat[r][0]&&flat[stop][3]==flat[r][1]){
          stop=r;//这个断点stop的意思是从已匹配的点接着向后找
          num++;
      }

    }
if(num>maxer){
    maxer=num;
    xzb=flat[k][0];
    yzb=flat[k][1];
}
}
printf("%d %d %d",maxer+1,xzb,yzb);



return 0;
}


