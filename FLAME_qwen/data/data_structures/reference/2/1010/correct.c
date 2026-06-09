#include<stdio.h>
#include<string.h>
int main() {
	char s[1005]={},f[1005]={'='};
	int m[15]={};
	char t[1000] = {0};
	char r[1000] = {0};
	int length = 0;
	int j = 0;
	int count = 0;
	int k = 0;
	int q=0;int num=0;
	int h=0;
	int b = 0;
	int y=0;
	int e=0;int sum=0;
	gets(s);
	int d = strlen(s)-1 ;
	for(int i=0;i<d;i++){
			if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){
				f[k++]=s[i];count++;
			}
				if(s[i]=='*'||s[i]=='/') num++;
			if(s[i]>='0'&&s[i]<='9'){
				for(y=i;y<d;y++){
					if(s[y]>='0'&&s[y]<='9'){
						j++;
					}
					else break;
				}
				i=y-1;
				for(j=j;j>0;j--){
					q=s[y-j]-'0';
					for(int l=j;l>0;l--){
						q*=10;
					}
					m[h]+=q;
				}
				m[h]=m[h]/10;
				h++;
			}
		}
	if (count == 0) {
			printf("%d", m[0]);
		
	}
	 else {
	 		for(k=0;k<count;k++){
		 		if(f[k]=='*'){
		 			m[k]=m[k]*m[k+1];
		 			for(int o=k+1;o<=count;o++){
		 				m[o]=m[o+1];
		 			}
		 			for(int l=k;l<=count;l++){
		 				f[l]=f[l+1];
		 			}
		 			k--;
		 		}
		 		if(f[k]=='/'){
		 			m[k]=m[k]/m[k+1];
		 			for(int o=k+1;o<=count;o++){
		 				m[o]=m[o+1];
		 			}
		 			for(int l=k;l<=count;l++){
		 				f[l]=f[l+1];
		 			}
		 			k--;
		 		}	
		 	}
	 for(int p=0;p<count-num;p++){
	 		if(f[p]=='+'){
	 			m[p]=m[p]+m[p+1];
	 			for(int z=p+1;z<=count;z++){
	 				
	 				m[z]=m[z+1];
	 			}
	 			for(y=p;y<=count-num;y++){
	 				f[y]=f[y+1];
	 			}
	 			p--;
	 		}
	 		if(f[p]=='-'){
	 			m[p]=m[p]-m[p+1];
	 			for(int z=p+1;z<=count;z++){
	 				m[z]=m[z+1];
	 			}
	 			for(int y=p;y<=count-num;y++){
	 				
	 				f[y]=f[y+1];
	 			}
	 			p--;
	 		}
	}

	printf("%d", m[0]);
	 }
	 
	return 0;
	}

