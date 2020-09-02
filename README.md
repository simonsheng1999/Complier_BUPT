# Pascal-S语言编译程序设计报告  

## 一、课程设计目标和要求：  

&#160;&#160;&#160;&#160;&#160;&#160;&#160;
按照所给Pascal-S语言的语法，参考Pascal语言的语义，设计并实现Pascal-S语言编译为C语言的编译程序。


## 二、需求分析：  

### 1、词法分析： 

    单词种类、单词模式、右线性文法  
    注释、分隔符  
    错误  

### 2、语法分析： 

    语法结构、语法错误类型  
    文法，分析方法选择  
    改写文法  

### 3、语义分析： 

    类型、类型表示、类型检查、作用域、符号表内容  

### 4、代码生成： 

#### （1）目标语言：C语言  

#### （2）源/目标语言的映射关系：  

##### 程序头映射

	program sample (input, output);	=> #include<stdio.h>	

##### 常量声明映射

	const z = 's'; => const char z = 's';	
	
##### 变量声明映射
	
	var z: integer; => int z;

##### 子程序声明映射
	
	procedure test(var a:integer);                  void test(int a){	
        begin                                 =>	...	
        	...					}	
        end;	
	
	function gcd(a:integer):integer;		int gcd(int a){	
        begin				    =>          ...
   		gcd := 1;				return 1;	
        end;                                            }	
	
##### 复杂语句映射

## 三、开发环境：  

&#160;&#160;&#160;&#160;&#160;&#160;&#160;
1、PC机 

2、win10 
&#160;&#160;&#160;&#160;&#160;&#160;&#160;
3、CLion  

## 四、总体设计说明：  
![模块关系图](https://github.com/simonsheng1999/Complier_BUPT/blob/master/%E6%A8%A1%E5%9D%97%E5%85%B3%E7%B3%BB%E5%9B%BE.png)

### 1、总体结构设计： 

####  1）功能模块的划分及功能：  

##### a、词法分析模块：  

    （功能）  

##### b、语法分析模块：  

    （功能）  

##### c、语义分析模块：  

        1. 符号表的建立及维护  
        2. 类型检查  
        3. 错误检查及处理


##### d、代码生成模块：  

    （功能）

####  2）模块之间的关系及接口：  

&#160;&#160;&#160;&#160;&#160;&#160;&#160;
<img src="https://github.com/simonsheng1999/Complier_BUPT/blob/master/%E6%A8%A1%E5%9D%97%E5%85%B3%E7%B3%BB%E5%9B%BE.png" width = "700" height = "175" alt="" align=center />

### 2、数据结构设计：（符号表、语法树、记号二元组...）  

**符号表项 : T_item**

| name   | type | is_ref  | dimension | line | p                |
| ------ | ---- | ------- | --------- | ---- | ---------------- |
| string | int  | boolean | int       | int  | vector<T_item> * |

​	**name【名称】**：（字符串）标识符的具体名称

​	**type【类型】**：（整型）整型、实型等基本类型（也可以是函数、过程等类型）的整数表示

​    **is_ref【引用变量标识】**：（布尔型）该变量是否为（函数或过程中的）引用型参数变量

​	**dimension【维度】**：（整型）数组维度，如果是基本类型则为0，或是函数，过程等的参数个数

​	**line【出现行】**：（整型）标识符出现的行数

​	**p【指针域】**：（符号表指针）函数和过程的子表指针，以及数组的范围控制表

**PS: 针对数组的范围控制表中type和dimension两项分别存储数组范围的下界与上界**

**语法树节点: ATRNode**

| id【标识】 | attr【属性】 | line【出现行】 | children【子节点】 |
| ---------- | ------------ | -------------- | ------------------ |
| int        | string       | int            | vector <ATRNode>   |

​	**标识**：代表以该节点为根节点的子树的类型，叶节点为对应词法token类型（整数），非叶节点为-1

​	**属性**：代表以该节点为根节点的子树对应的语法结构的字符串表示（字符串）

​	**出现行**：该节点出现的行数，只有叶节点需要该属性，非叶节点对应值为0

​	**子节点**：该语法结构对应的各个子结构，叶节点的该属性域为空

### 3、错误处理恢复策略：（词法、语法、语义、代码生成）  

**语义分析**

​	对于错误，只进行错误类型和错误位置的提示，并不进行修改

​	**错误类型**

| 错误类型                | 输出提示 |
| ----------------------- | -------- |
| 重复定义                |          |
| 未定义的引用            |          |
| 类型信息错误            |          |
| 赋值类型语句不匹配      |          |
| if语句后需接布尔类型    |          |
| 循环变量类型错误        |          |
| while语句后需接布尔类型 |          |
| 数组参数维度为0         |          |
| 数组范围错误            |          |
| 非数组类型，不可索引    |          |
| 数组参数数目不匹配      |          |
| 存在非整数索引          |          |
| 函数参数数目不匹配      |          |
| 参数类型错误            |          |
| 关系运算子类型不匹配    |          |
| 非函数类型，不可调用    |          |




## 五、各部分的详细设计说明：  

### 1、接口描述： 

语义分析：

输入：语法树，每个节点都是一个结构体，结构体中需要包含

	记号：叶子节点中的标识符的id，非叶子结点为空
	
	属性：以该结点为根节点的子树所代表的语法成分
	
	所在行：叶子节点所在的行数
	
	子结点域：存放指向子结点的指针

输出：符号表、语法树

### 2、功能描述： 

**语义分析：**

​	对语法分析得到的语法树进行语义分析，实现的功能包括：

- ​	**符号表的简历与维护**
- ​	**类型检查**
- ​	**错误检查与输出**

### 3、所用数据结构说明： 

### 4、算法描述： 


## 六、程序清单：  


## 七、测试报告:  

### 1、测试环境： 

### 2、测试计划： 

### 3、测试结果： 


## 八、实验总结：  

### 1、实验中遇到的或存在的主要问题： 

### 2、改进建议： 

### 3、体会/收获：  
