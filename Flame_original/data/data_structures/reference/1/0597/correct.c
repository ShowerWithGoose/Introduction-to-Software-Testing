#include<stdio.h>
int n;
int jc[12];
int op[12];
void p();
void f();
int main(){
    int i,j,k;
    jc[0]=1;
    for(j=1;j<=11;j++)
    {
    	jc[j]=1;
    	for(k=1;k<=j;k++)
    	jc[j]=jc[j]*k;
	}
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        op[i-1]=i;
    }
    p();
    for(i=1;i<jc[n];i++){
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
        	printf("%d ",op[i]);
        	else
        	printf("%d\n",op[i]);
		}
}
void f()
{
	int i,j,k,t,t1;
    for(i=n-2;i>=0;i--)
	{
        if(op[i]<op[i+1])
           {
           	k=i;
           	t=i+1;
			break;
			} 
    }
    for(i=k+1;i<n;i++)
	{
        if(op[i]>op[k]&&op[i]<op[t])
        t=i;
    }
    t1=op[t];
    op[t]=op[k];
    op[k]=t1;
    for(j=k+1,i=n-1;i>j;i--,j++){
        t1=op[i];
        op[i]=op[j];
        op[j]=t1;
    }
}

