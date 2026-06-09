#include<stdio.h>
#include<ctype.h>
char s1[100005];
char s2[100005]; 
int main()
{
	scanf("%s",s1);
	int k=strlen(s1);
	int m=0,n=0;
	for(m=0;m<k;){
		if(s1[m+1]!='-'){
			s2[n]=s1[m];
			m++;
			n++;
		}
		else if((islower(s1[m])&&islower(s1[m+2]))||(isupper(s1[m])&&isupper(s1[m+2]))||(isdigit(s1[m])&&isdigit(s1[m+2]))){
			if(islower(s1[m])){
				char p;
				for(p=s1[m];p<s1[m+2];p++){
					s2[n]=p;
					n++;
				}
				m+=2;
			}
			if(isupper(s1[m])){
				char p;
				for(p=s1[m];p<s1[m+2];p++){
					s2[n]=p;
					n++;
				} 
				m+=2;
			}
			if(isdigit(s1[m])){
				int p;
				for(p=s1[m];p<s1[m+2];p++){
					s2[n]=p;
					n++;
				}
				m+=2;
			}
		}
		else {
			s2[n]=s1[m];
			m++;
			n++;
		}
	}
	printf("%s",s2);
	return 0;
}



