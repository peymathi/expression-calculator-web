/* I pledge that I have neither given nor receieved any help on this assignment */

// This class inherits from the Bin_Expr_Node class. This class represents all binary nodes that contain
// the subtraction operation

#ifndef _SUB_EXPR_NODE_
#define _SUB_EXPR_NODE_

#include "Bin_Expr_Node.h"

class Sub_Expr_Node : public Bin_Expr_Node
{
public:
  // Default Constructor
  Sub_Expr_Node(void);

  // Initializing Constructor
  Sub_Expr_Node(Expr_Node * left, Expr_Node * right);

  // Destructor
  ~Sub_Expr_Node(void);

  // Allows visitor support for this node
  virtual void accept(Expr_Node_Visitor & visitor) const;

};

#endif
