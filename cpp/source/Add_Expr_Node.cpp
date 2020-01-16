/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Add_Expr_Node class

#include "Add_Expr_Node.h"

// Default Constructor
Add_Expr_Node::Add_Expr_Node(void)
: Bin_Expr_Node("ADD")
{}

// Initializing Constructor
Add_Expr_Node::Add_Expr_Node(Expr_Node * left, Expr_Node * right)
: Bin_Expr_Node("ADD", left, right)
{}

// Destructor
Add_Expr_Node::~Add_Expr_Node(void)
{}

// Accept method
void Add_Expr_Node::accept(Expr_Node_Visitor & visitor) const
{
  visitor.visit_add_node(*this);
}
