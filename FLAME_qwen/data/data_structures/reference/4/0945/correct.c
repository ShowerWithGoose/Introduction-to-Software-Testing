#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char *mes[3000],a[3000][100],c,*temp,t;
int n[3000]={0};


int main(){
	
	FILE *fr;
	fr=fopen("article.txt","r");
	
	int i=0,j=0,flag,k,l,f1,f2;
	for(i=0;i<3000;i++)
	mes[i]=a[i];
	
	i=0;
	 
	while((c=fgetc(fr))!=EOF){
	if((c>=65&&c<=90)||(c>=97&&c<=122)){
		if(c<=90){
			c+=32;
		}
		*(mes[i]+j)=c;
		j++;
	}
	else{
		if(*mes[i]>=97&&*mes[i]<=122){
			n[i]++;
			for(k=0;k<i;k++){
				if(strcmp(mes[k],mes[i])==0){
					memset(mes[i],0,j);
					n[i]=0;
					i--;
					n[k]++;
					break;
				}
			}
			i++;
			j=0;
		}
	}
	}
	fclose(fr);
	
	if(*mes[i]>=97&&*mes[i]<=122){
			n[i]++;
			for(j=0;j<i;j++){
				if(strcmp(mes[j],mes[i])==0){
					memset(mes[i],0,sizeof(mes[i]));
					n[i]=0;
					i--;
					n[j]++;
					break;
				}
			}
			i++;
			j=0;
		}
	
	for(k=0;k<i-1;k++){
		flag=0;
		for(j=0;j<i-1-k;j++){
			
			if(*mes[j]>*mes[j+1]){
				temp=mes[j+1];
				mes[j+1]=mes[j];
				mes[j]=temp;
				flag=1;
				t=n[j+1];
				n[j+1]=n[j];
				n[j]=t;
			}
			if(*mes[j]==*mes[j+1]){ 
				for(l=0;(*(mes[j]+l)!='\0'||*(mes[j+1]+l)!='\0')&&*(mes[j]+l)>=*(mes[j+1]+l);l++){
				
					if(*(mes[j]+l)>*(mes[j+1]+l)){
						temp=mes[j+1];
						mes[j+1]=mes[j];
						mes[j]=temp;
						flag=1;
						t=n[j+1];
						n[j+1]=n[j];
						n[j]=t;
						break;
					}
				}
			}
		}
		if(!flag)
		break;
	}
	
	for(j=0;j<i;j++){
		printf("%s %d\n",mes[j],n[j]);
	}
	
	return 0;
}


