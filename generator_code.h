//
// Created by dell on 2020/5/29.
//

#ifndef GENERATER_GENERATER_H
#define GENERATER_GENERATER_H

#include <fstream>
#include <cstdlib>
#include "compile.h"
#include "yacc.tab.h"

//programstruct -> program_head ; program_body.
void generator_programstruct(ATRNode * node);

//生成预处理代码
void generator_pretreatment();

//program_body -> const_declarations
//               var_declarations
//               subprogram_declarations
//               compound_statement
void generator_program_body(ATRNode * node);

//idlist -> idlist , id | id
void generator_idlist(ATRNode * node, vector<ATRNode> * idlist);

//const_declarations -> const const_declaration; | e
void generator_const_declarations(ATRNode * node);

//const_declaration -> const_declaration ; id = const_value | id = const_value
void generator_const_declaration(ATRNode * node);

//const_value -> +num | -num | num | ‘letter’
void generator_const_value(ATRNode * node);

//num -> digseq | realnumber
void generator_num(ATRNode * node);

//var_declarations -> var var_declaration ; | e
void generator_var_declarations(ATRNode * node);

//var_declaration -> var_declaration ; idlist : type | idlist : type
void generator_var_declaration(ATRNode * node);

//type -> basic_type | array [ period ] of basic_type
void generator_type(ATRNode * node);

//basic_type -> integer | real | boolean | char
void generator_basic_type(ATRNode * node);

//period -> period , digseq .. digseq | digseq .. digseq
void generator_period(ATRNode * node);

//subprogram_declarations -> subprogram_declarations subprogram ; | e
void generator_subprogram_declarations(ATRNode * node);

//subprogram -> subprogram_head ; subprogram_body
void generator_subprogram(ATRNode * node);

//subprogram_head -> procedure id formal_parameter | function id formal_parameter : basic_type
void generator_subprogram_head(ATRNode * node);

//formal_parameter -> ( parameter_list ) | e
void generator_formal_parameter(ATRNode * node);

//parameter_list -> parameter_list ; parameter | parameter
void generator_parameter_list(ATRNode * node);

//parameter -> var_parameter | value_parameter
void generator_parameter(ATRNode * node);

//var_parameter -> var value_parameter
void generator_var_parameter(ATRNode * node);

//value_parameter -> idlist : basic_type
void generator_value_parameter(ATRNode * node);

//subprogram_body -> const_declarations
//                  var_declarations
//                  compound_statement
void generator_subprogram_body(ATRNode * ndoe);

//compound_statement -> begin statement_list end
void generator_compound_statement(ATRNode * node);

//statement_list -> statement_list ; statement | statement
void generator_statement_list(ATRNode * node);

//statement -> variable assignop expression
//|procedure_call
//|compound_statement
//|if expression then statement else_part
//|for id assignop expression to expression do statement
//|read ( variable_list )
//|write ( expression_list )
//|while expression do statement
//| e
void generator_statement(ATRNode * node);

//variable_list -> variable_list , variable | variable
void generator_variable_list(ATRNode * node, vector<ATRNode> * varlist);

//variable -> id id_varpart
void generator_variable(ATRNode * node);

//variable -> id id_varpart
void generator_variable_read(ATRNode * node);

//id_varpart -> [ expression_list ] | e
void generator_id_varpart(ATRNode * node);

//procedure_call -> id | id ( expression_list )
void generator_procedure_call(ATRNode * node);

//else_part -> else statement | e
void generator_else_part(ATRNode * node);

//expression_list -> expression_list , expression | expression
void generator_expression_list(ATRNode * node, vector<ATRNode> * exlist);

//expression ->  simple_expression relop simple_expression | simple_expression
void generator_expression(ATRNode * node);

//simple_expression -> simple_expression addop term | term
void generator_simple_expression(ATRNode * node);

//term -> term mulop factor | factor
void generator_term(ATRNode * node);

//factor -> num
//| variable
//| id ( expression_list )
//| ( expression )
//| not factor
//| - factor
void generator_factor(ATRNode * node);

//relop -> > | = | < | <= | >= | <>
void generator_relop(ATRNode * node);

//addop -> + | - | or
void generator_addop(ATRNode * node);

//mulop -> * | / | mod | and | div
void generator_mulop(ATRNode * node);

// expression的类型，返回值为INTEGER，CHAR，REAL
//expression ->  simple_expression relop simple_expression | simple_expression
int typeofexpression(ATRNode * node);

// simple_expression的类型，返回值为INTEGER，CHAR，REAL
//simple_expression -> simple_expression addop term | term
int typeofsimpleexpression(ATRNode * node);

// term的类型，返回值为INTEGER，CHAR，REAL
//term -> term mulop factor | factor
int typeofterm(ATRNode * node);

// factor的类型，返回值为INTEGER，CHAR，REAL
//factor -> num
//| variable
//| id ( expression_list )
//| ( expression )
//| not factor
//| - factor
int typeoffactor(ATRNode * node);

// 决定表达式类型
int gettype(int type1, int type2);

// 空格
void space(int n);

int N = 0;

int type = 0;

ATRNode * e;

int numofe = 0;

vector<T_item> * tempTable;

int startindex = 0;
int endindex = 0;

#endif //GENERATER_GENERATER_H