#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
    char a[500],b[500];
    scanf("%s",a);
    int i=0,j=0,k=0,m=0,z=0,n=strlen(a);
    while(i<n+1){
    	if(a[i]=='-'&&((a[i-1]-'a'>=0&&a[i-1]-'z'<=0&&a[i+1]-'a'>=0&&a[i+1]-'z'<=0)||(a[i-1]-'A'>=0&&a[i-1]-'Z'<=0&&a[i+1]-'A'>=0&&a[i+1]-'Z'<=0)||(a[i-1]-'0'>=0&&a[i-1]-'9'<=0&&a[i+1]-'0'>=0&&a[i+1]-'9'<=0))&&a[i+1]-a[i-1]>0)
    	{
    		k=a[i+1]-a[i-1]-1;
    		for(;j-i-m<k;j++){
    			b[j]=a[i-1]+j-i-m+1;
			}
			m+=k-1;
			i++;
			j--;
			if(a[i+1]-a[i-1]==1) n--; 
	}
	else {
	b[j]=a[i];
	i++;
}
j++;
	}
	printf("%s",b);
}
	




