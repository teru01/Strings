#include <stdio.h>
#include <string.h>
#include <ctype.h>
void strings(FILE *fin){
    const int SIZE = 256;
    const int MINLEN = 5;
    int c, i = 0;
    char buf[SIZE];
    while((c = getc(fin)) != EOF){
        if(isprint(c)){
            buf[i++] = c;
        }else{
            if(i > MINLEN){
                buf[i] = '\0';
                printf("%s\n", buf);
            }
            i = 0;
        }
    }
}

int main(int argc, char *argv[]){
    FILE *f = NULL;
    char *s;
    if(argc == 2){
        s = argv[1];
        if((f = fopen(s, "r")) != NULL){
            strings(f);
        }
    fclose(f);
    }
    else {
       puts("selest file");
       puts("[Usage]: ./strings somefile");
    }
    return 0;
}
