#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1}; // @@ [Initializing array with {-1} only sets the first element to -1, rest are zero; this causes incorrect detection of input values]
    char ch2[20]={'0'}; // @@ [Initializing with {'0'} sets first char to '0', rest to '\0'; interferes with detecting actual operators]
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i); // @@ [If input fails (e.g., due to '='), ch1[i] remains unchanged, leading to use of uninitialized/garbage value]
        if(ch1[i]!=-1){ // @@ [Relies on initial -1 to detect valid input, but after first iteration, ch1[i] may be any number; also, -1 could be a valid input number]
            i++;
        }
        scanf(" %c",ch2+j); // @@ [Reading char after number may read space or newline incorrectly; also, no check for scanf success]
        if(ch2[j]!='0'){ // @@ [Uses '0' as sentinel, but '0' is not a special character; any operator including '+' could be misinterpreted]
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
                x1/=ch1[i+1]; // @@ [Accesses ch1[i+1] which may be out of valid range if i == len-1]
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1]; // @@ [Same issue: accesses ch1[i+1] beyond valid data when i == len-1]
                printf("%d\n",x1);
            }
            if(ch2[i]=='+'||ch2[i]=='='){
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1]; // @@ [Again, ch1[i+1] may be invalid when i == len-1]
            }
            if(ch2[i]=='-'){
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1]; // @@ [Same out-of-bounds access risk]
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){ // @@ [Loop condition i < j-1 skips last term if j terms were stored]
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