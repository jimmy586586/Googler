#include "binary_search_tree.hpp"

using std::cout;
using std::endl;

BinarySearchTree::BinarySearchTree() : root_(nullptr) {}


void BinarySearchTree::Add(int value) {
    Node* new_node = new Node(value);

    if (!root_) {
        root_ = new_node;
        return;
    } else {
        Node* ptr = root_;
        while (ptr) {
            if (value <= ptr->value) {
                if (ptr->left_child) {
                    ptr = ptr->left_child;
                } else {
                    new_node->parent = ptr;
                    ptr->left_child = new_node;
                    break;
                }
            } else {
                if (ptr->right_child) {
                    ptr = ptr->right_child;
                } else {
                    new_node->parent = ptr;
                    ptr->right_child = new_node;
                    break;
                }
            }
        }
    }
}

void BinarySearchTree::Remove(int value) {

}


void BinarySearchTree::PreOrderTraversal(std::ostream& os, Node* node) const {
    if (node) {
        os << node->value << " ";
        PreOrderTraversal(os, node->left_child);
        PreOrderTraversal(os, node->right_child);
    }
}

void BinarySearchTree::InOrderTraversal(std::ostream& os, Node* node) const {
    if (node) {
        InOrderTraversal(os, node->left_child);
        os << node->value << " ";
        InOrderTraversal(os, node->right_child);
    }
}

void BinarySearchTree::PostOrderTraversal(std::ostream& os, Node* node) const {
    if (node) {
        PostOrderTraversal(os, node->left_child);
        PostOrderTraversal(os, node->right_child);
        os << node->value << " ";
    }
}


std::ostream& operator<< (std::ostream& os, const BinarySearchTree& bst) {
    os << "PreOrder: ";
    bst.PreOrderTraversal(os, bst.root_);
    os << endl;

    os << "InOrder: ";
    bst.InOrderTraversal(os, bst.root_);
    os << endl;

    os << "PostOrder: ";
    bst.PostOrderTraversal(os, bst.root_);
    return os << endl;
}
