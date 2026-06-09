#include<stdio.h>
void Swap(int a[], int i, int j);
int main()
{
 int n,i,j;
 int temp,p=0;
 int x1[100],y1[100],x2[100],y2[100];
 int m,k;
 int a[100],b[100]={0},c[100];
 scanf("%d",&n);
 while( scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i])!=EOF)
 {
 	i++;
 }
 for (i = 0; i < n; i++)
  {
        for (j=0;j<n-i-1; j++) 
		{
            if (x1[j]>x1[j + 1])
			 {
                Swap(x1,j,j+1);
           Swap(x2,j,j+1);
           Swap(y1,j,j+1);
          Swap(y2,j,j+1);
            }
        }
    }
    for(i=0;i<n;i++)
    {
     m=x2[i];
     k=y2[i];
     a[p]=x1[i];
     c[p]=y1[i];
  for(j=i+1;j<n;j++)
     {
      if(m==x1[j]&&k==y1[j])
      {
       m=x2[j];
       k=y2[j];
       b[p]++;
   }
  }
  p++;
 }
 for (i = 0; i < n; i++) 
 {
        for (j = 0; j<n-i-1; j++) 
		{
            if (b[j] < b[j + 1]) 
			{
				Swap(a,j,j+1);
				Swap(b,j,j+1);
				Swap(c,j,j+1);
            }
        }
    }
    printf("%d %d %d",b[0]+1,a[0],c[0]);
    return 0;
}

void Swap(int a[], int i, int j)
 {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

