/* I pledge that I have neither given nor received any help on this assignment */

// Driver for the program
#include "Calculator.h"

// NODEJS SUPPORT
#include <node.h>

// For exception handling
#include "Eval_Expr_Tree.h"
#include "Expr_Builder.h"
#include <string.h>
#include <iostream>

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Object;
using v8::String;
using v8::Value;

void NodeAdapter(const FunctionCallbackInfo<Value>& args) 
{
  // Setting up Nodejs communication stuff
  Isolate* isolate = args.GetIsolate();
  std::string input;

  // Get the string of values entered from function args
  if (args[0].IsString())
  {
    input = args[0].ToString()->As();
  }

  else
  {
   args.GetReturnValue().Set("Not a String"); 
  }

  // String is assumed to be in space seperated form
  // Integer to store the result of the evaluated expression
  int result;

  // Calculator object
  Calculator * calc = new Calculator();

  // Attempt to calculate the entered string using the calculator
  calc->set_expression(userInput);
  result = calc->evaluate();

  // Translate the result to JS accepted format
  Local<Number> translated = Number::New(isolate, result);
  
  // Return the result
  args.GetReturnValue().Set(translated);
}

// int main()
// {
//   // Program takes a string from the user and prints the result of the expression until the user enters quit

//   // String for user input
//   std::string userInput;

//   // Integer to store the result of the evaluated expression
//   int result;

//   // Calculator object
//   Calculator * calc = new Calculator();

  

//   while(true)
//   {
//     std::cout << "Enter an expression or enter QUIT: ";
//     std::getline(std::cin, userInput);
//     // If the user entered QUIT, then break from the loop and the program
//     if(userInput == "QUIT")
//     {
//       break;
//     }

//     // Attempt to calculate the entered string using the calculator
//     try
//     {
//       calc->set_expression(userInput);
//       result = calc->evaluate();

//       std::cout << result;
//     }

//     // Catches Divide by zero exception
//     catch(Eval_Expr_Tree::divide_by_zero ex)
//     {
//       std::cout << "Expression attempts to divide by zero. Please try again." << std::endl;
//     }

//     // Catches Mod by zero exception
//     catch(Eval_Expr_Tree::mod_by_zero ex)
//     {
//       std::cout << "Expression attempts to take a modulus by zero. Please try again." << std::endl;
//     }

//     // Catches logic error
//     catch(Expr_Builder::logic_error ex)
//     {
//       std::cout << "Logic error in the entered expression. Please try again." << std::endl;
//     }

//     // Catches empty exception
//     catch(Calculator::empty_expression ex)
//     {
//       std::cout << "No expression entered. Please try again." << std::endl;
//     }

//     // Catches invalid token exception
//     catch(Calculator::invalid_token ex)
//     {
//       std::cout << "Invalid Token entered. Please try again." << std::endl;
//     }

//     // Catches unknown errors
//     catch(...)
//     {
//       std::cout << "Unknown Error. Please try again" << std::endl;
//     }

//     // Clear the calc object
//     calc->clear_calculator();

//   }

//   delete calc;
//   return 0;
// }
