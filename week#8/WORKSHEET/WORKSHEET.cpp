#include<iostream>

using namespace std;

struct list
{
    int info;
    list * link;
};


int main(void)
{
    list *head = new list;
    list *current, *temp, *last, *trail;
    
    // head->info = 75;
    // head ->link = new list;
    // head->link->info = 35;
    // head->link->link = new list;
    // head->link->link->info = 86;
    // head->link->link->link = new list;
    // head->link->link->link->info = 10;
    // head->link->link->link->link = new list;
    // head->link->link->link->link->info = 50;
    // head->link->link->link->link->link = new list;
    // head->link->link->link->link->link->info = 28;
    // head->link->link->link->link->link->link = new list;
    // head->link->link->link->link->link->link->info = 65;
    // head->link->link->link->link->link->link->link = new list;
    // head->link->link->link->link->link->link->link->info = 39;
    // head->link->link->link->link->link->link->link->link = NULL;

    // current = head;
    // temp = current->link->link;
    // trail = temp->link->link->link->link;
    // last = temp->link;
    

    list *node = new list;
    // node->info = 28;
    // trail = new list;
    // trail->info = 33;
    // trail->link = node;
    // node->link = NULL;
    // current = new list;
    // current->info = 62;
    // trail->link = current;
    // current->link = node;
    // node = trail;
    // current = node->link;
    // trail = current->link;
    // cout << node->info << " " << current->info << " " 
    // << trail->info << endl;

    current = new list;
    current->info = 72;
    current->link = NULL;
    trail = current;
    current = new list;
    current->info = 46;
    current->link = trail;
    node = current;
    current = new list;
    current->info = 52;
    node->link = current;
    current->link = trail;
    trail = current;
    current = new list;
    current->info = 91;
    current->link = trail->link;
    trail->link = current;
    current = node;
    while (current!= NULL)
    {
        cout << current->info << " ";
        current=current->link;
    }



    return 0;
}