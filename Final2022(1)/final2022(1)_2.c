#include <stdio.h>

#define LENGTH 50
#define COUNTRY 10
#define CASE_COLUMN 4

//Function Declaration (Prototype)
void sort_quick(int randomNum[], int bottom, int top);

int main(void){

    char country[][LENGTH]={"USA", "INDIA", "BRAZIL", "UK", "RUSSIA", "TURKEY", "FRANCE", "IRAN", "ARGENTINA", "SPAIN"};

    int casesOrigin[COUNTRY][CASE_COLUMN]=
        {{45549842, 739803, 35107459, 9702580},
        {34023005, 451509, 33362709, 208787},
        {21597949, 601643, 20740267, 256039},
        {8272883, 138080, 6765629, 1369174},
        {7892980, 220315, 6937756, 734909},
        {7540223, 66841, 6987778, 485604},
        {7069089, 117173, 6860549, 91367},
        {5754047, 123498, 5280624, 349925},
        {5268653, 115582, 5135343, 17728},
        {4980206, 86869, 4823235, 70102}};

    int cases[]={739803, 451509, 601643, 138080, 220315, 66841, 117173, 123498, 115582, 86869};

    int loop, totalNum=sizeof(casesOrigin)/sizeof(casesOrigin[0]);

    printf("BEFORE SORTING:\n\n");

    for(loop=0;loop<totalNum;loop++){
        printf("%d\t", cases[loop]);}

    printf("\n\nAFTER SORTING (quick sort):\n\n");
    sort_quick(cases, 0, totalNum-1);

    for(loop=0;loop<totalNum;loop++){
        printf("%d\t", cases[loop]);}

    printf("\n");

return 0;
}

//Function Definition: sort_quick
void sort_quick(int cases[], int bottom, int top){

    int left, right, temp, pivot, flag;

    if(top>bottom){
        pivot=cases[top];
        right=top;
        left=bottom-1;

        do{
            flag=1;
            while(cases[++left]<pivot);
            while(cases[--right]>pivot);

            if(left<right){
                temp=cases[left];
                cases[left]=cases[right];
                cases[right]=temp;}

            else{
                break;}

        }while(flag>0);

        temp=cases[left];
        cases[left]=cases[top];
        cases[top]=temp;

        sort_quick(cases, bottom, left-1);
        sort_quick(cases, left+1, top);

    }

}
