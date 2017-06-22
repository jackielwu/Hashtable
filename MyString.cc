
// CS251 Data Structures
// String Implementation
// IMPORTANT: Do not use any of the functions in the string C runtime library
// Example. Do not use strcpy, strcmp, etc. Implement your own

// IMPORTANT: See the MyString.h file for a description of
// what each method needs to do.

#include <stdio.h>
#include "MyString.h"

// My own implementation of strlen
int
MyString::slength(const char *s) const
{
	int l = 0;
	while(s[l] != '\0')
	{
		s[l];
		l++;
	}
  return l;
}

// Initialize _s. Allocate memory for _s and copy s into _s
void
MyString::initialize(const char * s)
{
  // Add implementation here
  // Allocate memory for _s.
	_s = new char[slength(s)+1];
  // Copy s into _s
	int i = 0;
	while(s[i] != '\0')
	{
		_s[i] = s[i];
		i++;
	}
	_s[i+1] = '\0';
}

// Create a MyString from a C string
MyString::MyString(const char * s)
{
  initialize(s);
}

// Create a MyString from a copy of another string
MyString::MyString(const MyString &s)
{
  initialize(s._s);
}

// Create a MyString with an empty string
MyString::MyString()
{
  _s = new char[1];
  *_s = 0;
}

// Assignment operator. Without this operator the assignment is
// just a shallow copy that will copy the pointer _s. If the original _s
// goes away then the assigned _s will be a dangling reference.
MyString &
MyString::operator = (const MyString & other) {
  if (this != &other) // protect against invalid self-assignment
  {
    // deallocate old memory
    delete [] _s;

    // Initialize _s with the "other" object.
    initialize(other._s);

    // by convention, always return *this
    return *this;
  }
}

// Obtain a substring of at most n chars starting at location i
// if i is larger than the length of the string return an empty string.
MyString
MyString::substring(int i, int n)
{
  // Add implementation here

  // Make sure that i is not beyond the end of string

  // Allocate memory for substring

  // Copy characters of substring
  MyString sub;

  // Return substring
  return sub;
}

// Remove at most n chars starting at location i
void
MyString::remove(int i, int n)
{
  // Add implementation here

  // If i is beyond the end of string return

  // If i+n is beyond the end trunc string

  // Remove characters
}

// Return true if strings "this" and s are equal
bool
MyString::operator == (const MyString & s)
{
  // Add implementation here
  return false;
}


// Return true if strings "this" and s are not equal
bool
MyString::operator != (const MyString &s)
{
  // Add implementation here
  return false;
}

// Return true if string "this" and s is less or equal
bool
MyString::operator <= (const MyString &s)
{
  // Add implementation here
  return false;
}

// Return true if string "this" is greater than s
bool
MyString::operator > (const MyString &s)
{
  // Add implementation here
  return false;
}

// Return character at position i.  Return '\0' if out of bounds.
char
MyString::operator [] (int i)
{
  // Add implementation here
  return ' ';
}

// Return C representation of string
const char *
MyString::cStr()
{
  // Add implementation here
	const char* s = _s;
  return s;
}

// Get string length of this string.
int
MyString::length() const
{
  // Add implementation here
  return slength(_s);
}

// Destructor. Deallocate the space used by _s
MyString::~MyString()
{
  // Add implementation here
  delete [] _s;
}

// Concatanate two strings (non member method)
MyString operator + (const MyString &s1, const MyString &s2)
{
  // Add implementation here

  // Allocate memory for the concatenated string

  // Add s1

  // Add s2

  MyString s;
  return s;
}

