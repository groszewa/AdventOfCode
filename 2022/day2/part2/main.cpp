#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main () {
    ifstream file("input.txt");
    string str;
    int scores[3][3] = {
        {
            3, // A X : 3 + 0
            4, // A Y : 1 + 3
            8  // A Z : 2 + 6
        },
        {
            1, // B X : 1 + 0
            5, // B Y : 2 + 3
            9  // B Z : 3 + 6
        },
        {
            2, // C X : 2 + 0
            6, // C Y : 3 + 3
            7  // C Z : 1 + 6
        }
    };
    int score = 0;
    while(getline(file, str)) {
        char them = str[0];
        char you  = str[2];
        score += scores[them - 'A'][you - 'X'];
    }
    cout << "The final score is " << score << endl;
    return 0;
}
