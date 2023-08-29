#include <stdio.h>
int MAXSIZE=8;
int stack[8];
int top=-1;
//check if the stack is empty
int isempty()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
//check if the stack is full
int isfull()
{
    if(top==MAXSIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//function to return the peek element
int peek()
{
    return stack[top];
}
//function to delete from the stack
int pop()
{
    int data;
    if(!isempty())
    {
        data=stack[top];
        top-=1;
        return data;
    }
    else
    {
        printf("could not retrieve the data,stack is empty.\n");
    }
    return 0;
}
//function to insert
int push(int data)
{
    if(!isfull())
    {
        top+=1;
        stack[top]=data;
    }
    else
    {
        printf("could not insert the data,stack is full\n");
    }
    return 0;
}
//main func
int main()
{
    push(44);
    push(10);
    push(62);
    push(123);
    push(15);
    printf("element at the top of the stack:%d\n",peek());
    printf("elements:\n");
    //print stack data
    while(!isempty())
    {
        int data=pop();
        printf("%d\n",data);
    }
    printf("stack full:%s\n",isfull()?"true":"false");
    printf("stack empty:%s\n",isempty()?"true":"false");
    return 0;
}
