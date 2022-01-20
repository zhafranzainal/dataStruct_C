#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function Declaration (Prototype)
void sort_selection(int randomNum[], int totalNum);
clock_t timer_begin();
clock_t timer_end(clock_t timeBegin);

int totalCompare=0, totalMove=0;

int main(void){

    double timeBegin;
    int loop, totalNum=0, randomNum[100000];
    float elapseTicks, elapseMsec, elapseSec;

    printf("BEFORE SORTING:\n\n");

    FILE *randomNumberList;

    //read from file
    randomNumberList = fopen("listOfRandomNum.txt", "r");

    while(fscanf(randomNumberList, "%d", &randomNum[totalNum])!=EOF){
        printf("%d\t", randomNum[totalNum]);
        totalNum++;}

    fclose(randomNumberList);

    printf ("\n\nTimer set to: %.2f", timeBegin);
    timeBegin = timer_begin();

    sort_selection(randomNum, totalNum);

    printf("\n\nAFTER SORTING (selection sort):\n\n");

    for(loop=0;loop<totalNum;loop++){
        printf("%d\t", randomNum[loop]);}

    printf("\n\nNumber of data compares = %d", totalCompare);
    printf("\nNumber of data moves    = %d", totalMove);

    elapseTicks = timer_end(timeBegin);
    elapseMsec = elapseTicks/1000;
    elapseSec = elapseMsec/1000;

    printf("\n\nRunning time (in milliseconds)  = %.2f", elapseMsec);
    printf("\nRunning time (in seconds)       = %.2f", elapseSec);

    printf("\n");

return 0;
}

//Function Definition: sort_selection
void sort_selection(int randomNum[], int totalNum){

    int smallest;
	int sort1, sort2, temp;

	for(sort1=0;sort1<totalNum;sort1++){
        smallest=sort1;

        for(sort2=sort1+1;sort2<totalNum;sort2++){

            if(randomNum[sort2]<randomNum[smallest]){
                smallest=sort2;}

            totalCompare++;
        }

        temp=randomNum[sort1];
        totalMove++;
        randomNum[sort1]=randomNum[smallest];
        totalMove++;
        randomNum[smallest]=temp;
        totalMove++;
    }

}

//Function Definition: timer_begin
clock_t timer_begin(){

    clock_t Begin;

    //start timer
    Begin=clock()*CLK_TCK;

    return Begin;
}

//Function Definition: timer_end
clock_t timer_end(clock_t timeBegin){

    clock_t End;

    //stop timer
    End=clock()*CLK_TCK;

    return End;
}
