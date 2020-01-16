/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Sub_Expr_Node class

#include "Sub_Expr_Node.h"

// Default Constructor
Sub_Expr_Node::Sub_Expr_Node(void)
: Bin_Expr_Node("SUB")
{}

// Initializing Constructor
Sub_Expr_Node::Sub_Expr_Node(Expr_Node * left, Expr_Node * right)
: Bin_Expr_Node("SUB", left, right)
{}

// Destructor
Sub_Expr_Node::~Sub_Expr_Node(void)
{}

// Accept method
void Sub_Expr_Node::accept(Expr_Node_Visitor & visitor) const
{
  visitor.visit_sub_node(*this);
}
