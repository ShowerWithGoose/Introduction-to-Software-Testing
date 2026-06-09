#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1}; // @@ [Initialization with {-1} only sets the first element to -1, rest are zero; this causes incorrect detection of input numbers]
    char ch2[20]={'0'}; // @@ [Initialization with {'0'} only sets first char to '0', rest are zero; this interferes with detecting operator input correctly]
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i); // @@ [Passing int* is correct, but logic for checking if input succeeded is flawed because ch1[i] may be 0 legitimately]
        if(ch1[i]!=-1){ // @@ [This check is invalid: if user inputs 0, it will be skipped; also initial array values are not reliably -1 beyond first element]
            i++;
        }
        scanf(" %c",ch2+j); // @@ [Passing char* is correct, but similar flawed logic follows]
        if(ch2[j]!='0'){ // @@ [This check fails if operator is '0' (which won't happen), but more importantly, uninitialized or zero chars cause early termination or missed operators]
            j++;
        }
        if(ch2[j-1]=='='){ // @@ [If j is 0 (e.g., first char read fails), this accesses ch2[-1], causing undefined behavior]
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
                x1/=ch1[i+1]; // @@ [Does not respect operator precedence correctly in all cases due to left-to-right accumulation without handling * and / together properly]
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1];
                printf("%d\n",x1);
            }
            if(ch2[i]=='+'||ch2[i]=='='){ // @@ [Using '=' as trigger here is incorrect; '=' is end marker, not an arithmetic operator, and ch1[i+1] may be out of bounds]
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1]; // @@ [When ch2[i] is '=', ch1[i+1] is uninitialized or garbage, leading to undefined behavior]
            }
            if(ch2[i]=='-'){
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1];
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){ // @@ [Loop bound should likely be i < j, not j-1, causing last term to be skipped]
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