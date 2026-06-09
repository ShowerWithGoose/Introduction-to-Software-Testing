package front_end.parser;

import exception.CompilerError;
import exception.ErrorTackle;
import exception.Exception;
import front_end.ast.ASTNode;
import front_end.ast.NodeType;
import front_end.lexer.Lexer;
import front_end.lexer.Token;
import front_end.lexer.TokenType;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Parser {
    private final List<Token> tokens;
    private final List<Token> tokensCopy;
    private int current;

    public Parser(Lexer lexer) {
        this.tokens = lexer.getTokens();
        this.tokensCopy = new ArrayList<>();
        for (Token token : tokens) {
            tokensCopy.add(new Token(token.getType(), token.getValue()));
        }
        this.current = 0;
    }

    // 入口方法，解析编译单元
    public ASTNode parseCompUnit()  {
        ArrayList<Object> decls = new ArrayList<>();
        while ((peek(TokenType.CONSTTK) || peek(TokenType.INTTK) || peek(TokenType.CHARTK))
                && peekNext().getType() != TokenType.MAINTK
                && peekAt(current+2).getType() != TokenType.LPARENT) {
            decls.add(parseDecl());
        }
        while (isFuncDefStart()) {
            decls.add(parseFuncDef());
        }
        decls.add(parseMainFuncDef());
        ASTNode compUnit = new ASTNode(NodeType.CompUnit,decls);
        expect(TokenType.EOF);
        return compUnit;
    }

    // 检查是否是函数定义的开始
    private boolean isFuncDefStart() {
        TokenType type = peekType();
        return (type == TokenType.VOIDTK || type == TokenType.INTTK || type == TokenType.CHARTK) && Objects.requireNonNull(peekNext()).getType() == TokenType.IDENFR;
    }

    // 解析声明
    private ASTNode parseDecl()  {
        if (peek(TokenType.CONSTTK)) {
            return parseConstDecl();
        } else {
            return parseVarDecl();
        }
    }

    // 解析常量声明
    private ASTNode parseConstDecl()  {
        expect(TokenType.CONSTTK);
        ArrayList<Object> nodes = new ArrayList<>();
        nodes.add(TokenType.CONSTTK);
        nodes.add(parseBType());
        do {
            nodes.add(parseConstDef());
            nodes.add(TokenType.COMMA);
        } while (match(TokenType.COMMA));
        nodes.remove(nodes.size() - 1);
        ASTNode constDecl = new ASTNode(NodeType.ConstDecl, nodes);
        expect(TokenType.SEMICN);
        nodes.add(TokenType.SEMICN);
        return constDecl;
    }

    // 解析变量声明
    private ASTNode parseVarDecl()  {
        ArrayList<Object> nodes = new ArrayList<>();
        nodes.add(parseBType());
        do {
            nodes.add(parseVarDef());
            nodes.add(TokenType.COMMA);
        } while (match(TokenType.COMMA));
        nodes.remove(nodes.size() - 1);
        expect(TokenType.SEMICN);
        nodes.add(TokenType.SEMICN);
        return new ASTNode(NodeType.VarDecl, nodes);
    }

    // 解析基本类型
    private TokenType parseBType()  {
        if (peek(TokenType.INTTK) || peek(TokenType.CHARTK)) {
            TokenType type = peekType();
            advance();
            return type;
        }
        return peekType();
        //throw error("Expected basic type 'int' or 'char'");
    }

    // 解析常量定义
    private ASTNode parseConstDef()  {
        String ident = peekNow().toString();
        expect(TokenType.IDENFR);
        ArrayList<Object> nodes = new ArrayList<>();
        nodes.add(new ASTNode(TokenType.IDENFR,ident));
        if (match(TokenType.LBRACK)) {
            nodes.add(TokenType.LBRACK);
            nodes.add(parseConstExp());
            expect(TokenType.RBRACK);
            nodes.add(TokenType.RBRACK);
        }
        expect(TokenType.ASSIGN);
        nodes.add(TokenType.ASSIGN);
        nodes.add(parseConstInitVal());
        return new ASTNode(NodeType.ConstDef,nodes);
    }

    // 解析常量初值
    private ASTNode parseConstInitVal()  {
        if (peek(TokenType.LBRACE)) {
            match(TokenType.LBRACE);
            ArrayList<Object> constExps = new ArrayList<>();
            constExps.add(TokenType.LBRACE);
            if (!peek(TokenType.RBRACE)) {
                do {
                    constExps.add(parseConstExp());
                    constExps.add(TokenType.COMMA);
                } while (match(TokenType.COMMA));
                constExps.remove(constExps.size()-1);
            }
            expect(TokenType.RBRACE);
            constExps.add(TokenType.RBRACE);
            return new ASTNode(NodeType.ConstInitVal, constExps);
        } else if (peek(TokenType.STRCON)) {
            Token token = peekNow();
            match(TokenType.STRCON);
            return new ASTNode(NodeType.ConstInitVal, new ASTNode(TokenType.STRCON,token.toString()));
        } else {
            return new ASTNode(NodeType.ConstInitVal, parseConstExp());
        }
    }

    // 解析变量定义
    private ASTNode parseVarDef()  {
        String ident = peekNow().toString();
        ArrayList<Object> nodes = new ArrayList<>();
        nodes.add(new ASTNode(TokenType.IDENFR,ident));
        expect(TokenType.IDENFR);
        if (match(TokenType.LBRACK)) {
            nodes.add(TokenType.LBRACK);
            nodes.add(parseConstExp());
            expect(TokenType.RBRACK);
            nodes.add(TokenType.RBRACK);
        }
        if (match(TokenType.ASSIGN)) {
            nodes.add(TokenType.ASSIGN);
            nodes.add(parseInitVal());
        }
        return new ASTNode(NodeType.VarDef, nodes);
    }

    // 解析变量初值
    private ASTNode parseInitVal()  {
        if (peek(TokenType.LBRACE)) {
            match(TokenType.LBRACE);
            ArrayList<Object> exps = new ArrayList<>();
            exps.add(TokenType.LBRACE);
            if (!peek(TokenType.RBRACE)) {
                do {
                    exps.add(parseExp());
                    exps.add(TokenType.COMMA);
                } while (match(TokenType.COMMA));
                exps.remove(exps.size()-1);
            }
            ASTNode initVal = new ASTNode(NodeType.InitVal, exps);
            expect(TokenType.RBRACE);
            exps.add(TokenType.RBRACE);
            return initVal;
        } else if (peek(TokenType.STRCON)) {
            Token token = peekNow();
            match(TokenType.STRCON);
            return new ASTNode(NodeType.InitVal, new ASTNode(TokenType.STRCON,token.toString()));
        } else {
            ASTNode exp = parseExp();
            return new ASTNode(NodeType.InitVal, exp);
        }
    }

    // 解析函数定义
    private ASTNode parseFuncDef()  {
        ArrayList<Object> nodes = new ArrayList<>();
        TokenType funcType = parseFuncType();
        nodes.add(new ASTNode(NodeType.FuncType,List.of(funcType)));
        nodes.add(new ASTNode(TokenType.IDENFR, peekNow().toString()));
        expect(TokenType.IDENFR);
        expect(TokenType.LPARENT);
        nodes.add(TokenType.LPARENT);
        if (!peek(TokenType.RPARENT)) {
            nodes.add(parseFuncFParams());
        }
        nodes.add(TokenType.RPARENT);
        expect(TokenType.RPARENT);
        ASTNode block = parseBlock();
        nodes.add(block);
        return new ASTNode(NodeType.FuncDef, nodes);
    }

    // 解析主函数定义
    private ASTNode parseMainFuncDef()  {
        ArrayList<Object> nodes = new ArrayList<>();
        expect(TokenType.INTTK);
        expect(TokenType.MAINTK);
        expect(TokenType.LPARENT);
        expect(TokenType.RPARENT);
        nodes.add(TokenType.INTTK);
        nodes.add(TokenType.MAINTK);
        nodes.add(TokenType.LPARENT);
        nodes.add(TokenType.RPARENT);
        nodes.add(parseBlock());
        return new ASTNode(NodeType.MainFuncDef,nodes);
    }

    // 解析函数类型
    private TokenType parseFuncType()  {
        if (peek(TokenType.VOIDTK) || peek(TokenType.INTTK) || peek(TokenType.CHARTK)) {
            TokenType type = peekType();
            advance();
            return type;
        }
        return peekType();
//        return null;
        //throw error("Expected function type 'void', 'int' or 'char'");
    }

    // 解析函数形参表
    private ASTNode parseFuncFParams()  {
        ArrayList<Object> funcFParams = new ArrayList<>();
        do {
            funcFParams.add(parseFuncFParam());
            funcFParams.add(TokenType.COMMA);
        } while (match(TokenType.COMMA));
        funcFParams.remove(funcFParams.size()-1);
        return new ASTNode(NodeType.FuncFParams,funcFParams);
    }

    // 解析函数形参
    private ASTNode parseFuncFParam()  {
        ArrayList<Object> nodes = new ArrayList<>();
        Object nodeType = parseBType();
        nodes.add(nodeType);
        nodes.add(new ASTNode(TokenType.IDENFR,peekNow().toString()));
        boolean isArr = false;
        expect(TokenType.IDENFR);
        if (match(TokenType.LBRACK)) {
            nodes.add(TokenType.LBRACK);
            isArr = true;
            expect(TokenType.RBRACK);
            nodes.add(TokenType.RBRACK);
        }
        return new ASTNode(NodeType.FuncFParam,isArr,nodes);
    }

    // 解析语句块
    private ASTNode parseBlock()  {
        expect(TokenType.LBRACE);
        ArrayList<Object> blockItems = new ArrayList<>();
        blockItems.add(TokenType.LBRACE);
        while (!peek(TokenType.RBRACE)) {
            blockItems.add(parseBlockItem());
        }
        expect(TokenType.RBRACE);
        blockItems.add(TokenType.RBRACE);
        return new ASTNode(NodeType.Block,blockItems);
    }

    // 解析语句块项
    private  ASTNode parseBlockItem()  {
        if (peek(TokenType.CONSTTK) || peek(TokenType.INTTK) || peek(TokenType.CHARTK)) {
            ASTNode decl = parseDecl();
            return new ASTNode(NodeType.BlockItem,decl);
        } else {
            Object stmt = parseStmt();
            return new ASTNode(NodeType.BlockItem,new ArrayList<>(List.of(stmt)));
        }
    }

    // 解析语句
    private Object parseStmt()  {
        TokenType type = peekType();
        ArrayList<Object> nodes = new ArrayList<>();
        switch (type) {
            case IDENFR:
                int index = current;
                nodes.add(parseLVal());
                if (peek(TokenType.ASSIGN)) {
                    expect(TokenType.ASSIGN);
                    nodes.add(TokenType.ASSIGN);
                    if (peek(TokenType.GETINTTK) || peek(TokenType.GETCHARTK)) {
                        if (match(TokenType.GETINTTK)) {
                            expect(TokenType.LPARENT);
                            expect(TokenType.RPARENT);
                            nodes.addAll(List.of(TokenType.GETINTTK,TokenType.LPARENT,TokenType.RPARENT));
                        } else if (match(TokenType.GETCHARTK)) {
                            expect(TokenType.LPARENT);
                            expect(TokenType.RPARENT);
                            nodes.addAll(List.of(TokenType.GETCHARTK,TokenType.LPARENT,TokenType.RPARENT));
                        }
                    } else {
                        nodes.add(parseExp());
                    }
                    expect(TokenType.SEMICN);
                    nodes.add(TokenType.SEMICN);
                    return new ASTNode(NodeType.Stmt,nodes);
                }
                else {
                    peekReset(index);
                    ASTNode exprStmt = new ASTNode(NodeType.Stmt,List.of(parseExp(),TokenType.SEMICN));
                    expect(TokenType.SEMICN);
                    return exprStmt;
                }
            case SEMICN:
                match(TokenType.SEMICN);
                return new ASTNode(NodeType.Stmt,List.of(TokenType.SEMICN));
            case LBRACE:
                nodes = new ArrayList<>();
                nodes.add(parseBlock());
                return new ASTNode(NodeType.Stmt,nodes);
            case IFTK:
                nodes = new ArrayList<>();
                nodes.add(TokenType.IFTK);
                match(TokenType.IFTK);
                nodes.add(TokenType.LPARENT);
                expect(TokenType.LPARENT);
                nodes.add(parseCond());
                expect(TokenType.RPARENT);
                nodes.add(TokenType.RPARENT);
                nodes.add(parseStmt());
                if (match(TokenType.ELSETK)) {
                    nodes.add(TokenType.ELSETK);
                    nodes.add(parseStmt());
                }
                return new ASTNode(NodeType.Stmt,nodes);
            case FORTK:
                nodes = new ArrayList<>();
                match(TokenType.FORTK);
                expect(TokenType.LPARENT);
                nodes.add(TokenType.FORTK);
                nodes.add(TokenType.LPARENT);
                // 解析 for 的三个部分
                // ForStmt ; ASTNode ; ForStmt
                if (!peek(TokenType.SEMICN)) {
                    nodes.add(parseForStmt());
                }
                nodes.add(TokenType.SEMICN);
                expect(TokenType.SEMICN);
                if (!peek(TokenType.SEMICN)) {
                    nodes.add(parseCond());
                }
                nodes.add(TokenType.SEMICN);
                expect(TokenType.SEMICN);
                if (!peek(TokenType.RPARENT)) {
                    nodes.add(parseForStmt());
                }
                nodes.add(TokenType.RPARENT);
                expect(TokenType.RPARENT);
                nodes.add(parseStmt());
                return new ASTNode(NodeType.Stmt,nodes);
            case BREAKTK:
                match(TokenType.BREAKTK);
                expect(TokenType.SEMICN);
                return new ASTNode(NodeType.Stmt,List.of(TokenType.BREAKTK,TokenType.SEMICN));
            case CONTINUETK:
                match(TokenType.CONTINUETK);
                expect(TokenType.SEMICN);
                return new ASTNode(NodeType.Stmt,List.of(TokenType.CONTINUETK,TokenType.SEMICN));
            case RETURNTK:
                match(TokenType.RETURNTK);
                ArrayList<Object> expReturn = new ArrayList<>();
                expReturn.add(TokenType.RETURNTK);
                if (!peek(TokenType.SEMICN)) {
                    expReturn.add(parseExp());
                }
                expReturn.add(TokenType.SEMICN);
                expect(TokenType.SEMICN);
                return new ASTNode(NodeType.Stmt,expReturn);
            case PRINTFTK:
                ArrayList<Object> exps = new ArrayList<>();
                match(TokenType.PRINTFTK);
                expect(TokenType.LPARENT);
                exps.add(TokenType.PRINTFTK);
                exps.add(TokenType.LPARENT);
                exps.add(new ASTNode(TokenType.STRCON, peekNow().toString()));
                expect(TokenType.STRCON);
                while (match(TokenType.COMMA)) {
                    exps.add(TokenType.COMMA);
                    exps.add(parseExp());
                }
                expect(TokenType.RPARENT);
                expect(TokenType.SEMICN);
                exps.add(TokenType.RPARENT);
                exps.add(TokenType.SEMICN);
                return new ASTNode(NodeType.Stmt,exps);
            default:
                ASTNode exprStmt = new ASTNode(NodeType.Stmt,List.of(parseExp(),TokenType.SEMICN));
                expect(TokenType.SEMICN);
                return exprStmt;
                //throw error("Unexpected statement start: " + type);
        }
    }

    // 解析 for 语句头

    // 解析 for 语句中的 ForStmt
    private ASTNode parseForStmt()  {
        ASTNode lVal = parseLVal();
        expect(TokenType.ASSIGN);
        ASTNode exp = parseExp();
        return new ASTNode(NodeType.ForStmt,new ArrayList<>(List.of(lVal,TokenType.ASSIGN,exp)));
    }

    // 解析 getint/getchar 赋值语句

    // 解析表达式
    private ASTNode parseExp()  {
        return new ASTNode(NodeType.Exp,parseAddExp());
    }

    // 解析条件表达式
    private ASTNode parseCond()  {
        return new ASTNode(NodeType.Cond,parseLOrExp());
    }

    // 解析左值表达式
    private ASTNode parseLVal()  {
        ArrayList<Object> nodes = new ArrayList<>();
        nodes.add(new ASTNode(TokenType.IDENFR,peekNow().toString()));
        expect(TokenType.IDENFR);
        if (match(TokenType.LBRACK)) {
            nodes.add(TokenType.LBRACK);
            nodes.add(parseExp());
            expect(TokenType.RBRACK);
            nodes.add(TokenType.RBRACK);
        }
        return new ASTNode(NodeType.LVal,nodes);
    }

    // 解析加减表达式
    private ASTNode parseAddExp()  {
        int index1=current;
        ASTNode mulExp = parseMulExp();
        if (peek(TokenType.PLUS) || peek(TokenType.MINU)) {
            int index2 = current;
            TokenType addOp = peek(TokenType.PLUS) ? TokenType.PLUS : TokenType.MINU;
            while(peek(TokenType.PLUS) || peek(TokenType.MINU))
            {
                index2 = current;
                addOp = peek(TokenType.PLUS) ? TokenType.PLUS : TokenType.MINU;
                advance();
                parseMulExp();
            }
            peekReset(index1);
            peekDisable(index2);
            ASTNode addExp = parseAddExp();
            peekEnable(index2);
            advance();
            ASTNode mulExpTemp = parseMulExp();
            return new ASTNode(NodeType.AddExp,new ArrayList<>(List.of(addExp, addOp, mulExpTemp)));
        }
        else {
            return new ASTNode(NodeType.AddExp,new ArrayList<>(List.of(mulExp)));
        }
    }

    // 解析乘除模表达式
    private ASTNode parseMulExp()  {
        int index1 = current;
        ASTNode unaryExp = parseUnaryExp();
        if (peek(TokenType.MULT) || peek(TokenType.DIV) || peek(TokenType.MOD)) {
            int index2 = current;
            TokenType mulOp = peek(TokenType.MULT) ? TokenType.MULT :
                    peek(TokenType.DIV) ? TokenType.DIV : TokenType.MOD;
            while(peek(TokenType.MULT) || peek(TokenType.DIV) || peek(TokenType.MOD))
            {
                index2 = current;
                mulOp = peek(TokenType.MULT) ? TokenType.MULT :
                        peek(TokenType.DIV) ? TokenType.DIV : TokenType.MOD;
                advance();
                parseUnaryExp();
            }
            peekReset(index1);
            peekDisable(index2);
            ASTNode mulExp = parseMulExp();
            peekEnable(index2);
            advance();
            ASTNode unaryExpTemp = parseUnaryExp();
            return new ASTNode(NodeType.MulExp,new ArrayList<>(List.of(mulExp, mulOp, unaryExpTemp)));
        }
        else {
            return new ASTNode(NodeType.MulExp,new ArrayList<>(List.of(unaryExp)));
        }
    }

    // 解析一元表达式
    private ASTNode parseUnaryExp()  {
        if (peek(TokenType.IDENFR)) {
            Token ident = peekNow();
            Token next = peekNext();
            if (next != null && next.getType() == TokenType.LPARENT) {
                // 函数调用
                match(TokenType.IDENFR);
                ArrayList<Object> args = new ArrayList<>();
                expect(TokenType.LPARENT);
                args.add(new ASTNode(TokenType.IDENFR,ident.toString()));
                args.add(TokenType.LPARENT);
                if (!peek(TokenType.RPARENT)) {
                    args.add(parseFuncRParams());
                }
                expect(TokenType.RPARENT);
                args.add(TokenType.RPARENT);
                return new ASTNode(NodeType.UnaryExp,args);
            } else {
                ASTNode primaryExp = parsePrimaryExp();
                return new ASTNode(NodeType.UnaryExp,new ArrayList<>(List.of(primaryExp)));
            }
        } else if (peek(TokenType.PLUS) || peek(TokenType.MINU) || peek(TokenType.NOT)) {
            Object op = parseUnaryOp();
            ASTNode exp = parseUnaryExp();
            return new ASTNode(NodeType.UnaryExp,new ArrayList<>(List.of(op,exp)));
        } else {
            ASTNode primaryExp = parsePrimaryExp();
            return new ASTNode(NodeType.UnaryExp,new ArrayList<>(List.of(primaryExp)));
        }
    }

    // 解析基本表达式
    private ASTNode parsePrimaryExp()  {
        if (peek(TokenType.LPARENT)) {
            advance();
            ASTNode exp = parseExp();
            expect(TokenType.RPARENT);
            return new ASTNode(NodeType.PrimaryExp,new ArrayList<>(List.of(TokenType.LPARENT,exp,TokenType.RPARENT)));
        } else if (peek(TokenType.IDENFR)) {
            return new ASTNode(NodeType.PrimaryExp,parseLVal());
        } else if (peek(TokenType.INTCON)) {
            ASTNode number = new ASTNode(TokenType.INTCON,peekNow().toString());
            match(TokenType.INTCON);
            return new ASTNode(NodeType.PrimaryExp,new ASTNode(NodeType.Number,number));
        } else if (peek(TokenType.CHRCON)) {
            ASTNode character = new ASTNode(TokenType.CHRCON,peekNow().toString());
            match(TokenType.CHRCON);
            return new ASTNode(NodeType.PrimaryExp, new ASTNode(NodeType.Character,character));
        } else {
            return new ASTNode(TokenType.VOIDTK, "");
//            return null;
            //throw error("Unexpected primary expression: " + peekType());
        }
    }

    // 解析函数实参表
    private ASTNode parseFuncRParams()  {
        ArrayList<Object> args = new ArrayList<>();
        do {
            args.add(parseExp());
            args.add(TokenType.COMMA);
        } while (match(TokenType.COMMA));
        args.remove(args.size()-1);
        return new ASTNode(NodeType.FuncRParams,args);
    }

    // 解析逻辑或表达式
    private ASTNode parseLOrExp()  {
        int index1 = current;
        ASTNode left = parseLAndExp();
        if (peek(TokenType.OR)) {
            int index2 = current;
            ASTNode lAndExpTemp;
            while(peek(TokenType.OR))
            {
                index2 = current;
                advance();
                parseLAndExp();
            }
            peekReset(index1);
            peekDisable(index2);
            ASTNode lOrExp = parseLOrExp();
            peekEnable(index2);
            advance();
            lAndExpTemp = parseLAndExp();
            return new ASTNode(NodeType.LOrExp,new ArrayList<>(List.of(lOrExp, TokenType.OR, lAndExpTemp)));
        }
        return new ASTNode(NodeType.LOrExp,new ArrayList<>(List.of(left)));
    }

    // 解析逻辑与表达式
    private ASTNode parseLAndExp()  {
        int index1 = current;
        ASTNode left = parseEqExp();
        if (peek(TokenType.AND)) {
            int index2 = current;
            ASTNode eqExpTemp = null;
            while(peek(TokenType.AND))
            {
                index2 = current;
                advance();
                eqExpTemp = parseEqExp();
            }
            peekReset(index1);
            peekDisable(index2);
            ASTNode lAndExp = parseLAndExp();
            peekEnable(index2);
            advance();
            eqExpTemp = parseEqExp();
            return new ASTNode(NodeType.LAndExp,new ArrayList<>(List.of(lAndExp, TokenType.AND, eqExpTemp)));
        }
        return new ASTNode(NodeType.LAndExp,new ArrayList<>(List.of(left)));
    }

    // 解析相等性表达式
    private ASTNode parseEqExp()  {
        int index1 = current;
        ASTNode relExp = parseRelExp();
        if (peek(TokenType.EQL) || peek(TokenType.NEQ)) {
            int index2 = current;
            TokenType eqOp = peek(TokenType.EQL) ? TokenType.EQL : TokenType.NEQ;
            ASTNode relExpTemp = null;
            while(peek(TokenType.EQL) || peek(TokenType.NEQ))
            {
                index2 = current;
                eqOp = peek(TokenType.EQL) ? TokenType.EQL : TokenType.NEQ;
                advance();
                parseRelExp();
            }
            peekReset(index1);
            peekDisable(index2);
            ASTNode eqExp = parseEqExp();
            peekEnable(index2);
            advance();
            relExpTemp = parseRelExp();
            return new ASTNode(NodeType.EqExp,new ArrayList<>(List.of(eqExp, eqOp, relExpTemp)));
        }
        return new ASTNode(NodeType.EqExp,new ArrayList<>(List.of(relExp)));
    }

    // 解析关系表达式
    private ASTNode parseRelExp()  {
        int index1 = current;
        ASTNode addExp = parseAddExp();
        if (peek(TokenType.LSS) || peek(TokenType.GRE) ||
                peek(TokenType.LEQ) || peek(TokenType.GEQ)) {
            TokenType relOp = peek(TokenType.LSS) ? TokenType.LSS :
                    peek(TokenType.GRE) ? TokenType.GRE :
                            peek(TokenType.LEQ) ? TokenType.LEQ :
                                    TokenType.GEQ;
            int index2 = current;
            ASTNode addExpTemp;
            while(peek(TokenType.LSS) || peek(TokenType.GRE) ||
                    peek(TokenType.LEQ) || peek(TokenType.GEQ))
            {
                index2 = current;
                relOp = peek(TokenType.LSS) ? TokenType.LSS :
                        peek(TokenType.GRE) ? TokenType.GRE :
                                peek(TokenType.LEQ) ? TokenType.LEQ :
                                        TokenType.GEQ;
                advance();
                parseAddExp();
            }
            peekReset(index1);
            peekDisable(index2);
            ASTNode relExp = parseRelExp();
            peekEnable(index2);
            advance();
            addExpTemp = parseAddExp();
            return new ASTNode(NodeType.RelExp,new ArrayList<>(List.of(relExp, relOp, addExpTemp)));
        }
        return new ASTNode(NodeType.RelExp,new ArrayList<>(List.of(addExp)));
    }

    // 解析一元运算符
    private ASTNode parseUnaryOp()  {
        if (peek(TokenType.PLUS) || peek(TokenType.MINU) || peek(TokenType.NOT)) {
            TokenType type = peekType();
            advance();
            return new ASTNode(NodeType.UnaryOp,List.of(type));
        }
        return new ASTNode(NodeType.UnaryOp,List.of(TokenType.PLUS));
//        return null;
        //throw error("Expected unary operator '+', '-', '!' ");
    }

    // 解析常量表达式
    private ASTNode parseConstExp()  {
        return new ASTNode(NodeType.ConstExp,parseAddExp());
        // 此处可以添加对常量的检查（如变量是否为常量）
    }

    // 辅助方法：检查当前Token是否匹配指定类型
    private boolean match(TokenType type) {
        if (peek(type)) {
            advance();
            return true;
        }
        return false;
    }

    private Token peekNow() {
        if (current < tokens.size()) {
            return tokens.get(current);
        }
        return new Token(TokenType.EOF, "");
    }

    // 辅助方法：期望当前Token匹配指定类型，否则抛出异常
    private boolean expect(TokenType type)  {
        boolean ans = match(type);
        if (!ans && type == TokenType.RPARENT) {
            ErrorTackle.addError(new CompilerError(ErrorTackle.transTokenPosToLine(current-1), "j"));
        }
        if (!ans && type == TokenType.SEMICN) {
            ErrorTackle.addError(new CompilerError(ErrorTackle.transTokenPosToLine(current-1), "i"));
        }
        if (!ans && type == TokenType.RBRACK) {
            ErrorTackle.addError(new CompilerError(ErrorTackle.transTokenPosToLine(current-1), "k"));
        }
        return ans;
        //throw error("Expected token " + type + " but found " + peekType());
    }

    // 查看当前Token类型
    private TokenType peekType() {
        if (current < tokens.size()) {
            return tokens.get(current).getType();
        }
        return TokenType.EOF;
    }

    // 查看下一个Token
    private Token peekNext() {
        if (current + 1 < tokens.size()) {
            return tokens.get(current + 1);
        }
        return tokens.get(tokens.size() - 1);
    }

    private Token peekAt(int index) {
        if (index < tokens.size()) {
            return tokens.get(index);
        }
        return tokens.get(tokens.size() -1);
    }

    // 检查当前Token是否为指定类型
    private boolean peek(TokenType type) {
        return peekType() == type;
    }

    // 让token的索引回到指定位置
    private void peekReset(int index) {
        current = index;
    }

    // 暂时让指定位置的token失效
    private void peekDisable(int index) {
        tokens.get(index).setType(TokenType.EOF);
    }

    // 恢复指定位置的token
    private void peekEnable(int index) {
        TokenType type = tokensCopy.get(index).getType();
        tokens.get(index).setType(type);
    }

    // 消耗当前Token并返回
    private Token advance() {
        if (current < tokens.size()) {
            return tokens.get(current++);
        }
        return tokens.get(tokens.size() - 1);
    }
}