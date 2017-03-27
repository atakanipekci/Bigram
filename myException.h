#ifndef MYEXCEPTION_H
#define	MYEXCEPTION_H

#include <exception>
#include <string>
/*Used for exception cathching in mainTest*/
/*A common exception class which is used for using your exceptions without using types like int,string etc. Instead it simply uses exception.*/
using namespace std;
/*Note that it is derived from the original exception class*/
class myException : public exception{
public:
    
	myException()throw () :warning_message(string()) {};
	myException(const string& theMessage)throw () : warning_message(theMessage) {};
	virtual ~myException() throw () {} ;
    virtual const char* what () const throw () { return warning_message.c_str();};
    
            
private:
    string warning_message; /*To store the warning message */
};


#endif	


