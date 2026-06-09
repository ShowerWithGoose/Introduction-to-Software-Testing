#include<stdio.h>
#include<string.h>

int main()
{
	char x[105]={0};
	char xy[110]={0};
	gets(x);
	int i,j,k=0;
	int last,first;
	
	if(x[0]!='0'){//大于1
	xy[0]=x[0];
	xy[1]='.';
	for(i=1;x[i]!='.';i++)
	{
		xy[i+1]=x[i];
	}
		last=i;
	for(i+=1;x[i]!='\0';i++)
	{
		xy[i]=x[i];
	}
	
	}
	else{//小于1
	for(i=0,j=2;x[i]!='\0';i++)
	{
		if((x[i]!='0')&&(x[i]!='.'))
		break;
	}

		for(;x[i]!='\0';i++){
		k++;
		if(k==1){
			first=i;//小数点位移为i-1；
			xy[0]=x[i];
			if(x[i+1]!='\0')
			xy[1]='.';
		}
		else
		{
		xy[j++]=x[i];
		}
		}
	}

	


	for(i=0;i<strlen(xy);i++)
	printf("%c",xy[i]);
	if(x[0]=='0')
	printf("e-%d",first-1);
	else
	printf("e%d",last-1);
return 0;
}

