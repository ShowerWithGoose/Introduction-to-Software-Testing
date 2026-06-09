import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class GrammarTreeNode {
    List<GrammarTreeNode> ChildrenNode;
    Token token;
    ComponentType type;
    Boolean Terminator;

    static int deepth = 0;

    public enum ComponentType{
        // 文法单元
        COMPUNIT("<CompUnit>"),
        DECL("<Decl>"),
        CONSTDECL("<ConstDecl>"),
        VARDECL("<VarDecl>"),
        FUNCDEF("<FuncDef>"),
        MAINFUNCDEF("<MainFuncDef>"),

        // 基本类型和函数类型
        BTYPE("<BType>"),
        FUNCTYPE("<FuncType>"),

        // 常量定义和变量定义
        CONSTDEF("<ConstDef>"),
        VARDEF("<VarDef>"),
        CONSTINITVAL("<ConstInitVal>"),
        INITVAL("<InitVal>"),

        // 函数形参和函数实参
        FUNCFPARAMS("<FuncFParams>"),
        FUNCFPARAM("<FuncFParam>"),
        FUNCRPARAMS("<FuncRParams>"),

        // 语句块和语句块项
        BLOCK("<Block>"),
        BLOCKITEM("<BlockItem>"),

        // 语句
        STMT("<Stmt>"),

        // 条件表达式和其他表达式
        COND("<Cond>"),
        FORSTMT("<ForStmt>"),
        EXP("<Exp>"),
        UNARYEXP("<UnaryExp>"),
        UNARYOP("<UnaryOp>"),
        ADDEXP("<AddExp>"),
        MULEXP("<MulExp>"),
        RELEXP("<RelExp>"),
        EQEXP("<EqExp>"),
        LANDEXP("<LAndExp>"),
        LOREXP("<LOrExp>"),

        // 左值表达式和基本表达式
        LVAL("<LVal>"),
        PRIMARYEXP("<PrimaryExp>"),

        // 常量表达式
        CONSTEXP("<ConstExp>"),
        NUMBER("<Number>"),
        CHARACTER("<Character>"),

        // 终结符
//        INT("<int>"),
//        CHAR("<char>"),
//        CONST("<const>"),
//        VOID("<void>"),
//        IF("<if>"),
//        ELSE("<else>"),
//        FOR("<for>"),
//        RETURN("<return>"),
//        BREAK("<break>"),
//        CONTINUE("<continue>"),
//        MAIN("<main>"),
//        ASSIGN("<=>"),
//        LPAREN("<(>"),
//        RPAREN("<)>"),
//        LBRACE("<{>"),
//        RBRACE("<}>"),
//        LBRACK("<[>"),
//        RBRACK("<]>"),
//        COMMA("<,>"),
//        SEMICOLON("<;>"),
//        INTCONST("<IntConst>"),
//        CHARCONST("<CharConst>"),
//        STRINGCONST("<StringConst>"),

        // 未知或错误类型
        UNKNOWN("<Unknown>");

        private final String name;

        ComponentType(String name) {
            this.name = name;
        }

        @Override
        public String toString() {
            return name;
        }
    }

    GrammarTreeNode(Token token){
        this.ChildrenNode = new ArrayList<>();
        this.token = token;
        this.type = null;
        this.Terminator = true;
    }

    GrammarTreeNode(ComponentType type){
        this.ChildrenNode = new ArrayList<>();
        this.token = null;
        this.type = type;
        this.Terminator = false;
    }

    public GrammarTreeNode CreateTerminatorChildNode(Token ChildToken){
        GrammarTreeNode c = new GrammarTreeNode(ChildToken);
        ChildrenNode.add(c);
        return c;
    }

    public GrammarTreeNode CreateNonTerminatorChildNode(ComponentType ChildType){
        GrammarTreeNode c = new GrammarTreeNode(ChildType);
        ChildrenNode.add(c);
        return c;
    }

    public void DFS() {
        int i = 1;

        if(deepth > 256){
            deepth = deepth;
            return;
        }

        if (Terminator) {
            Parser.tree.add(token.type.getValue() + ' ' + token.content);
            deepth--;
            System.out.println(deepth);
        } else {
            for (GrammarTreeNode childNode : ChildrenNode) {
                deepth++;
                childNode.DFS();
            }
            if(type != ComponentType.BLOCKITEM && type != ComponentType.DECL && type != ComponentType.BTYPE){
                Parser.tree.add(type.toString());
            }
            deepth--;
            System.out.println(deepth);
        }
    }
}
