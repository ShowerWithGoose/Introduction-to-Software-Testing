import node.*;
import node.TokenType;
import java.util.ArrayList;

public class Parser {
    private TokenList tokens;
    private ArrayList<tokenError> tokenErrors;

    public Parser(TokenList tokens,ArrayList<tokenError> tokenErrors) {
        this.tokens = tokens;
        this.tokenErrors = tokenErrors;
    }
    public boolean isExp(Token token) {
        int index = tokens.getIndex();
        if (token.getTokenType() == TokenType.LPARENT || token.getTokenType() == TokenType.INTCON || token.getTokenType() == TokenType.STRCON || token.getTokenType() == TokenType.CHRCON) {
            return true;
        }
        if (token.getTokenType() == TokenType.IDENFR) {
            return !isLValBegin(token);
        }
        return false;

    }
    public TreeNode parseCompUnit() {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        Token token = tokens.getNext();
        while (isDecl(token)) {
            nodes.add(parseDecl(token));
            token = tokens.getNext();
        }
        while (!isMain(token)) {
            nodes.add(parseFuncDef(token));
            token = tokens.getNext();
        }
        nodes.add(parseMainFuncDef(token));
        return new CompUnitNode(nodes);

    }

    public boolean isMain(Token token) {
        Token t = tokens.getNext();
        if (token.getTokenType() == TokenType.INTTK && t.getTokenType() == TokenType.MAINTK) {
            tokens.backLast();
            return true;
        }
        tokens.backLast();
        return false;
    }

    public boolean isDecl(Token token) {
        if (token.getTokenType() == TokenType.CONSTTK) {
            return true;
        }
        Token token1 = tokens.getNext();
        Token token2 = tokens.getNext();
        if (token2.getTokenType() == TokenType.LPARENT) {
            tokens.backLast();
            tokens.backLast();
            return false;
        }
        /*
        if (token1.getTokenType() == TokenType.MAINTK) {
            tokens.backLast();
            tokens.backLast();
            return false;
        }*/
        tokens.backLast();
        tokens.backLast();
        return true;
    }
    public TreeNode parseMainFuncDef(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(token);
        nodes.add(tokens.getNext());
        nodes.add(tokens.getNext());
        Token token1 = tokens.getNext();
        if (token1.getTokenType() != TokenType.RPARENT) {
            tokens.backLast();
            tokenErrors.add(new tokenError(getErrorLine('j',nodes),"j"));
        }
        nodes.add(token1);
        nodes.add(parseBlock(tokens.getNext()));
        return new MainFuncDefNode(nodes);
    }

    public TreeNode parseFuncDef(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseFuncType(token));
        nodes.add(tokens.getNext()); // ident
        nodes.add(tokens.getNext()); // '('
        Token t = tokens.getNext();
        if (t.getTokenType() != TokenType.RPARENT && t.getTokenType() != TokenType.LBRACE) {
            nodes.add(parseFuncFParams(t));
            t = tokens.getNext();
        }
        if (t.getTokenType() != TokenType.RPARENT) {
            tokens.backLast();
            tokenErrors.add(new tokenError(getErrorLine('j',nodes),"j"));
        } else {
            nodes.add(t); // ')'
        }

        nodes.add(parseBlock(tokens.getNext()));
        return new FuncDefNode(nodes);
    }

    public TreeNode parseBlock(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(token);
        Token t = tokens.getNext();
        while (t.getTokenType() != TokenType.RBRACE) {
            nodes.add(parseBlockItem(t));
            t = tokens.getNext();
        }
        nodes.add(t);
        return new BlockNode(nodes);
    }

    public TreeNode parseBlockItem(Token token) {
        if (token.getTokenType() == TokenType.CONSTTK || token.getTokenType() == TokenType.INTTK || token.getTokenType() == TokenType.CHARTK) {
            return new BlockItemNode(parseDecl(token));
        }
        else {
            return new BlockItemNode(parseStmt(token));
        }
    }

    public TreeNode parseStmt(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        if (token.getTokenType() == TokenType.INTCON || token.getTokenType() == TokenType.CHRCON || token.getTokenType() == TokenType.LPARENT ||
                token.getTokenType() == TokenType.PLUS || token.getTokenType() == TokenType.MINU || token.getTokenType() == TokenType.NOT) {
            nodes.add(parseExp(token));
            Token t = tokens.getNext();
            if (t.getTokenType() != TokenType.SEMICN) {
                tokens.backLast();
                tokenErrors.add(new tokenError(getErrorLine('i',nodes),"i"));
            } else {
                nodes.add(t); //';'
            }
        }
        else if (token.getTokenType() == TokenType.SEMICN) {
            nodes.add(token);
        }
        else if (token.getTokenType() == TokenType.IDENFR) {
            // 可能是 LVal 或者 Exp

            if (!isLValBegin(token)) {
                //Exp
                nodes.add(parseExp(token));
                Token t = tokens.getNext();
                if (t.getTokenType() != TokenType.SEMICN) {
                    tokens.backLast();
                    tokenErrors.add(new tokenError(getErrorLine('i',nodes),"i"));
                } else {
                    nodes.add(t); //';'
                }
            }
            else {

                nodes.add(parseLVal(token));
                nodes.add(tokens.getNext()); // '='
                Token t = tokens.getNext();
                if (t.getTokenType() == TokenType.GETCHARTK || t.getTokenType() == TokenType.GETINTTK) {
                    nodes.add(t);
                    nodes.add(tokens.getNext()); //'('
                    t = tokens.getNext();
                    if (t.getTokenType() != TokenType.RPARENT) {
                        tokens.backLast();
                        tokenErrors.add(new tokenError(getErrorLine('j',nodes),"j"));
                    } else {
                        nodes.add(t); //')'
                    }


                    t = tokens.getNext();
                    if (t.getTokenType() != TokenType.SEMICN) {
                        tokens.backLast();
                        tokenErrors.add(new tokenError(getErrorLine('i',nodes),"i"));
                    } else {
                        nodes.add(t); //';'
                    }

                } else {
                    nodes.add(parseExp(t));
                    t = tokens.getNext();
                    if (t.getTokenType() != TokenType.SEMICN) {
                        tokens.backLast();
                        tokenErrors.add(new tokenError(getErrorLine('i',nodes),"i"));
                    } else {
                        nodes.add(t); //';'
                    }
                }
            }
        }
        else if (token.getTokenType() == TokenType.LBRACE) {
            nodes.add(parseBlock(token));
        }
        else if (token.getTokenType() == TokenType.IFTK) {
            nodes.add(token); // 'if'
            nodes.add(tokens.getNext()); // '('
            nodes.add(parseCond(tokens.getNext())); // Cond
            Token t = tokens.getNext();
            if (t.getTokenType() != TokenType.RPARENT) {
                tokens.backLast();
                tokenErrors.add(new tokenError(getErrorLine('j',nodes),"j"));
            } else {
                nodes.add(t); //')'
            }
            //nodes.add(tokens.getNext()); // ')'
            nodes.add(parseStmt(tokens.getNext())); // Stmt
            t = tokens.getNext();
            if (t.getTokenType() == TokenType.ELSETK) {
                nodes.add(t);
                nodes.add(parseStmt(tokens.getNext())); // Stmt
            } else {
                tokens.backLast();
            }
        } else if (token.getTokenType() == TokenType.FORTK) {
            nodes.add(token);
            nodes.add(tokens.getNext()); // '('
            Token t = tokens.getNext();
            if (t.getTokenType() != TokenType.SEMICN) {
                nodes.add(parseForStmt(t));
                nodes.add(tokens.getNext()); // ';'
            } else {
                nodes.add(t);
            }
            t = tokens.getNext();
            if (t.getTokenType() != TokenType.SEMICN) {
                nodes.add(parseCond(t));
                nodes.add(tokens.getNext()); // ';'
            }
            else {
                nodes.add(t);
            }
            t = tokens.getNext();
            if (t.getTokenType() != TokenType.RPARENT) {
                nodes.add(parseForStmt(t));
                nodes.add(tokens.getNext()); // ')'
            } else {
                nodes.add(t);
            }
            nodes.add(parseStmt(tokens.getNext()));
        }
        else if (token.getTokenType() == TokenType.BREAKTK ||token.getTokenType() == TokenType.CONTINUETK ) {
            nodes.add(token);
            Token t = tokens.getNext();
            if (t.getTokenType() != TokenType.SEMICN) {
                tokens.backLast();
                tokenErrors.add(new tokenError(getErrorLine('i',nodes),"i"));
            } else {
                nodes.add(t); //';'
            }
            //nodes.add(tokens.getNext());
        } else if (token.getTokenType() == TokenType.PRINTFTK) {
            nodes.add(token);
            nodes.add(tokens.getNext());
            nodes.add(tokens.getNext());
            Token t = tokens.getNext();
            while (t.getTokenType() == TokenType.COMMA) {
                nodes.add(t);
                nodes.add(parseExp(tokens.getNext()));
                t = tokens.getNext();
            }
            //t = tokens.getNext();
            if (t.getTokenType() != TokenType.RPARENT) {
                tokens.backLast();
                tokenErrors.add(new tokenError(getErrorLine('j',nodes),"j"));
            } else {
                nodes.add(t); //')'
            }

            t = tokens.getNext();
            if (t.getTokenType() != TokenType.SEMICN) {
                tokens.backLast();
                tokenErrors.add(new tokenError(getErrorLine('i',nodes),"i"));
            } else {
                nodes.add(t); //';'
            }
        } else if (token.getTokenType() == TokenType.RETURNTK) {
            nodes.add(token);
            Token t = tokens.getNext();
            if (isExp(t)) {
                nodes.add(parseExp(t));
                t = tokens.getNext();
            }
            if (t.getTokenType() != TokenType.SEMICN) {
                tokens.backLast();
                tokenErrors.add(new tokenError(getErrorLine('i',nodes),"i"));
            } else {
                nodes.add(t); //';'
            }
        }
        return new StmtNode(nodes);
    }

    public boolean isLValBegin(Token token) {
        int index = tokens.getIndex();
        Token t = tokens.getNext();
        int check = 0;
        while (t.getTokenType() != TokenType.ASSIGN) {
            if (t.getTokenType() == TokenType.SEMICN) {
                tokens.setIndex(index);
                return false;
            }
            if (t.getTokenType() == TokenType.LBRACK ){
                check = 1;
            }

            if (t.getTokenType() != TokenType.LBRACK && t.getTokenType() != TokenType.RBRACK && check == 0) {
                tokens.setIndex(index);
                return false;
            }
            if (t.getTokenType() == TokenType.RBRACK ){
                check = 0;
            }
            t = tokens.getNext();
        }
        tokens.setIndex(index);
        return true;
    }


    public TreeNode parseCond(Token token) {
        return new CondNode((LOrExpNode) parseLOrExp(token));
    }

    public TreeNode parseForStmt(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseLVal(token));
        nodes.add(tokens.getNext()); // '='
        nodes.add(parseExp(tokens.getNext())); // Exp
        return new ForStmtNode(nodes);
    }

    public TreeNode parseLOrExp(Token token) {
        //改写为 LOrExp -> LAndExp {'||' LAndExp}
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseLAndExp(token));
        Token t = tokens.getNext();
        while (t.getTokenType() == TokenType.OR) {
            nodes.add(t);
            nodes.add(parseLAndExp(tokens.getNext()));
            t = tokens.getNext();
        }
        tokens.backLast();
        return new LOrExpNode(nodes);
    }

    public TreeNode parseLAndExp(Token token) {
        //改写为 LAndExp -> EqExp { '&&' EqExp}
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseEqExp(token));
        Token t = tokens.getNext();
        while (t.getTokenType() == TokenType.AND) {
            nodes.add(t);
            nodes.add(parseEqExp(tokens.getNext()));
            t = tokens.getNext();
        }
        tokens.backLast();
        return new LAndExpNode(nodes);
    }

    public TreeNode parseEqExp(Token token) {
        // 改写为 EqExp -> RelExp {('==' | '!=') RelExp}
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseRelExp(token));
        Token t = tokens.getNext();
        while (t.getTokenType() == TokenType.NEQ || t.getTokenType() == TokenType.EQL) {
            nodes.add(t);
            nodes.add(parseRelExp(tokens.getNext()));
            t = tokens.getNext();
        }
        tokens.backLast();
        return new EqExpNode(nodes);
    }

    public TreeNode parseRelExp(Token token) {
        // 改写为 RelExp -> AddExp {('<' | '>' | '<=' | '>=') AddExp}
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseAddExp(token));
        Token t = tokens.getNext();
        while (t.getTokenType() == TokenType.GRE ||t.getTokenType() == TokenType.LSS || t.getTokenType() == TokenType.LEQ || t.getTokenType() == TokenType.GEQ) {
            nodes.add(t);
            nodes.add(parseAddExp(tokens.getNext()));
            t = tokens.getNext();
        }
        tokens.backLast();
        return new RelExpNode(nodes);
    }

    public TreeNode parseFuncType(Token token) {
        if (token.getTokenType() == TokenType.VOIDTK || token.getTokenType() == TokenType.INTTK || token.getTokenType() == TokenType.CHARTK) {
            return new FuncTypeNode(token);
        }
        return null;
    }

    public TreeNode parseDecl(Token token) {
        if (token.getTokenType() == TokenType.CONSTTK) {
            return new DeclNode(parseConstDecl(token));
        } else {
            return new DeclNode(parseVarDecl(token));
        }
    }



    public TreeNode parseConstDecl(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(token);
        nodes.add(parseBType(tokens.getNext()));
        nodes.add(parseConstDef(tokens.getNext()));
        Token t = tokens.getNext();
        while (t.getTokenType() == TokenType.COMMA) {
            nodes.add(t);
            nodes.add(parseConstDef(tokens.getNext()));
            t = tokens.getNext();
        }
        if (t.getTokenType() != TokenType.SEMICN) {
            tokens.backLast();
            ConstDeclNode result = new ConstDeclNode(nodes);
            tokenError tokenError = new tokenError(getErrorLine('i',nodes),"i");
            tokenErrors.add(tokenError);
            return result;
        } else {
            nodes.add(t);
        }
        return new ConstDeclNode(nodes);
    }

    public ArrayList<tokenError> getTokenErrors() {
        return tokenErrors;
    }

    public TreeNode parseConstDef(Token token) {

        ArrayList<TreeNode> nodes = new ArrayList<>();
        if (token.getTokenType() == TokenType.IDENFR) {
            nodes.add(token);
            Token t = tokens.getNext();
            if (t.getTokenType() == TokenType.LBRACK) {
                nodes.add(t);
                nodes.add(parseConstExp(tokens.getNext()));
                t = tokens.getNext();
                if (t.getTokenType() != TokenType.RBRACK) {
                    tokens.backLast();
                    tokenErrors.add(new tokenError(getErrorLine('k',nodes),"k"));
                } else {
                    nodes.add(t); //右中括号
                }

                t = tokens.getNext();
            }
            nodes.add(t);
            nodes.add(parseConstInitVal(tokens.getNext()));
        } else {
            return null;
        }
        return new ConstDefNode(nodes);
    }

    public int getErrorLine(char type,ArrayList<TreeNode> nodes) {
        switch (type){
            case 'i':
                return nodes.get(nodes.size() - 1).getLine();
            case 'k':
                return nodes.get(nodes.size() - 1).getLine();
            case 'j':
                return nodes.get(nodes.size() - 1).getLine();
            default:
                break;
        }
        return 0;
    }

    public TreeNode parseConstInitVal(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        if (token.getTokenType() == TokenType.STRCON) {
            nodes.add(token);
        }
        else if (token.getTokenType() == TokenType.LBRACE) {
            nodes.add(token);
            Token t  = tokens.getNext();
            if (t.getTokenType() != TokenType.RBRACE) {
                nodes.add(parseConstExp(t));
                t = tokens.getNext();
                while (t.getTokenType() == TokenType.COMMA) {
                    nodes.add(t);
                    nodes.add(parseConstExp(tokens.getNext()));
                    t = tokens.getNext();
                }
            }
            nodes.add(t);
        }
        else {
            nodes.add(parseConstExp(token));
        }
        return new ConstInitValNode(nodes);
    }

    public TreeNode parseVarDecl(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseBType(token));
        nodes.add(parseVarDef(tokens.getNext()));
        Token t = tokens.getNext();
        while (t.getTokenType() == TokenType.COMMA) {
            nodes.add(t);
            nodes.add(parseVarDef(tokens.getNext()));
            t = tokens.getNext();
        }
        if (t.getTokenType() != TokenType.SEMICN) {
            tokens.backLast();
            tokenErrors.add(new tokenError(getErrorLine('i',nodes),"i"));
        } else {
            nodes.add(t); //';'
        }
        return new VarDeclNode(nodes);

    }

    public TreeNode parseBType(Token token) {
        //Token token = tokens.getNext();
        if (token.getTokenType() == TokenType.INTTK  || token.getTokenType() == TokenType.CHARTK) {
            return new BTypeNode(token);
        }
        return null;
    }

    public TreeNode parseVarDef(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        if (token.getTokenType() == TokenType.IDENFR) {
            nodes.add(token);
            Token t = tokens.getNext();
            if (t.getTokenType() == TokenType.LBRACK) {
                nodes.add(t);
                nodes.add(parseConstExp(tokens.getNext()));
                t = tokens.getNext();
                if (t.getTokenType() != TokenType.RBRACK) {
                    tokens.backLast();
                    tokenErrors.add(new tokenError(getErrorLine('k',nodes),"k"));
                } else {
                    nodes.add(t);
                }
                t = tokens.getNext();
            }
            if (t.getTokenType() == TokenType.ASSIGN) {
                nodes.add(t);
                nodes.add(parseInitVal(tokens.getNext()));
                t = tokens.getNext();
            }
            tokens.backLast();
            return new VarDefNode(nodes);
        }
        else {
            return null;
        }
    }

    public TreeNode parseInitVal(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        if (token.getTokenType() == TokenType.STRCON) {
            nodes.add(token);
        } else if (token.getTokenType() == TokenType.LBRACE ){
            nodes.add(token);
            Token t = tokens.getNext();
            if (t.getTokenType() != TokenType.RBRACE) {
                nodes.add(parseExp(t));
                t = tokens.getNext();
                while (t.getTokenType() == TokenType.COMMA) {
                    nodes.add(t);
                    nodes.add(parseExp(tokens.getNext()));
                    t = tokens.getNext();
                }
            }
            nodes.add(t);
        } else {
            nodes.add(parseExp(token));
        }
        return new InitValNode(nodes);
    }

    public TreeNode parseConstExp(Token token) {
        return new ConstExpNode((AddExpNode) parseAddExp(token));
    }

    public TreeNode parseAddExp(Token token) {
        // 消除左递归 AddExp -> MulExp { ('+' | '-')  MulExp}
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseMulExp(token));
        Token t = tokens.getNext();
        while (t.getTokenType() == TokenType.PLUS || t.getTokenType() == TokenType.MINU) {
            nodes.add(t);
            nodes.add(parseMulExp(tokens.getNext()));
            t = tokens.getNext();
        }
        tokens.backLast();
        return new AddExpNode(nodes);

    }

    public TreeNode parseMulExp(Token token) {
        // 消除左递归 MulExp -> UnaryExp { ('*' | '/' | '%' ) UnaryExp }
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseUnaryExp(token));
        Token t = tokens.getNext();
        while (t.getTokenType() == TokenType.MULT || t.getTokenType() == TokenType.DIV || t.getTokenType() == TokenType.MOD) {
            nodes.add(t);
            nodes.add(parseUnaryExp(tokens.getNext()));
            t = tokens.getNext();
        }
        tokens.backLast();
        return new MulExpNode(nodes);
    }

    public TreeNode parseUnaryExp(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        if (token.getTokenType() == TokenType.LPARENT || token.getTokenType() == TokenType.CHRCON||token.getTokenType() == TokenType.INTCON) {
            nodes.add(parsePrimaryExp(token));
            return new UnaryExpNode(nodes);
        }
        else if (token.getTokenType() == TokenType.IDENFR) {
            Token t =  tokens.getNext();
            if (t.getTokenType() == TokenType.LPARENT) {
                tokens.backLast();
                nodes.add(token);
                t = tokens.getNext();
                if (t.getTokenType() == TokenType.LPARENT) {
                    nodes.add(t);
                    t = tokens.getNext();
                    if (t.getTokenType() == TokenType.LPARENT || t.getTokenType() == TokenType.IDENFR || t.getTokenType() == TokenType.PLUS || t.getTokenType() == TokenType.MINU || t.getTokenType() == TokenType.NOT || t.getTokenType() == TokenType.INTCON || t.getTokenType() == TokenType.CHRCON) {
                        nodes.add(parseFuncRParams(t));
                        t = tokens.getNext();
                    }
                    if (t.getTokenType() != TokenType.RPARENT) {
                        tokens.backLast();
                        tokenErrors.add(new tokenError(getErrorLine('j',nodes),"j"));
                    } else {
                        nodes.add(t);
                    }
                    return new UnaryExpNode(nodes);
                }
            }
            else {
                tokens.backLast();
                nodes.add(parsePrimaryExp(token));
                return new UnaryExpNode(nodes);
            }
        } else {
            nodes.add(parseUnaryOp(token));
            nodes.add(parseUnaryExp(tokens.getNext()));
            return new UnaryExpNode(nodes);
        }
        return null;
    }

    public TreeNode parseFuncRParams(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseExp(token));
        Token t = tokens.getNext();
        while (t.getTokenType() == TokenType.COMMA) {
            nodes.add(t);
            nodes.add(parseExp(tokens.getNext()));
            t = tokens.getNext();
        }
        tokens.backLast();
        return new FuncRParamsNode(nodes);
    }

    public TreeNode parsePrimaryExp(Token token) {
        ArrayList<TreeNode> list = new ArrayList<>();
        if (token.getTokenType() == TokenType.LPARENT) {
            list.add(token);
            list.add(parseExp(tokens.getNext()));
            Token token1 = tokens.getNext();
            if (token1.getTokenType() == TokenType.RPARENT) {
                list.add(token1);
            } else {
                tokens.backLast();
                tokenErrors.add(new tokenError(getErrorLine('j',list),"j"));
            }
            return new PrimaryExpNode(list);
        } else if (token.getTokenType() == TokenType.IDENFR) {
            list.add(parseLVal(token));
            return new PrimaryExpNode(list);
        } else if (token.getTokenType() == TokenType.INTCON) {
            list.add(parseNumber(token));
            return new PrimaryExpNode(list);
        } else {
            list.add(parseCharacter(token));
            return new PrimaryExpNode(list);
        }
    }

    public TreeNode parseExp(Token token) {
        return new ExpNode((AddExpNode) parseAddExp(token));
    }

    public TreeNode parseLVal(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        if (token.getTokenType() == TokenType.IDENFR) {
            nodes.add(token);
            Token t = tokens.getNext();
            if (t.getTokenType() == TokenType.LBRACK) {
                nodes.add(t);
                nodes.add(parseExp(tokens.getNext()));
                t = tokens.getNext();
                if (t.getTokenType() == TokenType.RBRACK) {
                    nodes.add(t);
                    return new LValNode(nodes);
                } else {
                    tokens.backLast();
                    tokenErrors.add(new tokenError(getErrorLine('k',nodes),"k"));
                    return new LValNode(nodes);
                }
            } else {
                tokens.backLast();
                return new LValNode(nodes);
            }
        }
        return null;
    }

    public TreeNode parseNumber(Token token) {
        if (token.getTokenType() == TokenType.INTCON) {
            return new NumberNode(token);
        }
        return null;
    }

    public TreeNode parseCharacter(Token token) {
        if (token.getTokenType() == TokenType.CHRCON) {
            return new CharacterNode(token);
        }
        return null;
    }

    public TreeNode parseFuncFParams(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseFuncFParam(token));
        Token t = tokens.getNext();
        while (t.getTokenType() == TokenType.COMMA) {
            nodes.add(t);
            nodes.add(parseFuncFParam(tokens.getNext()));
            t = tokens.getNext();
        }
        tokens.backLast();
        return new FuncFParamsNode(nodes);
    }

    public TreeNode parseFuncFParam(Token token) {
        ArrayList<TreeNode> nodes = new ArrayList<>();
        nodes.add(parseBType(token));
        nodes.add(tokens.getNext());
        Token token1 = tokens.getNext();
        if (token1.getTokenType() == TokenType.LBRACK) {
            nodes.add(token1);
            Token t = tokens.getNext();
            if (t.getTokenType() != TokenType.RBRACK) {
                tokens.backLast();
                tokenErrors.add(new tokenError(getErrorLine('k',nodes),"k"));
            } else {
                nodes.add(t);
            }

        } else {
            tokens.backLast();
        }
        return new FuncFParamNode(nodes);
    }

    public TreeNode parseUnaryOp(Token token) {
        if (token.getTokenType() == TokenType.PLUS || token.getTokenType() == TokenType.MINU || token.getTokenType() == TokenType.NOT) {
            return new UnaryOpNode(token);
        }
        return null;
    }




}
