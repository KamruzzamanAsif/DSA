#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>    // for gets()

using namespace std;
#define SIZE 100

string res;     // global declaration of resultant postfix string
char st[SIZE];  // stack
int top=-1;     // initializing top=-1 as array index starts from 0
double ev_st[SIZE]; // evaluation stack
int ev_top=-1;  // initializing ev_top=-1 as array index starts from 0


void push(char elem)
{                       // PUSH operation
    st[++top]=elem;
}

void ev_push(double item)  // push operation in evaluation stack
{
    ev_st[++ev_top] = item;
}

char pop()
{                      // POP operation
    return(st[top--]);
}

double ev_pop()  // pop operation in evaluation stack
{
    return(ev_st[ev_top--]);
}

int pr(char symbol)
{                 // Function for precedence

	if(symbol == '^') // exponent operator, highest precedence
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')   // lowest precedence
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(string ex)
{
    int i=0;
    char x;
    string  lstr;  // declaring a local string for calculation purpose

    for(i=0;i<ex.size();i++)
    {
        if( ex[i] == '(')
            push(ex[i]);
        else if(isalnum(ex[i]))   // isalnum() checks whether char is alphanumeric or not
        {
            while(isalnum(ex[i]) && i<ex.size())  // loop for numbers of more than one digit
            {
                lstr += ex[i];
                i++;
            }
            i--;
            res += lstr;
            res += " ";
            lstr.clear();
        }
        else if( ex[i] == ')')
        {
            while( st[top] != '(')
            {
                x = pop();
                res += x;
                res += " ";
            }
            x=pop(); // Remove '('
        }
        else if(ex[i]==' ')
            continue;
        else
        {           // Operator
            while( pr(st[top]) >= pr(ex[i]) )
            {
                x = pop();
                res += x;
                res += " ";
            }
            push(ex[i]);
        }
    }

    while( top >= 0)     // Pop from stack till empty
    {
        x = pop();
        res += x;
        res += " ";
    }

    // Printing Postfix expression
    cout<<"Postfix expression: ";
    for(int j=0;j<res.size();j++)
    {
        if(res[j]==' ' && j!= res.size()-1)
            cout<<", ";
        else
            cout<<res[j];
    }

}


double PostfixEvaluation()
{
    for(int i = 0;i< res.length();i++)
    {
		if(res[i] == ' ' || res[i] == ',')
		    continue;
		else if(res[i]=='+'||res[i]=='-'||res[i]=='*'||res[i]=='/')
        {
			// Pop two operands for calculation
			double v1 = ev_pop();
			double v2 = ev_pop();
			switch (res[i])
            {
                case '+': ev_push(v2 + v1); break;
                case '-': ev_push(v2 - v1); break;
                case '*': ev_push(v2 * v1); break;
                case '/': ev_push(v2 / v1); break;
            }
		}
		else if(isalnum(res[i]))
		{
			double operand = 0;
			while(i<res.length() && isalnum(res[i]))  // loop for numbers of more than one digit
            {
				operand = (operand*10) + (res[i] - '0');   // this converts the char to int value
				i++;
			}
			i--;
			ev_push(operand);
		}
	}

	return ev_pop(); // returning the resultant value stored lastly in evaluation stack
}


int main()
{
    char infix[SIZE];
    gets(infix);        // taking an infix arithmetic expression

    InfixToPostfix(infix);  // function calling to convert infix to postfix notation

    cout<<"\nValue: "<<PostfixEvaluation();   // printing the value of postfix expression

    return 0;
}









