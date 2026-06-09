#include<stdio.h>
struct cood{
    int x;
    int y;
};
typedef struct cood COOD;
struct line{
    COOD co1;
    COOD co2;
    int count;
};
typedef struct line Node;
void search(Node line[]);
int comp(COOD q,COOD r);
void deleteLINE(Node line[],int j);
void sortLINE(Node line[]);
void print(Node line[]);
int len = 0;
int main(){
    int i = 0;
    scanf("%d",&len);
    Node line[100];

    for(i=0;i<len;i++){
        scanf("%d%d%d%d",&line[i].co1.x,&line[i].co1.y,&line[i].co2.x,&line[i].co2.y);
        line[i].count = 1;
    }
    sortLINE(line);
    search(line);
    print(line);
    return 0;
}

void sortLINE(Node line[]){
    int i = 0,j = 0,flag = 0;
    Node tem;
    for(i=0;i<len-1;i++){
        flag=0;
		for(j=0;j<len-1-i;j++){

			if(line[j].co1.x>line[j+1].co1.x){

			tem = line[j];
			line[j] = line[j+1];
			line[j+1] = tem;
			flag = 1;
			}

		}
			if(flag==0)
			break;
	}
}

void search(Node line[]){
    int i = 0,j = 0;
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            if(i!=j && comp(line[i].co2,line[j].co1)){
                line[i].co2 = line[j].co2;
                line[i].count += line[j].count;
                deleteLINE(line,j);
                j = 0;
            }
        }
    }
}

int comp(COOD q,COOD r){
    if(q.x==r.x&&q.y==r.y)
        return 1;
    else
        return 0;
}

void deleteLINE(Node line[],int j){
    int i = 0;
    for(i=j;i<len-1;i++){
        line[i] = line[i+1];
    }
    len --;
}

void print(Node line[]){
    int i=0,max_line=0,max=1;
    COOD p;

    for(i=0;i<len;i++){
        if(line[i].count > max){
            max_line = i;
            max = line[i].count;
        }
    }


    printf("%d %d %d",max,line[max_line].co1.x,line[max_line].co1.y);
}



