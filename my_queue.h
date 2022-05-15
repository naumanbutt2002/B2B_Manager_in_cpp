#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
//FOR QUEUE
struct Node
{
    string q_cname,q_model;
    unsigned int q_amount,q_price;
    Node *link;
};
	//FOR QUEUE:-
Node *front = NULL;
Node *rear = NULL;

// Function to check if queue is empty or not
bool isempty()
{
    if (front == NULL && rear == NULL)
        return true;
    else
        return false;
}

// function to enter elements in queue
void enqueue(string qname, string qm, unsigned int qa, unsigned int qp)
{
    Node *ptr = new Node();
    ptr->q_cname = qname;
    ptr->q_model = qm;
    ptr->q_amount = qa;
    ptr->q_price = qp;
    ptr->link = NULL;

    // If inserting the first element/node
    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->link = ptr;
        rear = ptr;
    }
}

// function to delete/remove element from queue
// void dequeue()
// {
//     if (isempty())
//         cout << "Queue is empty\n";
//     else
//         // only one element/node in queue.
//         if (front == rear)
//         {
//             free(front);
//             front = rear = NULL;
//         }
//         else
//         {
//             Node *ptr = front;
//             front = front->link;
//             free(ptr);
        
//         }
// }

// function to show the element at front
void showfront()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
        {

            cout << "element at front is:-\n\n"<<"NAME\tMODEL\tAMOUNT\tPRICE\n"
            << front->q_cname <<front->q_model <<front->q_amount <<front->q_price << "\n";
        }
        
}

// function to display queue
void displayQueue()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
    {
        Node *ptr = front;
        while (ptr != NULL)
        {
            cout <<"NAME\t\tMODEL\t\tAMOUNT\tPRICE\n"
            << front->q_cname <<"\t\t"<<front->q_model <<"\t"<<front->q_amount<<"\t" <<front->q_price << "\n";  
                      ptr = ptr->link;
        }
    }
}