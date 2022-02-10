#include <stdio.h>

//Function Declaration (Prototype)
void sort_bubble(int num[],int totalNum);

int main(void){

    int totalNum, loop;

    printf("Enter list size: ");
    scanf(" %d", &totalNum);

    int num[totalNum];

    printf("\n");

    for(loop=0;loop<totalNum;loop++){
        printf("Enter number: ");
        scanf(" %d", &num[loop]);}

    //Sorting process
    printf("\nSorting process:-\n\n");;

    sort_bubble(num, totalNum);

    //Sorted list
    printf("\nSorted list: ");
    for(loop=0;loop<totalNum;loop++){
        printf(" %d", num[loop]);}

    printf("\n");

return 0;
}

void sort_bubble(int num[],int totalNum){

    int temp, loop, max=totalNum;

    while(max>1){
        max--;

        for(loop=0;loop<max;loop++){
            if(num[loop]<num[loop+1]){
                temp=num[loop];
                num[loop]=num[loop+1];
                num[loop+1]=temp;}
        }

        for(loop=0;loop<totalNum;loop++){
            printf(" %d", num[loop]);}

        printf("\n");
    }

    printf("\n");
    max=totalNum;

    while(max>1){
        max--;

        for(loop=0;loop<max;loop++){
            if(num[loop]>num[loop+1]){
                temp=num[loop];
                num[loop]=num[loop+1];
                num[loop+1]=temp;}
        }

        for(loop=0;loop<totalNum;loop++){
            printf(" %d", num[loop]);}

        printf("\n");
    }

}
