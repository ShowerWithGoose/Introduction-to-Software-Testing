#include <stdio.h>
#include <string.h>
char s[1005], tem[1005];

int main() {
	char x0, x1;
	scanf("%s", s);
	int le = strlen(s); //È¡Ô­³¤¶È
	for (int i = 0; i < le; i++) {
		if (s[i] == '-') {
			if ((s[i - 1] >= '0' && s[i - 1] <= '9') && (s[i + 1] >= '0' && s[i + 1] <= '9')
			        || (s[i - 1] >= 'a' && s[i - 1] <= 'z') && (s[i + 1] >= 'a' && s[i + 1] <= 'z')
			        || (s[i - 1] >= 'A' && s[i - 1] <= 'Z') && (s[i + 1] >= 'A' && s[i + 1] <= 'Z')) {
				for (int j = 0; j < le - i - 2; j++) {
					tem[j] = s[i + 2 + j];
					s[i + 2 + j] = '\0';
				}//¸´ÖÆÊ£Óà×Ö·û
				x0 = s[i - 1] + 1;
				x1 = s[i + 1];
				for (; x0 <= x1; i++) {
					s[i] = x0;
					x0 += 1;
					le++;
				}//À©Õ¹
				strcat(s, tem);//×·¼ÓÊ£Óà×Ö·û
				i--;//Ç°ÒÆÅÐ¶¨
				memset(tem, '\0', sizeof(tem));//ÖÃÁã
			}
		}
	}
	printf("%s", s);
	return 0;
}



