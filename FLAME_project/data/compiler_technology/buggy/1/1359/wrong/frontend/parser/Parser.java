package frontend.parser;

import frontend.Category;
import frontend.Error;
import frontend.lexer.Token;

import java.util.ArrayList;

public class Parser {
    private int curPos;

    private ArrayList<Token> tokens;

    private Token curToken;

    private boolean isCorrect = true;

    private ArrayList<String> outputList;

    public Error error;

    public Parser(ArrayList<Token> tokens, Error error) {
        this.curPos = -1;
        this.tokens = tokens;
        this.outputList = new ArrayList<>();
        this.error = error;
    }

    public Boolean isCorrect() {
        return isCorrect;
    }

    public ArrayList<String> parseCompUnit() {
        curPos = 0;
        curToken = tokens.get(0);
        while (nextTokenRD(1).getCategory() != Category.MAINTK) {
            if (nextTokenRD(2).getCategory() == Category.LPARENT) {
                parseFuncDef();
            } else {
                parseDecl();
            }
        }
        parseMainFunc();
        outputList.add("<CompUnit>\n");
        return outputList;
    }

    private void parseMainFunc() {
        skipTokens(3);  // skip "int", "main" and "("

        if (curToken.getCategory() != Category.RPARENT) {
            dealError("j");
        } else {
            skipTokens(1); // skip )
        }

        parseBlock(); // block of the main function
        outputList.add("<MainFuncDef>\n");
    }

    private void parseFuncDef() {
        parseFuncType();
        skipTokens(2); // skip ident and (
        if (curToken.getCategory() == Category.INTTK || curToken.getCategory() == Category.CHARTK) {
            parseFuncFParams();
        }
        if (curToken.getCategory() != Category.RPARENT) {
            dealError("j");
        } else {
            skipTokens(1); // skip )
        }
        parseBlock();
        outputList.add("<FuncDef>\n");
    }

    private void parseBlock() {
        skipTokens(1); // skip {
        if (curToken.getCategory() == Category.RBRACE) {
            skipTokens(1); // skip }
        } else {
            while (curToken.getCategory() != Category.RBRACE) {
                parseBlockItem();
            }
            skipTokens(1); // skip }
        }
        outputList.add("<Block>\n");
    }

    private void parseBlockItem() {
        if (curToken.getCategory() == Category.CONSTTK || curToken.getCategory() == Category.INTTK || curToken.getCategory() == Category.CHARTK) {
            parseDecl();
        } else {
            parseStmt();
        }
    }

    private void parseStmt() {
        switch (curToken.getCategory()) {
            case SEMICN:  // 空语句，仅有分号
                skipTokens(1);
                break;
            case LBRACE:  // 语句块
                parseBlock();
                break;
            case IFTK:    // if 语句
                parseIfStmt();
                break;
            case FORTK:   // for 语句
                parseForLoop();
                break;
            case BREAKTK: // break 语句
                parseBreakStmt();
                break;
            case CONTINUETK: // continue 语句
                parseContinueStmt();
                break;
            case RETURNTK: // return 语句
                parseReturnStmt();
                break;
            case PRINTFTK:  // printf 语句
                parsePrintfStmt();
                break;
            default:  // LVal 语句
                parseLValOrExpStmt();
        }
        outputList.add("<Stmt>\n");
    }

    private void parseIfStmt() {
        skipTokens(2);
        parseCond();
        if (curToken.getCategory() != Category.RPARENT) {
            dealError("j");
        } else {
            skipTokens(1); // skip )
        }
        parseStmt();
        if (curToken.getCategory() == Category.ELSETK) {
            skipTokens(1);
            parseStmt();
        }
    }

    private void parseForLoop() {
        skipTokens(2);
        if (curToken.getCategory() != Category.SEMICN) {
            parseForStmt();
        }
        skipTokens(1); // skip ;
        if (curToken.getCategory() != Category.SEMICN) {
            parseCond();
        }
        skipTokens(1); // skip ;
        if (curToken.getCategory() != Category.RPARENT) {
            parseForStmt();
        }
        if (curToken.getCategory() != Category.RPARENT) {
            dealError("j");
        } else {
            skipTokens(1); // skip )
        }
        parseStmt();
    }

    private void parseBreakStmt() {
        skipTokens(1); // skip breaks
        if (curToken.getCategory() != Category.SEMICN) {
            dealError("i");
        } else {
            skipTokens(1); // skip ;
        }
    }

    private void parseContinueStmt() {
        skipTokens(1); // skip continue
        if (curToken.getCategory() != Category.SEMICN) {
            dealError("i");
        } else {
            skipTokens(1); // skip ;
        }
    }

    private void parseReturnStmt() {
        int returnLineNumber = curToken.getLine();
        skipTokens(1); // skip return
        if (curToken.getCategory() != Category.SEMICN) {
            if (curToken.getLine() == returnLineNumber) {
                parseExp();
                if (curToken.getCategory() != Category.SEMICN) {
                    dealError("i");
                } else {
                    skipTokens(1); // skip ;
                }
            } else {
                dealError("i");
            }
        } else {
            skipTokens(1); // skip ;
        }
    }

    private void parsePrintfStmt() {
        skipTokens(3); // skip printf, (, string
        while (curToken.getCategory() == Category.COMMA) {
            skipTokens(1); // skip ,
            parseExp();
        }
        if (curToken.getCategory() != Category.RPARENT) {
            dealError("j");
        } else {
            skipTokens(1); // skip )
        }
        if (curToken.getCategory() != Category.SEMICN) {
            dealError("i");
        } else {
            skipTokens(1); // skip ;
        }
    }

    private void parseLValOrExpStmt() {
        if (isHasAssign()) {
            parseLVal();
            skipTokens(1); // skip =
            if (curToken.getCategory() == Category.GETINTTK || curToken.getCategory() == Category.GETCHARTK) {
                skipTokens(2); // skip get*, (
                if (curToken.getCategory() != Category.RPARENT) {
                    dealError("j");
                } else {
                    skipTokens(1); // skip )
                }
                if (curToken.getCategory() != Category.SEMICN) {
                    dealError("i");
                } else {
                    skipTokens(1); // skip ;
                }
            } else {
                parseExp();
                if (curToken.getCategory() != Category.SEMICN) {
                    dealError("i");
                } else {
                    skipTokens(1); // skip ;
                }
            }
        } else {
            parseExp();
            if (curToken.getCategory() != Category.SEMICN) {
                dealError("i");
            } else {
                skipTokens(1); // skip ;
            }
        }
    }

    private void parseForStmt() {
        parseLVal();
        skipTokens(1); // skip =
        parseExp();
        outputList.add("<ForStmt>\n");
    }

    private void parseCond() {
        parseLOrExp();
        outputList.add("<Cond>\n");
    }

    private void parseLOrExp() {
        parseLAndExp();
        outputList.add("<LOrExp>\n");
        while (curToken.getCategory() == Category.OR) {
            skipTokens(1);
            parseLAndExp();
            outputList.add("<LOrExp>\n");
        }
    }

    private void parseLAndExp() {
        parseEqExp();
        outputList.add("<LAndExp>\n");
        while (curToken.getCategory() == Category.AND) {
            skipTokens(1);
            parseEqExp();
            outputList.add("<LAndExp>\n");
        }
    }

    private void parseEqExp() {
        parseRelExp();
        outputList.add("<EqExp>\n");
        while (curToken.getCategory() == Category.EQL || curToken.getCategory() == Category.NEQ) {
            skipTokens(1);
            parseRelExp();
            outputList.add("<EqExp>\n");
        }
    }

    private void parseRelExp() {
        parseAddExp();
        outputList.add("<RelExp>\n");
        while (curToken.getCategory() == Category.LSS || curToken.getCategory() == Category.LEQ || curToken.getCategory() == Category.GRE || curToken.getCategory() == Category.GEQ) {
            skipTokens(1); // skip <,<=...
            parseAddExp();
            outputList.add("<RelExp>\n");
        }
    }

    private void parseFuncFParams() {
        parseFuncFParam();
        while (curToken.getCategory() == Category.COMMA) {
            skipTokens(1); // skip ,
            parseFuncFParam();
        }
        outputList.add("<FuncFParams>\n");
    }

    private void parseFuncFParam() {
        skipTokens(2);
        if (curToken.getCategory() == Category.LBRACK) {
            skipTokens(1); // skip [
            if (curToken.getCategory() != Category.RBRACK) {
                dealError("k");
            } else {
                skipTokens(1); // skip ]
            }
        }
        outputList.add("<FuncFParam>\n");
    }

    private void parseFuncType() {
        skipTokens(1); // skip type
        outputList.add("<FuncType>\n");
    }

    private void parseDecl() {
        if (curToken.getCategory() == Category.CONSTTK) {
            parseConstDecl();
        } else {
            parseVarDecl();
        }
        // no need to output
    }

    private void parseVarDecl() {
        skipTokens(1); // skip BType
        parseVarDef();
        while (curToken.getCategory() == Category.COMMA) {
            skipTokens(1); // skip ,
            parseVarDef();
        }
        if (curToken.getCategory() != Category.SEMICN) {
            dealError("i");
        } else {
            skipTokens(1); // skip ;
        }
        outputList.add("<VarDecl>\n");
    }

    private void parseVarDef() {
        skipTokens(1); // skip ident
        if (curToken.getCategory() == Category.LBRACK) { // IF now is [
            skipTokens(1); // skip [
            parseConstExp();
            if (curToken.getCategory() != Category.RBRACK) {
                dealError("k");
            } else {
                skipTokens(1); // skip ]
            }
        }
        if (curToken.getCategory() == Category.ASSIGN) {
            skipTokens(1); // skip =
            parseInitVal();
        }
        outputList.add("<VarDef>\n");
    }

    private void parseInitVal() {
        if (curToken.getCategory() == Category.STRCON) {
            skipTokens(1);
        } else if (curToken.getCategory() == Category.LBRACE) {
            skipTokens(1); // skip {
            parseExp();
            while (curToken.getCategory() == Category.COMMA) {
                skipTokens(1); // skip ,
                parseExp();
            }
            skipTokens(1); // skip }
        } else {
            parseExp();
        }
        outputList.add("<InitVal>\n");
    }

    private void parseConstDecl() {
        skipTokens(2); // skip const, BType
        parseConstDef();
        while (tokens.get(curPos).getCategory() == Category.COMMA) {
            skipTokens(1); // skip ,
            parseConstDef();
        }
        if (curToken.getCategory() != Category.SEMICN) {
            dealError("i");
        } else {
            skipTokens(1); // skip ;
        }
        outputList.add("<ConstDecl>\n");
    }

    private void parseConstDef() {
        skipTokens(1); // skip Ident
        if (curToken.getCategory() == Category.LBRACK) { // if now is [
            skipTokens(1); // skip [
            parseConstExp();
            if (curToken.getCategory() != Category.RBRACK) {
                dealError("k");
            } else {
                skipTokens(1); // skip [
            }
        }
        skipTokens(1); //skip =,jump in InitiVal
        parseConstInitVal();
        outputList.add("<ConstDef>\n");
    }

    private void parseConstInitVal() {
        if (curToken.getCategory() == Category.STRCON) {
            skipTokens(1); // skip
        } else if (curToken.getCategory() == Category.LBRACE) {
            skipTokens(1); // skip {
            if (curToken.getCategory() != Category.RBRACE) {
                parseConstExp();
                while (curToken.getCategory() == Category.COMMA) {
                    skipTokens(1); // skip ,
                    parseConstExp();
                }
            }
            skipTokens(1); // skip }
        } else {
            parseConstExp();
        }
        outputList.add("<ConstInitVal>\n");
    }

    private void parseConstExp() {
        parseAddExp();
        outputList.add("<ConstExp>\n");
    }

    private void parseAddExp() {
        parseMulExp();
        outputList.add("<AddExp>\n");
        while (curToken.getCategory() == Category.PLUS // if now is +
                || curToken.getCategory() == Category.MINU) {// or -
            skipTokens(1); // skip -, +
            parseMulExp();
            outputList.add("<AddExp>\n");
        }
    }

    private void parseMulExp() {
        parseUnaryExp();
        outputList.add("<MulExp>\n");
        while (curToken.getCategory() == Category.MULT // if now is *
                || curToken.getCategory() == Category.DIV // or /
                || curToken.getCategory() == Category.MOD) { //or %
            skipTokens(1); // skip *...
            parseUnaryExp();
            outputList.add("<MulExp>\n");
        }
    }

    private void parseUnaryExp() {
        if (isUnaryOp()) { // 当前是 +, -, 或者 !
            parseUnaryOp();
            parseUnaryExp();
        } else if (isFunctionCall()) { // 当前是函数调用
            parseFunctionCall();
        } else {
            parsePrimaryExp(); // 否则解析为基本表达式
        }
        outputList.add("<UnaryExp>\n");
    }

    private boolean isUnaryOp() {
        return curToken.getCategory() == Category.NOT|| curToken.getCategory() == Category.MINU || curToken.getCategory() == Category.PLUS;
    }

    private boolean isFunctionCall() {
        return curToken.getCategory() == Category.IDENFR && nextTokenRD(1).getCategory() == Category.LPARENT;
    }

    private void parseFunctionCall() {
        skipTokens(1);  // now is (

        if (nextTokenRD(1).getCategory() != Category.RPARENT) { // if next isn't )
            skipTokens(1); // skip (
            if (curToken.getCategory() == Category.SEMICN) { // 不含参数的函数调用
                dealError("j");
            }
            else {
                parseFuncRParams();
                if (curToken.getCategory() != Category.RPARENT) {
                    dealError("j");
                } else {
                    skipTokens(1); // skip )
                }
            }
        } else {
            skipTokens(2); // skip ( and )
        }
    }


    private void parseFuncRParams() {
        parseExp();
        while (curToken.getCategory() == Category.COMMA) {
            skipTokens(1); // skip ,
            parseExp();
        }
        outputList.add("<FuncRParams>\n");
    }

    private void parsePrimaryExp() {
        if (curToken.getCategory() == Category.LPARENT) {
            skipTokens(1); // skip (
            parseExp();
            if (curToken.getCategory() != Category.RPARENT) {
                dealError("j");
            } else {
                skipTokens(1); // skip )
            }
        } else if (curToken.getCategory() == Category.IDENFR) {
            parseLVal();
        } else { // it's num or char
            if (curToken.getCategory() == Category.INTCON) {
                parseNumber();
            } else {
                parseCharacter();
            }
        }
        outputList.add("<PrimaryExp>\n");
    }

    private void parseNumber() {
        skipTokens(1); // just skip
        outputList.add("<Number>\n");
    }

    private void parseCharacter() {
        skipTokens(1); // just skip
        outputList.add("<Character>\n");
    }

    private void parseLVal() {
        if (nextTokenRD(1).getCategory() == Category.LBRACK) { // if next is [
            skipTokens(2); // skip Ident and [
            parseExp();
            if (curToken.getCategory() != Category.RBRACK) {
                dealError("k");
            } else {
                skipTokens(1); // skip ]
            }
        } else { // only Ident
            skipTokens(1); // just skip
        }
        outputList.add("<LVal>\n");
    }

    private void parseExp() {
        parseAddExp();
        outputList.add("<Exp>\n");
    }

    private void parseUnaryOp() {
        skipTokens(1);
        outputList.add("<UnaryOp>\n");
    }

    private void dealError(String type) {
        if (isCorrect) {
            isCorrect = false;
        }
        error.parseError(tokens.get(curPos - 1).getLine(), type);
    }

    private boolean isHasAssign() {
        int lineNumber = curToken.getLine();
        int index = 1;
        boolean isHasAssign = false;
        while (nextTokenRD(index) != null && nextTokenRD(index).getLine() == lineNumber) {
            if (nextTokenRD(index).getCategory() == Category.ASSIGN) {
                isHasAssign = true;
            }
            index++;
        }
        return isHasAssign;
    }

    private Token nextToken() {
        Token token = tokens.get(curPos);
        outputList.add(token.getCategory() + " " + token.getValue() + "\n");
        curPos++;
        if (curPos < tokens.size()) {
            return tokens.get(curPos);
        }
        return null;
    }

    private Token nextTokenRD(int index) {
        if (curPos + index < tokens.size()) {
            return tokens.get(curPos + index);
        }
        return null;
    }

    private void skipTokens(int num) {
        for (int i = 0; i < num; i++) {
            curToken = nextToken();
        }
    }
}
