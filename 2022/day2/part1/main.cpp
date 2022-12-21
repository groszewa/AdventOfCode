#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main () {
    ifstream file("input.txt");
    string str;
    int scores[3][3] = {
        {
            4, // A X : 1 + 3 = 4
            8, // A Y : 2 + 6 = 8
            3  // A Z : 3 + 0 = 3
        },
        {
            1, // B X : 1 + 0 = 1
            5, // B Y : 2 + 3 = 5
            9  // B Z : 3 + 6 = 9
        },
        {
            7, // C X : 1 + 6 = 7
            2, // C Y : 2 + 0 = 2
            6  // C Z : 3 + 3 = 6
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
