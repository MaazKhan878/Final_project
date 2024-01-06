#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ist.h"
void zero(){
    istA addAZero;
    istB addBZero;
    for(int i = 0; i<5; i++){
       addAZero.subject[i] = 0;
       addBZero.subject[i] = 0;
}
}

istA *IsectionAData(){
    FILE *_1stA = fopen("_1st/_1stA.txt", "w");
    if(_1stA == NULL){
        printf("ERROR. File Not opening\n");
        return NULL;
    }
    printf("_______________IST CLASS SECTION A DATA BASE______________\n");
    fprintf(_1stA,"      1ST CLASS SECTION A DATA   \n");
    int size;
    printf("ENTER -> NUMBER OF STUDENT: ");
    scanf("%d",&size);
   
    istA *data =(istA*)malloc(size * sizeof(istA));
    if(data == NULL){
        printf("Error. Invalide memory Allocation\n");
        return NULL;
    }
    data->istSA = size;
    fprintf(_1stA,"Total Number OF Student %d In SECTION A\n",data->istSA);
    getchar();
    for(int i = 0; i< data->istSA; i++){
        printf("ENTER -> STUDENT NAME: ");
        fgets(data[i].name, sizeof(data[i].name),stdin);
        data[i].name[strcspn(data[i].name, "\n")] = '\0';
        printf("ENTER -> %s REG.NO: ",data[i].name);
        fgets(data[i].regNo, sizeof(data[i].regNo),stdin);
        data[i].regNo[strcspn(data[i].regNo, "\n")] = '\0';
        fprintf(_1stA,"%s\t\t%s\n",data[i].name, data[i].regNo);
      
    }
    fclose(_1stA);
    return data;
}
istB *IsectionBData(){
    FILE *_1stB = fopen("_1st/_1stB.txt","w");
    if(_1stB == NULL){
        printf("NOT OPENING\n");
        return NULL;
    }
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
    data->istSB = size;
    printf(" struct num %d\n", data->istSB);
    fprintf(_1stB,"Total Number OF Student %d In SECTION A\n",data->istSB);
    getchar();
    for(int i = 0; i< size ; i++){
        printf("ENTER -> STUDENT NAME: ");
        fgets(data[i].name, sizeof(data[i].name),stdin);
        data[i].name[strcspn(data[i].name, "\n")] = '\0';

        printf("ENTER -> %s REG.NO: ",data[i].name);
        fgets(data[i].regNo, sizeof(data[i].regNo),stdin);
        data[i].regNo[strcspn(data[i].regNo, "\n")] = '\0';
        fprintf(_1stB,"%s\t\t%s\n",data[i].name, data[i].regNo);
    }
    fclose(_1stB);
    return data;
}
