#include<string>
#include<fstream>
#include<vector>
#include<iostream>

using namespace std;


vector<string> readFile1(string filename){
    vector<string> lines;
    string line;

    ifstream infile(filename);

    while(infile >> line){
        if(line.length())
            lines.push_back(line);
    }

    return lines;
}

vector<string> readFile2(string filename){
    vector<string> lines;
    string line;

    ifstream infile(filename);
    while(getline(infile, line)){   // getline
        if(line.length())
            lines.push_back(line);
    }

    return lines;
}

void printLines(vector<string> lines){
    for(int i=0; i<lines.size(); i++)
        cout << lines[i] << endl;
}

int main(){
    string filename = "vocab.txt";

    vector<string> words;
    words = readFile1(filename);
    printLines(words);
    words.clear();
    words = readFile2(filename);
    printLines(words);
}
