#include<stdio.h>
#include<string.h>

int a[5000];
int b[5000];

struct num1{
	int a1;
	int n1;
};

struct num2{
	int a2;
	int n2;
};

void bubbleSort(int b[], int n)   // n¸öÊı £¬ 0 ~ n-1 
{
	int i, j, hold, flag;
	for (i = 0; i < n-1; i++)
	{
		flag = 0;
		for (j = 0; j < n-1-i; j++)
		{
			if (b[j] < b[j + 1])
			{
				hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
				
				hold = b[j];
				b[j] = b[j + 1];
				b[j + 1] = hold;
				
				flag = 1;
			}
		}
		if (0 == flag)
		break;
	}
}


int main()
{
	int i,j,k,t1,t2,t;
	char flag;
	
	struct num1 s1[100];
	struct num2 s2[100];
	
	i=0;
	while(1)
	{
		i++;
		scanf("%d %d%c",&s1[i].a1 ,&s1[i].n1 ,&flag);
		
		if(flag == '\n')
		{
			t1=i;
			break;
		}
	}
	
	i=0;
	while(1)
	{
		i++;
		scanf("%d %d%c",&s2[i].a2 ,&s2[i].n2 ,&flag);
		
		if(flag == '\n')
		{
			t2=i;
			break;
		}
	}
	
	k=s1[1].n1 + s2[1].n2 ;
	
	int val=0;
	int h;
	for(i=1;i<=t1;i++)
	{
		for(j=1;j<=t2;j++)
		{
			h=0;
			t=s1[i].n1 + s2[j].n2 ;
			for(k=0; k<val; k++)
			{
				if(b[k] == t)
				{
					a[k] = a[k] + s1[i].a1 * s2[j].a2 ;
					h=1;
					break;
				}
			}
			if(h == 0){
				a[val] = a[val] + s1[i].a1 * s2[j].a2 ;
				b[val] = t ;
				val++;
			}
		}
	}
	
	bubbleSort(b, val);
	
	for(i=0 ; i<val ; i++)
	{
		printf("%d %d ",a[i],b[i]);
	}
	
	
	
	return 0;
}


