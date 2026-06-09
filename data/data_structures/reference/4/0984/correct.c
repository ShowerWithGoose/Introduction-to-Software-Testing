#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct vocabulary{
	int amount;
	char ch[50];
};
int main()
{
	char a[50],c[50],sh[50];
	struct vocabulary b[10000],t;
	int n=0,j,i,k;
	FILE *in;
	in=fopen("article.txt","r");
	for(j=0;j<10000;j++){
		b[j].ch[0]='\0';
		b[j].amount=0;
	}
	while(fscanf(in,"%s",c)!=EOF){
		int l,flag,sign;
		for(k=0;k<strlen(c);){
		flag=0,sign=0;
		j=0;
		for(;k<strlen(c);k++){
			if(c[k]>='a'&&c[k]<='z'||c[k]>='A'&&c[k]<='Z')
			{
			  sign=1;
			  a[j]=c[k];
			  j++;
			}
			else
			{
				if(sign==1)
				  break;
			}
		}
		a[j]='\0';
		l=strlen(a);  
		if(l==0)
		  break;
		for(j=0;j<l;j++){
			if(a[j]>=65&&a[j]<=90)
			  {
				a[j]=a[j]+32;
			  }
		}
		if(n==0)
		{
			strcpy(b[n].ch,a);
			n++;
		}
		for(j=0;j<n;j++){
			if(strcmp(a,b[j].ch)==0)
			{
				b[j].amount++;
				flag=1;
				break;
			}
		}
		if(flag==0){
		   strcpy(b[n].ch,a);
		   b[n].amount++;
		   n=n+1;
	    }
	    for(i=0;i<50;i++){
	    	a[i]='\0';
		}
		}
	} 
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(strcmp(b[j].ch,b[j+1].ch)>0){
				t=b[j+1];
				b[j+1]=b[j];
				b[j]=t;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%s %d\n",b[i].ch,b[i].amount);
	}
	fclose(in); 
	return 0;
}

