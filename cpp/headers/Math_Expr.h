/* I pledge that I have neither given nor received any help on this assignment */

// This class is an interface to represent a mathematical expression.

#ifndef _MATH_EXPR_
#define _MATH_EXPR_

class Math_Expr
{
public:
  // Default Constructor
  Math_Expr(void);

  // Destructor
  virtual ~Math_Expr(void) = 0;

  // Evaluates the expression
  virtual int evaluate(void) = 0;

  // Returns the result
  int get_result(void);

protected:
  // Result of the expression
  int result_;

};

// Include the inline implementation
#include "Math_Expr.inl"

#endif
