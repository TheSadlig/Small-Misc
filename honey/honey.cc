#include <iostream>
#include <vector>
#include <map>

static std::map<int, std::map<int, std::map<int, int> > > memoization;

int distance(int x, int y)
{
  x = x > 0 ? x : -x;
  y = y > 0 ? y : -y;

  if (y >= x)
    return x + (y - x);

  if (x > y)
    return y + (x - y);
}

int parcours(int x, int y, int steps, int dist[15][15])
{
  int x_1 = x >= 0 ? x : -x;
  int y_1 = y >= 0 ? y : -y;

  /*  if (steps <= dist[x_1][y_1])
      return (steps == dist[x_1][y_1]);*/
  if (steps == 0)
    return (x == 0 && y == 0);

  --steps;

  if (memoization[x][y][steps])
    return memoization[x][y][steps];

  int res;
  // To handle the shifting in x between two lines
  // Not the shortest way, but the most understandable
  if (y % 2)
    res = parcours(x - 1, y - 1, steps, dist)
      + parcours(x, y - 1, steps, dist)
      + parcours(x - 1, y, steps, dist)
      + parcours(x + 1, y, steps, dist)
      + parcours(x - 1, y + 1, steps, dist)
      + parcours(x, y + 1, steps, dist);
  else
    res = parcours(x, y - 1, steps, dist) // Changed
      + parcours(x + 1, y - 1, steps, dist) // Changed
      + parcours(x - 1, y, steps, dist)
      + parcours(x + 1, y, steps, dist)
      + parcours(x, y + 1, steps, dist) // Changed
      + parcours(x + 1, y + 1, steps, dist); // Changed

  memoization[x][y][steps] = res;
  return res;
}

int main()
{
  int dist[15][15];
  int nb_cases = 0;
  std::cin >> nb_cases;

  for (int x = 0; x < 14; ++x)
    for (int y = 0; y < 14; ++y)
      dist[x][y] = distance(x, y);

  for (int x = 0; x < nb_cases; ++x)
    {
      int steps = 0;
      std::cin >> steps;
      std::cout << parcours(0, 0, steps, dist) << std::endl;      
    }
}
