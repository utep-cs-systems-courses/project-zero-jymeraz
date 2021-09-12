#include <stdio.h>
#include "draw.h"

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Arrow = a, Triangle = t, Square = s, Font1 = 1, Font2 = 2, Font3 = 3) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 'a':
      puts("Your selected arrow:");
      print_arrow();
      break;
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case '1':
      puts("You selected Font1:");
      for (char c = 'A'; c < 'D'; c++)
	print_char_11x16(c);
      break;
    case '2':
      puts("You selected Font2:");
      for (char c = 'A'; c < 'D'; c++)
	print_char_5x7(c);
      break;
    case '3':
      puts("You selected Font3:");
      for (char c = 'A'; c < 'D'; c++)
	print_char_8x12(c);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
