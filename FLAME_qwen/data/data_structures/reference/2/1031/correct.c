#include<stdio.h>
#include<string.h>
int main(){
	int a[10000],sum=0;
	char s[10000];
	int i=0,j=0,k=0;
	while(1){
		if(i%2==0){
			scanf(" %d",&a[j++]);
		}else{
			scanf(" %c",&s[k++]);
			if(s[k-1]=='='){
				break;
			}
		}
		i++;
	}
	int len1=j,len2=k,sign=1;
	for(k=0,j=0;k<len2;k++){
		if(s[k]=='+'||s[k]=='-'){
			sum+=sign*a[j++];
			if(s[k]=='+'){
				sign=1;
			}else{
				sign=-1;
			}
		}else{
			if(s[k]=='*'){
				a[j+1]=a[j]*a[j+1];
				j++;
			}else if(s[k]=='/'){
				a[j+1]=a[j]/a[j+1];
				j++;
			}
		}
	}
	sum+=sign*a[j];
	printf("%d",sum);
	return 0;
}



