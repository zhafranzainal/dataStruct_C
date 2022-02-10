#include <stdio.h>

//Function Declaration (Prototype)
void sort_bubbleDesc(int num[], int totalNum, int max);
void sort_bubbleAsc(int num[], int totalNum, int max);

int main(void){

    int totalNum, max, loop;

    printf("Enter list size: ");
    scanf(" %d", &totalNum);

    max=totalNum;
    int num[totalNum];

    printf("\n");

    for(loop=0;loop<totalNum;loop++){
        printf("Enter number: ");
        scanf(" %d", &num[loop]);}

    //Sorting process
    printf("\nSorting process:-\n\n");

    sort_bubbleDesc(num, totalNum, max);
    printf("\n");
    sort_bubbleAsc(num, totalNum, max);

    //Sorted list
    printf("\n Sorted list:");
    for(loop=0;loop<totalNum;loop++){
        printf(" %d", num[loop]);}

    printf("\n");

return 0;
}

//Function Definition: sort_bubbleDesc
void sort_bubbleDesc(int num[], int totalNum, int max){

    int temp, loop;

    while(totalNum>1){
        totalNum--;

        for(loop=0;loop<totalNum;loop++){
            if(num[loop]<num[loop+1]){
                temp=num[loop];
                num[loop]=num[loop+1];
                num[loop+1]=temp;}
        }

        for(loop=0;loop<max;loop++){
            printf(" %d", num[loop]);}

        printf("\n");

    }

}

//Function Definition: sort_bubbleAsc
void sort_bubbleAsc(int num[], int totalNum, int max){

    int temp, loop;

    while(totalNum>1){
        totalNum--;

        for(loop=0;loop<totalNum;loop++){
            if(num[loop]>num[loop+1]){
                temp=num[loop];
                num[loop]=num[loop+1];
                num[loop+1]=temp;}
        }

        for(loop=0;loop<max;loop++){
            printf(" %d", num[loop]);}

        printf("\n");

    }

}
