#include <bits/stdc++.h>

#define NEIGHBORS 0
#define UNKNOWN -2
#define MYSELF -1
#define MAXIMUM_NUMBER_OF_NODES 1010
#define MAXIMUM_NUMBER_OF_SCENARIOS 100
#define DISTANCE_COLUMN 1
#define NEXT_HOP_COLUMN 2

int routingTables[MAXIMUM_NUMBER_OF_NODES][MAXIMUM_NUMBER_OF_NODES][2];

int main() {
  int numberOfNodes;
  int numberOfEdges;
  scanf("%d %d", &numberOfNodes, &numberOfEdges);

  for(int i = 0; i < numberOfNodes; i++) {
    for(int j = 0; j < numberOfNodes; j++) {
      if(i == j) {
        routingTables[i][j][DISTANCE_COLUMN] = MYSELF;
        routingTables[i][j][NEXT_HOP_COLUMN] = i;
      } else {
        routingTables[i][j][DISTANCE_COLUMN] = UNKNOWN;
        routingTables[i][j][NEXT_HOP_COLUMN] = UNKNOWN;
      }
    }
  }

  for(int i = 0; i < numberOfEdges; i++) {
    int firstNode;
    int secondNode;
    scanf("%d %d", &firstNode, &secondNode);
    firstNode--;
    secondNode--;
    
    routingTables[firstNode][secondNode][DISTANCE_COLUMN] = NEIGHBORS;
    routingTables[firstNode][secondNode][NEXT_HOP_COLUMN] = secondNode;

    routingTables[secondNode][firstNode][DISTANCE_COLUMN] = NEIGHBORS;
    routingTables[secondNode][firstNode][NEXT_HOP_COLUMN] = firstNode;
  }

  int numberOfScenarios;
  scanf("%d", &numberOfScenarios);

  for(int i = 0; i < numberOfScenarios; i++) {
    int from;
    int to;
    scanf("%d %d", &from, &to);
    from--;
    to--;

    routingTables[to][from][DISTANCE_COLUMN] = NEIGHBORS;
    routingTables[to][from][NEXT_HOP_COLUMN] = from;

    for(int previousFrom = 0; previousFrom < numberOfNodes; previousFrom++) {
      if ((from != previousFrom) && (routingTables[from][previousFrom][DISTANCE_COLUMN] != UNKNOWN)) {
        int previousDistance = routingTables[from][previousFrom][DISTANCE_COLUMN];
        int currentDistance = routingTables[to][previousFrom][DISTANCE_COLUMN];
        int newDistance = 1 + previousDistance + routingTables[to][from][DISTANCE_COLUMN];
        if((currentDistance == UNKNOWN) || ((currentDistance != UNKNOWN) && (currentDistance > newDistance))) {
          routingTables[to][previousFrom][DISTANCE_COLUMN] = newDistance;
          routingTables[to][previousFrom][NEXT_HOP_COLUMN] = from;
        } else if((currentDistance == newDistance) && (from < routingTables[to][previousFrom][NEXT_HOP_COLUMN])) {
          routingTables[to][previousFrom][NEXT_HOP_COLUMN] = from;
        }
      }
    }
  }

  for(int i = 0; i < numberOfNodes; i++) {
    for(int j = 0; j < numberOfNodes; j++) {
      printf("%d %d\n", routingTables[i][j][DISTANCE_COLUMN]+1, routingTables[i][j][NEXT_HOP_COLUMN]+1);
    }
  }
}