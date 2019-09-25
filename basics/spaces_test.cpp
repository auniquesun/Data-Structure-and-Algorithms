#include<iostream>
#include<string>

using namespace std;

int main(){
    // reference: http://www.cplusplus.com/forum/general/51464/
    char ch;
    cin >> ch; // will neglect spaces
    if(ch == ' ')
        cout << "one: yes" << endl;
    else
        cout << "one: no" << endl;

    // judge a char eqauls to ' ' should be like this.
    string s;
    cin >> s;
    cout << s << endl;
    for(int i=0; i<s.size(); i++){
        if(s[i] == char(32))
            cout << "two: yes" << endl;
        else
            cout << "two: no" << endl;
    }
    s = "a  d";
    for(int i=0; i<s.size(); i++){
        if(s[i] == char(32))
            cout << "three: yes" << endl;
        else
            cout << "three: no" << endl;
    }
}
