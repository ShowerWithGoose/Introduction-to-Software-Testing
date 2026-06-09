package Parser;

import Lexer.Token;

import Error.*;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import IO.*;

public class Parser {
    private List<Token> tokens;
    private int currentTokenIndex = 0;

    private errorMessage errorMessage;
    private ArrayList<String> output;
    private BufferedWriter writer;

    public Parser(List<Token> tokens, errorMessage errorMessage,IO io) {
        this.tokens = tokens;
        this.writer = io.getParserWriter();
        this.output = new ArrayList<>();
        this.errorMessage = errorMessage;
    }

    private Token currentToken() {
        return this.tokens.get(currentTokenIndex);
    }

    private Token NextToken1() {
        if (currentTokenIndex + 1 < tokens.size()) {
            return tokens.get(currentTokenIndex + 1);
        } else {
            return null;
        }
    }

    private Token NextToken2() {
        if (currentTokenIndex + 2 < tokens.size()) {
            return tokens.get(currentTokenIndex + 2);
        } else {
            return null;
        }
    }

    private Token NextToken3() {
        if (currentTokenIndex + 3 < tokens.size()) {
            return tokens.get(currentTokenIndex + 3);
        } else {
            return null;
        }
    }

    private Token NextToken(int i) {
        if (currentTokenIndex + i < tokens.size()) {
            return tokens.get(currentTokenIndex + i);
        } else {
            return null;
        }
    }

    private Token LToken1() {
        if (currentTokenIndex - 1 >= 0) {
            return tokens.get(currentTokenIndex - 1);
        } else {
            return null;
        }
    }

    private Token LToken2() {
        if (currentTokenIndex - 2 >= 0) {
            return tokens.get(currentTokenIndex - 2);
        } else {
            return null;
        }
    }

    private Token LToken3() {
        if (currentTokenIndex - 3 >= 0) {
            return tokens.get(currentTokenIndex - 3);
        } else {
            return null;
        }
    }


    private void eat(String expectedType) {
        if (currentToken().getType().equals(expectedType)) {
            output.add(currentToken().getType() + " " + currentToken().getToken() + "\n");
            currentTokenIndex++;
        } else {
            if (expectedType.equals("SEMICN")) {
                errorMessage.addError(new error(null, LToken1().getLineNumber(), "i"));
            } else if (expectedType.equals("RPARENT")) {
                errorMessage.addError(new error(null, LToken1().getLineNumber(), "j"));
            } else if (expectedType.equals("RBRACK")){
                errorMessage.addError(new error(null, LToken1().getLineNumber(), "k"));
            }
//            throw new RuntimeException("LToken3: " + LToken3().getType() + " " + LToken3().getToken() + "\n" +
//                    "LToken2: " + LToken2().getType() + " " + LToken2().getToken() + "\n" +
//                    "LToken1: " + LToken1().getType() + " " + LToken1().getToken() + "\n"
//            + "Syntax Error: Expected " + expectedType + ", found " + currentToken().getType() + "\n" +
//              "Next1"  +  NextToken1().getType() + " " + NextToken1().getToken() + "\n" +
//                    "Next2"  +       NextToken2().getType() + " " + NextToken2().getToken() + "\n" +
//                    "Next3"  +     NextToken3().getType() + " " + NextToken3().getToken() + "\n");

        }
    }

    // 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
    public void parseCompUnit() throws IOException {
        while(isDecl()) {
            parseDecl();
        }
        while(isFuncDef() && !isMainFuncDef()) {
            parseFuncDef();
        }
        parseMainFuncDef();
        output.add("<CompUnit>\n");
        printOutput();
    }

    // 主函数定义 MainFuncDef → 'int' 'Compiler' '(' ')' Block
    private void parseMainFuncDef() {
        eat("INTTK");
        eat("MAINTK");
        eat("LPARENT");
        eat("RPARENT");
        parseBlock();
       output.add("<MainFuncDef>\n");
    }

    // 判断是否是Decl
    private boolean isDecl() {
        if (currentToken().getType().equals("CONSTTK")) {
            return true;
        }
        if ((currentToken().getType().equals("INTTK") || currentToken().getType().equals("CHARTK"))
                && !Objects.requireNonNull(NextToken2()).getType().equals("LPARENT")) {
            return true;
        }
        return false;
    }

    private boolean isFuncDef() {
        return (currentToken().getType().equals("INTTK") || currentToken().getType().equals("CHARTK") ||
                currentToken().getType().equals("VOIDTK")) && (Objects.requireNonNull(NextToken1()).getType().equals("IDENFR"));
    }

    private boolean isMainFuncDef() {
        return currentToken().getType().equals("INTTK") && Objects.requireNonNull(NextToken1()).getType().equals("MAINTK");
    }

    // 声明 Decl → ConstDecl | VarDecl
    public void parseDecl() {
        if (isConst()) {
            parseConstDecl();
        } else {
            parseVarDecl();
        }
    }

    private boolean isConst() {
        return currentToken().getType().equals("CONSTTK");
    }

    private boolean isVar() {
        return currentToken().getType().equals("INTTK") || currentToken().getType().equals("FLOATTK") ||
                currentToken().getType().equals("CHARTK");
    }

    // 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    private void parseFuncDef() {
        parseFuncType();
        eat("IDENFR");
        eat("LPARENT");
        if (!currentToken().getType().equals("RPARENT")) {
            parseFuncFParams();
        }
        eat("RPARENT");
        parseBlock();
       output.add("<FuncDef>\n");
    }

    // 语句块 Block → '{' { BlockItem } '}'
    private void parseBlock() {
        eat("LBRACE");
        while (!currentToken().getType().equals("RBRACE")) {
            parseBlockItem();
        }
        eat("RBRACE");
       output.add("<Block>\n");
    }

    // 语句块项 BlockItem → Decl | Stmt
    private void parseBlockItem() {
        if ((currentToken().getType().equals("INTTK")|| currentToken().getType().equals("CHARTK")) || currentToken().getType().equals("CONSTTK")) {
            parseDecl();
        } else {
            parseStmt();
        }
    }

    private boolean BeginExp() {
        return currentToken().getType().equals("LPARENT") || currentToken().getType().equals("IDENFR") ||
                currentToken().getType().equals("INTTK") ||
                currentToken().getType().equals("CHARTK") ||
                currentToken().getType().equals("LPARENT") || currentToken().getType().equals("MINU") ||
                currentToken().getType().equals("PLUS") || currentToken().getType().equals("NOT") ||
                currentToken().getType().equals("INTCON") ||
                 currentToken().getType().equals("CHRCON") ;
    }

    // 语句 Stmt → LVal '=' Exp ';' | [Exp] ';' | Block
    //            | 'if' '( Cond ')' Stmt [ 'else' Stmt ]
    //            | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    //            | 'break' ';'
    //            | 'continue' ';'
    //            | 'return' [Exp] ';'
    //            | LVal '=' 'getint''('')'';'
    //            | LVal '=' 'getchar''('')'';'
    //            | 'printf''('StringConst {','Exp}')'';'


    private boolean isLVal() {
        for (int i = 1; !Objects.equals(NextToken(i).getToken(), ";"); i++) {
            if (Objects.equals(NextToken(i).getToken(), "=")) {
                return true;
            }
        }
        return false;
    }
    private void parseStmt() {
        if (currentToken().getType().equals("IDENFR")) {
            if (isLVal()) {
                parseLVal();
                eat("ASSIGN");
                if (currentToken().getType().equals("GETINTTK")) {
                    eat("GETINTTK");
                    eat("LPARENT");
                    eat("RPARENT");
                    eat("SEMICN");
                } else if (currentToken().getType().equals("GETCHARTK")) {
                    eat("GETCHARTK");
                    eat("LPARENT");
                    eat("RPARENT");
                    eat("SEMICN");
                } else {
                    parseExp();
                    eat("SEMICN");
                }
            } else {
                if (!currentToken().getType().equals("SEMICN")) {
                    parseExp();
                    eat("SEMICN");
                } else {
                    eat("SEMICN");
                }
            }

        } else if (currentToken().getType().equals("IFTK")) {
            eat("IFTK");
            eat("LPARENT");
            parseCond();
            eat("RPARENT");
            parseStmt();
            if (currentToken().getType().equals("ELSETK")) {
                eat("ELSETK");
                parseStmt();
            }
        }
        // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        else if (currentToken().getType().equals("FORTK")) {
            eat("FORTK");
            eat("LPARENT");
            if (!currentToken().getType().equals("SEMICN")) {
                parseForStmt();
            }
            eat("SEMICN");
            if (!currentToken().getType().equals("SEMICN")) {
                parseCond();
            }
            eat("SEMICN");
            if (!currentToken().getType().equals("RPARENT")) {
                parseForStmt();
            }
            eat("RPARENT");
            parseStmt();
        } else if (currentToken().getType().equals("BREAKTK")) {
            eat("BREAKTK");
            eat("SEMICN");
        } else if (currentToken().getType().equals("CONTINUETK")) {
            eat("CONTINUETK");
            eat("SEMICN");
        } else if (currentToken().getType().equals("RETURNTK")) {
            eat("RETURNTK");
            if (!currentToken().getType().equals("SEMICN")) {
                parseExp();
            }
            eat("SEMICN");
        } else if (currentToken().getType().equals("PRINTFTK")) {
            eat("PRINTFTK");
            eat("LPARENT");
            parseStringConst();
            while (currentToken().getType().equals("COMMA")) {
                eat("COMMA");
                parseExp();
            }
            eat("RPARENT");
            eat("SEMICN");
        } else if (currentToken().getType().equals("SEMICN")){
            eat("SEMICN");
        } else if (BeginExp()){
            parseExp();
            eat("SEMICN");
        } else {
            parseBlock();
        }
       output.add("<Stmt>\n");
    }

    private void parseStringConst() {
        eat("STRCON");
    }

    // 语句 ForStmt → LVal '=' Exp
    private void parseForStmt() {
        parseLVal();
        eat("ASSIGN");
        parseExp();
       output.add("<ForStmt>\n");
    }

    // 条件表达式 Cond → LOrExp
    private void parseCond() {
        parseLOrExp();
        output.add("<Cond>\n");
    }

    // 逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
    private void parseLOrExp() {
        parseLAndExp();
        while (currentToken().getType().equals("OR")) {
           output.add("<LOrExp>\n");
            eat("OR");
            parseLAndExp();
        }
       output.add("<LOrExp>\n");
    }

    // 逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
    private void parseLAndExp() {
        parseEqExp();
        while (currentToken().getType().equals("AND")) {
           output.add("<LAndExp>\n");
            eat("AND");
            parseEqExp();
        }
       output.add("<LAndExp>\n");
    }

    // 相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
    private void parseEqExp() {
        parseRelExp();
        if (currentToken().getType().equals("EQL") || currentToken().getType().equals("NEQ")) {
           output.add("<EqExp>\n");
            eat(currentToken().getType());
            parseRelExp();
        }
       output.add("<EqExp>\n");
    }

    // 关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    private void parseRelExp() {
        parseAddExp();
        while (currentToken().getType().equals("LSS") || currentToken().getType().equals("LEQ") ||
                currentToken().getType().equals("GRE") || currentToken().getType().equals("GEQ")) {
           output.add("<RelExp>\n");
            eat(currentToken().getType());
            parseAddExp();
        }
       output.add("<RelExp>\n");
    }

    // 左值表达式 LVal → Ident {'[' Exp ']'}
    private void parseLVal() {
        eat("IDENFR");
        while (currentToken().getType().equals("LBRACK")) {
            eat("LBRACK");
            parseExp();
            eat("RBRACK");
        }
       output.add("<LVal>\n");
    }

    // 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
    private void parseFuncFParams() {
        parseFuncFParam();
        while (currentToken().getType().equals("COMMA")) {
            eat("COMMA");
            parseFuncFParam();
        }
       output.add("<FuncFParams>\n");
    }

    // 函数形参 FuncFParam → BType Ident ['[' ']']
    private void parseFuncFParam() {
        parseBType();
        eat("IDENFR");
        if (currentToken().getType().equals("LBRACK")) {
            eat("LBRACK");
            eat("RBRACK");
        }
       output.add("<FuncFParam>\n");
    }

    // 函数类型 FuncType → 'void' | 'int' | 'char'
    private void parseFuncType() {
        if (currentToken().getType().equals("VOIDTK") || currentToken().getType().equals("INTTK") || currentToken().getType().equals("CHARTK")) {
            eat(currentToken().getType());
        } else {
            throw new RuntimeException("Syntax Error: Expected 'void', 'int', or 'float', found " + currentToken().getType());
        }
       output.add("<FuncType>\n");
    }

    // 常量声明：  ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    private void parseConstDecl() {
        eat("CONSTTK");
        parseBType();
        parseConstDef();
        while (currentToken().getType().equals("COMMA")) {
            eat("COMMA");
            parseConstDef();
        }
        eat("SEMICN");
       output.add("<ConstDecl>\n");
    }

    // 变量声明 VarDecl → BType VarDef { ',' VarDef } ';'
    private void parseVarDecl() {
        parseBType();
        parseVarDef();
        while (currentToken().getType().equals("COMMA")) {
            eat("COMMA");
            parseVarDef();
        }
        eat("SEMICN");
       output.add("<VarDecl>\n");
    }

    // 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    private void parseVarDef() {
        eat("IDENFR");
        if (currentToken().getType().equals("LBRACK")) {
            eat("LBRACK");
            parseConstExp();
            eat("RBRACK");
        }
        if (currentToken().getType().equals("ASSIGN")) {
            eat("ASSIGN");
            parseInitVal();
        }
       output.add("<VarDef>\n");
    }

    // 变量初值 InitVal → Exp | '{' [ InitVal { ',' InitVal } ] '}' | StringConst
    private void parseInitVal() {
        if (currentToken().getType().equals("LBRACE")) {
            eat("LBRACE");
            parseExp();
            while (currentToken().getType().equals("COMMA")) {
                eat("COMMA");
                parseExp();
            }
            eat("RBRACE");
        } else if (currentToken().getType().equals("STRCON")){
            parseStringConst();
        } else {
            parseExp();
        }
       output.add("<InitVal>\n");
    }

    // 表达式 Exp → AddExp
    private void parseExp() {
        parseAddExp();
       output.add("<Exp>\n");
    }

    // 基本类型 BType → 'int' | 'char'
    private void parseBType() {
        if (currentToken().getType().equals("INTTK") || currentToken().getType().equals("CHARTK")) {
            eat(currentToken().getType());
        } else {
            throw new RuntimeException("Syntax Error: Expected 'int' or 'float', found " + currentToken().getType());
        }
    }

    // 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    private void parseConstDef() {
        eat("IDENFR");
        if (currentToken().getType().equals("LBRACK")) {
            eat("LBRACK");
            parseConstExp();
            eat("RBRACK");
        }
        eat("ASSIGN");
        parseConstInitVal();
       output.add("<ConstDef>\n");
    }

    // 常量表达式 ConstExp → AddExp
    private void parseConstExp() {
        parseAddExp();
       output.add("<ConstExp>\n");

    }

    // 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private void parseConstInitVal() {
        if (currentToken().getType().equals("LBRACE")) {
            eat("LBRACE");
            if (currentToken().getType().equals("RBRACE")) {
                eat("RBRACE");
            } else {
                parseConstExp();
                while (currentToken().getType().equals("COMMA")) {
                    eat("COMMA");
                    parseConstExp();
                }
                eat("RBRACE");
            }
        } else if (currentToken().getType().equals("STRCON")) {
            parseStringConst();
        } else {
            parseConstExp();
        }
       output.add("<ConstInitVal>\n");
    }

    // 加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
    private void parseAddExp() {
        parseMulExp();
        while (currentToken().getType().equals("PLUS") || currentToken().getType().equals("MINU")) {
           output.add("<AddExp>\n");
            eat(currentToken().getType());
            parseMulExp();
        }
       output.add("<AddExp>\n");
    }

    // 乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private void parseMulExp() {
        parseUnaryExp();
        while (currentToken().getType().equals("MULT") || currentToken().getType().equals("DIV") || currentToken().getType().equals("MOD")) {
           output.add("<MulExp>\n");
            eat(currentToken().getType());
            parseUnaryExp();
        }
       output.add("<MulExp>\n");
    }

    // 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    private void parseUnaryExp() {
        if (isUnaryOp()) {
            parseUnaryOp();
            parseUnaryExp();
        } else if (currentToken().getType().equals("IDENFR")) {
            if (Objects.requireNonNull(NextToken1()).getType().equals("LPARENT")) {
                eat("IDENFR");
                eat("LPARENT");
                if (!currentToken().getType().equals("RPARENT")) {
                    parseFuncRParams();
                }
                eat("RPARENT");
            } else {
                parsePrimaryExp();
            }
        } else {
            parsePrimaryExp();
        }
       output.add("<UnaryExp>\n");
    }

    //  UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
    private void parseUnaryOp() {
        eat(currentToken().getType());
       output.add("<UnaryOp>\n");
    }

    // 函数实参表 FuncRParams → Exp { ',' Exp }
    private void parseFuncRParams() {
        parseExp();
        while (currentToken().getType().equals("COMMA")) {
            eat("COMMA");
            parseExp();
        }
       output.add("<FuncRParams>\n");
    }

    private boolean isUnaryOp() {
        return currentToken().getType().equals("PLUS") ||
                currentToken().getType().equals("MINU") ||
                currentToken().getType().equals("NOT");
    }

    // 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character
    private void parsePrimaryExp() {
        if (currentToken().getType().equals("LPARENT")) {
            eat("LPARENT");
            parseExp();
            eat("RPARENT");
        } else if (currentToken().getType().equals("IDENFR")) {
            parseLVal();
        } else if (currentToken().getType().equals("INTCON")) {
            parseNumber();
        } else if (currentToken().getType().equals("CHRCON")) {
            parseCharacter();
        } else if (currentToken().getType().equals("RBRACE")) {

        }
        else {
            System.out.println(currentToken().getType() + " " + currentToken().getToken() + " " + currentToken().getLineNumber());
            throw new RuntimeException("Syntax Error: Expected '(', 'IDENFR', or number, found " + currentToken().getType());
        }
       output.add("<PrimaryExp>\n");
    }

    // 字符 Character → CharConst
    private void parseCharacter() {
        eat("CHRCON");
       output.add("<Character>\n");
    }

    // 数值 Number → IntConst | floatConst
    private void parseNumber() {
        if (currentToken().getType().equals("INTCON")) {
            eat("INTCON");
        } else {
            throw new RuntimeException("Syntax Error: Expected 'INTCON' or 'FLOATCON', found " + currentToken().getType());
        }
       output.add("<Number>\n");
    }

    private void printOutput() throws IOException {
        for (String s : output) {
//            System.out.println(s);
            writer.write(s);
        }
        writer.flush(); // 确保数据写入文件
        writer.close(); // 关闭文件
    }


}