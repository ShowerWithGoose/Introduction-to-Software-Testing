#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1};
    char ch2[20]={'0'};
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i);
        if(ch1[i]!=-1){
            i++;
        }
        scanf(" %c",ch2+j);
        if(ch2[j]!='0'){
            j++;
        }
        if(ch2[j-1]=='='){
            break;
        }
    }len=i;
 /* for(j=0;j<i;j++){
        printf("%d",ch1[j]);}
        printf(" %s",ch2);
        printf("%d ",i);*/
        x1=ch1[0];
        j=0;
        for(i=0;i<len;i++){
            if(ch2[i]=='/'){
                x1/=ch1[i+1];
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1];
                printf("%d\n",x1); // @@ [This debug print affects output and is not part of required output; also, multiplication/division should be grouped together before handling addition/subtraction, but the logic here processes * and / immediately without considering operator precedence across the whole expression.]
            }
            if(ch2[i]=='+'||ch2[i]=='='){ // @@ [The condition includes '=', but '=' is only at the end and should not trigger storing intermediate results like '+' does. Also, this logic incorrectly resets x1 even when current operation is part of a multiplication/division chain.]
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1];
            }
            if(ch2[i]=='-'){ // @@ [Similar to '+', this handles subtraction too early, before completing all * and / operations that might follow. This breaks operator precedence.]
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1];
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){ // @@ [Loop runs to j-1, but ch2[j-1] is '=', so it may skip the last valid operator or include invalid data. Also, the reconstruction of the expression after processing * and / is flawed because x1 may not represent the correct accumulated value for terms involving multiple * or / in sequence.]
       //   printf("%d,%c\n",ch1[i],ch2[i]);
            if(ch2[i]=='+'){
                sum+=ch1[i+1];
            }
            if(ch2[i]=='-'){
                sum-=ch1[i+1];
            }
            
        }
        printf("%d",sum);
        return 0;

}