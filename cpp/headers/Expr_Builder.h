/* I pledge that I have neither given nor receieved any help on this assignment */

// Expr_Builder class. Builds an expression of some form.

#ifndef _EXPR_BUILDER_
#define _EXPR_BUILDER_

#include "Math_Expr.h"
#include <exception>

class Expr_Builder
{
public:
  // Exception to be thrown when a logic error occurs
  class logic_error : public std::exception
  {
  public:
    // Default Constructor
    logic_error(void)
    : std::exception()
    {}

  };

  // Destructor
  virtual ~Expr_Builder(void) = 0;

  // Creates the initial expression object
  virtual void start_expression(void) = 0;

  // Builds a number object
  virtual void build_num (int num) = 0;

  // Builds an addition object
  virtual void build_add_operator (void) = 0;

  // Builds a subtraction object
  virtual void build_sub_operator (void) = 0;

  // Builds a multiplication object
  virtual void build_mult_operator (void) = 0;

  // Builds a division object
  virtual void build_div_operator (void) = 0;

  // Builds a modulus object
  virtual void build_mod_operator (void) = 0;

  // Builds an open parenthesis
  virtual void build_open_parenthesis(void) = 0;

  // Builds a closed parenthsis
  virtual void build_closed_parenthesis(void) = 0;

  // Returns the expression
  virtual Math_Expr * get_expression (void) = 0;

};

#endif
