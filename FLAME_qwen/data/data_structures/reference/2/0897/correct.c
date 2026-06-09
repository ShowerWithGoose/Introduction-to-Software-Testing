#include<stdio.h>
#include<math.h>
#include<string.h>
char s[105];
int sign[100][2];
int ssum,sum,lsum,nsum;
int num[100][2];
int main(){
	gets(s);
	int len =strlen(s);
	int i,j,k;
	for(i=0;i<len;i++){
		if(s[i]==' '){
		for(j=i;j<len-1;j++){
			s[j]=s[j+1];
		}
		i--;
		len--;
		}
	}
	len--;
	
	
	
	for(i=0,j=0;i<len;i++){
	   if(s[i]=='+'){
	   	sign[j][0]=1;
	   	sign[j][1]=1;
	   	j++;
	   }
	   if(s[i]=='-'){
	   	sign[j][0]=1;
	   	sign[j][1]=2;
	   	j++;
	   }
	   if(s[i]=='*'){
	   	sign[j][0]=1;
	   	sign[j][1]=3;
	   	j++;
	   }
	   if(s[i]=='/'){
	   	sign[j][0]=1;
	   	sign[j][1]=4;
	   	j++;
	   }
	}
	ssum=j;
	
	
	k=0;
	for(i=0,j=0;i<len;i++){
		lsum=0;
		lsum=s[i]-'0';
		for(i++;s[i]-'0'>=0&&s[i]-'0'<=9 ;i++){
		   lsum=lsum*10+(s[i]-'0');	
		}
	    num[k][1]=lsum;
	    num[k][0]=1;
	    k++;
	    i+=j;
	}

	
	
	
    i=0;
	for(i=0,j=0;i<ssum;i++){
		if(sign[i][1]==3){
			num[i+1][1]=num[i][1]*num[i+1][1];
			num[i][0]=0;
			sign[i][0]=0;
			j++;
		}
		if(sign[i][1]==4){
			num[i+1][1]=num[i][1]/num[i+1][1];
			num[i][0]=0;
			sign[i][0]=0;
			j++;
		}
	}
	for(i=0;num[i][0]==0;i++){
	}
	sum=num[i][1];
	num[i][0]=0;

	
	
	
	
	for(i=0,j=0;i<ssum;i++){
		if(sign[i][1]==1){
		for(j=1;num[j][0]==0;j++){
		
		}
		sum+=num[j][1];
		num[j][0]=0;
		}
		
		if(sign[i][1]==2){
		for(j=1;num[j][0]==0;j++){
		
		}
		sum-=num[j][1];
		num[j][0]=0;
		}
	}
				
				printf("%d",sum);
	
	
	
	
	
    
		
	
	return 0;
}

