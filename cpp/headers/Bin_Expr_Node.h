/* I pledge that I have neither given nor receieved any help on this assignment */

// This class inherits from Expr_Node class. It represents all nodes that have two children.

#ifndef _BIN_EXPR_NODE_
#define _BIN_EXPR_NODE_

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Bin_Expr_Node : public Expr_Node
{
public:
  // Default Constructor
  Bin_Expr_Node(const std::string id);

  // Initializing Constructor
  Bin_Expr_Node(const std::string id, Expr_Node * left, Expr_Node * right);

  // Destructor
  ~Bin_Expr_Node(void);

  // Passes the visitor support method to child methods because this is also an abstract class
  virtual void accept (Expr_Node_Visitor & visitor) const = 0;

  // Returns a pointer to the left child
  Expr_Node * get_left(void) const;

  // Returns a pointer to the right child
  Expr_Node * get_right(void) const;

  // Sets the left pointer
  void set_left(Expr_Node * left);

  // Sets the right pointer
  void set_right(Expr_Node * right);

protected:
  // Pointers to the left and right children
  Expr_Node * left_;
  Expr_Node * right_;

};

#endif
