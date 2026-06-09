package Syntax;
import CompileErrors.*;
import Datas.*;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import static Datas.Token.TokenType.*;

/**
 * @author
 * @Description: 语法分析
 * @date 2024/9/29 13:17
 */
public class Parser {
    public Parser(ArrayList<Token> tokens) {
        this.tokens = tokens;
        curSym = tokens.get(0);
        curIndex = 0;
        errorHandler = CompileErrorHandler.getInstance();
    }

    private static Parser instance;

    public static Parser getInstance(ArrayList<Token> tokens) {
        if (instance == null) {
            instance = new Parser(tokens);
        }
        return instance;
    }

    // Tokens result in Lexer
    public FileWriter writer;
    public CompileErrorHandler errorHandler;
    public ArrayList<Token> tokens;
    public Token curSym;
    public Token checkSym;  // for checking some tricky situations
    public int curIndex;
    public int checkIndex;
    public boolean isEnd;

    public void setWriter(FileWriter writer) {
        this.writer = writer;
    }

    public void analyze() {
        CompUnit();
        AstNode.root.output(writer);
    }

    /* ---------------------------------GetSym Tools--------------------------------- */
    // get the next N (start from 1) sym
    private Token getNextNSym(int n) {
        if (curIndex + n >= tokens.size()) {
            System.out.println("Notice: Get a sym out of range.");
            return tokens.get(tokens.size() - 1);
        } else if (curIndex +n < 0){
            System.out.println("Notice: Get a sym before index 0.");
            return tokens.get(0);
        } else {
            return tokens.get(curIndex + n);
        }
    }

    private Token getNextNCheckSym(int n) {
        if (checkIndex + n >= tokens.size()) {
            System.out.println("Notice: Get a sym out of range.");
            return tokens.get(tokens.size() - 1);
        } else if (checkIndex + n < 0){
            System.out.println("Notice: Get a sym before index 0.");
            return tokens.get(0);
        } else {
            return tokens.get(checkIndex + n);
        }
    }

    private void moveToNextSym() {
        curIndex++;
        if (curIndex == tokens.size()) {
            if (isEnd) {
                System.out.println("Error: Syntax analysis not finished.");
            } else {
                isEnd = true;
            }
        } else {
            curSym = tokens.get(curIndex);
        }
    }

    private void moveToNextCheckSym() {
        checkIndex++;
        if (checkIndex == tokens.size()) {
            if (isEnd) {
                System.out.println("Error: Syntax analysis not finished.");
            } else {
                isEnd = true;
            }
        } else {
            checkSym = tokens.get(checkIndex);
        }
    }
    /* -------------------------------------------------------------------------- */



    private void CompUnit() {
        AstNode.root = new AstNode("<CompUnit>");

        while(curSym.tokenType == CONSTTK ||((curSym.tokenType == INTTK || curSym.tokenType == CHARTK) &&
                CheckTools.isIdent(getNextNSym(1)) && getNextNSym(2).tokenType != LPARENT)) {
            if (curSym.tokenType == CONSTTK) {
                ConstDecl(AstNode.root);
            } else {
                VarDecl(AstNode.root);
            }
        }

        while (curSym.tokenType == VOIDTK || ((curSym.tokenType == INTTK || curSym.tokenType == CHARTK) &&
                CheckTools.isIdent(getNextNSym(1)) && getNextNSym(2).tokenType == LPARENT)) {
            FuncDef(AstNode.root);
        }

        if ((curSym.tokenType == INTTK || curSym.tokenType == CHARTK) && getNextNSym(1).tokenType == MAINTK) {
            MainFuncDef(AstNode.root);
        }
        // output("<CompUnit>");
    }

    private void ConstDecl(AstNode parent) {
        AstNode cur = new AstNode("<ConstDecl>");
        if (curSym.tokenType == CONSTTK) {
            TerminalSym(cur);
            if (CheckTools.isBType(curSym)) {
                TerminalSym(cur);
                ConstDef(cur);
                // repetitive match is like
                while (curSym.tokenType == COMMA) {
                    TerminalSym(cur);
                    ConstDef(cur);
                }
                errorCheckAndOutput(SEMICN, 'i', cur);
            }
        }
        parent.addChild(cur);
//        output("<ConstDecl>");
    }

    private void ConstDef(AstNode parent) {
        AstNode cur = new AstNode("<ConstDef>");

        if (CheckTools.isIdent(curSym)) {
            TerminalSym(cur);
            // optional match is like:
            if (curSym.tokenType == LBRACK) {
                TerminalSym(cur);
                ConstExp(cur);
                errorCheckAndOutput(RBRACK, 'k', cur);
            }
            if (curSym.tokenType == ASSIGN) {
                TerminalSym(cur);
                ConstInitVal(cur);
            }
        }
        parent.addChild(cur);
//        output("<ConstDef>");
    }

    private void ConstExp(AstNode parent) {
        AstNode cur = new AstNode("<ConstExp>");
        AddExp(cur);
        parent.addChild(cur);
//        output("<ConstExp>");
    }

    private void ConstInitVal(AstNode parent) {
        AstNode cur = new AstNode("<ConstInitVal>");
        if (curSym.tokenType == LBRACE) {
            TerminalSym(cur);
            if (curSym.tokenType != RBRACE) {
                // Actually I need to check FIRST(ConstExp), but I'm lazy (=_=)
                ConstExp(cur);
                while (curSym.tokenType == COMMA) {
                    TerminalSym(cur);
                    ConstExp(cur);
                }
            }
            if (curSym.tokenType == RBRACE) {
                TerminalSym(cur);
            }
        } else if (CheckTools.isStringCon(curSym)) {
            TerminalSym(cur);
        } else {
            ConstExp(cur);
        }
        parent.addChild(cur);
//        output("<ConstInitVal>");
    }


    private void VarDecl(AstNode parent) {
        AstNode cur = new AstNode("<VarDecl>");
        if (CheckTools.isBType(curSym)) {
            TerminalSym(cur);
            VarDef(cur);
            while (curSym.tokenType == COMMA) {
                TerminalSym(cur);
                VarDef(cur);
            }
            errorCheckAndOutput(SEMICN, 'i',cur );
        }
        parent.addChild(cur);
//        output("<VarDecl>");
    }

    private void VarDef(AstNode parent) {
        AstNode cur = new AstNode("<VarDef>");
        if (CheckTools.isIdent(curSym)) {
            TerminalSym(cur);
            // [] or not
            if (curSym.tokenType == LBRACK) {
                TerminalSym(cur);
                ConstExp(cur);
                errorCheckAndOutput(RBRACK, 'k',cur );
            }
            if (curSym.tokenType == ASSIGN) {
                TerminalSym(cur);
                InitVal(cur);
            }
        }
        parent.addChild(cur);
//        output("<VarDef>");
    }

    private void InitVal(AstNode parent) {
        AstNode cur = new AstNode("<InitVal>");
        if (curSym.tokenType == LBRACE) {
            TerminalSym(cur);
            if (curSym.tokenType != RBRACE) {
                // Actually I need to check FIRST(Exp), but I'm lazy (=_=)
                Exp(cur);
                while (curSym.tokenType == COMMA) {
                    TerminalSym(cur);
                    Exp(cur);
                }
            }
            if (curSym.tokenType == RBRACE) {
                TerminalSym(cur);
            }
        } else if (CheckTools.isStringCon(curSym)) {
            TerminalSym(cur);
        } else {
            Exp(cur);
        }
        parent.addChild(cur);
//        output("<InitVal>");
    }

    private void FuncDef(AstNode parent) {
        AstNode cur = new AstNode("<FuncDef>");
        FuncType(cur);
        if (CheckTools.isIdent(curSym)) {
            TerminalSym(cur);
            if (curSym.tokenType == LPARENT) {
                TerminalSym(cur);
                if (curSym.tokenType != RPARENT && curSym.tokenType != LBRACE) {
                    FuncFParams(cur);
                }
                errorCheckAndOutput(RPARENT, 'j',cur );
                Block(cur);
            }
        }
        parent.addChild(cur);
//        output("<FuncDef>");
    }

    private void MainFuncDef(AstNode parent) {
        AstNode cur = new AstNode("<MainFuncDef>");
        if (curSym.tokenType == INTTK) {
            TerminalSym(cur);
            if (curSym.tokenType == MAINTK) {
                TerminalSym(cur);
                if (curSym.tokenType == LPARENT) {
                    TerminalSym(cur);
                    errorCheckAndOutput(RPARENT, 'j',cur );
                    Block(cur);
                }
            }
        }
        parent.addChild(cur);
//        output("<MainFuncDef>");
    }

    private void FuncType(AstNode parent) {
        AstNode cur = new AstNode("<FuncType>");
        if (curSym.tokenType == VOIDTK || curSym.tokenType == INTTK || curSym.tokenType == CHARTK) {
            TerminalSym(cur);
        }
        parent.addChild(cur);
//        output("<FuncType>");
    }

    private void FuncFParams(AstNode parent) {
        AstNode cur = new AstNode("<FuncFParams>");
        FuncFParam(cur);
        while (curSym.tokenType == COMMA) {
            TerminalSym(cur);
            FuncFParam(cur);
        }
        parent.addChild(cur);
//        output("<FuncFParams>");
    }

    private void FuncFParam(AstNode parent) {
        AstNode cur = new AstNode("<FuncFParam>");
        if (CheckTools.isBType(curSym)) {
            TerminalSym(cur);
            if (CheckTools.isIdent(curSym)) {
                TerminalSym(cur);
                if (curSym.tokenType == LBRACK) {
                    TerminalSym(cur);
                    errorCheckAndOutput(RBRACK, 'k',cur );
                }
            }
        }
        parent.addChild(cur);
//        output("<FuncFParam>");
    }

    private void Block(AstNode parent) {
        AstNode cur = new AstNode("<Block>");
        if (curSym.tokenType == LBRACE) {
            TerminalSym(cur);
            while(curSym.tokenType != RBRACE) {
                if (curSym.tokenType == INTTK || curSym.tokenType == CHARTK) {
                    VarDecl(cur);
                } else if (curSym.tokenType == CONSTTK) {
                    ConstDecl(cur);
                } else {
                    Stmt(cur);
                }
            }
            // omit judging RBRACE
            TerminalSym(cur);
        }
        parent.addChild(cur);
//        output("<Block>");
    }

    private void Stmt(AstNode parent) {
        AstNode cur = new AstNode("<Stmt>");
        if (CheckTools.isIdent(curSym)) {
            // Exp V.S. LVal '=' ... ??????
            checkSym = curSym;
            checkIndex = curIndex;
            checkLVal();
//            System.out.println(checkSym.name);
            if (checkSym.tokenType == ASSIGN) {
                // LVal '=' ...
                LVal(cur);
                TerminalSym(cur);  // '='
                if (curSym.tokenType == GETINTTK || curSym.tokenType == GETCHARTK) {
                    TerminalSym(cur);
                    if (curSym.tokenType == LPARENT) {
                        TerminalSym(cur);
                        errorCheckAndOutput(RPARENT, 'j',cur );
                    }
                } else {
                    Exp(cur);
                }
                errorCheckAndOutput(SEMICN, 'i',cur );
            } else {
                Exp(cur);
                errorCheckAndOutput(SEMICN, 'i',cur );
            }

        } else if (curSym.tokenType == LBRACE) {
            // FIRST(Block) = {'{'}
            Block(cur);
        } else if (curSym.tokenType == IFTK) {
            ifAnalyze(cur);
        } else if (curSym.tokenType == FORTK) {
            forAnalyze(cur);
        } else if (curSym.tokenType == BREAKTK) {
            breakAnalyze(cur);
        } else if (curSym.tokenType == CONTINUETK) {
            continueAnalyze(cur);
        }else if (curSym.tokenType == RETURNTK) {
            returnAnalyze(cur);
        } else if (curSym.tokenType == PRINTFTK) {
            printfAnalyze(cur);
        } else if (curSym.tokenType == SEMICN) {
            // ';'
            TerminalSym(cur);
        } else {
            // rest of Exp
            Exp(cur);
            errorCheckAndOutput(SEMICN, 'i',cur );
        }
        parent.addChild(cur);
//        output("<Stmt>");
    }



    private void ForStmt(AstNode parent) {
        AstNode cur = new AstNode("<ForStmt>");
        LVal(cur);
        if (curSym.tokenType == ASSIGN) {
            TerminalSym(cur);
            Exp(cur);
        }
        parent.addChild(cur);
//        output("<ForStmt>");
    }

    private void Exp(AstNode parent) {
        AstNode cur = new AstNode("<Exp>");
        AddExp(cur);
        parent.addChild(cur);
//        output("<Exp>");
    }

    private void Cond(AstNode parent) {
        AstNode cur = new AstNode("<Cond>");
        LOrExp(cur);
        parent.addChild(cur);
//        output("<Cond>");
    }

    private void LVal(AstNode parent) {
        AstNode cur = new AstNode("<LVal>");
        if (CheckTools.isIdent(curSym)) {
            TerminalSym(cur);
            if (curSym.tokenType == LBRACK) {
                TerminalSym(cur);
                Exp(cur);
                errorCheckAndOutput(RBRACK, 'k',cur );
            }
        }
        parent.addChild(cur);
//        output("<LVal>");
    }

    private void PrimaryExp(AstNode parent) {
        AstNode cur = new AstNode("<PrimaryExp>");
        if (curSym.tokenType == LPARENT) {
            TerminalSym(cur);
            Exp(cur);
            errorCheckAndOutput(RPARENT, 'j',cur );
        } else if (CheckTools.isIntCon(curSym)) {
            NumberAnalyze(cur);
        } else if (CheckTools.isCharCon(curSym)) {
            CharacterAnalyze(cur);
        } else {
            LVal(cur);
        }
        parent.addChild(cur);
//        output("<PrimaryExp>");
    }

    private void NumberAnalyze(AstNode parent) {
        AstNode cur = new AstNode("<Number>");
        TerminalSym(cur);
        parent.addChild(cur);
//        output("<Number>");
    }

    private void CharacterAnalyze(AstNode parent) {
        AstNode cur = new AstNode("<Character>");
        TerminalSym(cur);
        parent.addChild(cur);
//        output("<Character>");
    }

    private void UnaryExp(AstNode parent) {
        AstNode cur = new AstNode("<UnaryExp>");
        // Pre-read: PrimaryExp -> LVal -> IDENT ... and IDENT '('
        if (CheckTools.isIdent(curSym) && getNextNSym(1).tokenType == LPARENT) {
            TerminalSym(cur);
            if (curSym.tokenType == LPARENT) {
                TerminalSym(cur);
                if (curSym.tokenType != RPARENT && CheckTools.isFirstExp(curSym)) {
                    FuncRParams(cur);
                }
                errorCheckAndOutput(RPARENT, 'j',cur );
            }
        } else if (curSym.tokenType == PLUS || curSym.tokenType == MINU || curSym.tokenType == NOT) {
            UnaryOp(cur);
            UnaryExp(cur);
        } else {
            PrimaryExp(cur);
        }
        parent.addChild(cur);
//        output("<UnaryExp>");
    }

    private void UnaryOp(AstNode parent) {
        AstNode cur = new AstNode("<UnaryOp>");
        TerminalSym(cur);
        parent.addChild(cur);
//        output("<UnaryOp>");
    }

    private void FuncRParams(AstNode parent) {
        AstNode cur = new AstNode("<FuncRParams>");
        Exp(cur);
        while (curSym.tokenType == COMMA) {
            TerminalSym(cur);
            Exp(cur);
        }
        parent.addChild(cur);
//        output("<FuncRParams>");
    }

    private void MulExp(AstNode parent) {
        AstNode cur = new AstNode("<MulExp>");
        UnaryExp(cur);
        while (curSym.tokenType == MULT || curSym.tokenType == DIV || curSym.tokenType == MOD) {
            // Because I shift Left Iteration to right one,
//             So I need to output one more <MulExp> after each <UnaryExp> except the last one
            AstNode tmp = new AstNode("<MulExp>");
            cur.insertLast(tmp);
//            output("<MulExp>");
            TerminalSym(cur);
            UnaryExp(cur);
        }
        parent.addChild(cur);
//        output("<MulExp>");
    }

    private void AddExp(AstNode parent) {
        AstNode cur = new AstNode("<AddExp>");
        MulExp(cur);
        while (curSym.tokenType == PLUS || curSym.tokenType == MINU) {
            // Because I shift Left Iteration to right one,
            // So I need to output one more <AddExp> after each <MulExp> except the last one
            AstNode tmp = new AstNode("<AddExp>");
            cur.insertLast(tmp);
//            output("<AddExp>");
            TerminalSym(cur);
            MulExp(cur);
        }
        parent.addChild(cur);
//        output("<AddExp>");
    }

    private void RelExp(AstNode parent) {
        AstNode cur = new AstNode("<RelExp>");
        AddExp(cur);
        while (curSym.tokenType == LSS || curSym.tokenType == GRE || curSym.tokenType == LEQ || curSym.tokenType == GEQ) {
            AstNode tmp = new AstNode("<RelExp>");
            cur.insertLast(tmp);
//            output("<RelExp>");
            TerminalSym(cur);
            AddExp(cur);
        }
        parent.addChild(cur);
//        output("<RelExp>");
    }

    private void EqExp(AstNode parent) {
        AstNode cur = new AstNode("<EqExp>");
        RelExp(cur);
        while (curSym.tokenType == EQL || curSym.tokenType == NEQ) {
            AstNode tmp = new AstNode("<EqExp>");
            cur.insertLast(tmp);
//            output("<EqExp>");
            TerminalSym(cur);
            RelExp(cur);
        }
        parent.addChild(cur);
//        output("<EqExp>");
    }

    private void LAndExp(AstNode parent) {
        AstNode cur = new AstNode("<LAndExp>");
        EqExp(cur);
        while (curSym.tokenType == AND) {
            AstNode tmp = new AstNode("<LAndExp>");
            cur.insertLast(tmp);
//            output("<LAndExp>");
            TerminalSym(cur);
            EqExp(cur);
        }
        parent.addChild(cur);
//        output("<LAndExp>");
    }

    private void LOrExp(AstNode parent) {
        AstNode cur = new AstNode("<LOrExp>");
        LAndExp(cur);
        while (curSym.tokenType == OR) {
            AstNode tmp = new AstNode("<LOrExp>");
            cur.insertLast(tmp);
//            output("<LOrExp>");
            TerminalSym(cur);
            LAndExp(cur);
        }
        parent.addChild(cur);
//        output("<LOrExp>");
    }

    /* ------------------------- Analyze Methods in Stmt ------------------- */
    private void ifAnalyze(AstNode cur) {
        TerminalSym(cur);
        if (curSym.tokenType == LPARENT) {
            TerminalSym(cur);
            Cond(cur);
            errorCheckAndOutput(RPARENT, 'j',cur );
            Stmt(cur);
            if (curSym.tokenType == ELSETK) {
                TerminalSym(cur);
                Stmt(cur);
            }
        }
        // no output
    }

    private void forAnalyze(AstNode cur) {
        TerminalSym(cur);
        if (curSym.tokenType == LPARENT) {
            TerminalSym(cur);
            if (curSym.tokenType != SEMICN) {
                ForStmt(cur);
            }
            if (curSym.tokenType == SEMICN) {
                TerminalSym(cur);
            }

            if (curSym.tokenType != SEMICN) {
                Cond(cur);
            }
            if (curSym.tokenType == SEMICN) {
                TerminalSym(cur);
            }

            if (curSym.tokenType != RPARENT) {
                ForStmt(cur);
            }
            if (curSym.tokenType == RPARENT) {
                TerminalSym(cur);
            }
            Stmt(cur);
        }
        // no output
    }

    private void breakAnalyze(AstNode cur) {
        TerminalSym(cur);
        errorCheckAndOutput(SEMICN, 'i',cur );
    }

    private void continueAnalyze(AstNode cur) {
        TerminalSym(cur);
        errorCheckAndOutput(SEMICN, 'i',cur );
    }

    private void returnAnalyze(AstNode cur) {
        TerminalSym(cur);
        if (curSym.tokenType != SEMICN) {
            Exp(cur);
        }
        errorCheckAndOutput(SEMICN, 'i',cur );
    }


    private void printfAnalyze(AstNode cur) {
        TerminalSym(cur);
        if (curSym.tokenType == LPARENT) {
            TerminalSym(cur);
            if (CheckTools.isStringCon(curSym)) {
                TerminalSym(cur);
                while (curSym.tokenType == COMMA) {
                    TerminalSym(cur);
                    Exp(cur);
                }
                errorCheckAndOutput(RPARENT, 'j',cur );
                errorCheckAndOutput(SEMICN, 'i',cur );

            }
        }
    }


    /*-------------------------- Check Stmt --------------------------*/
    // used in Clarifying Stmt -> [Exp]; | LVal '=' ...
    private void checkLVal() {
        moveToNextCheckSym();
        if (checkSym.tokenType == LBRACK) {
            moveToNextCheckSym();
            checkExp();
            if (checkSym.tokenType == RBRACK) {
                moveToNextCheckSym();
            }
        }
    }

    private void checkExp() {
        checkMulExp();
        while (checkSym.tokenType == PLUS || checkSym.tokenType == MINU) {
            moveToNextCheckSym();
            checkMulExp();
        }
    }

    private void checkMulExp() {
        checkUnaryExp();
        while (checkSym.tokenType == MULT || checkSym.tokenType == DIV || checkSym.tokenType == MOD) {
            moveToNextCheckSym();
            checkUnaryExp();
        }
    }

    private void checkUnaryExp() {
        // Pre-read: PrimaryExp -> LVal -> IDENT ... and IDENT '('
        if (CheckTools.isIdent(checkSym) && getNextNCheckSym(1).tokenType == LPARENT) {
            moveToNextCheckSym();
            if (checkSym.tokenType == LPARENT) {
                moveToNextCheckSym();
                if (checkSym.tokenType != RPARENT && CheckTools.isFirstExp(checkSym)) {
                    checkFuncRParams();
                }
                moveToNextCheckSym();
            }
        } else if (checkSym.tokenType == PLUS || checkSym.tokenType == MINU || checkSym.tokenType == NOT) {
            moveToNextCheckSym();
            checkUnaryExp();
        } else {
            checkPrimaryExp();
        }
    }
    
    private void checkPrimaryExp() {
        if (checkSym.tokenType == LPARENT) {
            moveToNextCheckSym();
            checkExp();
            if (curSym.tokenType == RPARENT) {
                moveToNextCheckSym();
            }
        } else if (CheckTools.isIntCon(checkSym)) {
            moveToNextCheckSym();
        } else if (CheckTools.isCharCon(checkSym)) {
            moveToNextCheckSym();
        } else {
            checkLVal();
        }
    }

    private void checkFuncRParams() {
        checkExp();
        while (checkSym.tokenType == COMMA) {
            moveToNextCheckSym();
            checkExp();
        }
    }


    /*------------------------------------ Common Tools ------------------------------*/

    private void errorCheckAndOutput(Token.TokenType checkType, char errorCode, AstNode node) {
        if (curSym.tokenType == checkType) {
            TerminalSym(node);
        } else {
            errorHandler.addErrorMessage(getNextNSym(-1).lineNumber, errorCode);
        }
    }

    private void TerminalSym(AstNode parent) {
        parent.addChild(new AstNode(curSym.tokenType.name() + " " + curSym.name));
//        output(curSym);
        moveToNextSym();
    }


    private void output(String str) {
        try {
            writer.write(str + "\n");
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    private void output(Token token) {
        try {
            writer.write(token.tokenType.name() + " " + token.name + "\n");
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}