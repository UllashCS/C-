#ifndef BOOLEAN_HPP
#define BOOLEAN_HPP

/* 
 * Challenge: Let's make an inverted boolean
 *
 * PROVIDE A BODY TO THIS FUNCTION TO MAKE IT COMPILE AND PRINT:
 *
 *    false
 *    true
 */

class boolean {
    public:
    bool m_Var;
	
    boolean (bool val);
    boolean& operator=(bool val);
    
	bool convert ();
    operator bool();
};


#endif  //BOOLEAN_HPP
