// C++ program to validate user input

#include <iostream>
#include <string>								// header file for strings

using namespace std;

#define NEWLINE '\n'

  class Usr_In									// Definition of class Usr_In
   {
    private:
     int m_nr = 1 ;								// Member variable
     int m_st = 1 ;								// Member variable
     char m_ch[3] {'a','b','c'} ;				// Member array of type char

   public:
     Usr_In ()									// Default constructor of class C_Staff
       {  cout << "  Class Usr_In initialized with default constructor " << m_nr << ", " << m_st << '\n' ; } 
     											// Constructor of class C_Staff with 2 parameters
     Usr_In ( int nr, int st ) : m_nr{ nr }, m_st{ st }
       {  cout << "  Class Usr_In initialized with user provided values " << m_nr << ", " << m_st ; } 

     static bool y_n_char ( char c )			// Definition of bool function to validate user input (y or n)
	 { return ( c == 'y' || c == 'n' ) ; }

     static bool int_char ( char c  )			// Definition of bool function to validate user input (pos integer)
	 { return ( c >= '0' && c <= '9' ) ; }

	 static bool any_inp ( const string& s, bool (*fnPtr)(char))
		{ for ( char chr : s )
		  { if (!fnPtr ( chr ) )
			{ return false ; }}
			  return !s.empty() ; }

												// Prototype of member functions to validate user input
	void check_string2 (string& st, int m, bool((*fnPt)(const string&, bool (*fPtr)(char))), bool (*fnPtr)(char)) ;

   } ;	

 // --------------------------------------------------------------

 int main ()
  {
   int a {1} ;
   string my_str {} ;									// String variables; Direct initiated

   cout << '\n' ;
   Usr_In Inp_1 {} ;									// Object Inp_1 created, default constructor
   Usr_In Inp_2 (2, 3) ;								// Object Inp_2 created, constructor with parameters  
   
   cout << '\n' ;
   cout << "  This Program validates user input. " << '\n' ;  cout << '\n' ;
   cout << "  Proceed with this Program (y/n) ? "  << '\n' ;

   Inp_2.check_string2 ( my_str, 1, &Inp_2.any_inp, &Inp_2.y_n_char ) ;	// Call function "check_string2"
   cout << "  You entered: " << my_str << '\n' ;
   cout << "  Please enter pos int -> " ;

   Inp_2.check_string2 ( my_str, 3, &Inp_2.any_inp, &Inp_2.int_char ) ;	// Call function "check_string2"
   cout << "  You entered: " << my_str << '\n' ;
   cout << '\n' ;

  return 0 ;
  }

 // --------------------------------------------------------------

	void Usr_In::check_string2 (string& str, int m, bool((*fnPt)(const string&, bool (*fPtr)(char))), bool (*fnPtr)(char))
	  { char chr {} ;
		bool valid{};
		do { valid = false ;							// Do-While loop until input by user is correct
			 cout << " Your input (max " << m << " digit(s)): " ;
			 cin >> str ;
			 if ( str.size() > m ) { valid = false ; }	// Count chars / digits are entered by user
			 else {
			 	   { if (fnPt ( str, fnPtr))			// Call comparison function (bool) via function pointer,
					 { valid = true ; }					// ...with 2 parameters, thereof 1 function pointer
			   	     else { valid = false ; }
			 	   }
				  }
			 if ( str == "n" )							// If User enteres n the program is terminated
				{ cout << "  " << "Program terminated!" << '\n' << '\n' ; exit ( 0 ) ; }
			 if ( valid == true && str.size() <= m )
			    { cout << " " ; }
			 else
			    { cout << "  Input wrong!" ; }
		   }
		while (!valid) ;
	  }

