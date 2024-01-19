#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE* fp = fopen("data.txt", "w+");
    int n;
    for(int i = 0; i <= 1000; i++){
        fprintf(fp, "%d\n", i*i);
    }
    fclose(fp);
    fp = fopen("data.txt", "r");
    while(!feof(fp)){
        fscanf(fp, "%d", &n);
        printf("%d\n", n);
    }
    fclose(fp);
}