#include <iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<sstream>
#include <stack>


#define MAX_LEN 200


using namespace std;

stack<char> myinfix;
stack<char> mypostfix;

int is_operator(char symbol);
int precedence(char symbol);
string InfixToPostfix(char inputChar[]);
int EvalPostfix( string inputStr);

int main()
{
    char infix[MAX_LEN], playagain[10];
    string postFix_str = "";
    cout<<"\t========================================================================="<<endl;
    cout<<"\t======================  Task 2  ========================================="<<endl;
    cout<<"\t========================================================================="<<endl;

    do {
    cout<<endl<<endl;
    cout<<"\n\tEnter Infix expression : ";
    gets(infix);


    cout<<endl<<endl;
    postFix_str = InfixToPostfix(infix);
    cout<<"\tPostfix Expression:  "<<postFix_str;

    cout<<endl<<endl;
    cout<<"\tEvalution of Postfix Expression Result :  ";
    cout<< EvalPostfix(postFix_str);

    cout<<endl<<endl;
    cout<<" Do you want to computer other statement? Press y for YES :\t";
    gets(playagain);
    }
    while(playagain[0] == 'y' || playagain[0] == 'Y');
    cout<<endl<<endl;

    cout<<endl<<endl<<endl;
    cout<<"\t========================================================================="<<endl;
    cout<<"\t======================  The END  ========================================"<<endl;
    cout<<"\t========================================================================="<<endl;
    cout<<endl<<endl<<endl;
    return 0;
}

int EvalPostfix(string inputStr)
{
    //cout<<endl<<endl<<" input string is : "<<inputStr<<endl<<endl;
    int n = inputStr.length();
    char postfix[n + 1];
    strcpy(postfix, inputStr.c_str());


    int i;
    char ch;
    int val;
    int A, B;
    string dd;
    stringstream ss;

    string::size_type siz;


    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            mypostfix.push(ch - '0');
        }
        else if (isalpha(ch)) {
            return -1;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

            while((' ' == mypostfix.top()) && (mypostfix.size() > 0))
            {
                mypostfix.pop();
            }
            ss.str("");
            while ((' ' != mypostfix.top()) && (mypostfix.size() > 0)) {
                ss.str(to_string(mypostfix.top()));
                mypostfix.pop();
            }

            ss>>dd;
            A = stoi(dd, &siz, 10);
            ss.clear();
            while((' ' == mypostfix.top()) && (mypostfix.size() > 0))
            {
                mypostfix.pop();
            }
            while ((' ' != mypostfix.top()) && (mypostfix.size() > 0)) {
                ss.str(to_string(mypostfix.top()));
                mypostfix.pop();
                if(mypostfix.size() <= 0)
                {
                    break;
                }
            }
            dd = "";
            ss>>dd;
            B = stoi(dd, &siz, 10);
            ss.clear();

            switch (ch) /* ch is an operator */
            {

            case '^':
                val = B * A;
                break;

            case '*':
                val = B * A;
                break;
            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            //cout<<endl<<endl<<" first Number : "<<A<<" and second : "<<B<<" so result is : "<<val;
            mypostfix.push(val);
        }
        else if(ch == ' ')
        {
            mypostfix.push(' ');
        }
    } // end of for loop

    return val;

}




string InfixToPostfix(char inputChar[])
{
    char output[MAX_LEN];

    int i, j;
    char item;
    char x;

    myinfix.push('(');
    strcat(inputChar,")");

    i = 0;
    j = 0;
    item = inputChar[i];

    while(item != '\0')
    {
        if(item == '(')
        {
            myinfix.push(item);
        }
        else if( isdigit(item) || isalpha(item))
        {
            output[j] = item;
            j++;
        }
        else if(is_operator(item) == 1)
        {
            x = myinfix.top();
            myinfix.pop();

            while(is_operator(x) == 1 && precedence(x)>= precedence(item))
            {
                output[j] = x;
                j++;
                x = myinfix.top();
                myinfix.pop();
            }
            myinfix.push(x);
            output[j] = ' ';
            j++;
            myinfix.push(item);
        }
        else if(item == ')')
        {
            x =  myinfix.top();
            myinfix.pop();
            while(x != '(')
            {
                output[j] = ' ';
                j++;
                output[j] = x;
                j++;
                output[j] = ' ';
                j++;
                x =  myinfix.top();
                myinfix.pop();
            } // end of while loop
        }
        else if( item == ' ')
        {
            output[j] = ' ';
            j++;
        }
        else
        {
            printf("\nInvalid Expression.\n");
            getchar();
            exit(1);
        }
        i++;
        item = inputChar[i];
    } // while loop ends here

    if(myinfix.size() > 0)
    {
        printf("\n Invalid infix Expression.\n");
        getchar();
        exit(1);
    }
    output[j] = '\0';
    return (string) output;
}














int precedence(char symbol)
{
    if(symbol == '^') // exponent or Power
    {
        return(3);
    }
    else if(symbol == '*' || symbol == '/')
    {
        return(2);
    }
    else if(symbol == '+' || symbol == '-')
    {
        return(1);
    }
    else
    {
        return(0);
    }
} // end of precedence methodd

int is_operator(char symbol)
{
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
} // end of is_operator method

