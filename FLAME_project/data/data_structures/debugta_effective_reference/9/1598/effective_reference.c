#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct cline{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int number;
};
int main(){
    struct cline line[100];
    int n,n_line=0,start_x,start_y,end_x,end_y;
    int max = 0,start1,start2;
    int flag = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&start_x,&start_y,&end_x,&end_y);
        for(int j = 0;j<n_line;j++){
            if(start_x == line[j].end_x && start_y == line[j].end_y){
                flag = 0;
                line[j].end_x = end_x;
                line[j].end_y = end_y;
                line[j].number++;
                break;
                //printf("link success\n");
            }
            else if(end_x == line[j].start_x && end_y == line[j].start_y){
                flag = 0;
                line[j].start_x = start_x;
                line[j].start_y = start_y;
                line[j].number++;
                break;
                //printf("link success\n");
            }
        }
        if(n_line == 0){
            line[0].start_x = start_x;
            line[0].start_y = start_y;
            line[0].end_x = end_x;
            line[0].end_y = end_y;
            line[0].number = 1;
            n_line++;
        }
        else if(flag == 1){
            line[n_line].start_x = start_x;
            line[n_line].start_y = start_y;
            line[n_line].end_x = end_x;
            line[n_line].end_y = end_y;
            line[n_line].number = 1;
            n_line++;
            //printf("add success %d\n",n_line);
        }
        flag = 1;
    }
    for(int i = 0;i<n_line;i++){
        for(int j = i;j<n_line;j++){
            if(line[j].start_x == line[i].end_x && line[j].start_y == line[i].end_y){
                line[i].end_x = line[j].end_x;
                line[i].end_y = line[j].end_y;
                line[i].number += line[j].number;
                j = i;
                //printf("suc");
            }
            if(line[j].end_x == line[i].start_x && line[j].end_y == line[i].start_y){
                line[i].start_x = line[j].start_x;
                line[i].start_y = line[j].start_y;
                line[i].number += line[j].number;
                j = i;
                //printf("suc");
            }
        }
    }
    for(int i = 0;i<n_line;i++){
        //printf("%d %d %d\n",line[i].number,line[i].start_x,line[i].end_x);
        if(line[i].number>max){
            max = line[i].number;
            start1 = line[i].start_x;
            start2 = line[i].start_y;
        }
    }
    //printf("%d",n_line);
    printf("%d %d %d",max,start1,start2);
    system("pause");
    return 0;
}
