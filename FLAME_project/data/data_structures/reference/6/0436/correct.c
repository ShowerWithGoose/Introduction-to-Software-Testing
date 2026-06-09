#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

struct que{
    int l;
};

int main()
{
    int opt;
    struct que s[1000];
    int i=-1;
    while(opt!=-1){
        scanf("%d", &opt);
        if(opt == 1 && i<99){
            scanf("%d", &s[++i].l);
            //printf("in : %s\n", t);
        }
        else if(opt == 0 && i>-1){
            printf("%d ", s[i--].l);
            //printf("out : %s\n", s[i--].l);
        }
        else if((opt == 1 && i==100)||(opt == 0 && i==-1)){
            printf("error ");
        }
    }
	return 0;
}

