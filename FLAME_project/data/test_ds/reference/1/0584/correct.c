#include<stdio.h>
 	#include<string.h>
 	int main(){
	    int i=0,j=0,k=0,len,len2;
 	    char in[200],out[200],temp[200]={0};
 	    gets(in);
 	    len=strlen(in);
 	    for(i=0;i<len;i++){
 	        if(in[i]=='-'&&in[i-1]>='a'&&in[i+1]<='z'){
 	            for(k=0;k<in[i+1]-in[i-1]-1;k++){
 	                temp[j]=in[i-1]+k+1;
	                j++;
	            }
	            i++;
            }
 	        if(in[i]=='-'&&in[i-1]>='A'&&in[i+1]<='Z'){
 	            for(k=0;k<in[i+1]-in[i-1]-1;k++){
 	                temp[j]=in[i-1]+k+1;
	                j++;
	            }
	            i++;
	        }
 	        if(in[i]=='-'&&in[i-1]>='0'&&in[i+1]<='9'){
 	            for(k=0;k<in[i+1]-in[i-1]-1;k++){
 	                temp[j]=in[i-1]+k+1;
 	                j++;
	            }
	            i++;
	        }
           temp[j]=in[i];
           j++;
	    }
	    len2=strlen(temp);
 	    for(i=0;i<len2;i++){
 	        printf("%c",temp[i]);
	    }
 	}

