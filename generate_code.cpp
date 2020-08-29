//
// Created by 18233 on 2020/8/25/025.
//

#include "generator_code.h"


using namespace std;

const char * fname;

//@
//programstruct -> program_head ; program_body.
void generator_programstruct(ATRNode * node) {
    cout << "generator_programstruct" << endl;
    fstream output_stream;
    output_stream.open(fname, ios::out);
    generator_pretreatment();
    generator_program_body(&node->children[2]);
    output_stream.close();
}

//@
//生成预处理代码
void generator_pretreatment() {
    cout << "generator_pretreatment" << endl;
    fstream output_stream;
    output_stream.open(fname, ios::app|ios::in|ios::out);
    output_stream << "#include <stdio.h>" << endl;
    output_stream.close();
};

//@
//program_body -> const_declarations var_declarations subprogram_declarations compound_statement
void generator_program_body(ATRNode * node) {
    cout << "generator_program_body" << endl;
    fstream output_stream;
    int i;

    for(i = 0; i < node->children.size(); i++) {
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << endl;
        output_stream.close();
        if(node->children[i].attr == "const_declarations")
            generator_const_declarations(&node->children[i]);
        else if(node->children[i].attr == "var_declarations")
            generator_var_declarations(&node->children[i]);
        else if(node->children[i].attr == "subprogram_declarations")
            generator_subprogram_declarations(&node->children[i]);
        else {
            type = 0;
            output_stream.open(fname, ios::app|ios::in|ios::out);
            space(N);
            output_stream << "void main() {" << endl;
            N++;
            output_stream.close();
            generator_compound_statement(&node->children[3]);
            N--;
            space(N);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "}";
            output_stream.close();
        }
    }
}

//@
//idlist -> idlist,id | id
void generator_idlist(ATRNode * node, vector<ATRNode> * idlist) {
    cout << "generator_idlist" << endl;
    int i;
    for (i = 0; i < node->children.size(); i++) {
        if (node->children[i].id == -1)
            generator_idlist(&node->children[i], idlist);
        else if (node->children[i].id == COMMA && node->children[i].attr == ",")
            continue;
        else
            idlist->push_back(node->children[i]);
    }
}

//@
//const_declarations -> const const_declaration; | e
void generator_const_declarations(ATRNode * node) {
    cout << "generator_const_declarations" << endl;
    if (node->children.size() == 3){
        generator_const_declaration(&node->children[1]);
    }
}

//@
//const_declaration -> const_declaration; id = const_value | id = const_value
void generator_const_declaration(ATRNode * node) {
    cout << "generator_const_declaration" << endl;
    int i;
    fstream output_stream;
    for (i = 0; i < node->children.size(); i++) {
        if (node->children[i].id == -1 && node->children[i].attr == "const_declaration")
            generator_const_declaration(&node->children[i]);
        else if (node->children[i].id == IDENTIFIER) {
            T_item id = search_table(node->children[i].attr, true);
            space(N);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "const ";
            if (id.type == INTEGER)
                output_stream << "int ";
            else if (id.type == REAL)
                output_stream << "float ";
            else if (id.type == CHAR)
                output_stream << "char ";
            output_stream << id.name << " = ";
            output_stream.close();
        }
        else if (node->children[i].id == -1 && node->children[i].attr == "const_value") {
            generator_const_value(&node->children[i]);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << ";" << endl;
            output_stream.close();
        }
        else
            continue;
    }
}

//@
//const_value -> +num | -num | num | 'letter'
void generator_const_value(ATRNode * node) {
    cout << "generator_const_value" << endl;
    fstream output_stream;
    if (node->children[0].id == PLUS || node->children[0].id == MINUS) {
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << node->children[0].attr;
        output_stream.close();
        generator_num(&node->children[1]);
    }
    else if (node->children[0].id == -1 && node->children[0].attr == "num")
        generator_num(&node->children[0]);
    else {
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << "'" << node->children[1].attr << "'";
        output_stream.close();
    }

}

//@
//num -> digits | realnumber
void generator_num(ATRNode * node) {
    cout << "generator_num" << endl;
    fstream output_stream;
    output_stream.open(fname, ios::app|ios::in|ios::out);
    output_stream << node->children[0].attr;
    output_stream.close();
}

//@
//var_declarations-> var var_declaration; | e
void generator_var_declarations(ATRNode * node){
    cout << "generator_var_declarations" << endl;
    if (node->children.size() == 3){
        generator_var_declaration(&node->children[1]);
    }
    else if (node->children.empty()){
        // debug
    }
}

//@
// var_declaration -> var_declaration; idlist: type | idlist: type
void generator_var_declaration(ATRNode * node){
    cout << "generator_var_declaration" << endl;
    int i;
    fstream output_stream;

    if (node->children[0].id == -1 && node->children[0].attr == "var_declaration") {
        generator_var_declaration(&node->children[0]);
        space(N);
        generator_type(&node->children[4]);
        ATRNode temp = node->children[4];
        if (temp.children[0].attr == "basic_type"){
            vector<ATRNode> idlist;
            generator_idlist(&node->children[2], &idlist);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            for (i = 0; i < idlist.size() -1; i++){
                output_stream << idlist[i].attr << ", ";
            }
            output_stream << idlist[idlist.size() - 1].attr << ";" << endl;
            output_stream.close();
        }
        else{
            vector<ATRNode> idlist;
            generator_idlist(&node->children[2], &idlist);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            for (i = 0; i < idlist.size() -1; i++){
                output_stream << idlist[i].attr;
                output_stream.close();
                generator_period(&temp.children[2]);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << ", ";
            }
            output_stream << idlist[idlist.size() - 1].attr;
            output_stream.close();
            generator_period(&temp.children[2]);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << ";" << endl;
            output_stream.close();
        }
    }
    else {
        space(N);
        generator_type(&node->children[2]);
        ATRNode temp = node->children[2];
        if (temp.children[0].attr == "basic_type"){
            vector<ATRNode> idlist;
            generator_idlist(&node->children[0], &idlist);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            for (i = 0; i < idlist.size() -1; i++){
                output_stream << idlist[i].attr << ", ";
            }
            output_stream << idlist[idlist.size() - 1].attr << ";" << endl;
            output_stream.close();
        }
        else{
            vector<ATRNode> idlist;
            generator_idlist(&node->children[0], &idlist);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            for (i = 0; i < idlist.size() -1; i++){
                output_stream << idlist[i].attr;
                output_stream.close();
                generator_period(&temp.children[2]);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << ", ";
            }
            output_stream << idlist[idlist.size() - 1].attr;
            output_stream.close();
            generator_period(&temp.children[2]);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << ";" << endl;
            output_stream.close();
        }
    }
}

//@
// type -> basic_type | array [period] of basic_type
void generator_type(ATRNode * node){
    cout << "generator_type" << endl;
    fstream output_stream;
    output_stream.open(fname, ios::app|ios::in|ios::out);

    if (node->children[0].id == -1 && node->children[0].attr == "basic_type")
        generator_basic_type(&node->children[0]);
    else if (node->children[0].id == ARRAY)
        generator_basic_type(&node->children[5]);
    output_stream << " ";
    output_stream.close();
}

//@
// basic_type -> integer | real | boolean | char
void generator_basic_type(ATRNode * node){
    cout << "generator_basic_type" << endl;
    fstream output_stream;
    output_stream.open(fname, ios::app|ios::in|ios::out);
    if (node->children[0].id == INTEGER || node->children[0].id == BOOLEAN){
        output_stream << "int";
    }
    else if (node->children[0].id == REAL){
        output_stream << "float";
    }
    else if (node->children[0].id == CHAR) {
        output_stream << "char";
    }
    output_stream.close();
}

//@
// period -> period, digseq .. digseq | digseq .. digseq
void generator_period(ATRNode * node){
    cout << "generator_period" << endl;
    fstream output_stream;
    output_stream.open(fname, ios::app|ios::in|ios::out);

    if (node->children[0].id == -1 && node->children[0].attr == "period"){
        generator_period(&node->children[0]);
        if (node->children[2].id == DIGSEQ && node->children[4].id == DIGSEQ){
            int length = stoi(node->children[4].attr) - stoi(node->children[2].attr) + 1;
            output_stream << "[" << length << "]";
        }
    }
    else if (node->children[0].id == DIGSEQ){
        if (node->children[2].id == DIGSEQ){
            int length = stoi(node->children[2].attr) - stoi(node->children[0].attr) + 1;
            output_stream << "[" << length << "]";
        }
    }
    output_stream.close();
}

//@
// subprogram_declarations -> subprogram_declarations subprogram; | e
void generator_subprogram_declarations(ATRNode * node){
    cout << "generator_subprogram_declarations" << endl;
    if (node->children.size() == 3){
        cout << node->children[0].attr << endl;
        generator_subprogram_declarations(&node->children[0]);
        generator_subprogram(&node->children[1]);
    }
    else if (node->children.empty()){
        // debug
    }
}

//@
// subprogram -> subprogram_head; subprogram_body
void generator_subprogram(ATRNode * node){
    cout << "generator_subprogram" << endl;
    cout << node->children[0].attr << endl;
    space(N);
    fstream output_stream;
    generator_subprogram_head(&node->children[0]);
    output_stream.open(fname, ios::app|ios::in|ios::out);
    output_stream << " ";
    output_stream.close();
    generator_subprogram_body(&node->children[2]);
    output_stream.open(fname, ios::app|ios::in|ios::out);
    output_stream << endl;
    output_stream.close();
}

//@
// subprogram_head -> procedure id formal_parameter | function id formal_parameter : basic_type
void generator_subprogram_head(ATRNode * node){
    cout << "generator_subprogram_head" << endl;
    fstream output_stream;
    T_item item = search_table(node->children[1].attr, true);
    curTable = item.p;
    if (node->children[0].id == PROCEDURE){
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << "void " << node->children[1].attr;
        output_stream.close();
        generator_formal_parameter(&node->children[2]);
        type = 0;
    }
    else if (node->children[0].id == FUNCTION){
        generator_basic_type(&node->children[4]);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << " ";   // basic type后不带空格手动添加
        output_stream << node->children[1].attr;
        output_stream.close();
        generator_formal_parameter(&node->children[2]);
        type = 1;
    }
}

//@
// formal_parameter -> ( parameter_list )
void generator_formal_parameter(ATRNode * node){
    cout << "generator_formal_parameter" << endl;
    fstream output_stream;
    if (node->children.size() == 3){
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << "(";
        output_stream.close();
        generator_parameter_list(&node->children[1]);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << ")";
        output_stream.close();
    }
    else if (node->children.empty()){
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << "()";
        output_stream.close();
    }
}

//@
// parameter_list -> parameter_list ; parameter | parameter
void generator_parameter_list(ATRNode * node){
    cout << "generator_parameter_list" << endl;
    fstream output_stream;
    if (node->children[0].id == -1 && node->children[0].attr == "parameter_list"){
        generator_parameter_list(&node->children[0]);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << ", ";
        output_stream.close();
        generator_parameter(&node->children[2]);
    }
    else if (node->children[0].id == -1 && node->children[0].attr == "parameter"){
        generator_parameter(&node->children[0]);
    }
}

//@
//parameter -> var_parameter | value_parameter
void generator_parameter(ATRNode * node) {
    cout << "generator_parameter" << endl;
    if (node->children[0].id == -1 && node->children[0].attr == "var_parameter") {
        generator_var_parameter(&node->children[0]);
    }
    else
        generator_value_parameter(&node->children[0]);
}

//@
//var_parameter -> var value_parameter
void generator_var_parameter(ATRNode * node) {
    cout << "generator_var_parameter" << endl;
    ATRNode temp = node->children[1];
    int i;
    fstream output_stream;
    vector<ATRNode> idlist;
    generator_idlist(&temp.children[0], &idlist);
    for (i = 0; i < idlist.size() - 1; i++) {
        generator_basic_type(&temp.children[2]);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << " * " << idlist[i].attr << ", ";
        output_stream.close();
    }
    generator_basic_type(&temp.children[2]);
    output_stream.open(fname, ios::app|ios::in|ios::out);
    output_stream << " * " << idlist[idlist.size() - 1].attr;
    output_stream.close();
}

//@
//value_parameter -> idlist : basic_type
void generator_value_parameter(ATRNode * node) {
    cout << "generator_value_parameter" << endl;
    int i;
    fstream output_stream;
    vector<ATRNode> idlist;
    generator_idlist(&node->children[0], &idlist);
    for (i = 0; i < idlist.size() - 1; i++) {
        generator_basic_type(&node->children[2]);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << " " << idlist[i].attr << ", ";
        output_stream.close();
    }
    generator_basic_type(&node->children[2]);
    output_stream.open(fname, ios::app|ios::in|ios::out);
    output_stream << " " << idlist[idlist.size() - 1].attr;
    output_stream.close();
}

//@
//subprogram_body -> const_declarations var_declarations compound_statement
void generator_subprogram_body(ATRNode * node) {
    cout << "generator_subprogram_body" << endl;
    fstream  output_stream;
    output_stream.open(fname, ios::app|ios::in|ios::out);
    output_stream << "{" << endl;
    N++;
    output_stream.close();
    int i;
    for(i = 0; i < node->children.size(); i++) {
        if(node->children[i].attr == "const_declarations")
            generator_const_declarations(&node->children[i]);
        else if(node->children[i].attr == "var_declarations")
            generator_var_declarations(&node->children[i]);
        else
            generator_compound_statement(&node->children[i]);
    }
    if (type == 1 && numofe == 1) {
        space(N);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << "return ";
        output_stream.close();
        generator_expression(e);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << ";" << endl;
        numofe--;
        output_stream.close();
    }
    output_stream.open(fname, ios::app|ios::in|ios::out);
    N--;
    space(N);
    output_stream << "}";
    output_stream.close();
    curTable = &SymbolTable;
}

//@
//compound_statement -> begin statement_list end
void generator_compound_statement(ATRNode * node) {
    cout << "generator_compound_statement" << endl;
    generator_statement_list(&node->children[1]);
}

//@
//statement_list -> statement_list ; statement | statement
void generator_statement_list(ATRNode * node) {
    cout << "generator_statement_list" << endl;
    int i;
    for (i = 0; i < node->children.size(); i++) {
        if (node->children[i].id == -1 && node->children[i].attr == "statement_list")
            generator_statement_list(&node->children[i]);
        else if (node->children[i].id == -1 && node->children[i].attr == "statement")
            generator_statement(&node->children[i]);
        else continue;
    }
}

//@
//statement -> variable assignop expression
//|procedure_call
//|compound_statement
//|if expression then statement else_part
//|for id assignop expression to expression do statement
//|read ( variable_list )
//|write ( expression_list )
//|while expression do statement
//| e
void generator_statement(ATRNode * node) {
    cout << "generator_statement" << endl;
    fstream output_stream;

    if (!node->children.empty()){
        if (node->children[0].id == -1 && node->children[0].attr == "variable") {
            ATRNode temp = node->children[0].children[0];
            if (temp.attr == (*curTable)[0].name && type == 1) {
                e = &node->children[2];
                numofe++;
            }
            else {
                space(N);
                T_item id = search_table(node->children[0].children[0].attr, false);
                generator_variable(&node->children[0]);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << " = ";
                output_stream.close();
                generator_expression(&node->children[2]);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << ";" << endl;
                output_stream.close();
            }

        }
        else if (node->children[0].id == -1 && node->children[0].attr == "procedure_call") {
            space(N);
            generator_procedure_call(&node->children[0]);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << ";" << endl;
            output_stream.close();
        }
        else if (node->children[0].id == -1 && node->children[0].attr == "compound_statement") {
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "{" << endl;
            N++;
            output_stream.close();
            generator_compound_statement(&node->children[0]);
            N--;
            space(N);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "}" << endl;
            output_stream.close();
        }
        else if (node->children[0].id == IF) {
            space(N);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "if " << "(";
            output_stream.close();
            generator_expression(&node->children[1]);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << ") ";
            output_stream << "{" << endl;
            N++;
            output_stream.close();
            generator_statement(&node->children[3]);
            if (type == 1 && numofe == 1) {
                space(N);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << "return ";
                output_stream.close();
                generator_expression(e);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << ";" << endl;
                numofe--;
                output_stream.close();
            }
            output_stream.open(fname, ios::app|ios::in|ios::out);
            N--;
            space(N);
            output_stream << "}" << endl;
            output_stream.close();
            generator_else_part(&node->children[4]);
        }
        else if (node->children[0].id == FOR) {
            space(N);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "for (" << node->children[1].attr << " = ";
            output_stream.close();
            generator_expression(&node->children[3]);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "; " << node->children[1].attr << " <= ";
            output_stream.close();
            generator_expression(&node->children[5]);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "; " << node->children[1].attr << "++" << ") ";
            output_stream << "{" << endl;
            N++;
            output_stream.close();
            generator_statement(&node->children[7]);
            if (type == 1 && numofe == 1) {
                space(N);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << "return ";
                output_stream.close();
                generator_expression(e);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << ";" << endl;
                numofe--;
                output_stream.close();
            }
            N--;
            space(N);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "}" << endl;
            output_stream.close();
        }
        else if (node->children[0].id == WHILE) {
            space(N);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "while (";
            output_stream.close();
            generator_expression(&node->children[1]);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << ") ";
            output_stream << "{" << endl;
            N++;
            output_stream.close();
            generator_statement(&node->children[3]);
            if (type == 1 && numofe == 1) {
                space(N);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << "return ";
                output_stream.close();
                generator_expression(e);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << ";" << endl;
                numofe--;
                output_stream.close();
            }
            N--;
            space(N);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "}" << endl;
            output_stream.close();
        }
        else if (node->children[0].id == READ) {
            space(N);
            vector<ATRNode> varlist;
            generator_variable_list(&node->children[2], &varlist);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "scanf(\"";
            int i;
            for (i = 0; i < varlist.size(); i++) {
                T_item id = search_table(varlist[i].children[0].attr, false);
                if (id.type == INTEGER)
                    output_stream << "%d";
                else if (id.type == REAL)
                    output_stream << "%f";
                else if (id.type == CHAR)
                    output_stream << "%c";
                if (i == varlist.size() - 1)
                    continue;
                output_stream << " ";
            }
            output_stream << "\", ";
            output_stream.close();
            for (i = 0; i < varlist.size(); i++) {
                T_item id = search_table(varlist[i].children[0].attr, false);
                if(!id.is_ref) {
                    output_stream.open(fname, ios::app|ios::in|ios::out);
                    output_stream << "&";
                    output_stream.close();
                }
                generator_variable_read(&varlist[i]);
                if (i == varlist.size() - 1)
                    continue;
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << ", ";
                output_stream.close();
            }
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << ");" << endl;
            output_stream.close();
        }
        else if (node->children[0].id == WRITE) {
            space(N);
            vector<ATRNode> exlist;
            generator_expression_list(&node->children[2], &exlist);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "printf(\"";
            int t;
            int i;
            for (i = 0; i < exlist.size(); i++) {
                t = typeofexpression(&exlist[i]);
                if (t == INTEGER)
                    output_stream << "%d";
                else if (t == REAL)
                    output_stream << "%f";
                else if (t == CHAR)
                    output_stream << "%c";
                if (i == exlist.size() - 1)
                    continue;
                output_stream << ", ";
            }
            output_stream << "\", ";
            output_stream.close();
            for (i = 0; i < exlist.size(); i++) {
                generator_expression(&exlist[i]);
                if (i == exlist.size() - 1)
                    continue;
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << ", ";
                output_stream.close();
            }
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << ");" << endl;
            output_stream.close();
        }
    }
    /*
     * else {
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << endl;
        output_stream.close();
    }
     */

}

//@
// variable_list -> variable_list, variable | variable
void generator_variable_list(ATRNode * node, vector<ATRNode> * varlist){
    cout << "generator_variable_list" << endl;
    if (node->children[0].attr == "variable_list"){
        generator_variable_list(&node->children[0], varlist);
        varlist->push_back(node->children[2]);
    }
    else if(node->children[0].attr == "variable"){
        varlist->push_back(node->children[0]);
    }
}

//@
// variable -> id id_varpart
void generator_variable(ATRNode * node){
    cout << "generator_variable" << endl;
    fstream output_stream;
    if (node->children[0].id == IDENTIFIER){
        T_item id = search_table(node->children[0].attr, false);
        if (id.dimension != 0) {
            tempTable = curTable;
            curTable = id.p;
        }
        output_stream.open(fname, ios::app|ios::in|ios::out);
        if(id.is_ref) output_stream << "*";
        output_stream << id.name;
        output_stream.close();
        generator_id_varpart(&node->children[1]);
    }
}

//@
// variable -> id id_varpart
void generator_variable_read(ATRNode * node){
    cout << "generator_variable" << endl;
    fstream output_stream;
    if (node->children[0].id == IDENTIFIER){
        T_item id = search_table(node->children[0].attr, false);
        if (id.dimension != 0) {
            tempTable = curTable;
            curTable = id.p;
        }
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << id.name;
        output_stream.close();
        generator_id_varpart(&node->children[1]);
    }
}

//@
// id_varpart -> [expression_list] | e
void generator_id_varpart(ATRNode * node){
    cout << "generator_id_varpart" << endl;
    fstream output_stream;

    if (node->children.size() == 3){
        vector<ATRNode> exlist;
        int i;

        generator_expression_list(&node->children[1], &exlist);
        for (i = 0; i < exlist.size(); i++){
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << "[";
            output_stream.close();
            ATRNode temp = exlist[i].children[0].children[0].children[0];
            if(temp.children[0].attr == "num") {
                string num = temp.children[0].children[0].attr;
                int a = strtol(num.c_str(), nullptr, 10);
                int b = (*curTable)[i].type;
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << a - b;
                output_stream << "]";
                output_stream.close();
            }
            else {
                generator_variable(&temp.children[0]);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << "]";
                output_stream.close();
            }
        }
        curTable = tempTable;
    }
    else if (node->children.empty()){
        // debug
    }
}

//@
// procedure_call -> id | id (expression_list)
void generator_procedure_call(ATRNode * node){
    cout << "generator_procedure_call" << endl;
    fstream output_stream;

    if (node->children[0].id == IDENTIFIER){
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << node->children[0].attr;
        if (node->children.size() == 4){
            T_item id = search_table(node->children[0].attr, false);
            vector<T_item> *p1;
            if((*curTable)[0].name == id.name) p1 = curTable;
            else p1 = id.p;
            vector<ATRNode> exlist;
            int i;

            output_stream << "(";
            output_stream.close();
            generator_expression_list(&node->children[2], &exlist);
            for (i = 0; i < exlist.size(); i++){
                if((*p1)[i + 1].is_ref) {
                    output_stream.open(fname, ios::app|ios::in|ios::out);
                    output_stream << "&";
                    output_stream.close();
                }
                generator_expression(&exlist[i]);
                if (i == exlist.size() - 1)
                    continue;
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << ", ";
                output_stream.close();
            }
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << ")";
            output_stream.close();
        }
        else if (node->children.size() == 1){
            output_stream << "()";
            output_stream.close();
        }
    }
}

//@
// else_part -> else statement | e
void generator_else_part(ATRNode * node){
    cout << "generator_else_part" << endl;
    fstream output_stream;

    if (node->children.size() == 2){
        if (node->children[0].id == ELSE){
            output_stream.open(fname, ios::app|ios::in|ios::out);
            space(N);
            output_stream << "else {" << endl;
            output_stream.close();
            N++;
            generator_statement(&node->children[1]);
            if (type == 1 && numofe == 1) {
                space(N);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << "return ";
                output_stream.close();
                generator_expression(e);
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << ";" << endl;
                numofe--;
                output_stream.close();
            }
            output_stream.open(fname, ios::app|ios::in|ios::out);
            N--;
            space(N);
            output_stream << "}" << endl;
            output_stream.close();
        }
    }
    else if (node->children.empty()){
        //debug
    }
}

//@
// expression_list -> expression_list, expression | expression
void generator_expression_list(ATRNode * node, vector<ATRNode> * exlist){
    cout << "generator_expression_list" << endl;
    if (node->children.size() == 3){
        generator_expression_list(&node->children[0], exlist);
        exlist->push_back(node->children[2]);
    }
    else if (node->children.size() == 1){
        exlist->push_back(node->children[0]);
    }
}

//@
// expression -> simple_expression relop simple_expression | simple_expression
void generator_expression(ATRNode * node){
    cout << "generator_expression" << endl;
    fstream output_stream;

    int i;
    for (i = 0; i < node->children.size(); i++){
        if (node->children[i].id == -1 && node->children[i].attr == "simple_expression"){
            generator_simple_expression(&node->children[i]);
        }
        else if (node->children[i].id == -1 && node->children[i].attr == "relop"){
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << " ";
            output_stream.close();
            generator_relop(&node->children[i]);
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << " ";
            output_stream.close();
        }
    }
}

//@
// simple_expression -> simple_expression addop term | term
void generator_simple_expression(ATRNode * node){
    cout << "generator_simple_expression" << endl;
    fstream output_stream;

    if (node->children[0].id == -1 && node->children[0].attr == "simple_expression"){
        generator_simple_expression(&node->children[0]);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << " ";
        output_stream.close();
        generator_addop(&node->children[1]);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << " ";
        output_stream.close();
        generator_term(&node->children[2]);
    }
    else if (node->children[0].id == -1 && node->children[0].attr == "term"){
        generator_term(&node->children[0]);
    }

    output_stream.close();
}

//@
// term -> term mulop factor | factor
void generator_term(ATRNode * node){
    cout << "generator_term" << endl;
    fstream output_stream;

    if (node->children[0].id == -1 && node->children[0].attr == "term"){
        generator_term(&node->children[0]);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << " ";
        output_stream.close();
        generator_mulop(&node->children[1]);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << " ";
        output_stream.close();
        generator_factor(&node->children[2]);
    }
    else if (node->children[0].id == -1 && node->children[0].attr == "factor"){
        generator_factor(&node->children[0]);
    }
}

//@
// factor -> num
//| variable
//| id ( expression_list )
//| ( expression )
//| not factor
//| - factor
void generator_factor(ATRNode * node){
    cout << "generator_factor" << endl;
    fstream output_stream;

    if (node->children[0].id == -1 && node->children[0].attr == "num"){
        generator_num(&node->children[0]);
    }
    else if (node->children[0].id == -1 && node->children[0].attr == "variable"){
        generator_variable(&node->children[0]);
    }
    else if (node->children[0].id == IDENTIFIER){
        T_item id = search_table(node->children[0].attr, false);
        vector<T_item> *p1 = id.p;
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << id.name;
        vector<ATRNode> exlist;
        generator_expression_list(&node->children[2], &exlist);
        int i;

        output_stream << "(";
        output_stream.close();
        for (i = 0; i < exlist.size(); i++){
            if((*p1)[i + 1].is_ref) {
                output_stream.open(fname, ios::app|ios::in|ios::out);
                output_stream << "&";
                output_stream.close();
            }
            generator_expression(&exlist[i]);
            if (i == exlist.size() - 1)
                continue;
            output_stream.open(fname, ios::app|ios::in|ios::out);
            output_stream << ", ";
            output_stream.close();
        }
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << ")";
        output_stream.close();
    }
    else if (node->children[0].attr == "("){
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << "(";
        output_stream.close();
        generator_expression(&node->children[1]);
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << ")";
        output_stream.close();
    }
    else if (node->children[0].id == NOT){
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << "!";
        output_stream.close();
        generator_factor(&node->children[1]);
    }
    else if (node->children[0].attr == "-"){
        output_stream.open(fname, ios::app|ios::in|ios::out);
        output_stream << "-";
        output_stream.close();
        generator_factor(&node->children[1]);
    }
}

//@
// relop -> > | = | < | <= | >= | <>
void generator_relop(ATRNode * node){
    cout << "generator_relop" << endl;
    fstream output_stream;
    output_stream.open(fname, ios::app|ios::in|ios::out);
    if (node->children[0].attr == ">"){
        output_stream << ">";
    }
    else if (node->children[0].attr == "="){
        output_stream << "==";
    }
    else if (node->children[0].attr == "<"){
        output_stream << "<";
    }
    else if (node->children[0].attr == "<="){
        output_stream << "<=";
    }
    else if (node->children[0].attr == ">="){
        output_stream << ">=";
    }
    else if (node->children[0].attr == "<>"){
        output_stream << "!=";
    }
    output_stream.close();
}

//@
// addop -> + | - | or
void generator_addop(ATRNode * node){
    cout << "generator_addop" << endl;
    fstream output_stream;
    output_stream.open(fname, ios::app|ios::in|ios::out);
    if (node->children[0].attr == "+"){
        output_stream << "+";
    }
    else if (node->children[0].attr == "-"){
        output_stream << "-";
    }
    else if (node->children[0].attr == "or"){
        output_stream << "||";
    }
    output_stream.close();
}

//@
// mulop -> * | / | mod | and | div
void generator_mulop(ATRNode * node){
    cout << "generator_mulop" << endl;
    fstream output_stream;
    output_stream.open(fname, ios::app|ios::in|ios::out);

    if (node->children[0].attr == "*"){
        output_stream << "*";
    }
    else if (node->children[0].attr == "/" || node->children[0].attr == "div"){
        output_stream << "/";
    }
    else if (node->children[0].attr == "mod"){
        output_stream << "%";
    }
    output_stream.close();
}

//@
// expression的类型，返回值为INTEGER，CHAR，REAL
//expression ->  simple_expression relop simple_expression | simple_expression
int typeofexpression(ATRNode * node){
    if (node->children.size() == 3){
        return INTEGER;
    }
    else return typeofsimpleexpression(&node->children[0]);
}

//@
// simple_expression的类型，返回值为INTEGER，CHAR，REAL
//simple_expression -> simple_expression addop term | term
int typeofsimpleexpression(ATRNode * node){
    if (node->children.size() == 3){
        ATRNode * temp = &node->children[1];
        if (temp->children[0].attr == "or"){
            return INTEGER;
        }
        return gettype(typeofsimpleexpression(&node->children[0]), typeofterm(&node->children[2]));
    }
    else return typeofterm(&node->children[0]);
}

//@
// term的类型，返回值为INTEGER，CHAR，REAL
//term -> term mulop factor | factor
int typeofterm(ATRNode * node){
    if (node->children.size() == 3){
        ATRNode * temp = &node->children[1];
        if (temp->children[0].attr == "and"){
            return INTEGER;
        }
        return gettype(typeofterm(&node->children[0]), typeoffactor(&node->children[2]));
    }
    else return typeoffactor(&node->children[0]);
}

//@
// factor的类型，返回值为INTEGER，CHAR，REAL
//factor -> num
//| variable
//| id ( expression_list )
//| ( expression )
//| not factor
//| - factor
int typeoffactor(ATRNode * node){
    if (node->children[0].attr == "num"){
        ATRNode * temp = &node->children[0];
        if (temp->children[0].id == DIGSEQ){
            return INTEGER;
        }
        else return REAL;
    }
    else if (node->children[0].attr == "variable"){
        ATRNode * temp = &node->children[0];
        T_item id = search_table(temp->children[0].attr, false);
        return id.type;
    }
    else if (node->children[0].id == IDENTIFIER){
        T_item id = search_table(node->children[0].attr, false);
        return (*id.p)[0].type;
    }
    else if (node->children[0].attr == "("){
        return typeofexpression(&node->children[1]);
    }
    else return typeoffactor(&node->children[1]);
}

//@
// 决定表达式类型
int gettype(int type1, int type2){
    if (type1 == REAL || type2 == REAL){
        return REAL;
    }
    else if (type1 == INTEGER || type2 == INTEGER){
        return INTEGER;
    }
    else if (type1 == CHAR && type2 == CHAR){
        return CHAR;
    }
    else{
        //error
        return CHAR;
    }
}

// 空格
void space(int n) {
    int i;
    fstream output_stream;
    output_stream.open(fname, ios::app|ios::in|ios::out);
    for(i = 0; i < n; i++) {
        output_stream << "    ";
    }
    output_stream.close();
}

void generate_code(ATRNode * node, const char * file_name) {
    char *temp = new char[strlen(file_name)+1];
    strcpy(temp, file_name);
    int i = 0;
    while(file_name[i] != '.') i++;
    temp[i + 1] = 'c';
    temp[i + 2] = '\0';
    fname = temp;
    generator_programstruct(node);
}