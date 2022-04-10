/*******************************************************************************
 * AUTHOR            : Jessica Hahm, Vinny Nguyen
 * LAB 012           : music collection
 * CLASS             : CS3A
 * SECTION           : 32276
 * DUE DATE          : 02/24/22
*******************************************************************************/

#include "music_collection.h"
using namespace std;
/****************
** CONSTRUCTOR ** 
*****************/


/*****************************************************************************
* Tune();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none 
*****************************************************************************/
Tune::Tune()
{
  title = "";
}

/*****************************************************************************
* Tune(const string &n)
*   Constructor; Initialize class attributes
*   Parameters: 
        const string &n: title of the tue
*   Return: none 
*****************************************************************************/
Tune::Tune(const string &n) // IN - title of the tune
{
  title = n;
}

/***************
** ACCESSORS **
***************/

/*****************************************************************************
 * Method get_title():  Class Tune
 * 
 * ---------------------------------------------------------------------------
 * This method returns the title of the tune
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      the tune should be initialized
 *    
 * POST-CONDITIONç
 *   This function returns the title of the tune
 * 
 *****************************************************************************/
const string & Tune::get_title() const
{
  return title;
}

/****************
** CONSTRUCTOR ** 
*****************/

/*****************************************************************************
* Music_collection();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none 
*****************************************************************************/
Music_collection::Music_collection()
{
  number = 0;
  max = 100;
  collection = new Tune[max];
}

/*****************************************************************************
* Music_collection(int n)
*   Constructor; Initialize class attributes
*   Parameters: 
*       int n: number of the tune to be stored in the collection
*   Return: none 
*****************************************************************************/
Music_collection::Music_collection(int n)   // IN - number of the tune 
{
  number = n;
  max = 100;
  collection = new Tune[max];
}

/*****************************************************************************
* Music_collection(const Music_collection &m)
*   Constructor; Initialize class attributes
*   Parameters: 
*       const Music_collection &m: music collection to be copied
*   Return: none 
*****************************************************************************/
Music_collection::Music_collection(const Music_collection &m)
{
  this->number = m.number;
  this->max = m.max;
  collection = new Tune[this->max];
  for(int i = 0; i < this->number; i++)
    this->collection[i] = m.collection[i];
}

/****************
**   MUTATOR   ** 
*****************/


/*****************************************************************************
 * Method Music_collection::add_tune(const Tune &t):  Class Music_collection
 * 
 * ---------------------------------------------------------------------------
 * This method adds tune to the collection
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const Tune &t: tune to be added to collection
 *    
 * POST-CONDITIONç
 *   collection will have new tune to 
 * 
 *****************************************************************************/
bool Music_collection::add_tune(const Tune &t)
{
    // when the size of the collection is not enough
  if(this->number + 1 > max)
    return false;
  else 
    this->collection[number] = t;
  number++;
  return true;
}

/*****************************************************************************
 * Method Music_collection::set_tune(int index, const Tune &t): Class Tune
 * 
 * ---------------------------------------------------------------------------
 * This method set the tune of the collection
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      int index: index to be inserted
 *      const Tune &t:  tune to be inserted to the index of the collection
 *    
 * POST-CONDITIONç
 *   The collection will have new tune for the index space
 * 
 *****************************************************************************/
bool Music_collection::set_tune(int index,  // IN - index it be inserted
                            const Tune &t)  // IN - tune to be inserted
{  
  if(index < number)
  {
    this->collection[index] = t;
    return true;
  }
  return false;
}

/*****************************************************************************
 * Method operator=(const Music_collection &m):  Class Tune
 * 
 * ---------------------------------------------------------------------------
 * This method overrides operator =
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const Music_collection &m: collection to be overriden
 *    
 * POST-CONDITIONç
 *   The vector will have new value for the index
 * 
 *****************************************************************************/
Music_collection & Music_collection::operator=
            (const Music_collection &m)  // IN - collection to be overriden
{
  //Must check for self assignment, "a = a";
    if(this->collection != m.collection)
    {
        int new_number;
        int new_max;
        this->number = m.number;
        this->max = m.max;
        if (this->number) 
        { 
            delete [] this->collection; 
            this->collection = new Tune[max];
            for(int i = 0; i < this->number; i++)
                set_tune(i,m.collection[i]);
        } 
    return *this;
  }
  return *this;
}

/*****************************************************************************
 * Method operator<<(ostream &out, const Music_collection &m): Class Tune
 * 
 * ---------------------------------------------------------------------------
 * This method overrides operator <<
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      ostream &out: output stream
 *      const Music_collection &m: music collection to be displayed
 *    
 * POST-CONDITIONç
 *   The collection is displayed
 * 
 *****************************************************************************/
ostream & operator<<(ostream &out,  // IN - output stream
         const Music_collection &m)     // IN - collection to be displayed
{
  for(int i = 0; i < m.number; i++)
    out << m.collection[i].get_title() << endl;
  return out;
}

/*****************
**  DESTRUCTOR  ** 
******************/

/*****************************************************************************
* ~Music_collection()
*   desctructor; deallocate the memory of the Music_collection
*   Parameters: none
*   Return: none 
*****************************************************************************/
Music_collection::~Music_collection()
{
  delete []collection;
}

