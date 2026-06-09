#include<stdio.h>
#include<string.h>
int n1[200][2],count=0,num[200];
int main(){
	char ch1[100],ch2[100];
	gets(ch1);
	int j=0,k=1;
	for(int i=0;i<strlen(ch1)-1;i++){
		if(ch1[i]==' ')
			continue;
		else
			ch2[j++]=ch1[i];
		if(ch2[j-1]=='+'){
			count++;
			n1[count][0]=j-1;
			n1[count][1]=0;
		}
		if(ch2[j-1]=='-'){
			count++;
			n1[count][0]=j-1;
			n1[count][1]=1;
		}
		if(ch2[j-1]=='*'){
			count++;
			n1[count][0]=j-1;
			n1[count][1]=2;
		}
		if(ch2[j-1]=='/'){
			count++;
			n1[count][0]=j-1;
			n1[count][1]=3;
		}
	}
	
	if(count==0){
		puts(ch2);
		return 0;
	}
	
	for(int i=0;i<n1[1][0];i++)
		num[k]=10*num[k]+ch2[i]-'0';
	k++;
	for(int i=1;i<count;i++){
		for(int m=n1[i][0]+1;m<n1[i+1][0];m++){
			num[k]=10*num[k]+ch2[m]-'0';
		}
		k++;
	}
	for(int i=n1[count][0]+1;i<j;i++)
		num[k]=10*num[k]+ch2[i]-'0';
	
	for(int i=1;i<=count;i++){
		if(n1[i][1]==2){
			num[i+1]=num[i]*num[i+1];
			num[i]=0;
			n1[i][1]=0;
		}
		if(n1[i][1]==3){
			num[i+1]=num[i]/num[i+1];
			num[i]=0;
			n1[i][1]=0;
		}
	}
	
	for(int i=1;i<=count;i++){
		if(n1[i][1]==0){
			num[i+1]=num[i]+num[i+1];
			num[i]=0;
		}
		if(n1[i][1]==1){
			int temp=num[i+1];
			num[i+1]=num[i]-num[i+1];
			num[i]=0;
			if(temp==0&&n1[i+1][1]==0)
				n1[i+1][1]=1;
		}
	}
	
	printf("%d",num[count+1]);
	return 0;
}

