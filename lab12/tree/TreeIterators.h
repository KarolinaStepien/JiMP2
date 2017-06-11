//
// Created by zosiek on 11.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATOR_H
#define JIMP_EXERCISES_TREEITERATOR_H
#include "Tree.h"
#include <vector>

using namespace std;

namespace tree {
    template <class T>
    void InOrderVector(Tree<T> *tree, std::vector<Tree<T> *> &vector){
        if(tree->Left()) InOrderVector(tree->Left(),vector);
        vector.push_back(tree);
        if(tree->Right()) InOrderVector(tree->Right(),vector);
    }

    template<class T>
    class InOrderTreeIterator;

template <class T>
    class InOrderTreeView{
        Tree<T> *tree_;
    public:
        InOrderTreeView(Tree<T> *tree) : tree_(tree) {};
        InOrderTreeIterator<T> begin(){
            InOrderTreeIterator<T> new_it(tree_->Root());
            return new_it;
        }
        InOrderTreeIterator<T> end(){
            InOrderTreeIterator<T> new_it(tree_->Root());
            new_it.ToEnd();
            return new_it;
        }
    };

    template<class T>
    InOrderTreeView<T> InOrder(Tree<T> *tree);

    template<class T>
    InOrderTreeView<T> InOrder(Tree<T> *tree) {
        return InOrderTreeView<T>(tree);
    }

    template <class T>
    class InOrderTreeIterator{
        void ToEnd(){
            it_ = (int) vector_.size();
        }
        vector<Tree<T> *> vector_;
        int it_;
    public:
        InOrderTreeIterator(Tree<T> *tree) : it_(0) {
            InOrderVector<T>(tree, vector_);
        }
        T operator*(){
            return vector_[it_]->Value();
        }
        InOrderTreeIterator<T> &operator++() {
            ++it_;
            return *this;
        }
        bool operator!=(const InOrderTreeIterator<T> &one) const{
            return it_ != one.it_;
        }
        friend class InOrderTreeView<T>;
    };
}

#endif //JIMP_EXERCISES_TREE_H

