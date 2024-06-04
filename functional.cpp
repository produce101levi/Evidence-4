#include <iostream>
// As best practice, vectors will be used instead of arrays.
#include <vector>

// Namespace std is also ommitted.

// Function to make the Depth First Search (DFS)
void depthFirstSearch(const std::vector<std::vector<int>> &tree, int node, int parent, int depth, int &max_depth){
  max_depth = std::max(max_depth, depth);
  for (int neighbor : tree[node]){
    if (neighbor != parent){
      depthFirstSearch(tree, neighbor, node, depth + 1, max_depth);
    }
    
  }
}


// Function to determine the winner of the game
std::string determine_winner(int n, int start_node, 
 const std::vector<std::vector<int>> &tree){
  int max_depth = 0;
  depthFirstSearch(tree, start_node, -1, 0, max_depth);

  if (max_depth % 2 == 0){
    return "Hermione";
  } else {
    return "Ron";
  }

}


// Function to print tree
void print_tree(const std::vector<std::vector<int>> &tree){
  for (int i = 0; i < tree.size(); i++){
    std::cout << "Node " << i << " is connected to: ";
    for(int neighbor : tree[i]){
      std::cout << neighbor << " ";
    }
    std::cout << std::endl;
  }
}


int main(){

  // User inserts values for n and t
  int n, t;
  std::cin >> n >> t;

  // Tree is declared
  std::vector<std::vector<int>> tree (n + 1);

  // For cycle to insert values into tree
  for (int i = 0;i<n-1;i++){
    int u, v;

    std::cin >> u >> v;

    tree[u].push_back(v);
    tree[v].push_back(u);
    
  }

  // Starting node is declared
  int start_node;
  std::cin >> start_node;

  // Assign value returned in function determine_winner() to result
  std::string result = determine_winner(n, start_node, tree);

  // Print tree
  print_tree(tree);

  // Print result
  std::cout << result;
  
}