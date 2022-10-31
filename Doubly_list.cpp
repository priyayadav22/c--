#include<iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node* prev=NULL;
    Node *next= NULL;

    Node(int d){
        int data;
        this->data= d;
        this->next= NULL;
        this->prev= NULL;
    }

    ~Node(){
        int val= this->data;
        if(next!= NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for "<< val <<endl;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<< " ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node*head){
    int len=0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp= temp->next;
    }
    return len;
}

void insertHead(Node* &head, int d, Node* &tail){
    if(head==NULL){
        Node* temp = new Node(d);
        head= temp;
        tail= temp;
    }
    else{
        Node *temp= new Node(d);
        temp->next= head;
        head->prev= temp;
        head= temp;
    }
}

void insertTail(Node* &head, int d, Node* &tail){
    if(tail==NULL){
        Node* temp= new Node(d);
        tail= temp; 
        head= temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next= temp;
        temp->prev= tail;
        tail= temp;
    }
}

void insertPosition(Node* &head, Node* &tail, int position, int d){
    if(position==1){
        insertHead(head,d,tail);
        return ;
    }
    Node* temp = head;
    int count=0;
    while(count<position-1){
        temp= temp->next;
        count++;
    }
    if(temp->next= NULL){
        insertTail(head, d, tail);
        return ;
    }
    Node* nodetoinsert = new Node(d);
    nodetoinsert->next= temp->next;
    temp->next->prev= nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void deleteNode(Node* &head, int position){
    if(position == 1){
        Node *temp= head;
        temp-> next->prev = NULL;
        head= temp->next;
        temp->next= NULL;
        delete temp;
    }
    else{
        Node* curr= head;
        Node* prev= NULL;

        int count=1;
        while(count<position){
            prev= curr;
            curr = curr->next;
            count++;
        }
        curr->prev= NULL;
        prev->next= curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    Node* head= NULL;
    Node* tail= NULL;
    print(head);
    insertHead(head,11,tail);
    insertHead(head,13,tail);
    insertHead(head,15,tail);
    insertTail(head,12,tail);

    deleteNode(head, 15);
    return 0;
}