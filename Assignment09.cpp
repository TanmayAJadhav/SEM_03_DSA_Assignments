// In any language program mostly syntax error occurs due to unbalancing delimiter such as ), }, [].
// Write C++ program using stack to check whether given expression is well parenthesized or not.

#include <iostream>
#include <string>
using namespace std;

class Node
{
    char data;
    Node *next;

public:
    Node()
    {
        data = '\0';
        next = NULL;
    }
    friend class Stack;
};
class Stack
{
    Node *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(char element)
    {
        Node *newn = new Node();
        newn->data = element;
        if (top == NULL)
        {
            top = newn;
        }
        else
        {
            newn->next = top;
            top = newn;
        }
        size++;
    }

    void display()
    {
        if (isEmpty() == true)
        {
            cout << "Stack is Empty !" << endl;
            return;
        }
        Node *temp = top;
        while (temp != NULL)
        {
            cout << "|" << temp->data << "|"
                 << "\n";
            temp = temp->next;
        }
        cout << endl;
    }

    void pop()
    {
        if (isEmpty() == true)
        {
            cout << "Stack is Empty !" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    char Top()
    {
        if (isEmpty() == true)
        {
            cout << "Stack is Empty !" << endl;
            return '0';
        }
        return top->data;
    }

    bool isWellParenthesized(string exp)
    {
        Stack obj;
        int len = exp.length();
        char ch;

        for (int i = 0; i < len; i++)
        {
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            {
                obj.push(exp[i]);
                continue;
            }

            if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if (obj.isEmpty()) // right side's paranthesis are greater than left side's paranthesis
                {
                    return false;
                }
                else
                {
                    switch (exp[i])
                    {
                    case ')':
                        ch = obj.Top();
                        obj.pop();
                        if (ch == '{' || ch == '[')
                        {
                            return false;
                        }
                        break;
                    case '}':
                        ch = obj.Top();
                        obj.pop();
                        if (ch == '(' || ch == '[')
                        {
                            return false;
                        }
                        break;
                    case ']':
                        ch = obj.Top();
                        obj.pop();
                        if (ch == '(' || ch == '{')
                        {
                            return false;
                        }
                        break;

                    default:
                        break;
                    }
                }
            }
        }
        if (obj.isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack obj;
    string str;
    cout << "Enter the expression : " << endl;
    cin >> str;
    bool ans = obj.isWellParenthesized(str);
    if (ans == true)
    {
        cout << str << " The given expression is well parenthesized ! " << endl;
    }
    else
    {
        cout << str << " The given expression is not well parenthesized !" << endl;
    }

    return 0;
}
