//
// Created by zosiek on 11.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATOR_H
#define JIMP_EXERCISES_TREEITERATOR_H
#include "Tree.h"
#include <vector>

using namespace std;

namespace tree {

    //INORDER


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



    //PREORDER

    template <class T>
    void PreOrderVector(Tree<T> *tree, std::vector<Tree<T> *> &vector){
        vector.push_back(tree);
        if(tree->Left()) PreOrderVector(tree->Left(),vector);
        if(tree->Right()) PreOrderVector(tree->Right(),vector);

    }

    template<class T>
    class PreOrderTreeIterator;

    template <class T>
    class PreOrderTreeView{
        Tree<T> *tree_;
    public:
        PreOrderTreeView(Tree<T> *tree) : tree_(tree) {};
        PreOrderTreeIterator<T> begin(){
            PreOrderTreeIterator<T> new_preit(tree_->Root());
            return new_preit;
        }
        PreOrderTreeIterator<T> end(){
            PreOrderTreeIterator<T> new_preit(tree_->Root());
            new_preit.ToEnd();
            return new_preit;
        }
    };

    template<class T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree);

    template<class T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree) {
        return PreOrderTreeView<T>(tree);
    }

    template <class T>
    class PreOrderTreeIterator{
        void ToEnd(){
            it_ = (int) vector_.size();
        }
        vector<Tree<T> *> vector_;
        int it_;
    public:
        PreOrderTreeIterator(Tree<T> *tree) : it_(0) {
            PreOrderVector<T>(tree, vector_);
        }
        T operator*(){
            return vector_[it_]->Value();
        }
        PreOrderTreeIterator<T> &operator++() {
            ++it_;
            return *this;
        }
        bool operator!=(const PreOrderTreeIterator<T> &one) const{
            return it_ != one.it_;
        }
        friend class PreOrderTreeView<T>;
    };


    //POSTORDER


    template <class T>
    void PostOrderVector(Tree<T> *tree, vector<Tree<T> *> &vector){
        if(tree->Left()) PostOrderVector(tree->Left(),vector);
        if(tree->Right()) PostOrderVector(tree->Right(),vector);
        vector.push_back(tree);

    }

    template<class T>
    class PostOrderTreeIterator;

    template <class T>
    class PostOrderTreeView{
        Tree<T> *tree_;
    public:
        PostOrderTreeView(Tree<T> *tree) : tree_(tree) {};
        PostOrderTreeIterator<T> begin(){
            PostOrderTreeIterator<T> new_it(tree_->Root());
            return new_it;
        }
        PostOrderTreeIterator<T> end(){
            PostOrderTreeIterator<T> new_it(tree_->Root());
            new_it.ToEnd();
            return new_it;
        }
    };

    template<class T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree);

    template<class T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree) {
        return PostOrderTreeView<T>(tree);
    }

    template <class T>
    class PostOrderTreeIterator{
        void ToEnd(){
            it_ = (int) vector_.size();
        }
        vector<Tree<T> *> vector_;
        int it_;
    public:
        PostOrderTreeIterator(Tree<T> *tree) : it_(0) {
            PostOrderVector<T>(tree, vector_);
        }
        T operator*(){
            return vector_[it_]->Value();
        }
        PostOrderTreeIterator<T> &operator++() {
            ++it_;
            return *this;
        }
        bool operator!=(const PostOrderTreeIterator<T> &one) const{
            return it_ != one.it_;
        }
        friend class PostOrderTreeView<T>;
    };
}




#endif //JIMP_EXERCISES_TREE_H

