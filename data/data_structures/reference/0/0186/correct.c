#include<stdio.h>
#include<string.h>

int main(){
	int i,j,k;
    char c[100000],d[100000];
    gets(c);
    for(i=0,j=0;i<strlen(c);i++){
    	k=1;
    	if(c[i]=='-'&&c[i-1]<c[i+1]){
    		if(c[i-1]>='0'&&c[i+1]<='9'){
    			do{
    				d[j]=c[i-1]+k;
    				k++;
				}while(d[j++]!=c[i+1]-1);
			}
			else if(c[i-1]>='a'&&c[i+1]<='z'){
    			do{
    				d[j]=c[i-1]+k;
    				k++;
				}while(d[j++]!=c[i+1]-1);
			}
			else if(c[i-1]>='A'&&c[i+1]<='Z'){
    			do{
    				d[j]=c[i-1]+k;
    				k++;
				}while(d[j++]!=c[i+1]-1);
			}
			else d[j++]=c[i];
		}
		else{
			d[j++]=c[i];
		}
	}
	puts(d);
	return 0;
}



