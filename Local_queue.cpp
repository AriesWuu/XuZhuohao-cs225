//
// Created by Kejun Wu on 2022/4/8.
//

#include "Local_queue.h"

Local_queue::Local_queue() {
    q = new queue<Person_Node>;
    p = new queue<Person_Node>;
    return;
}

void Local_queue::deal(int date) //process and record the status, date, and time for all the patients in queue.
{
    if(this->q->size()<= 40){
        while(!this->q->empty()){
            Person_Node *A = new Person_Node;
            (*A)= q->front();
            q->pop();
            Person_Node *B;
            B=A;//copy A to B to store to database.
            p->push(*B);
        }
    }
    else{
        for(int i = 40; i < 40 ; i++){
            Person_Node *A = new Person_Node;
            (*A)= q->front();
            q->pop();
            Person_Node *B;
            B=A;//copy A to B to store to database.
            p->push(*B);
        }
        for(int j = 0; j < q->size(); j++){
            Person_Node *A = new Person_Node;
            (*A)= q->front();
            
            q->pop();
            q->push(*A);
            Person_Node *B;
            B= A;//copy A to B to store to database.
            p->push(*B);
        }
    }
    return;
}

// sorting according to age
void Local_queue::agesort()
{
    // get the length of the queue p
    int len=p->size();
    Person_Node a[len]; // use a[] to store reg node from the queue
    // char b[len];
    Person_Node *p1;
    Person_Node *p2;

    // store and pop every element from the queue
    for (int i = 0; i < len; i++)
    {
        a[i] = p->front();
        p->pop();
    }

    // use selection sort to sort based on the age
    for (int i =0; i < len; i++)
    {
        int max=i;
        for (int j=i+1; j< len; j++)
        {
            p1 = &a[max];
            p2 = &a[j];

            // if p1 larger than p2, swap them
            if (p1->age < p2->age)
            {
                max=j;
            }
        }
        Person_Node temp = a[i];
        a[i] = a[max];
        a[max] = temp;
    }
    for (int i=0; i< len; i++)
    {
        p->push(a[i]);
    }
    // return p;
}

queue<Person_Node>* Local_queue::get_p(void)
{
    return p;
}


queue<Person_Node>* Local_queue::get_q(void)
{
    return q;
}

