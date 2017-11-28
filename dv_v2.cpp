#include <bits/stdc++.h>

#define MAX 1001
#define INF -1

int neighbours[MAX][MAX];
int distances[MAX][MAX];
int next_hops[MAX][MAX]; 

int main() {

  memset(neighbours, 0, sizeof(neighbours));
  memset(distances, INF, sizeof(distances));
  memset(next_hops, INF, sizeof(next_hops));

  int n_node, n_edge;
  scanf("%d %d", &n_node, &n_edge);

  // Record neighbours
  int n1, n2;
  for(int i=0; i<n_edge; i++) {
    scanf("%d %d", &n1, &n2);
    neighbours[n1][n2] = 1;
    neighbours[n2][n1] = 1;

    distances[n1][n2] = 1;
    distances[n2][n1] = 1;
    distances[n1][n1] = 0;
    distances[n2][n2] = 0;

    next_hops[n1][n2] = n2;
    next_hops[n2][n1] = n1;
    next_hops[n1][n1] = n1;
    next_hops[n2][n2] = n2;
  }

  // std::cout << "=== INITIAL STATE ===" << std::endl;
  // for(int node=1; node<n_node+1; node++) {
  //   std::cout << "Node " << node << std::endl;
  //   for (int neighbour=1; neighbour<n_node+1; neighbour++) {
  //     std::cout << distances[node][neighbour] << " " << next_hops[node][neighbour] << std::endl;
  //   }
  // }
  // std::cout << "=====================" << std::endl;

  // Scenario
  int n_scenario;
  scanf("%d", &n_scenario);

  int sender, receiver;
  
  for(int scenario=0; scenario<n_scenario; scenario++) {
    scanf("%d %d", &sender, &receiver);
    for (int i=1; i<n_node+1; i++) {
      if (distances[sender][i] != INF) {
        // Sender is connected to node i
        if (distances[receiver][i] == INF || distances[sender][i] < distances[receiver][i]) {
          // Receiver has no info about node i or distance to node i is closer through sender
          distances[receiver][i] = distances[sender][i] + 1;
          if (next_hops[receiver][i] == INF || sender < next_hops[receiver][i]) {
            // Receiver next hop to i has not been set or sender id is smaller than current next hop
            next_hops[receiver][i] = sender;  
          } // Receiver next hop to i has been set and sender id is larger than current next hop
        } // Receiver has info about node i and distance to node i is equal or further through sender
      } // Sender is not connected to node i
    }
  }

  for(int node=1; node<n_node+1; node++) {
    // printf("Node %d\n", node); 
    for (int neighbour=1; neighbour<n_node+1; neighbour++) {
      printf("%d %d\n", distances[node][neighbour], next_hops[node][neighbour]);
    }
  }

  return 0;
}