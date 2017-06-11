//
// Created by zosiek on 11.06.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H
#include <memory>
#include <iostream>

using namespace std;
namespace tree {
    template<class T>
    class Tree {
    public:
        Tree(){};
        Tree(T value) : size_{1}, depth_{1}, value_{value}, left_{nullptr}, right_{nullptr}{};
        void Insert(T value);
        int Value(){return value_;}
        int Size(){return size_;}
        size_t Depth();

    private:
        int size_;
        int depth_;
        T value_;
        unique_ptr<Tree> left_;
        unique_ptr<Tree> right_;
    };


    template<class T>
    void Tree<T>::Insert(T value) {
        if (value > value_) {
            if (!right_)
                right_ = make_unique<Tree<T>>(value);
            else
                right_->Insert(value);
        }else {
            if (!left_)
                left_ = make_unique<Tree<T>>(value);
            else
                left_->Insert(value);
        }
        size_++;
    }


    template <class T>
    size_t Tree<T>::Depth(){
        if(left_ && right_)
            return 1+max(left_->Depth(),right_->Depth());
        else{
            if(left_)
                return 1+left_->Depth();
            if(right_)
                return 1+right_->Depth();
            return 1;
        }
    };
}
#endif //JIMP_EXERCISES_TREE_H
