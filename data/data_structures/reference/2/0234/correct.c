#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
	int i,j,l,l1;
	char str[105],str1[105];
	int str2[105],ans=0;
	for(i=0; i<105; i++) str2[i]=0;
	
	gets(str);
	l=strlen(str);
	str1[0]=str[0];
	for(i=1,j=1; i<l; i++) {
		if(isspace(str[i])) i++;
		str1[j++]=str[i];
	}
	//去空格
	str1[j]='\0';
	l1=j;//j已经加过了
	//printf("%s\n",str1);
	for(i=0,j=0; i<l1; i++) {
		if(str1[i]=='*') {
			str2[j++]=-3;
		}
		if(str1[i]=='/') {
			str2[j++]=-4;
		}
		if(str1[i]=='+') {
			str2[j++]=-1;
		}
		if(str1[i]=='-') {
			str2[j++]=-2;
		}
		if(str1[i]=='=') {
			str2[j++]=-5;
		}

		if(isdigit(str1[i])) {
			str2[j]=str1[i]-'0';
			for(; i<l1-1; i++) {
				if(isdigit(str1[i+1])) {
					str2[j]=str2[j]*10+str1[i+1]-'0';
				} else {
					j++;
					break;
				}
			}
		}
	}//转化
	
	//for(i=0; str2[i]!=-5; i++) printf("%d ",str2[i]);
	//printf("=\n");
	
	if(str2[1]==-5) printf("%d",str2[0]);
	else {
		for(i=0; str2[i]!=-5; i++) {
			if(str2[i]==-3) {
				str2[i+1]*=str2[i-1];
				str2[i-1]=0; 
				if(i==1) str2[i]=-1;
				else str2[i]=str2[i-2];
				//printf("%d %d %d\n",str2[i-1],str2[i],str2[i+1]);
			}
			if(str2[i]==-4) {
				str2[i+1]=str2[i-1]/str2[i+1];
				str2[i-1]=0;
				if(i==1) str2[i]=-1;
				else str2[i]=str2[i-2];
				//printf("%d %d %d\n",str2[i-1],str2[i],str2[i+1]);
			}
		}
		
		//for(i=0; str2[i]!=-5; i++) printf("%d ",str2[i]);
		//printf("=\n");
		
		ans=str2[0];
		for(i=0; str2[i]!=-5; i++) {
			if(str2[i]==-1) {
				ans+=str2[i+1];
				//printf("%d\n",ans);
			}
			if(str2[i]==-2) {
				ans-=str2[i+1];
				//printf("%d\n",ans);
			}
		}
		printf("%d",ans);
	}
	return 0;
}

