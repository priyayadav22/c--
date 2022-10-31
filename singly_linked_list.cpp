#include<iostream>
#include<map>

using namespace std;

class Node{
    public: 
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next= NULL;
    }   

    ~Node(){
        int value= this->data;
        if(this->next!= NULL){
            delete next;
            this->next= NULL;
        }
        cout<<"memo free with  data" <<value <<endl;
    } 
};

void insertHead(Node*  &head, int d){
    Node *temp= new Node(d);
    temp->next= head;
    head= temp;
}

void insertTail(Node* &tail, int  d){
    Node *temp= new Node(d);
    tail->next=temp;
    tail= temp;
}

void print(Node* &head){
    if(head==NULL){
        cout<<"List is empty." <<endl;
        return;
    }
    Node*temp= head;
    while(temp!= NULL){
        cout<<temp->data<< " ";
        temp= temp->next;
    }
    cout<<endl;
}

void insertPosition(Node* &tail, Node* &head, int position,int d){
    if(position ==1){
        insertHead(head,d);
        return;
    }
    Node* temp =head;
    int count=1;
    while(count<position-1){
        temp= temp->next;
        count++;
    }
    if(temp->next == NULL){
        insertTail(tail,d);
        return;
    }
    Node* nodetoinsert= new Node(d);
    nodetoinsert->next = temp->next;
    temp->next= nodetoinsert;
}

void deleteNode(int position, Node *head){
    if(position==1){
        Node* temp= head;
        head= head->next;
        temp->next= NULL;
        delete temp;
    }
    else{
        Node* curr= head;
        Node* prev= NULL;
        int count=1;
        while(count<position){
            prev=curr;
            curr= curr->next;
            count++; 
        }
        prev->next= curr->next;
        curr->next=NULL;
        delete curr;

    }
}

int main(){
    Node *node1= new Node(10);
    Node *head= node1;
    Node *tail= node1;

    insertTail(tail,12);
    insertTail(tail,15);


}