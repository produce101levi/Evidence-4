#include <iostream>
// As best practice, vectors will be used instead of arrays for this problem.
// Also as best practice, C-style arrays are not used in this code. 
#include <vector>
#include <thread>
#include <mutex>

// Since using namespace std is generally considered bad practice, it is not used.

// Mutex for thread safety
std::mutex mtx;


// Deep First Search (DFS)
// Tree vector is defined with "const" as it should not be changed 
void depthFirstSearch(const std::vector<std::vector<int>> &tree, int node, int parent, int depth, int &max_depth){
  // Modify the maximum depth value
  max_depth = std::max(max_depth, depth);
  // For each of the tree's neighbors, run another DFS.
  for (int neighbor : tree[node]){

    if (neighbor != parent){
      // The function calls on itself, but now its current node is "neighbor" and 
      // its parent is "node". The depth has incremented by 1.
      depthFirstSearch(tree, neighbor, node, depth + 1, max_depth);
    }
    
  }
}


// Determining the winner
void determine_winner(int n, int start_node, const std::vector<std::vector<int>> &tree, std::string &result){

  //Right now, the maximum depth is 0.
  int max_depth = 0;

  // This function calls the DFS funcion stating that we'll start on 
  // 'start_node', its parent is -1 since it has none and its depth is 0.
  depthFirstSearch(tree, start_node, -1, 0, max_depth);


  // Declaring the std::string variable "winner"
  std::string winner;
  
  // The function calculates the value of the maximum depth. If the maximum depth
  // is an even number, Hermione is the winner. If the maximum depth is an uneven
  // number, Ron is the winner.
  if (max_depth % 2 == 0){
    winner = "Hermione";
  } else {
    winner = "Ron";
  }

// To avoid any other threads from accessing this resource, a mutex is used.
// A lock guard for the mutex is also a best practice because it's a RAII wrapper.
  std::lock_guard<std::mutex> lock(mtx);
  
  result = winner;
  
}

void print_tree(const std::vector<std::vector<int>>& tree) {
  for (int i = 0; i < tree.size(); i++) {
    std::cout << "Node " << i << " is connected to: ";
    for (int neighbor : tree[i]) {
      std::cout << neighbor << " ";
      }
    std::cout << std::endl;
  }
}

int main (){

// Insert the value of the number of nodes, then the value of the number of
// rounds. In the case of this problem, t is always equal to 1. 
  int n, t;
  
  std::cin >> n >> t;

  // The size of the tree is n + 1 because
  std::vector<std::vector<int>> tree (n+1);
  
  for (int i = 0; i < n-1; i++){
    int u, v;
    std::cin>>u>>v;

    tree[u].push_back(v);
    tree[v].push_back(u);

    
  }

  int start_node;

  std::cin >> start_node;

  


  // Wait for the result
  std::string result;

 

  std::thread t1(determine_winner, n, start_node, std::ref(tree), std::ref(result));
  std::thread t2(print_tree, tree);

  
  t1.join();
  t2.join();

  std::cout<<"Winner: "<<result<<std::endl;
  
  return 0;
}