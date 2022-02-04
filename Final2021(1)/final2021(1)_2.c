#include <stdio.h>

//Function Declaration (Prototype)
void sort_bubbleDesc(int num[], int totalNum, int max);
void sort_bubbleAsc(int num[], int totalNum, int max);

int main(void){

    int totalNum, max, loop;
    int num1[5]={7, 5, 3, 8, 1}, num2[5]={7, 5, 3, 1, 8};

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

    for(loop=0;loop<totalNum;loop++){
        printf(" %d", num1[loop]);}
    printf("\n");
    sort_bubbleDesc(num1, totalNum, max);

    for(loop=0;loop<totalNum;loop++){
        printf(" %d", num2[loop]);}
    printf("\n");
    sort_bubbleAsc(num2, totalNum, max);

    //Sorted list
    printf(" Sorted list:");
    for(loop=0;loop<totalNum;loop++){
        printf(" %d", num2[loop]);}

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
            if(totalNum>1){
                printf(" %d", num[loop]);}
        }

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
            if(totalNum>1){
                printf(" %d", num[loop]);}
        }

        printf("\n");

    }

}
