/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Num_Expr_Node class

#include "Num_Expr_Node.h"

// Default Constructor
Num_Expr_Node::Num_Expr_Node(void)
: Expr_Node("NUM"),
  number_(0)
{}

// Initializing Constructor
Num_Expr_Node::Num_Expr_Node(int num)
: Expr_Node("NUM"),
  number_(num)
{}

// Destructor
Num_Expr_Node::~Num_Expr_Node(void)
{}

// Evaluate Method
int Num_Expr_Node::evaluate(void) const
{
  return this->number_;
}

// Accept method
void Num_Expr_Node::accept(Expr_Node_Visitor & visitor) const
{
  visitor.visit_num_node(*this);
}
