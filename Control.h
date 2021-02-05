#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Frequency.h"
#include "Tree.h"


class Control {
    public:
        Control();
        ~Control();
        void Encode(std::string inputfile);
        void Decode(std::string inputfile);
        void ListTree();
        void Letters(std::string input);

};


