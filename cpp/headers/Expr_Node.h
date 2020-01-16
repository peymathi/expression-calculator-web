/* I pledge that I have neither given nor receieved any help on this assignment */

// This class is the interface for all Expression Nodes within an expression tree.

#ifndef _EXPR_NODE_
#define _EXPR_NODE_

// Includes the visitor class for this class to allow visitor support
#include "Expr_Node_Visitor.h"
#include <string>

class Expr_Node
{
public:
  // Default Constructor
  Expr_Node (const std::string id);

  // Destructor
  virtual ~Expr_Node (void) = 0;

  // To be implemented in all concrete classes to allow visitor support
  virtual void accept (Expr_Node_Visitor & visitor) const = 0;

  // String to contain the type
  const std::string ID;

};

#endif
