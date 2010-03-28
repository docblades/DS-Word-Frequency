#include <map>
#include <vector>
#include "bs_map.h"

template <typename Key, typename T>
bs_map<Key,T>::PairNode* bs_map::nextleaf()
{
  bs_map<Key,T>::PairNode* node = this->root_node;
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

int main(int argc, char *argv[])
{
    
    return 0;
}
