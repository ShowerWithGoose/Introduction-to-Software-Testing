#include<stdio.h>
int main()
{
	char a[10000],b[10000];
	scanf("%s",a);
	int i=0,j=i,m=0;
	for(i=0;a[i]!='\0';i++,j++){
		b[j]=a[i];
		if(a[i+1]=='-'&&((a[i]>='0'&&a[i]<='9')&&(a[i+2]>='0'&&a[i+2]<='9')||(a[i]>='a'&&a[i]<='z')&&(a[i+2]>='a'&&a[i+2]<='z')||(a[i]>='A'&&a[i]<='Z')&&(a[i+2]>='A'&&a[i+2]<='Z'))&&a[i]<a[i+2]){
			m=a[i+2]-a[i];
			for(int k=1;k<m;k++){
				b[++j]=a[i]+k;
			}
			i++;
		}
	}
	b[j+1]='\0';
	printf("%s\n",b);
	return 0;
}

