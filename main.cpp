#include "raylib.h"
#include "objects.h"
#include <vector>
#include <iostream>
using namespace std; 
using namespace N; 

int main()
{
  int cells_in_row = 50; 
  int cells_in_col = 50; 
  int windowheight = 1400; 
  int windowwidth = 1400; 
  InitWindow(windowheight, windowwidth, "Game of Life"); 
  SetTargetFPS(60); 
  
  vector<vector<CELL>> grid; 
  for (int row=0; row < cells_in_row; row++)
  {
    vector<CELL> row_cells;
    for (int col=0; col<cells_in_col; col++)
    {
     int x = row*(windowwidth/cells_in_row);
     int y = col*(windowheight/cells_in_col);
     int w = (windowwidth/cells_in_row)-1;
     int h = (windowwidth/cells_in_col)-1;
     row_cells.push_back(CELL(x, y, w, h, row, col));
    }
    grid.push_back(row_cells);
  }


  while (!WindowShouldClose())
  {
    if (IsKeyPressed(KEY_SPACE)){
      for (auto& row : grid)
        for (auto& cell : row)
        {
          cell.update_cells(grid, cells_in_row, cells_in_col);
        }

      for (auto& row : grid)
        for (auto& cell : row)
          cell.update();
    }
 

    ClearBackground(BLACK); 
    BeginDrawing(); 
    for (auto& row : grid)
      for (auto& cell : row)
      {
        cell.draw();
        cell.Check_if_pressed();
      }
    EndDrawing();
  }

  CloseWindow(); 
  return 0; 
}
