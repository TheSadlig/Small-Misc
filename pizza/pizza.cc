#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using Grid = std::vector<std::vector<int> >;

int total_blocks(int x, int y, Grid& grid)
{
  int res = 0;
  for (int i = 0; i < grid.size(); ++i)
    for (int j = 0; j < grid[i].size(); ++j)
        {
          res += (abs(x - i) + abs(y - j)) * grid[i][j];
        }
  return res;
}

void display(Grid& grid)
{
  for (int i = 0; i < grid.size(); ++i)
    {
      for (int j = 0; j < grid[i].size(); ++j)
        {
          std::cout << grid[i][j];
        }
      std::cout << std::endl;
    }
}


int main()
{
  int nb_cases;
  std::cin >> nb_cases;
  for (int i = 0; i < nb_cases; ++i)
    {
      Grid grid;
      int size_x;
      int size_y;

      std::cin >> size_y;
      std::cin >> size_x;
      
      for (int j = 0; j < size_x; ++j)
        {
          std::vector<int> line;
          grid.push_back(line);

          for (int k = 0; k < size_y; ++k)
            {
              int aux;
              std::cin >> aux;
              grid[j].push_back(aux);
            }
        }

      int min = INT_MAX;
      int best_x = -1;
      int best_y = -1;

      for (int j = 0; j < size_x; ++j)
        {
          for (int k = 0; k < size_y; ++k)
            {
              int res = total_blocks(j, k, grid);
              if (res < min)
                {
                  min = res;
                  best_x = j;
                  best_y = k;
                }

            }
        }
      
      std::cout << min << " blocks";
      std::cout << std::endl;
    }
}
