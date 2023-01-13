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
#include <memory>

using std::cout;
using std::endl;
using std::stack;
using std::queue;
using std::unique_ptr;
using std::make_unique;

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
 */
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

// void deleteTree(BinaryTree* root) {
//   if (root == nullptr) return;
//   deleteTree(root->left);
//   deleteTree(root->right);
//   delete root;
// }

BinaryTree* mergeBinaryTrees(BinaryTree* tree1, BinaryTree* tree2) {
  if (tree1 == nullptr) return tree2;
  if (tree2 == nullptr) return tree1;

  queue<BinaryTree*> q1, q2, resultQueue;
  q1.push(tree1);
  q2.push(tree2);

  BinaryTree* root = new BinaryTree(tree1->value + tree2->value);
  resultQueue.push(root);

  while (!q1.empty() && !q2.empty()) {
    BinaryTree* t1 = q1.front();
    q1.pop();
    BinaryTree* t2 = q2.front();
    q2.pop();

    BinaryTree* resultTree = resultQueue.front();
    resultQueue.pop();

    if (t1->left && t2->left) {
      resultTree->left = new BinaryTree(t1->left->value + t2->left->value);
      q1.push(t1->left);
      q2.push(t2->left);
      resultQueue.push(resultTree->left);
    }
    else if (t1->left && !t2->left) {
      resultTree->left = t1->left;
    }
    else if (!t1->left && t2->left) {
      resultTree->left = t2->left;
    }

    if (t1->right && t2->right) {
      resultTree->right = new BinaryTree(t1->right->value + t2->right->value);
      q1.push(t1->right);
      q2.push(t2->right);
      resultQueue.push(resultTree->right);
    }
    else if (t1->right && !t2->right) {
      resultTree->right = t1->right;
    }
    else if (!t1->right && t2->right) {
      resultTree->right = t2->right;
    }
  }

  return root;
}

int main() {
  BinaryTree tree1(1);
  tree1.left = new BinaryTree(3);
  tree1.right = new BinaryTree(2);
  tree1.left->left = new BinaryTree(7);
  tree1.left->right = new BinaryTree(4);
  breadthFirstSearch(&tree1);
  cout << endl;

  BinaryTree tree2(1);
  tree2.left = new BinaryTree(5);
  tree2.right = new BinaryTree(9);
  tree2.left->left = new BinaryTree(2);
  tree2.right->left = new BinaryTree(7);
  tree2.right->right = new BinaryTree(6);
  breadthFirstSearch(&tree2);
  cout << endl;

  BinaryTree* mergeResult =  mergeBinaryTrees(&tree1, &tree2);
  breadthFirstSearch(mergeResult);
  cout << endl;

  // deleteTree(&tree1);
  // deleteTree(&tree2);
  // deleteTree(mergeResult);

  return 0;
}
