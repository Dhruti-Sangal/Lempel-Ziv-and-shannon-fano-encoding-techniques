#include <iostream>
#include <vector>
#include <string>
#include <map>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::map;
using std::endl;
using std::to_string;

string decToBinary(int n)
{
    // array to store binary number
    int binaryNum[10];
    // string to store position in binary form
    string posBinary="";

    int i = 0;
    while (n > 0) {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // Storing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        posBinary += to_string(binaryNum[j]);
    
    return posBinary;
}

void LZcoding(string s1)
{
    map<string, int> table;
    string ch = "";
    ch += s1[0];
    int index=1;
    int count=0;
    for (int i = 1; i < s1.length()+1; i++) {
        if (table.find(ch) == table.end()) {
            table[ch] = i;
            count++;
            ch = s1[index];
        }
        else {
            char check=' ';
            while(true) {
                string temp = "";
                temp += s1[index];
                ch += temp;
                if (table.find(ch) == table.end()) {
                    table[ch] = i;
                    count++;
                    index++;
                    ch = s1[index];
                    check = s1[index];
                    break;
                }
                else
                    index++;
            }
            // when end of input string is reached 
            if (check=='\0') 
                break;                
        }
        index++;
    }
    map<string, int>::iterator it = table.begin();

    cout << "Strings and their repective positions:\n" ; 
    while (it != table.end())
    {
        // Accessing the key
        string word = it->first;
        // Accessing the value
        int count = it->second;
        cout << word << " :: " << count << endl;
        // iterator incremented to point next item
        it++;
    }
    cout << endl;

    string substring="";
    cout << "String\tPosition\tSubstring\tOutputCode\n";

    it = table.begin();
    while (it != table.end())
    {
        // Accessing the key
        string word = it->first;
        // Accessing the value
        int pos = it->second;
        string codeword="";
        int len = word.length();

        if (len > 1) {
            substring = word.substr(0, len-1);
            int tempPos = table[substring];
            string temp_pos = decToBinary(tempPos);
            codeword = temp_pos + word[len-1];
            cout << word << "\t" << pos << "\t\t" << substring << "\t\t" << codeword << "\n";
        }
        else {
            codeword = word;
            cout << word << "\t" << pos << "\t\t\t\t" << codeword << "\n";
        }      

        // iterator incremented to point next item
        it++;
    }
}

int main()
{
    string s = "101101000100100010010101";
    LZcoding(s);
    cout << endl;
}
