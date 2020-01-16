/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Mod_Expr_Node class

#include "Mod_Expr_Node.h"

// Defalut Constructor
Mod_Expr_Node::Mod_Expr_Node(void)
: Bin_Expr_Node("MOD")
{}

// Initializing Constructor
Mod_Expr_Node::Mod_Expr_Node(Expr_Node * left, Expr_Node * right)
: Bin_Expr_Node("MOD", left, right)
{}

// Destructor
Mod_Expr_Node::~Mod_Expr_Node(void)
{}

// Accept Method
void Mod_Expr_Node::accept(Expr_Node_Visitor & visitor) const
{
  visitor.visit_mod_node(*this);
}
