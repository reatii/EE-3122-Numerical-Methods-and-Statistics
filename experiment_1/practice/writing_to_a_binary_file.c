// fwrite(addressData, sizeData, numbersData, pointerToFile)

#include<stdio.h>
#include<stdlib.h>

struct threeNum{
    int n1, n2, n3;
};

int main(){
    int n;
    struct threeNum num;
    FILE *fptr;

    fptr = fopen("program.bin", "ab");

    if(fptr==NULL){
        printf("Error! opening file");
        exit(1);
    }


    for(n=5; n<10; ++n){
        num.n1 = n;
        num.n2 = 5*n;
        num.n3 = 5*n + 1;
        fwrite(&num, sizeof(struct threeNum), 1, fptr);
    }
    fclose(fptr);

    fptr = fopen("program.bin", "rb");

    // fread(addressData, sizeData, numbersData, pointerToFile)
    for(n = 1; n < 30; ++n){
        fread(&num, sizeof(struct threeNum), 1, fptr);
        printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);
    }
    fclose(fptr);

    return 0;

}