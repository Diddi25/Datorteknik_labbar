
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#define COLUMNS 6

void print_number(int n) {
  printf("%10d ", n);
}

void check_sieve_nr(int sieve_numbers[], int length) {
    for(int i = 2; i < sqrt(length); i++) {
        if(sieve_numbers[i] == 1)
            for(int j = i*i; j<length; j+=i) {
                sieve_numbers[j] = 0;
            }
    }
}

void print_sieves(int max_prime_number) {
    //initiate an array with boolean true (=1) values
    //int boolean_sieve_numbers[max_prime_number -1];
    int *boolean_sieve_numbers = (int *) malloc(sizeof(int)*(max_prime_number-1));
    //fill with true values
    for(int i = 0; i < max_prime_number; i++) {
        boolean_sieve_numbers[i] = 1;
    }
    //test the array values
    check_sieve_nr(boolean_sieve_numbers, max_prime_number);

    //print logic
    int column_nr = 1;
    for(int i = 2; i < max_prime_number; i++) {
        if(boolean_sieve_numbers[i] == 1) {
            if(column_nr > COLUMNS) {
                printf("\n");
                column_nr = 1;
            }
            print_number(i); //all primes are marked with "1"
            column_nr++;
        }
    }
    free(boolean_sieve_numbers);
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}

