/* I pledge that I have neither given nor receieved any help on this assignment */

// This class inherits from the Bin_Expr_Node class. This class represents all binary nodes
// that contain the modulus operation.

#ifndef _MOD_EXPR_NODE_
#define _MOD_EXPR_NODE_

#include "Bin_Expr_Node.h"
#include "Expr_Node_Visitor.h"
#include <exception>

class Mod_Expr_Node : public Bin_Expr_Node
{
public:

  // Default Constructor
  Mod_Expr_Node(void);

  // Initializing Constructor
  Mod_Expr_Node(Expr_Node * left, Expr_Node * right);

  // Destructor
  ~Mod_Expr_Node(void);

  // Allows visitor support for this node
  virtual void accept(Expr_Node_Visitor & visitor) const;

};

#endif
