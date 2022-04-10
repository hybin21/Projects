#ifndef INTNODE_H
#define INTNODE_H

//Struct for int node
struct IntNode
{
    int data;           //IN - data of the node
    IntNode *next;      //IN - pointer to point the next node
    IntNode *prev;      //IN - pointer to point the previous node

    /****************
    ** CONSTRUCTOR **
    ****************/
    IntNode(int data) : data(data), next(0), prev(0) {}  //CALC - data 
                                                         //of the node 
};
#endif

/****************
** CONSTRUCTOR **
 ****************/   
/******************************************************************************
 * IntNode(int data)
 *  Constructor: initializes an empty list
 *-----------------------------------------------------------------------------
 *  Parameters: 
 *      int data: data of the node
 *-----------------------------------------------------------------------------
 *  Return: nothing
 *****************************************************************************/