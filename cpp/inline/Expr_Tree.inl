/* I pledge that I have neither given nor received any help on this assignment */

// Inline implementation for the Expr_Tree class

#include "Expr_Tree.h"

inline
void Expr_Tree::set_root(Expr_Node * root)
{
  this->root_ = root;
}

inline
Expr_Node * Expr_Tree::get_root(void)
{
  return this->root_;
}
