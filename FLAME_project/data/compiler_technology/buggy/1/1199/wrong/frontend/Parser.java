package frontend;

import frontend.Lexer;
import frontend.Node;
import frontend.Token;
import frontend.TokenType;

public class Parser {
    private final Lexer lexer;

    public Parser(Lexer lexer) {
        this.lexer = lexer;
    }

    private void error(TokenType tokenType) {
        if (tokenType == TokenType.SEMICN) {
            lexer.back();
            lexer.getError().get(lexer.peek().getLineNumber()).add('i');
            lexer.next();
        } else if (tokenType == TokenType.RPARENT) {
            lexer.back();
            lexer.getError().get(lexer.peek().getLineNumber()).add('i');
            lexer.next();
        } else if (tokenType == TokenType.RBRACK) {
            lexer.back();
            lexer.getError().get(lexer.peek().getLineNumber()).add('i');
            lexer.next();
        }
    }

    private void match(Node node, Token token, TokenType tokenType) {
        if (token.equal(tokenType)) {
            node.addChild(new Node(token));
            lexer.next();
        } else error(tokenType);
    }

    public Node parseCompUnit() {
        Node compUnit = new Node(Type.CompUnit);
        while (lexer.peek().equal(TokenType.CONSTTK) || lexer.peek().equal(TokenType.INTTK) || lexer.peek().equal(TokenType.CHARTK)) {
            if (lexer.peek().equal(TokenType.CONSTTK)) {
                compUnit.addChild(parseDecl());
            } else if (lexer.peek().equal(TokenType.INTTK)) {
                lexer.next();
                if (lexer.peek().equal(TokenType.IDENFR)) {
                    lexer.next();
                    if (!lexer.peek().equal(TokenType.LPARENT)) {
                        lexer.back();
                        lexer.back();
                        compUnit.addChild(parseDecl());
                    } else {
                        lexer.back();
                        lexer.back();
                        break;
                    }
                } else {
                    lexer.back();
                    break;
                }
            } else if (lexer.peek().equal(TokenType.CHARTK)) {
                lexer.next();
                lexer.next();
                if (!lexer.peek().equal(TokenType.LPARENT)) {
                    lexer.back();
                    lexer.back();
                    compUnit.addChild(parseDecl());
                } else {
                    lexer.back();
                    lexer.back();
                    break;
                }
            }
        }
        while (lexer.peek().equal(TokenType.VOIDTK) || lexer.peek().equal(TokenType.INTTK) || lexer.peek().equal(TokenType.CHARTK)) {
            if (lexer.peek().equal(TokenType.VOIDTK) || lexer.peek().equal(TokenType.CHARTK)) {
                compUnit.addChild(parseFuncDef());
            } else {
                lexer.next();
                if (lexer.peek().equal(TokenType.IDENFR)) {
                    lexer.back();
                    compUnit.addChild(parseFuncDef());
                } else {
                    lexer.back();
                    break;
                }
            }
        }
        compUnit.addChild(parseMainFuncDef());
        return compUnit;
    }

    private Node parseDecl() {
        Node decl = null;
        if (lexer.peek().equal(TokenType.CONSTTK)) {
            decl = parseConstDecl();
        } else if (lexer.peek().equal(TokenType.INTTK) || lexer.peek().equal(TokenType.CHARTK)) {
            decl = parseVarDecl();
        } /*else {
            error();
        }*/
        return decl;
    }

    private Node parseConstDecl() {
        Node constDecl = new Node(Type.ConstDecl);
        match(constDecl, lexer.peek(), TokenType.CONSTTK);
        constDecl.addChild(parseBType());
        constDecl.addChild(parseConstDef());
        while (lexer.peek().equal(TokenType.COMMA)) {
            constDecl.addChild(new Node(lexer.peek()));
            lexer.next();
            constDecl.addChild(parseConstDef());
        }
        match(constDecl, lexer.peek(), TokenType.SEMICN);
        return constDecl;
    }

    private Node parseBType() {
        Node bType = null;
        if (lexer.peek().equal(TokenType.INTTK)) {
            bType = new Node(lexer.peek());
            lexer.next();
        } else if (lexer.peek().equal(TokenType.CHARTK)) {
            bType = new Node(lexer.peek());
            lexer.next();
        } /*else {
            error();
        }*/
        return bType;
    }

    private Node parseConstDef() {
        Node constDef = new Node(Type.ConstDef);
        match(constDef, lexer.peek(), TokenType.IDENFR);
        if (lexer.peek().equal(TokenType.LBRACK)) {
            constDef.addChild(new Node(lexer.peek()));
            lexer.next();
            constDef.addChild(parseConstExp());
            match(constDef, lexer.peek(), TokenType.RBRACK);
        }
        match(constDef, lexer.peek(), TokenType.ASSIGN);
        constDef.addChild(parseConstInitVal());
        return constDef;
    }

    private Node parseConstInitVal() {
        Node constInitVal = new Node(Type.ConstInitVal);
        if (lexer.peek().equal(TokenType.PLUS) || lexer.peek().equal(TokenType.MINU) ||
        lexer.peek().equal(TokenType.NOT) || lexer.peek().equal(TokenType.IDENFR) ||
        lexer.peek().equal(TokenType.LPARENT) || lexer.peek().equal(TokenType.INTCON) ||
        lexer.peek().equal(TokenType.CHRCON)) {
            constInitVal.addChild(parseConstExp());
        } else if (lexer.peek().equal(TokenType.LBRACE)) {
            constInitVal.addChild(new Node(lexer.peek()));
            lexer.next();
            if (!lexer.peek().equal(TokenType.RBRACE)) {
                constInitVal.addChild(parseConstExp());
                while (lexer.peek().equal(TokenType.COMMA)) {
                    constInitVal.addChild(new Node(lexer.peek()));
                    lexer.next();
                    constInitVal.addChild(parseConstExp());
                }
            }
            match(constInitVal, lexer.peek(), TokenType.RBRACE);
        } else if (lexer.peek().equal(TokenType.STRCON)) {
            constInitVal.addChild(new Node(lexer.peek()));
            lexer.next();
        } //else error();
        return constInitVal;
    }

    private Node parseVarDecl() {
        Node varDecl = new Node(Type.VarDecl);
        varDecl.addChild(parseBType());
        varDecl.addChild(parseVarDef());
        while (lexer.peek().equal(TokenType.COMMA)) {
            varDecl.addChild(new Node(lexer.peek()));
            lexer.next();
            varDecl.addChild(parseVarDef());
        }
        match(varDecl, lexer.peek(), TokenType.SEMICN);
        return varDecl;
    }

    private Node parseVarDef() {
        Node varDef = new Node(Type.VarDef);
        match(varDef, lexer.peek(), TokenType.IDENFR);
        if (lexer.peek().equal(TokenType.LBRACK)) {
            varDef.addChild(new Node(lexer.peek()));
            lexer.next();
            varDef.addChild(parseConstExp());
            match(varDef, lexer.peek(), TokenType.RBRACK);
        }
        if (lexer.peek().equal(TokenType.ASSIGN)) {
            varDef.addChild(new Node(lexer.peek()));
            lexer.next();
            varDef.addChild(parseInitVal());
        }
        return varDef;
    }

    private Node parseInitVal() {
        Node initVal= new Node(Type.InitVal);
        if (lexer.peek().equal(TokenType.PLUS) || lexer.peek().equal(TokenType.MINU) ||
                lexer.peek().equal(TokenType.NOT) || lexer.peek().equal(TokenType.IDENFR) ||
                lexer.peek().equal(TokenType.LPARENT) || lexer.peek().equal(TokenType.INTCON) ||
                lexer.peek().equal(TokenType.CHRCON)) {
            initVal.addChild(parseExp());
        }  else if (lexer.peek().equal(TokenType.LBRACE)) {
            initVal.addChild(new Node(lexer.peek()));
            lexer.next();
            if (!lexer.peek().equal(TokenType.RBRACE)) {
                initVal.addChild(parseExp());
                while (lexer.peek().equal(TokenType.COMMA)) {
                    initVal.addChild(new Node(lexer.peek()));
                    lexer.next();
                    initVal.addChild(parseExp());
                }
            }
            match(initVal, lexer.peek(), TokenType.RBRACE);
        } else if (lexer.peek().equal(TokenType.STRCON)) {
            initVal.addChild(new Node(lexer.peek()));
            lexer.next();
        } //else error();
        return initVal;
    }

    private Node parseFuncDef() {
        Node funcDef = new Node(Type.FuncDef);
        funcDef.addChild(parseFuncType());
        match(funcDef, lexer.peek(), TokenType.IDENFR);
        match(funcDef, lexer.peek(), TokenType.LPARENT);
        if (!lexer.peek().equal(TokenType.RPARENT)) {
            funcDef.addChild(parseFuncFParams());
        }
        match(funcDef, lexer.peek(), TokenType.RPARENT);
        funcDef.addChild(parseBlock());
        return funcDef;
    }

    private Node parseMainFuncDef() {
        Node mainFuncDef = new Node(Type.MainFuncDef);
        match(mainFuncDef, lexer.peek(), TokenType.INTTK);
        match(mainFuncDef, lexer.peek(), TokenType.MAINTK);
        match(mainFuncDef, lexer.peek(), TokenType.LPARENT);
        match(mainFuncDef, lexer.peek(), TokenType.RPARENT);
        mainFuncDef.addChild(parseBlock());
        return mainFuncDef;
    }

    private Node parseFuncType() {
        Node funcType = new Node(Type.FuncType);
        if (lexer.peek().equal(TokenType.VOIDTK)) {
            funcType.addChild(new Node(lexer.peek()));
            lexer.next();
        } else if (lexer.peek().equal(TokenType.INTTK)) {
            funcType.addChild(new Node(lexer.peek()));
            lexer.next();
        } else if (lexer.peek().equal(TokenType.CHARTK)) {
            funcType.addChild(new Node(lexer.peek()));
            lexer.next();
        } //else error();
        return funcType;
    }

    private Node parseFuncFParams() {
        Node funcFParams = new Node(Type.FuncFParams);
        funcFParams.addChild(parseFuncFParam());
        while (lexer.peek().equal(TokenType.COMMA)) {
            funcFParams.addChild(new Node(lexer.peek()));
            lexer.next();
            funcFParams.addChild(parseFuncFParam());
        }
        return funcFParams;
    }

    private Node parseFuncFParam() {
        Node funcFParam = new Node(Type.FuncFParam);
        funcFParam.addChild(parseBType());
        match(funcFParam, lexer.peek(), TokenType.IDENFR);
        if (lexer.peek().equal(TokenType.LBRACK)) {
            funcFParam.addChild(new Node(lexer.peek()));
            lexer.next();
            match(funcFParam, lexer.peek(), TokenType.RBRACK);
        }
        return funcFParam;
    }

    private Node parseBlock() {
        Node block = new Node(Type.Block);
        match(block, lexer.peek(), TokenType.LBRACE);
        while (!lexer.peek().equal(TokenType.RBRACE)) {
            block.addChild(parseBlockItem());
        }
        match(block, lexer.peek(), TokenType.RBRACE);
        return block;
    }

    private Node parseBlockItem() {
        if (lexer.peek().equal(TokenType.CONSTTK) ||
        lexer.peek().equal(TokenType.INTTK) || lexer.peek().equal(TokenType.CHARTK)) {
            return parseDecl();
        } else return parseStmt();
    }

    private Node parseStmt() {
        Node stmt = new Node(Type.Stmt);
        if (lexer.peek().equal(TokenType.IDENFR)) {
            lexer.next();
            if (lexer.peek().equal(TokenType.LPARENT)) {
                lexer.back();
                stmt.addChild(parseExp());
                match(stmt, lexer.peek(), TokenType.SEMICN);
            } else {
                lexer.back();
                int temp = lexer.getI();
                Node node = parseLVal();
                if (lexer.peek().equal(TokenType.ASSIGN)) {
                    stmt.addChild(node);
                    match(stmt, lexer.peek(), TokenType.ASSIGN);
                    if (lexer.peek().equal(TokenType.GETINTTK)) {
                        stmt.addChild(new Node(lexer.peek()));
                        lexer.next();
                        match(stmt, lexer.peek(), TokenType.LPARENT);
                        match(stmt, lexer.peek(), TokenType.RPARENT);
                    } else if (lexer.peek().equal(TokenType.GETCHARTK)) {
                        stmt.addChild(new Node(lexer.peek()));
                        lexer.next();
                        match(stmt, lexer.peek(), TokenType.LPARENT);
                        match(stmt, lexer.peek(), TokenType.RPARENT);
                    } else {
                        stmt.addChild(parseExp());
                    }
                    match(stmt, lexer.peek(), TokenType.SEMICN);
                } else {
                    lexer.setI(temp);
                    stmt.addChild(parseExp());
                    match(stmt, lexer.peek(), TokenType.SEMICN);
                }
            }
        } else if (lexer.peek().equal(TokenType.LBRACE)) {
            stmt.addChild(parseBlock());
        } else if (lexer.peek().equal(TokenType.IFTK)) {
            stmt.addChild(new Node(lexer.peek()));
            lexer.next();
            match(stmt, lexer.peek(), TokenType.LPARENT);
            stmt.addChild(parseCond());
            match(stmt, lexer.peek(), TokenType.RPARENT);
            stmt.addChild(parseStmt());
            if (lexer.peek().equal(TokenType.ELSETK)) {
                stmt.addChild(new Node(lexer.peek()));
                lexer.next();
                stmt.addChild(parseStmt());
            }
        } else if (lexer.peek().equal(TokenType.FORTK)) {
            stmt.addChild(new Node(lexer.peek()));
            lexer.next();
            match(stmt, lexer.peek(), TokenType.LPARENT);
            if (!lexer.peek().equal(TokenType.SEMICN)) {
                stmt.addChild(parseForStmt());
            }
            match(stmt, lexer.peek(), TokenType.SEMICN);
            if (!lexer.peek().equal(TokenType.SEMICN)) {
                stmt.addChild(parseCond());
            }
            match(stmt, lexer.peek(), TokenType.SEMICN);
            if (!lexer.peek().equal(TokenType.RPARENT)) {
                stmt.addChild(parseForStmt());
            }
            match(stmt, lexer.peek(), TokenType.RPARENT);
            stmt.addChild(parseStmt());
        } else if (lexer.peek().equal(TokenType.BREAKTK)) {
            stmt.addChild(new Node(lexer.peek()));
            lexer.next();
            match(stmt, lexer.peek(), TokenType.SEMICN);
        } else if (lexer.peek().equal(TokenType.CONTINUETK)) {
            stmt.addChild(new Node(lexer.peek()));
            lexer.next();
            match(stmt, lexer.peek(), TokenType.SEMICN);
        } else if (lexer.peek().equal(TokenType.RETURNTK)) {
            stmt.addChild(new Node(lexer.peek()));
            lexer.next();
            if (!lexer.peek().equal(TokenType.SEMICN)) {
                stmt.addChild(parseExp());
            }
            match(stmt, lexer.peek(), TokenType.SEMICN);
        } else if (lexer.peek().equal(TokenType.PRINTFTK)) {
            stmt.addChild(new Node(lexer.peek()));
            lexer.next();
            match(stmt, lexer.peek(), TokenType.LPARENT);
            match(stmt, lexer.peek(), TokenType.STRCON);
            while (lexer.peek().equal(TokenType.COMMA)) {
                stmt.addChild(new Node(lexer.peek()));
                lexer.next();
                stmt.addChild(parseExp());
            }
            match(stmt, lexer.peek(), TokenType.RPARENT);
            match(stmt, lexer.peek(), TokenType.SEMICN);
        } else if (!lexer.peek().equal(TokenType.SEMICN)) {
            stmt.addChild(parseExp());
            match(stmt, lexer.peek(), TokenType.SEMICN);
        } else match(stmt, lexer.peek(), TokenType.SEMICN);
        return stmt;
    }

    private Node parseForStmt() {
        Node forStmt = new Node(Type.ForStmt);
        forStmt.addChild(parseLVal());
        match(forStmt, lexer.peek(), TokenType.ASSIGN);
        forStmt.addChild(parseExp());
        return forStmt;
    }

    private Node parseExp() {
        Node exp = new Node(Type.Exp);
        exp.addChild(parseAddExp());
        return exp;
    }

    private Node parseCond() {
        Node cond = new Node(Type.Cond);
        cond.addChild(parseLOrExp());
        return cond;
    }

    private Node parseLVal() {
        Node lVal = new Node(Type.LVal);
        match(lVal, lexer.peek(), TokenType.IDENFR);
        if (lexer.peek().equal(TokenType.LBRACK)) {
            lVal.addChild(new Node(lexer.peek()));
            lexer.next();
            lVal.addChild(parseExp());
            match(lVal, lexer.peek(), TokenType.RBRACK);
        }
        return lVal;
    }

    private Node parsePrimaryExp() {
        Node primaryExp = new Node(Type.PrimaryExp);
        if (lexer.peek().equal(TokenType.LPARENT)) {
            primaryExp.addChild(new Node(lexer.peek()));
            lexer.next();
            primaryExp.addChild(parseExp());
            match(primaryExp, lexer.peek(), TokenType.RPARENT);
        } else if (lexer.peek().equal(TokenType.IDENFR)) {
            primaryExp.addChild(parseLVal());
        } else if (lexer.peek().equal(TokenType.INTCON)) {
            primaryExp.addChild(parseNumber());
        } else if (lexer.peek().equal(TokenType.CHRCON)) {
            primaryExp.addChild(parseCharacter());
        } //else error();
        return primaryExp;
    }

    private Node parseNumber() {
        Node number = new Node(Type.Number);
        match(number, lexer.peek(), TokenType.INTCON);
        return number;
    }

    private Node parseCharacter() {
        Node character = new Node(Type.Character);
        match(character, lexer.peek(), TokenType.CHRCON);
        return character;
    }

    private Node parseUnaryExp() {
        Node unaryExp = new Node(Type.UnaryExp);
        if (lexer.peek().equal(TokenType.IDENFR)) {
            lexer.next();
            if (lexer.peek().equal(TokenType.LPARENT)) {
                lexer.back();
                unaryExp.addChild(new Node(lexer.peek()));
                lexer.next();
                match(unaryExp, lexer.peek(), TokenType.LPARENT);
                if (!lexer.peek().equal(TokenType.RPARENT)) {
                    unaryExp.addChild(parseFuncRParams());
                }
                match(unaryExp, lexer.peek(), TokenType.RPARENT);
            } else {
                lexer.back();
                unaryExp.addChild(parsePrimaryExp());
            }
        } else if (lexer.peek().equal(TokenType.PLUS) ||
        lexer.peek().equal(TokenType.MINU) || lexer.peek().equal(TokenType.NOT)) {
            unaryExp.addChild(parseUnaryOp());
            unaryExp.addChild(parseUnaryExp());
        } else unaryExp.addChild(parsePrimaryExp());
        return unaryExp;
    }

    private Node parseUnaryOp() {
        Node unaryOp = new Node(Type.UnaryOp);
        if (lexer.peek().equal(TokenType.PLUS) ||
                lexer.peek().equal(TokenType.MINU) || lexer.peek().equal(TokenType.NOT)) {
            unaryOp.addChild(new Node(lexer.peek()));
            lexer.next();
        } //else error();
        return unaryOp;
    }

    private Node parseFuncRParams() {
        Node funcRParams = new Node(Type.FuncRParams);
        funcRParams.addChild(parseExp());
        while (lexer.peek().equal(TokenType.COMMA)) {
            funcRParams.addChild(new Node(lexer.peek()));
            lexer.next();
            funcRParams.addChild(parseExp());
        }
        return funcRParams;
    }

    private Node parseMulExp() {
        Node mulExp = new Node(Type.MulExp);
        mulExp.addChild(parseUnaryExp());
        while (lexer.peek().equal(TokenType.MULT) || lexer.peek().equal(TokenType.DIV) || lexer.peek().equal(TokenType.MOD)) {
            mulExp.addChild(new Node(lexer.peek()));
            lexer.next();
            mulExp.addChild(parseUnaryExp());
        }
        return mulExp;
    }

    private Node parseAddExp() {
        Node addExp = new Node(Type.AddExp);
        addExp.addChild(parseMulExp());
        while (lexer.peek().equal(TokenType.PLUS) || lexer.peek().equal(TokenType.MINU)) {
            addExp.addChild(new Node(lexer.peek()));
            lexer.next();
            addExp.addChild(parseMulExp());
        }
        return addExp;
    }

    private Node parseRelExp() {
        Node relExp = new Node(Type.RelExp);
        relExp.addChild(parseAddExp());
        while (lexer.peek().equal(TokenType.LSS) || lexer.peek().equal(TokenType.LEQ) || lexer.peek().equal(TokenType.GRE) || lexer.peek().equal(TokenType.GEQ)) {
            relExp.addChild(new Node(lexer.peek()));
            lexer.next();
            relExp.addChild(parseAddExp());
        }
        return relExp;
    }

    private Node parseEqExp() {
        Node eqExp = new Node(Type.EqExp);
        eqExp.addChild(parseRelExp());
        while (lexer.peek().equal(TokenType.EQL) || lexer.peek().equal(TokenType.NEQ)) {
            eqExp.addChild(new Node(lexer.peek()));
            lexer.next();
            eqExp.addChild(parseRelExp());
        }
        return eqExp;
    }

    private Node parseLAndExp() {
        Node lAndExp = new Node(Type.LAndExp);
        lAndExp.addChild(parseEqExp());
        while (lexer.peek().equal(TokenType.AND)) {
            lAndExp.addChild(new Node(lexer.peek()));
            lexer.next();
            lAndExp.addChild(parseEqExp());
        }
        return lAndExp;
    }

    private Node parseLOrExp() {
        Node lOrExp = new Node(Type.LOrExp);
        lOrExp.addChild(parseLAndExp());
        while (lexer.peek().equal(TokenType.OR)) {
            lOrExp.addChild(new Node(lexer.peek()));
            lexer.next();
            lOrExp.addChild(parseLAndExp());
        }
        return lOrExp;
    }

    private Node parseConstExp() {
        Node constExp = new Node(Type.ConstExp);
        constExp.addChild(parseAddExp());
        return constExp;
    }

}
