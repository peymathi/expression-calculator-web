/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Eval_Expr_Tree class

#include "Eval_Expr_Tree.h"

// Default Constructor
Eval_Expr_Tree::Eval_Expr_Tree(void)
{}

// Destructor
Eval_Expr_Tree::~Eval_Expr_Tree(void)
{}

// Visit Add node
void Eval_Expr_Tree::visit_add_node(const Add_Expr_Node & node)
{
  // Visit the left child
  node.get_left()->accept(*this);

  // Store the result from above in a temporary integer
  int leftVal = this->result_;

  // Visit the right child
  node.get_right()->accept(*this);

  // Add the value from the result of the left operation to the current result
  this->result_ += leftVal;

}

// Visit Sub node
void Eval_Expr_Tree::visit_sub_node(const Sub_Expr_Node & node)
{
  // Visit the left child
  node.get_left()->accept(*this);

  // Store the result from above in a temporary integer
  int leftVal = this->result_;

  // Visit the right child
  node.get_right()->accept(*this);

  // Subtract the value currently stored in the result member from the left value and store it in
  // this object's result member
  this->result_ = leftVal - this->result_;
}

// Visit Mult node
void Eval_Expr_Tree::visit_mult_node(const Mult_Expr_Node & node)
{
  // Visit the left child
  node.get_left()->accept(*this);

  // Store the result from above in a temporary integer
  int leftVal = this->result_;

  // Visit the right child
  node.get_right()->accept(*this);

  // Multiply the result from the left operation by the result currently stored in this object's result member
  this->result_ *= leftVal;
}

// Visit Div node
void Eval_Expr_Tree::visit_div_node(const Div_Expr_Node & node)
{
  // Visit the left child
  node.get_left()->accept(*this);

  // Store the result from above in a temporary integer
  int leftVal = this->result_;

  // Visit the right child
  node.get_right()->accept(*this);

  // Check to see if the result from the right operation is zero
  if(this->result_ == 0)
  {
    // Throw a divide_by_zero exception because this expression attempts to divide by zero
    throw divide_by_zero();
  }

  // Divide the result for the left operation by the result of the right operation and store it in this object's
  // result member
  this->result_ = leftVal / this->result_;
}

// Visit Mod node
void Eval_Expr_Tree::visit_mod_node(const Mod_Expr_Node & node)
{
  // visit the left child
  node.get_left()->accept(*this);

  // Store the result from above in a temporary integer
  int leftVal = this->result_;

  // Visit the right child
  node.get_right()->accept(*this);

  // Check to see if the result from the right operation is zero
  if(this->result_ == 0)
  {
    // Throw a mod_by_zero exception because this expression attempts to take modulus by zero
    throw mod_by_zero();
  }

  // Take the modulus of the left operation by the result of the right operation and store it in this object's
  // result member
  this->result_ = leftVal % this->result_;

}

// Visit Num node
void Eval_Expr_Tree::visit_num_node(const Num_Expr_Node & node)
{
  // Evaluate this node and set result to its evaluation
  this->result_ = node.evaluate();
}
