//lex.l和yacc.y共同使用的头文件
#ifndef COMPILE_HPP
#define COMPILE_HPP

#include <iostream>//使用C++库
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>//printf和FILE要用的

#define NONE -2

using namespace std;

extern "C"			//为了能够在C++程序里面调用C函数，必须把每一个需要使用的C函数，其声明都包括在extern "C"{}块里面，这样C++链接时才能成功链接它们。extern "C"用来在C++环境下设置C链接类型。
{				
    int yywrap(void);
	int yylex(void);	//这个是lex生成的词法分析函数，yacc的yyparse()里会调用它，如果这里不声明，生成的yacc.tab.c在编译时会找不到该函数
	void yyerror(const char *s);
	extern int yylex(void);//该函数是在lex.yy.c里定义的，yyparse()里要调用该函数，为了能编译和链接，必须用extern加以声明
}

/*当lex每识别出一个记号后，是通过变量yylval向yacc传递数据的。默认情况下yylval是int类型，也就是只能传递整型数据。
yylval是用YYSTYPE宏定义的，只要重定义YYSTYPE宏，就能重新指定yylval的类型(可参见yacc自动生成的头文件yacc.tab.h)。*/

struct ATRNode{
    int id;                     //记号
    string attr;                //属性
    int line;
    vector<ATRNode> children; //子节点vector

    ATRNode(){}

    ATRNode(int id, string attr, int line=0)
    {
        this->id = id;
        this->attr = std::move(attr);
        this->line = line;
    }
};

//符号表表项
struct T_item{
    string name;                //名称
    int type;                   //类型
    bool is_ref;                //是否为引用类型
    int dimension;              //维度
    int line;                   //声明行
    vector<T_item> *p;          //符号表指针

    T_item(string name, int type, int dimension, int line, vector<T_item> *p, bool is_ref=false)
    {
        this->name = std::move(name);
        this->type = type;
        this->is_ref = is_ref;
        this->dimension = dimension;
        this->line = line;
        this->p = p;
    }
};

// 储存type值
struct TYPE_info{
    int type;                   // 变量类型
    bool is_ref;                // 是否为引用型变量
    int dim;                    // 变量维度
    vector<T_item> *p;          // 符号表指针
    TYPE_info(int type, int dim, vector<T_item> *p, bool is_ref=false)
    {
        this->type = type;
        this->is_ref = is_ref;
        this->dim = dim;
        this->p = p;
    }
};

//符号表
extern vector<T_item> SymbolTable;
extern vector<vector<T_item>> temp_tables;
extern vector<T_item> * curTable;
extern ATRNode root_node;

ATRNode newNode(int, string, int);
void postorder_traversal(const ATRNode& Node);
int syntax_process(const char*);
void semantic(const ATRNode & node);
T_item search_table(const string & name, bool only_cur_table);
void insert_symbol_table(const T_item & item);
void print_stable();
void generate_code(ATRNode * node, const char* file_path);

#define YYSTYPE ATRNode     //把YYSTYPE(即yylval变量)重定义为struct类型，这样lex就能向yacc返回更多的数据了

#endif
