#include<bits/stdc++.h>
using namespace std;

class Node{
public:
        int value;
        Node *left=NULL;
        Node *right=NULL;

        Node(int value){
            this->value=value;
        }
};
class BinaryTree{
public:
    Node *root=NULL;
    BinaryTree(){
        cout<<"Create the tree"<<endl;
        root=createTree();
    }
    Node * createTree(){
        int val;
        Node *newNode=NULL;
        cout<<"Enter the node value "<<endl;
        cin>>val;
        if(val==-1) return newNode;
        newNode=new Node(val);
        cout<<"Enter left child of "<<val<<endl;
        newNode->left=createTree();
        cout<<"Enter right child of "<<val<<endl;
        newNode->right=createTree();
    }
    void inOrderTraversal(Node * root){
        if(root==NULL) return;
        inOrderTraversal(root->left);
        cout<<root->value<<" ";
        inOrderTraversal(root->right);
    }
};
int main(){
    BinaryTree bt;
    bt.inOrderTraversal(bt.root);
    return 0;
}
