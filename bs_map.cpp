#include <map>
#include <vector>
#include "bs_map.h"

using namespace std;

template <typename Key, typename T>
typename bs_map<Key,T>::PairNode* bs_map<Key,T>::nextleaf()
{
  bs_map<Key,T>::PairNode* node = root_node;
  while(node != NULL)
    {
      if (node->left != NULL)
	node = node->left;
      else if (node->right != NULL)
	node = node->right;
      else
	break;
    }
  return node;
}

template <typename Key, typename T>
vector<typename bs_map<Key,T>::nodeData> bs_map<Key,T>::inorder_traversal()
{
  vector<nodeData> sorted;
  //TODO
  return sorted;
}

template <typename Key, typename T>
bs_map<Key,T>::bs_map(bs_map<Key,T>::PairNode* root)
{
  this->root_node = root;
}

template <typename Key, typename T>
bool bs_map<Key,T>::isnull()
{
  if (this->root_node == NULL)
    return true;
  return false;
}

template <typename Key, typename T>
bool bs_map<Key,T>::isleaf()
{
  if (isnull())
    return true;
  if (root_node->left == NULL)
    if (root_node->right == NULL)
      return true;
  return false;
}

template <typename Key, typename T>
bs_map<Key,T> bs_map<Key,T>::left_subtree()
{
  if (isleaf())
    return *(new bs_map<Key,T>);
  
  bs_map<Key,T> new_tree(root_node->left);
  return new_tree;
}

template <typename Key, typename T>
bs_map<Key,T> bs_map<Key,T>::right_subtree()
{
  if (isleaf())
    return *(new bs_map<Key,T>);
  
  bs_map<Key,T> new_tree(root_node->right);
  return new_tree;
}

template <typename Key, typename T>
void bs_map<Key,T>::addleaf(const typename bs_map<Key,T>::nodeData& data)
{
  bs_map<Key,T>::PairNode cur_node = root_node;
  while(cur_node != NULL)
    {
      if(data.second < cur_node->data->second)
	cur_node = cur_node->left;
      else
	cur_node = cur_node->right;
    }
  cur_node = new bs_map<Key,T>::PairNode;
  cur_node->data = new bs_map<Key,T>::nodeData(data);
}

///////////////////////////////////////////////////////////
// This is just to compile just this library for testing //
///////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    
    return 0;
}
