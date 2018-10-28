#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


/** returns random char in list of chars need to make test fail **/
char inputChar()
{
    // TODO: rewrite this function
    char ascii[14] = { '\0', 'r', 'e', 's', 't', '[', ']', '{', '}', '(', ')', 'a', 'x', ' ' };   //array of all possible chars need to make test fail

    int idx = rand() % 14;	//produce rand num, 0 to (array len -1)

    return ascii[idx];		//return char at index of random number
}

/** returns a string in len 0 - 8 consisting of random chars needed to make test fail **/
char *inputString()
{
    // TODO: rewrite this function
    char chars[8];		//char array of length 8
    char *string;		//pointer to a char

    string = chars;		//point char pointer to char array
    

    for(int i = 0; i < 8; i++) {	//loop 8 times - to fill char array
	chars[i] = inputChar();		//call input char to get random char or null terminator
    }

    // return pointer to char array
    return string;



}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
