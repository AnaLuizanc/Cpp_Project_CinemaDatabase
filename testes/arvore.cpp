#include <iostream>
#include <vector>
#include <string>
//#include <stack>

using namespace std;

class Node{
    public:
        Node* left;
        Node* right;
        Node* next = NULL;
        char value;
        Node(char c){
            this->value = c;
            this->left = NULL;
            this->right = NULL;
        }
        Node(){
            this->left = NULL;
            this->right = NULL;
        }
};

class ExpressionTree{
    public:
        void inorder(Node* x){
            if (x == NULL)
                return;

            else{
                inorder(x->left);
                cout << x->value << " ";
                inorder(x->right);
            }
        }
};

class stack{
    Node* head = NULL;

    public:
        void push(Node*);
        Node* pop();

        friend class ExpressionTree;


};


Node* stack::pop(){
    Node* p = head;
    head = head->next;
    return p;

}

void stack::push(Node* x){
    if(!head)
        head = x;

    else{
        x->next = head;
        head = x;
    }

}


int main(){
    string s = "AB&C&DE|&";

    vector<string> keywords = {"titleType", "year", "genres"};

    stack e;
    ExpressionTree a;

    Node *x, *y, *z;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '&' || s[i] == '|'){
            z = new Node(s[i]);
            x = e.pop();
            y = e.pop();


            z->right = x;
            z->left = y;

            e.push(z);
        }

        else{
            z = new Node(s[i]);
            e.push(z);
        }
    }



    a.inorder(z);



    string input = "titleType(tvEpisode,short)&year(2023)&genres(Animation&Music)";
    vector<string> tokens;

    // Iterate through the string character by character
    for (char c : input) {
        // If the character is not a delimiter, append it to the current token
        if (c != ':' && c != '(' && c != ')' && c != ',') {
            if (tokens.empty() || tokens.back().back() != ' ') {
                tokens.push_back("");
            }
            tokens.back() += c;
        } else {
            // If the character is a delimiter, add it as a separate token
            tokens.push_back(string(1, c));
        }
    }

    for (const string& token : tokens) {
        //cout << token;
    }

    stack<string> values;
    stack<string> keychains;
    string queryDelimited;
    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i] == ":" || tokens[i] == "(" || tokens[i] == ")" || tokens[i] == "," || tokens[i] == "&"){
            if(queryDelimited != keywords[0] && queryDelimited != keywords[1] && queryDelimited != keywords[2])
                values.push(queryDelimited);
            
            keychains.push(tokens[i]);
            queryDelimited.clear();
            
        }
        else
            queryDelimited.append(tokens[i]);
    }

    for(int i = values.size()-1; i >=0; i--){
        cout << values.top() << " ";
        values.pop();
    }

    cout << endl;


    stack<string> defined;
    stack<string> final;


    for(int i = keychains.size()-1; i >= 0; i--){
        if(keychains.top() == "(" || keychains.top() == ")")
            keychains.pop();
        else{
            defined.push(keychains.top());
            keychains.pop();
        }

    }


    
    for(int i = defined.size()-1; i >=0; i--){
        cout << defined.top() << " ";
        defined.pop();
    }*/








}