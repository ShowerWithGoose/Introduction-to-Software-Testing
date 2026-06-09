#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int N,i,a[1024]={0};
	char s[1024]={'0'};
	scanf("%d",&N);
	for(i=0;i<N;i++){
		s[i]=i+1+'0';
		a[i]=i+1;
	}
	qpl(s,0,N-1);
	return 0;
	
}
void swap(char *a,char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}
void  qpl(char *s,int j,int n)
{
	int i,k,a[1024]={'0'},l;
	char c;
	if(j==n)
	{
		int i=1;
		for(k=0;k<=n;k++){
			a[k]=s[k]-'0';
			printf("%d ",a[k]);
		}
		printf("\n");
	}
	else
    {
    	for(i=j;i<=n;i++)
		{
			
			for(k=j;k<=n-1;k++){
   				for(l=j;l<=n-1;l++){
				   	if(s[l]>s[l+1]){
    					c = s[l];
    					s[l] = s[l+1];
    					s[l+1] = c;
   					}
   				}
 			}
			swap(s+i,s+j);
			qpl(s,j+1,n);
			swap(s+i,s+j);
		}
	}
}




