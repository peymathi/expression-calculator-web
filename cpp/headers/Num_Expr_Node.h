/* I pledge that I have neither given nor receieved any help on this assignment */

// This class inherits from Expr_Node. This class represents all leaf nodes which will always contain
// numbers and no children

#ifndef _NUM_EXPR_NODE_
#define _NUM_EXPR_NODE_

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Num_Expr_Node : public Expr_Node
{
public:
  // Default Constructor
  Num_Expr_Node(void);

  // Initializing Constructor
  Num_Expr_Node(int num);

  // Destructor
  ~Num_Expr_Node(void);

  // Evaluate Method returns the number stored by this node
  int evaluate(void) const;

  // Allows visitor support for this node
  virtual void accept(Expr_Node_Visitor & visitor) const;

private:
  // Number that this node holds. This node has no children because it is a leaf node
  int number_;

};

#endif
