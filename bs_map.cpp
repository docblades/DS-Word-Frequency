#include <map>
#include <vector>
#include "bs_map.h"
#include <string>
#include <iostream>


using namespace std;

template <typename Key, typename T>
typename bs_map<Key,T>::PairNode* bs_map<Key,T>::nextleaf()
{
  typename bs_map<Key,T>::PairNode* node = root_node;
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
bs_map<Key,T>::bs_map(typename bs_map<Key,T>::PairNode* root)
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
  typename bs_map<Key,T>::PairNode* cur_node = root_node;
  cout << data.first << endl;
  while(cur_node != NULL)
    {
      cout << "if" << endl;
      cout << "cur_node->data->second" << cur_node->data->second << endl;
      if(data.second < cur_node->data->second)
	{
	  cout << "in if" << endl;
  	cur_node = cur_node->left;
	cout << "out if" << endl;
	}

      else
	{
	  cout << "else" << endl;
	  cur_node = cur_node->right;
	}
    }
  cur_node = new typename bs_map<Key,T>::PairNode;
  cur_node->data = new typename bs_map<Key,T>::nodeData(data);
}

template <typename Key, typename T>
vector<typename bs_map<Key,T>::nodeData> bs_map<Key,T>::preorder_traversal()
{
  vector<typename bs_map<Key,T>::nodeData> sorted;
  if (isnull())
    return sorted;

  vector<typename bs_map<Key,T>::PairNode*> a_stack;
  a_stack.push_back(root_node);

  while(!a_stack.empty())
    {
      while(a_stack.back()->left != NULL)
	{
	  a_stack.push_back(a_stack.back()->left);
	  sorted.push_back(*(new typename bs_map<Key,T>::nodeData(*a_stack.back()->data)));
	}
      typename bs_map<Key,T>::PairNode* popped(a_stack.back());
      a_stack.pop_back();
      if (popped->right != NULL)
	{
	  a_stack.push_back(popped->right);
	  sorted.push_back(*(new typename bs_map<Key,T>::nodeData(*popped->right->data)));
	}	       
    }
  //TODO

  return sorted;
}
///////////////////////////////////////////////////////////
// This is just to compile just this library for testing //
///////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
  pair<string,size_t>* fpair = new pair<string,size_t>("hey", 1);
  bs_map<string,size_t>::PairNode* foo_node = new bs_map<string,size_t>::PairNode;
  foo_node->data = fpair;
  bs_map<string,size_t> bst;

  // bst.addleaf(fpair);
  for(size_t i = 65; i < 75; i++)
    {
      string foo_string;
      foo_string.push_back((char) i);
      // foo_string.push_back((char) i);

      pair<string,size_t> foo_pair(foo_string, i);

      bst.addleaf(foo_pair);
    }
  cout << bst.isnull() << endl;

  vector<pair<string,size_t> > foo_vec = bst.preorder_traversal();

  for (vector<pair<string,size_t> >::iterator iter = foo_vec.begin();
       iter != foo_vec.end(); iter++)
    {
      cout << (iter)->first << "=>" << (iter)->second;
    }

  return 0;
}
