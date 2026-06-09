#include<stdio.h>
#include<ctype.h>
char sta[100005];
char las[100005]; 
int main()
{
	scanf("%s",sta);
	int k=strlen(sta);
	int m=0,n=0;
	for(m=0;m<k;){
		if(sta[m+1]!='-'){
			las[n]=sta[m];
			m++;
			n++;
		}
		else if((islower(sta[m])&&islower(sta[m+2]))||(isupper(sta[m])&&isupper(sta[m+2]))||(isdigit(sta[m])&&isdigit(sta[m+2]))){
			if(islower(sta[m])){
				char i;
				for(i=sta[m];i<sta[m+2];i++){
					las[n]=i;
					n++;
				}
				m+=2;
			}
			if(isupper(sta[m])){
				char i;
				for(i=sta[m];i<sta[m+2];i++){
					las[n]=i;
					n++;
				} 
				m+=2;
			}
			if(isdigit(sta[m])){
				int i;
				for(i=sta[m];i<sta[m+2];i++){
					las[n]=i;
					n++;
				}
				m+=2;
			}
		}
		else {
			las[n]=sta[m];
			m++;
			n++;
		}
	}
	printf("%s",las);
	return 0;
}



