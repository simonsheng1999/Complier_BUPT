#include <fstream>
#include "compile.h"
#include "yacc.tab.h"

// 函数声明
vector<T_item> SymbolTable;
vector<T_item> * curTable = &SymbolTable;
vector<vector<T_item>> temp_tables;


// 错误处理函数
void exit_error();

void generate_1(const ATRNode & node);
void generate_2(const ATRNode & node);
void generate_3(const ATRNode & node);
void generate_4(const ATRNode & node);
int generate_5(const ATRNode & node, const TYPE_info & type_info);
int generate_6(const ATRNode & node, const TYPE_info & type_info);
void generate_7(const ATRNode & node);
void generate_8(const ATRNode & node);
void generate_9(const ATRNode & node);
void generate_10(const ATRNode & node);
void generate_15(const ATRNode & node);
void generate_16(const ATRNode & node);
void generate_17(const ATRNode & node);
void generate_18(const ATRNode & node);
TYPE_info generate_19(const ATRNode & node);
TYPE_info generate_20(const ATRNode & node);
TYPE_info generate_21(const ATRNode & node);
void generate_25(const ATRNode & node, TYPE_info & type_info);
void generate_26(const ATRNode & node, TYPE_info & type_info);
void generate_27(const ATRNode & node);
void generate_28(const ATRNode & node);
void generate_29(const ATRNode & node);
void generate_30(const ATRNode & node);
void generate_31(const ATRNode & node);
int generate_32(const ATRNode & node);
int generate_33(const ATRNode & node);
int generate_34(const ATRNode & node);
int generate_35(const ATRNode & node);
int generate_36(const ATRNode & node);
int generate_38(const ATRNode & node);
int generate_39(const ATRNode & node);
void generate_40(const ATRNode & node);
void generate_41(const ATRNode & node);
void generate_42(const ATRNode & node);
void generate_43(const ATRNode & node);
void generate_44(const ATRNode & node);
void generate_45(const ATRNode & node);
void generate_46(const ATRNode & node);
void generate_47(const ATRNode & node);
void generate_48(const ATRNode & node);
void generate_49(const ATRNode & node);
void generate_50(const ATRNode & node);
void generate_51(const ATRNode & node);
void generate_52(const ATRNode & node);
void generate_53(const ATRNode & node);
void generate_54(const ATRNode & node);
int generate_55(const ATRNode & node);
vector<T_item> generate_56(const ATRNode & node);
void generate_58(const ATRNode & node);
void generate_59(const ATRNode & node);
vector<T_item> generate_62(const ATRNode & node);
T_item generate_63(const ATRNode & node);
T_item generate_64(const ATRNode & node);
T_item generate_65(const ATRNode & node);
T_item generate_66(const ATRNode & node);
T_item generate_67(const ATRNode & node);
T_item generate_68(const ATRNode & node);
T_item generate_69(const ATRNode & node);
T_item generate_70(const ATRNode & node);
int generate_72(const ATRNode & node);
int generate_73(const ATRNode & node);
int generate_74(const ATRNode & node);
int generate_75(const ATRNode & node);


string show_type(int type)
{
    string str;
    switch(type)
    {
        case INTEGER:
            str = "integer";
            break;
        case REAL:
            str = "real";
            break;
        case CHAR:
            str = "char";
            break;
        case BOOLEAN:
            str = "boolean";
            break;
        case PROGRAM:
            str = "program";
            break;
        case FUNCTION:
            str = "function";
            break;
        case PROCEDURE:
            str = "procedure";
            break;
        default:
            str = "none";
            break;
    }
    return str;
}

void exit_error()
{
    cout << "semantic failed..." << endl;
    exit(100);
}

void init_temp_tables()
{
    for(int i=0; i < 100; i++)
    {
        vector<T_item> t;
        temp_tables.push_back(t);
    }
}

void print_stable()
{
    cout << "Symbol Table" << endl;
    printf("\n%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "ID", "TYPE", "DIMENSION", "LINE", "SUBTABLE");
    for(auto &i : SymbolTable)
    {
        printf("%-10s\t%-10s\t%-10d\t%-10d",i.name.c_str(), show_type(i.type).c_str(), i.dimension, i.line);
        if(i.p == nullptr)
        {
            printf("\t%-10s\n", "NO");
        }
        else
        {
            printf("\t%-10s\n\n", "YES");
            printf("%-10s%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "", "ID", "TYPE", "DIMENSION", "LINE", "SUBTABLE");
            for(auto &j: *i.p)
            {
                printf("%-10s", "");
                printf("%-10s\t%-10s\t%-10d\t%-10d\t%-10s\n",j.name.c_str(), show_type(j.type).c_str(),
                       j.dimension, j.line, "NO");
            }
            printf("\n");
        }
    }
}

// 针对函数调用的查找
T_item search_table(const string & name, int type)
{
    bool find_flag = false;
    T_item false_result("false", 0, 0, 0, nullptr);     // 找不到时的返回结果
    T_item result = false_result;   // 默认找不到
    for(auto & i : (*curTable))
    {
        if (name==i.name and i.type==type)
        {
            result = i;
            find_flag = true;
            break;
        }
    }
    if(find_flag)     // 已在当前子表中找到，或者只能在当前子表中查找，则返回结果
    {
        return result;
    }
    else        // 当前子表中未找到，且需要向外层表中查找
    {
        vector<T_item> * temp = curTable;   // 保存当前符号表指针
        curTable = (*curTable)[0].p;        // 上一层表
        bool find = false;
        while(curTable != nullptr)
        {
            result = search_table(name, true);
            if(result.name == "false")
            {
                curTable = (*curTable)[0].p;
            }
            else
            {
                find = true;    // 一旦找到，立刻返回
                break;
            }
        }
        if(!find)
        {
            result = false_result;
        }
        curTable = temp;    //恢复当前符号表指针
        return result;
    }
}

// 查找符号表中是否存在为 name 的项, only_cur_table: 只查询当前符号表，不向外层查询(重复定义判定)
T_item search_table(const string & name, bool only_cur_table)
{
    bool find_flag = false;
    T_item false_result("false", 0, 0, 0, nullptr);     // 找不到时的返回结果
    T_item result = false_result;   // 默认找不到
    for(auto & i : (*curTable))
    {
        if (name==i.name)
        {
            result = i;
            find_flag = true;
            break;
        }
    }
    if(find_flag or only_cur_table)     // 已在当前子表中找到，或者只能在当前子表中查找，则返回结果
    {
        return result;
    }
    else        // 当前子表中未找到，且需要向外层表中查找
    {
        vector<T_item> * temp = curTable;   // 保存当前符号表指针
        curTable = (*curTable)[0].p;        // 上一层表
        bool find = false;
        while(curTable != nullptr)
        {
            result = search_table(name, true);
            if(result.name == "false")
            {
                curTable = (*curTable)[0].p;
            }
            else
            {
                find = true;    // 一旦找到，立刻返回
                break;
            }
        }
        if(!find)
        {
            result = false_result;
        }
        curTable = temp;    //恢复当前符号表指针
        return result;
    }
}

// 在符号表中插入item表项 （只在变量定义时用到）
void insert_symbol_table(const T_item & item)
{
    T_item search_result = search_table(item.name, true);
    if(search_result.name == "false")
    {
        (*curTable).push_back(item);
    } else{
        // 重复定义错误
        cout << "Line " << item.line <<"\tredifinition：" << item.name <<endl;
        exit_error();
    }
}

// programstruct -> program_head  ；program_body .
void generate_1(const ATRNode & node)
{
    if(node.children[0].children.size()==2)
    {
        generate_3(node.children[0]);
    }
    else{
        generate_2(node.children[0]);
    }
    generate_4(node.children[2]);
}

// program_head -> program id 【创建子表】( idlist 【类型设置为空】【调用：类型传递】)
void generate_2(const ATRNode & node)
{
    ATRNode id = node.children[1];
    T_item item(id.attr, PROGRAM, 0, id.line, nullptr);
    insert_symbol_table(item);
    TYPE_info type_info(NONE, 0, nullptr);
    int id_count;
    if(node.children[3].children.size()==1)
    {
        id_count = generate_6(node.children[3], type_info);
    }
    else{
        id_count = generate_5(node.children[3], type_info);
    }
    (*curTable)[0].dimension = id_count;
}

// program_head -> program id
void generate_3(const ATRNode & node)
{
    ATRNode id = node.children[1];
    T_item item(id.attr, PROGRAM, 0, id.line, nullptr);
    insert_symbol_table(item);
}

/*
 * program_body ->  const_declarations
 *                  var_declarations
 *                  subprogram_declarations
 *                  compound_statement
 * */

void generate_4(const ATRNode & node)
{
    if(node.children[0].children.empty())
    {
        generate_8(node.children[0]);
    }
    else{
        generate_7(node.children[0]);
    }
    if(node.children[1].children.empty())
    {
        generate_16(node.children[1]);
    }
    else{
        generate_15(node.children[1]);
    }
    if(node.children[2].children.empty())
    {
        generate_28(node.children[2]);
    }
    else{
        generate_27(node.children[2]);
    }
    generate_41(node.children[3]);
}

// idlist -> idlist , id  【类型传递】【写入符号表】【调用：类型传递】
int generate_5(const ATRNode & node, const TYPE_info & type_info)
{
    int id_count = 1;
    if(node.children[0].children.size()==1)
    {
        id_count += generate_6(node.children[0], type_info);
    }
    else{
        id_count += generate_5(node.children[0], type_info);
    }
    ATRNode id = node.children[2];
    T_item item(id.attr, type_info.type, type_info.dim, id.line, type_info.p);
    insert_symbol_table(item);
    return id_count;
}

// idlist -> id  【类型传递】【写入符号表】
int generate_6(const ATRNode & node, const TYPE_info & type_info)
{
    ATRNode id = node.children[0];
    T_item item(id.attr, type_info.type, type_info.dim, id.line, type_info.p);
    insert_symbol_table(item);
    return 1;
}

// const_declarations -> const  const_declaration  ;
void generate_7(const ATRNode & node)
{
    if(node.children[1].children.size()==3)
    {
        generate_10(node.children[1]);
    }
    else{
        generate_9(node.children[1]);
    }
}

// const_declarations ->
void generate_8(const ATRNode & node)
{}

// const_declaration -> const_declaration ;  id = const_value  【类型传递】【写入符号表】
void generate_9(const ATRNode & node)
{
    if(node.children[0].children.size()==3)
    {
        generate_10(node.children[0]);
    }
    else{
        generate_9(node.children[0]);
    }
    ATRNode id = node.children[2];
    ATRNode value = node.children[4];
    int type;
    if(value.children.size()==3)
    {
        type = CHAR;
    }
    else if(value.children.size()==1)
    {
        ATRNode num = value.children[0];
        if(num.children[0].attr == "digits")
        {
            type = INTEGER;
        }
        else
        {
            type = REAL;
        }
    }
    else
    {
        ATRNode num = value.children[1];
        if(num.children[0].attr == "digits")
        {
            type = INTEGER;
        }
        else
        {
            type = REAL;
        }
    }
    T_item item(id.attr, type, 0, id.line, nullptr);
    insert_symbol_table(item);
}

// const_declaration -> id = const_value  【类型传递】【写入符号表】
void generate_10(const ATRNode & node)
{
    ATRNode id = node.children[0];
    ATRNode value = node.children[2];
    int type;
    if(value.children.size()==3)
    {
        type = CHAR;
    }
    else if(value.children.size()==1)
    {
        ATRNode num = value.children[0];
        if(num.children[0].id == DIGSEQ)
        {
            type = INTEGER;
        }
        else
        {
            type = REAL;
        }
    }
    else
    {
        ATRNode num = value.children[1];
        if(num.children[0].id == DIGSEQ)
        {
            type = INTEGER;
        }
        else
        {
            type = REAL;
        }
    }
    T_item item(id.attr, type, 0, id.line, nullptr);
    insert_symbol_table(item);
}

// var_declarations -> var  var_declaration ;
void generate_15(const ATRNode & node)
{
    if(node.children[1].children.size()==3)
    {
        generate_18(node.children[1]);
    } else{
        generate_17(node.children[1]);
    }
}

// var_declarations ->
void generate_16(const ATRNode & node)
{}

// var_declaration -> var_declaration  ;  idlist  :  type  【类型传递】【调用：类型传递】
void generate_17(const ATRNode & node)
{
    if(node.children[0].children.size()==3)
    {
        generate_18(node.children[0]);
    }
    else{
        generate_17(node.children[0]);
    }
    TYPE_info type_info(NONE, 0, nullptr);
    if(node.children[4].children.size()==1)
    {
        type_info = generate_19(node.children[4]);
    } else{
        type_info = generate_20(node.children[4]);
    }
    if(node.children[2].children.size()==1)
    {
        generate_6(node.children[2], type_info);
    }
    else{
        generate_5(node.children[2], type_info);
    }
}

// var_declaration -> idlist  :  type  【类型传递】【调用：类型传递】
void generate_18(const ATRNode & node)
{
    TYPE_info type_info(NONE, 0, nullptr);
    if(node.children[2].children.size()==1)
    {
        type_info = generate_19(node.children[2]);
    }
    else{
        type_info = generate_20(node.children[2]);
    }
    if(node.children[0].children.size()==1)
    {
        generate_6(node.children[0], type_info);
    }
    else{
        generate_5(node.children[0], type_info);
    }
}

// type -> basic_type  【类型传递】
TYPE_info generate_19(const ATRNode & node)
{
    return generate_21(node.children[0]);
}

// type -> array  【创建数组子表】[  period  ] 【退出数组子表】 of  basic_type  【类型传递】
TYPE_info generate_20(const ATRNode & node)
{
    TYPE_info type_info = generate_21(node.children[5]);
    vector<T_item> t;
    temp_tables.push_back(t);
    vector<T_item>* para_table = & temp_tables[temp_tables.size()-1];
    type_info.p = para_table;
    if(node.children[2].children.size()==3)
    {
        generate_26(node.children[2], type_info);
    }
    else
    {
        generate_25(node.children[2], type_info);
    }
    return type_info;
}

// basic_type -> integer | real | boolean | char 【类型传递】
TYPE_info generate_21(const ATRNode & node)
{
    ATRNode type = node.children[0];
    if(type.attr=="integer")
    {
        TYPE_info type_info(INTEGER, 0, nullptr);
        return type_info;
    }
    else if(type.attr=="real")
    {
        TYPE_info type_info(REAL, 0, nullptr);
        return type_info;
    }
    else if(type.attr=="boolean")
    {
        TYPE_info type_info(BOOLEAN, 0, nullptr);
        return type_info;
    }
    else if(type.attr=="char")
    {
        TYPE_info type_info(CHAR, 0, nullptr);
        return type_info;
    }
    else{
        TYPE_info type_info(NONE, 0, nullptr);
        cout << "Line " << type.line << "\tbasic_type is illegal" <<endl;
        exit_error();
        return type_info;
    }
}

// period -> period ， digits .. digits  【维度+1】【范围保存】
void generate_25(const ATRNode & node, TYPE_info & type_info)
{
    if(node.children[0].children.size()==3)
    {
        generate_26(node.children[0], type_info);
    }
    else
    {
        generate_25(node.children[0], type_info);
    }
    int start_index = stoi(node.children[2].attr);
    int end_index = stoi(node.children[4].attr);
    T_item item("", start_index, end_index, 0, nullptr);
    type_info.dim += 1;
    type_info.p->push_back(item);
}

// period -> digits .. digits  （常整数） 【维度设为1】【范围保存】
void generate_26(const ATRNode & node, TYPE_info & type_info)
{
    int start_index = stoi(node.children[0].attr);
    int end_index = stoi(node.children[2].attr);
    T_item item("", start_index, end_index, 0, nullptr);
    type_info.dim = 1;
    type_info.p->push_back(item);
}

/*
 * subprogram_declarations -> subprogram_declarations
 *                            subprogram  ;
 */
void generate_27(const ATRNode & node)
{
    if(node.children[0].children.empty())
    {
        generate_28(node.children[0]);
    }
    else{
        generate_27(node.children[0]);
    }
    generate_29(node.children[1]);
}

// subprogram_declarations ->
void generate_28(const ATRNode & node)
{}

// subprogram -> subprogram_head   ;  subprogram_body 【退出子表】
void generate_29(const ATRNode & node)
{
    if(node.children[0].children.size()==3)
    {
        generate_30(node.children[0]);
    }
    else
    {
        generate_31(node.children[0]);
    }
    generate_40(node.children[2]);
    // 退出子表
    curTable = (*curTable)[0].p;
}

// subprogram_head -> procedure  id 【创建子表并填写id】 formal_parameter
void generate_30(const ATRNode & node)
{
    ATRNode id = node.children[1];
    vector<T_item> t;
    temp_tables.push_back(t);
    vector<T_item>* prod_table = &temp_tables[temp_tables.size()-1];
    T_item head_item(id.attr, NONE, 0, id.line, curTable);
    prod_table->push_back(head_item);
    T_item item(id.attr, PROCEDURE, 0, id.line, prod_table);
    insert_symbol_table(item);
    curTable = item.p;  // 进入子表
    int param_count;
    if(node.children[2].children.empty())
    {
        param_count = generate_33(node.children[2]);
    }
    else
    {
        param_count = generate_32(node.children[2]);
    }
    vector<T_item> * temp = (*curTable)[0].p;
    (*temp)[(*temp).size() - 1].dimension = param_count;    //统计参数数目
}

// subprogram_head -> function  id  【创建子表并填写id】formal_parameter  :  basic_type
void generate_31(const ATRNode & node)
{
    ATRNode id = node.children[1];
    TYPE_info type_info = generate_21(node.children[4]);
    vector<T_item> t;
    temp_tables.push_back(t);
    vector<T_item> * func_table = & temp_tables[temp_tables.size()-1];
    T_item head_item(id.attr, type_info.type, 0, id.line, curTable);
    func_table->push_back(head_item);
    T_item item(id.attr, FUNCTION, 0, id.line, func_table);
    insert_symbol_table(item);
    curTable = item.p;      //进入子表
    int param_count;
    if(node.children[2].children.empty())
    {
        param_count = generate_33(node.children[2]);
    }
    else
    {
        param_count = generate_32(node.children[2]);
    }
    vector<T_item> * temp = (*curTable)[0].p;
    (*temp)[(*temp).size() - 1].dimension = param_count;
}

// formal_parameter -> (  parameter_list  )
int generate_32(const ATRNode & node)
{
    int param_count;
    if(node.children[1].children.size()==1)
    {
        param_count = generate_35(node.children[1]);
    }
    else
    {
        param_count = generate_34(node.children[1]);
    }
    return param_count;
}

// formal_parameter ->   【参数个数为0并填入主表]
int generate_33(const ATRNode & node)
{
    return 0;
}

// parameter_list -> parameter_list  ;  parameter  【维度+1】
int generate_34(const ATRNode & node)
{
    int param_count;
    if(node.children[0].children.size()==1)
    {
        param_count = generate_35(node.children[0]);
    }
    else
    {
        param_count = generate_34(node.children[0]);
    }
    param_count += generate_36(node.children[2]);
    return param_count;
}

// parameter_list -> parameter  【维度设为1】
int generate_35(const ATRNode & node)
{
    return generate_36(node.children[0]);
}

// parameter -> var_parameter  |  value_parameter
int generate_36(const ATRNode & node)
{
    int param_count;
    if(node.children[0].children.size()==2)
    {
        param_count = generate_38(node.children[0]);
    }
    else
    {
        param_count = generate_39(node.children[0]);
    }
    return param_count;
}

// var_parameter -> var  value_parameter
int generate_38(const ATRNode & node)
{
    return generate_39(node.children[1]);
}

// value_parameter -> idlist  :  basic_type  【类型传递】【调用：类型传递】
int generate_39(const ATRNode & node)
{
    TYPE_info type_info = generate_21(node.children[2]);
    int param_count;
    if(node.children[0].children.size()==1)
    {
        param_count = generate_6(node.children[0], type_info);
    } else{
        param_count = generate_5(node.children[0], type_info);
    }
    return param_count;
}

/*
 * subprogram_body ->   const_declarations
 *                      var_declarations
 *                      compound_statement
 */
void generate_40(const ATRNode & node)
{
    if(node.children[0].children.empty())
    {
        generate_8(node.children[0]);
    }
    else{
        generate_7(node.children[0]);
    }
    if(node.children[1].children.empty())
    {
        generate_16(node.children[1]);
    }
    else{
        generate_15(node.children[1]);
    }
    generate_41(node.children[2]);
}

// compound_statement -> begin statement_list  end
void generate_41(const ATRNode & node)
{
    if(node.children[1].children.size()==1)
    {
        generate_43(node.children[1]);
    }
    else
    {
        generate_42(node.children[1]);
    }
}

// statement_list -> statement_list  ;  statement
void generate_42(const ATRNode & node)
{
    if(node.children[0].children.size()==1)
    {
        generate_43(node.children[0]);
    }
    else
    {
        generate_42(node.children[0]);
    }

    ATRNode first_node = node.children[2];
    if(first_node.children.empty())
    {
        generate_52(first_node);
    }
    else if(first_node.children[0].attr=="variable")
    {
        generate_44(first_node);
    }
    else if(first_node.children[0].attr=="procedure_call")
    {
        generate_45(first_node);
    }
    else if(first_node.children[0].attr=="compound_statement")
    {
        generate_46(first_node);
    }
    else if(first_node.children[0].attr=="if")
    {
        generate_47(first_node);
    }
    else if(first_node.children[0].attr=="for")
    {
        generate_48(first_node);
    }
    else if(first_node.children[0].attr=="while")
    {
        generate_49(first_node);
    }
    else if(first_node.children[0].attr=="read")
    {
        generate_50(first_node);
    }
    else if(first_node.children[0].attr=="write")
    {
        generate_51(first_node);
    }
}

// statement_list -> statement
void generate_43(const ATRNode & node)
{
    ATRNode first_node = node.children[0];
    if(first_node.children.empty())
    {
        generate_52(first_node);
    }
    else if(first_node.children[0].attr=="variable")
    {
        generate_44(first_node);
    }
    else if(first_node.children[0].attr=="procedure_call")
    {
        generate_45(first_node);
    }
    else if(first_node.children[0].attr=="compound_statement")
    {
        generate_46(first_node);
    }
    else if(first_node.children[0].attr=="if")
    {
        generate_47(first_node);
    }
    else if(first_node.children[0].attr=="for")
    {
        generate_48(first_node);
    }
    else if(first_node.children[0].attr=="while")
    {
        generate_49(first_node);
    }
    else if(first_node.children[0].attr=="read")
    {
        generate_50(first_node);
    }
    else if(first_node.children[0].attr=="write")
    {
        generate_51(first_node);
    }
}

// statement -> variable  assignop  expression  【类型检查】
void generate_44(const ATRNode & node)
{
    int type1 = generate_55(node.children[0]);
    int type2;
    if(node.children[2].children.size()==1)
    {
        type2 = generate_65(node.children[2]).type;
    }
    else{
        type2 = generate_64(node.children[2]).type;
    }
    if(type1 != type2)
    {
        cout << "Line " << node.children[0].children[0].line << "\tAssignment Statement types do not match: "
        << show_type(type1) << " and " << show_type(type2) << endl;
        exit_error();
    }
}

// statement -> procedure_call
void generate_45(const ATRNode & node)
{
    if(node.children[0].children.size() == 1)
    {
        generate_58(node.children[0]);
    }
    else
    {
        generate_59(node.children[0]);
    }
}

// statement -> 【创建子表】compound_statement 【退出子表】
void generate_46(const ATRNode & node)
{
    /*vector<T_item> block_table;
    T_item item("_", NONE, 0, 0, &block_table);
    insert_symbol_table(item);
    T_item item1("_", NONE, 0, 0, curTable);
    curTable = item.p;
    insert_symbol_table(item1);*/
    generate_41(node.children[0]);
    /*curTable = (*curTable)[0].p;*/
}

// statement -> if  expression  then statement  else_part
void generate_47(const ATRNode & node)
{
    int type;
    if(node.children[1].children.size()==1)
    {
        type = generate_65(node.children[1]).type;
    }
    else
    {
        type = generate_64(node.children[1]).type;
    }
    if(type != BOOLEAN)
    {
        cout << "Line " << node.children[0].line << "\tAfter if must be boolean: " << endl;
        exit_error();
    }
    else
    {
        ATRNode first_node = node.children[3];
        if(first_node.children.empty())
        {
            generate_52(first_node);
        }
        else if(first_node.children[0].attr=="variable")
        {
            generate_44(first_node);
        }
        else if(first_node.children[0].attr=="procedure_call")
        {
            generate_45(first_node);
        }
        else if(first_node.children[0].attr=="compound_statement")
        {
            generate_46(first_node);
        }
        else if(first_node.children[0].attr=="if")
        {
            generate_47(first_node);
        }
        else if(first_node.children[0].attr=="for")
        {
            generate_48(first_node);
        }
        else if(first_node.children[0].attr=="while")
        {
            generate_49(first_node);
        }
        else if(first_node.children[0].attr=="read")
        {
            generate_50(first_node);
        }
        else if(first_node.children[0].attr=="write")
        {
            generate_51(first_node);
        }
        if(!node.children[4].children.empty())
        {
            ATRNode second_node = node.children[4].children[1];
            if(second_node.children.empty())
            {
                generate_52(second_node);
            }
            else if(second_node.children[0].attr=="variable")
            {
                generate_44(second_node);
            }
            else if(second_node.children[0].attr=="procedure_call")
            {
                generate_45(second_node);
            }
            else if(second_node.children[0].attr=="compound_statement")
            {
                generate_46(second_node);
            }
            else if(second_node.children[0].attr=="if")
            {
                generate_47(second_node);
            }
            else if(second_node.children[0].attr=="for")
            {
                generate_48(second_node);
            }
            else if(second_node.children[0].attr=="while")
            {
                generate_49(second_node);
            }
            else if(second_node.children[0].attr=="read")
            {
                generate_50(second_node);
            }
            else if(second_node.children[0].attr=="write")
            {
                generate_51(second_node);
            }
        }
    }
}

// statement -> for  id【检索符号表】  assignop  expression 【类型检查】  to  expression 【类型检查】  do  statement
void generate_48(const ATRNode & node)
{
    ATRNode id = node.children[1];
    T_item item1 = search_table(id.attr, false);
    if(item1.name == "false")
    {
        cout << "Line " << id.line << "\tundifined reference: " << id.attr << endl;
        exit_error();
    }
    else
    {
        T_item item2("", NONE, 0, 0, nullptr);
        if(node.children[3].children.size()==1)
        {
            item2 = generate_65(node.children[3]);
        }
        else
        {
            item2 = generate_64(node.children[3]);
        }
        T_item item3("", NONE, 0, 0, nullptr);
        if(node.children[5].children.size()==1)
        {
            item3 = generate_65(node.children[5]);
        }
        else
        {
            item3 = generate_64(node.children[5]);
        }
        if(item1.type != item2.type or item1.type != item3.type)
        {
            cout << "Line " << node.children[1].line << "\terror type for loop variable: "<< item1.name << endl;
            exit_error();
        }
        else
        {
            ATRNode first_node = node.children[7];
            if(first_node.children.empty())
            {
                generate_52(first_node);
            }
            else if(first_node.children[0].attr=="variable")
            {
                generate_44(first_node);
            }
            else if(first_node.children[0].attr=="procedure_call")
            {
                generate_45(first_node);
            }
            else if(first_node.children[0].attr=="compound_statement")
            {
                generate_46(first_node);
            }
            else if(first_node.children[0].attr=="if")
            {
                generate_47(first_node);
            }
            else if(first_node.children[0].attr=="for")
            {
                generate_48(first_node);
            }
            else if(first_node.children[0].attr=="while")
            {
                generate_49(first_node);
            }
            else if(first_node.children[0].attr=="read")
            {
                generate_50(first_node);
            }
            else if(first_node.children[0].attr=="write")
            {
                generate_51(first_node);
            }
        }
    }
}

// statement -> while expression do statement
void generate_49(const ATRNode & node)
{
    T_item item("", NONE, 0, 0, nullptr);
    if(node.children[1].children.size()==1)
    {
        item = generate_65(node.children[1]);
    }
    else
    {
        item = generate_64(node.children[1]);
    }
    if(item.type != BOOLEAN)
    {
        cout << "Line " << node.children[0].line << "\tAfter while must be boolean: " << endl;
        exit_error();
    }
    else
    {
        ATRNode first_node = node.children[3];
        if(first_node.children.empty())
        {
            generate_52(first_node);
        }
        else if(first_node.children[0].attr=="variable")
        {
            generate_44(first_node);
        }
        else if(first_node.children[0].attr=="procedure_call")
        {
            generate_45(first_node);
        }
        else if(first_node.children[0].attr=="compound_statement")
        {
            generate_46(first_node);
        }
        else if(first_node.children[0].attr=="if")
        {
            generate_47(first_node);
        }
        else if(first_node.children[0].attr=="for")
        {
            generate_48(first_node);
        }
        else if(first_node.children[0].attr=="while")
        {
            generate_49(first_node);
        }
        else if(first_node.children[0].attr=="read")
        {
            generate_50(first_node);
        }
        else if(first_node.children[0].attr=="write")
        {
            generate_51(first_node);
        }
    }
}

// statement -> read ( variable_list  )
void generate_50(const ATRNode & node)
{
    if(node.children[2].children.size()==1)
    {
        generate_54(node.children[2]);
    }
    else
    {
        generate_53(node.children[2]);
    }
}

// statement -> write ( expression_list )
void generate_51(const ATRNode & node)
{
    if(node.children[2].children.size()==1)
    {
        generate_63(node.children[2]);
    }
    else
    {
        generate_62(node.children[2]);
    }
}

//
void generate_52(const ATRNode & node)
{}

// variable_list -> variable_list , variable
void generate_53(const ATRNode & node)
{
    if(node.children[0].children.size() == 1)
    {
        generate_54(node.children[0]);
    }
    else
    {
        generate_53(node.children[0]);
    }
    generate_55(node.children[2]);
}

// variable_list -> variable
void generate_54(const ATRNode & node)
{
    generate_55(node.children[0]);
}

// variable -> id【检索符号表】 id_varpart 【参数计算，类型匹配】
int generate_55(const ATRNode & node)
{
    ATRNode id = node.children[0];
    T_item item = search_table(id.attr, false);
    if(item.name == "false")
    {
        cout << "Line " << id.line << "\tundefined reference: " << id.attr << endl;
        exit_error();
    }
    else{
        if(node.children[1].children.empty())
        {
            if(item.dimension!=0)
            {
                cout << "Line " << id.line << "\tIllegal number of parameters for array: " << id.attr << endl;
                exit_error();
            }
        }
        else if(item.dimension==0)
        {
            cout << "Line " << id.line << "\tNot array: " << item.name  << endl;
            exit_error();
        }
        else
        {
            vector<T_item> param_list = generate_56(node.children[1]);
            vector<T_item> index_list = *(item.p);
            if(param_list.size() != index_list.size())
            {
                cout << "Line " << id.line << "\tIllegal number of parameters for array: " << item.name << endl;
                exit_error();
            }
            else
            {
                for(auto & i : param_list)
                {
                    if(i.type != INTEGER)
                    {
                        cout << "Line " << id.line << "\tIllegal type index for array: " << item.name << endl;
                        exit_error();
                    }
                    // 数组范围检查
                }
            }
        }
    }
    return item.type;
}

// id_varpart -> [ expression_list ]
vector<T_item> generate_56(const ATRNode & node)
{
    if(node.children[1].children.size()==1)
    {
        vector<T_item> item;
        item.push_back(generate_63(node.children[1]));
        return item;
    }
    else
    {
        return generate_62(node.children[1]);
    }
}

// procedure_call -> id 【检索符号表】
void generate_58(const ATRNode & node)
{
    ATRNode id = node.children[0];
    T_item item = search_table(id.attr, PROCEDURE);
    if(item.name == "false")
    {
        cout << "Line " << id.line << "\tundefined procedure call: " << id.attr << endl;
        exit_error();
    }
}

// procedure_call -> id 【检索符号表】( expression_list【调用：参数匹配】 )
void generate_59(const ATRNode & node)
{
    ATRNode id = node.children[0];
    T_item item = search_table(id.attr, PROCEDURE);
    if(item.name == "false")
    {
        cout << "Line " << id.line << "\tundefined function call: " << id.attr << endl;
        exit_error();
    }
    else
    {
        vector<T_item> param_table = *(item.p);
        vector<T_item> param_list;
        if(node.children[2].children.size() == 1)
        {
            param_list.push_back(generate_63(node.children[2]));
        }
        else
        {
            param_list = generate_62(node.children[2]);
        }
        if(param_list.size() != item.dimension)
        {
            cout << "Line " << id.line << "\tWrong number of parameters for procedure: " << item.name  << endl;
            exit_error();
        }
        else{
            for(int i=0; i<item.dimension; i++)
            {
                if(param_list[i].type != param_table[i+1].type)
                {
                    cout << "Line " << id.line << "\t" << item.name << "\tWrong type parameter: " << i+1 << endl;
                    exit_error();
                }
            }
        }
    }
}

// expression_list -> expression_list  ,  expression  【参数匹配】【调用：参数匹配】
vector<T_item> generate_62(const ATRNode & node)
{
    vector<T_item> item;
    if(node.children[0].children.size()==1)
    {
        item.push_back(generate_63(node.children[0]));
    }
    else
    {
        item = generate_62(node.children[0]);
    }
    if(node.children[2].children.size()==1)
    {
        item.push_back(generate_65(node.children[2]));
    }
    else
    {
        item.push_back(generate_64(node.children[2]));
    }
    return item;
}

// expression_list -> expression  【参数匹配】
T_item generate_63(const ATRNode & node)
{
    if(node.children[0].children.size()==1)
    {
        return generate_65(node.children[0]);
    }
    else
    {
        return generate_64(node.children[0]);
    }
}

// expression -> simple_expression  relop  simple_expression 【类型检查】【布尔类型传递】
T_item generate_64(const ATRNode & node)
{
    T_item item1("", NONE, 0, 0, nullptr);
    T_item item2("", NONE, 0, 0, nullptr);
    if(node.children[0].children.size()==1)
    {
        item1 = generate_67(node.children[0]);
    }
    else
    {
        item1 = generate_66(node.children[0]);
    }
    if(node.children[2].children.size()==1)
    {
        item2 = generate_67(node.children[2]);
    }
    else
    {
        item2 = generate_66(node.children[2]);
    }
    if(item1.type == item2.type and (item1.type == INTEGER or item1.type == REAL))
    {
        T_item item("", BOOLEAN, 0, 0, nullptr);
        return item;
    }
    else
    {
        cout << "Line " << node.children[1].children[0].line << "\twrong type for relop: "
        << node.children[1].children[0].attr << endl;
        exit_error();
        T_item item("", NONE, 0, 0, nullptr);
        return item;
    }
}

// expression -> simple_expression  【类型传递】
T_item generate_65(const ATRNode & node)
{
    if(node.children[0].children.size()==1)
    {
        return generate_67(node.children[0]);
    }
    else
    {
        return generate_66(node.children[0]);
    }
}

// simple_expression -> simple_expression  addop term  【类型检查】【类型传递】
T_item generate_66(const ATRNode & node)
{
    ATRNode add_op = node.children[1].children[0];
    T_item item1("", NONE, 0, 0, nullptr);
    T_item item2("", NONE, 0, 0, nullptr);
    if(node.children[0].children.size()==1)
    {
        item1 = generate_67(node.children[0]);
    }
    else
    {
        item1 = generate_66(node.children[0]);
    }
    if(node.children[2].children.size()==1)
    {
        item2 = generate_69(node.children[2]);
    }
    else
    {
        item2 = generate_68(node.children[2]);
    }
    if(item1.type == item2.type and (item1.type == INTEGER or item1.type == REAL))
    {
        T_item item("", item1.type, 0, 0, nullptr);
        return item;
    }
    else
    {
        cout << "Line " << add_op.line << "\twrong type: " << add_op.attr << endl;
        exit_error();
        T_item item("", NONE, 0, 0, nullptr);
        return item;
    }
}

// simple_expression -> term  【类型传递】
T_item generate_67(const ATRNode & node)
{
    if(node.children[0].children.size()==1)
    {
        return generate_69(node.children[0]);
    }
    else
    {
        return generate_68(node.children[0]);
    }
}

// term -> term  mulop  factor  【类型检查】【类型传递】
T_item generate_68(const ATRNode & node)
{
    int type1, type2, type;
    if(node.children[0].children.size()==1)
    {
        type1 = generate_69(node.children[0]).type;
    }
    else
    {
        type1 = generate_68(node.children[0]).type;
    }

    ATRNode factor = node.children[2];
    if(factor.children[0].attr == "num")
    {
        type2 = generate_70(factor).type;
    }
    else if(factor.children[0].attr == "variable")
    {
        type2 = generate_55(factor.children[0]);
    }
    else if(factor.children[0].id == IDENTIFIER)
    {
        type2 = generate_72(factor);
    }
    else if(factor.children[0].id == NOT)
    {
        type2 = generate_74(factor);
    }
    else if(factor.children[0].id == MINUS)
    {
        type2 = generate_75(factor);
    }
    else
    {
        type2 = generate_73(factor);
    }

    ATRNode mul_op = node.children[1].children[0];
    if(mul_op.attr == "mod" or mul_op.attr == "div")    //只能对整数取模
    {
        if(type1 == type2 and type1 == INTEGER)
        {
            type = INTEGER;
        }
        else
        {
            cout << "Line " << mul_op.line << "\tonly for integer" << endl;
            exit_error();
            type = NONE;
        }
    }
    else if(type1 == type2 and (type1 == REAL or type1 == INTEGER))
    {
        type = type1;
    }
    else
    {
        cout << "Line " << mul_op.line << "\twrong type for mulop" << mul_op.attr << endl;
        exit_error();
        type = NONE;
    }
    T_item item("", type, 0, 0, nullptr);
    return item;
}

// term -> factor  【类型传递】
T_item generate_69(const ATRNode & node)
{
    ATRNode factor = node.children[0];
    if(factor.children[0].attr == "num")
    {
        return generate_70(factor);
    }
    else if(factor.children[0].attr == "variable")
    {
        int type = generate_55(factor.children[0]);
        T_item item("", type, 0, 0, nullptr);
        return item;
    }
    else if(factor.children[0].id == IDENTIFIER)
    {
        int type = generate_72(factor);
        T_item item("", type, 0, 0, nullptr);
        return item;
    }
    else if(factor.children[0].id == NOT)
    {
        int type = generate_74(factor);
        T_item item("", type, 0, 0, nullptr);
        return item;
    }
    else if(factor.children[0].id == MINUS)
    {
        int type = generate_75(factor);
        T_item item("", type, 0, 0, nullptr);
        return item;
    }
    else
    {
        int type = generate_73(factor);
        T_item item("", type, 0, 0, nullptr);
        return item;
    }
}

// factor -> num  (常量)  【类型传递】
T_item generate_70(const ATRNode & node)
{
    ATRNode first_node = node.children[0];
    if(first_node.children[0].id==DIGSEQ)
    {
        T_item item("", INTEGER, 0, 0, nullptr);
        return item;
    }
    else
    {
        T_item item("", REAL, 0, 0, nullptr);
        return item;
    }
}

// factor -> id  【检索符号表】( expression_list 【调用：参数匹配】 )【类型传递】
int generate_72(const ATRNode & node)
{
    ATRNode id = node.children[0];
    T_item item = search_table(id.attr, FUNCTION);
    if(item.name == "false")
    {
        cout << "Line " << id.line << "\tundefined reference: " << id.attr << endl;
        exit_error();
    }
    else
    {
        vector<T_item> param_table = *(item.p);
        vector<T_item> param_list;
        if(node.children[2].children.size() == 1)
        {
            param_list.push_back(generate_63(node.children[2]));
        }
        else
        {
            param_list = generate_62(node.children[2]);
        }
        if(param_list.size() != item.dimension)
        {
            cout << "Line " << id.line << "\tWrong number of parameters for function: " << item.name  << endl;
            exit_error();
        }
        else{
            for(int i=0; i<item.dimension; i++)
            {
                if(param_list[i].type != param_table[i+1].type)
                {
                    cout << "Line " << id.line << "\t" << item.name << "\tWrong type parameter: " << i+1 << endl;
                    exit_error();
                }
            }
        }
        return param_table[0].type;
    }
    return NONE;
}

// factor -> ( expression 【类型传递】)
int generate_73(const ATRNode & node)
{
    if(node.children[1].children.size()==1)
    {
        return generate_65(node.children[1]).type;
    }
    else
    {
        return generate_64(node.children[1]).type;
    }
}

// factor -> not  factor  【类型传递】
int generate_74(const ATRNode & node)
{
    int type;
    ATRNode factor = node.children[1];
    if(factor.children[0].attr == "num")
    {
        type = generate_70(factor).type;
    }
    else if(factor.children[0].attr == "variable")
    {
        type = generate_55(factor.children[0]);
    }
    else if(factor.children[0].id == IDENTIFIER)
    {
        type = generate_72(factor);
    }
    else if(factor.children[0].id == NOT)
    {
        type = generate_74(factor);
    }
    else if(factor.children[0].id == MINUS)
    {
        type = generate_75(factor);
    }
    else
    {
        type = generate_73(factor);
    }
    return type;
}

// factor -> uminus  factor  【类型传递】
int generate_75(const ATRNode & node)
{
    int type;
    ATRNode factor = node.children[1];
    if(factor.children[0].attr == "num")
    {
        type = generate_70(factor).type;
    }
    else if(factor.children[0].attr == "variable")
    {
        type = generate_55(factor.children[0]);
    }
    else if(factor.children[0].id == IDENTIFIER)
    {
        type = generate_72(factor);
    }
    else if(factor.children[0].id == NOT)
    {
        type = generate_74(factor);
    }
    else if(factor.children[0].id == MINUS)
    {
        type = generate_75(factor);
    }
    else
    {
        type = generate_73(factor);
    }
    return type;
}

// 主程序
void semantic(const ATRNode & node)
{
    init_temp_tables();
    generate_1(node);
}
