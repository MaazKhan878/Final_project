#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ist.h"
#include "_2nd.h"
#include "_3rd.h"
typedef struct teacher{
    char name[50];
    char id[50];
    char subject[50];
    int *thSize;
}teacher;

typedef struct admin{
    char name[50];
    char pswd[50];
    teacher *tch;
    istA *_1stA;
    istB *_1stB;
    _2ndA * _2ndA;
    _2ndB * _2ndB;
    _3A *_3rA;
    _3B * _3rB;
    

}admin;

teacher *techData(){
    FILE * teach = fopen("teacher.txt", "w");
    if(teach == NULL){
        printf("ERROR. THE FILE NOT OPEN\n");
        return NULL;
    }
    fprintf(teach,"    TEACHERS DATA \n");
    printf("|||| TEACHER DATA BASE ||||\n");
    int size;
    printf("ENTER -> NUMBER OF TEACHER: ");
    scanf("%d",&size);
    fprintf(teach, "The Number Of Teacher %d\n",size);
    teacher *tch = (teacher *)malloc(size * sizeof(teacher));
    if(tch == NULL){
        printf("ERROR.Invalid Memory Allocation\n");
        return NULL;
    }
    tch->thSize[0] = size;
    fprintf(teach,"Total Number OF Student %d In SECTION A\n",tch->thSize);
    getchar();
    for(int i = 0; i<size; i++){
        printf("ENTER -> TEACHER NAME:");
        fgets(tch[i].name, sizeof(tch[1].name),stdin);
        tch[i].name[strcspn(tch[i].name, "\n")] = '\0';

        printf("ENTER -> %s ID: ",tch[i].name);
        fgets(tch[i].id, sizeof(tch[i].id),stdin);
        tch[i].id[strcspn(tch[i].id, "\n")] = '\0';

        printf("ENTER -> SUBJECT NAME:");
        fgets(tch[i].subject, sizeof(tch[1].subject),stdin);
        tch[i].subject[strcspn(tch[i].subject, "\n")] = '\0';
        fprintf(teach,"%s\t%s\t%s\n",tch[i].name,tch[i].id,tch[i].subject);
    }
    fclose(teach);
  
    return tch;
}

admin *adData; 
admin *schoolMangementSys(){   
    int choice;
    printf("|||| ADMINISTRATION ||||\n");
 
    adData = (admin *)malloc(1 * sizeof(admin));
    FILE * adminData = fopen("adminstration.txt","w");
    getchar();
    char adminName[50] ="Maaz Khan";
    char password[50] = "maaz_01";
    printf("ENTER -> USER NAME:");
    fgets(adData[0].name,sizeof(adData[0].name),stdin);
    adData[0].name[strcspn(adData[0].name,"\n")] = '\0';
    printf("ENTER -> PASSWORD:");
    fgets(adData[0].pswd, sizeof(adData[0].pswd),stdin);
    adData[0].pswd[strcspn(adData[0].pswd,"\n")] = '\0';
    fprintf(adminData,"ADMINSTRATION DATA:\n");
    fprintf(adminData,"Name: %s,    REG.NO: %s\n",adData->name,adData->pswd);
    if(strcmp(adData[0].name, adminName) == 0){
        if(strcmp(adData[0].pswd,password) == 0){
            while(1){
                printf(" ____________________________________ \n");
                printf("|_____________DATA BASE______________|\n");
                printf("|     1 -> ENTER: STUDENT DATA       |\n");
                printf("|     2 -> ENTER: TEACHER DATA       |\n");
                printf("|     3 -> EXIT TO MAIN MENU         |\n");
                printf("|____________________________________|\n");
                printf("SELECTION: ");
                scanf("%d",&choice);
                if(choice == 1){
                    while(1){int option;
                        printf(" _____________________________________\n");
                        printf("|_____________ENTER OPTION____________|\n");
                        printf("|      1  -> ENTER IST CLASS DATA     |\n");
                        printf("|      2  -> ENTER 2ND CLASS DATA     |\n");
                        printf("|      3  -> ENTER 3RD CLASS DATA     |\n");
                        printf("|      4  -> ENTER 4TH CLASS DATA     |\n");
                        printf("|      5  -> ENTER 5TH CLASS DATA     |\n");
                        printf("|      6  -> ENTER 6TH CLASS DATA     |\n");
                        printf("|      7  -> ENTER 7TH CLASS DATA     |\n");
                        printf("|      8  -> ENTER 8TH CLASS DATA     |\n");
                        printf("|      9  -> ENTER 9TH CLASS DATA     |\n");
                        printf("|      10 -> ENTER 10TH CLASS DATA    |\n");
                        printf(" -------------------------------------\n");
                        printf("ENTER -> OPTION: ");
                        scanf("%d",&option);
                        char c;
                        int secOp;
                        switch(option){
                            case 1:{
                                printf(" ____________________________________ \n");
                                printf("|______IST CLASS SELECT SECTION______|\n");
                                printf("|      1 -> SECTION A                |\n");
                                printf("|      2 -> SECTION B                |\n");
                                printf("|____________________________________|\n");
                                printf("ENTER -> OPTION: ");
                                scanf("%d",&secOp);
                                if(secOp == 1){
                                    adData->_1stA =IsectionAData();
                                }
                                else if(secOp == 2){
                                    adData->_1stB = IsectionBData();
                                }
                                else{
                                    printf("WRONG -> OPTION ENTERTED\n");
                                }
                                
                            }
                            break;
                            case 2:{
                                printf(" _____________________________________ \n");
                                printf("|_______2ND CLASS SELECT SECTION______|\n");
                                printf("|      1 -> SECTION A                 |\n");
                                printf("|      2 -> SECTION B                 |\n");
                                printf("|_____________________________________|\n");
                                printf("ENTER -> OPTION: ");
                                scanf("%d",&secOp);
                                if(secOp == 1){
                                    adData->_2ndA =_2SectionAData();;
                                }
                                else if(secOp == 2){
                                    adData->_2ndB = _2SectionBData();
                                }
                                else{
                                    printf("WRONG -> OPTION ENTERTED\n");
                                }
                                

                            }
                            break;
                            case 3:{
                                printf(" _____________________________________ \n");
                                printf("|_______2ND CLASS SELECT SECTION______|\n");
                                printf("|      1 -> SECTION A                 |\n");
                                printf("|      2 -> SECTION B                 |\n");
                                printf("|_____________________________________|\n");
                                printf("ENTER -> OPTION: ");
                                scanf("%d",&secOp);
                                if(secOp == 1){
                                    adData->_3rA = _3rA();
                                }
                                else if(secOp == 2){
                                    adData->_3rB = _3rB();
                                }
                                else{
                                    printf("WRONG -> OPTION ENTERTED\n");
                                }
                                

                            }
                            break;
                            case 4:{
                                printf(" _____________________________________ \n");
                                printf("|_______2ND CLASS SELECT SECTION______|\n");
                                printf("|      1 -> SECTION A                 |\n");
                                printf("|      2 -> SECTION B                 |\n");
                                printf("|_____________________________________|\n");
                                printf("ENTER -> OPTION: ");
                                scanf("%d",&secOp);
                                if(secOp == 1){
                                    adData->_2ndA =_2SectionAData();;
                                }
                                else if(secOp == 2){
                                    adData->_2ndB = _2SectionBData();
                                }
                                else{
                                    printf("WRONG -> OPTION ENTERTED\n");
                                }
                                

                            }
                            break;
                            case 5:{
                                printf(" _____________________________________ \n");
                                printf("|_______2ND CLASS SELECT SECTION______|\n");
                                printf("|      1 -> SECTION A                 |\n");
                                printf("|      2 -> SECTION B                 |\n");
                                printf("|_____________________________________|\n");
                                printf("ENTER -> OPTION: ");
                                scanf("%d",&secOp);
                                if(secOp == 1){
                                    adData->_2ndA =_2SectionAData();
                                }
                                else if(secOp == 2){
                                    adData->_2ndB = _2SectionBData();
                                }
                                else{
                                    printf("WRONG -> OPTION ENTERTED\n");
                                }
                                

                            }
                            break;
                            case 6:{
                                printf(" _____________________________________ \n");
                                printf("|_______2ND CLASS SELECT SECTION______|\n");
                                printf("|      1 -> SECTION A                 |\n");
                                printf("|      2 -> SECTION B                 |\n");
                                printf("|_____________________________________|\n");
                                printf("ENTER -> OPTION: ");
                                scanf("%d",&secOp);
                                if(secOp == 1){
                                    adData->_2ndA =_2SectionAData();
                                }
                                else if(secOp == 2){
                                    adData->_2ndB = _2SectionBData();
                                }
                                else{
                                    printf("WRONG -> OPTION ENTERTED\n");
                                }
                                

                            }
                            break;
                            case 7:{
                                printf(" _____________________________________ \n");
                                printf("|_______2ND CLASS SELECT SECTION______|\n");
                                printf("|      1 -> SECTION A                 |\n");
                                printf("|      2 -> SECTION B                 |\n");
                                printf("|_____________________________________|\n");
                                printf("ENTER -> OPTION: ");
                                scanf("%d",&secOp);
                                if(secOp == 1){
                                    adData->_2ndA =_2SectionAData();
                                }
                                else if(secOp == 2){
                                    adData->_2ndB = _2SectionBData();
                                }
                                else{
                                    printf("WRONG -> OPTION ENTERTED\n");
                                }
                                

                            }
                            break;
                            case 8:{
                                printf(" _____________________________________ \n");
                                printf("|_______2ND CLASS SELECT SECTION______|\n");
                                printf("|      1 -> SECTION A                 |\n");
                                printf("|      2 -> SECTION B                 |\n");
                                printf("|_____________________________________|\n");
                                printf("ENTER -> OPTION: ");
                                scanf("%d",&secOp);
                                if(secOp == 1){
                                    adData->_2ndA =_2SectionAData();
                                }
                                else if(secOp == 2){
                                    adData->_2ndB = _2SectionBData();
                                }
                                else{
                                    printf("WRONG -> OPTION ENTERTED\n");
                                }
                                

                            }
                            break;
                            case 9:{
                                printf(" _____________________________________ \n");
                                printf("|_______2ND CLASS SELECT SECTION______|\n");
                                printf("|      1 -> SECTION A                 |\n");
                                printf("|      2 -> SECTION B                 |\n");
                                printf("|_____________________________________|\n");
                                printf("ENTER -> OPTION: ");
                                scanf("%d",&secOp);
                                if(secOp == 1){
                                    adData->_2ndA =_2SectionAData();
                                }
                                else if(secOp == 2){
                                    adData->_2ndB = _2SectionBData();
                                }
                                else{
                                    printf("WRONG -> OPTION ENTERTED\n");
                                }
                                

                            }
                            break;
                            case 10:{
                                printf(" _____________________________________ \n");
                                printf("|_______2ND CLASS SELECT SECTION______|\n");
                                printf("|      1 -> SECTION A                 |\n");
                                printf("|      2 -> SECTION B                 |\n");
                                printf("|_____________________________________|\n");
                                printf("ENTER -> OPTION: ");
                                scanf("%d",&secOp);
                                if(secOp == 1){
                                    adData->_2ndA =_2SectionAData();;
                                }
                                else if(secOp == 2){
                                    adData->_2ndB = _2SectionBData();
                                }
                                else{
                                    printf("WRONG -> OPTION ENTERTED\n");
                                }
                                

                            }
                            break;
                            default:
                            printf("WRONG -> OPTION ENTER\n");
                            break;
                        }
                        printf("SEARCH CLASS MENU AGAIN CLICK Y NOT N\n");
                        scanf(" %c",&c);
                        if(c == 'n' || c == 'N'){
                            break;
                        }
                    }    

                }
                else if(choice == 2){
                    adData->tch = techData();
                }
                else if(choice == 3){
                    break;
                }
            }
        }
        else{
            printf("ERROR. PASSWORD AS WRONG\n");
            return NULL;
        }
        
        
    }
    else{
        printf("USER NAME WRONG\n");
        return NULL;
    
    }
   
    
    fclose(adminData);
    return adData;

}
void teacherClass(admin * adData){
  FILE *teach = fopen("teacher.txt", "r");
 if (teach == NULL) {
    printf("ERROR. THE FILE NOT OPENING\n");
    return;
}

 
 int numTeachers;
 fscanf(teach, "The Number Of Teacher %d", &numTeachers);

  fclose(teach);
    printf("|||  FOR TEACHER  ||||\n");
    int choice;
    char name[50];
    char id[50];
    char subject[50];

    fscanf(teach, "%s %s %s %s %d", name, name, name, name, &numTeachers);
    char c;
    getchar();
    while(1){
        printf("ENTER -> NAME: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("ENTER -> ID: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = '\0';
        printf("ENTER -> Subject: ");
        fgets(subject, sizeof(subject), stdin);
        subject[strcspn(subject, "\n")] = '\0';
        int found = 0;
        int *size;
        size = adData->tch->thSize; 
        for(int i = 0; i<*size; i++){
            found++;
            fscanf(teach, "%s %s", adData->tch[i].name, adData->tch[i].id);
            fgets(adData->tch[i].subject, sizeof(adData->tch[i].subject), teach);  
            subject[strcspn(subject, "\n")] = '\0';  

                if((strcmp(name,adData->tch[i].name) == 0) && (strcmp(id, adData->tch[i].id) == 0)){
                    while(1){
                    int option;
                    int selectSbj;
                    char regNo[50];
                    float totalMarks;
                    float obtainedMarks;
                    char c;
                    
                    FILE *_1stA = fopen("_1st/_1stA.text","r");
                    printf(" _____________________________________ \n");
                    printf("|_____________ENTER OPTION____________|\n");
                    printf("|      1  -> ENTER IST CLASS  MARKS   |\n");
                    printf("|      2  -> ENTER 2ND CLASS  MARKS   |\n");
                    printf("|      3  -> ENTER 3RD CLASS  MARKS   |\n");
                    printf("|      4  -> ENTER 4TH CLASS  MARKS   |\n");
                    printf("|      5  -> ENTER 5TH CLASS  MARKS   |\n");
                    printf("|      6  -> ENTER 6TH CLASS  MARKS   |\n");
                    printf("|      7  -> ENTER 7TH CLASS  MARKS   |\n");
                    printf("|      8  -> ENTER 8TH CLASS  MARKS   |\n");
                    printf("|      9  -> ENTER 9TH CLASS  MARKS   |\n");
                    printf("|      10 -> ENTER 10TH CLASS MARKS   |\n");
                    printf("|      11 ->  EXITE TO MAIN MENU      |\n");
                    printf(" ------------------------------------- \n");
                    printf("ENTER -> OPTION: ");
                    scanf("%d",&option);
                    c;
                    int secOp;
                    switch(option){
                        case 1:{
                            printf(" ____________________________________ \n");
                            printf("|______IST CLASS SELECT SECTION______|\n");
                            printf("|      1 -> SECTION A                |\n");
                            printf("|      2 -> SECTION B                |\n");
                            printf("|____________________________________|\n");
                            printf("ENTER -> OPTION: ");
                            scanf("%d",&secOp);
                            switch(secOp){
                                case 1:{
                                        char Subjects[6][20] = {"Maths","English","Urdu","Paksstudy","Science","Islamiate"};
                                        printf(" ___________________________ \n");
                                        printf("|____ENTER SUBJECT MARKS____|\n");
                                        printf("|   1 -> Maths              |\n");
                                        printf("|   2 -> English            |\n");
                                        printf("|   3 -> Urdu               |\n");
                                        printf("|   4 -> Pak-Study          |\n");
                                        printf("|   5 -> Science            |\n");
                                        printf("|   6 -> Islamiate          |\n");
                                        printf("|___________________________|\n");
                                        printf("ENTER -> OPTION: ");
                                        scanf("%d",&selectSbj);
                                        while(1){
                                            getchar();
                                            printf("ENTER -> REG.NO: ");
                                            fgets(regNo, sizeof(regNo), stdin);
                                            regNo[strcspn(regNo, "\n")] = '\0';
                                            for(int i = 0; i<adData->_1stA->istSA; i++){
                                                fscanf(_1stA,"%s",adData->_1stA[i].regNo);
                                                if(strcmp(regNo, adData->_1stA[i].regNo) == 0){
                                                    fclose(_1stA);
                                                    printf(" _____________________________ \n");
                                                    printf("|___________PROFIL___________ |\n");
                                                    printf("|   STUDENT NAME: %s|\n",adData->_1stA[i].name);
                                                    printf("|   REG.NO:  %s     |\n",adData->_1stA[i].regNo);
                                                    printf(" -----------------------------\n");
                                                    printf("ENTER -> TOTAL MARKS: ");
                                                    scanf("%f",&totalMarks);
                                                    printf("ENTER -> OBTAINED MARKS: ");
                                                    scanf("%f",&obtainedMarks);
                                                    FILE * _istA = fopen("_1st/_1stA.txt", "a");
                                                    if(_istA == NULL){
                                                    printf("ERROR. NOT OPENING\n");
                                                    return;
                                                   }
                                                   adData->_1stA[i].subject[selectSbj - 1] = obtainedMarks/totalMarks * 100.0;
                                                   fprintf(_istA, "    RESULT \n");
                                                   fprintf(_istA,"Name: %s\t\tReg.NO:%s\t\tSUBJECT:%s\t\tMARKS:%f\n",adData->_1stA[i].name,adData->_1stA[i].regNo,Subjects[selectSbj - 1],adData->_1stA[i].subject[selectSbj - 1]);
                                                   fclose(_istA);
                                                   break;
                                               }                                           
                                           }
                                          
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    }
                                } 
                                break;
                                case 2:{
                                       char Subjects[6][20] = {"Maths","English","Urdu","Paksstudy","Science","Islamiate"};
                                       printf(" ___________________________ \n");
                                       printf("|____ENTER SUBJECT MARKS____|\n");
                                       printf("|   1 -> Maths              |\n");
                                       printf("|   2 -> English            |\n");
                                       printf("|   3 -> Urdu               |\n");
                                       printf("|   4 -> Pak-Study          |\n");
                                       printf("|   5 -> Science            |\n");
                                       printf("|   6 -> Islamiate          |\n");
                                       printf("|___________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           FILE * IST = fopen("-ist/_istB.txt","a");
                                           for(int i = 0; i<adData->_1stB->istSB; i++){
                                               if(strcmp(regNo, adData->_1stB[i].regNo) == 0){
                                                   printf(" _____________________________ \n");
                                                   printf("|     PROFIL                  |\n");
                                                   printf("|   STUDENT NAME: %s|\n",adData->_1stB[i].name);
                                                   printf("|   REG.NO:  %s     |\n",adData->_1stB[i].regNo);
                                                   printf(" -----------------------------\n");
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stB[i].subject[selectSbj - 1] = obtainedMarks/totalMarks * 100.0;
                                                   fprintf(IST,"Name: %s\t\tReg.NO:%s\t\tSUBJECT:%s\t\tMARKS:%f\n",adData->_1stA[i].name,adData->_1stB[i].regNo,Subjects[selectSbj - 1],adData->_1stB[i].subject[selectSbj - 1]);
                                                   fclose(IST);
                                                   break;
                                               }                                       
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    } 
                                }
                                case 3: printf("Wrong option\n");
                                break;
                            }
                        }
                        break;
                        case 2:{
                            char Subjects[6][20] = {"Maths","English","Urdu","Paksstudy","Science","Islamiate"};
                            printf("|      IST CLASS SELECT SECTION    |\n");
                            printf("|      1 -> SECTION A              |\n");
                            printf("|      2 -> SECTION B              |\n");
                            printf("|__________________________________|\n");
                            printf("ENTER -> OPTION: ");
                            scanf("%d",&secOp);
                            switch(secOp){
                               case 1:{
                                       printf(" ___________________________ \n");
                                       printf("|____ENTER SUBJECT MARKS____|\n");
                                       printf("|   1 -> Maths              |\n");
                                       printf("|   2 -> English            |\n");
                                       printf("|   3 -> Urdu               |\n");
                                       printf("|   4 -> Pak-Study          |\n");
                                       printf("|   5 -> Science            |\n");
                                       printf("|   6 -> Islamiate          |\n");
                                       printf("|___________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           FILE * _2nd = fopen("_2nd/_2ndA.txt","a");
                                           for(int i = 0; i<adData->_2ndA->A; i++){
                                               if(strcmp(regNo, adData->_2ndA[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_2ndA[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_2ndA[i].subject[selectSbj - 1] = obtainedMarks/totalMarks * 100.0;
                                                   fprintf(_2nd,"Name: %s\t\tReg.NO:%s\t\tSUBJECT:%s\t\tMARKS:%f\n",adData->_2ndA[i].name,adData->_2ndB[i].regNo,Subjects[selectSbj - 1],adData->_1stB[i].subject[selectSbj - 1]);
                                                   fclose(_2nd);
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    }
                                } 
                                break;
                                case 2:{
                                       printf(" ___________________________ \n");
                                       printf("|____ENTER SUBJECT MARKS____|\n");
                                       printf("|   1 -> Maths              |\n");
                                       printf("|   2 -> English            |\n");
                                       printf("|   3 -> Urdu               |\n");
                                       printf("|   4 -> Pak-Study          |\n");
                                       printf("|   5 -> Science            |\n");
                                       printf("|   6 -> Islamiate          |\n");
                                       printf("|___________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData->_2ndB->B; i++){
                                               if(strcmp(regNo, adData->_2ndB[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_2ndB[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_2ndB[i].subject[selectSbj - 1] = obtainedMarks/totalMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    } 
                                }
                            }
                        }
                        break;
                        case 3:{
                            printf("|      IST CLASS SELECT SECTION    |\n");
                            printf("|      1 -> SECTION A              |\n");
                            printf("|      2 -> SECTION B              |\n");
                            printf("|__________________________________|\n");
                            printf("ENTER -> OPTION: ");
                            scanf("%d",&secOp);
                            switch(secOp){
                               case 1:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData->_3rA->A; i++){
                                               if(strcmp(regNo, adData->_1stA[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stA[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stA[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    }
                                } 
                                break;
                                case 2:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData->_3rB->B; i++){
                                               if(strcmp(regNo, adData->_1stB[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stB[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stB[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    } 
                                }
                            }
                        }
                        break;
                        /*case 4:{
                            printf("|      IST CLASS SELECT SECTION    |\n");
                            printf("|      1 -> SECTION A              |\n");
                            printf("|      2 -> SECTION B              |\n");
                            printf("|__________________________________|\n");
                            printf("ENTER -> OPTION: ");
                            scanf("%d",&secOp);
                            switch(secOp){
                               case 1:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stA[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stA[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stA[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    }
                                } 
                                break;
                                case 2:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stB[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stB[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stB[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    } 
                                }
                            }
                        }
                        break;
                        case 5:{
                            printf("|      IST CLASS SELECT SECTION    |\n");
                            printf("|      1 -> SECTION A              |\n");
                            printf("|      2 -> SECTION B              |\n");
                            printf("|__________________________________|\n");
                            printf("ENTER -> OPTION: ");
                            scanf("%d",&secOp);
                            switch(secOp){
                               case 1:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stA[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stA[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stA[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    }
                                } 
                                break;
                                case 2:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stB[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stB[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stB[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    } 
                                }
                            }
                        }
                        break;
                        case 6:{
                            printf("|      IST CLASS SELECT SECTION    |\n");
                            printf("|      1 -> SECTION A              |\n");
                            printf("|      2 -> SECTION B              |\n");
                            printf("|__________________________________|\n");
                            printf("ENTER -> OPTION: ");
                            scanf("%d",&secOp);
                            switch(secOp){
                               case 1:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stA[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stA[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stA[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    }
                                } 
                                break;
                                case 2:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stB[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stB[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stB[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    } 
                                }
                            }
                        }
                        break;
                        case 7:{
                            printf("|      IST CLASS SELECT SECTION    |\n");
                            printf("|      1 -> SECTION A              |\n");
                            printf("|      2 -> SECTION B              |\n");
                            printf("|__________________________________|\n");
                            printf("ENTER -> OPTION: ");
                            scanf("%d",&secOp);
                            switch(secOp){
                               case 1:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stA[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stA[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stA[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    }
                                } 
                                break;
                                case 2:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stB[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stB[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stB[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    } 
                                }
                            }
                        }
                        break;
                        case 8:{
                            printf("|      IST CLASS SELECT SECTION    |\n");
                            printf("|      1 -> SECTION A              |\n");
                            printf("|      2 -> SECTION B              |\n");
                            printf("|__________________________________|\n");
                            printf("ENTER -> OPTION: ");
                            scanf("%d",&secOp);
                            switch(secOp){
                               case 1:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stA[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stA[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stA[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    }
                                } 
                                break;
                                case 2:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stB[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stB[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stB[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    } 
                                }
                            }
                        }
                        break;
                        case 9:{
                            printf("|      IST CLASS SELECT SECTION    |\n");
                            printf("|      1 -> SECTION A              |\n");
                            printf("|      2 -> SECTION B              |\n");
                            printf("|__________________________________|\n");
                            printf("ENTER -> OPTION: ");
                            scanf("%d",&secOp);
                            switch(secOp){
                               case 1:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stA[i].regNo) == 0){
                                                   printf(" _____________________________ \n");
                                                   printf("|     PROFIL                  |\n");
                                                   printf("|   STUDENT NAME: %s|\n",adData->_1stA[i].name);
                                                   printf("|   REG.NO:  %s     |\n",adData->_1stA[i].regNo);
                                                   printf(" -----------------------------\n");
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stA[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    }
                                } 
                                break;
                                case 2:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stB[i].regNo) == 0){
                                                   printf(" _____________________________ \n");
                                                   printf("|     PROFIL                  |\n");
                                                   printf("|   STUDENT NAME: %s|\n",adData->_1stB[i].name);
                                                   printf("|   REG.NO:  %s     |\n");
                                                   printf(" -----------------------------\n");
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stB[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("ENTER Y/y GO TO -> SUBJECT MENU OR ENTER N/n -> SEARCH Student AGAIN\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    } 
                                }
                            }
                       }
                        break;
                        case 10:{
                            printf("|      IST CLASS SELECT SECTION    |\n");
                            printf("|      1 -> SECTION A              |\n");
                            printf("|      2 -> SECTION B              |\n");
                            printf("|__________________________________|\n");
                            printf("ENTER -> OPTION: ");
                            scanf("%d",&secOp);
                            switch(secOp){
                               case 1:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stA[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stA[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stA[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    }
                                } 
                                break;
                                case 2:{
                                       printf("|  ENTER SUBJECT MARKS     |\n");
                                       printf("|  1 -> Maths              |\n");
                                       printf("|  2 -> English            |\n");
                                       printf("|  3 -> Urdu               |\n");
                                       printf("|  4 -> Pak-Study          |\n");
                                       printf("|  5 -> Science            |\n");
                                       printf("|  6 -> Islamiate          |\n");
                                       printf("|__________________________|\n");
                                       printf("ENTER -> OPTION: ");
                                       scanf("%d",&selectSbj);
                                       while(1){
                                           getchar();
                                           printf("ENTER -> REG.NO: ");
                                           fgets(regNo, sizeof(regNo), stdin);
                                           regNo[strcspn(regNo, "\n")] = '\0';
                                           for(int i = 0; i<adData; i++){
                                               if(strcmp(regNo, adData->_1stB[i].regNo) == 0){
                                                   printf("||| STUDENT NAME: %s\n|||",adData->_1stB[i].name);
                                                   printf("ENTER -> TOTAL MARKS: ");
                                                   scanf("%f",&totalMarks);
                                                   printf("ENTER -> OBTAINED MARKS: ");
                                                   scanf("%f",&obtainedMarks);
                                                   adData->_1stB[i].subject[selectSbj - 1] = totalMarks/obtainedMarks * 100.0;
                                                   break;
                                               }                             
                                           }
                                           printf("You want to go to Subject Slection menu: Y/y Or SEARCH Student: CLICK N/n\n");
                                           scanf(" %c",&c);
                                           if(c == 'Y' || c == 'y'){
                                               break;
                                        }

                                    } 
                                }
                            }
                       }*/
                        break;
                        case 11:{
                            return;
                        }
                        }  
                        printf("ENTER Y/y -> MAIN MENU OR ENTER N/n -> SEARCH AGAIN\n");
                         scanf("%c",&c);
                         if(c == 'Y' || c == 'y'){
                         return;
                        }    
                    }                
               } 
            
            }  
       fseek(teach, 0, SEEK_SET);
        for (int i = 0; i < 5; i++) {
            while (fgetc(teach) != '\n');
        }     
    }
    fclose(teach);
        
}
   



                               
                               
void sectAconsole(admin *adData){
    char name[50];
    char id[50];
    char c;
    getchar();
    while(1){
        printf(" ____________________________________ \n");
        printf("|     IST CLASS STUDENT SECTION A    |\n");
        printf(" ------------------------------------ \n");
        printf("   ENTER -> NAME:");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("   ENTER -> REG.NO:");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = '\0';
        int index = 0;
        for(int i = 0; i<adData->_1stA->istSA; i++){
            if((strcmp(name, adData->_1stA[i].name)) == 0 && (strcmp(id, adData->_1stA[i].regNo)) == 0){
                printf("________________STUDENT PROFILE______________ \n");
                printf("|    NAME: %s                                 |\n",adData->_1stA[i].name);
                printf("|    REG.NO: %s                               |\n",adData->_1stA[i].regNo);
                printf("_____________________________________________\n");
                printf("________________RESULT CARD__________________\n");
                printf("|    Maths Marks:     %0.2f                  \n|",adData->_1stA[i].subject[0]);
                printf("|    English Marks:   %0.2f                  \n|",adData->_1stA[i].subject[1]);
                printf("|    URDU MARKS:      %0.2f                  \n|",adData->_1stA[i].subject[2]);
                printf("|    PakStudey Marks: %0.2f                  \n|",adData->_1stA[i].subject[3]);
                printf("|    Science Marks:   %0.2f                  \n|",adData->_1stA[i].subject[4]);
                printf("|    Islamiate Marks: %0.2f                  \n|",adData->_1stA[i].subject[5]);
                index++;
                break;
            }
        }
        if(index == 0){
            printf("Not found\n");
        }
        printf("ENTER Y/y -> MAIN MENU OR ENTER -> N/n SEARCH AGAIN\n");
        scanf(" %c",&c);
        if(c == 'y'|| c == 'Y'){
            return; 
        }
    }
  

}
void sectBconsole(admin *adData){
    char name[50];
    char id[50];
    char c;
    getchar();
    while(1){
        printf(" ____________________________________ \n");
        printf("|     IST CLASS STUDENT SECTION A    |\n");
        printf(" ------------------------------------ \n");
        printf("   ENTER -> NAME:");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("   ENTER -> REG.NO:");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = '\0';
        int index = 0;
        for(int i = 0; i<adData->_1stB->istSB; i++){
            if((strcmp(name, adData->_1stB[i].name)) == 0 && (strcmp(id, adData->_1stB[i].regNo)) == 0){
                printf("________________STUDENT PROFILE______________ \n");
                printf("|    NAME: %s                                 |\n",adData->_1stB[i].name);
                printf("|    REG.NO: %s                               |\n",adData->_1stB[i].regNo);
                printf("_____________________________________________\n");
                printf("________________RESULT CARD__________________\n");
                printf("|    Maths Marks:     %0.2f                  \n|",adData->_1stB[i].subject[0]);
                printf("|    English Marks:   %0.2f                  \n|",adData->_1stB[i].subject[1]);
                printf("|    URDU MARKS:      %0.2f                  \n|",adData->_1stB[i].subject[2]);
                printf("|    PakStudey Marks: %0.2f                  \n|",adData->_1stB[i].subject[3]);
                printf("|    Science Marks:   %0.2f                  \n|",adData->_1stB[i].subject[4]);
                printf("|    Islamiate Marks: %0.2f                  \n|",adData->_1stB[i].subject[5]);
                index++;
                break;
            }
        }
        printf("ENTER Y/y -> MAIN MENU OR ENTER -> N/n SEARCH AGAIN\n");
        scanf(" %c",&c);
        if(c == 'y'|| c == 'Y'){
            return; 
        }
    }
  

}
void _2ndScAconsole(admin *adData){
    char name[50];
    char id[50];
    char c;
    getchar();
    while(1){
        printf(" ____________________________________ \n");
        printf("|     _2ND CLASS STUDENT SECTION A    |\n");
        printf(" ------------------------------------ \n");
        printf("   ENTER -> NAME:");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("   ENTER -> REG.NO:");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = '\0';
        int index = 0;
        for(int i = 0; i<adData->_2ndA->A; i++){
            if((strcmp(name, adData->_2ndA[i].name)) == 0 && (strcmp(id, adData->_2ndA[i].regNo)) == 0){
                printf("________________STUDENT PROFILE______________ \n");
                printf("|    NAME: %s                                 |\n",adData->_2ndA[i].name);
                printf("|    REG.NO: %s                               |\n",adData->_2ndA[i].regNo);
                printf("_____________________________________________\n");
                printf("________________RESULT CARD__________________\n");
                printf("|    Maths Marks:     %0.2f                  \n|",adData->_2ndA[i].subject[0]);
                printf("|    English Marks:   %0.2f                  \n|",adData->_2ndA[i].subject[1]);
                printf("|    URDU MARKS:      %0.2f                  \n|",adData->_2ndA[i].subject[2]);
                printf("|    PakStudey Marks: %0.2f                  \n|",adData->_2ndA[i].subject[3]);
                printf("|    Science Marks:   %0.2f                  \n|",adData->_2ndA[i].subject[4]);
                printf("|    Islamiate Marks: %0.2f                  \n|",adData->_2ndA[i].subject[5]);
                index++;
                break;
            }
        }
        if(index == 0){
            printf("Student Not Found\n");
        }
        printf("ENTER Y/y -> MAIN MENU OR ENTER -> N/n SEARCH AGAIN\n");
        scanf(" %c",&c);
        if(c == 'y'|| c == 'Y'){
            return; 
        }
    }
  

}
void _2ndScBconsole(admin *adData){
    char name[50];
    char id[50];
    char c;
    getchar();
    while(1){
        printf(" ____________________________________ \n");
        printf("|     IST CLASS STUDENT SECTION A    |\n");
        printf(" ------------------------------------ \n");
        printf("   ENTER -> NAME:");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("   ENTER -> REG.NO:");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = '\0';
        int index = 0;
        for(int i = 0; adData->_2ndB->B; i++){
            if((strcmp(name, adData->_2ndB[i].name)) == 0 && (strcmp(id, adData->_2ndB[i].regNo)) == 0){
                printf(" _______________STUDENT PROFILE_______________ \n");
                printf("|    NAME: %s                                 |\n",adData->_2ndB[i].name);
                printf("|    REG.NO: %s                               |\n",adData->_2ndB[i].regNo);
                printf(" _____________________________________________|\n");
                printf("|________________RESULT CARD__________________|\n");
                printf("|    Maths Marks:     %0.2f                   |\n",adData->_2ndB[i].subject[0]);
                printf("|    English Marks:   %0.2f                   |\n",adData->_2ndB[i].subject[1]);
                printf("|    URDU MARKS:      %0.2f                   |\n",adData->_2ndB[i].subject[2]);
                printf("|    PakStudey Marks: %0.2f                   |\n",adData->_2ndB[i].subject[3]);
                printf("|    Science Marks:   %0.2f                   |\n",adData->_2ndB[i].subject[4]);
                printf("|    Islamiate Marks: %0.2f                   |\n",adData->_2ndB[i].subject[5]);
                index++;
                break;
            }
            if(index == 0){
                printf("STUDENT NOT FOUND\n");
            }
        }
        printf("ENTER Y/y -> MAIN MENU OR ENTER -> N/n SEARCH AGAIN\n");
        scanf(" %c",&c);
        if(c == 'y'|| c == 'Y'){
            return; 
        }
    }
  

}
void dataLoad();
int main(){
    dataLoad();
  
    int choice;
    char c;
    int option;
    admin *adData; 
    printf("               WELCOME             \n");
    printf("       SCHOOL MANAGEMENT SYSTEM    \n");
       
    while(1){
        printf("NOTE: IST ENTER THE DATA USING ADMINSTRATION OPTION\n");
        printf(" __________________________________________________________|\n");
        printf("|     SELECT ONE OF THE OPTION TO PROCEED                  |\n");
        printf("|        ENTER ->1: FOR ADMINSTRATION                      |\n");
        printf("|        ENTER ->2: FOR TEACHER                            |\n");
        printf("|        ENTER ->3: FOR STUDENT                            |\n");
        printf("|        ENTER ->4: TO CLOSE THE PROGRAM                   |\n");
        printf("SELECT OPTION: ");
        scanf("%d",&choice);
        if(choice == 1){
            adData = schoolMangementSys();
          
        }
        else if(choice == 2){
            teacherClass( adData);
        }
        else if(choice == 3){
            int select;
            printf(" _____________________________________ \n");
            printf("|_____________ENTER OPTION____________|\n");
            printf("|      1  -> IST  CLASS  CONSOLE      |\n");
            printf("|      2  -> 2ND  CLASS  CONSOLE      |\n");
            printf("|      3  -> 3RD  CLASS  CONSOLE      |\n");
            printf("|      4  -> 4TH  CLASS  CONSOLE      |\n");
            printf("|      5  -> 5TH  CLASS  CONSOLE      |\n");
            printf("|      6  -> 6TH  CLASS  CONSOLE      |\n");
            printf("|      7  -> 7TH  CLASS  CONSOLE      |\n");
            printf("|      8  -> 8TH  CLASS  CONSOLE      |\n");
            printf("|      9  -> 9TH  CLASS  CONSOLE      |\n");
            printf("|      10 -> 10TH  CLASS CONSOLE      |\n");
            printf(" -------------------------------------\n");
            printf("ENTER -> OPTION: ");
            scanf("%d",&select);
            switch(select){
                case 1:{
                    printf(" ____________________________________ \n");
                    printf("|______IST CLASS SELECT SECTION______|\n");
                    printf("|      1 -> SECTION A                |\n");
                    printf("|      2 -> SECTION B                |\n");
                    printf("|____________________________________|\n");
                    printf("ENTER -> OPTION: ");
                    scanf("%d",&option);
                    switch(option){
                        case 1: sectAconsole(adData);
                        break;
                        case 2: sectBconsole(adData);
                        break;
                        default: printf("Wrong Option Entered\n");
                        break; 
                    }
                }
                break;    
                case 2:{
                    printf(" ____________________________________ \n");
                    printf("|______2ND CLASS SELECT SECTION______|\n");
                    printf("|      1 -> SECTION A                |\n");
                    printf("|      2 -> SECTION B                |\n");
                    printf("|____________________________________|\n");
                    printf("ENTER -> OPTION: ");
                    scanf("%d",&option);
                    switch(option){
                        case 1: _2ndScAconsole(adData);
                        break;
                        case 2: _2ndScBconsole(adData);
                        break;
                        default: printf("Wrong Option Entered\n");
                        break; 
                    }
                }
                break;    
                case 3:{
                    printf(" ____________________________________ \n");
                    printf("|______2ND CLASS SELECT SECTION______|\n");
                    printf("|      1 -> SECTION A                |\n");
                    printf("|      2 -> SECTION B                |\n");
                    printf("|____________________________________|\n");
                    printf("ENTER -> OPTION: ");
                    scanf("%d",&option);
                    switch(option){
                        case 1: sectAconsole(adData);
                        break;
                        case 2: sectBconsole(adData);
                        break;
                        default: printf("Wrong Option Entered\n");
                        break; 
                    }
                }
                break;    
                case 4:{
                    printf(" ____________________________________ \n");
                    printf("|______IST CLASS SELECT SECTION______|\n");
                    printf("|      1 -> SECTION A                |\n");
                    printf("|      2 -> SECTION B                |\n");
                    printf("|____________________________________|\n");
                    printf("ENTER -> OPTION: ");
                    scanf("%d",&option);
                    switch(option){
                        case 1: sectAconsole(adData);
                        break;
                        case 2: sectBconsole(adData);
                        break;
                        default: printf("Wrong Option Entered\n");
                        break; 
                    }
                }
                break;    
                case 5:{
                    printf(" ____________________________________ \n");
                    printf("|______IST CLASS SELECT SECTION______|\n");
                    printf("|      1 -> SECTION A                |\n");
                    printf("|      2 -> SECTION B                |\n");
                    printf("|____________________________________|\n");
                    printf("ENTER -> OPTION: ");
                    scanf("%d",&option);
                    switch(option){
                        case 1: sectAconsole(adData);
                        break;
                        case 2: sectBconsole(adData);
                        break;
                        default: printf("Wrong Option Entered\n");
                        break; 
                    }
                }
                break;    
                case 6:{
                    printf(" ____________________________________ \n");
                    printf("|______IST CLASS SELECT SECTION______|\n");
                    printf("|      1 -> SECTION A                |\n");
                    printf("|      2 -> SECTION B                |\n");
                    printf("|____________________________________|\n");
                    printf("ENTER -> OPTION: ");
                    scanf("%d",&option);
                    switch(option){
                        case 1: sectAconsole(adData);
                        break;
                        case 2: sectBconsole(adData);
                        break;
                        default: printf("Wrong Option Entered\n");
                        break; 
                    }
                }
                break;    
                case 7:{
                    printf(" ____________________________________ \n");
                    printf("|______IST CLASS SELECT SECTION______|\n");
                    printf("|      1 -> SECTION A                |\n");
                    printf("|      2 -> SECTION B                |\n");
                    printf("|____________________________________|\n");
                    printf("ENTER -> OPTION: ");
                    scanf("%d",&option);
                    switch(option){
                        case 1: sectAconsole(adData);
                        break;
                        case 2: sectBconsole(adData);
                        break;
                        default: printf("Wrong Option Entered\n");
                        break; 
                    }
                }
                break;    
                case 8:{
                    printf(" ____________________________________ \n");
                    printf("|______IST CLASS SELECT SECTION______|\n");
                    printf("|      1 -> SECTION A                |\n");
                    printf("|      2 -> SECTION B                |\n");
                    printf("|____________________________________|\n");
                    printf("ENTER -> OPTION: ");
                    scanf("%d",&option);
                    switch(option){
                        case 1: sectAconsole(adData);
                        break;
                        case 2: sectBconsole(adData);
                        break;
                        default: printf("Wrong Option Entered\n");
                        break; 
                    }
                }
                break;    
                case 9:{
                    printf(" ____________________________________ \n");
                    printf("|______IST CLASS SELECT SECTION______|\n");
                    printf("|      1 -> SECTION A                |\n");
                    printf("|      2 -> SECTION B                |\n");
                    printf("|____________________________________|\n");
                    printf("ENTER -> OPTION: ");
                    scanf("%d",&option);
                    switch(option){
                        case 1: sectAconsole(adData);
                        break;
                        case 2: sectBconsole(adData);
                        break;
                        default: printf("Wrong Option Entered\n");
                        break; 
                    }
                }
                break;    
                case 10:{
                    printf(" ____________________________________ \n");
                    printf("|______IST CLASS SELECT SECTION______|\n");
                    printf("|      1 -> SECTION A                |\n");
                    printf("|      2 -> SECTION B                |\n");
                    printf("|____________________________________|\n");
                    printf("ENTER -> OPTION: ");
                    scanf("%d",&option);
                    switch(option){
                        case 1: sectAconsole(adData);
                        break;
                        case 2: sectBconsole(adData);
                        break;
                        default: printf("Wrong Option Entered\n");
                        break; 
                    }
                }
                break;    
                default: printf("ENTER WRONG OPTION\n");
                  
                 
            }
        }
        else if(choice == 4){
            break;
        }
        else{
            printf("ENTER THE WRONG OPTION......\n");
        }

    }
    free(adData->_1stA);
    free(adData->_1stB);
    free(adData);
}
void dataLoad(){
    FILE *f = fopen("teacher.txt", "r");
    int i = 0;
    while(!feof(f)){
        fscanf(f,"%s\t%s\t%s\n",adData->tch[i].name,adData->tch[i].id,adData->tch[i].subject);
    }
    fclose(f);
}

