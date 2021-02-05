#include"Control.h"

using namespace std;
int main(int argc,char**argv) {
    Control control;
    string command=argv[1];
    if(command=="-i"){
        string sub_command=argv[3];
        if (sub_command=="-encode"){
            control.Encode(argv[2]);
        }
        else if(sub_command=="-decode"){
            control.Decode(argv[2]);
        }
    }
    else if(command=="-s"){
        control.Letters(argv[2]);
    }
    else if(command=="-l"){
        control.ListTree();
    }
    return 0;
}
