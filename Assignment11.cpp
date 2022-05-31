#include <iostream>
using namespace std;

class Queue;    
class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    friend class Queue;
};

class Queue 
{
private:
    Node *front;
    Node *rear;
    int size;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void Enqueue(int no) 
    {
        Node * newn = new Node();
        newn->data = no;
        newn->next = NULL;

        if (front == NULL && rear == NULL) 
        {
            front = newn;
            rear = newn;
        }
        else
        {
            rear->next = newn;
            rear = newn;       
        }
        size++;
    }

    int Dequeue()
    {
        int no = 0;
               Node * temp = front;
               
               if(front == NULL && rear == NULL)
               {
                   cout<<"Queue is empty\n";
                   return -1;
               }
               
               if(front == rear)
               {
                   no = front->data;
                   delete front;
                   front = NULL;
                   rear = NULL;
               }
               else
               {
                   no = front->data;
                   front = front -> next;
                   delete temp;
               }
               
               size--;
               return no;
    }

    void Display()
    {
        Node * temp = front;

        for(int i = 1 ; i <= size; i++)
        {
            cout<<"|"<<temp->data<<"|-> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }

    int Count()
    {
        return size;
    }
};

int main()
{
    Queue obj;
    int choice = 0, ele = 0, count = 0;
    while (choice != 5)
    {
        cout<<"1) Enter elements in Queue\n";
        cout<<"2) Delete elements in Queue\n";
        cout<<"3) Number of elements in Queue\n";
        cout<<"4) Display Queue\n";
        cout<<"5) Exit\n";

        cout<<"Enter choice\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter element\n";
            cin>>ele;
            obj.Enqueue(ele);
            break;
        case 2:
            obj.Dequeue();
            break;   
        case 3:
            count = obj.Count();
            cout<<"Number of elements are "<<count<<endl;
            break;   
        case 4:
            obj.Display();
            break;   
        case 5:
            cout<<"Thank you !\n";
            break; 
        default:
            break;
        }
    }
    
    return 0;
}
