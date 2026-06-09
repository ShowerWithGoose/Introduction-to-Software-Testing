package Syntax;
import CompileErrors.*;
import Datas.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import static Datas.Token.TokenType.*;

/**
 * @author
 * @Description:
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
    }

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

    private void CompUnit() {
        while(curSym.tokenType == CONSTTK ||((curSym.tokenType == INTTK || curSym.tokenType == CHARTK) &&
                CheckTools.isIdent(getNextNSym(1)) && getNextNSym(2).tokenType != LPARENT)) {
            if (curSym.tokenType == CONSTTK) {
                ConstDecl();
            } else {
                VarDecl();
            }
        }

        while (curSym.tokenType == VOIDTK || ((curSym.tokenType == INTTK || curSym.tokenType == CHARTK) &&
                CheckTools.isIdent(getNextNSym(1)) && getNextNSym(2).tokenType == LPARENT)) {
            FuncDef();
        }

        if ((curSym.tokenType == INTTK || curSym.tokenType == CHARTK) && getNextNSym(1).tokenType == MAINTK) {
            MainFuncDef();
        }
        output("<CompUnit>");
    }

    private void ConstDecl() {
        if (curSym.tokenType == CONSTTK) {
            TerminalSym();
            if (CheckTools.isBType(curSym)) {
                TerminalSym();
                ConstDef();
                // repetitive match is like
                while (curSym.tokenType == COMMA) {
                    TerminalSym();
                    ConstDef();
                }
                errorCheckAndOutput(SEMICN, 'i');
            }
        }
        output("<ConstDecl>");
    }

    private void ConstDef() {
        if (CheckTools.isIdent(curSym)) {
            TerminalSym();
            // optional match is like:
            if (curSym.tokenType == LBRACK) {
                TerminalSym();
                ConstExp();
                errorCheckAndOutput(RBRACK, 'k');
            }
            if (curSym.tokenType == ASSIGN) {
                TerminalSym();
                ConstInitVal();
            }
        }
        output("<ConstDef>");
    }

    private void ConstExp() {
        AddExp();
        output("<ConstExp>");
    }

    private void ConstInitVal() {
        if (curSym.tokenType == LBRACE) {
            TerminalSym();
            if (curSym.tokenType != RBRACE) {
                // Actually I need to check FIRST(ConstExp), but I'm lazy (=_=)
                ConstExp();
                while (curSym.tokenType == COMMA) {
                    TerminalSym();
                    ConstExp();
                }
            }
            if (curSym.tokenType == RBRACE) {
                TerminalSym();
            }
        } else if (CheckTools.isStringCon(curSym)) {
            TerminalSym();
        } else {
            ConstExp();
        }
        output("<ConstInitVal>");
    }


    private void VarDecl() {
        if (CheckTools.isBType(curSym)) {
            TerminalSym();
            VarDef();
            while (curSym.tokenType == COMMA) {
                TerminalSym();
                VarDef();
            }
            errorCheckAndOutput(SEMICN, 'i');
        }
        output("<VarDecl>");
    }

    private void VarDef() {
        if (CheckTools.isIdent(curSym)) {
            TerminalSym();
            // [] or not
            if (curSym.tokenType == LBRACK) {
                TerminalSym();
                ConstExp();
                errorCheckAndOutput(RBRACK, 'k');
            }
            if (curSym.tokenType == ASSIGN) {
                TerminalSym();
                InitVal();
            }
        }
        output("<VarDef>");
    }

    private void InitVal() {
        if (curSym.tokenType == LBRACE) {
            TerminalSym();
            if (curSym.tokenType != RBRACE) {
                // Actually I need to check FIRST(Exp), but I'm lazy (=_=)
                Exp();
                while (curSym.tokenType == COMMA) {
                    TerminalSym();
                    Exp();
                }
            }
            if (curSym.tokenType == RBRACE) {
                TerminalSym();
            }
        } else if (CheckTools.isStringCon(curSym)) {
            TerminalSym();
        } else {
            Exp();
        }
        output("<InitVal>");
    }

    private void FuncDef() {
        FuncType();
        if (CheckTools.isIdent(curSym)) {
            TerminalSym();
            if (curSym.tokenType == LPARENT) {
                TerminalSym();
                if (curSym.tokenType != RPARENT && curSym.tokenType != LBRACE) {
                    FuncFParams();
                }
                errorCheckAndOutput(RPARENT, 'j');
//                if (curSym.tokenType == RPARENT) {
//                    TerminalSym();
//                } else {
//                    errorHandler.addErrorMessage(getNextNSym(-1).lineNumber, 'j');
//                }
                Block();
            }
        }
        output("<FuncDef>");
    }

    private void MainFuncDef() {
        if (curSym.tokenType == INTTK) {
            TerminalSym();
            if (curSym.tokenType == MAINTK) {
                TerminalSym();
                if (curSym.tokenType == LPARENT) {
                    TerminalSym();
                    errorCheckAndOutput(RPARENT, 'j');
                    Block();
                }
            }
        }
        output("<MainFuncDef>");
    }

    private void FuncType() {
        if (curSym.tokenType == VOIDTK || curSym.tokenType == INTTK || curSym.tokenType == CHARTK) {
            TerminalSym();
        }
        output("<FuncType>");
    }

    private void FuncFParams() {
        FuncFParam();
        while (curSym.tokenType == COMMA) {
            TerminalSym();
            FuncFParam();
        }
        output("<FuncFParams>");
    }

    private void FuncFParam() {
        if (CheckTools.isBType(curSym)) {
            TerminalSym();
            if (CheckTools.isIdent(curSym)) {
                TerminalSym();
                if (curSym.tokenType == LBRACK) {
                    TerminalSym();
                    errorCheckAndOutput(RBRACK, 'k');
                }
            }
        }
        output("<FuncFParam>");
    }

    private void Block() {
        if (curSym.tokenType == LBRACE) {
            TerminalSym();
            while(curSym.tokenType != RBRACE) {
                if (curSym.tokenType == INTTK || curSym.tokenType == CHARTK) {
                    VarDecl();
                } else if (curSym.tokenType == CONSTTK) {
                    ConstDecl();
                } else {
                    Stmt();
                }
            }
            // omit judging RBRACE
            TerminalSym();
        }
        output("<Block>");
    }

    private void Stmt() {
        if (CheckTools.isIdent(curSym)) {
            // Exp V.S. LVal '=' ... ??????
            checkSym = curSym;
            checkIndex = curIndex;
            checkLVal();
//            System.out.println(checkSym.name);
            if (checkSym.tokenType == ASSIGN) {
                // LVal '=' ...
                LVal();
                TerminalSym();  // '='
                if (curSym.tokenType == GETINTTK || curSym.tokenType == GETCHARTK) {
                    TerminalSym();
                    if (curSym.tokenType == LPARENT) {
                        TerminalSym();
                        errorCheckAndOutput(RPARENT, 'j');
                    }
                } else {
                    Exp();
                }
                errorCheckAndOutput(SEMICN, 'i');
            } else {
                Exp();
                errorCheckAndOutput(SEMICN, 'i');
            }

        } else if (curSym.tokenType == LBRACE) {
            // FIRST(Block) = {'{'}
            Block();
        } else if (curSym.tokenType == IFTK) {
            ifAnalyze();
        } else if (curSym.tokenType == FORTK) {
            forAnalyze();
        } else if (curSym.tokenType == BREAKTK) {
            breakAnalyze();
        } else if (curSym.tokenType == CONTINUETK) {
            continueAnalyze();
        }else if (curSym.tokenType == RETURNTK) {
            returnAnalyze();
        } else if (curSym.tokenType == PRINTFTK) {
            printfAnalyze();
        } else if (curSym.tokenType == SEMICN) {
            // ';'
            TerminalSym();
        } else {
            // rest of Exp
            Exp();
            errorCheckAndOutput(SEMICN, 'i');
        }
        output("<Stmt>");
    }



    private void ForStmt() {
        LVal();
        if (curSym.tokenType == ASSIGN) {
            TerminalSym();
            Exp();
        }
        output("<ForStmt>");
    }

    private void Exp() {
        AddExp();
        output("<Exp>");
    }

    private void Cond() {
        LOrExp();
        output("<Cond>");
    }

    private void LVal() {
        if (CheckTools.isIdent(curSym)) {
            TerminalSym();
            if (curSym.tokenType == LBRACK) {
                TerminalSym();
                Exp();
                errorCheckAndOutput(RBRACK, 'k');
            }
        }
        output("<LVal>");
    }

    private void PrimaryExp() {
        if (curSym.tokenType == LPARENT) {
            TerminalSym();
            Exp();
            errorCheckAndOutput(RPARENT, 'j');
        } else if (CheckTools.isIntCon(curSym)) {
            NumberAnalyze();
        } else if (CheckTools.isCharCon(curSym)) {
            CharacterAnalyze();
        } else {
            LVal();
        }
        output("<PrimaryExp>");
    }

    private void NumberAnalyze() {
        TerminalSym();
        output("<Number>");
    }

    private void CharacterAnalyze() {
        TerminalSym();
        output("<Character>");
    }

    private void UnaryExp() {
        // Pre-read: PrimaryExp -> LVal -> IDENT ... and IDENT '('
        if (CheckTools.isIdent(curSym) && getNextNSym(1).tokenType == LPARENT) {
            TerminalSym();
            if (curSym.tokenType == LPARENT) {
                TerminalSym();
                if (curSym.tokenType != RPARENT && CheckTools.isFirstExp(curSym)) {
                    FuncRParams();
                }
                errorCheckAndOutput(RPARENT, 'j');
            }
        } else if (curSym.tokenType == PLUS || curSym.tokenType == MINU || curSym.tokenType == NOT) {
            UnaryOp();
            UnaryExp();
        } else {
            PrimaryExp();
        }
        output("<UnaryExp>");
    }

    private void UnaryOp() {
        TerminalSym();
        output("<UnaryOp>");
    }

    private void FuncRParams() {
        Exp();
        while (curSym.tokenType == COMMA) {
            TerminalSym();
            Exp();
        }
        output("<FuncRParams>");
    }

    private void MulExp() {
        UnaryExp();
        while (curSym.tokenType == MULT || curSym.tokenType == DIV || curSym.tokenType == MOD) {
            // Because I shift Left Iteration to right one,
            // So I need to output one more <MulExp> after each <UnaryExp> except the last one
            output("<MulExp>");
            TerminalSym();
            UnaryExp();
        }
        output("<MulExp>");
    }

    private void AddExp() {
        MulExp();
        while (curSym.tokenType == PLUS || curSym.tokenType == MINU) {
            // Because I shift Left Iteration to right one,
            // So I need to output one more <AddExp> after each <MulExp> except the last one
            output("<AddExp>");
            TerminalSym();
            MulExp();
        }
        output("<AddExp>");
    }

    private void RelExp() {
        AddExp();
        while (curSym.tokenType == LSS || curSym.tokenType == GRE || curSym.tokenType == LEQ || curSym.tokenType == GEQ) {
            output("<RelExp>");
            TerminalSym();
            AddExp();
        }
        output("<RelExp>");
    }

    private void EqExp() {
        RelExp();
        while (curSym.tokenType == EQL || curSym.tokenType == NEQ) {
            output("<EqExp>");
            TerminalSym();
            RelExp();
        }
        output("<EqExp>");
    }

    private void LAndExp() {
        EqExp();
        while (curSym.tokenType == AND) {
            output("<LAndExp>");
            TerminalSym();
            EqExp();
        }
        output("<LAndExp>");
    }

    private void LOrExp() {
        LAndExp();
        while (curSym.tokenType == OR) {
            output("<LOrExp>");
            TerminalSym();
            LAndExp();
        }
        output("<LOrExp>");
    }

    private void ifAnalyze() {
        TerminalSym();
        if (curSym.tokenType == LPARENT) {
            TerminalSym();
            Cond();
            errorCheckAndOutput(RPARENT, 'j');
            Stmt();
            if (curSym.tokenType == ELSETK) {
                TerminalSym();
                Stmt();
            }
        }
        // no output
    }

    private void forAnalyze() {
        TerminalSym();
        if (curSym.tokenType == LPARENT) {
            TerminalSym();
            if (curSym.tokenType != SEMICN) {
                ForStmt();
            }
            if (curSym.tokenType == SEMICN) {
                TerminalSym();
            }

            if (curSym.tokenType != SEMICN) {
                Cond();
            }
            if (curSym.tokenType == SEMICN) {
                TerminalSym();
            }

            if (curSym.tokenType != RPARENT) {
                ForStmt();
            }
            if (curSym.tokenType == RPARENT) {
                TerminalSym();
            }
            Stmt();
        }
        // no output
    }

    private void breakAnalyze() {
        TerminalSym();
        errorCheckAndOutput(SEMICN, 'i');
    }

    private void continueAnalyze() {
        TerminalSym();
        errorCheckAndOutput(SEMICN, 'i');
    }

    private void returnAnalyze() {
        TerminalSym();
        if (curSym.tokenType != SEMICN) {
            Exp();
        }
        errorCheckAndOutput(SEMICN, 'i');
    }

    private void printfAnalyze() {
        TerminalSym();
        if (curSym.tokenType == LPARENT) {
            TerminalSym();
            if (CheckTools.isStringCon(curSym)) {
                TerminalSym();
                while (curSym.tokenType == COMMA) {
                    TerminalSym();
                    Exp();
                }
                errorCheckAndOutput(RPARENT, 'j');
//                if (curSym.tokenType == RPARENT) {
//                    TerminalSym();
//                } else {
//                    errorHandler.addErrorMessage(getNextNSym(-1).lineNumber, 'j');
//                }
                errorCheckAndOutput(SEMICN, 'i');

            }
        }
    }

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

    private void errorCheckAndOutput(Token.TokenType checkType, char errorCode) {
        if (curSym.tokenType == checkType) {
            TerminalSym();
        } else {
            errorHandler.addErrorMessage(getNextNSym(-1).lineNumber, errorCode);
        }
    }

    private void TerminalSym() {
        output(curSym);
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