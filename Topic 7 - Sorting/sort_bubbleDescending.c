#include <stdio.h>
#include <string.h>

//Function Declaration (Prototype)
void sort_bubble(char array[], int stringLength);

int main(void){

    char array[50]="THISISATEST";
    int loop, arraySize=0, stringLength;

    stringLength=strlen(array);

    printf("Descending unsorted : %s\n", array);

    sort_bubble(array, stringLength);

    printf("Descending sorted   : %s", array);

    printf("\n");

return 0;
}

//Function Definition: sort_bubble
void sort_bubble(char array[], int stringLength){

    int temp, loop;

    while(stringLength>1){
        stringLength--;

        for(loop=0;loop<stringLength;loop++){

            if(array[loop]<array[loop+1]){
				temp=array[loop+1];
				array[loop+1]=array[loop];
				array[loop]=temp;}
        }
    }

}
