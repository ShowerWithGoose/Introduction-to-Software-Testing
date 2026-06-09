public class Parser {
    private static Parser parser;
    private static LexType nowType;
    private static int lastLineNum;

    private Parser() {
        nowType = null;
        lastLineNum = 0;
    }

    public static Parser getInstance() {
        // 如果是第一次使用：
        if (parser == null) {
            parser = new Parser();
        }
        return parser;
    }

    public void parseCompUnit() {
        lastLineNum = Lexer.getInstance().getLineNum();
        Lexer lexer = Lexer.getInstance();
        //LexType nowType = null;
        newNowType();
        while (nowType == LexType.CONSTTK || nowType == LexType.INTTK ||
                nowType == LexType.CHARTK || nowType == LexType.VOIDTK) {
            if (nowType == LexType.CONSTTK) {
                parseDecl();
            } else if (nowType == LexType.VOIDTK) {
                parseFuncDef();
            } else {
                lexer.setPrePos();
                LexType preType = lexer.preRead();
                if (preType == LexType.MAINTK) {
                    parseMainFuncDef();
                    break;
                } else if (preType == LexType.IDENFR) {
                    LexType prePreType = lexer.preRead();
                    if (prePreType == LexType.LPARENT) {
                        parseFuncDef();
                    } else {
                        parseDecl();
                    }
                }
            }
        }
        IOStream.add2outputString(null, null, "CompUnit");
    }

    public void parseDecl() {
        lastLineNum = Lexer.getInstance().getLineNum();
        if (nowType == LexType.CONSTTK) {
            parseConstDecl();
        } else {
            parseVarDecl();
        }
        //IOStream.add2outputString(null, null, "Decl");
    }

    public void parseFuncDef() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseFuncType();
        outputNowWord();
        newNowType(); // 跳过ident
        outputNowWord();
        newNowType(); // 跳过'('
        if (nowType == LexType.INTTK || nowType == LexType.CHARTK || nowType == LexType.VOIDTK) { // 无形参
            parseFuncFParams();
        }
        if (nowType != LexType.RPARENT) {
            IOStream.setErrorHappened(ErrorType.j, lastLineNum,
                    Lexer.getInstance().getCurPos());
        } else {
            outputNowWord();
            newNowType(); // ')'
        }
        parseBlock();
        IOStream.add2outputString(null, null, "FuncDef");
    }

    public void parseMainFuncDef() {
        lastLineNum = Lexer.getInstance().getLineNum();
        outputNowWord();
        newNowType(); // 'int'
        outputNowWord();
        newNowType(); // 'main'
        outputNowWord();
        newNowType(); // '('
        if (nowType != LexType.RPARENT) {
            IOStream.setErrorHappened(ErrorType.j, lastLineNum,
                    Lexer.getInstance().getCurPos());
        } else {
            outputNowWord();
            newNowType(); // ')'
        }
        parseBlock();
        IOStream.add2outputString(null, null, "MainFuncDef");
    }

    public void parseConstDecl() {
        lastLineNum = Lexer.getInstance().getLineNum();
        if (nowType == LexType.CONSTTK) {
            outputNowWord();
            newNowType();
            parseBtype();
            parseConstDef();
            while (nowType == LexType.COMMA) {
                outputNowWord();
                newNowType();
                parseConstDef();
            }
            if (nowType != LexType.SEMICN) {
                IOStream.setErrorHappened(ErrorType.i, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ';'
            }
            IOStream.add2outputString(null, null, "ConstDecl");
        }
    }

    public void parseVarDecl() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseBtype();
        parseVarDef();
        while (nowType == LexType.COMMA) {
            outputNowWord();
            newNowType();
            parseVarDef();
        }
        if (nowType != LexType.SEMICN) { // 缺少';',报错
            IOStream.setErrorHappened(ErrorType.i, lastLineNum,
                    Lexer.getInstance().getCurPos());
        } else {
            outputNowWord();
            newNowType(); // 此时nowType==';',要移动到下一个单词
        }
        IOStream.add2outputString(null, null, "VarDecl");
    }

    public void parseBtype() {
        lastLineNum = Lexer.getInstance().getLineNum();
        outputNowWord();
        newNowType(); // 'int' or 'char'
        //IOStream.add2outputString(null, null, "Btype");
    }

    public void parseConstDef() {
        lastLineNum = Lexer.getInstance().getLineNum();
        outputNowWord();
        newNowType(); // ident
        if (nowType == LexType.LBRACK) { // array
            outputNowWord();
            newNowType(); // '['
            parseConstExp();
            if (nowType != LexType.RBRACK) {
                IOStream.setErrorHappened(ErrorType.k, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ']'
            }
        }
        outputNowWord();
        newNowType(); // '='
        parseConstInitVal();
        IOStream.add2outputString(null, null, "ConstDef");
    }

    public void parseVarDef() {
        lastLineNum = Lexer.getInstance().getLineNum();
        outputNowWord();
        newNowType(); // ident
        if (nowType == LexType.LBRACK) {
            outputNowWord();
            newNowType(); // '['
            parseConstExp();
            if (nowType != LexType.RBRACK) {
                IOStream.setErrorHappened(ErrorType.k, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ']'
            }
        }
        if (nowType == LexType.ASSIGN) {
            outputNowWord();
            newNowType(); // '='
            parseInitVal();
        }
        IOStream.add2outputString(null, null, "VarDef");
    }

    public void parseFuncType() {
        lastLineNum = Lexer.getInstance().getLineNum();
        outputNowWord();
        newNowType(); // funcType
        IOStream.add2outputString(null, null, "FuncType");
    }

    public void parseBlock() {
        lastLineNum = Lexer.getInstance().getLineNum();
        outputNowWord();
        newNowType(); // '{'
        while (nowType != LexType.RBRACE) {
            parseBlockItem();
        }
        outputNowWord();
        newNowType(); // '}'
        IOStream.add2outputString(null, null, "Block");
    }

    public void parseConstExp() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseAddExp();
        IOStream.add2outputString(null, null, "ConstExp");
    }

    public void parseConstInitVal() {
        lastLineNum = Lexer.getInstance().getLineNum();
        if (nowType != LexType.LBRACE && nowType != LexType.STRCON) {
            parseConstExp();
        } else if (nowType == LexType.LBRACE) {
            outputNowWord();
            newNowType(); // '{'
            if (nowType != LexType.RBRACE) {
                parseConstExp();
                while (nowType == LexType.COMMA) {
                    outputNowWord();
                    newNowType(); // ','
                    parseConstExp();
                }
            }
            outputNowWord();
            newNowType(); // '}'
        } else {
            outputNowWord();
            newNowType(); // STRCON
        }
        IOStream.add2outputString(null, null, "ConstInitVal");
    }

    public void parseInitVal() {
        lastLineNum = Lexer.getInstance().getLineNum();
        if (nowType != LexType.LBRACE && nowType != LexType.STRCON) {
            parseExp();
        } else if (nowType == LexType.LBRACE) {
            outputNowWord();
            newNowType(); // '{'
            if (nowType != LexType.RBRACE) {
                parseExp();
                while(nowType == LexType.COMMA) {
                    outputNowWord();
                    newNowType(); // ','
                    parseExp();
                }
            }
            outputNowWord();
            newNowType(); // '}'
        } else {
            outputNowWord();
            newNowType(); // STRCON
        }
        IOStream.add2outputString(null, null, "InitVal");
    }

    public void parseExp() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseAddExp();
        IOStream.add2outputString(null, null, "Exp");
    }

    public void parseFuncFParams() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseFuncFParam();
        while(nowType == LexType.COMMA) {
            outputNowWord();
            newNowType(); // ','
            parseFuncFParam();
        }
        IOStream.add2outputString(null, null, "FuncFParams");
    }

    public void parseFuncFParam() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseBtype();
        outputNowWord();
        newNowType(); // ident
        if (nowType == LexType.LBRACK) {
            outputNowWord();
            newNowType(); // '['
            if (nowType != LexType.RBRACK) {
                IOStream.setErrorHappened(ErrorType.k, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ']'
            }
        }
        IOStream.add2outputString(null, null, "FuncFParam");
    }

    public void parseBlockItem() {
        lastLineNum = Lexer.getInstance().getLineNum();
        if (nowType == LexType.CONSTTK || isBType(nowType)) {
            parseDecl();
        } else {
            parseStmt();
        }
        // IOStream.add2outputString(null, null, "BlockItem");
    }

    public void parseStmt() {
        lastLineNum = Lexer.getInstance().getLineNum();
        Lexer.getInstance().setPrePos();
        LexType preType = Lexer.getInstance().preRead();
        if (nowType == LexType.IDENFR && preType == LexType.LPARENT) {
            parseExp();
            if (nowType != LexType.SEMICN) { // 报错
                IOStream.setErrorHappened(ErrorType.i, lastLineNum, Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ';'
            }
        } else if (nowType == LexType.IDENFR) {
            int outputPos = IOStream.getOutputPos();
            int curPos = Lexer.getInstance().getCurPos();
            int lineNum = Lexer.getInstance().getLineNum();
            LexType lexType = Lexer.getInstance().getLexType();
            String token = Lexer.getInstance().getToken();
            LexType lastType = nowType;
            parseLVal();
            if (nowType != LexType.ASSIGN) { // 回溯
                IOStream.removeByPos(outputPos);
                Lexer.getInstance().reset(lineNum, curPos, lexType, token); // 删除之前的记录
                nowType = lastType;
                parseExp();
            } else {
                outputNowWord();
                newNowType(); // '='
                if (nowType == LexType.GETINTTK || nowType == LexType.GETCHARTK) {
                    outputNowWord();
                    newNowType(); // getInt or getChar
                    outputNowWord();
                    newNowType(); // '('
                    if (nowType != LexType.RPARENT) {
                        IOStream.setErrorHappened(ErrorType.j, lastLineNum,
                                Lexer.getInstance().getCurPos());
                    } else {
                        outputNowWord();
                        newNowType(); // ')'
                    }
                } else {
                    parseExp();
                }
            }
            if (nowType != LexType.SEMICN) { // 报错
                IOStream.setErrorHappened(ErrorType.i, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ';'
            }
        } else if (nowType == LexType.LBRACE) {
            parseBlock();
        } else if (nowType == LexType.IFTK) {
            outputNowWord();
            newNowType(); // 'if'
            outputNowWord();
            newNowType(); // '('
            parseCond();
            if (nowType != LexType.RPARENT) {
                IOStream.setErrorHappened(ErrorType.j, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ')'
            }
            parseStmt();
            if (nowType == LexType.ELSETK) {
                outputNowWord();
                newNowType(); // 'else'
                parseStmt();
            }
        } else if (nowType == LexType.FORTK) {
            outputNowWord();
            newNowType(); // 'for'
            outputNowWord();
            newNowType(); // '('
            if (nowType != LexType.SEMICN) {
                parseForStmt();
            }
            outputNowWord();
            newNowType(); // ';'
            if (nowType != LexType.SEMICN) {
                parseCond();
            }
            outputNowWord();
            newNowType(); // ';'
            if (nowType != LexType.RPARENT) {
                parseForStmt();
            }
            outputNowWord();
            newNowType(); // ')'
            parseStmt();
        } else if (nowType == LexType.BREAKTK || nowType == LexType.CONTINUETK) {
            outputNowWord();
            newNowType(); // break or continue
            if (nowType != LexType.SEMICN) {
                IOStream.setErrorHappened(ErrorType.i, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ';'
            }
        } else if (nowType == LexType.RETURNTK) {
            outputNowWord();
            newNowType(); // return
            if (nowType == LexType.LPARENT || nowType == LexType.IDENFR || nowType == LexType.INTCON
                    || nowType == LexType.CHRCON || nowType == LexType.PLUS
                    || nowType == LexType.MINU || nowType == LexType.NOT) { // IsEXP
                parseExp();
            }
            if (nowType != LexType.SEMICN) {
                IOStream.setErrorHappened(ErrorType.i, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ';'
            }
        } else if (nowType == LexType.PRINTFTK) {
            outputNowWord();
            newNowType(); // printf
            outputNowWord();
            newNowType(); // '('
            outputNowWord();
            newNowType(); // STRCON
            while (nowType == LexType.COMMA) {
                outputNowWord();
                newNowType();
                parseExp();
            }
            if (nowType != LexType.RPARENT) {
                IOStream.setErrorHappened(ErrorType.j, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ')'
            }
            if (nowType != LexType.SEMICN) {
                IOStream.setErrorHappened(ErrorType.i, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ';'
            }
        } else {
            if (nowType == LexType.LPARENT || nowType == LexType.IDENFR || nowType == LexType.INTCON
                    || nowType == LexType.CHRCON || nowType == LexType.PLUS
                    || nowType == LexType.MINU || nowType == LexType.NOT) { // is EXP
                parseExp();
            }
            if (nowType != LexType.SEMICN) { // 报错
                IOStream.setErrorHappened(ErrorType.i, lastLineNum, Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ';'
            }
        }
        IOStream.add2outputString(null, null, "Stmt");
    }

    private boolean isBType(LexType a) {
        lastLineNum = Lexer.getInstance().getLineNum();
        return (a == LexType.INTTK || a == LexType.CHARTK
                || a == LexType.VOIDTK);
    }

    public void parseForStmt() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseLVal();
        outputNowWord();
        newNowType(); // '='
        parseExp();
        IOStream.add2outputString(null, null, "ForStmt");
    }

    public void parseCond() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseLorExp();
        IOStream.add2outputString(null, null, "Cond");
    }

    public void parseLVal() {
        lastLineNum = Lexer.getInstance().getLineNum();
        outputNowWord();
        newNowType(); // Ident
        if (nowType == LexType.LBRACK) {
            outputNowWord();
            newNowType(); // '['
            parseExp();
            if (nowType != LexType.RBRACK) {
                IOStream.setErrorHappened(ErrorType.k, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ']'
            }
        }
        IOStream.add2outputString(null, null, "LVal");
    }

    public void parseAddExp() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseMulExp();
        IOStream.add2outputString(null, null, "AddExp");
        while(nowType == LexType.PLUS || nowType == LexType.MINU) {
            outputNowWord();
            newNowType(); // + or -
            parseMulExp();
            IOStream.add2outputString(null, null, "AddExp");
        }
    }

    public void parseMulExp() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseUnaryExp();
        IOStream.add2outputString(null, null, "MulExp");
        while (nowType == LexType.MULT || nowType == LexType.DIV
                || nowType == LexType.MOD) {
            outputNowWord();
            newNowType(); // * or / or %
            parseUnaryExp();
            IOStream.add2outputString(null, null, "MulExp");
        }
    }

    public void parseLorExp() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseLAndExp();
        IOStream.add2outputString(null, null, "LOrExp");
        while (nowType == LexType.OR) {
            outputNowWord();
            newNowType(); // ||
            parseLAndExp();
            IOStream.add2outputString(null, null, "LOrExp");
        }
    }

    public void parseLAndExp() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseEqExp();
        IOStream.add2outputString(null, null, "LAndExp");
        while (nowType == LexType.AND) {
            outputNowWord();
            newNowType(); // &&
            parseEqExp();
            IOStream.add2outputString(null, null, "LAndExp");
        }
    }

    public void parseUnaryExp() {
        lastLineNum = Lexer.getInstance().getLineNum();
        if (nowType == LexType.LPARENT || nowType == LexType.INTCON ||
                nowType == LexType.CHRCON || isLVal()) {
            parsePrimaryExp();
        } else if (nowType == LexType.IDENFR) {
            outputNowWord();
            newNowType(); // ident
            outputNowWord();
            newNowType(); // '('
            if (nowType == LexType.LPARENT || nowType == LexType.IDENFR || nowType == LexType.INTCON
                    || nowType == LexType.CHRCON || nowType == LexType.PLUS
                    || nowType == LexType.MINU || nowType == LexType.NOT) { //IsExp
                parseFuncRParams();
            }
            if (nowType != LexType.RPARENT) {
                IOStream.setErrorHappened(ErrorType.j, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ')'
            }
        } else {
            parseUnaryOp();
            parseUnaryExp();
        }
        IOStream.add2outputString(null, null, "UnaryExp");
    }

    private boolean isLVal() { // 仅仅针对于parseUnaryExp方法，其他情况不一定通用
        lastLineNum = Lexer.getInstance().getLineNum();
        Lexer lexer = Lexer.getInstance();
        if (nowType == LexType.IDENFR) {
            lexer.setPrePos();
            if (lexer.preRead() != LexType.LPARENT) {
                return true;
            }
        }
        return false;
    }

    public void parsePrimaryExp() {
        lastLineNum = Lexer.getInstance().getLineNum();
        if (nowType == LexType.LPARENT) {
            outputNowWord();
            newNowType(); // '('
            parseExp();
            if (nowType != LexType.RPARENT) {
                IOStream.setErrorHappened(ErrorType.j, lastLineNum,
                        Lexer.getInstance().getCurPos());
            } else {
                outputNowWord();
                newNowType(); // ')'
            }
        } else if (nowType == LexType.IDENFR) {
            parseLVal();
        } else if (nowType == LexType.INTCON) {
            parseNumber();
        } else if (nowType == LexType.CHRCON) {
            parseCharacter();
        }
        IOStream.add2outputString(null, null, "PrimaryExp");
    }

    public void parseNumber() {
        lastLineNum = Lexer.getInstance().getLineNum();
        outputNowWord();
        newNowType(); // INTCON
        IOStream.add2outputString(null, null, "Number");
    }

    public void parseCharacter() {
        lastLineNum = Lexer.getInstance().getLineNum();
        outputNowWord();
        newNowType(); // CHRCON
        IOStream.add2outputString(null, null, "Character");
    }

    public void parseFuncRParams() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseExp();
        while (nowType == LexType.COMMA) {
            outputNowWord();
            newNowType(); // ','
            parseExp();
        }
        IOStream.add2outputString(null, null, "FuncRParams");
    }

    public void parseEqExp() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseRelExp();
        IOStream.add2outputString(null, null, "EqExp");
        while (nowType == LexType.EQL || nowType == LexType.NEQ) {
            outputNowWord();
            newNowType();
            parseRelExp();
            IOStream.add2outputString(null, null, "EqExp");
        }
    }

    public void parseRelExp() {
        lastLineNum = Lexer.getInstance().getLineNum();
        parseAddExp();
        IOStream.add2outputString(null, null, "RelExp");
        while (nowType == LexType.LSS || nowType == LexType.LEQ ||
                nowType == LexType.GRE ||nowType == LexType.GEQ) {
            outputNowWord();
            newNowType();
            parseAddExp();
            IOStream.add2outputString(null, null, "RelExp");
        }
    }

    public void parseUnaryOp() {
        lastLineNum = Lexer.getInstance().getLineNum();
        outputNowWord();
        newNowType(); // + - !
        IOStream.add2outputString(null, null, "UnaryOp");
    }

    private void newNowType() { //往后读一个单词更新到nowType中
        lastLineNum = Lexer.getInstance().getLineNum();
        Lexer.getInstance().read1word();
        nowType = Lexer.getInstance().getLexType();
    }

    private void outputNowWord() {
        IOStream.add2outputString(nowType,
                Lexer.getInstance().getToken(), null);
    }

    private void preReadLVal() {
        Lexer.getInstance().setPrePos();
        LexType preType = Lexer.getInstance().preRead();
        if (preType == LexType.LBRACK) {
            Lexer.getInstance().preRead(); // '['
            preReadExp();

            LexType prePreType = Lexer.getInstance().preRead(); // ']'
        }
    }

    private void preReadExp() {

    }

}
