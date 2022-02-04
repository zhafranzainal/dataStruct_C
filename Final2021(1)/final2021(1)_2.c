#include <stdio.h>

//Function Declaration (Prototype)
void sort_bubble(int num[], int totalNum);

int main(void){

    int totalNum, loop;

    printf("Enter list size: ");
    scanf(" %d", &totalNum);

    int num[totalNum];

    printf("\n");

    for(loop=0;loop<totalNum;loop++){
        printf("Enter number: ");
        scanf(" %d", &num[loop]);}

    printf("\nBefore sorting    :");
    for(loop=0;loop<totalNum;loop++){
        printf(" %d", num[loop]);}

    printf("\n\nSorting process:-\n\n");
    sort_bubble(num, totalNum);

    printf("\nSorted list       :");
    for(loop=0;loop<totalNum;loop++){
        printf(" %d", num[loop]);}

    printf("\n");

return 0;
}

//Function Definition: sort_bubble
void sort_bubble(int num[], int totalNum){

    int temp, loop;

    while(totalNum>1){
        totalNum--;

        for(loop=0;loop<totalNum;loop++){

            if(num[loop]>num[loop+1]){
                temp=num[loop];
                num[loop]=num[loop+1];
                num[loop+1]=temp;}
        }

        for(loop=0;loop<5;loop++){
            printf(" %d", num[loop]);}

        printf("\n");

    }

}
