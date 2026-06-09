#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[10010];
struct word{
	char spell[130];
	int num;
};
struct word a[8888];
int main()
{
	int n=0,k,l,flag;
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(s,10009,in)!=NULL){
		int len=strlen(s);
		int i,j;
		char b[130];
		for(i=0;i<len;i++){
			if(s[i]>='A'&&s[i]<='Z')
				s[i]=s[i]-'A'+'a';
		}
		for(i=0;i<len;i++){
			if(s[i]>='a'&&s[i]<='z')
			{
				memset(b,0,sizeof(b));
				for(j=0;s[i+j]>='a'&&s[i+j]<='z'&&s[i+j]!='\0';j++){
					b[j]=s[i+j];
				}
				b[j]='\0';
				flag=0;
				for(k=0;k<n;k++){
					if(strcmp(a[k].spell,b)==0)
					{
						a[k].num++;
						flag=1;
						break;
					}						
				}
				if(flag==0)
				{
					strcpy(a[n].spell,b);
					a[n].num=1;
					n++;
				}
				i+=j;
			}
		}
	}
	struct word temp;
	for(k=0;k<n-1;k++){
		flag=0;
		for(l=0;l<n-1-k;l++){
			if(strcmp(a[l].spell,a[l+1].spell)>0)
			{
				temp=a[l];
				a[l]=a[l+1];
				a[l+1]=temp;
				flag=1;
			}
		}
		if(flag==0)	
			break;
	}
	for(k=0;k<n;k++){
		printf("%s %d\n",a[k].spell,a[k].num);
	}	
	fclose(in);
	return 0;
}



