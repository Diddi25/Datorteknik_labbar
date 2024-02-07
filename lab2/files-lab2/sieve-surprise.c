#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#define COLUMNS 6

void print_number(int n) {
  printf("%10d ", n);
}

void check_sieve_nr(int sieve_numbers[], int length) {
    for(int i = 2; i < length*10; i++) {
        if(sieve_numbers[i] == 1)
            for(int j = i*i; j<length*10; j+=i) {
                sieve_numbers[j] = 0;
            }
    }
}

/*
int search_prime_index(int index) {
    int nr_of_primes = 0;
    for(int i = 2; i < index; i++) {
        if(sieve_numbers[i] == 1)
            for(int j = i*i; j<length; j+=i) {
                sieve_numbers[j] = 0;
            }
    }
    while(nr_of_primes  < index) {

    }
    return nr_of_primes;
}*/

void print_sieves(int prime_index) {
    //initiate an array with boolean true (=1) values
    int boolean_sieve_numbers[((prime_index*10)-2)];
    //fill with true values
    for(int i = 0; i < ((prime_index*10)-2); i++) {
        boolean_sieve_numbers[i] = 1;
    }
    //test the array values
    check_sieve_nr(boolean_sieve_numbers, prime_index);

    //print logic
    int column_nr = 1;
    int counter = 0;
    /*
    for(int i = 2; i < ((prime_index*10)-2); i++) {
        if(boolean_sieve_numbers[i] == 1 && counter) {
            counter++;
            if(column_nr > COLUMNS) {
                printf("\n");
                column_nr = 1;
            }
            print_number(i); //all primes are marked with "1"
            column_nr++;
        }
    }*/
    for(int i = 2; i < (prime_index*10-2); i++) {
        if(boolean_sieve_numbers[i-2] != 0) {
            counter++;
            if(boolean_sieve_numbers[prime_index] == counter) {
                print_number(i);
            }
        }
    }
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

