#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void reverse(char * str) {
  //WRITE ME!
  //if(str==NULL) return;
  char arr[1000];
  char *a= arr; int n=0;

  while(*str!='\0')
    {
      *a= *str;
      str++;
      a++;
      n++;
    }
  *a='\0';
  a-=n;
  str--;
  while(*a!='\0')
    {
      *str= *a;
      str--;
      a++;
    }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  if(str==NULL) return;
  char arr[1000];
  char *a= arr; int n=0;

  while(*str!='\0')
    {
      *a= *str;
      str++;
      a++;
      n++;
    }
  *a='\0';
  a-=n;
  str--;
  while(*a!='\0')
    {
      *str= *a;
      str--;
      a++;
    }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}

