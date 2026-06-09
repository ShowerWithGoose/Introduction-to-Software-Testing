#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
#include<algorithm>

using namespace std;

string source;//用于存储源程序字符串
int lineNum = 1;//用于记录当前行号
string token,lexType;//用于存储当前的token和token的类型
int curPos = 0;//用于记录当前解析到source的位置
int num = 0;//用于解析数字
vector<tuple<string, string, int>> identifier;//用于存储已经识别的标识符
int is_error = 0;//用于记录是否有错误
ofstream correct,error,parser;//输出文件
//错误处理信息的结构体
struct errorData
{
    int linenum;
    char errorType;
};

vector<errorData> errorDataList;

bool compareData(const errorData& a, const errorData& b) {
    return a.linenum < b.linenum;
}
//列举保留字的所有类型以及其对应的类别码
unordered_map<string, string> reserveWords = {
    {"main","MAINTK"},{"const","CONSTTK"},
    {"int","INTTK"},{"char","CHARTK"},
    {"break","BREAKTK"},{"continue","CONTINUETK"},
    {"if","IFTK"},{"else","ELSETK"},
    {"for","FORTK"},{"getint","GETINTTK"},
    {"getchar","GETCHARTK"},{"printf","PRINTFTK"},
    {"return","RETURNTK"},{"void","VOIDTK"},
};

//列举单个标点符号的所有类型以及其对应的类别码
unordered_map<string, string> chars = {
    {"+","PLUS"},
    {"-","MINU"},{"*","MULT"},
    {"%","MOD"},{";","SEMICN"},
    {",","COMMA"},{"(","LPARENT"},
    {")","RPARENT"},{"[","LBRACK"},
    {"]","RBRACK"},{"{","LBRACE"},
    {"}","RBRACE"},
};


/*读取文件到字符串当中*/
string readFileIntoString(const string& filename) {
    ifstream file(filename);
    ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int cur_ident=0;//记录当前分析到哪一个词法成分

//即将建立的语法树节点情况
typedef struct tree_node
{
    string synt_component;//该节点的语法成分（终结符或者非终结符）
    string Type;//如果是终结符，则是该节点的类型，等同于词法分析的lexType.
    vector<tree_node*> children;//该节点的孩子节点
}GrammarTree;

GrammarTree *root;//语法树的根节点

int isExp()
{
    if(get<1>(identifier[cur_ident])=="IDENFR"
    ||get<1>(identifier[cur_ident])=="INTCON"
    ||get<1>(identifier[cur_ident])=="CHRCON"
    ||get<1>(identifier[cur_ident])=="LPARENT"
    ||get<1>(identifier[cur_ident])=="PLUS"
    ||get<1>(identifier[cur_ident])=="MINU"
    ||get<1>(identifier[cur_ident])=="NOT")
    {
        return 1;
    }

    else
    {
        return 0;
    }



}

//将当前解析到的终结符加入语法树叶子节点
void addToTree(GrammarTree *node)
{
    GrammarTree *node1=new GrammarTree;

    node1->synt_component=get<0>(identifier[cur_ident]);
    node1->Type=get<1>(identifier[cur_ident]);
    node->children.push_back(node1);
    cur_ident++;
}

//树的后序遍历算法
void postOrderTraversal(tree_node* node) {
    if (node == nullptr) return;
    // Traverse all the children
    for (auto child : node->children) {
        postOrderTraversal(child);
    }

    if(node->Type!="")
    // Visit the node
        parser << node->Type << " " << node->synt_component << endl;
    else
    {
        if(node->synt_component!="<BlockItem>"&&node->synt_component!="<Decl>"&&node->synt_component!="<BType>")
        {
            parser << node->synt_component << endl;
        }
    }
}


//语法分析各种函数的声明
void CompUnit();
GrammarTree *Decl();
GrammarTree *BType();
GrammarTree *ConstDecl();
GrammarTree *ConstDef();
GrammarTree *ConstInitVal();
GrammarTree *VarDecl();
GrammarTree *VarDef();
GrammarTree *InitVal();
GrammarTree *FuncDef();
GrammarTree *MainFuncDef();
GrammarTree *FuncType();
GrammarTree *FuncFParams();
GrammarTree *FuncFParam();
GrammarTree *Block();
GrammarTree *BlockItem();
GrammarTree *Stmt();
GrammarTree *ForStmt();
GrammarTree *Exp();
GrammarTree *Cond();
GrammarTree *LVal();
GrammarTree *PrimaryExp();
GrammarTree *Number();
GrammarTree *Character();
GrammarTree *UnaryExp();
GrammarTree *UnaryOp();
GrammarTree *FuncRParams();
GrammarTree *MulExp();
GrammarTree *AddExp();
GrammarTree *RelExp();
GrammarTree *EqExp();
GrammarTree *LAndExp();
GrammarTree *LOrExp();
GrammarTree *ConstExp();

//常量表达式 ConstExp → AddExp 注：使用的 Ident 必须是常量 
GrammarTree *ConstExp()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<ConstExp>";
    GrammarTree *p;

    //常量表达式的定义是AddExp
    p=AddExp();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }
    return node;
}

//逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
GrammarTree *LOrExp()
{
    //最终返回的子树根节点
    GrammarTree *node;

    //建立语法树的节点
    GrammarTree *node1 = new GrammarTree;
    node1->synt_component = "<LOrExp>";
    GrammarTree *p;

    //首先是一个AddExp
    p=LAndExp();
    if(p!=NULL)
    {
        node1->children.push_back(p);
    }

    node=node1;//此时的根节点还是node1
    //之后是循环检测
    while(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="OR")
    {
        //为上一个node1建立一个新的父节点
        GrammarTree *node2=new GrammarTree;
        node2->synt_component="<LOrExp>";
        node2->children.push_back(node);

        //先将运算符加入到节点中
        addToTree(node2);

        //解析完符号之后在解析一个一元表达式
        p=LAndExp();
        if(p!=NULL)
        {
            node2->children.push_back(p);
        }
        node=node2;//node2成为新的父节点
    }
    return node;
}

//逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
GrammarTree *LAndExp()
{
    //最终返回的子树根节点
    GrammarTree *node;

    //建立语法树的节点
    GrammarTree *node1 = new GrammarTree;
    node1->synt_component = "<LAndExp>";
    GrammarTree *p;

    //首先是一个AddExp
    p=EqExp();
    if(p!=NULL)
    {
        node1->children.push_back(p);
    }

    node=node1;//此时的根节点还是node1

    //之后是循环检测
    while(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="AND")
    {
        //为上一个node1建立一个新的父节点
        GrammarTree *node2=new GrammarTree;
        node2->synt_component="<LAndExp>";
        node2->children.push_back(node);

        //先将运算符加入到节点中
        addToTree(node2);

        //解析完符号之后在解析一个一元表达式
        p=EqExp();
        if(p!=NULL)
        {
            node2->children.push_back(p);
        }
        node=node2;//node2成为新的父节点
    }
    return node;
}

//相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp 
GrammarTree *EqExp()
{
    //最终返回的子树根节点
    GrammarTree *node;

    //建立语法树的节点
    GrammarTree *node1 = new GrammarTree;
    node1->synt_component = "<EqExp>";
    GrammarTree *p;

    //首先是一个AddExp
    p=RelExp();
    if(p!=NULL)
    {
        node1->children.push_back(p);
    }

    node=node1;//此时的根节点还是node1

    //之后是循环检测
    while(cur_ident<identifier.size()&&(get<1>(identifier[cur_ident])=="EQL"
    ||get<1>(identifier[cur_ident])=="NEQ"))
    {
        //为上一个node1建立一个新的父节点
        GrammarTree *node2=new GrammarTree;
        node2->synt_component="<EqExp>";
        node2->children.push_back(node);
        //先将运算符加入到节点中
        addToTree(node2);

        //解析完符号之后在解析一个一元表达式
        p=RelExp();
        if(p!=NULL)
        {
            node2->children.push_back(p);
        }
        
        node=node2;//node2成为新的父节点
    }
    return node;
}

//关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp 
GrammarTree *RelExp()
{
    //最终返回的子树根节点
    GrammarTree *node;

    //建立语法树的节点
    GrammarTree *node1 = new GrammarTree;
    node1->synt_component = "<RelExp>";
    GrammarTree *p;

    //首先是一个AddExp
    p=AddExp();
    if(p!=NULL)
    {
        node1->children.push_back(p);
    }

    node=node1;//此时的根节点还是node1

    //如果解析完UnaryExp之后，出现了一个乘号，模号，或者除号
    while(cur_ident<identifier.size()&&(get<1>(identifier[cur_ident])=="LSS"
    ||get<1>(identifier[cur_ident])=="LEQ"
    ||get<1>(identifier[cur_ident])=="GRE"
    ||get<1>(identifier[cur_ident])=="GEQ"))
    {
        //为上一个node1建立一个新的父节点
        GrammarTree *node2=new GrammarTree;
        node2->synt_component="<RelExp>";
        node2->children.push_back(node);

        //先将运算符加入到节点中
        addToTree(node2);

        //解析完符号之后在解析一个一元表达式
        p=AddExp();
        if(p!=NULL)
        {
            node2->children.push_back(p);
        }
        node=node2;//node2成为新的父节点
    }
    return node;
}

//加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp 
GrammarTree *AddExp()
{
    //最终返回的子树根节点
    GrammarTree *node;

    //建立语法树的节点
    GrammarTree *node1 = new GrammarTree;
    node1->synt_component = "<AddExp>";
    GrammarTree *p;

    //首先是一个UnaryExp
    p=MulExp();
    if(p!=NULL)
    {
        node1->children.push_back(p);
    }

    node=node1;//此时的根节点还是node1

    //如果解析完UnaryExp之后，出现了一个乘号，模号，或者除号
    while(cur_ident<identifier.size()&&(get<1>(identifier[cur_ident])=="PLUS"
    ||get<1>(identifier[cur_ident])=="MINU"))
    {
        //为上一个node1建立一个新的父节点
        GrammarTree *node2=new GrammarTree;
        node2->synt_component="<AddExp>";
        node2->children.push_back(node);

        //先将运算符加入到节点中
        addToTree(node2);

        //解析完符号之后在解析一个一元表达式
        p=MulExp();
        if(p!=NULL)
        {
            node2->children.push_back(p);
        }
        node=node2;//node2成为新的父节点
    }

    return node;
}

//乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp 
GrammarTree *MulExp()
{
    //最终返回的子树根节点
    GrammarTree *node;

    //建立语法树的节点
    GrammarTree *node1 = new GrammarTree;
    node1->synt_component = "<MulExp>";
    GrammarTree *p;

    //首先是一个UnaryExp
    p=UnaryExp();
    if(p!=NULL)
    {
        node1->children.push_back(p);
    }

    node=node1;//此时的根节点还是node1

    //如果解析完UnaryExp之后，出现了一个乘号，模号，或者除号
    while(cur_ident<identifier.size()&&(get<1>(identifier[cur_ident])=="MULT"
    ||get<1>(identifier[cur_ident])=="DIV"
    ||get<1>(identifier[cur_ident])=="MOD"))
    {
        //为上一个node1建立一个新的父节点
        GrammarTree *node2=new GrammarTree;
        node2->synt_component="<MulExp>";
        node2->children.push_back(node);

        //先将运算符加入到节点中
        addToTree(node2);

        //解析完符号之后在解析一个一元表达式
        p=UnaryExp();
        if(p!=NULL)
        {
            node2->children.push_back(p);
        }
        node=node2;//node2成为新的父节点
    }
    return node;
}

//函数实参表 FuncRParams → Exp { ',' Exp } 
GrammarTree *FuncRParams()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<FuncRParams>";
    GrammarTree *p;

    //首先解析一个Exp
    p=Exp();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }
    //之后是{,Exp}的循环检测
    while(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="COMMA")
    {
        addToTree(node);

        //之后是一个Exp
        p=Exp();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    return node;
}

//单目运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中 
GrammarTree *UnaryOp()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<UnaryOp>";
    addToTree(node);
    return node;
}

//一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
GrammarTree *UnaryExp()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<UnaryExp>";
    GrammarTree *p;

    //如果以+，-，!开头，则解析UnaryOp
    if(cur_ident<identifier.size()&&(get<1>(identifier[cur_ident])=="PLUS"
    ||get<1>(identifier[cur_ident])=="MINU"
    ||get<1>(identifier[cur_ident])=="NOT"))
    {
        p=UnaryOp();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
        p=UnaryExp();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }

    //如果以标识符开头
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="IDENFR")
    {
        //如果标识符之后的是一个左括号，则说明这是一个函数调用
        if(cur_ident+1<identifier.size()&&get<1>(identifier[cur_ident+1])=="LPARENT")
        {
            //首先是一个标识符
            addToTree(node);

            //之后是一个左括号
            addToTree(node);
            

            //如果之后不直接是右括号
            //之后是函数实参表
            if(isExp())
            {
                p=FuncRParams();
                if(p!=NULL)
                {
                    node->children.push_back(p);
                }
            }

            //再之后是右括号
            if(cur_ident<identifier.size()
            &&get<1>(identifier[cur_ident])=="RPARENT")
            {
                addToTree(node);
            }

            else//否则就要报错
            {
                is_error=1;
                errorDataList.push_back({get<2>(identifier[cur_ident-1]),'j'});
            }

        }
        //如果标识符后面不是一个小括号，则说明要解析的是PrimaryExp
        else
        {
            p=PrimaryExp();
            if(p!=NULL)
            {
                node->children.push_back(p);
            }
        }

    }
    //如果是其他情况，则解析PrimaryExp
    else
    {
        p=PrimaryExp();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    return node;
}

//Character → CharConst 
GrammarTree *Character()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<Character>";
    addToTree(node);
    return node;
}

//数值 Number → IntConst 
GrammarTree *Number()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<Number>";

    //建立子节点
    addToTree(node);
    return node;
}

//基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
GrammarTree *PrimaryExp()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<PrimaryExp>";
    GrammarTree *p;

    //如果刚开始出现的是一个左括号的话
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="LPARENT")
    {
        //先处理这个小括号
        addToTree(node);

        //之后应当是一个EXP
        p=Exp();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }

        //如果之后是右括号，则说明是正确的
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RPARENT")
        {
            addToTree(node);
        }

        //如果不是右括号,则发生了j类型错误
        else
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'j'});
        }
    }

    //如果刚开始是一个数字常量的话
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="INTCON")
    {
        p=Number();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }   
    }

    //如果开始的是一个字符常量的话，那么解析Character
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="CHRCON")
    {
        p=Character();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }

    //如果是一个标识符的话，那么解析LVal
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="IDENFR")
    {
        p=LVal();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    return node;
}

//左值表达式 LVal → Ident ['[' Exp ']'] // k
GrammarTree *LVal()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<LVal>";
    GrammarTree *p;

    //首先处理一个ident
    addToTree(node);
    //如果解析完标识符之后，有一个中括号，则中括号之后会有一个EXP,同时会有一个右括号
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="LBRACK")
    {
        addToTree(node);

        //接下来是一个Exp
        p=Exp();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }

        //如果EXP之后是一个有括号的话，那么说明是正确的
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RBRACK")
        {
            addToTree(node);

        }

        else//否则就要报错
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'k'});
        }
    }
    //之后可能胡出现中括号
    return node;
}

//条件表达式 Cond → LOrExp 
GrammarTree *Cond()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<Cond>";
    GrammarTree *p;
    //接下来是一个LOrExp
    p=LOrExp();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }
    return node;
}

//表达式 Exp → AddExp 
GrammarTree *Exp()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<Exp>";
    GrammarTree *p;
    //接下来是一个AddExp
    p=AddExp();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }
    
    return node;
}

//语句 ForStmt → LVal '=' Exp 
GrammarTree *ForStmt()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<ForStmt>";
    GrammarTree *p;
    //首先是一个LVal
    p=LVal();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }

    //接下来是一个等号
    addToTree(node);

    //接下来是一个Exp
    p=Exp();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }
    return node;
}

/*
语句 Stmt → LVal '=' Exp ';' // i
| [Exp] ';' // i
| Block
| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt 
| 'break' ';' | 'continue' ';' // i
| 'return' [Exp] ';' // i
| LVal '=' 'getint''('')'';' // i j
| LVal '=' 'getchar''('')'';' // i j
| 'printf''('StringConst {','Exp}')'';' // i j
*/
GrammarTree *Stmt()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<Stmt>";
    GrammarTree *p;

    //以左大括号开头，说明是一个语句块
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="LBRACE")
    {
        p=Block();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }

    //以if开头，说明是一个if语句
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="IFTK")
    {//将if加入到语法树中
        addToTree(node);
        //之后是一个左括号
        addToTree(node);
        //之后是一个条件表达式
        p=Cond();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
        //如果之后是一个右括号的话
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RPARENT")
        {
            addToTree(node);         
        }

        //如果不是右括号就报错
        else
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'j'});
        }

        //之后是一个语句
        p=Stmt();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }

        //之后可能会有一个else
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="ELSETK")
        {//将else加入到语法树中

            addToTree(node);
            //之后是一个语句
            p=Stmt();
            if(p!=NULL)
            {
                node->children.push_back(p);
            }
        }
    }

    //以for开头，说明是一个for语句
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="FORTK")
    {
    
        //先把for单词加入语法树
        addToTree(node);

        //之后是一个括号，把括号加入语法树
        addToTree(node);

        //如果不是分号，说明之后有一个表达式
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])!="SEMICN")
        {
            p=ForStmt();
            if(p!=NULL)
            {
                node->children.push_back(p);
            }
        }
        
        //将分号加入到语法树中
        addToTree(node);

        //如果不是右括号，说明之后有一个条件表达式
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])!="SEMICN")
        {
            p=Cond();
            if(p!=NULL)
            {
                node->children.push_back(p);
            }
        }

        //在将一个分号加入语法树
        addToTree(node);
        //如果不是右括号，说明之后有一个表达式
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])!="RPARENT")
        {
            p=ForStmt();
            if(p!=NULL)
            {
                node->children.push_back(p);
            }
        }
        //应当有一个右括号
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RPARENT")
        {
            addToTree(node);
        }
        //之后是一个语句
        p=Stmt();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    //如果开头是一个break，说明是一个break语句
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="BREAKTK")
    {
        addToTree(node);
        //之后如果是一个分号的话
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN"
        &&get<2>(identifier[cur_ident])==get<2>(identifier[cur_ident-1]))
        {
            addToTree(node);
        }
        else
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
        }
    }

    //如果开头是一个continue，说明是一个continue语句
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="CONTINUETK")
    {
        addToTree(node);
        //之后如果是一个分号的话
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN"
        &&get<2>(identifier[cur_ident])==get<2>(identifier[cur_ident-1]))
        {
            addToTree(node);
        }
        else
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
        }
    }

    //如果开头是一个return，说明是一个return语句
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RETURNTK")
    {
        addToTree(node);
        //如果是一个表达式,且表达式和return在同一行
        if(isExp())
        {
            p=Exp();
            if(p!=NULL)
            {
                node->children.push_back(p);
            }

            //如果是一个分号
            if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN"
            &&get<2>(identifier[cur_ident])==get<2>(identifier[cur_ident-1]))
            {
                addToTree(node);
            }

            else
            {
                is_error=1;
                errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
            }
        }
        //如果是一个分号
        else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN")
        {
            addToTree(node);
        }

        else
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
        }
    }
    //如果是printf，说明是一个printf语句
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="PRINTFTK")
    {
        addToTree(node);
        
        //接下来是一个括号
        addToTree(node);

        //接下来是一个stringconst
        addToTree(node);

        //接下来是若干逗号和Exp
        while(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="COMMA")
        {//将逗号加入到语法树中
            addToTree(node);

            p=Exp();
            if(p!=NULL)
            {
                node->children.push_back(p);
            }
        }

        //是否有右括号
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RPARENT")
        {
            addToTree(node);
        }

        else
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'j'});
        }

        //接下来是一个分号
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN"
        &&get<2>(identifier[cur_ident])==get<2>(identifier[cur_ident-1]))
        {
            addToTree(node);
        }

        else
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
        }
    }

    //如果是一个分号，说明是一个空语句
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN")
    {
        addToTree(node);
    }

    //重新设计LVal的情况以及Exp情况，它们存在以标识符开头的情况
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="IDENFR")

    {
        int stride=0;
        //进行预读
        while(cur_ident+stride<identifier.size()
        &&get<1>(identifier[cur_ident+stride])!="ASSIGN"
        &&get<1>(identifier[cur_ident+stride])!="SEMICN"
        &&get<2>(identifier[cur_ident+stride])==get<2>(identifier[cur_ident]))
        {
            stride++;
        }
        //进行预读，预读完成之后，如果是等号，说明是一个左值表达式
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident+stride])=="ASSIGN")
        {
            p=LVal();
            if(p!=NULL)
            {
                node->children.push_back(p);
            }
            addToTree(node);//紧接着将等号加入语法树当中
            //如果是getint
            if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="GETINTTK")
            {
                addToTree(node);

                //左括号
                addToTree(node);
                //如果是右括号
                if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RPARENT")
                {
                    addToTree(node);
                }

                else
                {
                    is_error=1;
                    errorDataList.push_back({get<2>(identifier[cur_ident-1]),'j'});
                }

                //如果是分号
                if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN"
                &&get<2>(identifier[cur_ident])==get<2>(identifier[cur_ident-1]))
                {
                    addToTree(node);
                }

                else
                {
                    is_error=1;
                    errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
                }

            }

            //如果是char
            else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="GETCHARTK")
            {
                addToTree(node);

                //左括号
                addToTree(node);
                //如果是右括号
                if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RPARENT")
                {
                    addToTree(node);
                }

                else
                {
                    is_error=1;
                    errorDataList.push_back({get<2>(identifier[cur_ident-1]),'j'});
                }

                //如果是分号
                if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN"
                &&get<2>(identifier[cur_ident])==get<2>(identifier[cur_ident-1]))
                {
                    addToTree(node);
                }

                else
                {
                    is_error=1;
                    errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
                }

            }

            //如果都不是，说明是一个表达式
            else
            {
                p=Exp();
                if(p!=NULL)
                {
                    node->children.push_back(p);
                }
                //之后再解析分号
                if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN"
                &&get<2>(identifier[cur_ident])==get<2>(identifier[cur_ident-1]))
                {
                    addToTree(node);
                }

                else
                {
                    is_error=1;
                    errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
                }
            }
        }
        //解析完LVal之后，如果不是等号，说明是一个表达式Exp

        else
        {
            p=Exp();
            if(p!=NULL)
            {
                node->children.push_back(p);
            }

            //之后再解析分号
            if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN"
            &&get<2>(identifier[cur_ident])==get<2>(identifier[cur_ident-1]))
            {
                addToTree(node);
            }

            else
            {
                is_error=1;
                errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
            }

        }
    }
 
    else//是[Exp] ';' // i的情况
    {
        if(isExp())
        {
            p=Exp();
            if(p!=NULL)
            {
                node->children.push_back(p);
            }
        }
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN"
        &&get<2>(identifier[cur_ident])==get<2>(identifier[cur_ident-1]))
        {
            addToTree(node);
        }

        else
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
        }
    }

    return node;
}

//语句块项 BlockItem → Decl | Stmt 
GrammarTree *BlockItem()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<BlockItem>";
    GrammarTree *p;

    //如果以const,int,char开头，则说明是Decl
    if(cur_ident<identifier.size()&&(get<1>(identifier[cur_ident])=="INTTK"
    ||get<1>(identifier[cur_ident])=="CHARTK"
    ||get<1>(identifier[cur_ident])=="CONSTTK"))
    {
        p=Decl();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    else//如果不是，则说明是其他类型的语句
    {
        p=Stmt();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    return node;
}

//语句块 Block → '{' { BlockItem } '}' 
GrammarTree *Block()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<Block>";
    GrammarTree *p;
    //首先解析一个左大括号
    addToTree(node);
    //接下来解析若干个BlockItem
    while(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])!="RBRACE")
    {
        //如果不是右大括号，说明是一个BlockItem

        p=BlockItem();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }

    //最后解析右大括号
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RBRACE")
    {
        addToTree(node);
    }
    return node;
}

//FuncFParam → BType Ident ['[' ']'] // k
GrammarTree *FuncFParam()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<FuncFParam>";
    GrammarTree *p;
    //首先是一个BType
    p=BType();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }

    //之后是标识符
    addToTree(node);

    //如果有中括号的话
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="LBRACK")
    {
        addToTree(node);
        //之后判断是不是右中括号
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RBRACK")
        {
            addToTree(node);
        }

        else
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'k'});
        }
    }
    return node;
}

//函数形参表 FuncFParams → FuncFParam { ',' FuncFParam } 
GrammarTree *FuncFParams()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<FuncFParams>";
    GrammarTree *p;

    //先解析一个FuncFParam
    p=FuncFParam();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }
    //循环解析 { ',' FuncFParam } 
    while(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="COMMA")
    {
        //先将逗号加入到语法树中
        addToTree(node);
        //之后解析一个FuncFParam
        p=FuncFParam();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    return node;
}

//函数类型 FuncType → 'void' | 'int' | 'char'
GrammarTree *FuncType()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<FuncType>";
    //它的子节点只能是int或者char或者void
    addToTree(node);
    return node;
}

 //MainFuncDef → 'int' 'main' '(' ')' Block // j
GrammarTree *MainFuncDef()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<MainFuncDef>";
    //将前三个非终结符加入到语法树
    addToTree(node);
    addToTree(node);
    addToTree(node);
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RPARENT")
    {
        addToTree(node);
    }
    else
    {
        is_error=1;
        errorDataList.push_back({get<2>(identifier[cur_ident-1]),'j'});
    }
    GrammarTree *p;
    //最后解析Block
    p=Block();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }
    return node;

}

//函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
GrammarTree *FuncDef()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<FuncDef>";
    GrammarTree *p;
    p=FuncType();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }
    //解析完函数返回值类型后，解析函数名。
    addToTree(node);

    //之后是处理左括号
    addToTree(node);

    //左括号完了之后是int或者char，则说明该函数有参数,先解析参数列表
    if(cur_ident<identifier.size()&&
    (get<1>(identifier[cur_ident])=="INTTK"
    ||get<1>(identifier[cur_ident])=="CHARTK"))
    {
        p=FuncFParams();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }

    //如果直接是右括号的话，说明参数列表结束
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RPARENT")
    {
        addToTree(node);
    }
    //如果没有右括号，说明出错。
    else
    {
        is_error=1;
        errorDataList.push_back({get<2>(identifier[cur_ident-1]),'j'});
    }
    //最后处理语句块Block
    p=Block();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }
    return node;
}

//变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst 
GrammarTree *InitVal()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<InitVal>";
    GrammarTree *p;
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="LBRACE")
    {//如果解析到了左括号，说明是第二种情况,先将左大括号加入到语法树中
        addToTree(node);

        //之后应该解析一个Exp
        p=Exp();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
        //循环解析 { ',' Exp } 
        while(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="COMMA")
        {
            //将逗号加入到语法树中
            addToTree(node);
            //解析Exp
            p=Exp();
            if(p!=NULL)
            {
                node->children.push_back(p);
            }
        }

        //如果解析完左括号之后，cur_ident指向的符号应该是右括号，将cur_ident加1，指向下一个词法成分
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RBRACE")
        {
            addToTree(node);
        }
    }

    //如果不是左括号，而是解析到一个字符串常量，将其作为该节点下的第一个孩子节点
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="STRCON")
    {
        //建立语法树的节点
        addToTree(node);
    }

    //如果都不是，说明解析到了单个Exp，需要对Exp进行分析
    else
    {
        p=Exp();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    return node;

}

//变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
GrammarTree *VarDef()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<VarDef>";
    GrammarTree *p;

    //如果是标识符，说明正确，将其作为该节点下的第一个孩子节点
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="IDENFR")
    {
        addToTree(node);
    }


    //如果是左括号，说明是一个数组，将其作为该节点下的第二个孩子节点
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="LBRACK")
    {
        addToTree(node);
        //解析完左括号之后应该是，应当是一个ConstExp
        p=ConstExp();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }

        //如果解析完ConstExp之后，cur_ident指向的符号应该是右括号，将cur_ident加1，指向下一个词法成分
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RBRACK")
        {
            addToTree(node);
        }
        else//如果不是右括号，则说明出错
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'k'});
        }
    }

    //如果是等号，说明是一个常量初始化值，将其作为该节点下的第三个孩子节点
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="ASSIGN")
    {
        addToTree(node);
        //解析完等号之后应该是，应当是一个ConstInitVal
        p=InitVal();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    return node;
}

//变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // i
GrammarTree *VarDecl()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<VarDecl>";
    GrammarTree *p;

    //解析BType，返回一个语法树节点
    p=BType();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }

    //解析一个VarDef
    p=VarDef();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }

    //之后循环解析 { ',' VarDef }
    while(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="COMMA")
    {
        addToTree(node);
        p=VarDef();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    //解析完VarDecl之后，cur_ident指向的符号应该是分号，将cur_ident加1,并将其作为语法树的最后一个孩子节点
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN"
    &&get<2>(identifier[cur_ident])==get<2>(identifier[cur_ident-1]))
    {
        addToTree(node);
    }

    else
    {
        is_error=1;
        errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
    }


    return node;
}

//常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
GrammarTree *ConstInitVal()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<ConstInitVal>";
    GrammarTree *p;

    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="LBRACE")
    {//如果以大括号开头，则先把大括号加入到语法树中
        addToTree(node);

        //解析完左括号之后应该是，应当是若干个ConstExp和逗号
        while(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])!="RBRACE")
        {
            if(get<1>(identifier[cur_ident])=="COMMA")
            {
                //如果解析到的符号是逗号，就新建立一个终结符节点,并将cur_ident加1
               addToTree(node);
            }
            //解析完左括号之后应该是，应当是一个ConstExp
            else
            {//如果不是括号，则说明解析到了一个ConstExp
                p=ConstExp();
                if(p!=NULL)
                {
                    node->children.push_back(p);
                }
            }
        }

        //如果解析完左括号之后，cur_ident指向的符号应该是右括号，将cur_ident加1，指向下一个词法成分
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RBRACE")
        {
            addToTree(node);
        }
    }

    //如果不是左括号，而是解析到一个字符串常量，将其作为该节点下的第一个孩子节点
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="STRCON")
    {
        addToTree(node);
    }

    //如果都不是，说明解析到了单个ConstExp，需要对ConstExp进行分析
    else
    {
        p=ConstExp();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    return node;
}

//ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
GrammarTree *ConstDef()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<ConstDef>";
    GrammarTree *p;

    //如果是标识符，说明正确，将其作为该节点下的第一个孩子节点
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="IDENFR")
    {
        addToTree(node);
    }

    //如果是左括号，说明是一个数组，将其作为该节点下的第二个孩子节点
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="LBRACK")
    {
        addToTree(node);

        //解析完左括号之后应该是，应当是一个ConstExp
        p=ConstExp();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }

        //如果解析完ConstExp之后，cur_ident指向的符号应该是右括号，将cur_ident加1，指向下一个词法成分
        if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="RBRACK")
        {
            addToTree(node);
        }
        else//如果不是右括号，则说明出错
        {
            is_error=1;
            errorDataList.push_back({get<2>(identifier[cur_ident-1]),'k'});
        }
    }

    //处理等号
    addToTree(node);
    //解析完等号之后应该是，应当是一个ConstInitVal
    p=ConstInitVal();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }
    return node;
}

//BType → 'int' | 'char' 
GrammarTree *BType()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    node->synt_component = "<BType>";
    //它的子节点只能是int或者char
    addToTree(node);
    return node;
}


//ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
GrammarTree *ConstDecl()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    GrammarTree *p;
    node->synt_component = "<ConstDecl>";

    //建立语法树的第一个孩子节点,该孩子节点为const字符串
    addToTree(node);
    //解析const之后的BType，返回一个语法树节点
    p=BType();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }

    //解析ConstDef，返回一个语法树节点
    p=ConstDef();
    if(p!=NULL)
    {
        node->children.push_back(p);
    }

    //之后循环解析{ ',' ConstDef } ，返回一个语法树节点
    while(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="COMMA")
    {
        //首先将逗号加入到语法树中
        addToTree(node);
        //之后解析ConstDef
        p=ConstDef();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }

    }

    //解析完ConstDecl之后，cur_ident指向的符号应该是分号，将cur_ident加1,并将其作为语法树的最后一个孩子节点

    //如果解析完ConstDecl之后，cur_ident指向的符号不是分号，说明语法错误
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="SEMICN"
    &&get<2>(identifier[cur_ident])==get<2>(identifier[cur_ident-1]))
    {
        addToTree(node);
    }
    else
    {//如果错误，则输出报错信息
        is_error=1;
        errorDataList.push_back({get<2>(identifier[cur_ident-1]),'i'});
    }
    return node;
}

// Decl → ConstDecl | VarDecl 
GrammarTree *Decl()
{
    //建立语法树的节点
    GrammarTree *node = new GrammarTree;
    GrammarTree *p;
    node->synt_component = "<Decl>";
    if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])=="CONSTTK")
    {//如果解析到的第一个符号是const,说明是一个常量声明
        p=ConstDecl();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    else if(cur_ident<identifier.size()&&get<1>(identifier[cur_ident])!="CONSTTK")
    {
        //说明是一个普通变量声明
        p=VarDecl();
        if(p!=NULL)
        {
            node->children.push_back(p);
        }
    }
    return node;
} 

//编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef 
void CompUnit()
{
    //建立语法树的根节点
    root = new GrammarTree;
    root->synt_component = "<CompUnit>";
    GrammarTree *p;
    //对CompUnit进行分析
    while(cur_ident<identifier.size())
    {
        if(get<1>(identifier[cur_ident])=="INTTK")//如果解析到INTTK
        {
            if(cur_ident+1<identifier.size()&&get<1>(identifier[cur_ident+1])=="MAINTK")
            {//预读，解析到main函数部分
                //对MainFuncDef进行分析，并将解释函数的返回值作为根节点的孩子节点
                p=MainFuncDef();
                if(p!=NULL)
                {
                    root->children.push_back(p);
                }
            }
            else if(cur_ident+1<identifier.size()&&get<1>(identifier[cur_ident+1])=="IDENFR")
            {//预读，解析到int后第二个单词是变量部分
                if(cur_ident+2<identifier.size()&&get<1>(identifier[cur_ident+2])=="LPARENT")
                {//预读，解析到int后第二个单词是变量部分，第三个单词是左括号,说明是函数定义部分，需要对FuncDef进行分析
                    //对FuncDef进行分析，并将解释函数的返回值作为根节点的孩子节点
                    p=FuncDef();
                    if(p!=NULL)
                    {
                        root->children.push_back(p);
                    }
                    
                }

                else if(cur_ident+2<identifier.size()&&get<1>(identifier[cur_ident+2])!="LPARENT")
                {//解析后发现是变量
                    //对VarDef进行分析，并将解释函数的返回值作为根节点的孩子节点
                    p=Decl();

                    if(p!=NULL)
                    {
                        root->children.push_back(p);
                    }
                }

            }
        }

        //如果解析到chartk
        else if(get<1>(identifier[cur_ident])=="CHARTK")
        {   //如果char后面是ident,在之后是(，那么说明是一个函数
            if(cur_ident+2<identifier.size()&&get<1>(identifier[cur_ident+2])=="LPARENT")
            {
                //对FuncDef进行分析，并将解释函数的返回值作为根节点的孩子节点
                p=FuncDef();
                if(p!=NULL)
                {
                    root->children.push_back(p);
                }
            }

            //如果不是（，那么说明是一个变量
            else if(cur_ident+2<identifier.size()&&get<1>(identifier[cur_ident+2])!="LPARENT")
            {
                //对VarDef进行分析，并将解释函数的返回值作为根节点的孩子节点
                p=Decl();
                if(p!=NULL)
                {
                    root->children.push_back(p);
                }
            }
        }

        //如果解析到void
        else if(get<1>(identifier[cur_ident])=="VOIDTK")
        {
            //如果void,说明是一个函数
            p=FuncDef();
            if(p!=NULL)
            {
                root->children.push_back(p);
            }
        }

        //如果解析到const
        else if(get<1>(identifier[cur_ident])=="CONSTTK")
        {
            p=Decl();
            //说明是一个变量声明
            if(p!=NULL)
            {
                root->children.push_back(p);
            }
        }
    }
}

// 词法分析器
int main(){
    //读取文件内容到字符串source中
    string filename = "testfile.txt";
    source = readFileIntoString(filename);

    //分别定义并打开输出正确信息和错误信息的文件
    correct.open("lexer.txt");
    error.open("error.txt");
    parser.open("parser.txt");
    //开始进行词法分析  
    while(curPos < source.length()){
        //跳过空白字符 
        if(curPos < source.length() && isspace(source.at(curPos))){
            if(source.at(curPos) == '\n'){
                lineNum++;
            }
            curPos++;
        }

        //解析标识符和保留字
        else if(isalpha(source.at(curPos))||source.at(curPos) == '_'){//如果是字母或者下划线开头
            token = "";
            token += source.at(curPos);
            curPos++;

            while(curPos < source.length() && 
            (isalpha(source.at(curPos)) || isdigit(source.at(curPos))||source.at(curPos) == '_')){
                //下一次字符为数字或字母或下划线
                token += source.at(curPos);
                curPos++;
            }

            //判断是否为保留字  
            if(reserveWords.find(token)!= reserveWords.end()){
            //如果是保留字
                lexType = reserveWords.find(token)->second;
            }
            else{
                lexType = "IDENFR";
            }
            identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
        }

        //解析数字
        else if(isdigit(source.at(curPos))){
            //如果是数字
            token = "";
            while(curPos < source.length() && isdigit(source.at(curPos))){
                token += source.at(curPos);
                curPos++;
            }
            lexType = "INTCON";
            identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
        }

        //解析单元符号
        else if(chars.find(source.substr(curPos,1))!= chars.end()){
            //如果是符号
            token = source.substr(curPos,1);
            lexType = chars.find(token)->second;
            identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
            curPos++;
        }

        //解析!和!=
        else if(source.substr(curPos,1) == "!"&&curPos < source.length()){
            //如果是!
            token = "";
            token += source.at(curPos);
            curPos++;

            if(curPos < source.length() && source.at(curPos) == '='){
                //如果是!=
                token += source.at(curPos);
                lexType = "NEQ";
                curPos++;
            }
            else{
                lexType = "NOT";
            }

            identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
        }

        //解析&&
        else if(source.substr(curPos,1) == "&"&&curPos < source.length()){
            //如果是&
            token = "";
            token += source.at(curPos);
            curPos++;
            if(curPos < source.length() && source.at(curPos) == '&'){
                //如果是&&
                token += source.at(curPos);
                lexType = "AND";
                identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
                curPos++;
            }
            else{
                //如果不是&&,则报错
                errorDataList.push_back({lineNum,'a'});
                is_error = 1;
                lexType = "AND";
                identifier.push_back(make_tuple("&&",lexType,lineNum));//将标识符加入到标识符表中
            }
        }

        //解析||
        else if(source.substr(curPos,1) == "|"&&curPos < source.length()){
            //如果是|
            token = "";
            token += source.at(curPos);
            curPos++;
            if(curPos < source.length() && source.at(curPos) == '|'){
                //如果是||
                token += source.at(curPos);
                lexType = "OR";
                identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
                curPos++;
            }
            else{
                //如果不是||,则报错
                errorDataList.push_back({lineNum,'a'});
                is_error = 1;
                lexType = "OR";
                identifier.push_back(make_tuple("||",lexType,lineNum));//将标识符加入到标识符表中
            }
        }

        //解析<=和<
        else if(source.substr(curPos,1) == "<"&&curPos < source.length()){
            //如果是<
            token = "";
            token += source.at(curPos);
            curPos++;

            if(curPos < source.length() && source.at(curPos) == '='){
                //如果是<=
                token += source.at(curPos);
                lexType = "LEQ";
                curPos++;
            }
            else{
                lexType = "LSS";
            }

            identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
        }

        //解析>=和>
        else if(source.substr(curPos,1) == ">"&&curPos < source.length()){
            //如果是>
            token = "";
            token += source.at(curPos);
            curPos++;

            if(curPos < source.length() && source.at(curPos) == '='){
                //如果是>=
                token += source.at(curPos);
                lexType = "GEQ";
                curPos++;
            }
            else{
                lexType = "GRE";
            }

            identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
        }

        //解析==和=
        else if(source.substr(curPos,1) == "="&&curPos < source.length()){
            //如果是=
            token = "";
            token += source.at(curPos);
            curPos++;

            if(curPos < source.length() && source.at(curPos) == '='){
                //如果是==
                token += source.at(curPos);
                lexType = "EQL";
                curPos++;
            }
            else{
                lexType = "ASSIGN";
            }

            identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
        }


        //解析字符常量
        else if(source.at(curPos) == '\''){
            //如果是字符常量
            token = "";
            token += source.at(curPos);
            curPos++;
            lexType = "CHRCON";

            if(curPos < source.length() && source.at(curPos) == '\\'){
                //如果是转义字符
                token += source.substr(curPos,3);
                curPos+=3;
            }

            else if(curPos < source.length() && source.at(curPos) != '\\'){
                //如果是字符常量
                token += source.substr(curPos,2);
                curPos+=2;
            }
            identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
        }

        //解析字符串常量
        else if(source.at(curPos) == '\"')
        {
            //如果是字符串常量
            token = "";
            token += source.at(curPos);
            curPos++;
            lexType = "STRCON";

            while(curPos < source.length() && source.at(curPos)!= '\"'){
                //如果是字符串常量
                token += source.at(curPos);
                if(source.substr(curPos,2) == "\n"){
                    //如果是换行符
                    lineNum++;
                }
                curPos++;
            }

            if(curPos < source.length() && source.at(curPos) == '\"'){
                //如果是字符串常量
                token += source.at(curPos);
                curPos++;
            }

            identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
        }

        //解析注释
        else if(source.at(curPos)== '/')
        {
            token = "";
            token += source.at(curPos);
            curPos++;
            if(curPos < source.length() && source.at(curPos) == '/')
            {
                curPos++;
                while(curPos < source.length() && source.at(curPos)!= '\n')
                {
                    //如果是//注释
                    curPos++;
                }
                if(curPos < source.length() && source.at(curPos) == '\n')
                {
                    curPos++;

                    //如果是//注释
                    lineNum++;
                }
            }
            else if(curPos < source.length() && source.at(curPos) == '*')
            {
                //如果是/*注释
                token += source.at(curPos);
                curPos++;
                while(curPos < source.length())
                {
                    if(source.at(curPos)=='\n')
                    {
                        //如果是/*注释
                        lineNum++;
                    }
                    if(source.substr(curPos,2) == "*/"&&curPos+1 < source.length())
                    {
                        //如果是/*注释
                        token += source.substr(curPos,2);
                        curPos+=2;
                        break;
                    }
                    else if(curPos+1 < source.length()&&source.substr(curPos,2)!="*/"){
                        //如果是/*注释
                        token += source.at(curPos);
                        curPos++;
                    }
                }

            }
            else
            {
                //如果不是注释
                lexType = "DIV";
                identifier.push_back(make_tuple(token,lexType,lineNum));//将标识符加入到标识符表中
            }
        }
    }

    //解析完之后，对标识符表进行分析
    CompUnit();
    if(is_error==0)
    {
    postOrderTraversal(root);
    }
    sort(errorDataList.begin(),errorDataList.end(),compareData);

    for(int i=0;i<errorDataList.size();i++)
    {
        error<<errorDataList[i].linenum<<" "<<errorDataList[i].errorType<<endl;
    }
    return 0;
}