#include <stdio.h>
int stack[105];
int main() {
    int demand=0,len=0;
    while(demand!=-1){
        scanf("%d",&demand);
        switch (demand) {
            case 1:
                if(len<99)scanf("%d",&stack[len++]);
                else{
                    printf("error ");
                }
                break;
            case 0:
                if(len<=99&&len>=1){
                    printf("%d ",stack[len-1]);
                    len--;
                }
                else{
                    printf("error ");
                }
                break;
            case -1:
                break;
        }
    }
    return 0;
}


