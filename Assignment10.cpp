// Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions: 
// 1. Operands and operator, both must be single character.
// 2. Input Postfix expression must be in a desired format.
// 3. Only '+', '-', '*' and '/' operators are expected.

#include <iostream>
using namespace std;

template <class T>
class Stack;
template <class T>
class Node
{
    T data;
    Node<T> *next;

public:
    Node()
    {
        next = NULL;
    }
    friend class Stack<T>;
};

template <class T>
class Stack
{
    Node<T> *top;

public:
    Stack();
    bool isEmpty();
    void push(T ele);
    void pop();
    void display();
    T Top();
};

template <class T>
Stack<T>::Stack()
{
    top = NULL;
}

template <class T>
void Stack<T>::push(T element)
{
    Node<T> *newn = new Node<T>;
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
}

template <class T>
bool Stack<T>::isEmpty()
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

template <class T>
void Stack<T>::pop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty !" << endl;
        return;
    }
    else
    {
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }
}

template <class T>
void Stack<T>::display()
{
    Node<T> *temp = top;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|"
             << "\n";
        temp = temp->next;
    }
    if (top == NULL)
    {
        cout << "NULLLLL" << endl;
    }
}

template <class T>
T Stack<T>::Top()
{
    return top->data;
}

class Infix_Postfix
{
public:
    int precidance(char ch)
    {
        if (ch == '*' || ch == '/')
        {
            return 2;
        }
        else if (ch == '+' || ch == '-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    bool isWellParenthesized(string exp)
    {
        Stack<char> obj;
        int len = exp.length();
        char ch = '\0';
        bool flag = false;
        for (int i = 0; i < len; i++)
        {
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            {
                obj.push(exp[i]);
                continue;
            }

            if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if (obj.isEmpty())
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
            flag = true;
        }
        else
        {
            flag = false;
        }

        return flag;
    }

    string infixToPostfix(string exp)
    {
        Stack<char> st;
        string result;
        bool flag = isWellParenthesized(exp);

        if (!flag)
        {
            return " ";
        }

        for (int i = 0; i < exp.length(); i++)
        {
            char c = exp[i];
            //(a-b/c)*(a/k-l)           
            //result    ab-/ 
            //stack     
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                result += c;

            else if (c == '(')
                st.push('(');

            else if (c == ')')
            {
                while (st.Top() != '(')
                {
                    result += st.Top();
                    st.pop();
                }
                st.pop();
            }

            else
            {                       //                  2                       -1
                while (st.isEmpty() == false  && precidance(exp[i]) <= precidance(st.Top()))
                {
                    result += st.Top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.isEmpty())
        {
            result += st.Top();
            st.pop();
        }

        return result;
    }

    int EvaluatePostFix(string exp)
    {
        Stack<int> st;
        string poststr = infixToPostfix(exp);

        for (int i = 0; i < poststr.length(); i++)
        {
            if (poststr[i] >= '0' && poststr[i] <= '9')
            {
                st.push(poststr[i] - '0');
            }
            else
            {
                int opt2 = st.Top();
                st.pop();
                int opt1 = st.Top();
                st.pop();

                switch (poststr[i])
                {
                case '*':
                    st.push(opt1 * opt2);
                    break;
                case '/':
                    st.push(opt1 / opt2);
                    break;
                case '+':
                    st.push(opt1 + opt2);
                    break;
                case '-':
                    st.push(opt1 - opt2);
                    break;
                }
            }
        }
        return st.Top();
    }
};

int main()
{
    Infix_Postfix obj;
    string str, anotherstring;
    cout << "Enter expression : \n";
    cin >> str;
    bool flag = false;
    int ret = 0;
    int choice = 0;

    while (choice != 4)
    {
        cout << "--------Menu--------\n";
        cout << "1) Convert infix to postfix \n";
        cout << "2) Converting infix to postfix and its evaluation \n";
        cout << "3) Enter another expression\n";
        cout << "4) Exit \n";
        cout << "Enter choice \n";
        cin >> choice;

        flag = obj.isWellParenthesized(str);

        if (flag == true)
        {
            switch (choice)
            {
            case 1:
                cout << "Infix to postfix conversion : \n";
                cout << obj.infixToPostfix(str) << endl;
                break;

            case 2:
                cout << "Evaluation of Infix to postfix expression is : \n";
                cout << obj.EvaluatePostFix(str) << endl;
                break;

            case 3:
                cout << "Enter expression \n";
                cin >> anotherstring;
                str = anotherstring;
                break;

            case 4:
                cout << "Thank you !\n";
                break;

            default:
                cout << "Choose frome 1 to 3\n";
                break;
            }
        }
        else
        {
            cout << "expression is not  well paranthesized";
        }
        cout << endl;
    }

    return 0;
}
