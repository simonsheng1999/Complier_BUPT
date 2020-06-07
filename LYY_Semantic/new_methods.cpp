//
// Created by dell on 2020/6/4.
//
#include "Complier.h"
#include "methods.h"


//生成一棵树
ATRNode sampleCreate()
{
    //叶子节点,即程序源码
    ATRNode program(PROGRAM, "program", 1);
    ATRNode id1(IDENTIFIER, "example",1);
    ATRNode leftBracket(LPAREN, "(",1);
    ATRNode id2(IDENTIFIER, "input",1);
    ATRNode comma1(COMMA, ",",1);
    ATRNode id3(IDENTIFIER, "output",1);
    ATRNode rightBracket(RPAREN, ")",1);
    ATRNode scolon1(SEMICOLON, ";",1);

    ATRNode empty1(EMPTY,"");
    ATRNode var(VAR, "var",2);
    ATRNode id4(IDENTIFIER, "x",2);
    ATRNode comma2(COMMA, ",",2);
    ATRNode id5(IDENTIFIER, "y",2);
    ATRNode colon(COLON, ":",2);

    ATRNode integer(INTEGER, "integer",2);

    ATRNode scolon2(SEMICOLON, ";",2);
    ATRNode empty2(EMPTY,"");

    ATRNode begin(PBEGIN, "begin",3);
    ATRNode id6(IDENTIFIER, "x",4);
    ATRNode empty3(EMPTY, "");
    ATRNode assignment(ASSIGNMENT, ":=",4);
    ATRNode id7(IDENTIFIER, "y",4);
    ATRNode empty4(EMPTY, "");
    ATRNode add(PLUS, "+",4);
    ATRNode digseq(DIGSEQ, "1",4);

    ATRNode end(END, "end",6);
    ATRNode dot(DOT, ".",6);

    //生成非叶子节点
    ATRNode const_declarations(-1, "const_declarations");   //const_declarations->NULL
    const_declarations.children.push_back(empty1);

    ATRNode subprogram_declarations(-1, "subprogram_declarations"); //subprogram_declarations->NULL
    subprogram_declarations.children.push_back(empty2);

    //program example(input,output)
    ATRNode idlist1(-1,"idlist");   //idlist->id
    idlist1.children.push_back(id2);

    ATRNode idlist2(-1,"idlist");   //idlist->idlist , id
    idlist2.children.push_back(idlist1);
    idlist2.children.push_back(comma1);
    idlist2.children.push_back(id3);

    ATRNode program_head(-1, "program_head");   //program_head->program id ( idlist )
    program_head.children.push_back(program);
    program_head.children.push_back(id1);
    program_head.children.push_back(leftBracket);
    program_head.children.push_back(idlist2);
    program_head.children.push_back(rightBracket);

    //var  x,y:integer;
    ATRNode idlist3(-1,"idlist");   //idlist->id
    idlist3.children.push_back(id4);

    ATRNode idlist4(-1,"idlist");   //idlist->idlist , id
    idlist4.children.push_back(idlist3);
    idlist4.children.push_back(comma2);
    idlist4.children.push_back(id5);


    ATRNode basic_type(-1,"basic_type");  //basic_type->integer
    basic_type.children.push_back(integer);

    ATRNode type(-1,"type");  //type->basic_type
    type.children.push_back(basic_type);


    ATRNode var_declaration(-1, "var_declaration"); //var_declaration->idlist  :  type
    var_declaration.children.push_back(idlist4);
    var_declaration.children.push_back(colon);
    var_declaration.children.push_back(type);

    ATRNode var_declarations(-1, "var_declarations"); //var_declarations->var  var_declaration ;
    var_declarations.children.push_back(var);
    var_declarations.children.push_back(var_declaration);
    var_declarations.children.push_back(scolon2);

    //begin
    //     x:=y+1
    //end
    ATRNode id_varpart1(-1, "id_varpart"); //id_varpart->NULL
    id_varpart1.children.push_back(empty3);

    ATRNode variable1(-1, "variable"); //variable->id id_varpart
    variable1.children.push_back(id6);
    variable1.children.push_back(id_varpart1);


    ATRNode id_varpart2(-1, "id_varpart"); //id_varpart->NULL
    id_varpart2.children.push_back(empty4);

    ATRNode variable2(-1, "variable"); //variable->id id_varpart
    variable2.children.push_back(id7);
    variable2.children.push_back(id_varpart2);

    ATRNode factor1(-1,"factor"); //factor->variable
    factor1.children.push_back(variable2);

    ATRNode term1(-1,"term"); //term->factor
    term1.children.push_back(factor1);

    ATRNode simple_expression1(-1, "simple_expression"); //simple_expression->term
    simple_expression1.children.push_back(term1);

    ATRNode num(-1,"num"); //factor->variable
    num.children.push_back(digseq);

    ATRNode factor2(-1,"factor"); //factor->variable
    factor2.children.push_back(num);

    ATRNode term2(-1,"term"); //term->factor
    term2.children.push_back(factor2);

    ATRNode addop(-1,"addop"); //term->factor
    addop.children.push_back(add);


    ATRNode simple_expression2(-1, "simple_expression"); //simple_expression->simple_expression addop term
    simple_expression2.children.push_back(simple_expression1);
    simple_expression2.children.push_back(addop);
    simple_expression2.children.push_back(term2);

    ATRNode expression(-1, "expression");   //expression->simple_expression
    expression.children.push_back(simple_expression2);

    ATRNode statement(-1, "statement"); //statement->variable assignment expression
    statement.children.push_back(variable1);
    statement.children.push_back(assignment);
    statement.children.push_back(expression);

    ATRNode statement_list(-1, "statement_list"); //statement_list->statement
    statement_list.children.push_back(statement);

    ATRNode compound_statement(-1, "compound_statement");
    compound_statement.children.push_back(begin);
    compound_statement.children.push_back(statement_list);
    compound_statement.children.push_back(end);


    ATRNode program_body(-1, "program_body");
    program_body.children.push_back(const_declarations);
    program_body.children.push_back(var_declarations);
    program_body.children.push_back(subprogram_declarations);
    program_body.children.push_back(compound_statement);

    ATRNode programstruct(-1, "programstruct");
    programstruct.children.push_back(program_head);
    programstruct.children.push_back(scolon1);
    programstruct.children.push_back(program_body);
    programstruct.children.push_back(dot);


    return programstruct;
}


//遍历树
//后序遍历树
void postorder_traversal(ATRNode *Node)
{

    if(Node->children.empty())       // 如果到根节点
    {
        cout << Node->attr << " ";
    }
    else{
        for(auto & i : Node->children)
        {
            postorder_traversal(&i);
        }
    }

}


//画表
void DrawTable()
{
    cout << endl << "|\t名称\t|\t类型\t|\t维度\t|\t声明行\t|\t指针域\t|" <<endl;
    for(auto & i : SymbolTable)
    {
        string s;
        if(i.p == nullptr) s="否";
        else
        {
            s="是";
        }
        cout << "|\t" <<i.name;
        cout <<"\t|\t"<<i.type;
        cout <<"\t|\t"<<i.dimension;
        cout <<"\t|\t"<<i.line;
        cout <<"\t|\t"<<s<<"\t|" <<endl;
    }
}


//空间回收
//表类型
//主表    递归
//作用域表 递归删，除去第一行
//数组表  直接删
//过程函数表 递归删，除去第一行
void distroyTable(vector<T_item> *Table , int count)
{

    for(int i = count;i<Table->size();i++)
    {
        if((*Table)[i].p != nullptr)
        {
            if((*Table)[i].type == FUNCTION || (*Table)[i].type==PROCEDURE || (*Table)[i].name=="_")
            {
                distroyTable((*Table)[i].p, 1);
            }
            delete (*Table)[i].p;
        }
    }
}


int main()
{
    ATRNode root = sampleCreate();

    postorder_traversal(&root);
    cout<<endl;

    programstruct(&root);


    //输出错误
    for (auto &i:SemanticErrorTable) {
        cout<<i.kind << " "<< i.line<<endl;
    }


    DrawTable();
    distroyTable(&SymbolTable, 0);

    return 0;
}