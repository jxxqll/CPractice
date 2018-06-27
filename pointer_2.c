

#include <stdio.h>

int main() {
    
    char * name = (char *) malloc(3* sizeof(char));
    name[0] = 'A';
    name[1] = 'B';
    name[2] = 'C';
    
    printf("show pointer name's position: %x \n", &name);

    printf("before str is %s \n", name);
  
      
    processChar(name);
    
    printf("after str is %s\n", name);
    
    free(name);   //free the pointer's allocated memory   void free(pointer)
    return 0;
}

void processChar (char * pchar)
{
    printf("show pointer parameter position: %x \n", &pchar);
    printf("enter method \n");
       *pchar =  'x';
   printf("end of method\n");
}
 
    