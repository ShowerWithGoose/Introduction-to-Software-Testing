#include<stdio.h>
#include<string.h>

int main()
{
	char a[1000],b[1000];
	scanf("%s",a);
	printf("%c",a[0]);
	int i=0,ib=0;
	int j,p;
	int len=strlen(a);
	while(i<=len-1){
		if(a[i]=='-'){
			if((a[i-1]>='0' && a[i-1]<='9' && a[i+1]>='0' && a[i+1]<='9' && a[i-1]<a[i+1]) || (a[i-1]>='a' && a[i-1]<='z' && a[i+1]>='a' && a[i+1]<='z' && a[i-1]<a[i+1]) || (a[i-1]>='A' && a[i-1]<='Z' && a[i+1]>='A' && a[i+1]<='Z' && a[i-1]<a[i+1])){
				int det=a[i+1]-a[i-1];
				for(j=1;j<det;j++){
					b[ib-1+j]=a[i-1]+j;
				}
				i+=1;
				ib+=det-1;
			}
			else{
				b[ib]=a[i];
				i++;
				ib++;
			}
		}
		else{
			b[ib]=a[i];
			i++;
			ib++;
		}
	}
	b[ib]='\0';
	int len2=strlen(b); 
	for(p=1;p<len2;p++){
		printf("%c",b[p]);
	}
	return 0;
}



