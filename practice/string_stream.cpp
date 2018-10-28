#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    int value;
    char separator;
    stringstream ss(str);
    vector<int> int_values;
    ss >> value;
    while(ss.peek() != -1){
        int_values.push_back(value);
        ss >> separator;
        ss >> value;
    }
    if(value != NULL){
        int_values.push_back(value);
    }
    return int_values;
}

int main() {
    string str;
    int sum = 0;
    cin >> str;
    vector<int> integers = parseInts(str);
    cout << endl << "printing vector contents" << endl;
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
        sum += integers[i];
    }
    cout << sum << endl;
    return 0;
}
