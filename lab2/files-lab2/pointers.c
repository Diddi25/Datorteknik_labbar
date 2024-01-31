
#include <stdio.h>

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";

int nr_of_elements = sizeof(*text1)/sizeof(char);
int *list1 = malloc(nr_of_elements*sizeof(int));

int *list1;
int *list2;
char *count;

void work() {
  int *a0 = text1;
  int *a1 = list1;
  int *a2 = count;
  copycodes();

  //
}

void copycodes() {
  //så länge char *text1 inte är null
  while() {
    //ska pekaren på text1 = text1++;
    //denna pekare sparar värdet på *list

    //innehållet i count stegras med 1
    //sparar det nya värdet på count i pekaren på count
  }
  

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

  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
}
