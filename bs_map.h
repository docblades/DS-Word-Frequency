#ifndef _BS_MAP_H_
#define _BS_MAP_H_

#include <map>
#include <vector>
using namespace std;

template <typename Key, typename T>
class bs_map
{
public:
  typedef typename std::pair<Key,T> nodeData;
  bs_map();
  bs_map(map<Key,T> copymap); // Init from a map
  bs_map(nodeData* pairArray, size_t arraySize); // Init from array of pairs
  bs_map(const bs_map<Key,T>& copytree); // copy constructor
  bs_map(PairNode* root); // Init with root node
  virtual ~bs_map();

  vector<nodeData> inorder_traversal(); // returns a sorted vector
  bool isnull();
  bool isleaf();
  bs_map<Key,T> left_subtree();
  bs_map<Key,T> right_subtree();

  struct PairNode {
    nodeData* data;
    PairNode* left;
    PairNode* right;
  };

private:
  PairNode* root_node;

  void addleaf(nodeData data); // inserts a new PairNode in the tree
  PairNode* nextleaf(); // used in the destructor to grab the next leaf to delete
};
#endif /* _BS_MAP_H_ */
