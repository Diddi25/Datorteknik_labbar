
#include <stdio.h>

int number[10];

int main() {
    int *p = number; //p pekar på första elementet i number
    int i = 10;      //i initieras med 10

    do{
        *p = i;  //p pekar på första elementet i number som blir i
        p++;     //p pekar på nästa element i arrayen
        i--;     // i dekrementeras med 1
    } while(i != 0); //så länge i inte är 0

    p = number; //innehållet i p blir till första elementet i number
    int result = *p + (*(p+1)); //
    printf("Result : %d\n", result);
}