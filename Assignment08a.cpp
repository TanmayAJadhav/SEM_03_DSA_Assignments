Write C++ program for storing appointment schedule for day. Appointments are booked randomly using linked list. Set start and end time and min and max duration for
visit slot. Write functions for
a) Display free slots
b) Book appointment
c) Cancel appointment (check validity, time bounds, availability)
d) Sort list based on time
e) Sort list based on time using pointer manipulation

#include <iostream>
#include <string>
using namespace std;

class Clinic;
class SinglyLL
{
private:
    int startTime;
    int endTime;
    int minTime;
    int maxTime;
    int bookStatus;
    SinglyLL *next;

public:
    SinglyLL()
    {
        startTime = 0;
        endTime = 0;
        minTime = 0;
        maxTime = 0;
        bookStatus = 0;
        next = NULL;
    }
    friend class Clinic;
};

class Clinic
{
private:
    SinglyLL *head;

public:
    Clinic()
    {
        head = NULL;
    }
    void setSchedule()
    {
        int n = 0;
        cout << "How many appointment slots are there ?\n";
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            SinglyLL *node = new SinglyLL();
            cout << "Enter Starting time (in 24 H format)\n";
            cin >> node->startTime;
            cout << "Enter Ending time (in 24 H format)\n";
            cin >> node->endTime;
            cout << "Enter Minimum Duration in mins: \n";
            cin >> node->minTime;
            cout << "Enter Maximum Duration in mins: \n";
            cin >> node->maxTime;

            node->next = NULL;
            if (head == NULL)
            {
                head = node;
            }
            else
            {
                SinglyLL *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = node;
            }
            cout << endl;
        }
    }

    void book()
    {
        int time;
        SinglyLL *temp = head;

        cout << "Enter starting time to book slot : \n";
        cin >> time;
        while (temp != NULL)
        {
            if (time == temp->startTime)
            {
                if (temp->bookStatus == 0)
                {
                    temp->bookStatus = 1;
                    cout << temp->startTime << " Appointment booked successfully !\n"
                         << temp->bookStatus << endl;
                    break;
                }
                else
                {
                    cout << "Sorry,appointment Slot is Booked ! \n";
                }
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Entered slot is not available in schedule\n";
        }
    }

    void cancel()
    {
        int time;
        SinglyLL *temp = head;

        cout << "Enter starting time to cancel slot : \n";
        cin >> time;
        while (temp != NULL)
        {
            if (time == temp->startTime)
            {
                if (temp->bookStatus == 1)
                {
                    temp->bookStatus = 0;
                    cout << "Your appointment Slot is cancelled successfully ! \n";
                }
                else
                {
                    cout << "This appointment was not Booked !\n";
                }
            }
            temp = temp->next;
        }
    }

    void sortbyTime()
    {
        SinglyLL *temp1 = head;
        SinglyLL *temp2 = head;
        int val = 0;
        bool val2 = 0;
        while (temp1 != NULL)
        {
            temp2 = head;
            while (temp2->next != NULL)
            {
                if (temp2->startTime > temp2->next->startTime)
                {
                    val = temp2->startTime;
                    temp2->startTime = temp2->next->startTime;
                    temp2->next->startTime = val;

                    val = temp2->endTime;
                    temp2->endTime = temp2->next->endTime;
                    temp2->next->endTime = val;

                    val = temp2->minTime;
                    temp2->minTime = temp2->next->minTime;
                    temp2->next->minTime = val;

                    val = temp2->maxTime;
                    temp2->maxTime = temp2->next->maxTime;
                    temp2->next->maxTime = val;

                    val2 = temp2->bookStatus;
                    temp2->bookStatus = temp2->next->bookStatus;
                    temp2->next->bookStatus = val2;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }

    void Display()
    {
        int AppointmentNo = 1;
        SinglyLL *temp = NULL;

        cout << "\n\n\t Appointment Schdule";
        cout << "\n\n\t Srno.\tStart\tEnd\tMin_Dur\tMax_Dur\tStatus";
        cout << "\n\t-------------------------------------------------";
        temp = head;
        while (temp != NULL)
        {
            cout << "\n\n\t " << AppointmentNo;
            cout << "\t " << temp->startTime;
            cout << "\t " << temp->endTime;
            cout << "\t " << temp->minTime;
            cout << "\t " << temp->maxTime;
            if (temp->bookStatus)
            {
                cout << "\tBooked";
            }
            else
            {
                cout << "\tFree";
            }
            AppointmentNo++;
            temp = temp->next;
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Clinic obj;
    int choice = 0;
    while (choice != 6)
    {
        cout << "---Menu----\n";
        cout << "1) Create Appointment schedule \n";
        cout << "2) Display Free Slot\n";
        cout << "3) Book an Appointment\n";
        cout << "4) Cancel an Appointment\n";
        cout << "5) Sort Slots based on Time\n";
        cout << "6) exit\n";
        cout << endl;
        cout << "Enter your choice\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.setSchedule();
            break;
        case 2:
            obj.Display();
            break;
        case 3:
            obj.book();
            break;
        case 4:
            obj.cancel();
            break;
        case 5:
            obj.sortbyTime();
            break;
        case 6:
            cout << "Thank you !\n";
            break;
        default:
            cout << "\nWrong Choice !\n";
            break;
        }
    }
    return 0;
}
