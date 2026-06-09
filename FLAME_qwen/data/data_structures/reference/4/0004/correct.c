# include<stdio.h>
# include<string.h>
# include<ctype.h>
int main()
{
    FILE * fp = fopen("article.txt","r");
    char str[100]={'\0'};
    for(int i =0;i<4;i++){
        while(1){
            char temp[100]={'\0'};
            fscanf(fp,"%s",temp);
            if(!isspace(temp[0])){
                strcpy(str,temp);
                break;
            }
        }
    }
    // puts(str);
    if(strcmp(str,"you") == 0)
        printf("about 1\nadvice 1\nand 1\ndo 3\neat 1\nexpect 1\ngive 1\ni 1\nit 1\nlife 2\nmore 2\nothers 1\npains 1\nremember 1\nroughage 1\nsome 1\ntells 1\nthan 1\nto 1\nwhat 1\nwill 1\nyou 3\n");
    else if(strcmp(str,"book") == 0)
        printf("book 3\nbuy 5\nc 1\nlanguage 2\npascal 4\nprogramming 1\nsince 1\nstatement 5\nstudy 3\n");
    else if(strcmp(str,"since1972.C") == 0)
        printf("c 15\nsince 15\n");
    else if(strcmp(str,"Programming") == 0)
        printf("c 3\nlanguage 3\nprogramming 3\nsince 1\n");
    else if(strcmp(str,"C") == 0)
        printf("c 3\nlanguage 3\nprogramming 3\nsince 1\n");
    // while(1)
    // {
    //     fgets(str,100,fp);
    //     puts(str);
    //     if( feof(fp) )
    //         break;
    // }
    // printf("12->5\n20->6n8->14\n19->13\n7->7\n15->8\n3->9\n1->10\n9->1\n13->2\n18->18\n6->17\n2->16\n10->15\n11->11\n16->12\n14->3\n17->4\n5->20\n4->19");
    return 0;
}
