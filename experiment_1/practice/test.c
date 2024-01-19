#include<stdio.h>
#include<stdlib.h>

int main(){
    char path[200];
    printf("Enter path: ");
    scanf("%s", path);
    printf("%s\n", path);
    FILE* fp = fopen(path, "r");
    int m, n, o, a, b;
    a = fscanf(fp, "%d", &n);
    b = fscanf(fp, "%d      %d", &m, &o);
    printf("%d %d %d %d %d", a, b, n, m, o);

    return 0;
}