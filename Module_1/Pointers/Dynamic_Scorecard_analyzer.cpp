#include<stdio.h>
#include<stdlib.h>

// Taking input for the inning score
void inputScores(int* scoresPtr, int size){
    for(int i=0; i<size; i++){
        printf("Enter the score for Game %d (0-100): \n", i+1);
        do{
            scanf("%d", scoresPtr+i);
            if(*(scoresPtr+i) >=0 && *(scoresPtr+i) <=100){
                break;
            }
            else{
                printf("Invalid score. Must be between 0 and 100. Please re-enter.");
            }
        }while(1);
    }
}

// Function to calculate the average 
double calculateAverage(const int* scoresPtr, int size){
    double sum = 0.0;
    for(int i=0; i<size; i++){
        sum += *(scoresPtr+i);
    }
    return sum/size;
}

//Function for calculating highest score
int findHighest(const int* scoresPtr, int size){
    int highest = scoresPtr[0];
    for(int i=1; i<size; i++){
        if(*(scoresPtr+i) >highest){
            highest = *(scoresPtr+i);
        }
    }
    return highest;
}

// Function to display all the result
void display(int* scorePtr, int size){
    inputScores(scorePtr,size);
    //Calling average function
    double ans = calculateAverage(scorePtr,size);
    //Calling hihghest score function
    int highest_score = findHighest(scorePtr,size);

    printf("The average inning score is %.2f\n",ans);
    printf("The highest innning score is %d\n",highest_score);

}

int main(){
    //Allocating dynamic memory for number of games
    int* numGames = (int*)malloc(sizeof(int));
    if(numGames == NULL){
        printf("Memory not allocated properly!!\n");
        return 1;
    }
    do{
        printf("Enter the number of innings\n");
        scanf("%d", numGames);
        if(*numGames<=0){
            printf("Number of games must be positive. Please re-enter.\n");
        }
    }while(*numGames<=0);

    int* inningScores = (int*)malloc((*numGames) * sizeof(int));
     if (inningScores == NULL) {
        printf("Memory allocation failed!\n");
        free(numGames);
        return 1;
    }
    display(inningScores,*numGames);
    
    //Freeing up memory after using
    free(numGames);
    free(inningScores);
    //Prevention from dangling pointers
    numGames = NULL;
    inningScores = NULL;
    return 0;
}