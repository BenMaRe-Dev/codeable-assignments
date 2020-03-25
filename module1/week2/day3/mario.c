#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int n;
  do
  {
    n = get_int("Choose the size of the pyramid - just numbers between 1 and 8: ");
  } while (n < 1 || n > 8);
  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < n; y++)
    {
      if (x + y < n - 1)
      {
        printf(" ");
      }
      else
      {
        printf("#");
      }
    }
    printf(" ");
    printf(" ");
    for (int y = 0; y < n; y++)
    {
      if (n - x < y + 2)
      {
        printf("#");
      }
    }
    printf("\n");
  }
}