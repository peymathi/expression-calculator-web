/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Unary_Expr_Node class

#include "Unary_Expr_Node.h"

// Default Constructor
Unary_Expr_Node::Unary_Expr_Node(void)
: Expr_Node("UNARY"),
  child_(nullptr)
{}

// Initializing Constructor
Unary_Expr_Node::Unary_Expr_Node(Expr_Node * child)
: Expr_Node("UNARY"),
  child_(child)
{}

// Destructor
Unary_Expr_Node::~Unary_Expr_Node(void)
{
  delete this->child_;
}

// Get child
Expr_Node * Unary_Expr_Node::get_child(void)
{
  return this->child_;
}
