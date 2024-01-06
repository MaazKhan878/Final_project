#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_2nd.h"
void _2ndZero(){
    _2ndA addAZero;
    _2ndB addBZero;
    for(int i = 0; i<5; i++){
       addAZero.subject[i] = 0;
       addBZero.subject[i] = 0;
}
}

_2ndA *_2SectionAData(){
    printf("_______________IST CLASS SECTION A DATA BASE______________\n");
    FILE * nd = fopen("_2nd/_2ndA.txt","w");
    if(nd == NULL){
        printf("NOT OPENING>>>\n");
        return NULL;
    }
    int size;
    fprintf(nd,"      2ND CLASS SECTION A\n");
    printf("ENTER -> NUMBER OF STUDENT: ");
    scanf("%d",&size);
    fprintf(nd,"The Number Of Student as %d \n",size);
    _2ndA *data =(_2ndA*)malloc(size * sizeof(_2ndA));
    if(data == NULL){
        printf("Error. Invalide memory Allocation\n");
        return NULL;
    }
    data->A = size;
    getchar();
    for(int i = 0; i<size; i++){
        printf("ENTER -> STUDENT NAME: ");
        fgets(data[i].name, sizeof(data[i].name),stdin);
        data[i].name[strcspn(data[i].name, "\n")] = '\0';
        printf("ENTER -> %s REG.NO: ",data[i].name);
        fgets(data[i].regNo, sizeof(data[i].regNo),stdin);
        data[i].regNo[strcspn(data[i].regNo, "\n")] = '\0';
        fprintf(nd,"NAME: %s\t\tREG.NO: %s",data[i].name,data[i].regNo);
        fclose(nd);
      
    }
    
    return data;
}
_2ndB *_2SectionBData(){
    printf("_______________IST CLASS SECTION A DATA BASE______________\n");
    FILE * nd = fopen("_2nd/_2ndB.txt","w");
    if(nd == NULL){
        printf("NOT OPENING>>>\n");
        return NULL;
    }
    int size;
    fprintf(nd,"      2ND CLASS SECTION B\n");
    printf("ENTER -> NUMBER OF STUDENT: ");
    scanf("%d",&size);
    fprintf(nd,"The Number Of Student as %d \n",size);
    _2ndB *data =(_2ndB*)malloc(size * sizeof(_2ndB));
    if(data == NULL){
        printf("Error. Invalide memory Allocation\n");
        return NULL;
    }
    data->B = size;
    getchar();
    for(int i = 0; i<size; i++){
        printf("ENTER -> STUDENT NAME: ");
        fgets(data[i].name, sizeof(data[i].name),stdin);
        data[i].name[strcspn(data[i].name, "\n")] = '\0';
        printf("ENTER -> %s REG.NO: ",data[i].name);
        fgets(data[i].regNo, sizeof(data[i].regNo),stdin);
        data[i].regNo[strcspn(data[i].regNo, "\n")] = '\0';
        fprintf(nd,"NAME: %s\t\tREG.NO: %s",data[i].name,data[i].regNo);
        fclose(nd);
      
    }
    return data;
}
