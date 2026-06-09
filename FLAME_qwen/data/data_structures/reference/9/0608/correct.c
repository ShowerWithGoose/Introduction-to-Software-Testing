#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
void bubble(int a[], int b[],int c[],int d[],int n);

int main()
{

int n,i,j,k,longest=1,length=1,head,top,x1[105],x2[105],y1[105],y2[105];
scanf("%d",&n);
for (i=0;i<n;i++){
	scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
}

bubble(x1,y1,x2,y2,n);

for (i=n-1;i>0;i--){
	j=i-1,k=i,length=1;
	while (j>=0){
		if (x1[k]==x2[j]&&y1[k]==y2[j]){
			length++;
			head=j;
			k=j,j--;
			
		}
		else{
			j--;
		}
	}
	if (length>longest)
	longest=length , top=head;
}
printf("%d %d %d",longest,x1[top],y1[top]);
return 0; 
}

void bubble(int a[], int b[],int c[],int d[],int n)
{
int i, j, hold, hold2,hold3,hold4,flag;
for (i = 0; i < n-1; i++)
{
flag = 0;
for (j = 0; j < n-1-i; j++)
{
if (a[j] > a[j + 1])
{
hold = a[j];
a[j] = a[j + 1];
a[j + 1] = hold;
hold2 = b[j];
b[j] = b[j + 1];
b[j + 1] = hold2;
hold3 = c[j];
c[j] = c[j + 1];
c[j + 1] = hold3;
hold4 = d[j];
d[j] = d[j + 1];
d[j + 1] = hold4;
flag = 1;
}
}
if (0 == flag)
break;
}
}






