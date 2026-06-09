#include<stdio.h>
#include<string.h>

int n,i,j;
char ch[10000];
long long x[10000];
int next[10000],len[10000];


int main(){
	for(i=0;ch[i-1]!='=';i++){
		scanf("%lld %c",&x[i],&ch[i]);
		len[ch[i]]++;
		next[i]=i+1;
	}
	n=next[i-1];
	while(len['+']!=0||len['-']!=0||len['*']!=0||len['/']!=0){
		if(len['*']!=0||len['/']!=0){
			for(i=0;i<n;i=next[i]){
				if(ch[i]=='*'||ch[i]=='/'){
					j=next[i];break;
				}
			}if(ch[i]=='*'){
					x[i]*=x[j];
					ch[i]=ch[j];
					next[i]=next[j];
					len['*']--;
			}else{
					x[i]/=x[j];
					ch[i]=ch[j];
					next[i]=next[j];
					len['/']--;
			}
		}else{
			for(i=0;i<n;i=next[i]){
				if(ch[i]=='+'||ch[i]=='-'){
					j=next[i];break;
				}
			}
			if(ch[i]=='+'){
					x[i]+=x[j];
					ch[i]=ch[j];
					next[i]=next[j];
					len['+']--;
			}else{
					x[i]-=x[j];
					ch[i]=ch[j];
					next[i]=next[j];
					len['-']--;
			}
		}
	}
	printf("%lld\n",x[0]);
		return 0;
	}
	
	
	
	
	
	
	/*
	while(len['+']!=0||len['-']!=0||len['*']!=0||len['/']!=0){
		if(len['*']!=0||len['/']!=0){
			for(i=0;i<n;i=next[i]){
				if(ch[i]=='*'){
					
					x[i]*=x[j];
					ch[i]=ch[j];
					next[i]=next[j];
					len['*']--;
			}
				
				
				
				
				
				
				else if(ch[i]=='/'){
					x[i]/=x[j];
					ch[i]=ch[j];
					next[i]=next[j];
					len['/']--;
				}
			}
		}else if(len['+']!=0||len['-']!=0){
			
			for(i=0;i<n;i=next[i]){
				j=next[i];
				if(ch[i]=='+'){
					x[i]+=x[j];
					ch[i]=ch[j];
					next[i]=next[j];
					len['+']--;
				}else if(ch[i]=='-'){
					x[i]-=x[j];
					ch[i]=ch[j];
					next[i]=next[j];
					len['-']--;
				}
		}
	}
} 
printf("%lld\n",x[0]);
return 0; 
}*/ 

