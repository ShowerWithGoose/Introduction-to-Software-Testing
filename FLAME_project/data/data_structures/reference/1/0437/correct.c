#include<stdio.h>
int i,z,j,amount;
int factorialnum[11];
int output[10];

void find()
{
    int i; 
    for(i=amount-2;i>-1;i--)
	{ 
        if(output[i]<output[i+1])
        {
        	break;
		}
    }
    int t=i,temp_low=i+1,temp;
    for(i=t+1;i<amount;i++)
	{   
        if(output[i]>output[t]&&output[i]<output[temp_low])
        {
        	temp_low=i;
		}
    }
    temp=output[temp_low];
    output[temp_low]=output[t];
    output[t]=temp;
    for(j=t+1,i=amount-1;i>j;i--,j++)
	{
        temp=output[i];
        output[i]=output[j];
        output[j]=temp;
    }
}

int scanf1() 
{
	scanf("%d",&amount);
	return amount;
} 

void out(int k)
{
	int i=0;
	while(i<k)
	{ 
        output[i]=i+1;
        i++;
    }
}

void pr()
{
	printf("\n");
}

void pr1(int z)
{
	printf("%d ",output[z]);
}

int main(){ 
    factorialnum[0]=1;
    for(i=1;i<10;i++)
	{
        factorialnum[i]=i*factorialnum[i-1];
    }
    amount=scanf1();
    out(amount);
    for(i=0;i<amount;i++)
    {
    	pr1(i);
	}
    pr();
    for(i=1;i<factorialnum[amount];i++)
	{ 
        find();
        for(z=0;z<amount;z++)
        {
    	    pr1(z);
	    }
	    pr();
    }
}

