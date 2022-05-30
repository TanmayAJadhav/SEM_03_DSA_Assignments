// The ticket booking system of Cinemax theatre has to be implemented using C++ program. There are 10 rows and 7 seats in each row. Doubly circular linked list has
// to be maintained to keep track of free seats at rows. Assume some random booking to start with. Use array to store pointers (Head pointer) to each row. On demand
// a) The list of available seats is to be displayed
// b) The seats are to be booked
// c) The booking can be cancelled.

#include <iostream>
using namespace std;

class Theatre;
class Node
{
private:
    Node *next;
    Node *previous;
    bool status;

public:
    Node()
    {
        next = NULL;
        previous = NULL;
        status = false;
    }
    friend class Theatre;
};

class Theatre
{
private:
    Node *head[10];
    Node *tail[10];

public:
    Theatre()
    {
        for (int i = 0; i < 10; i++)
        {
            head[i] = NULL;
            tail[i] = NULL;
        }
    }
    void prepareTheatre()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                Node *newn = new Node;
                if (head[i] == NULL)
                {
                    head[i] = newn;
                    tail[i] = newn;
                    newn->next = NULL;
                    newn->previous = NULL;
                }
                else
                {
                    tail[i]->next = newn;
                    newn->previous = tail[i];
                    tail[i] = newn;
                }
                head[i]->previous = tail[i];
                tail[i]->next = head[i];
            }
        }
    }

    void book()
    {
        int row,col;
        cout << "\nEnter row no : ";
        cin >> row;
        cout << "Enter coulmn no : ";
        cin >> col;
        row--;
        col--;
        int i = 0;
        if (row <= 9 && col <= 7)
        {
            Node *temp = head[row];
            for (i = 0; i < col; i++)
            {
                temp = temp->next;
            }
            if (temp->status == false)
            {
                temp->status = true;
                cout << "\nSeat booked successfully !\n\n";
            }
            else
            {
                cout << "\nSorry, seat is already booked, try other\n";
                book();
            }
        }
        else
        {
            cout << "enter another row and column\n";
            book();
        }
    }

    void cancel()
    {
        int row,col;
        cout << "\nEnter row no : ";
        cin >> row;
        cout << "Enter coulmn no : ";
        cin >> col;
        row--;
        col--;
        int i = 0;
        if (row <= 9 && col <= 7)
        {
            Node *temp = head[row];
            for (i = 0; i < col; i++)
            {
                temp = temp->next;
            }
            if (temp->status == true)
            {
                temp->status = false;
                cout << "\nSeat cancelled successfully !\n";
            }
            else
            {
                cout << "Sorry, this seat was not booked\n";
                cancel();
            }
        }
        else
        {
            cout << "enter another row and column\n";
            cancel();
        }
    }

    void available()
    {
        cout << "\n";
        int i = 0, j = 0, count = 0;
        for (i = 0, count = 1; i < 10; i++)
        {
            Node *temp = head[i];
            for (j = 0; j < 7; j++)
            {
                if (temp->status == 0)
                {
                    if (count / 10 == 0)
                    {
                        cout << "S0" << count << ": |A |  ";
                    }
                    else
                    {
                        cout << "S" << count << ": |A |  ";
                    }
                }
                else
                {
                    if (count / 10 == 0)
                    {
                        cout << "S0" << count << ": |NA|  ";
                    }
                    else
                    {
                        cout << "S" << count << ": |NA|  ";
                    }
                }
                temp = temp->next;
                count++;
            }
            cout << endl;
        }
    }

    void display()
    {
        cout << "\n---------------------------------------------------------------------\n";
        cout << "                         WELCOME TO CINEMAX                           \n";
        cout << "---------------------------------------------------------------------\n\n";
        int i = 0, j = 0, count = 0;
        for (i = 0, count = 1; i < 10; i++)
        {
            Node *temp = head[i];
            for (j = 0; j < 7; j++)
            {
                if (temp->status == 0)
                {
                    if (count / 10 == 0)
                    {
                        cout << "S0" << count << ": |_|  ";
                    }
                    else
                    {
                        cout << "S" << count << ": |_|  ";
                    }
                }
                else
                {
                    if (count / 10 == 0)
                    {
                        cout << "S0" << count << ": |B|  ";
                    }
                    else
                    {
                        cout << "S" << count << ": |B|  ";
                    }
                }
                temp = temp->next;
                count++;
            }
            cout << endl;
        }
    }
};

int main()
{
    Theatre obj;
    obj.prepareTheatre();
    obj.display();
    int choice = 1, row = 0, col = 0;
    while (choice != 4)
    {
        cout << "\n----------Menu----------\n";
        cout << "1) Book a seat \n2) Cancel a booked seat \n3) Available seats \n4) Exit\n\n";
        cout << "Enter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.book();
            obj.display();
            break;
        case 2:
            obj.cancel();
            obj.display();
            break;
        case 3:
            obj.available();
            break;
        case 4:
            cout << "Thank you !\n";
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
        cout << "\n";
    }
    return 0;
}
