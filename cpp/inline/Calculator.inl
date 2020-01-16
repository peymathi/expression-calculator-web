/* I pledge that I have neither given nor received any help on this assignment */

// Inline Implementation for the Calculator class

inline
void Calculator::set_expression(std::string expr)
{
  this->expression_string_ = expr;
}

inline
int Calculator::get_result(void)
{
  return this->result_;
}

inline
void Calculator::clear_calculator(void)
{
  this->result_ = 0;
  this->expression_string_ = "";
  delete this->expression_tree_;
  this->expression_tree_ = nullptr;
}
