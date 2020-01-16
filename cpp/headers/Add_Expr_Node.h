/* I pledge that I have neither given nor receieved any help on this assignment */

// This class inherits from the Bin_Expr_Node class and represents binary nodes that contain
// the addition operation

#ifndef _ADD_EXPR_NODE_
#define _ADD_EXPR_NODE_

#include "Bin_Expr_Node.h"

class Add_Expr_Node : public Bin_Expr_Node
{
public:
  // Default Constructor
  Add_Expr_Node(void);

  // Initializing Constructor
  Add_Expr_Node(Expr_Node * left, Expr_Node * right);

  // Destructor
  ~Add_Expr_Node(void);

  // Allows visitor support on this node
  virtual void accept(Expr_Node_Visitor & visitor) const;

};

#endif
