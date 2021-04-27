#pragma once

#include <functional>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

namespace strukdat {

template <typename VertexType>
class graph {
  using list_type = std::unordered_set<VertexType>;
  using adj_list_type = std::unordered_map<VertexType, list_type>;

 public:
  graph() {}

  void add_vertex(const VertexType &val) {
    _adj_list.insert(std::make_pair(val, list_type()));
  }

  void remove_vertex(const VertexType &val) {
    auto neighbours = _adj_list[val];
    for (const auto &n : neighbours) {
      remove_edge(val, n);
    }
    _adj_list.erase(val);
  }

  void add_edge(const VertexType &val1, const VertexType val2) {
    _adj_list[val1].insert(val2);
    _adj_list[val2].insert(val1);
  }

  void remove_edge(const VertexType &val1, const VertexType &val2) {
    _adj_list[val1].erase(val2);
    _adj_list[val2].erase(val1);
  }

  size_t order() const { return _adj_list.size(); }

  bool is_edge(const VertexType &val1, const VertexType &val2) const {
    const auto &neighbours = _adj_list.at(val1);
    return neighbours.find(val2) != neighbours.end();
  }

  const &list_type neighbours(const VertexType &val) const {
    return _adj_list.at(val);
  }

  void bfs(const VertexType &root,
           std::function<void(const VertexType &)> func) const {
    VertexType current = root;
    std::unordered_map<VertexType, bool> visited;
    std::queue<VertexType> q;

    q.push(current);
    visited[current] = true;

    while (!q.empty()) {
      current = q.front();
      q.pop();
      func(current);

      for (const auto &adj : _adj_list.at(current)) {
        if (!visited[adj]) {
          visited[adj] = true;
          q.push(adj);
        }
      }
    }
  }

  void dfs(const VertexType &root,
           std::function<void(const VertexType &)> func) const {
    VertexType current = root;
    std::unordered_map<VertexType, bool> visited;
    std::stack<VertexType> s;

    s.push(current);

    while (!s.empty()) {
      current = s.top();
      s.pop();
      if (!visited[current]) {
        func(current);
        visited[current] = true;
        for (const auto &adj : _adj_list.at(current)) {
          s.push(adj);
        }
      }
    }
  }

 private:
  adj_list_type _adj_list;
};

}  // namespace strukdat