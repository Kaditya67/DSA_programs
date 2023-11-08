#include<stdio.h>

int stack[20];
int top = -1;

// for eg. 24+

void push(int x) 
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}



void main()
{
    char exp[20];	// array
    char *e;  
    int ascii;
    int n1,n2,n3,num;
    
    printf("Enter the expression :: ");
    scanf("%s",exp);	// "24+"
    
    
    e = &exp[0];   // Address of Array of 1st element is being copied in e
    
    while(*e != '\0')	// checks for the end of expression
    {
	ascii = *e;	// ascii = value of 1st_element ....		// ascii = '2' -> 50  // ascii = '4' -> 52
	// char -> Int = ascii
	
        if(ascii>=48 && ascii<=57)
        {
            num = ascii - 48;	// 50 - 48 = 2 // 52-48 = 4
            push(num);	// push into the stack
        }
        else{
            n1 = pop();	// 1st Element
            n2 = pop();	// 2md Element
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);	// push into the stack
        }
        e++;	// address of 2nd element;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
}