#include <iostream>

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
    string s = "ABCDEF||&&&";

    stack e;
    ExpressionTree a;

    Node *x, *y, *z;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '&' || s[i] == '|'){
            z = new Node(s[i]);
            x = e.pop();
            y = e.pop();

            z->left = y;
            z->right = x;

            e.push(z);
        }

        else{
            z = new Node(s[i]);
            e.push(z);
        }
    }



    a.inorder(z);



}