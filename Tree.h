//
// Created by Selcuk on 17.12.2020.
//
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class Tree{
public:
    Tree();
    ~Tree();
    void Add(std::string xitem,int xfrequency);

    int getFrequency() const;

    struct TreeNode{
    std::string item;
    TreeNode* rightchild;
    TreeNode* leftchild;
    TreeNode* parent;
    };

    TreeNode* tail;
    int frequency;

    void TailCalibration();
    void printInorder(TreeNode* node,std::string location);
};




