#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
       this->data = data;
       this->next = NULL;
    }
};
void Print(Node*  head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
}
void insertNode(Node* &head,int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

int Length(Node* & head){
     int len =1;
     Node* temp = head;
     while(temp->next != NULL){
        len++;
        temp = temp->next;
     }
     return len;
}

void DeleteHead(Node* &head){
     Node* temp = head;
     head = head->next;
     temp->next= NULL;
     delete temp;
}


void DeleteTail(Node* &head,Node* tail){
    Node* temp = head;
    int i=1;
    int pos = Length(head);
    while(i<pos-1){
         temp = temp->next;
         i++;
    }
    temp->next = NULL;
    tail = temp;
    delete temp;
}


void deleteMiddle(Node* &head,int pos ){
    Node* prev = head;
    int i=1;
    while(i<pos-1){
         prev = prev->next;
         i++;
    }
    Node* curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;

}


Node *getMiddle(Node* & head){
    if(head==NULL){
        return head;
    }

    if(head->next == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && slow!=NULL){
          fast = fast->next;
          if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
          }
    }
    return slow;
}


Node* reverseKNodes(Node*& head, int k){
    if (head == NULL) {
        return head;
    }

    // Check if there are at least k nodes in the list
    Node* temp = head;
    int len = 0;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    if (len < k) {
        return head;
    }


    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    int count =0;
    while(count < k & curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;

        curr= forward;
        count++;

    }
    if(forward!=NULL){
        head->next = reverseKNodes(forward,k);
    }
    return prev;
}


bool checkLoop(Node* & head){
    if(head == NULL){
        return false;
    }
    Node* fast = head;
    Node* slow = head;
    while (fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL){
          fast = fast->next;
          slow = slow->next;
        }
        if(fast == slow){
            return true;
        }

    }
    return false;
    
}

Node* findStart(Node* & head){
    if(head == NULL){
        return head;
    }
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
            slow= slow->next;
        }
        if(fast == slow){
            slow = head;
        }
        while(slow != fast){
            fast =  fast->next;
            slow= slow->next;
        }

    }
    return slow;
}


int main(){
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    first->next = second;
    second->next= third;
    insertNode(first,5);
    reverseKNodes(first,2);
    // cout<<"Length  : "<<Length(first)<<endl;
    Print(first);
}