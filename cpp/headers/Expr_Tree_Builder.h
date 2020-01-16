/* I pledge that I have neither given nor received any help on this assignment */

// This class inherits from Expr_Builder and builds an expression in the form of a binary tree.
// This class is designed to build an expression tree from an expression in postfix order

#ifndef _EXPR_TREE_BUILDER_
#define _EXPR_TREE_BUILDER_

#include "Expr_Builder.h"
#include "Bin_Expr_Node.h"
#include "Expr_Tree.h"
#include "Stack.h"
#include "Queue.h"

class Expr_Tree_Builder : public Expr_Builder
{
public:
  // Default Constructor
  Expr_Tree_Builder(void);

  // Destructor
  ~Expr_Tree_Builder(void);

  // Creates the Expr_Tree object
  virtual void start_expression(void);

  // Creates a number node and adds it to the tree
  virtual void build_num(int num);

  // Creats an Addition node and pushes it to the operator stack
  virtual void build_add_operator(void);

  // Creates a subraction node and pushes it to the operator Stack
  virtual void build_sub_operator(void);

  // Creates a Multiplication node and pushes it to the operator stack
  virtual void build_mult_operator(void);

  // Creates a division node and pushes it to the operator stack
  virtual void build_div_operator(void);

  // Creates a modulus node and pushes it to the operator stack
  virtual void build_mod_operator(void);

  // Adds a nullptr element to the stack to represent an open parenthesis
  virtual void build_open_parenthesis(void);

  // Pops elements off the stack and adds them to the tree until open parenthesis is found
  virtual void build_closed_parenthesis(void);

  // Returns the stored expression tree
  Math_Expr * get_expression(void);

private:
  // Current State of the expression tree
  Expr_Tree * expression_tree_;

  // Stack to represent the nodes in the tree currently being build
  Stack<Expr_Node*> * current_nodes_;

  // Stack to hold the operators to be added to the tree later
  Stack<Bin_Expr_Node*> * operators_;

  // Helper method for dealing with operator presedence
  void move_operators(Bin_Expr_Node * node);

  // Helper method for adding an operator to the tree
  void push_to_tree(Bin_Expr_Node * node);

};

#endif
