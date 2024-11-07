/*
You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
Return the string formed after mapping.

The test cases are generated so that a unique mapping will always exist.

 

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
Example 2:

Input: s = "1326#"
Output: "acz"

*/



#include <iostream>
#include <map>
#include <string>
#include <cctype>
int main() {

    std::map<std::string, std::string> table = {
        {"1" , "a"},
        {"2" , "b"},
        {"3", "c"},
        {"4", "d"},
        {"5", "e"},
        {"6", "f"},
        {"7", "g"},
        {"8", "h"},
        {"9", "i"},
        {"10#", "j"},
        {"11#", "k"},
        {"12#", "l"},
        {"13#", "m"},
        {"14#", "n"},
        {"15#", "o"},
        {"16#", "p"},
        {"17#", "q"},
        {"18#", "r"},
        {"19#", "s"},
        {"20#", "t"},
        {"21#", "u"},
        {"22#", "v"},
        {"23#", "w"},
        {"24#", "x"},
        {"25#", "y"},
        {"26#", "z"}
    };     
    
    std::string input, output = ""; std::cin >> input;
    std::cout << input << std::endl;
    for (int i = input.size() - 1; i > -1; i--){
        if (input[i] == '#') {
            if (i >= 2 && isdigit(input[i - 1]) && isdigit(input[i - 2])){

                //CONSTRUCT THE KEY {XY#} WHEN IT'S ABOVE 9 vvv
                std::string key = std::string(1, input[i - 2]) + input[i - 1] + '#';

                if (table.find(key) != table.end()) {
                    output = table[key] + output;
                    std::cout << "Key found: " << key << " -> Value : " << table[key] << std::endl;
                }
                else {
                    std::cout << "Key not found in table." << std::endl;
                }

                i -= 2; // SKIP THE NUMBERS YOU'VE ALREADY CHECKED
            }
        }
        else if (isdigit(input[i])) {
                //CONSTRUCT THE KEY {X} WHEN IT'S BELOW 10 vvv
                std::string key(1, input[i]); // (1 FOR ONE CHARACTER)

                if (table.find(key) != table.end()) {
                    output = table[key] + output; // CONCATENATE THE MAP VALUE WITH THE REST OF THE VALUES 
                    std::cout << "Key found: " << key << " -> Value : " << table[key] << std::endl;
                }
                else {
                    std::cout << "Key not found in table." << std::endl;
                }
            }
        }
        std::cout << "Decoded Output: " << output << std::endl;
    return 0;
}
