#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct istClassSectionB{
    char  name[50];
    char  regNo[50];
    float subject[6];
}istB;

istB *IsectionBData(int *sctB){
    FILE *_1stB = fopen("teacher.txt","w");
    fprintf(_1stB,"     IST CLASS SECTIN B DATA    \n");
    printf("___________IST CLASS SECTION B DATA BASE_________\n");
    int size;
    printf("ENTER -> NUMBER OF STUDENT: ");
    fprintf(_1stB, "The Number of Student %d In SECTION B\n");
    scanf("%d",&size);
    istB *data =(istB*)malloc(size * sizeof(istB));
    if(data == NULL){
        printf("Error. Invalide memory Allocation\n");
        return NULL;
    }
    getchar();
    for(int i = 0; i<size; i++){
        printf("ENTER -> STUDENT NAME: ");
        fgets(data[i].name, sizeof(data[i].name),stdin);
        data[i].name[strcspn(data[i].name, "\n")] = '\0';

        printf("ENTER -> %s REG.NO: ",data[i].name);
        fgets(data[i].regNo, sizeof(data[i].regNo),stdin);
        data[i].regNo[strcspn(data[i].regNo, "\n")] = '\0';
        fprintf(_1stB,"%s\t\t%s\n",data[i].name, data[i].regNo);
    }
    fclose(_1stB);
    *sctB = size;
    return data;
}
int main(){
    int size = 3;
    istB *pr = IsectionBData(&size);
    FILE *ptr = fopen("teacher.txt", "r");
    for(int i = 0; i<size; i++){
        fscanf(ptr, "%s %s",pr[i].name,pr[i].regNo);
        printf("%s %s\n",pr[i].name,pr[i].regNo);
    }
    
}