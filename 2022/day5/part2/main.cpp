#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include<vector>
using namespace std;


int main() {
    //ifstream file("test.txt");
    ifstream file("input.txt");
    string str;
    stack<string> initial_state;
    do {
        getline(file, str);
        if(str[1]=='1') break;
        initial_state.push(str);
    } while(true);
    vector<stack<char>> v;
    v.push_back(stack<char>());
    for(auto ch : str) if(isdigit(ch)) v.push_back(stack<char>());
    while(not initial_state.empty()) {
        string line = initial_state.top();
        int index = 1;
        for(int i=1; i<line.size(); i+=4) {
            if(isalpha(line[i])) {
                v[index].push(line[i]);
            }
            index++;
        }
        initial_state.pop();
    }
    getline(file, str);
    while(getline(file, str)) {
        str = str.substr(str.find(' ')+1);
        int count = stoi(str.substr(0,str.find(' ')));
        str = str.substr(str.find(' ')+1);
        str = str.substr(str.find(' ')+1);
        int from  = stoi(str.substr(0,str.find(' ')));
        str = str.substr(str.find(' ')+1);
        str = str.substr(str.find(' ')+1);
        int to    = stoi(str);
        stack<char> tmp;
        while(count) {
            tmp.push(v[from].top());
            v[from].pop();
            count--;
        }
        while(not tmp.empty()) {
            v[to].push(tmp.top()); 
            tmp.pop();
        }
    }
    for(int i=1; i<v.size(); i++) cout << v[i].top();
    cout << endl;
    return 0;
}
