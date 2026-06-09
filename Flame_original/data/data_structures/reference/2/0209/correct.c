#include<stdio.h>
char num_string[500],num_string_count;
	int num_store[500],num_count;
	int num_sum[500],num_sum_count;
	int char_store[500],char_count;
	char input[5000];
	int  input_count;
	int sum,sum_flag;
	int i,j,k;
int main()
{
	
	
	gets(input);
	if(input[0]=='-')
	{
		num_sum[0]=-1;
		char_count=-1;
	}
	else
	num_sum[0]=1;
	for(input_count=0;input[input_count]!='\0';input_count++)
	{
		if(input[input_count]>='0'&&input[input_count]<='9')
		{
			for(num_string_count=0;;num_string_count++)
			{
				if(input[input_count]>='0'&&input[input_count]<='9')
				num_string[num_string_count]=input[input_count++];
				else
				{
					input_count--;
				    break;
				}
			}
			num_string[num_string_count]='\0';
			sscanf(num_string,"%d",&num_store[num_count++]);
		}
		else
		switch (input[input_count])
		{
			case '+':char_store[char_count++]=1;break;
			case '-':char_store[char_count++]=2;break;
			case '*':char_store[char_count++]=3;break;
			case '/':char_store[char_count++]=4;break;
			case '=':char_store[char_count++]=5;break;
			default : break;
		}
		
	}
	
	for(i=0;i<char_count;i++)
	{   if(i==0)
		num_sum[num_sum_count]*=num_store[i];
		if(char_store[i]==1||char_store[i]==2||char_store[i]==5)
		{
			
			if(char_store[i]==1)
			num_sum[++num_sum_count]=1*num_store[i+1];
			else
			num_sum[++num_sum_count]=-1*num_store[i+1];
		}
		else
		{
			if(char_store[i]==3)
			num_sum[num_sum_count]*=num_store[i+1];
			else
			num_sum[num_sum_count]/=num_store[i+1];
		}
	
		
	}
	
	
	
	for(num_sum_count;num_sum_count>=0;num_sum_count--)
	sum+=num_sum[num_sum_count];
	printf("%d",sum);
	
}

