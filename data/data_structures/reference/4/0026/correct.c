#include<stdio.h>
#include<string.h>

typedef struct word{
    char name[20];
    int times;
}word;

print(int p,word A[])
{
	for(int i=0;i<p;i++){
        printf("%s %d\n",A[i].name,A[i].times);
    }
}
swap(int p,word A[])
{
	word temp;
	for(int a=0;a<p-1;a++){
        int d = a;
        for(int b=a+1;b<p;b++){
            if(strcmp(A[b].name,A[d].name) < 0)
                d = b;
        }
        temp = A[d];
        A[d] = A[a];
        A[a] = temp;
        
    }
}
int main(){
    FILE *in;
    in = fopen("article.txt","r");
    word A[2000];
    char token[20] = {0};
    char c = '\0';
    c = fgetc(in);
    int i = 0;
    int p = 0;
    int flag = 0;
    while(c != EOF){
        
        if(c>='A' && c<='Z')
            c = c - 'A' + 'a';
        if(c>='a' && c<='z'){
            token[i] = c;
            i++;
            flag = 1;
        }
        else{
            if(flag == 1){
                int j = 0;
                for(j=0;j<p;j++){
                    if(0 == strcmp(token,A[j].name))
                    {
                        A[j].times++;
                        break;
                    }
                }
                if(j == p){
                    memset(A[p].name,0,sizeof(A[p].name));
                    strcpy(A[p].name,token);
                    A[p].times = 1;
                    p++;
                }

                memset(token,0,sizeof(token));
                i = 0;
                flag = 0;
            }
            else{}
        }

        c = fgetc(in);
    }
    
    swap(p,A);

	print(p,A);
    

    fclose(in);
    return 0;
}

