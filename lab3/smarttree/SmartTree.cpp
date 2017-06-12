//
// Created by Admin on 2017-03-21.
//

#include "SmartTree.h"

namespace datastructures{
    unique_ptr <SmartTree> CreateLeaf(int value){
        unique_ptr<SmartTree> p = make_unique<SmartTree>();
        p -> value = value;
        p -> left = NULL;
        p -> right = NULL;
        return p;
    }

    unique_ptr <SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree){
        if (tree -> left == NULL){
            tree -> left = move(left_subtree);
        }
        return tree;
    }

    unique_ptr <SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree){
        if (tree -> right == NULL){
            tree -> right = move(right_subtree);
        }
        return tree;
    }

    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, ostream *out){
        if (unique_ptr -> left != NULL){ // "Dzień dobry, czy ma pan lewe dziecko?"
            PrintTreeInOrder (move(unique_ptr->left), out); // "Dobrze, lecimy dalej."
        }
        *out << unique_ptr -> value << ", ";
        if (unique_ptr -> right != NULL){
            PrintTreeInOrder (move(unique_ptr->right),  out);
        }
    }

    string DumpTree(const unique_ptr<SmartTree> &tree){
        string nawiaski;
        nawiaski += "["+to_string(tree->value)+" ";
        if(tree -> left != NULL) {
            nawiaski += DumpTree(tree->left);
        }

        else{
            nawiaski += "[none]";
        }

        nawiaski+= " ";
        if(tree -> right != NULL){
            nawiaski += DumpTree(tree->right);
        }

        else{
            nawiaski += "[none]";
        }
        nawiaski += "]";

        return nawiaski;
    }

    /* unique_ptr <SmartTree> RestoreTree(const string &tree){
         for (iterator it = tree.begin(); it != tree.end(); ++it){

         }
     }*/
}