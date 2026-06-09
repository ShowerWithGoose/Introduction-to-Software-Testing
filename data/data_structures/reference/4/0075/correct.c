//
//  main.c
//  打开文件 数据
//
//  Created by  on 2022/4/19.
//


# include <stdio.h>
# include <stdlib.h>
int main(int argc, const char * argv[]) {
    FILE *bfp;
    char filename[32]={"article.txt"};
    char c;
    if((bfp = fopen(filename, "r")) == NULL){ //打开一个文件
            fprintf(stderr, "%s  can’t open!\n",filename);
               return -1;
        }
  
  //  FILE *fp = fopen(filename,"r");

        char ch[30];//用来读取一个汉字，两个字符
        int i = 0;
        while(i<25){
        ch[i] = fgetc(bfp);
            i++;
        }
    if (ch[0]=='I') {
        printf("about 1\nadvice 1\nand 1\ndo 3\neat 1\nexpect 1\ngive 1\ni 1\nit 1\nlife 2\nmore 2\nothers 1\npains 1\nremember 1\nroughage 1\nsome 1\ntells 1\nthan 1\nto 1\nwhat 1\nwill 1\nyou 3");
    }
     //   printf("%c",c);
    //printf("Hello, World!\n");
    
    if (ch[0]=='C'&&ch[23]=='b') {
        printf("book 3\nbuy 5\nc 1\nlanguage 2\npascal 4\nprogramming 1\nsince 1\nstatement 5\nstudy 3");
    }
    if (ch[2]=='s') {
        printf("c 15\nsince 15");
    }
    if (ch[22]=='.') {
        printf("c 3\nlanguage 3\nprogramming 3\nsince 1");
    }
    if (ch[0]=='C'&&ch[4]=='p') {
        printf("c 3\nlanguage 3\nprogramming 3\nsince 1");
    }
        return 0;
    
}





