/*
 * Bebas disini bisa masukin apa aja.
 * Misal mau testing atau debugging sendiri.
 *
 * Disini ada contoh code, boleh dihapus.
 */

#include <iostream>
#include <string>

#include "graph.hpp"

int main() {
  strukdat::graph<int> g;

  g.add_edge(1, 2);
  g.add_edge(1, 4);
  g.add_edge(2, 3);
  g.add_edge(2, 5);
  g.add_edge(3, 4);
  g.add_edge(3, 5);

  g.dfs(1, [](int a) {
    if (a == 2) a = 1;
    std::cout << a << ' ';
  });

  std::cout << '\n';

  g.dfs(1, [](int a) { std::cout << a << ' '; });

  std::cout << '\n';

  g.bfs(1, [](int a) { std::cout << a << ' '; });

  return 0;
}
