%{
/*本yacc的生成文件是yacc.tab.c和yacc.tab.h
yacc文件由3段组成，用2个%%行把这3段隔开。
第1段是声明段，包括：
1-C代码部分：include头文件、函数、类型等声明，这些声明会原样拷到生成的.c文件中。
2-记号声明，如%token
3-类型声明，如%type
第2段是规则段，是yacc文件的主体，包括每个产生式是如何匹配的，以及匹配后要执行的C代码动作。
第3段是C函数定义段，如yyerror()的定义，这些C代码会原样拷到生成的.c文件中。该段内容可以为空*/

//第1段：声明段
#include "compile.h"	//lex和yacc要共用的头文件，里面包含了一些头文件，重定义了YYSTYPE
ATRNode p;

ATRNode root_node;

int layer=0;
%}

/*lex里要return的记号的声明
用token后加一对<member>来定义记号，旨在用于简化书写方式。
假定某个产生式中第1个终结符是记号OPERATOR，则引用OPERATOR属性的方式：
1-如果记号OPERATOR是以普通方式定义的，如%token OPERATOR，则在动作中要写$1.m_cOp，以指明使用YYSTYPE的哪个成员
2-用%token<m_cOp>OPERATOR方式定义后，只需要写$1，yacc会自动替换为$1.m_cOp
另外用<>定义记号后，非终结符如file, tokenlist，必须用%type<member>来定义(否则会报错)，以指明它们的属性对应YYSTYPE中哪个成员，这时对该非终结符的引用，如$$，会自动替换为$$.member*/

%token INTEGER LETTER SQUOTATION ELSE CHARACTER_STRING DQUOTATION ARRAY DIGSEQ MULTIP DIVIDE
%token AND ARRAR PBEGIN BOOLEAN CASE CHAR CONST DIV DO DOWNTO END FOR FUNCTION IF MOD
%token NOT OF OR PROCEDURE PROGRAM REAL RECORD REPEAT THEN TO TYPE UNTIL VAR WHILE
%token SUBBOUNDARY ASSIGNOP LE GE EQ NE notEQUAL EQUAL IDENTIFIER READ WRITE REALNUMBER
%token EQUL LT GT COMMA COLON SEMICOLON DOT DOTDOT LPAREN RPAREN LBRAC RBRAC PLUS MINUS SLASH STAR

%%

programstruct
	: program_head SEMICOLON program_body DOT
	{
		p=newNode(-1,"Program",0);
		p.children.push_back($1);
		p.children.push_back($2);
		p.children.push_back($3);
		p.children.push_back($4);
		root_node=p;
		$$=p;
	}
	;


program_head
	: PROGRAM IDENTIFIER LPAREN identifier_list RPAREN 
	{
		p=newNode(-1,"program_head",0);
		p.children.push_back($1);
		p.children.push_back($2);
		p.children.push_back($3);
		p.children.push_back($4);
		p.children.push_back($5);
		$$ = p;
	}
	| PROGRAM IDENTIFIER
	{
        p=newNode(-1,"program_head",0);
        p.children.push_back($1);
        p.children.push_back($2);
        $$ = p;
	}
	;


program_body
	: const_declarations var_declarations subprogram_declarations compound_statement
	{
		p=newNode(-1,"program_body",0);
		p.children.push_back($1);
		p.children.push_back($2);
		p.children.push_back($3);
		p.children.push_back($4);
		$$ = p;
	}
	;


identifier_list
	: identifier_list COMMA IDENTIFIER
	{
		p=newNode(-1,"identifier_list",0);
		p.children.push_back($1);
		p.children.push_back($2);
		p.children.push_back($3);
		$$ = p;
	}
	| IDENTIFIER
	{
		p=newNode(-1,"identifier_list",0);
		p.children.push_back($1);
		$$ = p;
	}
	;


const_declarations
	: CONST const_declaration SEMICOLON 
	{
		p=newNode(-1,"const_declarations",0);
		p.children.push_back($1);
		p.children.push_back($2);
		p.children.push_back($3);
		$$ = p;
	}
	|
	{
		$$ = newNode(-1,"const_declarations",0);
	}
	;


const_declaration
	: const_declaration SEMICOLON IDENTIFIER EQUAL const_value 
	{
		p=newNode(-1,"const_declaration",0);
		p.children.push_back($1);
		p.children.push_back($2);
		p.children.push_back($3);
		p.children.push_back($4);
		p.children.push_back($5);
		$$ = p;
	}
	| IDENTIFIER EQUAL const_value 
	{
        p=newNode(-1,"const_declaration",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	;


const_value
	: PLUS num 
	{
        p=newNode(-1,"const_value",0);                        
        p.children.push_back($1);
        p.children.push_back($2);
        $$ = p;

	}
	| MINUS num 
	{
        p=newNode(-1,"const_value",0);
        p.children.push_back($1);
        p.children.push_back($2);
        $$ = p;
	}
	| num 
	{
        p=newNode(-1,"const_value",0);       			
        p.children.push_back($1);
        $$ = p;
	}
	| LETTER
	{
		ATRNode node_1 = newNode(SQUOTATION, $1.attr.substr(0,1), $1.line);
		ATRNode node_2 = newNode(SQUOTATION, $1.attr.substr(1,1), $1.line);
		ATRNode node_3 = newNode(SQUOTATION, $1.attr.substr(2,1), $1.line);
        p=newNode(-1,"const_value",0);       			
        p.children.push_back(node_1);
		p.children.push_back(node_2);
		p.children.push_back(node_3);
        $$ = p;
	}
	;


num
	: DIGSEQ
	{
        p=newNode(-1,"num",0);
        p.children.push_back($1);
        $$ = p;

	}
	| REALNUMBER
	{
        p=newNode(-1,"num",0);
        p.children.push_back($1);
        $$ = p;
	}
	;


var_declarations
	: VAR var_declaration SEMICOLON 
	{
        p=newNode(-1,"var_declarations",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| 
	{
		$$ = newNode(-1,"var_declarations",0);
	}
	;


var_declaration
	: var_declaration SEMICOLON identifier_list COLON type
	{
        p=newNode(-1,"var_declaration",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        p.children.push_back($4);
        p.children.push_back($5);
        $$ = p;
	}
	| identifier_list COLON type 
	{
        p=newNode(-1,"var_declaration",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
		$$ = p;
	}
	;


type
	: basic_type 
	{
        p=newNode(-1,"type",0);
        p.children.push_back($1);
        $$ = p;
	}
	| ARRAY LBRAC period RBRAC OF basic_type 
	{
        p=newNode(-1,"type",0);
        p.children.push_back($1);
		p.children.push_back($2);
        p.children.push_back($3);
        p.children.push_back($4); 
        p.children.push_back($5);
        p.children.push_back($6);
        $$ = p;
	}
	;


basic_type
	: INTEGER 
	{
        p=newNode(-1,"basic_type",0);
        p.children.push_back($1);
        $$ = p;
	}
	| REAL 
	{
        p=newNode(-1,"basic_type",0);
        p.children.push_back($1);
        $$ = p;
	}
	| BOOLEAN 
	{
        p=newNode(-1,"basic_type",0);
        p.children.push_back($1);
        $$ = p;
	}
	| CHAR 
	{
        p=newNode(-1,"basic_type",0);
        p.children.push_back($1);
        $$ = p;
	}
	;


period
	: period COMMA DIGSEQ DOTDOT DIGSEQ 
	{                     
        p=newNode(-1,"period",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        p.children.push_back($4);
        p.children.push_back($5);
        $$ = p;
	}
	| DIGSEQ DOTDOT DIGSEQ 
	{
        p=newNode(-1,"period",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	;


subprogram_declarations
	: subprogram_declarations subprogram SEMICOLON 
	{
		p=newNode(-1,"subprogram_declarations",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| 
	{
		$$ = newNode(-1,"subprogram_declarations",0);
	}
	;


subprogram
	: subprogram_head SEMICOLON subprogram_body 
	{
		p=newNode(-1,"subprogram",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	;


subprogram_head
	: FUNCTION IDENTIFIER formal_parameter COLON basic_type
	{
		p=newNode(-1,"subprogram_head",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        p.children.push_back($4);
        p.children.push_back($5);
        $$ = p;
	}
	| PROCEDURE IDENTIFIER formal_parameter
	{
		p=newNode(-1,"subprogram_head",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	;


formal_parameter
	: LPAREN parameter_list RPAREN 
	{
		p=newNode(-1,"formal_parameter",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| 
	{
		$$ = newNode(-1,"formal_parameter",0);
	}
	;


parameter_list
	: parameter_list SEMICOLON parameter 
	{
		p=newNode(-1,"parameter_list",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| parameter 
	{
		p=newNode(-1,"parameter_list",0);
        p.children.push_back($1);
        $$ = p;
	}
	;


parameter
	: var_parameter 
	{
		p=newNode(-1,"parameter",0);
        p.children.push_back($1);
        $$ = p;
	}
	| value_parameter 
	{
		p=newNode(-1,"parameter",0);
        p.children.push_back($1);
        $$ = p;
	}
	;


var_parameter
	: VAR value_parameter
	{
		p=newNode(-1,"var_parameter",0);
        p.children.push_back($1);
        p.children.push_back($2);
        $$ = p;
	}
	;


value_parameter
	: identifier_list COLON basic_type
	{
		p=newNode(-1,"value_parameter",0);
        p.children.push_back($1);
        p.children.push_back($2);
		p.children.push_back($3);
        $$ = p;
	}
	;


subprogram_body
	: const_declarations var_declarations compound_statement 
	{
		p=newNode(-1,"subprogram_body",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	|
	{
		$$ = newNode(-1,"subprogram_body",0);
	}
	;


compound_statement
	: PBEGIN statement_list END 
	{
		p=newNode(-1,"compound_statement",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	;

statement_list
	: statement_list SEMICOLON statement 
	{
		p=newNode(-1,"statement_list",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| statement 
	{
		p=newNode(-1,"statement_list",0);
        p.children.push_back($1);
        $$ = p;
	}
	;


statement
	: variable ASSIGNOP expression 
	{
		p=newNode(-1,"statement",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| procedure_call 
	{	
		p=newNode(-1,"statement",0);
        p.children.push_back($1);
        $$ = p;
	}
	| compound_statement 
	{	
		p=newNode(-1,"statement",0);
        p.children.push_back($1);
        $$ = p;
	}
	| IF expression THEN statement else_part 
	{
		p=newNode(-1,"statement",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        p.children.push_back($4);
        p.children.push_back($5);
        $$ = p;
	}
	| FOR IDENTIFIER ASSIGNOP expression TO expression DO statement 
	{
		p=newNode(-1,"statement",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        p.children.push_back($4);
        p.children.push_back($5);
        p.children.push_back($6);
        p.children.push_back($7);
        p.children.push_back($8);
        $$ = p;
	}
	| READ LPAREN variable_list RPAREN
	{
		p=newNode(-1,"statement",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        p.children.push_back($4);
        $$ = p;
	}
	| WRITE LPAREN expression_list RPAREN
	{
		p=newNode(-1,"statement",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        p.children.push_back($4);
        $$ = p;
	}
	| WHILE expression DO statement
	{
		p=newNode(-1,"statement",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        p.children.push_back($4);
        $$ = p;
	}
	|
	{
		$$ = newNode(-1,"statement",0);
	}
	;


variable_list
	: variable_list COMMA variable
	{
		p=newNode(-1,"variable_list",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| variable
	{
		p=newNode(-1,"variable_list",0);
        p.children.push_back($1);
        $$ = p;
	}
	;


variable
	: IDENTIFIER id_varpart 
	{
		p=newNode(-1,"variable",0);
        p.children.push_back($1);
        p.children.push_back($2);
        $$ = p;
	}
	;



id_varpart
	: LBRAC expression_list RBRAC 
	{
		p=newNode(-1,"id_varpart",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| 
	{
		p=newNode(-1,"id_varpart",0);
		$$ = p;
	}
	;


procedure_call
	: IDENTIFIER 
	{
		p=newNode(-1,"procedure_call",0);
        p.children.push_back($1);
        $$ = p;
	}
	| IDENTIFIER LPAREN expression_list RPAREN 
	{
		p=newNode(-1,"procedure_call",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        p.children.push_back($4);
        $$ = p;
	}
	;


else_part
	: ELSE statement 
	{
		p=newNode(-1,"else_part",0);
        p.children.push_back($1);
        p.children.push_back($2);
        $$ = p;
	}
	|
	{
		$$ = newNode(-1,"else_part",0);
	}
	;


expression_list
	: expression_list COMMA expression 
	{
		p=newNode(-1,"expression_list",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| expression 
	{
		p=newNode(-1,"expression_list",0);
        p.children.push_back($1);
        $$ = p;
	}
	;


expression
	: simple_expression relop simple_expression 
	{
		p=newNode(-1,"expression",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| simple_expression 
	{
		p=newNode(-1,"expression",0);
        p.children.push_back($1);
        $$ = p;
	}
	;


simple_expression
	: term 
	{
		p=newNode(-1,"simple_expression",0);
        p.children.push_back($1);
        $$ = p;
	}
	| simple_expression addop term 
	{
		p=newNode(-1,"simple_expression",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	;


term
	: term mulop factor 
	{
		p=newNode(-1,"term",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| factor 
	{
		p=newNode(-1,"term",0);
        p.children.push_back($1);
        $$ = p;
	}
	;


factor
	: num
	{
		p=newNode(-1,"factor",0);
        p.children.push_back($1);
        $$ = p;
	}
	| variable 
	{
		p=newNode(-1,"factor",0);
        p.children.push_back($1);
        $$ = p;
	}
	| IDENTIFIER LPAREN expression_list RPAREN 
	{
		p=newNode(-1,"factor",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        p.children.push_back($4);
        $$ = p;
	}
	| LPAREN expression RPAREN 
	{
		p=newNode(-1,"factor",0);
        p.children.push_back($1);
        p.children.push_back($2);
        p.children.push_back($3);
        $$ = p;
	}
	| NOT factor 
	{
		p=newNode(-1,"factor",0);
        p.children.push_back($1);
        p.children.push_back($2);
        $$ = p;
	}
	| MINUS factor
	{
		p=newNode(-1,"factor",0);
        p.children.push_back($1);
        p.children.push_back($2);
        $$ = p;
	}
	;


relop
	: GT
	{
		p=newNode(-1,"relop",0);
        p.children.push_back($1);
        $$ = p;
	}
	| EQUAL
	{
		p=newNode(-1,"relop",0);
        p.children.push_back($1);
        $$ = p;
	}
	| LT
	{
		p=newNode(-1,"relop",0);
        p.children.push_back($1);
        $$ = p;
	}
	| LE
	{
		p=newNode(-1,"relop",0);
        p.children.push_back($1);
        $$ = p;
	}
	| GE
	{
		p=newNode(-1,"relop",0);
        p.children.push_back($1);
        $$ = p;
	}
	| notEQUAL
	{
		p=newNode(-1,"relop",0);
        p.children.push_back($1);
        $$ = p;
	}


addop
	: PLUS
	{
		p=newNode(-1,"addop",0);
        p.children.push_back($1);
        $$ = p;
	}
	| MINUS
	{
		p=newNode(-1,"addop",0);
        p.children.push_back($1);
        $$ = p;
	}
	| OR
	{
		p=newNode(-1,"addop",0);
        p.children.push_back($1);
        $$ = p;
	}
	;


mulop
	: STAR
	{
		p=newNode(-1,"mulop",0);
        p.children.push_back($1);
        $$ = p;
	}
	| SLASH
	{
		p=newNode(-1,"mulop",0);
        p.children.push_back($1);
        $$ = p;
	}
	| MOD
	{
		p=newNode(-1,"mulop",0);
        p.children.push_back($1);
        $$ = p;
	}
	| AND
	{
		p=newNode(-1,"mulop",0);
        p.children.push_back($1);
        $$ = p;
	}
	| DIV
	{
		p=newNode(-1,"mulop",0);
        p.children.push_back($1);
        $$ = p;
	}
	;
%%

void yyerror(const char *s)			//当yacc遇到语法错误时，会回调yyerror函数，并且把错误信息放在参数s中
{
	cerr<<s<<endl;					//直接输出错误信息
}

void postorder_traversal(const ATRNode& Node)
{
    for(int i=0; i<layer; i++)
    {
        cout << "\t";
    }
    
    if(Node.children.empty() and Node.id != -1)
    {
        cout << "[" << Node.id << " | " << Node.attr << " | " << Node.line << "]" << endl;
    }
    else{
        cout << Node.attr << endl;
        layer++;
        for(auto & i : Node.children)
        {
            postorder_traversal(i);
        }
        layer--;
    }
}

ATRNode newNode(int id, string attr, int line=0)
{
	cout << id << "\t" << attr << endl;
    ATRNode temp(id, attr, line);
    return temp;
}

int syntax_process()							//程序主函数，这个函数也可以放到其它.c, .cpp文件里
{
	const char* sFile="file.txt";	//打开要读取的文本文件
	FILE* fp=fopen(sFile, "r");
	if(fp==NULL)
	{
		printf("cannot open %s\n", sFile);
		return -1;
	}
	extern FILE* yyin;				//yyin和yyout都是FILE*类型
	yyin=fp;						//yacc会从yyin读取输入，yyin默认是标准输入，这里改为磁盘文件。yacc默认向yyout输出，可修改yyout改变输出目的

	printf("-----PBEGIN parsing %s\n", sFile);
	yyparse();						//使yacc开始读取输入和解析，它会调用lex的yylex()读取记号
	puts("-----end parsing");
	fclose(fp);
	postorder_traversal(root_node);
	cout << endl;
	return 0;
}


