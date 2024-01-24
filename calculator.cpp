#include <iostream>
#include <string>
#include <regex>

using namespace std;

int calculator(const string &operation) {
    smatch operation_match;
    if (regex_search(operation, operation_match, regex("^([0-9]+)([-+*/])([0-9]+)"))) {
        int initial = stoi(operation_match[1]);
        int final_number = stoi(operation_match[3]);
        char operation_ = operation_match[2].str()[0];
        string operators ("+-*/");

        int result = 0;

        switch (operation_) {
            case '+':
                result = initial + final_number;
                break;
            case '-':
                result = initial - final_number;
                break;
            case '*':
                result = initial * final_number;
                break;
            case '/':
                result = initial / final_number;
                break;
            default:
                cout << "Invalid operation." << endl;
                return 0; 
        }
        if (!operation_match.suffix().str().empty() && operators.find(operation_match.suffix().str()[0]) != std::string::npos) {
            return calculator(to_string(result) + operation_match.suffix().str());
        } else {
            return result;
        }
    } else {
        cout << "The operation provided isn't proper, please check again" << endl;
        return 0;
    }
}

int main() {
    string operation ("");
    cin >> operation;
    cout << calculator(operation) << endl;
    return 0;
}
