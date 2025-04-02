#include <iostream>
#include <string>
#include <stack>
#include "ParseTreeClass.h"

using namespace std;


/*

S → (Χ)
Χ → ΥΖ
Υ → a | b | S
Ζ → *Χ | -Χ | +Χ | ε

*/




bool analyze(string input, ParseTree* mytree) {

    stack<string> stack;
    stack.push("$");
    stack.push("S");

    input.append("$");   


    while (stack.empty() == false) {                                  

        if (stack.top() == "S") {

            stack.pop();

            if (input[0] == '(') {

                stack.push(")");
                stack.push("X");
                stack.push("(");
                mytree->Insert("S", "(X)");

            }
            else {
                mytree->~ParseTree();
                return false;
            }

        }
        else if (stack.top() == "X") {

            stack.pop();

            if (input[0] == '(' || input[0] == 'a' || input[0] == 'b') {

                stack.push("Z");
                stack.push("Y");
                mytree->Insert("X", "YZ");
            }
            else {
                mytree->~ParseTree();
                return false;
            }

        }
        else if (stack.top() == "Y") {

            stack.pop();

            if (input[0] == '(') {

                stack.push("S");
                mytree->Insert("Y", "S");

            }
            else if (input[0] == 'a') {
                
                stack.push("a");
                mytree->Insert("Y", "a");

            }
            else if (input[0] == 'b') {

                stack.push("b");
                mytree->Insert("Y", "b");

            }
            else {
                mytree->~ParseTree();
                return false;
            }

        }
        else if (stack.top() == "Z") {

            stack.pop();

            if (input[0] == ')') {
                mytree->Insert("Z", "");

            }
            else if (input[0] == '*') {

                stack.push("X");
                stack.push("*");
                mytree->Insert("Z", "*X");

            }
            else if (input[0] == '-') {

                stack.push("X");
                stack.push("-");
                mytree->Insert("Z", "-X");

            }
            else if (input[0] == '+') {

                stack.push("X");
                stack.push("+");
                mytree->Insert("Z", "+X");

            }
            else {
                mytree->~ParseTree();
                return false;
            }

        }
        else if (stack.top() == "(") {
                     
            if (input[0] != '(') {
                mytree->~ParseTree();
                return false;
            }
            stack.pop();
            input.erase(0, 1);
        }
        else if (stack.top() == ")") {

            if (input[0] != ')') {
                mytree->~ParseTree();
                return false;
            }
            stack.pop();
            input.erase(0, 1);
        }
        else if (stack.top() == "a" || stack.top() == "b" || stack.top() == "*" || stack.top() == "-" || stack.top() == "+" || stack.top() == "$") {

            if ( input[0] != stack.top()[0]) {
                mytree->~ParseTree();
                return false;
            }
            stack.pop();
            input.erase(0, 1);
        }


    }


    return true;

}




int main()
{
    string input;
    cout << "Enter input: ";
    cin >> input;
    cout << "\n";

    
    ParseTree mytree;


    if (analyze(input, &mytree)) {
        cout << "It belongs to the grammar \n\n";
        mytree.print();

    }
    else {
        cout << "\n\nIt doesn't belong to the grammar \n";
    } 


}
