//
// Created by dell on 2020/5/29.
//

#ifndef COMPLIER_COMPLIER_H
#define COMPLIER_COMPLIER_H

#include <iostream>
#include <utility>
#include <vector>
#include <string>

#define   AND      1
#define   ARRAY      2
#define   CASE      3
#define   CONST      4
#define   DIV      5
#define   DO      6
#define   DOWNTO      7
#define   ELSE      8
#define   END      9

#define   EXTERNAL      10
#define   FOR      11
#define   FORWARD      12
#define   FUNCTION      13
#define   GOTO      14
#define   IF      15
#define   IN      16
#define   LABEL      17
#define   MOD      18
#define   NIL      19
#define   NOT      20
#define   OF       21
#define   OR      22
#define   OTHERWISE      23
#define   PACKED      24
#define   PBEGIN      25
#define   PFILE      26
#define   PROCEDURE      27
#define   PROGRAM      28
#define   RECORD      29
#define   REPEAT      30
#define   SET      31
#define   THEN      32
#define   TO      33
#define   TYPE      34
#define   UNTIL      35
#define   VAR      36
#define   WHILE      37
#define   WITH      38
#define   IDENTIFIER      39

#define   ASSIGNMENT      40
#define   CHARACTER_STRING      41
#define   COLON      42
#define   COMMA      43
#define   DIGSEQ      44
#define   DOT      45
#define   DOTDOT      46
#define   EQUAL      47
#define   GE      48
#define   GT      49
#define   LBRAC      50
#define   LE      51
#define   LPAREN      52
#define   LT      53
#define   MINUS      54
#define   PLUS      56
#define   RBRAC      57
#define   REALNUMBER      58
#define   RPAREN      59
#define   SEMICOLON      60
#define   SLASH      61
#define   STAR      62
#define   STARSTAR      63
#define   UPARROW      64


#define   notEQUAL    65


#define   Enum	      67
#define   Sarray      68
#define   Sstring     69

#define   INTEGER     70
#define   REAL        71
#define   CHAR        72
#define   BOOLEAN     73
#define   TEXT        74
#define   INPUT       75
#define   OUTPUT      76
#define   NONE        77
#define   UMINUS      78
#define   EMPTY       79




using namespace std;

//语义错误
struct Semantic_Error
{
    string kind;        //错误类型
    int line;           //错误行
    Semantic_Error(string kind, int line)
    {
        this->kind = std::move(kind);
        this->line = line;
    }
};




//数组结构
struct Array
{
    int begin;
    int end;
    Array(int a, int b)
    {
        this->begin = a;
        this->end = b;
    }
    Array()
    {
        this->begin = 0;
        this->end = 0;
    }
};



//抽象语法树节点
struct ATRNode{
    int id;                     //记号
    int line;                   //申明行
    int param_count;            //参数数量

    string attr;                //属性

    bool is_array;      //是否为数组指针变量

    vector<ATRNode> children; //子节点vector

    vector<Array> array_record;   //定义数组

    Array dim;

    ATRNode(int id, string attr, int line=0)
    {
        this->id = id;
        this->attr = std::move(attr);
        this->line = line;
        this->is_array = false;
        this->param_count = 0;

    }
};

//符号表表项
struct T_item{
    string name;                //名称
    int type;                   //类型
    int dimension;              //维度
    int line;                   //声明行
    vector<T_item> *p;          //符号表指针

    T_item(string name, int type, int dimension, int line, vector<T_item> *p)
    {
        this->name = std::move(name);
        this->type = type;
        this->dimension = dimension;
        this->line = line;
        this->p = p;
    }
};

//符号表
vector<T_item> SymbolTable;
vector<T_item> *TablePointer = &SymbolTable;    //记录此刻表的位置

vector<Semantic_Error> SemanticErrorTable;  //错误记录

#endif //COMPLIER_COMPLIER_H