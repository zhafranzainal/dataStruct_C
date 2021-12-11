#include <stdio.h>

#define MAX 10

//Function Declaration (Prototype)
void search_binary(int element[MAX], int totalElement, int searchValue);

int main(void){

    int totalElement, element[MAX], loop1, loopNext, temp, searchValue;

    printf("Enter list size : ");
    scanf(" %d", &totalElement);

    printf("\n");

    for(loop1=0;loop1<totalElement;loop1++){
        printf("Enter number    : ");
        scanf(" %d", &element[loop1]);}

    for(loop1=0;loop1<totalElement;loop1++){
        for(loopNext=loop1+1; loopNext<totalElement; loopNext++){
            if(element[loop1]>element[loopNext]){
                temp=element[loop1];
                element[loop1]=element[loopNext];
                element[loopNext]=temp;}}}

    printf("\nEnter key value for binary search: ");
    scanf(" %d", &searchValue);

    printf("\nSorted list of element entered:");
    for(loop1=0;loop1<totalElement;loop1++){
        printf(" %d", element[loop1]);}

    printf("\n");

    //Function Calling: search_binary
    search_binary(element, totalElement, searchValue);

    printf("\n");

return 0;
}

//Function Definition: search_binary
void search_binary(int element[MAX], int totalElement, int searchValue){

    int elemFirst=0, elemLast=totalElement-1, elemMid, loop=0;

    while(elemFirst<=elemLast){

        ++loop;

        elemMid=(elemFirst+elemLast)/2;
        printf("\nValue for mid: %d", elemMid);

        if(searchValue==element[elemMid]){
            printf("\n\nKey match found in data[%d]", elemMid);
            printf("\nNumber of comparison is %d", loop);
            return;}

		else{

            if(searchValue<element[elemMid]){
                elemLast=elemMid-1;}
			else{
				elemFirst=elemMid+1;}}
	}

    printf("\n\nNo match found!");
}
