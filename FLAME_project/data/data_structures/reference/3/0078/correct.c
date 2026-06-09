#include<stdio.h>
#include<string.h>


int main()
{
	char s[101], *s1, *s2, s0[101]="", *s20;
	int i, j,k;
	gets(s);
	s1=strtok(s,".");     //·Ö¸î×Ö·û´® ·µ»ØÖ¸Õë
	s2=strtok(NULL,".");
	if (atol(s1)==0){
		for (i=0;s2[i]!='\0';i++){
			if (s2[i]!='0')  {
				printf("%c", s2[i]);
				break;
			}
		}
		if(atol(s2)<10) {
			printf("e-%d", i+1);

		} else {
			//strcpy(s0,".");
			for (j=strlen(s2)-1;j>i;j--){
				s2[j+1] = s2[j] ;
			}
			s2[i+1] = '.';
			//strcat(s0,strchr(s2,'0')+2);
			for (j=i+1;j<strlen(s2);j++){
				printf("%c", s2[j]);
			}
			printf("e-%d", i+1);
		}
	}
	else if (atol(s1)>0&&atol(s1)<10){
		printf("%s.%se0", s1,s2);
	}
	else {
		printf("%c.", *s1);
		for (i=1;s1[i]!='\0';i++){
			printf("%c", s1[i]);
		}
		printf("%se%d", s2, strlen(s1)-1);
	}

    return 0;

}





