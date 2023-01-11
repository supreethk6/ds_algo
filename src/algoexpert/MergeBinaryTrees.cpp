/**
 * @file MergeBinaryTrees.cpp
 * @author skk
 * @brief 
 * 
 * Given 2 binary trees, merge them and return the resulting tree 
 * if 2 nodes overlap during the merger then sum the values, 
 * otherwise use the existing node.
 * 
 * Note that your solution can either mutate the existing trees or
 * return a new tree.
 * 
 * Sample input:
 * 
 * tree1 =      1
 *             / \
 *            3   2
 *           / \
 *          7   4
 * 
 * tree2 =      1
 *             / \
 *            5   9
 *           /   / \
 *          2   7   6
 * 
 * Sample output:
 * 
 *               2
 *             /   \
 *            8     11
 *           / \    / \
 *          9   4  7   6
 * 
 * @version 0.1
 * @date 2023-01-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <stack>
#include <queue>

using std::cout;
using std::endl;
using std::stack;
using std::queue;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) {
    this->value = value;
  }
};

/**
 * @brief Depth First Search (DFS)
 * 
 * @param root root value of the tree
 *
void depthFirstSearch(BinaryTree* root) {
  stack<BinaryTree*> nodes;
  BinaryTree* current = root;

  while (current != nullptr || !nodes.empty()) {
    while (current != nullptr) {
      cout << current->value << " ";
      nodes.push(current);
      current = current->left;
    }

    current = nodes.top();
    nodes.pop();
    current = current->right;
  }
}
*/

/**
 * @brief Breadth First Search
 * 
 * @param root root value of the tree
 *
void breadthFirstSearch(BinaryTree* root) {
  queue<BinaryTree*> nodes;
  nodes.push(root);

  while (!nodes.empty()) {
    BinaryTree* current = nodes.front();
    nodes.pop();

    cout << current->value << " ";

    if (current->left != nullptr) {
      nodes.push(current->left);
    }
    if (current->right != nullptr) {
      nodes.push(current->right);
    }
  }
}
*/

BinaryTree* mergeBinaryTrees(BinaryTree* tree1, BinaryTree* tree2) {
  // Write your code here.
  BinaryTree* mergeOutput;
  // depthFirstSearch(tree1);
  // cout << endl;
  // breadthFirstSearch(tree1);
  // cout << endl;
  // breadthFirstSearch(tree2);
  // cout << endl;

  queue<BinaryTree*> nodes1;
  nodes1.push(tree1);

  queue<BinaryTree*> nodes2;
  nodes2.push(tree2);

  while (!nodes1.empty() && !nodes2.empty()) {
    cout << " - " << !nodes1.empty() << " && " << !nodes2.empty() << " - " ;
    BinaryTree* current1 = nodes1.front();
    nodes1.pop();
    BinaryTree* current2 = nodes2.front();
    nodes2.pop();

    BinaryTree resultTree(current1->value + current2->value);
    cout << resultTree.value << " + "; 

    cout << current1->value << " ";

    if (current1->left != nullptr && current2->left != nullptr) {
      nodes1.push(current1->left);
      nodes2.push(current2->left);
      resultTree.left = new BinaryTree(current1->left->value + current2->left->value);
    }
    else if (current1->left != nullptr && current2->left == nullptr) {
      nodes1.push(current1->left);
      resultTree.left = new BinaryTree(current1->left->value);
    }
    else if (current1->left == nullptr && current2->left != nullptr) {
      nodes2.push(current2->left);
      resultTree.left = new BinaryTree(current2->left->value);
    }

    if (current1->right != nullptr && current2->right != nullptr) {
      nodes1.push(current1->right);
      nodes2.push(current2->right);
      resultTree.right = new BinaryTree(current1->right->value + current2->right->value);
    }
    else if (current1->right != nullptr && current2->right == nullptr) {
      nodes1.push(current1->right);
      resultTree.right = new BinaryTree(current1->right->value);
    }
    else if (current1->right == nullptr && current2->right != nullptr) {
      nodes2.push(current2->right);
      resultTree.right = new BinaryTree(current2->right->value);
    }
  }

  cout << " - " << !nodes1.empty() << " && " << !nodes2.empty() << " - " ;
  // cout << nodes2.front()->value << endl;

  return mergeOutput;
}

int main() {
  BinaryTree tree1(1);
  tree1.left = new BinaryTree(3);
  tree1.right = new BinaryTree(2);
  tree1.left->left = new BinaryTree(7);
  tree1.left->right = new BinaryTree(4);

  BinaryTree tree2(1);
  tree2.left = new BinaryTree(5);
  tree2.right = new BinaryTree(9);
  tree2.left->left = new BinaryTree(2);
  tree2.right->left = new BinaryTree(7);
  tree2.right->right = new BinaryTree(6);

  BinaryTree* mergeResult =  mergeBinaryTrees(&tree1, &tree2);

  return 0;
}
