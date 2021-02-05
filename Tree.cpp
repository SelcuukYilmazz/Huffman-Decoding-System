#include "Tree.h"

using namespace std;
string movea="";
string set_text="   |";
Tree::Tree()
{
    TreeNode* temp = new TreeNode();
    temp->item="";
    frequency = 0;
    temp->rightchild = nullptr;
    temp->leftchild = nullptr;
    temp->parent = nullptr;
    tail = temp;
}


Tree::~Tree()
{
}


void Tree::TailCalibration(){
    if (tail->leftchild==NULL||tail->rightchild==NULL){
        if (tail->leftchild!=NULL){
            tail = tail->leftchild;
        }
        else  if (tail->rightchild!=NULL){
            tail = tail->rightchild;
        }
    }

}
void Tree::Add(std::string xitem,int xfrequency)
{
    if (tail->leftchild==NULL){
        tail->leftchild= new TreeNode();
        tail->leftchild->parent = tail;
        tail->leftchild->item = xitem;
        frequency+=xfrequency;
        tail->leftchild->leftchild = nullptr;
        tail->leftchild->rightchild = nullptr;
    }
    else if(tail->rightchild==NULL) {
        tail->rightchild = new TreeNode();
        tail->rightchild->parent=tail;
        tail->rightchild->item = xitem;
        frequency+=xfrequency;
        tail->rightchild->leftchild = nullptr;
        tail->rightchild->rightchild = nullptr;
    }
    else{
        if (frequency>xfrequency){
            tail->parent = new TreeNode();
            tail->parent->rightchild =tail;
            tail = tail->parent;
            tail->item = "";
            tail->leftchild = new TreeNode();
            tail->leftchild->parent = tail;
            tail->leftchild->item = xitem;
            frequency+=xfrequency;
            tail->leftchild->leftchild= nullptr;
            tail->leftchild->rightchild= nullptr;
        }
        else if (frequency<=xfrequency){
            tail->parent = new TreeNode();
            tail->parent->leftchild =tail;
            tail = tail->parent;
            tail->item = "";
            tail->rightchild = new TreeNode();
            tail->rightchild->parent = tail;
            tail->rightchild->item = xitem;
            frequency+=xfrequency;
            tail->rightchild->leftchild= nullptr;
            tail->rightchild->rightchild= nullptr;
        }
    }
}

int Tree::getFrequency() const {
    return frequency;
}

void Tree::printInorder(struct TreeNode* node,string location)
{


    ofstream mytree;
    mytree.open ("tree.txt",std::ios_base::app);

    ofstream myfile;
    myfile.open ("dictionary.txt",std::ios_base::app);

    if (node == NULL){
        return;}



    /* first recur on left child */
    if (node->item!="")
    {

        if(location == "left")
        {
            movea.append("0");
            node->item=node->item.append(movea);
        }
        else if (location == "right")
        {

            movea.append("1");
            node->item=node->item.append(movea);

        }
        if (node==tail&&node->item!=""){
            mytree<<"   |  +- grandchild-"<<node->item<<endl;
            myfile << node->item <<endl;
            movea.clear();
            return;
        }
    }
    else{
        if (location=="left")
        {
            movea.append("0");
        }
        else if(location =="right")
        {
            movea.append("1");
        }
    }


    if (node!=tail&&location =="left"&&movea.substr(0,1)=="1"){
        if (node->parent->leftchild->item!=""||node->parent->rightchild->item!=""){
            mytree<<set_text<<"  +- Parent-"<<movea.substr(0,movea.size()-1)<<endl;
            set_text.append("  |");
        }
    }

    if (node!=tail && location =="left"&&movea.substr(0,1)=="0"){

        if (node->parent->leftchild->item!=""||node->parent->rightchild->item!=""){
            mytree<<set_text<<"  +- Parent-"<<movea.substr(0,movea.size()-1)<<endl;
            set_text.append("  |");
        }
    }
    if (node->item!="" && movea.substr(0,1)=="0")
    {
        mytree<<set_text<<"  +- "<<"grandchild-"<<node->item<<endl;
    }


    printInorder(node->leftchild,"left");

    if (node->item!="")
    {
        myfile << node->item <<endl;
    }

    printInorder(node->rightchild,"right");

    if (node->item!="" && movea.substr(0,1)=="1")
    {
        mytree<<set_text<<"  +- "<<"grandchild-"<<node->item<<endl;
    }

    if (location=="right"){
        set_text=set_text.substr(0,set_text.size()-3);
    }

    if (!movea.empty()) {
        movea.erase(std::prev(movea.end()));
    }


    myfile.close();
    mytree.close();
}

