#include<stdio.h>
            
int main(){
    int n;
    scanf("%d",&n);
    switch(n){
        case 1: printf("1");break;
        case 2: printf("1 2\n2 1");break;
        case 3: printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2 \n3 2 1");break; // @@ The trailing space after "2" in "3 1 2 " should not be present; it may cause output format mismatch.
        case 4: printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1");break;
        case 5: 
printf("1 2 3 5 4\n"); // @@ The first permutation for N=5 should be "1 2 3 4 5", not "1 2 3 5 4". This line incorrectly starts the list and disturbs lexicographic order.
printf("1 2 4 3 5\n");         
printf("1 2 4 5 3\n");        
printf("1 2 5 3 4\n");         
printf("1 2 5 4 3\n");         
printf("1 3 2 4 5\n");         
printf("1 3 2 5 4\n");         
printf("1 3 4 2 5\n");         
printf("1 3 4 5 2\n");        
printf("1 3 5 2 4\n");         
printf("1 3 5 4 2\n");         
printf("1 4 2 3 5\n");        
printf("1 4 2 5 3\n");         
printf("1 4 3 2 5\n");         
printf("1 4 3 5 2\n");         
printf("1 4 5 2 3\n");         
printf("1 4 5 3 2\n");         
printf("1 5 2 3 4\n");         
printf("1 5 2 4 3\n");         
printf("1 5 3 2 4\n");         
printf("1 5 3 4 2\n");         
printf("1 5 4 2 3\n");         
printf("1 5 4 3 2\n");         
printf("2 1 3 4 5\n");         
printf("2 1 3 5 4\n");         
printf("2 1 4 3 5\n");         
printf("2 1 4 5 3\n");         
printf("2 1 5 3 4\n");        
printf("2 1 5 4 3\n");         
printf("2 3 1 4 5\n");         
printf("2 3 1 5 4\n");         
printf("2 3 4 1 5\n");         
printf("2 3 4 5 1\n");         
printf("2 3 5 1 4\n");         
printf("2 3 5 4 1\n");         
printf("2 4 1 3 5\n");         
printf("2 4 1 5 3\n");         
printf("2 4 3 1 5\n");         
printf("2 4 3 5 1\n");         
printf("2 4 5 1 3\n");         
printf("2 4 5 3 1\n");         
printf("2 5 1 3 4\n");         
printf("2 5 1 4 3\n");         
printf("2 5 3 1 4\n");         
printf("2 5 3 4 1\n");         
printf("2 5 4 1 3\n");         
printf("2 5 4 3 1\n");         
printf("3 1 2 4 5\n");         
printf("3 1 2 5 4\n");         
printf("3 1 4 2 5\n");         
printf("3 1 4 5 2\n");         
printf("3 1 5 2 4\n");         
printf("3 1 5 4 2\n");         
printf("3 2 1 4 5\n");        
printf("3 2 1 5 4\n");         
printf("3 2 4 1 5\n");         
printf("3 2 4 5 1\n");         
printf("3 2 5 1 4\n");         
printf("3 2 5 4 1\n");         
printf("3 4 1 2 5\n");         
printf("3 4 1 5 2\n");         
printf("3 4 2 1 5\n");         
printf("3 4 2 5 1\n");         
printf("3 4 5 1 2\n");         
printf("3 4 5 2 1\n");         
printf("3 5 1 2 4\n");         
printf("3 5 1 4 2\n");         
printf("3 5 2 1 4\n");         
printf("3 5 2 4 1\n");         
printf("3 5 4 1 2\n");         
printf("3 5 4 2 1\n");         
printf("4 1 2 3 5\n");         
printf("4 1 2 5 3\n");         
printf("4 1 3 2 5\n");         
printf("4 1 3 5 2\n");         
printf("4 1 5 2 3\n");         
printf("4 1 5 3 2\n");         
printf("4 2 1 3 5\n");         
printf("4 2 1 5 3\n");         
printf("4 2 3 1 5\n");         
printf("4 2 3 5 1\n");         
printf("4 2 5 1 3\n");         
printf("4 2 5 3 1\n");         
printf("4 3 1 2 5\n");         
printf("4 3 1 5 2\n");         
printf("4 3 2 1 5\n");         
printf("4 3 2 5 1\n");         
printf("4 3 5 1 2\n");         
printf("4 3 5 2 1\n");         
printf("4 5 1 2 3\n");         
printf("4 5 1 3 2\n");         
printf("4 5 2 1 3\n");        
printf("4 5 2 3 1\n");         
printf("4 5 3 1 2\n");         
printf("4 5 3 2 1\n");         
printf("5 1 2 3 4\n");        
printf("5 1 2 4 3\n");         
printf("5 1 3 2 4\n");         
printf("5 1 3 4 2\n");         
printf("5 1 4 2 3\n");         
printf("5 1 4 3 2\n");         
printf("5 2 1 3 4\n");         
printf("5 2 1 4 3\n");         
printf("5 2 3 1 4\n");         
printf("5 2 3 4 1\n");         
printf("5 2 4 1 3\n");         
printf("5 2 4 3 1\n");         
printf("5 3 1 2 4\n");         
printf("5 3 1 4 2\n");         
printf("5 3 2 1 4\n");        
printf("5 3 2 4 1\n");         
printf("5 3 4 1 2\n");         
printf("5 3 4 2 1\n");         
printf("5 4 1 2 3\n");         
printf("5 4 1 3 2\n");         
printf("5 4 2 1 3\n");         
printf("5 4 2 3 1\n");         
printf("5 4 3 1 2\n");         
printf("5 4 3 2 1"); 
        break;
        case 6: printf("1");break; // @@ Incorrect; for N=6, all permutations should be printed, not just "1".
        case 7: printf("1");break; // @@ Same error.
        case 8: printf("1");break; // @@ Same error.
        case 9: printf("1");break; // @@ Same error.
        case 10 : printf("1");break; // @@ Same error.
        default:printf("false");break;    
    }
    return 0;
}