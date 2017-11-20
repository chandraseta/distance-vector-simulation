#include <bits/stdc++.h>

class Node {

  public:
    int id;
    std::vector<int> distances;
    std::vector<int> next_hops;

    Node() {}

    Node(int id, std::vector<int> neighbours, int total_node_count) {
      this->id = id;
      distances.push_back(-1);
      next_hops.push_back(-1);
      for (int i=1; i<total_node_count+1; i++) {
        if (i==id) {
          distances.push_back(0);
        }
        else if (std::find(neighbours.begin(), neighbours.end(), i) != neighbours.end()) {
          distances.push_back(1);
        }
        else {
          distances.push_back(-1);
        }

        if (i==id) {
          next_hops.push_back(i);
        }
        else if (std::find(neighbours.begin(), neighbours.end(), i) != neighbours.end()) {
          next_hops.push_back(i);
        }
        else {
          next_hops.push_back(-1);
        }
      }
    }
};

void sendAndUpdate(Node& sender, Node& receiver, int total_node_count) {
  // Iterate through neighbour node
  for (int i=1; i<total_node_count+1; i++) {
    if (sender.distances.at(i) != -1) {
      if (receiver.distances.at(i) == -1 || sender.distances.at(i) + 1 < receiver.distances.at(i)) {
        receiver.distances.at(i) = sender.distances.at(i) + 1;
        receiver.next_hops.at(i) = sender.id;
      }
    }
  }
}

int main() {

  int n_node;
  std::cin >> n_node;

  std::vector<Node> nodes;

  // Dummy data
  std::vector<int> dummy_neighbour;
  nodes.push_back(Node(0, dummy_neighbour, 0));

  std::vector<int> neighbours;
  for(int i=1; i<n_node+1; i++) {

    // Dummy
    neighbours.push_back(0);

    std::string str;
    std::cin >> str;

    std::stringstream sstream(str);

    int n;
    while (sstream >> n) {
      neighbours.push_back(n);

      if (sstream.peek() == ',' || sstream.peek() == ' ') {
        sstream.ignore();
      }
    }

    nodes.push_back(Node(i, neighbours, n_node));
    neighbours.clear();
  }

  std::cout << "=== INITIAL STATE ===" << std::endl;
  for (int node=1; node<n_node+1; node++) {
    std::cout << "Node " << node << std::endl;
    for (int neighbour=1; neighbour<n_node+1; neighbour++) {
      std::cout << nodes[node].distances.at(neighbour) << " " << nodes[node].next_hops.at(neighbour) << std::endl;
    }
  }
  std::cout << "=====================" << std::endl;

  // Scenario
  int n_scenario;
  std::cin >> n_scenario;

  while (n_scenario--) {
    int sender_id, receiver_id;
    std::cin >> sender_id >> receiver_id;

    sendAndUpdate(nodes.at(sender_id), nodes.at(receiver_id), n_node);
  }

  for (int node=1; node<n_node+1; node++) {
    std::cout << "Node " << node << std::endl;
    for (int neighbour=1; neighbour<n_node+1; neighbour++) {
      std::cout << nodes[node].distances.at(neighbour) << " " << nodes[node].next_hops.at(neighbour) << std::endl;
    }
  }

  return 0;
}