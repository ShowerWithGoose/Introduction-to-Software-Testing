#include<stdio.h>
int  main(){
	char c[BUFSIZ];
	int a[512]={0},i,p,q,r;
	gets(c);
	for(i=0,p=0;c[i]!='=';i++){
		if(c[i]==' ')
		continue;
		else if(c[i]>='0'&&c[i]<='9'){
		if(a[p]<0)
		p++;
			a[p]=a[p]*10+c[i]-'0';
		}
		else if(c[i]=='+')
		a[++p]=-1;
		else if(c[i]=='-')
		a[++p]=-2;
		else if(c[i]=='*')
		a[++p]=-3;
		else if(c[i]=='/')
		a[++p]=-4;
	}

	for(q=1;q<=p;)
	{
		if(a[q]==-3)
		{
			a[q-1]=a[q-1]*a[q+1];
			for(r=q;r<=p-2;r++)
				a[r]=a[r+2];
			p-=2;
		}
		else if(a[q]==-4)
		{
			a[q-1]=a[q-1]/a[q+1];
			for(r=q;r<=p-2;r++)
				a[r]=a[r+2];
			p-=2;
		}
		else
		q+=2;
	}
	for(q=1;q<=p;)
	{
		if(a[q]==-1)
		{
			a[q-1]=a[q-1]+a[q+1];
			for(r=q;r<=p-2;r++)
				a[r]=a[r+2];
			p-=2;
		}
		else if(a[q]==-2)
		{
			a[q-1]=a[q-1]-a[q+1];
			for(r=q;r<=p-2;r++)
				a[r]=a[r+2];
			p-=2;
		}
		else
		q+=2;
	}
	printf("%d",a[0]);
	return 0;
}

