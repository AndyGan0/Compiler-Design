#pragma once
#include <iostream>
#include <queue>
using namespace std;




//Decraring classes
class ParseTree;



//Defining Class BinaryTreeNode
class Node {
public:
    Node() { }
    friend ParseTree;

private:    
    string data;
    vector<Node*>Children;
};






class ParseTree {
private:

    Node* root;    //  pointer to the root

    Node* makeEmpty(Node* t) {

        if (t == NULL)
            return NULL;
        {
            for (size_t i = 0; i < t->Children.size(); i++)
            {
                makeEmpty(t->Children[i]);
            }
            t->Children.clear();
            delete t;
        }
        return NULL;
    }


    bool InsertHelper(Node* current, string OldSymbol, string NewSymbol) {
        //  In-Order traversal

        //current node

        //  checking if current leaf
        if (current->Children.empty()) {
            if (current->data == OldSymbol) {

                //  if Z-->ε 
                if (NewSymbol == "") {
                    Node* temp = new Node;
                    temp->data = "";
                    current->Children.push_back(temp);
                }

                // else
                for (int i = 0; i < NewSymbol.size(); i++)
                {
                    Node* temp = new Node;
                    temp->data = NewSymbol[i];
                    current->Children.push_back(temp);
                }
                return true;
            }
            return false;
        }


        for (int i = 0; i < current->Children.size(); i++)
        {

            if (InsertHelper(current->Children[i], OldSymbol, NewSymbol) == true) {
                return true;
            }

        }
        return false;

    }

    
    void PrintHelper(const std::string& prefix, const Node* node, bool NotLastChildOfParent)
    {
        if (node)
        {

            std::cout << prefix;

            // print the value of the node
            if (NotLastChildOfParent) {
                std::cout << "|---  " << node->data << endl;
            }
            else {
                std::cout << "'---  " << node->data << endl;
            }
            

            

            // enter the next tree level
            
            for (int i = 0; i < (node->Children.size()); i++) {

                if (i != node->Children.size() - 1) {
                    PrintHelper(prefix + (NotLastChildOfParent ? "|     " : "      "), node->Children[i], true);
                }
                else {
                    PrintHelper(prefix + (NotLastChildOfParent ? "|     " : "      "), node->Children[i], false);
                }

            }


        }
    }

     
    


public:    

    ParseTree() { root = new Node; root->data = "S"; };


    ~ParseTree() { root = makeEmpty(root); };


    bool Insert(string OldSymbol, string NewSymbol) {        
        return InsertHelper(root, OldSymbol, NewSymbol);
    }
    

    void print() {
        PrintHelper("", root, false);
    }


};
