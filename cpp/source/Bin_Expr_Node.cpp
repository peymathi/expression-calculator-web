/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Bin_Expr_Node class

#include "Bin_Expr_Node.h"

// Default Constructor
Bin_Expr_Node::Bin_Expr_Node(const std::string id)
: Expr_Node(id),
  left_(nullptr),
  right_(nullptr)
{}

// Initializing Constructor
Bin_Expr_Node::Bin_Expr_Node(const std::string id, Expr_Node * left, Expr_Node * right)
: Expr_Node(id),
  left_(left),
  right_(right)
{}

// Destructor
Bin_Expr_Node::~Bin_Expr_Node(void)
{
  delete this->left_;
  delete this->right_;
}

// Get left
Expr_Node * Bin_Expr_Node::get_left(void) const
{
  return this->left_;
}

// Get right
Expr_Node * Bin_Expr_Node::get_right(void) const
{
  return this->right_;
}

// Set left
void Bin_Expr_Node::set_left(Expr_Node * left)
{
  this->left_ = left;
}

// Set right
void Bin_Expr_Node::set_right(Expr_Node * right)
{
  this->right_ = right;
}
