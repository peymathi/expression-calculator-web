/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Expr_Tree_Builder class

#include "Expr_Tree_Builder.h"

// Default Constructor
Expr_Tree_Builder::Expr_Tree_Builder(void)
: expression_tree_(nullptr),
  operators_(new Stack<Bin_Expr_Node*>()),
  current_nodes_(new Stack<Expr_Node*>())
{}

// Destructor
Expr_Tree_Builder::~Expr_Tree_Builder(void)
{
  // Does not delete the expression tree contained here in order to let the client control that

  // Delete the two stacks used for building
  delete this->operators_;
  delete this->current_nodes_;
}

// Start Expression
void Expr_Tree_Builder::start_expression(void)
{
  // Creates a new Expr_Tree object and stores it as state
  this->expression_tree_ = new Expr_Tree();
}

// Num
void Expr_Tree_Builder::build_num(int num)
{
  // Creates a new number node and pushes it to the stack of nodes
  Expr_Node * node = new Num_Expr_Node(num);
  this->current_nodes_->push(node);
}

// Add
void Expr_Tree_Builder::build_add_operator(void)
{
  // Create the node as a specific concrete type in order to call those methods
  Add_Expr_Node * node = new Add_Expr_Node();

  // Check for operator presence if the stack is not empty
  if(!this->operators_->is_empty())
  {
    this->move_operators(node);
  }

  // Push the current node to the stack of operators
  this->operators_->push(node);

}

// Sub
void Expr_Tree_Builder::build_sub_operator(void)
{
  Sub_Expr_Node * node = new Sub_Expr_Node();

  // Check for operator presence if the stack is not empty
  if(!this->operators_->is_empty())
  {
    this->move_operators(node);
  }

  // Push the current node to the stack of operators
  this->operators_->push(node);
}

// Mult
void Expr_Tree_Builder::build_mult_operator(void)
{
  Mult_Expr_Node * node = new Mult_Expr_Node();

  // Check for operator presence if the stack is not empty
  if(!this->operators_->is_empty())
  {
    this->move_operators(node);
  }

  // Push the current node to the stack of operators
  this->operators_->push(node);

}

// Div
void Expr_Tree_Builder::build_div_operator(void)
{
  Div_Expr_Node * node = new Div_Expr_Node();

  // Check for operator presence if the stack is not empty
  if(!this->operators_->is_empty())
  {
    this->move_operators(node);
  }

  // Push the current node to the stack of operators
  this->operators_->push(node);
}

// Mod
void Expr_Tree_Builder::build_mod_operator(void)
{
  Mod_Expr_Node * node = new Mod_Expr_Node();

  // Check for operator presence if the stack is not empty
  if(!this->operators_->is_empty())
  {
    this->move_operators(node);
  }

  // Push the current node to the stack of operators
  this->operators_->push(node);

}

// Open parenthesis
void Expr_Tree_Builder::build_open_parenthesis(void)
{
  // Push a nullptr to the stack of operators to represent an open parenthesis
  this->operators_->push(nullptr);

}

// Closed parenthesis
void Expr_Tree_Builder::build_closed_parenthesis(void)
{
  // Pop elements from the stack and add them to the tree until the open parenthesis is found

  // If the stack is empty, throw a logic exception
  if(this->operators_->is_empty())
  {
    throw logic_error();
  }

  // Pointer to contain the next element from the operator stack
  Bin_Expr_Node * current_operator = nullptr;

  // Runs until stack is empty
  while(!this->operators_->is_empty())
  {
    // Gets the next operator
    current_operator = this->operators_->pop();

    // If the operator equals nullptr then the loop is done
    if(current_operator == nullptr)
    {
      break;
    }

    // If the stack is now empty and nullptr was not found then throw a logic error
    else if(this->operators_->is_empty())
    {
      throw logic_error();
    }

    // Add this operator to the tree and keep going
    this->push_to_tree(current_operator);
  }
}

// Get Expression
Math_Expr * Expr_Tree_Builder::get_expression(void)
{
  // Check that an expression was started
  if(this->expression_tree_ == nullptr)
  {
    throw logic_error();
  }

  // Pop the rest of the elements off the operator stack and add to the tree
  while(!this->operators_->is_empty())
  {
    // If a nullptr is found, throw a logic error because an open parenthesis was not closed
    if(this->operators_->top() == nullptr)
    {
      throw logic_error();
    }

    this->push_to_tree(this->operators_->pop());
  }

  // If the stack has an element, set that element as the root node of the Expr_Tree
  if(!this->current_nodes_->is_empty())
  {
    this->expression_tree_->set_root(this->current_nodes_->top());
  }

  // Return the expression tree stored in state
  return this->expression_tree_;

}

// Helper method: Move operators
void Expr_Tree_Builder::move_operators(Bin_Expr_Node * node)
{
  // If the node is an addition node or a subtraction node
  if(node->ID == "ADD" || node->ID == "SUB")
  {
    // Pop elements off the stack and add to tree until the stack is empty or nullptr is found
    while(!this->operators_->is_empty() && this->operators_->top() != nullptr)
    {
      this->push_to_tree(this->operators_->pop());
    }
  }

  // If the node is a multiplication, division, or modulus node
  else if(node->ID == "MULT" || node->ID == "DIV" || node->ID == "MOD")
  {
    // Pop elements off the stack and add to tree until the stack is empty, nullptr is found, or the
    // element is an addition or subtraction node
    while(!this->operators_->is_empty() && this->operators_->top() != nullptr)
    {
      if(this->operators_->top()->ID != "ADD" && this->operators_->top()->ID != "SUB")
      {
        this->push_to_tree(this->operators_->pop());
      }

      else
      {
        break;
      }
    }
  }
}

// Helper method: Push to tree
void Expr_Tree_Builder::push_to_tree(Bin_Expr_Node * node)
{
  // If the stack is empty then throw a logic exception
  if(this->current_nodes_->is_empty())
  {
    delete node;
    throw logic_error();
  }

  // Pop an element off the tree stack and set it as the right child of the operator node
  node->set_right(this->current_nodes_->pop());

  // Check to see if the stack is empty now and if it is throw an exception
  if(this->current_nodes_->is_empty())
  {
    delete node;
    throw logic_error();
  }

  // Pop an element off the tree stack and set it as the left child of the operator node
  node->set_left(this->current_nodes_->pop());

  // Push this operator node to the tree stack
  this->current_nodes_->push(node);
}
