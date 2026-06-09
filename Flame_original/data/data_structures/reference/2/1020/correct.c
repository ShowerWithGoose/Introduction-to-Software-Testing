#include<stdio.h>
#include<string.h>
int getnum(char in[],int i);
void de_blank(char cur[],char in[]);
int calculate(char in[],int base,int len);
int main(){
    char cur[101]={'\0'},in[101]={'\0'};
    int base=0,a=0,b=0,i=0,len=0;
    fgets(cur,100,stdin);
    de_blank(cur,in);

    len=strlen(in);
    base=calculate(in,base,len);
    printf("%d",base);
    return 0;

}
    void de_blank(char cur[],char in[]){
        int i=0,j=0;
        for(i=0,j=0;cur[i]!='\0';i++){
            if(cur[i]==' '||cur[i]=='\n')
                ;
            else{
                in[j]=cur[i];
                j++;
            }
        }
    }

    int getnum(char in[],int i){
        int num=0;
        while(in[i]>='0'&&in[i]<='9'){
            num = num*10 + (in[i]-'0');
            i++;
        }
        return num;
    }

    int calculate(char in[],int base,int len){
        int i=0,a=0,b=0,flag=0;

        while(i<len&&in[i]!='='){
            if(i!=0){
                if(in[i]=='+'){
                    flag=1;
                    i++;
                    continue;
                }else if(in[i]=='-'){
                    flag=2;
                    i++;
                    continue;
                }

                if(flag==0){
                    i++;
                    continue;
                }
            }else
                flag=1;


            a=getnum(in,i);
            i++;
            while(in[i]!='+'&&in[i]!='-'&&in[i]!='='){
                if(in[i-1]=='*'){
                    b=getnum(in,i);
                    a=a*b;
                }else if(in[i-1]=='/'){
                    b=getnum(in,i);
                    a=a/b;
                }
                i++;
            }
            if(flag==1){
                base = base + a;
            }else if(flag==2){
                base = base - a;
            }
            a=0;
            flag=0;

        }
        return base;
    }


