#include<stdio.h>
#include<string.h>
#include<ctype.h>
void Swap(int a[], int i, int j);
struct first{
 int a[100];
 int x[100];
}first;

struct second{
 int a[100];
 int x[100];
}second;

struct third{
 int a[100];
 int x[100];
}third;
int main()
{
 int i=0,j=0,k=0;
 int n=0,m=0;
 char c;
  while(c!='\n')
 {
  scanf("%d%d",&first.a[i],&first.x[i]);
  i++;
  n++;
  c=getchar();
 }
 i=0;
  while(scanf("%d%d",&second.a[i],&second.x[i])!=EOF)
 {
  i++;
  m++;
 }
 
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
  third.a[k]=first.a[i] * second.a[j];
   k++;
  }
 }
 k=0;//求系数 
 
  for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   third.x[k]=first.x[i] + second.x[j];
   k++;
  }
 }//求次方 
 
 for(i=0;i<k;i++)
 {
  for(j=i+1;j<k;j++)
  {
   if(third.a[i]!=0&&third.a[j]!=0)
   {
    if(third.x[i]==third.x[j])
    {
    third.a[i]=third.a[j]+third.a[i];
     third.a[j]=0;
    }
   }
  }
 }
 //合并同类项 
 
 int temp;
 for (i = 0; i < k; i++) {
        for (j = 0; j + 1 < k - i; j++) {
            if (third.x[j] < third.x[j+1]) {
                temp=third.x[j];
                third.x[j]=third.x[j+1];
                third.x[j+1]=temp;
                temp=third.a[j];
                third.a[j]=third.a[j+1];
               third.a[j+1]=temp;
            }
        }
    }
    //排序
	 
    for(i=0;i<k;i++)
    {
     if(third.a[i]!=0)
     {
      printf("%d %d ",third.a[i],third.x[i]);
  }
 }
 return 0;
}


void Swap(int a[], int i, int j)
 {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

