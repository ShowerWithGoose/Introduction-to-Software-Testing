#include<stdio.h>
#include<string.h> 

struct data1{
	int base;
	int index;
}data1[100];

struct data2{
	int base;
	int index;
}data2[100];

struct cons{
	int base;
	int index;
	int flag;
}cons[200];

int i=0;

int main(){
    
    int k,j,u,n=0,temp,tt;
    char c;
    
	scanf("%d %d",&data1[i].base,&data1[i].index);i++;
    scanf("%c",&c);
    while(c!='\n'){
    	scanf("%d %d",&data1[i].base,&data1[i].index);i++;
    	scanf("%c",&c);
	}
	k=i;
	
	i=0;
	scanf("%d %d",&data2[i].base,&data2[i].index);i++;
	scanf("%c",&c);
	while(c!='\n'){
    	scanf("%d %d",&data2[i].base,&data2[i].index);i++;
    	scanf("%c",&c);
	}
	j=i;
	
	for(i=0;i<k;i++){
		for(u=0;u<j;u++){
			cons[n].base=data1[i].base*data2[u].base;
			cons[n].index=data1[i].index+data2[u].index;
			n++;
		}
	} 
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(cons[j].index<cons[j+1].index){
				temp=cons[j+1].index;
				cons[j+1].index=cons[j].index;
				cons[j].index=temp;
				tt=cons[j+1].base;
				cons[j+1].base=cons[j].base;
				cons[j].base=tt;
			}
		}
	}
	
	cons[0].flag=0;
	for(i=0;i<n;i++){
		for(j=1;i+j<n;j++){
			if(cons[i].index==cons[i+j].index){
				cons[i].base=cons[i].base+cons[i+j].base;
				cons[i+j].flag=1;
			}
			else{
				cons[i+j].flag=0;
			}
		}
	}
	
	for(i=0;i<n;i++){
		if(cons[i].flag!=1)
	  printf("%d %d ",cons[i].base,cons[i].index);
	}
}

