#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct calcul{
	int xs1,zs1,xs2,zs2;
}list[10086];
int i=0,j=0,k,t;
int M,D,len,temp;
char b,c;
char str1[1000][1000];
char str2[1000][1000];
int num1=0,num2=0,max;
void turn(){
	for(i=0;i<num1;i=i+2){
		list[k].xs1=atoi(str1[i]);
		list[k].zs1=atoi(str1[i+1]);
		k++;
	}
	k=0;
	for(i=0;i<num2;i=i+2){
		list[k].xs2=atoi(str2[i]);
		list[k].zs2=atoi(str2[i+1]);
		k++;
	}
}
int search(int n){
	for(i=0;i<num1;i++){
		if(n==list[i].zs1){
			return i;
		}
	}
	return -1;
}

int main(){
	while((c=getchar())!=EOF){  
        if(c!='\n'){
        	  if(c>='0'&&c<='9'){
             	str1[num1][j]=c;
        	    j++; 
              }
              else{ 
                str1[num1][j]='\0';
                num1++;
                j=0;
              }
        }
        if(c=='\n'){
        	num1++;
        	 j=0;
		    break;
        }
    }
    while((b=getchar())!=EOF){  
        if(b!='\n'){
        	  if(b>='0'&&b<='9'){
             	str2[num2][j]=b;
        	    j++; 
              }
              else{ 
                str2[num2][j]='\0';
                num2++;
                j=0;
              }
        }
        if(b=='\n'){
        	num2++;
		    break;
        }
    }
    turn();
    num1/=2;num2/=2;t=num1;
    for(i=0;i<(num1*(num2+1));i=i+num2+1){
        M=list[i].zs1;
	    D=list[i].xs1;
    	for(k=0;k<num2;k++){
		    for(j=t-1;j>=i;j--){
		    	list[j+1].zs1=list[j].zs1;
		    	list[j+1].xs1=list[j].xs1;
		    }
			t++;  
		    list[i].zs1=M+list[k].zs2;
		    list[i].xs1=D*list[k].xs2;
    	}
    } 
    for(i=1;i<num1*(num2+1);i++){
    	if((i-num2)%(num2+1)==0){
    		list[i].zs1=0;
    		list[i].xs1=0;
    		len++;
    	}
    }
    for(i=0;i<num1*(num2+1)-1;i++){
	    for(j=i+1;j<num1*(num2+1);j++){
		    if(list[j].zs1==list[i].zs1)	{
		    	list[i].xs1+=list[j].xs1;
		    	list[j].zs1=0;
		    	list[j].xs1=0;
		    }
    	}
    }
    for(i=0;i<num1*(num2+1)-1;i++){
	    for(j=i+1;j<num1*(num2+1);j++){
		    if(list[j].zs1 > list[i].zs1)	{
		    	temp = list[i].zs1;
			    list[i].zs1 = list[j].zs1;
		    	list[j].zs1 = temp;
		    	temp = list[i].xs1;
			    list[i].xs1 = list[j].xs1;
		    	list[j].xs1 = temp;
		    }
    	}
    }
 
	for(i=0;i<(num1*(num2+1));i++){
		if(list[i].xs1!=0)printf("%d %d ",list[i].xs1,list[i].zs1);
	}
	return 0;   
} 

