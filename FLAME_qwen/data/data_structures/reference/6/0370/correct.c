#include<stdio.h>
int main(){
	int s[100],a[2000],i,n;
	int top=-1;
	for(i=0;;i++){
		scanf("%d",&a[i]);
		if(a[i]==-1){
			break;
		}
	}
	n=i;
	for(i=0;i<=n;i++){
		if(a[i]==-1){
			break;
		}
		else if(a[i]==1){
			if(top==99) printf("error ");
			else{
				i++;
				s[++top]=a[i];
			}
		}
		else if(a[i]==0){
			if(top==-1) printf("error ");
			else{
				printf("%d ",s[top--]);
			}
		}
	}
	return 0;
}

