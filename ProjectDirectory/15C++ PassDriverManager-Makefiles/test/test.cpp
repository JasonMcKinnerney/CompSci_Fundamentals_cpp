
//test 

#include<iostream>
#include<string>
using namespace std;



 
string encrypt(string pass) {
   string ret = "";
   for(int i = 0; i < pass.length(); ++i){
       ret += ((pass[i] - 33) + 45) % 94 + 33;
    cout << ret << " ";
   }
   cout << ret << endl;

   return ret;
}

bool meetsCriteria(string pass) {
    bool valid = true;
    bool digit = false;
    bool lower = false;
    char ch;


    if (pass.length() < 9) {
        valid = false;
        return valid;
    }
    if (pass[0] == '_') {
        valid = false;
        return valid;
    } 
    
    
    for (int i = 0; i < pass.length(); ++i){
        ch = pass[i];
        if (islower(ch)){
            lower = true;
        }
        if (isdigit(ch)) {
            digit = true;
        }    
    }

    if (digit != true || lower != true) {
        valid = false;
    }
    return valid;
}

    void setUsername(string) {

}

bool authenticate(string pass){
    bool flag;
    string encrypted = "000fff[[[";
    string tempEncrypt;
    cout << "encrypted: " << encrypted << endl;
    cout << "pass: " << pass << endl;
    tempEncrypt = encrypt(pass);
    cout << "tempEncrypt: " << tempEncrypt << endl;
    if (tempEncrypt == encrypted) {
        flag = true;
    }
    else {
        flag = false;
    }
    return flag;
}
int main() {

    string pass;
    string result;
    //cout << "Type password to encrypt: ";
    //cin >> pass;

    //result = encrypt(pass);

    //cout << "Encryption: " << result << endl << endl;;

    cout << "Testing authenticate" << endl;
    cout << "----------------------" << endl << endl;

    string string1, string2, string3;
    cout << "Enter Test Case 1: ";
    cin >> string1;
    cout << boolalpha << authenticate(string1) << endl << endl;
    cout << "Enter Test Case 2: ";
    cin >> string2;
    cout << boolalpha <<  authenticate(string2) << endl << endl;
    cout << "Enter Test Case 3: ";
    cin >> string3;
    cout << boolalpha << authenticate(string3) << endl << endl;
    

    return 0;
}
