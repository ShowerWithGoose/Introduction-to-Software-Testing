#include<stdio.h>
int main()
{
	char a[101],b[101];
	scanf("%s",a);
	int i=0,j=0,k;
	while(a[i]!='\0'){
		if(a[i]!='-'){
			b[j]=a[i];
			i++;
			j++;
		}
		else if((a[i-1]>47&&a[i-1]<58&&a[i+1]>47&&a[i+1]<58&&a[i-1]<a[i+1])||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])){
			for(k=1;(a[i+1]-a[i-1])>k;k++){
				b[j++]=a[i-1]+k;
			}
			i++;
		}
		else{
			b[j++]=a[i++];
		}
	}
	b[j]='\0';
	printf("%s",b);
	return 0;
}



