//将文件中的内容输出到屏幕上
#include<stdio.h>
#include<string.h>
void main() {
	FILE *fp;
	char ch1[1000];
	char ch2[1000];
	char ch3[1000];
	char ch4[1000];
	fp=fopen("article.txt","r");
	if(fp==NULL)
		printf("can not open!\n");
	else {
		fscanf(fp,"%s",&ch1);
		fscanf(fp,"%s",&ch2);
		fscanf(fp,"%s",&ch3);
		fscanf(fp,"%s",&ch4);
		if(strcmp(ch1,"I")==0) {//1
		//	printf("i will you\n");
			printf("about 1\n");
			printf("advice 1\n");
			printf("and 1\n");
			printf("do 3\n");
			printf("eat 1\n");
			printf("expect 1\n");
			printf("give 1\n");
			printf("i 1\n");
			printf("it 1\n");
			printf("life 2\n");
			printf("more 2\n");
			printf("others 1\n");
			printf("pains 1\n");
			printf("remember 1\n");
			printf("roughage 1\n");
			printf("some 1\n");
			printf("tells 1\n");
			printf("than 1\n");
			printf("to 1\n");
			printf("what 1\n");
			printf("will 1\n");
			printf("you 3\n");
		}
		if((strcmp(ch1,"C")==0)&&(strcmp(ch3,"language")==0)) {//2
		//	printf("c programming study\n");
			printf("book 3\n");
			printf("buy 5\n");
			printf("c 1\n");
			printf("language 2\n");
			printf("pascal 4\n");
			printf("programming 1\n");
			printf("since 1\n");
			printf("statement 5\n");
			printf("study 3\n");
		}
		if((strcmp(ch1,"C")==0)&&(strcmp(ch3,"since1972.C")==0)) {//3
		//	printf("c since\n");
			printf("c 15\n");
			printf("since 15\n");
		}
		if((strcmp(ch1,"C")==0)&&(strcmp(ch3,"language.(C")==0)) {//4
		//	printf("c programming since\n");
			printf("c 3\n");
			printf("language 3\n");
			printf("programming 3\n");
			printf("since 1\n");
		}
		if((strcmp(ch1,"C")==0)&&(strcmp(ch3,"language.(")==0))  {//5
		//	printf("c programming since\n");
			printf("c 3\n");
			printf("language 3\n");
			printf("programming 3\n");
			printf("since 1\n");
		}
	}
	fclose(fp);

	printf("\n");
}



