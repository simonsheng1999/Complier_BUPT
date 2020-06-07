//
// Created by dell on 2020/6/4.
//

#ifndef COMPLIER_METHODS_H
#define COMPLIER_METHODS_H
#include "Complier.h"
#include "function_define.h"

//传入的Node都是父节点

//idlist->id  |  idlist , id
void idlist(ATRNode *Node)
{

    if(Node->children.size()==1)
    {
        if(Node->array_record.empty()) //非数组
        {
            T_item temp(Node->children[0].attr, Node->id, 0, Node->children[0].line, nullptr);
            TablePointer->push_back(temp);
        } else
        {
            auto *newTable = new vector<T_item>;
            int size = Node->array_record.size();
            for(int i=size-1;i>=0;i--)      //倒着填入
            {
                T_item dim("", Node->array_record[i].begin, Node->array_record[i].end, 0, nullptr); //添加数组信息
                newTable->push_back(dim);
            }

            T_item temp(Node->children[0].attr, Node->id, Node->array_record.size(), Node->children[0].line, newTable);
            TablePointer->push_back(temp);
        }
    } else{
        if(Node->array_record.empty()) //非数组
        {
            //先对id做处理
            T_item temp(Node->children[2].attr, Node->id, 0, Node->children[2].line, nullptr);
            TablePointer->push_back(temp);

            Node->children[0].id = Node->id;
            idlist(&Node->children[0]);

        } else
        {
            //先对id做处理
            auto *newTable = new vector<T_item>;
            int size = Node->array_record.size();
            for(int i=size-1;i>=0;i--)      //倒着填入
            {
                T_item dim("", Node->array_record[i].begin, Node->array_record[i].end, 0, nullptr);
                newTable->push_back(dim);
            }

            T_item temp(Node->children[2].attr, Node->id, Node->array_record.size(), Node->children[2].line, newTable);
            TablePointer->push_back(temp);

            Node->children[0].id = Node->id;
            Node->children[0].array_record = Node->array_record;
            idlist(&Node->children[0]);
        }
    }

}

//const_value-> + num | - num | num | 'letter'
void const_value(ATRNode *Node)
{
    if(Node->children.size()==1)
    {
        num(&Node->children[0]);
        Node->id = Node->children[0].id;
    }
    else if(Node->children.size()==2){
        num(&Node->children[1]);
        Node->id = Node->children[1].id;
    }else{
        Node->id = Node->children[1].id;
    }
}

//const_declaration -> const_declaration ;  id = const_value | id = const_value
void const_declaration(ATRNode *Node)
{
    if(Node->children.size()==5)
    {
        const_value(&Node->children[4]);    //先让其获取id

        T_item temp(Node->children[2].attr, Node->children[4].id, 0, 0, nullptr);
        TablePointer->push_back(temp);

        const_declaration(&Node->children[0]);

    } else{
        const_value(&Node->children[4]);    //先让其获取id

        T_item temp(Node->children[0].attr, Node->children[2].id, 0, 0, nullptr);
        TablePointer->push_back(temp);
    }
}

//const_declarations -> const  const_declaration  ;  | NULL
void const_declarations(ATRNode *Node)
{
    if(Node->children.size()>1) const_declaration(&Node->children[1]);
}

//basic_type -> integer | real | boolean | char
void basic_type(ATRNode *Node)
{
    Node->id = Node->children[0].id;
}

//period -> period ， digits .. digits | digits .. digits
void period(ATRNode *Node)
{
    if(Node->children.size()==3)
    {
        int first = stoi(Node->children[0].attr);
        int second = stoi(Node->children[2].attr);
        Array temp(first, second);
        Node->array_record.push_back(temp);

    } else{
        period(&Node->children[0]);

        Node->array_record = Node->children[0].array_record;

        int first = stoi(Node->children[2].attr);
        int second = stoi(Node->children[4].attr);
        Array temp(first, second);
        Node->array_record.push_back(temp);
    }
}

//type -> basic_type | type -> array [  period  ] of  basic_type
void type(ATRNode *Node)
{

    if(Node->children.size()==1)
    {
        basic_type(&Node->children[0]);
        Node->id = Node->children[0].id;
    } else{

        period(&Node->children[2]);
        basic_type(&Node->children[5]);

        Node->id = Node->children[5].id;
        Node->array_record = Node->children[2].array_record;

    }
}

//var_declaration -> var_declaration  ;  idlist  :  type | idlist  :  type
void var_declaration(ATRNode *Node)
{
    if(Node->children.size() == 3)
    {
        type(&Node->children[2]);   //通过递归先获取到id

        Node->children[0].id = Node->children[2].id;
        Node->children[0].array_record = Node->children[2].array_record;//记录数组


        idlist(&Node->children[0]);
    } else{

        var_declaration(&Node->children[0]);

        type(&Node->children[4]);   //通过递归先获取到id

        Node->children[2].id = Node->children[4].id;
        Node->children[2].array_record = Node->children[4].array_record;//记录数组
        idlist(&Node->children[2]);
    }
}

//var_declarations -> var  var_declaration ;  | NULL
void var_declarations(ATRNode *Node)
{
    if(Node->children.size()>1) var_declaration(&Node->children[1]);
}

//value_parameter -> idlist  :  basic_type
void value_parameter(ATRNode *Node)
{
    basic_type(&Node->children[2]);

    Node->children[0].id = Node->children[2].id;

    idlist(&Node->children[0]);
}

//var_parameter -> var value_parameter
void var_parameter(ATRNode *Node)
{
    value_parameter(&Node->children[1]);
}

//parameter -> var_parameter | value_parameter
void parameter(ATRNode *Node)
{
    if(Node->children[0].attr == "var_parameter") var_parameter(&Node->children[0]);
    else value_parameter(&Node->children[0]);
}

//parameter_list -> parameter_list  ;  parameter |  parameter
void parameter_list(ATRNode *Node)
{
    if(Node->children.size()==1)
    {
        parameter(&Node->children[0]);
    } else{
        parameter_list(&Node->children[0]);
        parameter_list(&Node->children[2]);
    }
}

//formal_parameter -> (  parameter_list  )  | NULL
void formal_parameter(ATRNode *Node)
{
    if(Node->children.size()>1) parameter_list(&Node->children[1]);
}

//subprogram_head -> procedure id formal_parameter | function id formal_parameter : basic_type
void subprogram_head(ATRNode *Node)
{
    auto *sub_Table = new vector<T_item>;       //建立新的子表


    if(Node->children.size()==3)        //过程
    {
        T_item title(Node->children[1].attr, NONE, 0, Node->children[1].line, TablePointer);
        sub_Table->push_back(title);

        vector<T_item> *pre = TablePointer; //记录上一张表
        TablePointer = sub_Table;       //改变表指针

        formal_parameter(&Node->children[2]);

        int dim = int(sub_Table->size()) - 1;        //当前表的大小减1,此时只填充了参数
        T_item temp(Node->children[1].attr, PROCEDURE, dim, Node->children[1].line, TablePointer);
        pre->push_back(temp);
    } else{
        basic_type(&Node->children[4]);     //获取返回值属性
        T_item title(Node->children[1].attr, Node->children[4].id, 0, Node->children[1].line, TablePointer);
        sub_Table->push_back(title);

        vector<T_item> *pre = TablePointer; //记录上一张表
        TablePointer = sub_Table;       //改变表指针

        formal_parameter(&Node->children[2]);

        int dim = int(sub_Table->size()) - 1;        //当前表的大小减1,因为有表头,此时只填充了参数
        T_item temp(Node->children[1].attr, FUNCTION, dim, Node->children[1].line, TablePointer);
        pre->push_back(temp);
    }


}


//factor -> num  (常量)
//factor -> variable
//factor -> ( expression)
//factor -> not  factor
//factor -> uminus  factor
//factor -> id ( expression_list )
void factor(ATRNode *Node)
{
    string attr = Node->children[0].attr;
    if(attr == "num")
    {
        num(&Node->children[0]);
        Node->id = Node->children[0].id;
    }
    else if(attr == "variable")
    {
        variable(&Node->children[0]);
        Node->id = Node->children[0].id;
        Node->is_array = Node->children[0].is_array;
    }
    else if(attr == "(")
    {
        expression(&Node->children[1]);
        Node->id = Node->children[1].id;
        Node->is_array = Node->children[1].is_array;
    }
    else if(attr == "not")
    {
        //不用类型检测吗？
        factor(&Node->children[1]);
        Node->id = BOOLEAN;
    }
    else if(attr == "uminus")
    {
        //不用类型检测吗？
        factor(&Node->children[1]);

        if(Node->children[1].is_array)
        {
            Semantic_Error error("KindError", Node->children[1].line);
            SemanticErrorTable.push_back(error);
        }
        if(Node->children[1].id==REAL || Node->children[1].id==REALNUMBER)
            Node->id = REAL;
        else Node->id = INTEGER;

    }
    else if(Node->children[0].id == IDENTIFIER)     //检测是不是有这个函数
    {
        procedure_call(Node);

    } else{
        Node->id = Node->children[0].id;
    }

}


//term -> term  mulop  factor
//term -> factor
void term(ATRNode *Node)
{
    if(Node->children.size()==1)
    {
        factor(&Node->children[0]);
        Node->id = Node->children[0].id;
        Node->is_array = Node->children[0].is_array;
    } else{
        term(&Node->children[0]);
        mulop(&Node->children[1]);
        factor(&Node->children[2]);


        //不可以的操作
        //为mod时，只能为integer和DIGSEQ
        //除了mod，数组名不行，类型不同不行

        int id_0 = Node->children[0].id;
        int id_1 = Node->children[1].id;
        int id_2 = Node->children[2].id;

        bool condition0 = id_1==MOD && ((id_0 != DIGSEQ && id_0 != INTEGER) || (id_2 != DIGSEQ && id_2 != INTEGER));
        bool condition1 = id_0 != id_2;

        bool condition2 = (id_0==DIGSEQ && id_2!= INTEGER) || (id_0==INTEGER && id_2!= DIGSEQ);     //因为上一个条件，所以等价于反过来
        bool condition3 = (id_0==REALNUMBER && id_2!= REAL) || (id_0==REAL && id_2!= REALNUMBER);

        bool condition4 = Node->children[0].is_array || Node->children[2].is_array;     //两者至少有一个为指针


        if(condition0 || (condition1 && (condition2 || condition3)) || condition4)
        {
            Semantic_Error error("KindError", Node->children[1].line);
            SemanticErrorTable.push_back(error);
            Node->id = NONE;
        }else{

            if(Node->children[1].id==AND)
            {
                Node->id = BOOLEAN;
            }else
            {
                Node->id = Node->children[0].id;        //因为类型判断无所谓，所以不用区分类型放哪个
            }

        }


    }
}


//simple_expression -> simple_expression  addop term
//simple_expression -> term
void simple_expression(ATRNode *Node)
{
    if(Node->children.size()==1)
    {
        term(&Node->children[0]);
        Node->id = Node->children[0].id;
        Node->is_array = Node->children[0].is_array;
    } else
    {
        simple_expression(&Node->children[0]);
        addop(&Node->children[1]);
        term(&Node->children[2]);


        //不可以的操作
        //为mod时，只能为integer和DIGSEQ
        //除了mod，数组名不行，类型不同不行

        int id_0 = Node->children[0].id;
        int id_2 = Node->children[2].id;


        bool condition1 = id_0 != id_2;

        bool condition2 = (id_0==DIGSEQ && id_2!= INTEGER) || (id_0==INTEGER && id_2!= DIGSEQ);     //因为上一个条件，所以等价于反过来
        bool condition3 = (id_0==REALNUMBER && id_2!= REAL) || (id_0==REAL && id_2!= REALNUMBER);

        bool condition4 = Node->children[0].is_array || Node->children[2].is_array;     //两者至少有一个为指针


        //相同类型即可
        if((condition1 && (condition2 || condition3)) || condition4)
        {
            Semantic_Error error("KindError", Node->children[1].line);
            SemanticErrorTable.push_back(error);
            Node->id = NONE;
        }else{
            if(Node->children[1].id==OR)
            {
                Node->id = BOOLEAN;
            }else
            {
                Node->id = Node->children[0].id;        //因为类型判断无所谓，所以不用区分类型放哪个
            }
        }

    }
}


//expression -> simple_expression  relop  simple_expression
//expression -> simple_expression
void expression(ATRNode *Node)
{
    if(Node->children.size()==1)
    {
        simple_expression(&Node->children[0]);
        Node->id = Node->children[0].id;
        Node->is_array = Node->children[0].is_array;
    } else
    {
        simple_expression(&Node->children[0]);
        relop(&Node->children[1]);
        simple_expression(&Node->children[2]);

        int id_0 = Node->children[0].id;
        int id_1 = Node->children[1].id;
        int id_2 = Node->children[2].id;


        bool condition1 = id_0 != id_2;

        bool condition2 = (id_0==DIGSEQ && id_2!= INTEGER) || (id_0==INTEGER && id_2!= DIGSEQ);     //因为上一个条件，所以等价于反过来
        bool condition3 = (id_0==REALNUMBER && id_2!= REAL) || (id_0==REAL && id_2!= REALNUMBER);

        bool condition4 = Node->children[0].is_array || Node->children[2].is_array;     //两者至少有一个为指针

        //相同类型即可
        if((condition1 && (condition2 || condition3)) || condition4)
        {
            Semantic_Error error("KindError", Node->children[1].line);
            SemanticErrorTable.push_back(error);
        }

        Node->id = BOOLEAN;
    }
}


//expression_list -> expression_list  ,  expression
//expression_list -> expression
//只用于参数匹配
void expression_list(ATRNode *Node)
{
    //参数匹配？？？
    if(Node->children.size()==1)
    {
        expression(&Node->children[0]);
        Node->param_count++;
    } else{
        expression_list(&Node->children[0]);
        expression(&Node->children[2]);
        Node->param_count += Node->children[0].param_count + 1;     //记录参数个数
    }
}


//else_part -> else statement
//else_part -> NULL
void else_part(ATRNode *Node)
{
    if(Node->children.size()>1) statement(&Node->children[1]);
}


//procedure_call -> id
//procedure_call -> id ( expression_list )
void procedure_call(ATRNode *Node)
{
    //区分过程和函数
    //检索符号表
    //参数数量匹配？？？
    T_item *item_pointer = TableSearch(Node->children[0].attr, TablePointer);


    if(item_pointer == nullptr)
    {
        Semantic_Error error("ProcedureOrFunctionNotFound", Node->children[0].line);
        SemanticErrorTable.push_back(error);
    } else{
        if(item_pointer->type==PROCEDURE)
        {
            Node->id = NONE;
            if(Node->children[2].param_count != item_pointer->dimension)
            {
                Semantic_Error error("ParamsCountNotMatch", Node->children[0].line);
                SemanticErrorTable.push_back(error);
            }

            if(Node->children.size()>1) expression_list(&Node->children[2]);
        }
        else if(item_pointer->type==FUNCTION)
        {
            Node->id = (*item_pointer->p)[0].type;  //获取返回值类型

            if(Node->children[2].param_count != item_pointer->dimension)
            {
                Semantic_Error error("ParamsCountNotMatch", Node->children[0].line);
                SemanticErrorTable.push_back(error);
            }

            if(Node->children.size()>1) expression_list(&Node->children[2]);
        }else{
            Semantic_Error error("KindError", Node->children[0].line);
            SemanticErrorTable.push_back(error);
        }
    }


}


//id_varpart -> [ expression_list ]
//id_varpart -> NULL
void id_varpart(ATRNode *Node)
{
    if(Node->children.size()>1)
    {
        expression_list(&Node->children[1]);
        /*
        //希望数组内的所有值都是int
        if(Node->children[1].id != INTEGER)
        {
            Semantic_Error error("KindError", Node->children[0].line);
            SemanticErrorTable.push_back(error);
        }
        */
        Node->is_array = true;
    }
}


//variable -> id id_varpart
void variable(ATRNode *Node)
{

    id_varpart(&Node->children[1]);

    //检索符号表
    T_item *item_pointer = TableSearch(Node->children[0].attr, TablePointer);
    if(item_pointer== nullptr)   //如果不存在
    {
        Semantic_Error error("IdNotFound", Node->children[0].line);
        SemanticErrorTable.push_back(error);
        Node->id = NONE;
    } else{
        if((item_pointer->dimension>0 && Node->children[1].is_array) || (item_pointer->dimension==0 && !Node->children[1].is_array)) //常量
        {
            Node->id = item_pointer->type;
        }
        else if(item_pointer->dimension>0 && !Node->children[1].is_array)//指针
        {
            Node->id = item_pointer->type;
            Node->is_array = true;
        }
        else if(item_pointer->dimension==0 && Node->children[1].is_array)//常量加[]
        {
            Semantic_Error error("KindArray", Node->children[0].line);
            SemanticErrorTable.push_back(error);

            Node->id = item_pointer->type;
            Node->is_array = true;

        }
    }



}


//variable_list -> variable_list , variable
//variable_list -> variable
void variable_list(ATRNode *Node)
{
    if(Node->children.size()==1)
    {
        variable(&Node->children[0]);
    } else{
        variable_list(&Node->children[0]);
        variable(&Node->children[2]);
    }
}


//statement -> variable  assignop  expression
//statement -> procedure_call
//statement -> compound_statement
//statement -> if  expression  then statement else_part
//statement -> for  id  assignop  expression   to  expression   do  statement
//statement -> read ( variable_list  )
//statement -> write ( expression_list )
//statement -> NULL
void statement(ATRNode *Node)
{
    string attr = Node->children[0].attr;
    if(attr == "variable")
    {
        //先获取变量类型
        variable(&Node->children[0]);
        expression(&Node->children[2]);

        //可以赋值的情况为两者都是类型,切都为指针或者非指针,还要不为函数和过程类型

        int id_0 = Node->children[0].id;
        int id_1 = Node->children[1].id;
        int id_2 = Node->children[2].id;

        bool condition1 = id_0 != id_2;

        bool condition2 = (id_0==DIGSEQ && id_2!= INTEGER) || (id_0==INTEGER && id_2!= DIGSEQ);     //因为上一个条件，所以等价于反过来
        bool condition3 = (id_0==REALNUMBER && id_2!= REAL) || (id_0==REAL && id_2!= REALNUMBER);

        bool condition4 = Node->children[0].is_array || Node->children[2].is_array;     //两者至少有一个为指针


        bool is_pro_or_func_1 = id_0 == PROCEDURE || id_0 == FUNCTION;



        if((condition1 && (condition2 || condition3)) || condition4 || is_pro_or_func_1)
        {
            Semantic_Error error("AssignError", Node->children[1].line);
            SemanticErrorTable.push_back(error);
        }

    }
    else if(attr == "procedure_call")
    {
        procedure_call(&Node->children[0]);
    }
    else if(attr == "compound_statement")
    {
        compound_statement(&Node->children[0]);
    }
    else if(attr == "if")
    {
        expression(&Node->children[1]);
        statement(&Node->children[3]);
        else_part(&Node->children[4]);
    }
    else if(attr == "for")
    {
        //三者要类型一致
        expression(&Node->children[3]);
        expression(&Node->children[5]);

        //检索符号表
        T_item *item_pointer = TableSearch(Node->children[1].attr, TablePointer);
        if(item_pointer == nullptr)   //如果不存在
        {
            Semantic_Error error("IdNotFound", Node->children[0].line);
            SemanticErrorTable.push_back(error);
        } else{

            //判断是否符合for循环规则，需要整数，不能为指针变量
            bool is_array = item_pointer->dimension>0;
            int type = item_pointer->type;
            bool long_flag = type != INTEGER || Node->children[3].id != INTEGER || Node->children[5].id != INTEGER || is_array || Node->children[3].is_array || Node->children[5].is_array;
            if(long_flag)
            {
                Semantic_Error error("AssignError", Node->children[1].line);
                SemanticErrorTable.push_back(error);
            }

        }





        statement(&Node->children[7]);

    }
    else if(attr == "read")
    {
        variable_list(&Node->children[2]);
    }
    else if(attr == "write")
    {
        expression_list(&Node->children[2]);
    }
}


//statement_list -> statement_list  ;  statement | statement
void statement_list(ATRNode *Node)
{
    if(Node->children.size()==1)
    {
        statement(&Node->children[0]);
    } else{
        statement_list(&Node->children[0]);
        statement(&Node->children[1]);
    }
}

//compound_statement -> begin statement_list  end
void compound_statement(ATRNode *Node)
{
    auto *sub_Table = new vector<T_item>;
    //创建子表，即作用域
    T_item title("_", NONE, 0, Node->children[1].line, TablePointer);
    sub_Table->push_back(title);

    vector<T_item> *pre = TablePointer; //记录上一张表
    TablePointer = sub_Table;       //改变表指针

    //先前表填写
    T_item temp("_", NONE, 0, Node->children[1].line, TablePointer);
    pre->push_back(temp);

    //执行代码
    statement_list(&Node->children[1]);

    //退出子表
    TablePointer = pre;

}

//subprogram_body -> const_declarations var_declarations compound_statement
void subprogram_body(ATRNode *Node)
{
    const_declarations(&Node->children[0]);
    var_declarations(&Node->children[1]);
    compound_statement(&Node->children[2]);
}

//subprogram -> subprogram_head   ;  subprogram_body
void subprogram(ATRNode *Node)
{
    subprogram_head(&Node->children[0]);
    subprogram_body(&Node->children[2]);

    TablePointer = (*TablePointer)[0].p;    //由头得到指向上一张子表的指针

}

//subprogram_declarations -> subprogram_declarations subprogram  ;
//subprogram_declarations -> NULL
void subprogram_declarations(ATRNode *Node)
{
    if(Node->children.size()>1)
    {
        subprogram_declarations(&Node->children[0]);
        subprogram(&Node->children[1]);
    }
}

//program_body -> const_declarations var_declarations subprogram_declarations compound_statement
void program_body(ATRNode *Node)
{
    const_declarations(&Node->children[0]);
    var_declarations(&Node->children[1]);
    subprogram_declarations(&Node->children[2]);
    compound_statement(&Node->children[3]);
}


//program_head -> program id ( idlist ) | program id
void program_head(ATRNode *Node)
{
    if(Node->children.size()>2) idlist(&Node->children[3]);
}

//programstruct -> program_head ; program_body .
void programstruct(ATRNode *Node)
{
    program_head(&Node->children[0]);
    program_body(&Node->children[2]);
}

//num -> digseq | realnumber
void num(ATRNode *Node)
{
    Node->id = Node->children[0].id;
    Node->attr = Node->children[0].attr;
}

//relop -> > | = | < | <= | >= | <>
void relop(ATRNode *Node)
{
    Node->id = Node->children[0].id;
    Node->attr = Node->children[0].attr;
}

//addop -> + | - | or
void addop(ATRNode *Node)
{
    Node->id = Node->children[0].id;
    Node->attr = Node->children[0].attr;
}

//mulop -> * | / | mod | and | div
void mulop(ATRNode *Node)
{
    Node->id = Node->children[0].id;
    Node->attr = Node->children[0].attr;
}



//自底向上搜索表
T_item* TableSearch(const string& name, vector<T_item> *pointer)
{
    T_item* res = nullptr;

    for(auto & i : *pointer)
    {
        if(i.name == name)
        {
            res = &i;
            break;
        }
    }

    if(res == nullptr && pointer != &SymbolTable)
    {
        vector<T_item> *next_pointer = (*pointer)[0].p;
        res = TableSearch(name, next_pointer);
    }

    return res;

}


#endif //COMPLIER_METHODS_H
