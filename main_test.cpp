#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "graph.hpp"

TEST_CASE("dapat menambah dan menghapus vertex", "[case_1]") {
  strukdat::graph<int> g;
  g.add_vertex(1);
  g.add_vertex(2);
  REQUIRE(g.order() == 2);

  g.add_vertex(2);
  REQUIRE(g.order() == 2);

  g.add_vertex(3);
  REQUIRE(g.order() == 3);

  g.remove_vertex(2);
  REQUIRE(g.order() == 2);
}

TEST_CASE("dapat menambah dan menghapus edge", "[case_2]") {
  strukdat::graph<int> g;

  g.add_vertex(1);
  g.add_vertex(2);
  g.add_vertex(3);

  g.add_edge(1, 2);
  REQUIRE(!g.is_edge(1, 3));

  g.add_edge(1, 3);
  REQUIRE(g.is_edge(1, 2));
  REQUIRE(g.is_edge(1, 3));
  REQUIRE(g.is_edge(2, 1));
  REQUIRE(!g.is_edge(2, 3));
}