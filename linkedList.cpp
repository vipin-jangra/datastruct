#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next = NULL;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);

    if(head == NULL){
        head = n;
        return ;
    }
    Node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;

}

bool search(Node* head, int key){
    Node* temp = head;

    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        
        temp = temp->next;
    }
    return false;
}

void delteAtHead(Node* &head){
    Node* todelete = head;
    head = head->next;

    delete todelete;
}

void deletion(Node* &head, int val)
{
    Node* temp = head;
    if(head==NULL){
        return;
    }

    if(head->next == NULL){
        delteAtHead(head);
        return;
    }
    while(temp->next->data!=val){
        temp = temp->next;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

Node* reverse(Node* &head){
    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr;

    while(currPtr !=NULL){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    return prevPtr;
}

int main(){

    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);

    insertAtHead(head,4);
    display(head);

    cout<< search(head,3)<<endl;

    delteAtHead(head);
    display(head);

    Node* newHead = reverse(head);
    display(newHead);

}