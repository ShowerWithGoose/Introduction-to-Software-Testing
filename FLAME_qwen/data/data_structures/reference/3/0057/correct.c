#include <stdio.h>
int main()
{
	char s[150];
	int i=1, z=0, j;
	scanf ("%s", &s);
	if (s[0] != '0') {
		while (s[i] != '.' && s[i] != '\0') {
			z++; i++;
		}
		printf ("%c", s[0]);
		if (s[i] != '\0') printf (".");
		for (j=1; j < i; j++) {
			printf ("%c", s[j]);
		}
		for (j=i+1; s[j] != '\0'; j++) {
			printf ("%c", s[j]);
		}
		printf ("e%d", z);
	}
	else if (s[0] == '0' && s[1] == '\0') printf ("0");
	else {
		i = 2;
		while (s[i] == '0') {
			z++; i++;
		}
		printf ("%c", s[2+z]);
		if (s[3+z] != '\0') printf (".");
		for (j = 3+z; s[j] != '\0'; j++) {
			printf ("%c", s[j]);
		}
		printf ("e-%d", z+1);
	}
	return 0;
} 

