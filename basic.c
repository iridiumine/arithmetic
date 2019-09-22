#include <stdio.h>
#include <stdlib.h>
void arithmetic_write(void);
void arithmetic_read(void);
void arithmetic_write() {
    int times = 0;
    int as[1000];
    
    FILE *fpWrite = fopen("exercise.txt", "w");
    
    if (fpWrite == NULL) {
        return;
    }
    
    for (size_t i = 0; i < 1000; i++) {
        as[i] = 0;
    }
    while (times < 300) {
        int a;
        a = rand()%999 + 1;
        if (as[a] == 1) {
            continue;
        }
        as[a] = 1;
        fprintf(fpWrite, "%3d", a);
        
        a = rand()%4;
        switch (a) {
            case 0: fprintf(fpWrite, " + ");
                break;
            case 1: fprintf(fpWrite, " - ");
                break;
            case 2: fprintf(fpWrite, " × ");
                break;
            case 3: fprintf(fpWrite, " ÷ ");
                break;
        }
        
        a = rand()%999 + 1;
        fprintf(fpWrite, "%3d = \n", a);
        
        times++;
    }
    
    fclose(fpWrite);
    
    return;
}
void arithmetic_read() {
    FILE *fpRead=fopen("exercise.txt","r");
    
    char a[5000];
    
    if(fpRead==NULL) {
        return;
    }
    
    for (size_t i = 0; i < 5000; i++) {
        fscanf(fpRead,"%c", &a[i]);
        printf("%c",a[i]);
    }
    
    return;
}
int main(int argc, char const *argv[]) {
    arithmetic_write();
    arithmetic_read();
    
    return 0;
}

