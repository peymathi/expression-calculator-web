/* I pledge that I have neither given nor receieved any help on this assignment */

/* Expr_Node_Visitor Class. This class is designed to be able to visit and perform various
  operations on the Expression Tree by visiting the concrete nodes of the Expr_Node class structure */

#ifndef _EXPR_NODE_VISITOR_
#define _EXPR_NODE_VISITOR_

// Forward declaration because these classes both include each other
class Add_Expr_Node;
class Mult_Expr_Node;
class Sub_Expr_Node;
class Mod_Expr_Node;
class Div_Expr_Node;
class Num_Expr_Node;

class Expr_Node_Visitor
{
public:
  // Destructor
  virtual ~Expr_Node_Visitor(void) = 0;

  // Visit all types of nodes in the Expression Tree
  virtual void visit_add_node(const Add_Expr_Node & node) = 0;
  virtual void visit_sub_node(const Sub_Expr_Node & node) = 0;
  virtual void visit_mult_node(const Mult_Expr_Node & node) = 0;
  virtual void visit_div_node(const Div_Expr_Node & node) = 0;
  virtual void visit_mod_node(const Mod_Expr_Node & node) = 0;
  virtual void visit_num_node(const Num_Expr_Node & node) = 0;

  // Returns a result of a visitors operation if there is one
  virtual int get_result(void) const = 0;

};

#endif
