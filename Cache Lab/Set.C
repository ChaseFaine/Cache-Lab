#include <iostream>
#include <string>
#include <assert.h>
#include "Set.h"

//TO DO: lots of work to do in this file. 
//       Look for TO DO throughout the file

/*
 * Set
 * Constructor required by compiler
 */
Set::Set() 
{
   
}

/*
 * initialize
 * Initialize the Set object by creating an array 
 * of Lines.  The tag field of each line needs to be set to 0.
 * The valid field of each line needs to be set to false.
 */
void Set::initialize(int32_t associativity)
{

   //TO DO 
   this->associativity = associativity;
   lines = new Line[associativity];
   for(int i = 0; i < associativity; i++) {
      lines[i].tag = 0;
      lines[i].valid = false;
   }
   firstAccess = true;
}

/*
 * isHit
 * Looks in the Set for the tag. Returns true if found and false otherwise.
 */
bool Set::isHit(int64_t tag)
{

   //TO DO
   for(int i = 0; i < associativity; i++) {
      if(lines[i].tag == tag) {
         if(tag == 0 && firstAccess == true)
            return false;
         return true;
      }
   }
   return false;
}

/*
 * isFull
 * Returns true if every valid field in the Set is true. This is used
 * to determine whether an eviction will occur.
 */
bool Set::isFull()
{
   //TO DO
   for(int i = 0; i < associativity; i++) {
      if(lines[i].valid == false) {
         return false;
      }
   }   
   return true;
}

/*
 * update
 * Updates the Set with the provided tag.
 * The tags in the Set need to be kept in LRU
 * order so that the MRU is in the front.
 * (You could get it to work the other direction too, 
 * but this direction is easier.)
 * 
 * Suppose tag is T and associativity is 4.
 * If the tags in the Set are: A B C D
 * then after the update, the tags are: T A B C
 *
 * If the tags in the Set are: T A B D
 * then after the update, the tags are: T A B D
 *
 * If the tags in the Set are: A B - -
 * (where - indicates invalid is false)
 * then after the update, the tags are: T A B -
 * 
 */
void Set::update(int64_t tag)
{
   //TO DO
   if(tag == 0 && firstAccess == true) {
      //if the tag is 0 and its the first access to the cache set.
      firstAccess = false;
   }
   int inSet = getLineNumber(tag);
   if(inSet == -1) {
      for(int i = associativity-1; i > 0; i--) {
         lines[i] = lines[i-1];
      }
      lines[0].tag = tag;
      lines[0].valid = true;
   } else {
      for(int i = inSet; i > 0; i--) {
         lines[i] = lines[i-1];
      }
      lines[0].tag = tag;
      lines[0].valid = true;
   }
}
/*
 * getLineNumber
 * Returns the line index in the lines array
 * of the line that contains the tag (tag matches
 * and valid is true). Returns -1 if not in Set.
 */
int32_t Set::getLineNumber(int64_t tag)
{
   //TO DO
   if (isHit(tag)) {
      for (int i = 0; i < associativity; i++) {
         if (lines[i].tag == tag) {
            return i;
         }
      }
   }
   return -1;
}

/*
 * Destructor for the dynamically allocated data.
 */
Set::~Set()
{
   //TO DO
   delete [] lines;
}

/*
 * print
 * Prints the contents of the Set. This is called
 * by the print method in the Cache class.
 */
void Set::print()
{
   int32_t i, j;
   bool printSet;
   printSet = false;
   for (j = 0; j < associativity; j++)
      if (lines[j].valid == true) printSet = true;
   if (printSet)
   {
      std::cout << "\nSet: " << i << " ";
      for (j = 0; j < associativity; j++)
      {
         std::cout << std::hex << lines[j].tag << "," << lines[j].valid << " ";
      }
   }
}

