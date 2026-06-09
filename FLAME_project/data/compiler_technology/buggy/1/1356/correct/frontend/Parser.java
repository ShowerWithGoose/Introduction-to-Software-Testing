package frontend;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Parser {
    private Lexer lexer;
    private ASTNode root;
    private String now;
    private String nowType;
    private int nowLine;
    private int lastLine;
    private PrintWriter parserOutput;
    private PrintWriter errorOutput;


    public Parser(Lexer lexer) {
        this.lexer = lexer;
        this.root = new ASTNode("CompUnit");
        this.now = "";
        this.nowType = "";
    }

    //调用端口
    public void parse() {
        try {
            parserOutput = new PrintWriter("parser.txt");
            errorOutput = new PrintWriter("error.txt");
            CompUnit();
            root.traverseOutput(root, parserOutput);
            parserOutput.close();
            errorOutput.close();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    //编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
    public void CompUnit() {
        next();
        while (true) {
            String preRead = preRead(1);
            String prePreRead = preRead(2);

            if (now.equals("int") && preRead.equals("MAINTK")) {
                ASTNode mainFuncDef = MainFuncDef();
                root.addChild(mainFuncDef);
                break;
            }
            else if (preRead.equals("IDENFR") && prePreRead.equals("LPARENT")) {
                ASTNode funcDef = FuncDef();
                root.addChild(funcDef);
            }
            else {
                ASTNode decl = Decl();
                root.addChild(decl);
            }
        }
        //lexerOutput.println("<CompUnit>");
    }

    //变量声明 Decl → ConstDecl | VarDecl
    public ASTNode Decl() {
        if (now.equals("const")) {
            return ConstDecl();
        }
        else {
            return VarDecl();
        }
    }

    //常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    public ASTNode ConstDecl() {
        ASTNode constDecl = new ASTNode("ConstDecl");
        if (now.equals("const")) {
            constDecl.addChild(nowNode());
            next();
            constDecl.addChild(BType());
            constDecl.addChild(ConstDef());
            while (now.equals(",")) {
                constDecl.addChild(nowNode());
                next();
                constDecl.addChild(ConstDef());
            }
            if (now.equals(";")) {
                constDecl.addChild(nowNode());
                next();
            }
            else {
                errorOutput.println(lastLine + " i");
            }
        }
        return constDecl;
    }

    //基本类型 BType → 'int' | 'char'
    public ASTNode BType() {
        if (now.equals("int") || now.equals("char")) {
            ASTNode bType = nowNode();
            next();
            return bType;
        }
        else {
            System.out.println("Error in BType: int or char");
            return nowNode();
        }
    }

    //常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    public ASTNode ConstDef() {
        ASTNode constDef = new ASTNode("ConstDef");
        if (nowType.equals("IDENFR")) {
            constDef.addChild(nowNode());
            next();
            if (now.equals("[")) {
                constDef.addChild(nowNode());
                next();
                constDef.addChild(ConstExp());
                if (now.equals("]")) {
                    constDef.addChild(nowNode());
                    next();
                }
                else {
                    errorOutput.println(lastLine + " k");
                }
            }
            if (now.equals("=")) {
                constDef.addChild(nowNode());
                next();
                constDef.addChild(ConstInitVal());
                //lexerOutput.println("<ConstDef>");
            }
        }
        return constDef;
    }

    //常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public ASTNode ConstInitVal() {
        ASTNode constInitVal = new ASTNode("ConstInitVal");
        if (now.equals("{")) {
            constInitVal.addChild(nowNode());
            next();
            if (now.equals("}")) {
                constInitVal.addChild(nowNode());
                next();
                //lexerOutput.println("<ConstInitVal>");
            }
            else {
                constInitVal.addChild(ConstExp());
                while (now.equals(",")) {
                    constInitVal.addChild(nowNode());
                    next();
                    constInitVal.addChild(ConstExp());
                }
                if (now.equals("}")) {
                    constInitVal.addChild(nowNode());
                    next();
                    //lexerOutput.println("<ConstInitVal>");
                }
            }
        }
        else if (nowType.equals("STRCON")) {
            constInitVal.addChild(nowNode());
            next();
            //lexerOutput.println("<ConstInitVal>");
        }
        else {
            constInitVal.addChild(ConstExp());
            //lexerOutput.println("<ConstInitVal>");
        }
        return constInitVal;
    }

    //变量声明 VarDecl → BType VarDef { ',' VarDef } ';'
    public ASTNode VarDecl() {
        ASTNode varDecl = new ASTNode("VarDecl");
        varDecl.addChild(BType());
        varDecl.addChild(VarDef());
        while (now.equals(",")) {
            varDecl.addChild(nowNode());
            next();
            varDecl.addChild(VarDef());
        }
        if (now.equals(";")) {
            varDecl.addChild(nowNode());
            next();
            //lexerOutput.println("<VarDecl>");
        }
        else {
            errorOutput.println(lastLine + " i");
        }
        return varDecl;
    }

    //变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    public ASTNode VarDef() {
        ASTNode varDef = new ASTNode("VarDef");
        if (nowType.equals("IDENFR")) {
            varDef.addChild(nowNode());
            next();
            if (now.equals("[")) {
                varDef.addChild(nowNode());
                next();
                varDef.addChild(ConstExp());
                if (now.equals("]")) {
                    varDef.addChild(nowNode());
                    next();
                }
                else {
                    errorOutput.println(lastLine + " k");
                }
            }
            if (now.equals("=")) {
                varDef.addChild(nowNode());
                next();
                varDef.addChild(InitVal());
                //lexerOutput.println("<VarDef>");
            }
        }
        return varDef;
    }

    //变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public ASTNode InitVal() {
        ASTNode initVal = new ASTNode("InitVal");
        if (now.equals("{")) {
            initVal.addChild(nowNode());
            next();
            if (now.equals("}")) {
                initVal.addChild(nowNode());
                next();
                //lexerOutput.println("<InitVal>");
            }
            else {
                initVal.addChild(Exp());
                while (now.equals(",")) {
                    initVal.addChild(nowNode());
                    next();
                    initVal.addChild(Exp());
                }
                if (now.equals("}")) {
                    initVal.addChild(nowNode());
                    next();
                    //lexerOutput.println("<InitVal>");
                }
                else {
                    System.out.println("Error in InitVal: }");
                }
            }
        }
        else if (nowType.equals("STRCON")) {
            initVal.addChild(nowNode());
            next();
            //lexerOutput.println("<InitVal>");
        }
        else {
            initVal.addChild(Exp());
            //lexerOutput.println("<InitVal>");
        }
        return initVal;
    }

    //函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    public ASTNode FuncDef() {
        ASTNode funcDef = new ASTNode("FuncDef");
        funcDef.addChild(FuncType());
        if (nowType.equals("IDENFR")) {
            funcDef.addChild(nowNode());
            next();
            if (now.equals("(")) {
                funcDef.addChild(nowNode());
                next();
                if (!now.equals(")") && !now.equals("{")) {
                    funcDef.addChild(FuncFParams());
                }
                if (now.equals(")")) {
                    funcDef.addChild(nowNode());
                    next();
                    funcDef.addChild(Block());
                    //lexerOutput.println("<FuncDef>");
                }
                else {
                    funcDef.addChild(new ASTNode(")", "RPARENT", lastLine));
                    errorOutput.println(lastLine + " j");
                    funcDef.addChild(Block());
                }
            }
            else {
                System.out.println("Error in FuncDef: (");
            }
        }
        else {
            System.out.println("Error in FuncDef: IDENFR");
        }
        return funcDef;
    }

    //主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block
    public ASTNode MainFuncDef() {
        ASTNode mainFuncDef = new ASTNode("MainFuncDef");
        if (now.equals("int")) {
            mainFuncDef.addChild(nowNode());
            next();
            if (now.equals("main")) {
                mainFuncDef.addChild(nowNode());
                next();
                if (now.equals("(")) {
                    mainFuncDef.addChild(nowNode());
                    next();
                    if (now.equals(")")) {
                        mainFuncDef.addChild(nowNode());
                        next();
                        mainFuncDef.addChild(Block());
                        //lexerOutput.println("<MainFuncDef>");
                    }
                    else {
                        mainFuncDef.addChild(new ASTNode(")", "RPARENT", lastLine));
                        errorOutput.println(lastLine + " j");
                        mainFuncDef.addChild(Block());
                    }
                }
                else {
                    System.out.println("Error in MainFuncDef: (");
                }
            }
            else {
                System.out.println("Error in MainFuncDef: main");
            }
        }
        else {
            System.out.println("Error in MainFuncDef: int");
        }
        return mainFuncDef;
    }

    //函数类型 FuncType → 'void' | 'int' | 'char'
    public ASTNode FuncType() {
        ASTNode funcType = new ASTNode("FuncType");
        if (now.equals("void") || now.equals("int") || now.equals("char")) {
            funcType.addChild(nowNode());
            next();
            //lexerOutput.println("<FuncType>");
        }
        else {
            System.out.println("Error in FuncType: void or int or char");
        }
        return funcType;
    }

    //函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
    public ASTNode FuncFParams() {
        ASTNode funcFParams = new ASTNode("FuncFParams");
        funcFParams.addChild(FuncFParam());
        while (now.equals(",")) {
            funcFParams.addChild(nowNode());
            next();
            funcFParams.addChild(FuncFParam());
        }
        //lexerOutput.println("<FuncFParams>");
        return funcFParams;
    }

    //函数形参 FuncFParam → BType Ident ['[' ']']
    public ASTNode FuncFParam() {
        ASTNode funcFParam = new ASTNode("FuncFParam");
        funcFParam.addChild(BType());
        if (nowType.equals("IDENFR")) {
            funcFParam.addChild(nowNode());
            next();
            if (now.equals("[")) {
                funcFParam.addChild(nowNode());
                next();
                if (now.equals("]")) {
                    funcFParam.addChild(nowNode());
                    next();
                }
                else {
                    errorOutput.println(lastLine + " k");
                }
            }
            //lexerOutput.println("<FuncFParam>");
        }
        else {
            System.out.println("Error in FuncFParam: IDENFR");
        }
        return funcFParam;
    }

    //语句块 Block → '{' { BlockItem } '}'
    public ASTNode Block() {
        ASTNode block = new ASTNode("Block");
        if (now.equals("{")) {
            block.addChild(nowNode());
            next();
            while (!now.equals("}")) {
                block.addChild(BlockItem());
            }
            if (now.equals("}")) {
                block.addChild(nowNode());
                next();
                //lexerOutput.println("<Block>");
            }
            else {
                System.out.println("Error in Block: }");
            }
        }
        else {
            System.out.println("Error in Block: {");
        }
        return block;
    }

    //语句块项 BlockItem → Decl | Stmt
    public ASTNode BlockItem() {
        if (now.equals("const") || now.equals("int") || now.equals("char")) {
            return Decl();
        }
        else {
            return Stmt();
        }
    }

    //语句 Stmt
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
    public ASTNode Stmt() {
        ASTNode stmt = new ASTNode("Stmt");
        // LVal 或 Exp
        if (nowType.equals("IDENFR")) {
            String preRead = preRead(1);
            if (preRead.equals("LBRACK") || preRead.equals("ASSIGN")) {
                stmt.addChild(LVal());
                if (now.equals("=")) {
                    stmt.addChild(nowNode());
                    next();
                    if (now.equals("getint") || now.equals("getchar")) {
                        stmt.addChild(nowNode());
                        next();
                        if (now.equals("(")) {
                            stmt.addChild(nowNode());
                            next();
                            if (now.equals(")")) {
                                stmt.addChild(nowNode());
                                next();
                            } else {
                                stmt.addChild(new ASTNode(")", "RPARENT", lastLine));
                                errorOutput.println(lastLine + " j");
                            }

                            if (now.equals(";")) {
                                stmt.addChild(nowNode());
                                next();
                                //lexerOutput.println("<Stmt>");
                            }
                            else {
                                errorOutput.println(lastLine + " i");
                            }
                        }
                        else {
                            System.out.println("Error in Stmt: (");
                        }
                    }
                    else {
                        stmt.addChild(Exp());
                        if (now.equals(";")) {
                            stmt.addChild(nowNode());
                            next();
                            //lexerOutput.println("<Stmt>");
                        }
                        else {
                            errorOutput.println(lastLine + " i");
                        }
                    }
                }
                else {
                    System.out.println("Error in Stmt: =");
                }
            }
            else {
                stmt.addChild(Exp());
                if (now.equals(";")) {
                    stmt.addChild(nowNode());
                    next();
                    //lexerOutput.println("<Stmt>");
                }
                else {
                    errorOutput.println(lastLine + " i");
                }
            }
        }
        // Block
        else if (now.equals("{")) {
            stmt.addChild(Block());
            //lexerOutput.println("<Stmt>");
        }
        // if
        else if (now.equals("if")) {
            stmt.addChild(nowNode());
            next();
            if (now.equals("(")) {
                stmt.addChild(nowNode());
                next();
                stmt.addChild(Cond());
                if (now.equals(")")) {
                    stmt.addChild(nowNode());
                    next();
                    stmt.addChild(Stmt());
                } else {
                    stmt.addChild(new ASTNode(")", "RPARENT", lastLine));
                    errorOutput.println(lastLine + " j");
                    stmt.addChild(Stmt());
                }
                if (now.equals("else")) {
                    stmt.addChild(nowNode());
                    next();
                    stmt.addChild(Stmt());
                }
                //lexerOutput.println("<Stmt>");
            }
            else {
                System.out.println("Error in Stmt: (");
            }
        }
        //for
        else if (now.equals("for")) {
            stmt.addChild(nowNode());
            next();
            if (now.equals("(")) {
                stmt.addChild(nowNode());
                next();
                if (!now.equals(";")) {
                    stmt.addChild(ForStmt());
                }
                if (now.equals(";")) {
                    stmt.addChild(nowNode());
                    next();
                    if (!now.equals(";")) {
                        stmt.addChild(Cond());
                    }
                    if (now.equals(";")) {
                        stmt.addChild(nowNode());
                        next();
                        if (!now.equals(")")) {
                            stmt.addChild(ForStmt());
                        }
                        if (now.equals(")")) {
                            stmt.addChild(nowNode());
                            next();
                            stmt.addChild(Stmt());
                            //lexerOutput.println("<Stmt>");
                        }
                        else {
                            stmt.addChild(new ASTNode(")", "RPARENT", lastLine));
                            errorOutput.println(lastLine + " j");
                            stmt.addChild(Stmt());
                        }
                    }
                    else {
                        System.out.println("Error in Stmt: ;");
                    }
                }
                else {
                    System.out.println("Error in Stmt: ;");
                }
            }
            else {
                System.out.println("Error in Stmt: (");
            }
        }
        //break
        else if (now.equals("break")) {
            stmt.addChild(nowNode());
            next();
            if (now.equals(";")) {
                stmt.addChild(nowNode());
                next();
                //lexerOutput.println("<Stmt>");
            }
            else {
                errorOutput.println(lastLine + " i");
            }
        }
        //continue
        else if (now.equals("continue")) {
            stmt.addChild(nowNode());
            next();
            if (now.equals(";")) {
                stmt.addChild(nowNode());
                next();
                //lexerOutput.println("<Stmt>");
            }
            else {
                errorOutput.println(lastLine + " i");
            }
        }
        //return
        else if (now.equals("return")) {
            stmt.addChild(nowNode());
            next();
            if (!now.equals(";")) {
                stmt.addChild(Exp());
            }
            if (now.equals(";")) {
                stmt.addChild(nowNode());
                next();
                //lexerOutput.println("<Stmt>");
            }
            else {
                errorOutput.println(lastLine + " i");
            }
        }
        //printf
        else if (now.equals("printf")) {
            stmt.addChild(nowNode());
            next();
            if (now.equals("(")) {
                stmt.addChild(nowNode());
                next();
                if (nowType.equals("STRCON")) {
                    stmt.addChild(nowNode());
                    next();
                    while (now.equals(",")) {
                        stmt.addChild(nowNode());
                        next();
                        stmt.addChild(Exp());
                    }
                    if (now.equals(")")) {
                        stmt.addChild(nowNode());
                        next();
                    } else {
                        stmt.addChild(new ASTNode(")", "RPARENT", lastLine));
                        errorOutput.println(lastLine + " j");
                    }
                    if (now.equals(";")) {
                        stmt.addChild(nowNode());
                        next();
                        //lexerOutput.println("<Stmt>");
                    }
                    else {
                        errorOutput.println(lastLine + " i");
                    }
                }
            }
        }
        //Exp
        else {
            if (now.equals("(") || nowType.equals("IDENFR") || nowType.equals("INTCON") || nowType.equals("CHRCON") || now.equals("+") || now.equals("-") || now.equals("!")) {
                stmt.addChild(Exp());
            }
            if (now.equals(";")) {
                stmt.addChild(nowNode());
                next();
                //lexerOutput.println("<Stmt>");
            }
            else {
                errorOutput.println(lastLine + " i");
            }
        }
        return stmt;
    }

    //语句 ForStmt → LVal '=' Exp
    public ASTNode ForStmt() {
        ASTNode forStmt = new ASTNode("ForStmt");
        forStmt.addChild(LVal());
        if (now.equals("=")) {
            forStmt.addChild(nowNode());
            next();
            forStmt.addChild(Exp());
            //lexerOutput.println("<ForStmt>");
        }
        else {
            System.out.println("Error in ForStmt: =");
        }
        return forStmt;
    }

    //表达式 Exp → AddExp
    public ASTNode Exp() {
        ASTNode exp = new ASTNode("Exp");
        exp.addChild(AddExp());
        //lexerOutput.println("<Exp>");
        return exp;
    }

    //条件表达式 Cond → LOrExp
    public ASTNode Cond() {
        ASTNode cond = new ASTNode("Cond");
        cond.addChild(LOrExp());
        //lexerOutput.println("<Cond>");
        return cond;
    }

    //左值表达式 LVal → Ident ['[' Exp ']']
    public ASTNode LVal() {
        ASTNode lVal = new ASTNode("LVal");
        if (nowType.equals("IDENFR")) {
            lVal.addChild(nowNode());
            next();
            if (now.equals("[")) {
                lVal.addChild(nowNode());
                next();
                lVal.addChild(Exp());
                if (now.equals("]")) {
                    lVal.addChild(nowNode());
                    next();
                }
                else {
                    errorOutput.println(lastLine + " k");
                }
            }
            //lexerOutput.println("<LVal>");
        }
        else {
            System.out.println("Error in LVal: IDENFR");
        }
        return lVal;
    }

    //基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character
    public ASTNode PrimaryExp() {
        ASTNode primaryExp = new ASTNode("PrimaryExp");
        if (now.equals("(")) {
            primaryExp.addChild(nowNode());
            next();
            primaryExp.addChild(Exp());
            if (now.equals(")")) {
                primaryExp.addChild(nowNode());
                next();
            }
            else {
                primaryExp.addChild(new ASTNode(")", "RPARENT", lastLine));
                errorOutput.println(lastLine + " j");
            }
        }
        else if (nowType.equals("IDENFR")) {
            primaryExp.addChild(LVal());
        }
        else if (nowType.equals("INTCON")) {
            primaryExp.addChild(myNumber());
        }
        else if (nowType.equals("CHRCON")) {
            primaryExp.addChild(myCharacter());
        }
        else {
            System.out.println("Error in PrimaryExp: ");
        }
        //lexerOutput.println("<PrimaryExp>");
        return primaryExp;
    }

    //数值 Number → IntConst
    public ASTNode myNumber() {
        ASTNode number = new ASTNode("Number");
        if (nowType.equals("INTCON")) {
            number.addChild(nowNode());
            next();
            //lexerOutput.println("<Number>");
        }
        else {
            System.out.println("Error in Number: INTCON");
        }
        return number;
    }

    //字符 Character → CharConst
    public ASTNode myCharacter() {
        ASTNode character = new ASTNode("Character");
        if (nowType.equals("CHRCON")) {
            character.addChild(nowNode());
            next();
            //lexerOutput.println("<Character>");
        }
        else {
            System.out.println("Error in Character: CHRCON");
        }
        return character;
    }

    //一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public ASTNode UnaryExp() {
        ASTNode unaryExp = new ASTNode("UnaryExp");
        if (now.equals("+") || now.equals("-") || now.equals("!")) {
            unaryExp.addChild(UnaryOp());
            unaryExp.addChild(UnaryExp());
        }
        else {
            String preRead = preRead(1);
            if(nowType.equals("IDENFR") && preRead.equals("LPARENT")) {
                unaryExp.addChild(nowNode());
                next();
                if (now.equals("(")) {
                    unaryExp.addChild(nowNode());
                    next();
                    if (!now.equals(")")) {
                        unaryExp.addChild(FuncRParams());
                    }
                    if (now.equals(")")) {
                        unaryExp.addChild(nowNode());
                        next();
                    }
                    else {
                        unaryExp.addChild(new ASTNode(")", "RPARENT", lastLine));
                        errorOutput.println(lastLine + " j");
                    }
                }
                else {
                    System.out.println("Error in UnaryExp: (");
                }
            }
            else {
                unaryExp.addChild(PrimaryExp());
            }
        }
        //lexerOutput.println("<UnaryExp>");
        return unaryExp;
    }

    //单目运算符 UnaryOp → '+' | '−' | '!'
    public ASTNode UnaryOp() {
        ASTNode unaryOp = new ASTNode("UnaryOp");
        if (now.equals("+") || now.equals("-") || now.equals("!")) {
            unaryOp.addChild(nowNode());
            next();
            //lexerOutput.println("<UnaryOp>");
        }
        else {
            System.out.println("Error in UnaryOp: + or - or !");
        }
        return unaryOp;
    }

    //函数实参表 FuncRParams → Exp { ',' Exp }
    public ASTNode FuncRParams() {
        ASTNode funcRParams = new ASTNode("FuncRParams");
        funcRParams.addChild(Exp());
        while (now.equals(",")) {
            funcRParams.addChild(nowNode());
            next();
            funcRParams.addChild(Exp());
        }
        //lexerOutput.println("<FuncRParams>");
        return funcRParams;
    }

    //乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public ASTNode MulExp() {
        ASTNode mulExp = new ASTNode("MulExp");
        mulExp.addChild(UnaryExp());
        //lexerOutput.println("<MulExp>");
        while (now.equals("*") || now.equals("/") || now.equals("%")) {
            ASTNode nextMulExp = new ASTNode("MulExp");
            nextMulExp.addChild(mulExp);
            nextMulExp.addChild(nowNode());
            next();
            nextMulExp.addChild(UnaryExp());
            mulExp = nextMulExp;
            //lexerOutput.println("<MulExp>");
        }
        return mulExp;
    }

    //加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
    public ASTNode AddExp() {
        ASTNode addExp = new ASTNode("AddExp");
        addExp.addChild(MulExp());
        //lexerOutput.println("<AddExp>");
        while (now.equals("+") || now.equals("-")) {
            ASTNode nextAddExp = new ASTNode("AddExp");
            nextAddExp.addChild(addExp);
            nextAddExp.addChild(nowNode());
            next();
            nextAddExp.addChild(MulExp());
            addExp = nextAddExp;
            //lexerOutput.println("<AddExp>");
        }
        return addExp;
    }

    //关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    public ASTNode RelExp() {
        ASTNode relExp = new ASTNode("RelExp");
        relExp.addChild(AddExp());
        //lexerOutput.println("<RelExp>");
        while (now.equals("<") || now.equals(">") || now.equals("<=") || now.equals(">=")) {
            ASTNode nextRelExp = new ASTNode("RelExp");
            nextRelExp.addChild(relExp);
            nextRelExp.addChild(nowNode());
            next();
            nextRelExp.addChild(AddExp());
            relExp = nextRelExp;
            //lexerOutput.println("<RelExp>");
        }
        return relExp;
    }

    //相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
    public ASTNode EqExp() {
        ASTNode eqExp = new ASTNode("EqExp");
        eqExp.addChild(RelExp());
        //lexerOutput.println("<EqExp>");
        while (now.equals("==") || now.equals("!=")) {
            ASTNode nextEqExp = new ASTNode("EqExp");
            nextEqExp.addChild(eqExp);
            nextEqExp.addChild(nowNode());
            next();
            nextEqExp.addChild(RelExp());
            eqExp = nextEqExp;
            //lexerOutput.println("<EqExp>");
        }
        return eqExp;
    }

    //逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
    public ASTNode LAndExp() {
        ASTNode lAndExp = new ASTNode("LAndExp");
        lAndExp.addChild(EqExp());
        //lexerOutput.println("<LAndExp>");
        while (now.equals("&&")) {
            ASTNode nextLAndExp = new ASTNode("LAndExp");
            nextLAndExp.addChild(lAndExp);
            nextLAndExp.addChild(nowNode());
            next();
            nextLAndExp.addChild(EqExp());
            lAndExp = nextLAndExp;
            //lexerOutput.println("<LAndExp>");
        }
        return lAndExp;
    }

    //逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
    public ASTNode LOrExp() {
        ASTNode lOrExp = new ASTNode("LOrExp");
        lOrExp.addChild(LAndExp());
        //lexerOutput.println("<LOrExp>");
        while (now.equals("||")) {
            ASTNode nextLOrExp = new ASTNode("LOrExp");
            nextLOrExp.addChild(lOrExp);
            nextLOrExp.addChild(nowNode());
            next();
            nextLOrExp.addChild(LAndExp());
            lOrExp = nextLOrExp;
            //lexerOutput.println("<LOrExp>");
        }
        return lOrExp;
    }

    //常量表达式 ConstExp → AddExp
    public ASTNode ConstExp() {
        ASTNode constExp = new ASTNode("ConstExp");
        constExp.addChild(AddExp());
        //lexerOutput.println("<ConstExp>");
        return constExp;
    }


    public int next() {
        int i = lexer.next();
        if (i == 0) {
            now = lexer.getToken();
            nowType = lexer.getTokenType();
            lastLine = nowLine;
            nowLine = lexer.getLine();
            //lexerOutput.println(nowType + " " + now);
        }
        else if (i == 1) {
            now = lexer.getToken();
            nowType = lexer.getTokenType();
            lastLine = nowLine;
            nowLine = lexer.getLine();
            errorOutput.println(nowLine + " a");
        }
        return i;
    }

    public ASTNode nowNode() {
        return new ASTNode(now, nowType, nowLine);
    }


    //预读
    public String preRead(int n) {
        Lexer lexer2 = new Lexer(lexer);
        if (n == 1) {
            lexer2.next();
            return lexer2.getTokenType();
        }
        else if (n == 2) {
            lexer2.next();
            lexer2.next();
            return lexer2.getTokenType();
        }
        else {
            lexer2.next();
            lexer2.next();
            lexer2.next();
            return lexer2.getTokenType();
        }
    }

    public ASTNode getRoot() {
        return root;
    }
}
