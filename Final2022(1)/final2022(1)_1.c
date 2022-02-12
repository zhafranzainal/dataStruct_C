#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure Declaration (Template)
struct River{

    //Data Field
    char state[20];
    char riverName[30];
    int waterQualityIndex;
    char category[5];

    //Pointer (Link) Field
    struct River *ptrNext;};

struct River *ptrHead, *ptrNew, *ptrCurrent, *ptrCopy, *kelantan, *pahang, *terengganu;

//Function Declaration (Prototype)
void insert_riverInfo();
void display_riverInfo();
void copy_riverInfo();
void display_riverState(struct River *head);

int main(void){

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Kelantan");
    strcpy(ptrNew->riverName, "Sg. Alor B");
    ptrNew->waterQualityIndex=50;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Pahang");
    strcpy(ptrNew->riverName, "Sg. Jebong");
    ptrNew->waterQualityIndex=56;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Pahang");
    strcpy(ptrNew->riverName, "Sg. Singol");
    ptrNew->waterQualityIndex=57;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Pahang");
    strcpy(ptrNew->riverName, "Sg. Semberong");
    ptrNew->waterQualityIndex=59;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Terengganu");
    strcpy(ptrNew->riverName, "Sg. Ransan");
    ptrNew->waterQualityIndex=68;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Terengganu");
    strcpy(ptrNew->riverName, "Sg. Ruang");
    ptrNew->waterQualityIndex=71;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Kelantan");
    strcpy(ptrNew->riverName, "Sg. Keladi");
    ptrNew->waterQualityIndex=74;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Pahang");
    strcpy(ptrNew->riverName, "Sg. Bebar");
    ptrNew->waterQualityIndex=75;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Kelantan");
    strcpy(ptrNew->riverName, "Sg. Pengkalan Chepa");
    ptrNew->waterQualityIndex=76;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Pahang");
    strcpy(ptrNew->riverName, "Sg. Belat");
    ptrNew->waterQualityIndex=77;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Pahang");
    strcpy(ptrNew->riverName, "Sg. Tekam");
    ptrNew->waterQualityIndex=78;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Kelantan");
    strcpy(ptrNew->riverName, "Sg. Kelantan");
    ptrNew->waterQualityIndex=79;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Pahang");
    strcpy(ptrNew->riverName, "Sg. Jengka");
    ptrNew->waterQualityIndex=80;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Pahang");
    strcpy(ptrNew->riverName, "Sg. Pandan");
    ptrNew->waterQualityIndex=82;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Kelantan");
    strcpy(ptrNew->riverName, "Sg. Berok");
    ptrNew->waterQualityIndex=84;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Terengganu");
    strcpy(ptrNew->riverName, "Sg. Dungun");
    ptrNew->waterQualityIndex=85;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Terengganu");
    strcpy(ptrNew->riverName, "Sg. Besut");
    ptrNew->waterQualityIndex=86;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Kelantan");
    strcpy(ptrNew->riverName, "Sg. Betis");
    ptrNew->waterQualityIndex=87;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Pahang");
    strcpy(ptrNew->riverName, "Sg. Burung");
    ptrNew->waterQualityIndex=90;
    insert_riverInfo();

    ptrNew=(struct River *)malloc(sizeof(struct River));
    strcpy(ptrNew->state, "Kelantan");
    strcpy(ptrNew->riverName, "Sg. Ber");
    ptrNew->waterQualityIndex=91;
    insert_riverInfo();

    display_riverInfo();
    copy_riverInfo();

return 0;
}

//Function Definition: insert_riverInfo
void insert_riverInfo(){

    if(ptrHead==NULL){
        ptrHead=ptrNew;
        ptrNew->ptrNext=NULL;}

    else{
        ptrCurrent=ptrHead;

        while(ptrCurrent->ptrNext!=NULL){
            ptrCurrent=ptrCurrent->ptrNext;}

        ptrCurrent->ptrNext=ptrNew;
        ptrNew->ptrNext=NULL;}

}

//Function Definition: display_riverInfo
void display_riverInfo(){

    if(ptrHead==NULL){
        printf("No river registered in the system yet.\n");}

    else{
        printf("State\t\t River\t\t\t WQI\t Category\n");
        printf("=========================================================\n");
        ptrCurrent=ptrHead;

        do{

            if(ptrCurrent->waterQualityIndex<60){
                strcpy(ptrCurrent->category, "P");}

            else if(ptrCurrent->waterQualityIndex<=80){
                strcpy(ptrCurrent->category, "SP");}

            else{
                strcpy(ptrCurrent->category, "C");}

            printf("%-14s %-25s %-10d %s", ptrCurrent->state, ptrCurrent->riverName, ptrCurrent->waterQualityIndex, ptrCurrent->category);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

}

//Function Definition: copy_riverInfo
void copy_riverInfo(){

    kelantan=NULL;
    pahang=NULL;
    terengganu=NULL;

    if(ptrHead==NULL){
        printf("No river registered in the system yet.\n");}

    else{

        ptrCurrent=ptrHead;

        do{

            ptrCopy=(struct River *)malloc(sizeof(struct River));

            if(strcmp(ptrCurrent->state, "Kelantan")==0){

                strcpy(ptrCopy->state, ptrCurrent->state);
                strcpy(ptrCopy->riverName, ptrCurrent->riverName);
                ptrCopy->waterQualityIndex=ptrCurrent->waterQualityIndex;
                strcpy(ptrCopy->category, ptrCurrent->category);

                if(kelantan==NULL){
                    ptrCopy->ptrNext=NULL;
                    kelantan=ptrCopy;}
                else{
                    ptrCopy->ptrNext=kelantan;
                    kelantan=ptrCopy;}
            }

            else if(strcmp(ptrCurrent->state, "Pahang")==0){

                strcpy(ptrCopy->state, ptrCurrent->state);
                strcpy(ptrCopy->riverName, ptrCurrent->riverName);
                ptrCopy->waterQualityIndex=ptrCurrent->waterQualityIndex;
                strcpy(ptrCopy->category, ptrCurrent->category);

                if(pahang==NULL){
                    ptrCopy->ptrNext=NULL;
                    pahang=ptrCopy;}
                else{
                    ptrCopy->ptrNext=pahang;
                    pahang=ptrCopy;}
            }

            else{

                strcpy(ptrCopy->state, ptrCurrent->state);
                strcpy(ptrCopy->riverName, ptrCurrent->riverName);
                ptrCopy->waterQualityIndex=ptrCurrent->waterQualityIndex;
                strcpy(ptrCopy->category, ptrCurrent->category);

                if(terengganu==NULL){
                    ptrCopy->ptrNext=NULL;
                    terengganu=ptrCopy;}
                else{
                    ptrCopy->ptrNext=terengganu;
                    terengganu=ptrCopy;}
            }

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

    display_riverState(kelantan);
    display_riverState(pahang);
    display_riverState(terengganu);

}

//Function Definition: display_riverState
void display_riverState(struct River *head){

    if(head==NULL){
        printf("\nNo river registered in the system yet.\n");}

    else{
        printf("\nState\t\t River\t\t\t WQI\t Category\n");
        printf("=========================================================\n");
        ptrCurrent=head;

        do{

            printf("%-14s %-25s %-10d %s", ptrCurrent->state, ptrCurrent->riverName, ptrCurrent->waterQualityIndex, ptrCurrent->category);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

}
