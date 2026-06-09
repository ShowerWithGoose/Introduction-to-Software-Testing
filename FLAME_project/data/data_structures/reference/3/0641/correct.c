#include<stdio.h>
int fuhao(char *a) {
	if(a[0]=='0')
	return 0;
	return 1;
}
char a[105],b[200];
int main()
{
	int i=0,k,count,flag,j=0,flag2;
	gets(a);
	int d=strlen(a);
	if(fuhao(a)){
	b[j++]=a[i++];
	b[j++]='.';
	for(i=1;i<d;i++){
		if(a[i]=='.'){
		flag=i;
		continue;
	}
		else
		b[j++]=a[i];
	}
	count=flag-1;
printf("%se%d",b,count);
	
	}
	else
	{
		for(i=0;i<d;i++){
		if(a[i]=='.')
		flag=i;
		else
		{
			if(a[i]!='0')
		{
				flag2=i;
			break;}
		}
	}

	if(flag2==d-1)
	{
	b[j++]=a[i];
	
	count=flag2-flag;
}
else
{
	b[j++]=a[flag2];
	b[j++]='.';
	for(i=flag2+1;i<d;i++){
		b[j++]=a[i];
	}
	count=flag2-flag;
}printf("%se%d",b,-count);
}
	
	return 0;	
}


