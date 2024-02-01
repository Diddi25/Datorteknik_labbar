
#include <stdio.h>
#include <stdlib.h>

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";

int *list1;
int *list2;
int *count;

void copycodes(char *text, int *list, int *count) {
  *count = 0;
  while(*text != '\0') {
    unsigned int eight_bits = *text & 0xff; //extraherar 8 bits
    *list = eight_bits; //lägger 8 bitarna i cellen som pekas av *list
    text++; //inkrementerar text1
    list++; //
    (*count)++;
  }
  printf("Contents of list:\n");
  for(int i = 0; i < *count; i++) {
    printf("%d \n", *(list - *count + i)); // Print each element of the list
  }
  /*  
  while(*list != '\0'){
    printf("%d ", *list);
    list++;
  }
  */
  printf("End of list\n");
}

int countElements(char *text) {
  int nr_of_elements = 1;
  char *temporary_text_iterator = text1;
  while(*temporary_text_iterator != '\0') {
    temporary_text_iterator++;
    nr_of_elements++;
  }
  return nr_of_elements;
}

void work() {
  int nr_of_elements = countElements(text1);
  printf("Antalet element: %d\n",nr_of_elements); //18
  list1 = (int *) malloc(nr_of_elements*sizeof(char));
  count = (int *) malloc(sizeof(int));
  copycodes(text1, list1, count);
  free(list1);
  free(count);

  nr_of_elements = countElements(text2);
  list2 = (int *) malloc(nr_of_elements*sizeof(char));
  count = (int *) malloc(sizeof(int));
  copycodes(text2, list2, count);
  free(list2);
  free(count);
}

void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n", 
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));
  
}

int main(void){
  work();
  printf("kommer den hit?");

  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
}
