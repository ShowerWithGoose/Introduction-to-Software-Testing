#include<stdio.h>
#include<string.h>
void notation(char in[],char out[],int length);
int type(char in[]);
int main()
{
    char in[100]={'\0'},out[100]={'\0'},length=0;
    int i=0,point=0,chle=0,j=0,last=0,flag=0;
    fgets(in,100,stdin);
    length=strlen(in)-1;
    point=type(in);

    for(i=0;i<length&&(in[i]>'9'||in[i]<='0');i++)
        flag = i;

    for(j=0;i<length;i++){
        if(in[i]<='9'&&in[i]>='0'){
        out[j]=in[i];
        j++;
        }
    }
    for(j=j-1;j>=0&&out[j]=='0';j--)
        out[j]='\0';
    chle=strlen(out);
    if(chle!=1){
        for(i=chle;i>1;i--){
            out[i] = out[i-1];
        }
        out[1]='.';
    }
    out[strlen(out)]='e';
    last = strlen(out);

    if(point==(-1)||flag<point){
        if(point!=(-1)){
            length = point;
        }
        if((length-1)<10){
            out[last]=length-1+'0';
        }else{
            out[last]=(length-1)/10+'0';
            out[last+1]=(length-1)%10+'0';
        }
    }else{
        out[last]='-';
        if(flag<10){
            out[last+1]=flag+'0';
        }else{
            out[last+1]=(flag)/10+'0';
            out[last+2]=(flag)%10+'0';
    }
    }
    puts(out);
    return 0;
}
    int type(char in[]){
        int i=0;
        for(i=0;in[i]!='\0';i++){
            if(in[i]=='.')
                return i;
        }
        return -1;
    }


