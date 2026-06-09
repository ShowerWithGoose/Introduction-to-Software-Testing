#include<stdio.h>
int n;
int flag[12];
int str[12];
void p();
void f();
int main(){
    int i,j,k;
    flag[0]=1;
    for(j=1;j<=11;j++)
    {
    	flag[j]=1;
    	for(k=1;k<=j;k++)
    	flag[j]=flag[j]*k;
	}
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        str[i-1]=i;
    }
    p();
    for(i=1;i<flag[n];i++){
        f();
        p();
    }
}
void p()
{
    int i=0;
    for(i=0;i<=n-1;i++)
        {
        	if(i!=n-1)
        	printf("%d ",str[i]);
        	else
        	printf("%d\n",str[i]);
		}
}
void f()
{
	int i,j,k,t,t1;
    for(i=n-2;i>=0;i--)
	{
        if(str[i]<str[i+1])
           {
           	k=i;
           	t=i+1;
			break;
			} 
    }
    for(i=k+1;i<n;i++)
	{
        if(str[i]>str[k]&&str[i]<str[t])
        t=i;
    }
    t1=str[t];
    str[t]=str[k];
    str[k]=t1;
    for(j=k+1,i=n-1;i>j;i--,j++){
        t1=str[i];
        str[i]=str[j];
        str[j]=t1;
    }
}

