#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define size 20

void
check_neighborhoods(int x, int y, int field[][size], int tmp_field[][size])
{
  int neihgborhoods = 0;
  int xp = 0;
  int yp = 0;
  for (xp = -1; xp <= 1; xp++)
    {
      for (yp = -1; yp <= 1; yp++)
        {
          if (((xp + x > 0 || xp + x <size)
             &&(yp + y > 0 || yp + y <size ))
             &&(xp !=0 || yp !=0) && field[xp + x][yp + y] == 1 )
            {
              neihgborhoods++;
            }
        }
    }
  if (field[x][y] == 0 && neihgborhoods == 3)
    {
      tmp_field[x][y] = 1;
    }
  else if (field[x][y] == 1 && (neihgborhoods == 2 || neihgborhoods == 3))
    {
      tmp_field[x][y] = 1;
    }
  else
    {
      tmp_field[x][y] = 0;
    }
}

void
zerofy_2d_array(int array[][size])
{
  memset(array, 0, sizeof(array[0])  * size);
}

void
ClearScreen()
{
  int n;
  for (n = 0; n < 10; n++)
    {
      printf( "\n\n\n\n\n\n\n\n\n\n" );
    }
}



void
next_step(int field[][size], int tmp_field[][size])
{
  int i,j,x,y;
  for (x = 0; x < size; x++)
    {
      for (y = 0; y < size; y++)
        {
          check_neighborhoods(x, y, field, tmp_field);
        }
    }
  ClearScreen();
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      printf("%d ", field[i][j]);
    }
    printf("\n");
  }
  memcpy(field, tmp_field, sizeof(tmp_field[0]) * size);
  zerofy_2d_array(tmp_field);
}

int
main()
{
  srand((unsigned) time(NULL));
  int steps = 100;
  int step = 0;
  int field[size][size] = {{0}};
  int tmp_field[size][size]= {{0}};

  zerofy_2d_array (field);
  zerofy_2d_array (tmp_field);
  int i, j;
  for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++)
        {
          field[i][j] =  rand() & 1; // = 0 for clean array
          printf("%d ", field[i][j]);
        }
      printf("\n");
    }
  // Glider
  //field[10][10] = 1;
  //field[11][10] = 1;
  //field[12][10] = 1;
  //field[12][9]  = 1;
  //field[11][8]  = 1;

  while (step < steps)
    {
      next_step(field, tmp_field);
      usleep(70000);
      step++;
    }
  return 0;
}
