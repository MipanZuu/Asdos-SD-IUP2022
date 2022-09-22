#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    stack<int>myStack;
    int a;
    string input;
    int count = 0;
    
    cin >> a;
    
    for(int b = 0; b < a; b++){
        cin >> input;
        if (input == "hinzufugen") {
            int number, times;
            cin >> number >> times;
            for (int i = 0; i<times; i++) {
                myStack.push(number-count);
            }
            cout << myStack.size() << endl;
        }
        if (input == "subtrahieren") {
            int number;
            cin >> number;
            cout << myStack.top()+count << endl;
            for (int j = 0; j < number; j++) {
                myStack.pop();
            }
        }
        if (input == "ger") {
            int adding;
            cin >> adding;
            count = count+adding;
        }
        if (input == "gre") {
            int minus;
            cin >> minus;
            count = count-minus;
    }
    
}
    
    return 0;
}