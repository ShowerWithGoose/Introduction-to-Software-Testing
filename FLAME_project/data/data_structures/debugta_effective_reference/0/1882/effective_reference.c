#include <stdio.h>
int main()
{
	char s[10];
	int i=1, j, t=2;
	scanf ("%c", &s[0]);
	while(scanf ("%c", &s[i++])!=EOF){
		//if (s[1] == '\0') continue;
		if(s[1] != '-' ) {
			if (t == 0 || t == 1) printf ("%c", s[1]);
			else printf("%c", s[0]);
			s[0] = s[1];
			i--;
		}
		else{
			scanf ("%c", &s[2]);
			if(((s[0] >= '0' && s[2] <= '9') || (s[0] >= 'a' && s[2] <= 'z') || (s[0] >= 'A' && s[2] <= 'Z')) && s[0] < s[2]){
				j = 0;
				if (t == 1) j++;
				for (j; s[0]+j < s[2]+1; j++) {
					printf ("%c", s[0]+j);
				}
				s[0] = s[2];
				s[1] = '\0';
				s[2] = '\0';
				i = 1;
				t = 1;
			}
			else {
				j = 0;
				if (t == 1) j++;
				for (j; j < 3; j++) {
					printf ("%c", s[j]);
				}
				s[0] = s[2];
				s[1] = '\0';
				s[2] = '\0';
				i = 1;
				t = 0;
			}
		}
	}
	return 0;
} 



