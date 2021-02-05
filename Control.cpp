
#include "Control.h"
using namespace std;
Control::Control() {

}

Control::~Control() {

}

void Control::Encode(string inputfile) {
    Frequency frequency;
    Tree branchlower,branchbigger,root;
    vector<pair<int,string>> encoder_list,sub_listlower,sub_listbigger;



    ofstream myfile;
    myfile.open ("dictionary.txt");
    myfile.close();

    encoder_list = frequency.calculate_frequency();
    sort(encoder_list.begin(), encoder_list.end());

    int totalfrequencylower=0,totalfrequencybigger=0;
    for (int i = 0; i < encoder_list.size() ; i++) {
        sub_listlower.push_back(encoder_list[i]);
        totalfrequencylower= totalfrequencylower + encoder_list[i].first;
        if (totalfrequencylower >= totalfrequencybigger && encoder_list[i] != encoder_list[encoder_list.size() - 1]){
            totalfrequencybigger+=encoder_list[encoder_list.size() - 1].first;
            sub_listbigger.insert(sub_listbigger.begin(), encoder_list[encoder_list.size() - 1]);
            encoder_list.erase(encoder_list.end()-1);
        }
    }

    for (int i = 0 ; i < sub_listlower.size(); i++){
        branchlower.Add(sub_listlower[i].second, sub_listlower[i].first);
    }
    for (int i = 0 ; i < sub_listbigger.size(); i++){
        branchbigger.Add(sub_listbigger[i].second, sub_listbigger[i].first);
    }

    branchlower.TailCalibration();
    branchbigger.TailCalibration();

    ofstream myreset;
    myreset.open ("tree.txt");
    myreset.close();
    ofstream mytree;
    mytree.open ("tree.txt",std::ios_base::app);
    mytree<<"+- root"<<endl;
    if (branchlower.getFrequency() > branchbigger.getFrequency())
    {
        //branchlower is 1 branchbigger is 0 then
        mytree<<"   +- branch-left"<<endl;
        branchbigger.printInorder(branchbigger.tail, "left");
        mytree<<"   +- branch-right"<<endl;
        branchlower.printInorder(branchlower.tail, "right");
    }
    else{
        //branchlower is 0 branchbigger is 1 then
        mytree<<"   +- branch-left"<<endl;
        branchlower.printInorder(branchlower.tail, "left");
        mytree<<"   +- branch-right"<<endl;
        branchbigger.printInorder(branchbigger.tail, "right");
    }

    mytree.close();


    vector<string> output_letters;
    string Dictionary_text;
    ifstream MyDictionary("dictionary.txt");
    while (getline (MyDictionary, Dictionary_text)){
        output_letters.push_back(Dictionary_text);
    }


    string original_text,temp_text;
    ifstream MyEncodeFile(inputfile);
    int line=0;
    while (getline (MyEncodeFile, original_text))
    {

        if (line>=1){

            for (int i = 0; i < output_letters.size() ; i++)
            {
                if (output_letters[i].substr(0,1)=="\\")
                {
                    cout<<output_letters[i].substr(1);
                    break;
                }

            }
            for (int i = 0; i < output_letters.size() ; i++) {
                if (output_letters[i].substr(0,1)=="n")
                {
                    cout<<output_letters[i].substr(1);
                    break;
                }
            }
        }
        while (original_text.size()>0){
            temp_text = original_text.substr(0,1);
            original_text= original_text.substr(1);
            for (int i = 0; i < output_letters.size() ; i++)
            {
                if (output_letters[i].substr(0,1)==temp_text)
                {
                    cout<<output_letters[i].substr(1);
                    break;
                }
            }
        }
        line++;
    }
    line=0;
}

void Control::Decode(string inputfile) {

    string original_text,temp_text;
    vector<string> output_letters;
    temp_text.clear();
    ifstream MyDecodeFile(inputfile);

    string Dictionary_text;
    ifstream MyDictionary("dictionary.txt");
    while (getline (MyDictionary, Dictionary_text)){
        output_letters.push_back(Dictionary_text);
    }
    while (getline (MyDecodeFile, original_text))
    {
        while (original_text.size()>0){
            temp_text.append(original_text.substr(0,1));
            original_text= original_text.substr(1);
            for (int i = 0; i < output_letters.size() ; i++)
            {
                if (output_letters[i].substr(1)==temp_text)
                {
                    cout<<output_letters[i].substr(0,1);
                    temp_text.clear();
                    break;
                }
            }
        }
    }
    cout<<endl;

}

void Control::ListTree() {
    string original_text,temp_text;
    ifstream MyTreeFile("tree.txt");
    while (getline (MyTreeFile, original_text))
    {
        cout<<original_text<<endl;
    }
}

void Control::Letters(string input) {
    vector<string> output_letters;
    string Dictionary_text;
    ifstream MyDictionary("dictionary.txt");
    while (getline (MyDictionary, Dictionary_text)){
        output_letters.push_back(Dictionary_text);
    }

        for (int i = 0; i < output_letters.size() ; i++)
        {
            if (output_letters[i].substr(0,1)==input)
            {
                cout<<output_letters[i].substr(1)<<endl;
                break;
            }
        }


}
