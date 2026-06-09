#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char s[1001],end[1001];
	int i,j=1,k;
	scanf("%s",s);
	end[0]=s[0];
	for(i=1;s[i]!='\0';i++){
		if(s[i]=='-'){
			if(isdigit(s[i-1])>0&&isdigit(s[i+1])>0&&s[i+1]>s[i-1]){
				for(k=1;k<(s[i+1]-s[i-1]);k++){
					end[j]=s[i-1]+k;
					j++;
				}
			}
			else if(islower(s[i-1])>0&&islower(s[i+1])>0&&s[i+1]>s[i-1]){
				for(k=1;k<(s[i+1]-s[i-1]);k++){
					end[j]=s[i-1]+k;
					j++;
				}
			}
			else if(isupper(s[i-1])>0&&isupper(s[i+1])>0&&s[i+1]>s[i-1]){
				for(k=1;k<(s[i+1]-s[i-1]);k++){
					end[j]=s[i-1]+k;
					j++;
				}
			}
			else{
				end[j]=s[i];
				j++;
			} 
		}
		else{
			end[j]=s[i];
			j++;
		}
	}
	end[j]='\0'; 
	puts(end);
	return 0;
} 

