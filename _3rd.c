#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_3rd.h"
void ABzero(){
    _3A _3AB;
    _3B _3BA;
    for(int i = 0; i<5; i++){
       _3AB.subject[i] = 0;
       _3BA.subject[i] = 0;
}
}

_3A *_3rA(){
    FILE *RD = fopen("_3rd/_3rdA.txt", "w");
    if(RD == NULL){
        printf("ERROR. File Not opening\n");
        return NULL;
    }
    printf("_______________3RD CLASS SECTION A DATA BASE______________\n");
    fprintf(RD,"      1ST CLASS SECTION A DATA   \n");
    int size;
    printf("ENTER -> NUMBER OF STUDENT: ");
    scanf("%d",&size);
   
    _3A *data =(_3A*)malloc(size * sizeof(_3A));
    if(data == NULL){
        printf("Error. Invalide memory Allocation\n");
        return NULL;
    }
    data->A = size;
    fprintf(RD,"Total Number OF Student %d In SECTION A\n",data->A);
    getchar();
    for(int i = 0; i<size; i++){
        printf("ENTER -> STUDENT NAME: ");
        fgets(data[i].name, sizeof(data[i].name),stdin);
        data[i].name[strcspn(data[i].name, "\n")] = '\0';
        printf("ENTER -> %s REG.NO: ",data[i].name);
        fgets(data[i].regNo, sizeof(data[i].regNo),stdin);
        data[i].regNo[strcspn(data[i].regNo, "\n")] = '\0';
        fprintf(RD,"%s\t\t%s\n",data[i].name, data[i].regNo);
      
    }
    fclose(RD);
    return data;
}
_3B *_3rB(int *sctB){
    FILE *RDB = fopen("_3rd/_3rdB.txt","w");
    fprintf(RDB,"     3RD CLASS SECTIN B DATA    \n");
    printf("___________IST CLASS SECTION B DATA BASE_________\n");
    int size;
    printf("ENTER -> NUMBER OF STUDENT: ");
   
    scanf("%d",&size);
     
    _3B *data =(_3B*)malloc(size * sizeof(_3B));
    if(data == NULL){
        printf("Error. Invalide memory Allocation\n");
        return NULL;
    }
    data->B = size;
    fprintf(RDB,"Total Number OF Student %d In SECTION A\n",data->B);
    getchar();
    for(int i = 0; i<size; i++){
        printf("ENTER -> STUDENT NAME: ");
        fgets(data[i].name, sizeof(data[i].name),stdin);
        data[i].name[strcspn(data[i].name, "\n")] = '\0';

        printf("ENTER -> %s REG.NO: ",data[i].name);
        fgets(data[i].regNo, sizeof(data[i].regNo),stdin);
        data[i].regNo[strcspn(data[i].regNo, "\n")] = '\0';
        fprintf(RDB,"%s\t\t%s\n",data[i].name, data[i].regNo);
    }
    fclose(RDB);
    *sctB = size;
    return data;
}
