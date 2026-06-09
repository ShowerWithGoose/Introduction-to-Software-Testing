#include<stdio.h>
int main(){
int n;
int a[10]={0},m[11]={0};
scanf("%d",&n);
m[0]=1;
for(int y=1;y<10;y++){
m[y]=y*m[y-1];
}
int i=0;
for(;i<n;i++)
a[i]=i+1;
for(i=0;i<n-1;i++)
printf("%d ",a[i]);
printf("%d\n",a[i]);
for(int p=1;p<m[n];p++){
for(i=n-2;i>=0;i--){
if(a[i]<a[i+1])
break;
}
int k=i;
int t=i+1;
for(i=k+1;i<n;i++){
if(a[i]>a[k]&&a[i]<a[t])
t=i;
}
int t1;
int j=0;
t1=a[k];
a[k]=a[t];
a[t]=t1;
for(j=k+1,i=n-1;i>j;i--,j++){
t1=a[i];
a[i]=a[j];
a[j]=t1;
}
for(i=0;i<n-1;i++)
printf("%d ",a[i]);
printf("%d\n",a[i]);
}
return 0;
}

