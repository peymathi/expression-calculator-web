/* I pledge that I have neither given nor receieved any help on this assignment */

// This class inherits from the Bin_Expr_Node class. This class represents all binary nodes that
// contain the multiplication operation.

#ifndef _MULT_EXPR_NODE_
#define _MULT_EXPR_NODE_

#include "Bin_Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Mult_Expr_Node : public Bin_Expr_Node
{
public:
  // Default Constructor
  Mult_Expr_Node(void);

  // Initializing Constructor
  Mult_Expr_Node(Expr_Node * left, Expr_Node * right);

  // Destructor
  ~Mult_Expr_Node(void);

  // Allows visitor support for this node
  virtual void accept(Expr_Node_Visitor & visitor) const;

};

#endif
