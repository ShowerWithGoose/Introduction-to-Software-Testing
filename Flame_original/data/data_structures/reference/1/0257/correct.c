#include<stdio.h>
long long int x(int n)
{   int i,sum=1;
    if(n==1) return 1;
	else 
	for(i=1;i<=n;i++)
	{sum*=i;}
	return sum;}
	void y(int *a,int n)
{
	int i,j;
	for(i=n-2;i>=0;i--)
	{	if(a[i]<a[i+1])
		break;}
	int k=i,p=i+1;
	for(i=k+1;i<n;i++)
	{	if(a[i]<a[p]&&a[i]>a[k])
		p=i;}
	int zjz;
	zjz=a[k];
	a[k]=a[p];
	a[p]=zjz;
	for(i=k+1,j=n-1;i<j;i++,j--)
	{	zjz=a[i];
		a[i]=a[j];
		a[j]=zjz;}}
void z(int *a,int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
	 printf("%d ",a[i]);}
	 printf("%d\n",a[i]);}

int main()
{
	int a[10];
	int n,j;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=i+1;}
	    z(a,n);
	    j=x(n);
	for(i=1;i<j;i++)

	{	y(a,n);
		z(a,n);}
	return 0;} 


