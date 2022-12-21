#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    //ifstream file("test.txt");
    ifstream file("input.txt");
    string str;
    int total_overlaps = 0;
    while(getline(file, str)) {
        int comma_index = str.find(',');
        string range1 = str.substr(0,comma_index);
        string range2 = str.substr(comma_index+1);
        int r1_split = range1.find('-');
        int min1 = stoi(range1.substr(0,r1_split));
        int max1 = stoi(range1.substr(r1_split+1));
        int r2_split = range2.find('-');
        int min2 = stoi(range2.substr(0,r2_split));
        int max2 = stoi(range2.substr(r2_split+1));
        //cout << "[" << min1 << " : " << max1 << "] [" << min2 << " : " << max2 << "] ";
        //no_overlap =       max1 <  min2 or  min1 >  max2
        //overlap    = not ( max1 <  min2 or  min1 >  max2 )
        //overlap    =       max1 >= min2 and min1 <= max2
        if(((max1 >= min2) and (min1 <= max2))) total_overlaps++;
    }
    cout << "Total overlaps = " << total_overlaps << endl;
    return 0;
}
