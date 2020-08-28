#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;
int root=0;

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

void printQueue(queue<int> q)
{
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"\n";     
}

void printArray(vector<vector<int> > x)
{
  for(int i=0;i<x.size();i++){
    for(int j=0;j<x[i].size();j++){
      cout<<x[i][j]<<" ";
    }
    cout<<"\n";
  }
}

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  std::cin >> n;

  int height=0;
  int x;

  vector<vector<int> > a(n);
  for(int i=0;i<n;i++){
      cin>>x;
      if(x==-1) root=i;
      else
        a[x].push_back(i);
  }
  //printArray(a);
  queue<int> q;
  q.push(root);
  //printQueue(q);

  while(true){
    int nodecount=q.size();
    //cout<<nodecount<<endl;
    if(nodecount==0) {
      cout<<height<<endl;
      return 0;
    }
    else 
      height++;

    while(nodecount>0){
      int y=q.front();
      //cout<<y<<"\n";
      q.pop();
      //printQueue;
      for(int i=0;i<a[y].size();i++)
        q.push(a[y][i]);
      //printQueue(q);
      nodecount--;
    }

  }
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}

// OLD IMPLEMENTATION

  // std::vector<Node> nodes;
  // nodes.resize(n);
  // for (int child_index = 0; child_index < n; child_index++) {
  //   int parent_index;
  //   std::cin >> parent_index;
  //   if (parent_index >= 0)
  //     nodes[child_index].setParent(&nodes[parent_index]);
  //   nodes[child_index].key = child_index;
  // }



  // // Replace this code with a faster implementation
  // int maxHeight = 0;
  // for (int leaf_index = 0; leaf_index < n; leaf_index++) {
  //   int height = 0;
  //   for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
  //     height++;
  //   maxHeight = std::max(maxHeight, height);
  // }
