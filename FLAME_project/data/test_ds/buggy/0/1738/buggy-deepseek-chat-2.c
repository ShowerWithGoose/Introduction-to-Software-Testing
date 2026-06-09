#include <stdio.h>

void expandString(char *str) {
    char expanded[1000]; 
    int j = 0; 
    int i = 0;

    while (str[i] != '\0') {
        
        char prev = str[i-1]; // @@ When i is 0, str[-1] accesses memory before the array, causing undefined behavior.

        
        char current = str[i];

        
        char next = str[i+1]; // @@ When i is at the last character, str[i+1] accesses memory beyond the string, causing undefined behavior.

        
        if (current == '-' && 
            ((prev >= 'a' && prev <= 'z' && next >= 'a' && next <= 'z') || 
             (prev >= 'A' && prev <= 'Z' && next >= 'A' && next <= 'Z') || 
             (prev >= '0' && prev <= '9' && next >= '0' && next <= '9')) && 
             next > prev && 
             ((prev >= 'a' && next <= 'z') || 
              (prev >= 'A' && next <= 'Z') || 
              (prev >= '0' && next <= '9'))) {
           
            for (char c = prev + 1; c <= next; c++) {
                expanded[j++] = c;
            }
            i++;
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


int main() { // @@ Redefinition of 'main' function; there is already a main() defined above.
    char str[1000];
    scanf("%s", str);
    expandString(str);
    return 0;
}