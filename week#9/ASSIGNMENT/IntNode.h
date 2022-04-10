#ifndef INTNODE_H
#define INTNODE_H

// structure for int node
struct IntNode
{
    int data;   // IN - data of the node
    IntNode *next;  // IN - pointer to point the next node

    /****************
    ** CONSTRUCTOR **
    ****************/
    IntNode(int data) : data(data), next(0) {}  // data of the node 
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