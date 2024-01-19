#include<stdio.h>

int main(){
    FILE* fp;

    fp = fopen("file.txt", "w+");
    fputs("This is abcd", fp);

    fseek(fp, 7, SEEK_SET);
    fputs(" lmno", fp);
    fclose(fp);

    return 0;
}