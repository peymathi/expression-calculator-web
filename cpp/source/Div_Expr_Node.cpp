/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation of the Div_Expr_Node class

#include "Div_Expr_Node.h"

// Default Constructor
Div_Expr_Node::Div_Expr_Node(void)
: Bin_Expr_Node("DIV")
{}

// Initializing Constructor
Div_Expr_Node::Div_Expr_Node(Expr_Node * left, Expr_Node * right)
: Bin_Expr_Node("DIV", left, right)
{}

// Destructor
Div_Expr_Node::~Div_Expr_Node(void)
{}

// Accept method
void Div_Expr_Node::accept(Expr_Node_Visitor & visitor) const
{
  visitor.visit_div_node(*this);
}
