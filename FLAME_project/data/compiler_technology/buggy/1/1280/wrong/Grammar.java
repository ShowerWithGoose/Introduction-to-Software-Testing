import java.io.FileDescriptor;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.AbstractSet;
import java.util.ArrayList;
import java.util.function.Supplier;

public class Grammar {

    private int noneTerminalLine;
    private int noneTerminalColumn;
    private int wordPoint;
    private final ArrayList<Word> words;

    private final ArrayList<Error> errors = new ArrayList<>();
    private final ArrayList<String> outStr = new ArrayList<>();

    public Grammar(ArrayList<Word> words) {
        this.noneTerminalLine = 1;
        this.noneTerminalColumn = 1;
        this.words = words;
        this.wordPoint = 0;
    }

    public void analyze() {
        CompUnit();
    }

    private void CompUnit() {
        //CompUnit → {Decl} {FuncDef} MainFuncDef
        updateNumber();

        while (true) {
            Word word = words.get(wordPoint);
            if (word == null) {
                return;
            }
            if (word.getType() == Type.CONSTTK) {   //常量
                Decl();
            } else if (word.getType() == Type.CHARTK) {  //CHAR变量或函数
                Type type = words.get(wordPoint + 2).getType();
                if (type == Type.LPARENT) {  //左括号，函数
                    FuncDef();
                } else {    //char变量
                    Decl();
                }
            } else if (word.getType() == Type.INTTK) {
                //int 三种都有可能
                if (words.get(wordPoint + 1).getType() == Type.MAINTK) {   //主函数
                    MainFuncDef();
                    break; //结束编译单元
                }
                Type type = words.get(wordPoint + 2).getType();
                if (type == Type.LPARENT) {  //左括号，函数
                    FuncDef();
                } else {    //int变量
                    Decl();
                }
            } else if (word.getType() == Type.VOIDTK) { // void函数
                FuncDef();
            }
            else {
                System.out.printf("Error : Invalid Type! : %s in line %d%n", word.getType().toString(), word.getLine());
                return;
            }
        }
        outStr.add("<CompUnit>");
    }

    private void Decl() {
        //Decl → ConstDecl | VarDecl
        updateNumber();
        Word word = words.get(wordPoint);
        if (word.getType() == Type.CONSTTK) {
            ConstDecl();
        } else {
            VarDecl();
        }
    }

    private void VarDecl() {
        // VarDecl → BType VarDef { ',' VarDef } ';'
        updateNumber();
        //BType
        addOut();
        while (true) {
            VarDef();
            if (words.get(wordPoint).getType() == Type.SEMICN) {
                //分号出循环
                addOut();
                break;
            }
            //逗号
            if (words.get(wordPoint).getType() == Type.COMMA) {
                addOut();
            } else {
                //不是逗号，出错，即缺少分号
                addError('i');
                //继续下面的处理，默认有分号
                break;
            }
        }
        outStr.add("<VarDecl>");
    }

    private void VarDef() {
        //VarDef → Ident [ '[' ConstExp ']' ]
        //  | Ident [ '[' ConstExp ']' ] '=' InitVal
        updateNumber();
        //Ident
        addOut();
        //是否数组
        if (words.get(wordPoint).getType() == Type.LBRACK) {
            //' [ '
            addOut();
            //ConstExp
            ConstExp();
            //' ] '
            if (words.get(wordPoint).getType() == Type.RBRACK) {
                //添加右括号
                addOut();
            } else {    //不是右括号，报错
                addError('k');
            }
        }
        // 是否赋初值
        if (words.get(wordPoint).getType() == Type.ASSIGN) {
            addOut();
            InitVal();
        }
        outStr.add("<VarDef>");
    }

    private void InitVal() {
        //InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        updateNumber();
        Type type = words.get(wordPoint).getType();
        if (type == Type.LBRACE) {  //左大括号
            addOut();
            while (true) {
                Exp();
                if (words.get(wordPoint).getType() == Type.RBRACE) {
                    //右大括号出
                    addOut();
                    break;
                }
                //逗号继续
                addOut();
            }
        } else if (type == Type.STRCON) {
            addOut();
        } else {
            Exp();
        }
        outStr.add("<InitVal>");
    }

    private void Exp() {
        //Exp → AddExp
        updateNumber();
        AddExp();
        outStr.add("<Exp>");
    }

    private void ConstDecl() {
        //ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
        updateNumber();
        //进入肯定是const
        addOut();
        //BType无需
        addOut();
        //constDef的重复，逗号为间隔，分号为结束
        while (true) {
            ConstDef();
            if (words.get(wordPoint).getType() == Type.SEMICN) {    //若是分号
                addOut();
                break;
            }
            //否则逗号
            if (words.get(wordPoint).getType() == Type.COMMA) {
                addOut();
            } else {
                //不是逗号，出错，即缺少分号
                addError('i');
                //默认有分号，继续下面处理
                break;
            }
        }
        outStr.add("<ConstDecl>");
    }

    private void ConstDef() {
        // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        updateNumber();
        //语法上，Ident 终结符 直接添加
        addOut();
        //若有左方括号
        if (words.get(wordPoint).getType() == Type.LBRACK) {
            addOut();
            ConstExp();
            //右括号终结
            if (words.get(wordPoint).getType() == Type.RBRACK) {
                //添加右括号
                addOut();
            } else {    //不是右括号，报错
                addError('k');
            }
        }
        //=
        addOut();
        //ConstInitVal
        ConstInitVal();
        //非终结符结束
        outStr.add("<ConstDef>");
    }

    private void ConstInitVal() {
        //ConstInitVal → ConstExp |
        //      '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        updateNumber();
        Type type = words.get(wordPoint).getType();
        if (type == Type.LBRACE) {    //一维数组初始值
            addOut();
            while (true) {
                ConstExp();
                if (words.get(wordPoint).getType() == Type.RBRACE) {
                    //当右大括号，出
                    addOut();
                    break;
                }
                //否则为逗号
                addOut();
            }
        } else if (type == Type.STRCON) {   //字符串常量
            addOut();
        } else {
            ConstExp();
        }
        outStr.add("<ConstInitVal>");
    }

    private void ConstExp() {
        // ConstExp → AddExp
        updateNumber();
        AddExp();
        outStr.add("<ConstExp>");
    }

    private void AddExp() {
        // AddExp → MulExp | AddExp ('+' | '−') MulExp
        updateNumber();
        MulExp();
        while (words.get(wordPoint).getType() == Type.PLUS
                || words.get(wordPoint).getType() == Type.MINU) {
            outStr.add("<AddExp>");

            addOut();
            MulExp();
        }
        outStr.add("<AddExp>");
    }

    private void MulExp() {
        // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        updateNumber();
        UnaryExp();
        while (words.get(wordPoint).getType() == Type.MULT
                || words.get(wordPoint).getType() == Type.DIV
                || words.get(wordPoint).getType() == Type.MOD
                ) {
            outStr.add("<MulExp>");

            addOut();
            UnaryExp();
        }

        outStr.add("<MulExp>");
    }

    private void UnaryExp() {
        // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        updateNumber();
        Type type = words.get(wordPoint).getType();
        if (type == Type.PLUS
                || type == Type.MINU
                || type == Type.NOT) {
            UnaryOp();
            UnaryExp();
        } else if (type == Type.IDENFR
                && words.get(wordPoint + 1).getType() == Type.LPARENT) {
            //Ident
            addOut();
            //'('
            addOut();
            while (words.get(wordPoint).getType() != Type.RPARENT) {
                FuncRParams();
            }
            //')'
            if (words.get(wordPoint).getType() == Type.RPARENT) {
                addOut();
            } else {
                addError('j');
            }
        } else {
            PrimaryExp();
        }

        outStr.add("<UnaryExp>");
    }

    private void PrimaryExp() {
        //PrimaryExp → '(' Exp ')' | LVal | Number | Character
        updateNumber();
        Type type = words.get(wordPoint).getType();
        if (type == Type.LPARENT) {
            addOut();
            Exp();
            if (words.get(wordPoint).getType() == Type.RPARENT) {
                addOut();
            } else {
                addError('j');
            }
        } else if (type == Type.INTCON ) {
            myNumber();
        } else if (type == Type.CHRCON){
            myCharacter();
        } else {
            LVal();
        }

        outStr.add("<PrimaryExp>");
    }

    private void LVal() {
        //LVal → Ident ['[' Exp ']']
        updateNumber();
        addOut();
        if (words.get(wordPoint).getType() == Type.LBRACK) {
            addOut();
            Exp();
            if (words.get(wordPoint).getType() == Type.RBRACK) {
                //添加右括号
                addOut();
            } else {    //不是右括号，报错
                addError('k');
            }
        }

        outStr.add("<LVal>");
    }

    private void myCharacter() {
        updateNumber();
        addOut();
        outStr.add("<Character>");
    }

    private void myNumber() {
        updateNumber();
        addOut();
        outStr.add("<Number>");
    }

    private void FuncRParams() {
        // FuncRParams → Exp { ',' Exp }
        updateNumber();
        Exp();
        while (words.get(wordPoint).getType() == Type.COMMA) {
            addOut();
            Exp();
        }

        outStr.add("<FuncRParams>");
    }

    private void UnaryOp() {
        updateNumber();
        addOut();
        outStr.add("<UnaryOp>");
    }

    private void FuncDef() {
        // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
        updateNumber();
        //FuncType
        FuncType();
        //Ident
        addOut();
        //'('
        addOut();
        //不为右括号，有参数
        if (words.get(wordPoint).getType() != Type.RPARENT) {
            FuncFParams();
        }
        //')'
        if (words.get(wordPoint).getType() == Type.RPARENT) {
            addOut();
        } else {
            addError('j');
        }
        //Block
        Block();
        //结束
        outStr.add("<FuncDef>");
    }

    private void FuncType() {
        // FuncType → 'void' | 'int' | 'char'
        updateNumber();
        //直接加
        addOut();
        outStr.add("<FuncType>");
    }

    private void FuncFParams() {
        // FuncFParams → FuncFParam { ',' FuncFParam }
        updateNumber();
        while (true) {
            FuncFParam();
            if (words.get(wordPoint).getType() == Type.COMMA) {
                //逗号继续
                addOut();
                continue;
            }
            //不是逗号，离开（即右大括号）
            break;
        }
        outStr.add("<FuncFParams>");
    }

    private void FuncFParam() {
        //  FuncFParam → BType Ident ['[' ']']
        updateNumber();
        //BType
        addOut();
        //Ident
        addOut();
        //可能存在括号
        if (words.get(wordPoint).getType() == Type.LBRACK) {
            addOut();
            if (words.get(wordPoint).getType() == Type.RBRACK) {
                //添加右括号
                addOut();
            } else {    //不是右括号，报错
                addError('k');
            }
        }
        outStr.add("<FuncFParam>");
    }

    private void Block() {
        // Block → '{' { BlockItem } '}'
        updateNumber();
        //'{'
        addOut();
        // {BlockItem}
        while (words.get(wordPoint).getType() != Type.RBRACE) {
            BlockItem();
        }
        //'}'
        addOut();

        outStr.add("<Block>");
    }

    private void BlockItem() {
        // BlockItem → Decl | Stmt
        updateNumber();
        Type type = words.get(wordPoint).getType();
        if (type == Type.CONSTTK || type == Type.INTTK || type == Type.CHARTK) {
            //定义语句
            Decl();
        } else {
            Stmt();
        }
    }

    private void Stmt() {
        Type type = words.get(wordPoint).getType();
        updateNumber();
        if (type == Type.LBRACE) {
            Block();
        }
        else if (type == Type.IFTK) {
            //| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
            addOut();
            addOut();
            Cond();
            if (words.get(wordPoint).getType() == Type.RPARENT) {
                addOut();
            } else {
                addError('j');
            }
            Stmt();
            if (words.get(wordPoint).getType() == Type.ELSETK) {
                addOut();
                Stmt();
            }
        }
        else if (type == Type.FORTK) {
            //| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            addOut();
            addOut();
            if (words.get(wordPoint).getType() != Type.SEMICN) {
                ForStmt();
            }
            addOut();
            if (words.get(wordPoint).getType() != Type.SEMICN) {
                Cond();
            }
            // ';'
            addOut();
            //[ForStmt]
            if (words.get(wordPoint).getType() != Type.RPARENT) {
                ForStmt();
            }
            //')'
            if (words.get(wordPoint).getType() == Type.RPARENT) {
                addOut();
            } else {
                addError('j');
            }
            Stmt();
        }
        else if (type == Type.BREAKTK || type == Type.CONTINUETK) {
            //| 'break' ';' | 'continue' ';'
            addOut();
            if (words.get(wordPoint).getType() == Type.SEMICN) {
                addOut();
            } else {    //不是分号，报错
                addError('i');
            }
        }
        else if (type == Type.RETURNTK) {
            //| 'return' [Exp] ';' // 1.有Exp 2.无Exp
            // return 后 exp问题
            // 按最长匹配，即若有Exp的First集元素，则进入Exp，否则认为应该是分号
            addOut();
            Type type1 = words.get(wordPoint).getType();
            if (type1 == Type.PLUS || type1 == Type.MINU || type1 == Type.IDENFR
                || type1 == Type.CHRCON || type1 == Type.INTCON || type1 == Type.LPARENT) {
                Exp();
                //';'
                addOut();
            } else if (type1 == Type.SEMICN) {
                addOut();
            } else {    //不是分号，报错
                addError('i');
            }
        }
        else if (type == Type.PRINTFTK) {
            //| 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp
            addOut();
            addOut();
            addOut();
            //
            while (words.get(wordPoint).getType() == Type.COMMA) {
                addOut();
                Exp();
            }
            //')' ';'
            if (words.get(wordPoint).getType() == Type.RPARENT) {
                addOut();
            } else {
                addError('j');
            }
            if (words.get(wordPoint).getType() == Type.SEMICN) {
                addOut();
            } else {    //不是分号，报错
                addError('i');
            }
        }
        else if (type == Type.IDENFR) {
            // Stmt ->
            // LVal '=' Exp ';' // 每种类型的语句都要覆盖
            //| LVal '=' 'getint''('')'';'
            //| LVal '=' 'getchar''('')'';'
            //| [Exp] ';'
                // Exp -> LVal | Ident '(' ...
                // LVal → Ident ['[' Exp ']']

            //查看下一个，若是'('，则exp
            //若不是，则 Exp->LVal或assign
                // LVal → Ident ['[' Exp ']']
            //故再看LVal后一个，若是'='，则assign
                //正常报错
            //不是，则为Exp，应该';'
                //若无';'，报错，前一符号以Exp识别
            //getint 和 getchar ')'报错
            if (words.get(wordPoint + 1).getType() == Type.LPARENT) {
                Exp();
            } else {
                //LVal
                LVal();
                if (words.get(wordPoint).getType() == Type.ASSIGN) {
                    // LVal '=' Exp ';' // 每种类型的语句都要覆盖
                    //| LVal '=' 'getint''('')'';'
                    //| LVal '=' 'getchar''('')'';'
                    addOut();
                    if (words.get(wordPoint).getType() == Type.GETINTTK ||
                        words.get(wordPoint).getType() == Type.GETCHARTK) {
                        addOut();
                        addOut();
                        if (words.get(wordPoint).getType() == Type.RPARENT) {
                            addOut();
                        } else {
                            addError('j');
                        }
                    } else {
                        Exp();
                    }
                }
                else {
                    // Exp -> AddExp -> MulExp -> UnaryExp -> PrimaryExp -> LVal
                    outStr.add("<PrimaryExp>");
                    outStr.add("<UnaryExp>");
                    outStr.add("<MulExp>");
                    outStr.add("<AddExp>");
                    outStr.add("<Exp>");
                    //;
                }
            }
            if (words.get(wordPoint).getType() == Type.SEMICN) {
                addOut();
            } else {
                addError('i');
            }
        }
        else {
            //  [Exp] ';'
            if (words.get(wordPoint).getType() != Type.SEMICN) {
                Exp();
            }
            addOut();
        }

        outStr.add("<Stmt>");
    }

    private void ForStmt() {
        // ForStmt → LVal '=' Exp
        updateNumber();
        LVal();
        addOut();
        Exp();

        outStr.add("<ForStmt>");
    }

    private void Cond() {
        //Cond → LOrExp
        updateNumber();
        LOrExp();

        outStr.add("<Cond>");
    }

    private void LOrExp() {
        // LOrExp → LAndExp | LOrExp '||' LAndExp
        updateNumber();
        LAndExp();
        while (words.get(wordPoint).getType() == Type.OR) {
            outStr.add("<LOrExp>");

            addOut();
            LAndExp();
        }

        outStr.add("<LOrExp>");
    }

    private void LAndExp() {
        //LAndExp → EqExp | LAndExp '&&' EqExp
        updateNumber();
        EqExp();
        while (words.get(wordPoint).getType() == Type.AND) {
            outStr.add("<LAndExp>");

            addOut();
            EqExp();
        }

        outStr.add("<LAndExp>");
    }

    private void EqExp() {
        //EqExp → RelExp | EqExp ('==' | '!=') RelExp
        updateNumber();
        RelExp();
        while (words.get(wordPoint).getType() == Type.EQL
                || words.get(wordPoint).getType() == Type.NEQ) {
            outStr.add("<EqExp>");

            addOut();
            RelExp();
        }
        outStr.add("<EqExp>");
    }

    private void RelExp() {
        // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        updateNumber();
        AddExp();

        while (words.get(wordPoint).getType() == Type.LSS
                || words.get(wordPoint).getType() == Type.GRE
                || words.get(wordPoint).getType() == Type.LEQ
                || words.get(wordPoint).getType() == Type.GEQ) {
            outStr.add("<RelExp>");

            addOut();
            AddExp();
        }
        outStr.add("<RelExp>");
    }

    private void MainFuncDef() {
        // MainFuncDef → 'int' 'main' '(' ')' Block
        updateNumber();
        //int
        addOut();
        //'main'
        addOut();
        //'('
        addOut();
        //')'
        if (words.get(wordPoint).getType() == Type.RPARENT) {
            addOut();
        } else {
            addError('j');
        }
        //Block
        Block();

        outStr.add("<MainFuncDef>");
    }

    public ArrayList<String> getOutStr() {
        return outStr;
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }

    private void addError(char code) {
        errors.add(new Error(noneTerminalLine, noneTerminalColumn, code));
    }

    private void addOut() {
        Word word = words.get(wordPoint);
        if (word == null) {
            return;
        }
        outStr.add(String.format("%s %s", word.getType().toString(), word.getValue()));
        advancePoint();
    }

    private void updateNumber() {
        this.noneTerminalLine = words.get(wordPoint).getLine();
        this.noneTerminalColumn = words.get(wordPoint).getColumn();
    }

    private void advancePoint() {
        if (wordPoint >= words.size()) {
            System.out.println("Error : Top Point!");
            return;
        }
        wordPoint = wordPoint + 1;
    }

    private void backPoint() {
        if (wordPoint <= 0) {
            System.out.println("Error : Head Point!");
            return;
        }
        wordPoint = wordPoint - 1;
    }

}
