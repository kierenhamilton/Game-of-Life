#ifndef OBJECTS_H
#define OBJECTS_H
#include <vector>
#include <iostream> 

using namespace std; 
namespace N
{
  class CELL
  {
    public:
      CELL(int x, int y, int w, int h, int vecx, int vecy, bool isAlive = false, int dead = 0) 
        : xpos(x), ypos(y), width(w), height(h), vposx(vecx), vposy(vecy), alive(isAlive), alive_neighbours(dead) {}

      void draw()
      {
        Color foo; 
        if (alive) foo = GRAY;
        else foo = BLACK; 
        DrawRectangle (xpos, ypos, width, height, foo); 
      }

      bool isAlive()
      {
        return alive;
      }

      void Check_if_pressed()
      {
        {
          int x = GetMouseX();
          int y = GetMouseY(); 
          if ((x >= xpos && x <= xpos+width) && (y >= ypos && y <= ypos+height)) 
            if (IsMouseButtonPressed(0))
            {
              alive = !alive;
              cout << vposx << endl << vposy <<endl; 
            }
        }
      }

      void update_cells(vector<vector<CELL>> grid, int numrows, int numcols)
      {
          int x_start = (vposx > 0) ? -1 : 0;
          int x_end = (vposx < numcols - 1) ? 1 : 0;
          int y_start = (vposy > 0) ? -1 : 0;
          int y_end = (vposy < numrows - 1) ? 1 : 0;

          int num_alive = 0;

          for (int i = x_start; i <= x_end; i++) {
            for (int j = y_start; j <= y_end; j++) {
              if ((i != 0 || j != 0) && grid[vposx + i][vposy + j].isAlive()) {
                num_alive++;
              }
            }
          }
          alive_neighbours = num_alive;
      }

      void update ()
      {
          if (alive) alive = (alive_neighbours > 1) && (alive_neighbours < 4); 
          if (!alive) alive = alive_neighbours == 3; 
      }

    

    private:
      int xpos;
      int ypos; 
      int width; 
      int height;
      int vposx;
      int vposy;
      bool alive; 
      int alive_neighbours;
  };
}
#endif
