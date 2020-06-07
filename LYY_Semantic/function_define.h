//
// Created by dell on 2020/6/4.
//

#ifndef COMPLIER_FUNCTION_DEFINE_H
#define COMPLIER_FUNCTION_DEFINE_H
# include "Complier.h"



void idlist(ATRNode *Node);
void const_value(ATRNode *Node);
void const_declaration(ATRNode *Node);
void const_declarations(ATRNode *Node);
void basic_type(ATRNode *Node);
void period(ATRNode *Node);
void type(ATRNode *Node);
void var_declaration(ATRNode *Node);
void var_declarations(ATRNode *Node);
void value_parameter(ATRNode *Node);
void var_parameter(ATRNode *Node);
void parameter(ATRNode *Node);
void parameter_list(ATRNode *Node);
void formal_parameter(ATRNode *Node);
void subprogram_head(ATRNode *Node);
void factor(ATRNode *Node);
void term(ATRNode *Node);
void simple_expression(ATRNode *Node);
void expression(ATRNode *Node);
void expression_list(ATRNode *Node);
void else_part(ATRNode *Node);
void procedure_call(ATRNode *Node);
void id_varpart(ATRNode *Node);
void variable(ATRNode *Node);
void variable_list(ATRNode *Node);
void statement(ATRNode *Node);
void statement_list(ATRNode *Node);
void compound_statement(ATRNode *Node);
void subprogram_body(ATRNode *Node);
void subprogram(ATRNode *Node);

void num(ATRNode *Node);
void relop(ATRNode *Node);
void addop(ATRNode *Node);
void mulop(ATRNode *Node);



void subprogram_declarations(ATRNode *Node);
void program_body(ATRNode *Node);
void program_head(ATRNode *Node);
void programstruct(ATRNode *Node);




T_item* TableSearch(const string& named, vector<T_item> *pointer);


#endif //COMPLIER_FUNCTION_DEFINE_H
