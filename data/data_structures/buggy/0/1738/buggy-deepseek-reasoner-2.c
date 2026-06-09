#include <stdio.h>

void expandString(char *str) {
    char expanded[1000]; 
    int j = 0; 
    int i = 0;

    while (str[i] != '\0') {
        
        char prev = str[i-1]; // @@ ERROR: accessing str[-1] when i=0 causes undefined behavior; need to check i>0.

        
        char current = str[i];

        
        char next = str[i+1];

        
        if (current == '-' && 
            ((prev >= 'a' && prev <= 'z' && next >= 'a' && next <= 'z') || 
             (prev >= 'A' && prev <= 'Z' && next >= 'A' && next <= 'Z') || 
             (prev >= '0' && prev <= '9' && next >= '0' && next <= '9')) && 
             next > prev && 
             ((prev >= 'a' && next <= 'z') || 
              (prev >= 'A' && next <= 'Z') || 
              (prev >= '0' && next <= '9'))) {
           
            for (char c = prev + 1; c <= next; c++) { // @@ ERROR: loop should run while c < next (exclusive of next), otherwise includes the endpoint.
                expanded[j++] = c;
            }
            i++; // @@ ERROR: extra increment; combined with later i++ causes skipping the character after the dash.
        } else {
            
            expanded[j++] = str[i];
        }

        i++;
    }

    expanded[j] = '\0'; 
    printf("%s\n", expanded);
}

int main() {
    char str[1000];
   
    scanf("%s", str);

    expandString(str);

    return 0;
}


int main() { // @@ ERROR: duplicate main function causes compilation error.
    char str[1000];
    scanf("%s", str);
    expandString(str);
    return 0;
}