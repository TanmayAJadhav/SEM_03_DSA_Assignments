// Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like butterscotch ice-cream.
// Write C++ program to store two sets using linked list. compute and display a) Set of students who like both vanilla and butterscotch
// b) Set of students who like either vanilla or butterscotch or not both
// c) Number of students who like neither vanilla nor butterscotch

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    Student *next;

public:
    Student()
    {
        name = " ";
        next = NULL;
    }

    Student(string name)
    {
        this->name = name;
        next = NULL;
    }

    friend class Set;
};

class Set
{
private:
    Student *head = NULL;

public:
    Set()
    {
        head = NULL;
    }

    void insertStudent(string name)
    {
        Student *stud = new Student(name);
        if (head == NULL)
        {
            head = stud;
        }
        else
        {
            stud->next = head;
            head = stud;
        }
    }

    Set *intersection(Set *head1)
    {
        Student *temp1 = head;
        Student *temp2 = NULL;
        Set *temp3 = new Set;
        while (temp1 != NULL)
        {
            temp2 = head1->head;
            while (temp2 != NULL)
            {
                if (temp1->name == temp2->name)
                {
                    temp3->insertStudent(temp1->name);
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return temp3;
    }

    Set *unionS(Set *head1)
    {
        Student *temp1 = head;
        Student *temp2 = head1->head;
        Set *temp3 = new Set;
        while (temp1 != NULL)
        {
            temp3->insertStudent(temp1->name);
            temp1 = temp1->next;
        }

        while (temp2 != NULL)
        {
            bool flag = false;
            temp1 = head;
            while (temp1 != NULL)
            {
                if (temp1->name == temp2->name)
                {
                    flag = true;
                    break;
                }
                temp1 = temp1->next;
            }
            if (flag == false)
            {
                temp3->insertStudent(temp2->name);
            }
            temp2 = temp2->next;
        }
        return temp3;
    }

    Set *onlyFlav(Set *head1)
    {
        Student *temp1 = this->head;
        Student *temp2 = NULL;
        Set *temp3 = new Set;
        while (temp1 != NULL)
        {
            temp2 = head1->head;
            bool flag = false;
            while (temp2 != NULL)
            {
                if (temp1->name == temp2->name)
                {
                    flag = true;
                    break;
                }
                temp2 = temp2->next;
            }
            if (flag == false)
            {
                temp3->insertStudent(temp1->name);
            }
            temp1 = temp1->next;
        }
        return temp3;
    }

    void display()
    {
        Student *temp = head;
        cout << endl;
        while (temp != NULL)
        {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Set *Van = NULL, *Bsc = NULL, *None = NULL, *totalStudents = NULL, *ret = NULL;
    Van = new Set;
    Bsc = new Set;
    None = new Set;
    totalStudents = new Set;

    string s;
    int n, choice, flav;

    while (choice != 9)
    {
        cout << "\n--------Second Year Students--------\n";
        cout << "1)Add student \n"
             << "2)Students who like only Vannila \n"
             << "3)Students who like only Butterscotch \n"
             << "4)Students who like both Vanilla and Butterscotch \n"
             << "5)Students who like only Vannila and Butterscotch\n"
             << "6)Student who like none of flavour\n"
             << "7)Display students\n"
             << "8)Student who like Vannila and Butterscotch (Union)\n"
             << "9)Exit"
             << endl;
        cout << "Enter your choice\n";
        cin >> choice;
        

        switch (choice)
        {
        case 1:
            cout << "\nEnter the name of student : ";
            cin >> s;
            cout << "\nEnter the flavour liked:\n1)Vannila\n2)Butterscotch\n3)Both\n4)None\n";
            cout<<"Enter favourite flavour\n";
            cin >> flav;

            switch (flav)
            {
            case 1:
                Van->insertStudent(s);
                break;
            case 2:
                Bsc->insertStudent(s);
                break;
            case 3:
                Van->insertStudent(s);
                Bsc->insertStudent(s);
                break;
            case 4:
                None->insertStudent(s);
                break;
            default:
                cout << "Wrong option\n";
            }
            if (flav >= 1 && flav <= 4)
            {
                totalStudents->insertStudent(s);
            }
            break;
        case 2:
            cout << "Students who like Vannila : \n";
            ret = Van->onlyFlav(Bsc);
            ret->display();
            break;
        case 3:
            cout << "Students who like Butterscotch : \n";
            ret = Bsc->onlyFlav(Van);
            ret->display();
            break;
        case 4:
            cout << "Students who like both Vanilla and Butterscotch : \n";
            ret = Van->intersection(Bsc); 
            ret->display();
            break;
        case 5:
            cout << "Students who like only Vannila and Butterscotch\n";
            ret = Van->onlyFlav(Bsc);
            ret->display();
            ret = Bsc->onlyFlav(Van);
            ret->display();
            break;
        case 6:
            cout << "Students who like none of flavour : \n";
            None->display();
            break;
        case 7:
            cout << "Name of all students : \n";
            totalStudents->display();
            break;
        case 8:
            ret = Van->unionS(Bsc);
            cout<<"Student who like Vannila and Butterscotch (Union) : \n";
            ret->display(); 
            break;   
        case 9:
            cout << "Thank you !\n";
            break;
        default:
            break;
        }
    }
    return 0;
}
