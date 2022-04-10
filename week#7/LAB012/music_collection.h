/*******************************************************************************
 * AUTHOR            : Jessica Hahm, Vinny Nguyen
 * LAB 012           : music collection
 * CLASS             : CS3A
 * SECTION           : 32276
 * DUE DATE          : 02/24/22
*******************************************************************************/

#ifndef TUNE_H
#ifndef MUSIC_COLLECTION_H
#define TUNE_H
#define MUSIC_COLLECTION_H

#include <iostream>

using namespace std;

/******************************************************************************
 * Tune Class
 *  A class that stores the title of the song. It has two constructors and 
 *    one accessor.
 *
 *****************************************************************************/
class Tune
{
  private:
   string title;                      //The title of the Tune.

  public:

  /***************
  **CONSTRUCTORS**
  ***************/
   Tune();                            //Default constructor.
   Tune( const string &n );           //Constructor with one argument.

  /***************
  **  ACCESSOR  **
  ***************/
   const string & get_title() const;  //Accessor that retrieves the title.
};
#endif

//FUNCTION PROTOTYPES

/***************
**CONSTRUCTORS**
***************/

/*******************************************************************************
 * Tune(); 
 *  The default constructor of the Tune class. Sets the title equal to an empty
 *    string.
 *  - Returns:
 *      None, sets title equal to an empty string.
 *      
*******************************************************************************/

/*******************************************************************************
 * Tune(const string &n); 
 *  A constructor with one argument for the Tune class. Sets the title equal 
 *    to the parameter "n".
 *  - Returns:
 *      None, sets title equal to the parameter.
 *      
*******************************************************************************/

/***************
** ACCESSORS **
***************/

/*******************************************************************************
 * const string & get_title() const; 
 *  An accessor method that retrieves the title of the Tune. 
 *  - Returns:
 *      A string that represents the title of the Tune.
 *      
*******************************************************************************/








/******************************************************************************
 * Music_collection Class
 *  A class that represents a collection of music. Uses the Tune class. Uses
 *    a dynamic array to store values. It has 2 constructors, one destructor,
 *    2 mutators, and 3 overloaded functions.
 *
 *****************************************************************************/
class Music_collection
{
 private: 
   int number; // the number of tunes actually in the collection 
   int max;    // the number of tunes the collection will ever be able to hold 
   Tune *collection; // a dynamic array of Tunes: "Music_collection has-many Tunes"

 public:

  /***************
  **CONSTRUCTORS**
  ***************/
   // default value of max is a conservative 100
   Music_collection();     

   // sets max to n
   Music_collection( int n ); 

   // overloaded copy constructor
   Music_collection( const Music_collection &m);

  /**************
  **  ACESSOR  **
  ***************/
   // returns true if add was successful, 
   // returns false if not enough room to add
   bool add_tune( const Tune &t );

   // sets the Tune at position index in collection to t, 
   // returns true if index < number    
   bool set_tune( int index, const Tune &t );

   // overloaded assignment operator
   // make sure to deallocate the old memory before you allocate the new
   // memory
   // check for self-assignment a = a
   Music_collection & operator=( const Music_collection &m );

  // overloaded stream insertion operator
  // outputs the title of each Tune in the collection on a separate line
  friend ostream & operator<<( ostream &out, const Music_collection &m ); 

  /***************
  ** DESTRUCTOR **
  ***************/
   // Destructor
   ~Music_collection();
 
  
};

#endif

//FUNCTION PROTOTYPES

/***************
**CONSTRUCTORS**
***************/

/*******************************************************************************
 * Music_collection(); 
 *  The default constructor of the Music_collection class. Sets the number equal 
 *    to 0, the max equal to 100, and the collection pointer to a NULL pointer.
 *  - Returns:
 *      None, sets the private variables to their respective default values.
 *      
*******************************************************************************/

/*******************************************************************************
 * Music_collection(int n); 
 *  A constructor with one argument of the Music_collection class. Sets the 
 *    number equal to the parameter "n", the max equal to 100, and the collection 
 *    pointer to an array of Tune objects with a size of max.
 *  - Returns:
 *      None, sets the private variables and pointers to their respective values.
 *      
*******************************************************************************/

/*******************************************************************************
 * Music_collection(const Music_collection &m); 
 *  An overloaded copy constructor with one argument. Copies over the number,
 *    the max, and creates a new pointer for the new object of Tune objects with
 *    a size of max.
 *  - Returns:
 *      None, copies over the private variables and creates a new pointer.
 *      
*******************************************************************************/

/***************
**  MUTATORS **
***************/

/*******************************************************************************
 * bool add_tune(const Tune &t); 
 *  A mutator method that adds a new Tune to the collection. Only adds a new 
 *    Tune if the current number of Tunes is not greater than the max.
 *  - Returns:
 *      True if the Tune was added to the array, false if the number > max.
 *      
*******************************************************************************/

/*******************************************************************************
 * bool set_tune(int index, const Tune &t);
 *  A mutator method that sets a Tune to a different Tune in the collection. 
 *  - Returns:
 *      True if the Tune was set to the array, false if the index > max.
 *      
*******************************************************************************/

/*******************************************************************************
 * Music_collection & operator=( const Music_collection &m ); 
 *  An overloaded assignment operator, deallocates old memory before creating a
 *    new pointer to an array of Tune objects. Also checks for self-assignment.
 *  - Returns:
 *      None, assigns a Music_collection object the values of the object in the 
 *        parameter with a new pointer to a new array.
 *      
*******************************************************************************/

/*******************************************************************************
 * friend ostream & operator<<( ostream &out, const Music_collection &m ); 
 *  An overloaded extraction operator. Allows for the use of << to output a
 *    Music_collection object.
 *  - Returns:
 *      None, outputs the Music_collection object in the parameter to the
 *        ostream.
 *      
*******************************************************************************/

/***************
** DESTRUCTOR **
***************/

/*******************************************************************************
 * ~Music_collection();
 *  A destructor of the Music_collection
 *  - Returns:
 *      None
 *      
*******************************************************************************/
