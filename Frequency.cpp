//
// Created by Selcuk on 18.12.2020.
//

#include "Frequency.h"

using namespace std;
Frequency::Frequency() {

}

Frequency::~Frequency() {

}


std::vector<std::pair<int,string>> Frequency::calculate_frequency() {
    map<string, int> encoder;
    int line=0;
    vector<pair<int,string>> encoder_list;
    string original_text,temp_text;
    ifstream MyReadFile("input_1.txt");
    temp_text=" ";

    while (getline (MyReadFile, original_text))
    {
        for_each(original_text.begin(), original_text.end(), [](char & c){
            c = tolower(c);
        });

        if (line>=1){
            if(encoder.count("\\") > 0)
            {
                encoder.at("\\")++;
            }
            else{
                encoder.insert(pair<string, int>("\\", 1));
            }
            if(encoder.count("n") > 0)
            {
                encoder.at("n")++;
            }
            else{
                encoder.insert(pair<string, int>("n", 1));

            }

        }
        while (original_text.size()>0){

            temp_text = original_text.substr(0,1);
            original_text= original_text.substr(1);

            if(encoder.count(temp_text) > 0)
            {
                encoder.at(temp_text)++;
            }
            else{
                encoder.insert(pair<string, int>(temp_text, 1));

            }
        }
        line++;
    }
    MyReadFile.close();

    for (std::pair<std::string, int> element : encoder)
    {

        encoder_list.push_back(make_pair(element.second,element.first));
    }





    return (encoder_list);
}


