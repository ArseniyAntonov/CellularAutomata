#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define size 100
struct Ants
{
  int x;
  int y;
  int direction; //1-up 2-right 3-down 4-left
};

void
ClearScreen()
{
  int n;
  for (n = 0; n < 10; n++)
    {
      printf( "\n\n\n\n\n\n\n\n\n\n" );
    }
}



void draw_array(int field[][size])
{
  int i, j;
  ClearScreen();
  for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++)
        {
          if (field[i][j] ==1 )
            {
              printf ("*");
            }
          else
            {
              printf (".");
            }
        }
      printf("\n");
    }

}


void
zerofy_2d_array(int array[][size])
{
  memset(array, 0, sizeof(array[0])  * size);
}


void
move_forward(struct Ants *ant)
{
  if (ant->direction ==1 )
    {
      if (ant->y > 0)
        {
          ant->y--;
        }
      else
        {
          ant->y=size-1;
        }
    }
  if (ant->direction ==2 )
    {
      if (ant->x < size-1)
        {
          ant->x++;
        }
      else
        {
          ant->x=0;
        }


    }
  if (ant->direction ==3 )
    {
      if (ant->y < size-1)
        {
          ant->y++;
        }
      else
        {
          ant->y=0;
        }

    }
  if (ant->direction ==4 )
    {
      if (ant->x > 0)
        {
          ant->x--;
        }
      else
        {
          ant->x=size-1;
        }

    }



}

void
turn(struct Ants *ant, int turn)
{
  if (turn == 1)
    {
      ant->direction ++;
    }
  else if (turn == 0 )
    {
      ant->direction--;
    }
  if (ant->direction > 4)
    {
      ant->direction = 1;
    }
  else if (ant->direction < 1 )
    {
      ant->direction = 4;
    }
}
  void
  next_step(int field[][size], struct Ants *ant)
  {

    if (field[ant->x][ant->y] == 1)
      {
        turn(ant, 1);
        field[ant->x][ant->y] =0;
      }
    else if (field[ant->x][ant->y] == 0)
      {
        turn(ant, 0);
          field[ant->x][ant->y] = 1;
      }
    move_forward(ant);

       draw_array(field);
  }
int
main()
{

  srand((unsigned) time(NULL));
  int steps = 12000;
  int step = 0;
  int field[size][size] = {{0}};
  struct Ants ant;
  ant.x = rand()%size;//size/2;
  ant.y = rand()%size;//size/2;
  ant.direction = 1;
  zerofy_2d_array (field);
  // draw_array(field);

  while (step < steps)
    {
      next_step(field, &ant);
      usleep(3000);
      step++;
    }
  draw_array(field);
  return 0;
}
