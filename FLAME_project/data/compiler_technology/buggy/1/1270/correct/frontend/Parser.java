package frontend;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
public class Parser {
    private List<Token> tokens;
    private int index = 0;
    private PrintWriter parserOutput;
    private PrintWriter errorOutput;
    public Parser(List<Token> tokens) {
        this.tokens = tokens;
    }
    private Token getCurrentToken() {
        if (index < tokens.size()) {
            return tokens.get(index);
        } else {
            return null;
        }

    }
    private void advance(){
        if(index < tokens.size())
            index++;
    }
    private boolean match(TokenType type){
        if(getCurrentToken() != null && getCurrentToken().getType().equals(type)){
            return true;
        }
        return false;
    }
    private Token lookAhead() {
        int lookaheadIndex = index + 1; // 预查看下一个 Token 的位置
        if (lookaheadIndex < tokens.size()) {
            return tokens.get(lookaheadIndex);
        } else {
            return null; // 如果没有更多的 Token，返回 null
        }
    }
    private Token lookBehind(){
        int lookbehindIndex = index - 1; // 预查看下一个 Token 的位置
        if (lookbehindIndex < tokens.size()) {
            return tokens.get(lookbehindIndex);
        } else {
            return null; // 如果没有更多的 Token，返回 null
        }
    }
    public void parse(String parserOutputFile, String errorOutputFile){
        try{
            parserOutput = new PrintWriter(new FileWriter(parserOutputFile, true), true);
            errorOutput = new PrintWriter(new FileWriter(errorOutputFile, true), true);
            Node root = parseCompUnit();
            root.printTree(root, parserOutput);
            outputErrors();
            parserOutput.close();
            errorOutput.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    private Node parseCompUnit(){
        Node compUnitNode = new Node("<CompUnit>");
        while(isDecl()){
            // System.out.println(getCurrentToken().getValue()+"DECLBEGIN");
            compUnitNode.addChild(parseDecl());
            // System.out.println(getCurrentToken().getValue()+"DECLEND");
        }
        while(isFuncDef()){
            // System.out.println(getCurrentToken().getValue()+"FUNCDEFBEGIN");
            compUnitNode.addChild(parseFuncDef());
            // System.out.println(getCurrentToken().getValue()+"FUNCDEFEND");
        }
        compUnitNode.addChild(parseMainFuncDef());
        return compUnitNode;
    }
    private boolean isDecl() {
        Token currentToken = getCurrentToken();
        if (currentToken == null) {
            return false;
        }
        TokenType currentTokenType = currentToken.getType();
        if (currentTokenType == TokenType.INTTK || currentTokenType == TokenType.CHARTK) {
            Token nextToken = lookAhead();
            if (nextToken != null) {
                if (nextToken.getType() == TokenType.IDENFR) {
                    Token secondToken = index + 2 < tokens.size() ? tokens.get(index + 2) : null;
                    return secondToken == null || secondToken.getType() != TokenType.LPARENT;
                }
            }
        }
        return currentTokenType == TokenType.CONSTTK;
    }


    private Node parseDecl(){
        Node declNode = new Node();
        if(match(TokenType.CONSTTK)){
            declNode.addChild(parseConstDecl());
        } else {
            declNode.addChild(parseVarDecl());
        }
        return declNode;
    }
    private Node parseConstDecl(){
        Node constDeclNode = new Node("<ConstDecl>");
        match(TokenType.CONSTTK);
        Node constNode = new Node("CONSTTK", getCurrentToken().getValue());
        constDeclNode.addChild(constNode);
        advance();
        constDeclNode.addChild(parseBType());
        constDeclNode.addChild(parseConstDef());
        while(match(TokenType.COMMA)){
            Node commaNode = new Node("COMMA ,");
            constDeclNode.addChild(commaNode);
            advance();
            constDeclNode.addChild(parseConstDef());
        }
        if(match(TokenType.SEMICN)) {
            Node semicnNode = new Node("SEMICN", getCurrentToken().getValue());
            constDeclNode.addChild(semicnNode);
            advance();
        }else{
            Token.addError(lookBehind().getLine() + 1, "i");
        }
        return constDeclNode;
    }
    private Node parseBType(){
        Node bTypeNode = new Node();
        if(match(TokenType.INTTK)){
            Node intNode = new Node("INTTK", getCurrentToken().getValue());
            bTypeNode.addChild(intNode);
            advance();
            return bTypeNode;
        } else if(match(TokenType.CHARTK)){
            Node intNode = new Node("CHARTK", getCurrentToken().getValue());
            bTypeNode.addChild(intNode);
            advance();
            return bTypeNode;
        }else{
            System.out.println(getCurrentToken().getValue());
            System.out.println(lookAhead().getValue());
            System.out.println("ERRORINBTYPE");
            return null;
        }
    }
    private Node parseConstDef(){
        Node constDefNode = new Node("<ConstDef>");
        match(TokenType.IDENFR);
        Node idenfrNode = new Node("IDENFR", getCurrentToken().getValue());
        constDefNode.addChild(idenfrNode);
        advance();
        if(match(TokenType.LBRACK)){
            Node lBrackNode = new Node("LBRACK", getCurrentToken().getValue());
            constDefNode.addChild(lBrackNode);
            advance();
            constDefNode.addChild(parseConstExp());
            if(match(TokenType.RBRACK)) {
                Node rBrackNode = new Node("RBRACK", getCurrentToken().getValue());
                constDefNode.addChild(rBrackNode);
                advance();
            } else{
                Token.addError(lookBehind().getLine() + 1, "k");
            }
        }
        match(TokenType.ASSIGN);
        Node assignNode = new Node("ASSIGN", getCurrentToken().getValue());
        constDefNode.addChild(assignNode);
        advance();
        constDefNode.addChild((parseConstInitVal()));
        return constDefNode;
    }
    private Node parseConstExp(){
        Node constExpNode = new Node("<ConstExp>");
        constExpNode.addChild(parseAddExp());
        return constExpNode;
    }
    private Node parseConstInitVal(){
        Node constInitVal = new Node("<ConstInitVal>");
        if(match(TokenType.STRCON)){
            Node strNode = new Node("STRCON", getCurrentToken().getValue());
            constInitVal.addChild(strNode);
            advance();
        } else if(match(TokenType.LBRACE)){
                Node lBraceNode = new Node("LBRACE", getCurrentToken().getValue());
                constInitVal.addChild(lBraceNode);
                advance();
            if(!match(TokenType.RBRACE)) {
                constInitVal.addChild(parseConstExp());
                while (match(TokenType.COMMA)) {
                    Node commaNode = new Node("COMMA", getCurrentToken().getValue());
                    constInitVal.addChild(commaNode);
                    advance();
                    constInitVal.addChild(parseConstExp());
                }
            }
            match(TokenType.RBRACE);
            Node rBraceNode = new Node("RBRACE", getCurrentToken().getValue());
            constInitVal.addChild(rBraceNode);
            advance();
        } else{
            constInitVal.addChild(parseConstExp());
        }
        return constInitVal;
    }
    private Node parseAddExp(){
        Node addExpNode = new Node("<AddExp>");
        addExpNode.addChild(parseMulExp());
        while(match(TokenType.PLUS) || match(TokenType.MINU)){
            Node newAddExpNode = new Node("<AddExp>");
            newAddExpNode.addChild(addExpNode);
            if(match(TokenType.PLUS)){
                Node plusNode = new Node("PLUS", getCurrentToken().getValue());
                newAddExpNode.addChild(plusNode);
            } else{
                Node minuNode = new Node("MINU", getCurrentToken().getValue());
                newAddExpNode.addChild(minuNode);
            }
            advance();
            newAddExpNode.addChild(parseMulExp());
            addExpNode = newAddExpNode;
        }
        return addExpNode;
    }
    private Node parseMulExp(){
        System.out.println(getCurrentToken().getValue()+"  inMul");
        Node mulExpNode = new Node("<MulExp>");
        mulExpNode.addChild(parseUnaryExp());
        while(match(TokenType.MULT) || match(TokenType.DIV) || match(TokenType.MOD)){
            Node newMulExpNode = new Node("<MulExp>");
            newMulExpNode.addChild(mulExpNode);
            if(match(TokenType.MULT)){
                Node multNode = new Node("MULT",getCurrentToken().getValue());
                newMulExpNode.addChild(multNode);
            } else if(match(TokenType.DIV)){
                Node divNode = new Node("DIV",getCurrentToken().getValue());
                newMulExpNode.addChild(divNode) ;
            }else if(match(TokenType.MOD)){
                Node modNode = new Node("MOD",getCurrentToken().getValue());
                newMulExpNode.addChild(modNode);
            }
            advance();
            newMulExpNode.addChild(parseUnaryExp());
            mulExpNode = newMulExpNode;
        }
        return mulExpNode;
    }
    private Node parseUnaryExp() {
        System.out.println(getCurrentToken().getValue()+" inUnary");
        Node unaryExpNode = new Node("<UnaryExp>");
        if (match(TokenType.PLUS) || match(TokenType.MINU) || match(TokenType.NOT)) {
            Node unaryOpNode = new Node("<UnaryOp>");
            unaryExpNode.addChild(unaryOpNode);
            if(match(TokenType.PLUS)){
                Node plusNode = new Node("PLUS",getCurrentToken().getValue());
                unaryOpNode.addChild(plusNode);
            } else if(match(TokenType.MINU)){
                Node minuNode = new Node("MINU",getCurrentToken().getValue());
                unaryOpNode.addChild(minuNode);
            }else if(match(TokenType.NOT)){
                Node notNode = new Node("NOT",getCurrentToken().getValue());
                unaryOpNode.addChild(notNode);
            }
            advance();
            unaryExpNode.addChild(parseUnaryExp());
        } else if (match(TokenType.IDENFR) && lookAhead() != null && lookAhead().getType().equals(TokenType.LPARENT)) {
            Node idenfrNode = new Node("IDENFR", getCurrentToken().getValue());
            unaryExpNode.addChild(idenfrNode);
            advance();
            Node lParentNode = new Node("LPARENT", getCurrentToken().getValue());
            unaryExpNode.addChild(lParentNode);
            advance();
            if (!match(TokenType.RPARENT)) {
                unaryExpNode.addChild(parseFuncRParams());
            }
            if(match(TokenType.RPARENT)) {
                Node rParentNode = new Node("RPARENT", getCurrentToken().getValue());
                unaryExpNode.addChild(rParentNode);
                advance();
            } else{
                Token.addError(lookBehind().getLine() + 1 , "j");
            }
        } else {
            unaryExpNode.addChild(parsePrimaryExp());
        }
        return unaryExpNode;
    }
    private Node parseFuncRParams(){
        Node funcRParamsCode = new Node("<FuncRParams>");
        System.out.println(getCurrentToken().getValue()+"  inFuncRParam");
        funcRParamsCode.addChild(parseExp());
        while (match(TokenType.COMMA)) {
            Node commaNode = new Node("COMMA", getCurrentToken().getValue());
            funcRParamsCode.addChild(commaNode);
            advance();
            funcRParamsCode.addChild(parseExp());
        }
        return funcRParamsCode;
    }
    private Node parseExp(){
        Node expNode = new Node("<Exp>");
        expNode.addChild(parseAddExp());
        return expNode;
    }
    private Node parsePrimaryExp(){
        Node primaryExpNode = new Node("<PrimaryExp>");
        if(match(TokenType.LPARENT)){
            Node lParentNode = new Node("LPARENT", getCurrentToken().getValue());
            primaryExpNode.addChild(lParentNode);
            advance();
            primaryExpNode.addChild(parseExp());
            if(match(TokenType.RPARENT)) {
                Node rParentNode = new Node("RPARENT", getCurrentToken().getValue());
                primaryExpNode.addChild(rParentNode);
                advance();
            } else{
                Token.addError(lookBehind().getLine() + 1, "j");
            }
        } else if(match(TokenType.IDENFR)){
            primaryExpNode.addChild(parseLVal());
        } else if(match(TokenType.INTCON)){
            Node numberNode = new Node("<Number>");
            primaryExpNode.addChild(numberNode);
            Node intconNode = new Node("INTCON", getCurrentToken().getValue());
            numberNode.addChild(intconNode);
            advance();
        } else if(match(TokenType.CHRCON)){
            Node charNode = new Node("<Character>");
            primaryExpNode.addChild(charNode);
            Node chrconNode = new Node("CHRCON", getCurrentToken().getValue());
            charNode.addChild(chrconNode);
            advance();
        } else{
            //errorOutput.println("ERRORINPRIMARY");
            //errorOutput.println(getCurrentToken().getType()+getCurrentToken().getValue());
        }
        return primaryExpNode;
    }
    private Node parseLVal(){
        Node lValNode = new Node("<LVal>");
        match(TokenType.IDENFR);
        Node idenfrNode = new Node("IDENFR", getCurrentToken().getValue());
        lValNode.addChild(idenfrNode);
        advance();
        if(match(TokenType.LBRACK)) {
            Node lBrackNode = new Node("LBRACK", getCurrentToken().getValue());
            lValNode.addChild(lBrackNode);
            advance();
            lValNode.addChild(parseExp());
            if(match(TokenType.RBRACK)) {
                Node rBrackNode = new Node("RBRACK", getCurrentToken().getValue());
                lValNode.addChild(rBrackNode);
                advance();
            } else{
                Token.addError(lookBehind().getLine() + 1, "k");
            }
        }
        return lValNode;
    }
    private Node parseVarDecl(){
        System.out.println(getCurrentToken().getValue() + "VARDECL");
        Node varDeclNode = new Node("<VarDecl>");
        varDeclNode.addChild(parseBType());
        varDeclNode.addChild(parseVarDef());
        while(match(TokenType.COMMA)){
            Node commaNode = new Node("COMMA", getCurrentToken().getValue());
            varDeclNode.addChild(commaNode);
            advance();
            varDeclNode.addChild(parseVarDef());
        }
        if(match(TokenType.SEMICN)) {
            Node semicnNode = new Node("SEMICN", getCurrentToken().getValue());
            varDeclNode.addChild(semicnNode);
            advance();
        }else{
            Token.addError(lookBehind().getLine() + 1, "i");
        }
        return varDeclNode;
    }
    private Node parseVarDef(){
        Node varDefNode = new Node("<VarDef>");
        if(match(TokenType.IDENFR)){
            System.out.println(getCurrentToken().getValue());
            Node idenfrNode = new Node("IDENFR", getCurrentToken().getValue());
            varDefNode.addChild(idenfrNode);
            advance();
            if(match(TokenType.LBRACK)) {
                Node lbrackNode = new Node("LBRACK", getCurrentToken().getValue());
                varDefNode.addChild(lbrackNode);
                advance();
                varDefNode.addChild(parseConstExp());
                if(match(TokenType.RBRACK)) {
                    Node rbrackNode = new Node("RBRACK", getCurrentToken().getValue());
                    varDefNode.addChild(rbrackNode);
                    advance();
                } else{
                    Token.addError(lookBehind().getLine() + 1, "k");
                }
                if(match(TokenType.ASSIGN)) {
                    Node assignNode = new Node("ASSIGN", getCurrentToken().getValue());
                    varDefNode.addChild(assignNode);
                    advance();
                    varDefNode.addChild(parseInitVal());
                }
            } else if(match(TokenType.ASSIGN)){
                Node assignNode = new Node("ASSIGN", getCurrentToken().getValue());
                varDefNode.addChild(assignNode);
                advance();
                varDefNode.addChild(parseInitVal());
            }
        } else{
            errorOutput.println("ERRORINVARDEF");
        }
        return varDefNode;
    }
    private Node parseInitVal(){
        Node initValNode = new Node("<InitVal>");
        if(match(TokenType.LBRACE)){
            Node lBraceNode = new Node("LBRACE", getCurrentToken().getValue());
            initValNode.addChild(lBraceNode);
            advance();
            if(!match(TokenType.RBRACE)){
                initValNode.addChild(parseExp());
                while (match(TokenType.COMMA)) {
                    Node commaNode = new Node("COMMA", getCurrentToken().getValue());
                    initValNode.addChild(commaNode);
                    advance();
                    initValNode.addChild(parseExp());
                }
            }
            System.out.println(getCurrentToken().getValue());
            match(TokenType.RBRACE);
            Node rbraceNode = new Node("RBRACE", getCurrentToken().getValue());
            initValNode.addChild(rbraceNode);
            advance();
        } else if(match(TokenType.STRCON)){
            Node strConNode = new Node("STRCON", getCurrentToken().getValue());
            initValNode.addChild(strConNode);
            advance();
        } else{
            initValNode.addChild(parseExp());
        }
        return initValNode;
    }
    private boolean isFuncDef() {
        if (getCurrentToken().getType().equals(TokenType.INTTK) ||
                getCurrentToken().getType().equals(TokenType.CHARTK) ||
                getCurrentToken().getType().equals(TokenType.VOIDTK)) {
            Token nextToken = lookAhead();
            if (nextToken != null && nextToken.getType().equals(TokenType.IDENFR)) {
                return true;
            }
        }
        return false;
    }

    private Node parseFuncDef(){
        System.out.println("FUNCDEF");
        Node funcDefNode = new Node("<FuncDef>");
        if(match(TokenType.INTTK) || match(TokenType.CHARTK) || match(TokenType.VOIDTK)){
            Node funcTypeNode = new Node("<FuncType>");
            funcDefNode.addChild(funcTypeNode);
            if(match(TokenType.INTTK)){
                Node intNode = new Node("INTTK", getCurrentToken().getValue());
                funcTypeNode.addChild(intNode);
            } else if(match(TokenType.CHARTK)){
                Node charNode = new Node("CHARTK", getCurrentToken().getValue());
                funcTypeNode.addChild(charNode);
            } else{
                Node voidNode = new Node("VOIDTK", getCurrentToken().getValue());
                funcTypeNode.addChild(voidNode);
            }
            advance();
            if(match(TokenType.IDENFR)){
                Node idenfrNode = new Node("IDENFR", getCurrentToken().getValue());
                funcDefNode.addChild(idenfrNode);
                advance();
                if(match(TokenType.LPARENT)){
                    Node lParentNode = new Node("LPARENT", getCurrentToken().getValue());
                    funcDefNode.addChild(lParentNode);
                    advance();
                    if(match(TokenType.RPARENT)){
                        Node rParentNode = new Node("RPARENT", getCurrentToken().getValue());
                        funcDefNode.addChild(rParentNode);
                        advance();
                        funcDefNode.addChild(parseBlock());
                    } else if(match(TokenType.LBRACE)) {
                        Token.addError(lookBehind().getLine() + 1, "j");
                        funcDefNode.addChild(parseBlock());
                    }else{
                        funcDefNode.addChild(parseFuncFParams());
                        if(match(TokenType.RPARENT)) {
                            Node rParentNode = new Node("RPARENT", getCurrentToken().getValue());
                            funcDefNode.addChild(rParentNode);
                            advance();
                            funcDefNode.addChild(parseBlock());
                        } else{
                            Token.addError(lookBehind().getLine() + 1, "j");
                            funcDefNode.addChild(parseBlock());
                        }
                    }
                }
            }
        }
        return funcDefNode;
    }
    private Node parseFuncFParams(){
        Node funcFParamsNode = new Node("<FuncFParams>");
        funcFParamsNode.addChild(parseFuncFParam());
        while(match(TokenType.COMMA)){
            Node commaNode = new Node("COMMA", getCurrentToken().getValue());
            funcFParamsNode.addChild(commaNode);
            advance();
            funcFParamsNode.addChild(parseFuncFParam());
        }
        return funcFParamsNode;
    }
    private Node parseFuncFParam(){
        Node funcFParamNode = new Node("<FuncFParam>");
        funcFParamNode.addChild(parseBType());
        if(match(TokenType.IDENFR)){
            Node idenfrNode = new Node("IDENFR", getCurrentToken().getValue());
            funcFParamNode.addChild(idenfrNode);
            advance();
            if(match(TokenType.LBRACK)){
                Node lbrackNode = new Node("LBRACK", getCurrentToken().getValue());
                funcFParamNode.addChild(lbrackNode);
                advance();
                if(match(TokenType.RBRACK)){
                    Node rBrackNode = new Node("RBRACK", getCurrentToken().getValue());
                    funcFParamNode.addChild(rBrackNode);
                    advance();
                } else{
                    Token.addError(lookBehind().getLine() + 1, "k");
                }
            }
        }
        return funcFParamNode;
    }
    private Node parseBlock(){
        Node blockNode = new Node("<Block>");
        if(match(TokenType.LBRACE)){
            Node lBraceNode = new Node("LBRACE", getCurrentToken().getValue());
            blockNode.addChild(lBraceNode);
            advance();
            while(!match(TokenType.RBRACE)){
                if(isDecl()){
                    System.out.println(getCurrentToken().getValue()+"DECLBEGIN");
                    blockNode.addChild(parseDecl());
                    System.out.println(getCurrentToken().getValue()+"DECLEND");
                } else if(isStmt()){
                    System.out.println(getCurrentToken().getValue()+"STMTBEGIN");
                    blockNode.addChild(parseStmt());
                    System.out.println(getCurrentToken().getValue()+"STMTEND");
                } else{
                    errorOutput.println(getCurrentToken().getValue());
                    errorOutput.println("ERRORINBLOCK1");
                }
            }
            match(TokenType.RBRACE);
            Node rBraceNode = new Node("RBRACE", getCurrentToken().getValue());
            blockNode.addChild(rBraceNode);
            advance();
        } else{
            errorOutput.println("ERRORINBLOCK2");
        }
        return blockNode;
    }
    private boolean isStmt() {
        Token currentToken = getCurrentToken();
        if (currentToken == null) {
            return false;
        }
        TokenType currentTokenType = currentToken.getType();
        return currentTokenType == TokenType.IDENFR
                || currentTokenType == TokenType.INTCON || currentTokenType == TokenType.CHRCON
                || currentTokenType == TokenType.LBRACE || currentTokenType == TokenType.SEMICN
                || currentTokenType == TokenType.IFTK || currentTokenType == TokenType.FORTK
                || currentTokenType == TokenType.PLUS || currentTokenType == TokenType.MINU
                || currentTokenType == TokenType.NOT || currentTokenType == TokenType.LPARENT
                || currentTokenType == TokenType.BREAKTK || currentTokenType == TokenType.CONTINUETK
                || currentTokenType == TokenType.RETURNTK || currentTokenType == TokenType.PRINTFTK;
    }

    private Node parseStmt(){
        Node stmtNode = new Node("<Stmt>");
        if(getCurrentToken().getType().equals(TokenType.SEMICN)){
            match(TokenType.SEMICN);
            Node semicnNode = new Node("SEMICN", getCurrentToken().getValue());
            stmtNode.addChild(semicnNode);
            advance();
        } else if(match(TokenType.IFTK)){
            Node ifNode = new Node("IFTK",getCurrentToken().getValue());
            stmtNode.addChild(ifNode);
            advance();
            match(TokenType.LPARENT);
            Node lParentNode = new Node("LPARENT", getCurrentToken().getValue());
            stmtNode.addChild(lParentNode);
            advance();
            stmtNode.addChild(parseCond());
            if(match(TokenType.RPARENT)) {
                Node rParentNode = new Node("RPARENT", getCurrentToken().getValue());
                stmtNode.addChild(rParentNode);
                advance();
            } else{
                Token.addError(lookBehind().getLine() + 1, "j");
            }
            stmtNode.addChild(parseStmt());
            if(match(TokenType.ELSETK)){
                Node elseNode = new Node("ELSETK", getCurrentToken().getValue());
                stmtNode.addChild(elseNode);
                advance();
                stmtNode.addChild(parseStmt());
            }
        } else if(match(TokenType.FORTK)){
            System.out.println("FORTK");
            Node forNode = new Node("FORTK", getCurrentToken().getValue());
            stmtNode.addChild(forNode);
            advance();
            match(TokenType.LPARENT);
            Node lParentNode = new Node("LPARENT", getCurrentToken().getValue());
            stmtNode.addChild(lParentNode);
            advance();
            if(!match(TokenType.SEMICN)){
                stmtNode.addChild(parseForStmt());
            }
            match(TokenType.SEMICN);
            Node semicnNode = new Node("SEMICN", getCurrentToken().getValue());
            stmtNode.addChild(semicnNode);
            advance();
            if(!match(TokenType.SEMICN)){
                stmtNode.addChild(parseCond());
            }
            match(TokenType.SEMICN);
            stmtNode.addChild(semicnNode);
            advance();
            if(match(TokenType.IDENFR)){
                stmtNode.addChild(parseForStmt());
            }
            if(match(TokenType.RPARENT)) {
                Node rParentNode = new Node("RPARENT", getCurrentToken().getValue());
                stmtNode.addChild(rParentNode);
                advance();
            } else{
                Token.addError(lookBehind().getLine() + 1, "j");
            }
            stmtNode.addChild(parseStmt());
        } else if(match(TokenType.BREAKTK)){
            Node breakNode = new Node("BREAKTK",getCurrentToken().getValue());
            stmtNode.addChild(breakNode);
            advance();
            if(match(TokenType.SEMICN)) {
                Node semicnNode = new Node("SEMICN", getCurrentToken().getValue());
                stmtNode.addChild(semicnNode);
                advance();
            }else{
                Token.addError(lookBehind().getLine() + 1, "i");
            }
        } else if(match(TokenType.CONTINUETK)){
            Node continueNode = new Node("CONTINUETK",getCurrentToken().getValue());
            stmtNode.addChild(continueNode);
            advance();
            if(match(TokenType.SEMICN)) {
                Node semicnNode = new Node("SEMICN", getCurrentToken().getValue());
                stmtNode.addChild(semicnNode);
                advance();
            } else{
                Token.addError(lookBehind().getLine() + 1, "i");
            }
        } else if(match(TokenType.RETURNTK)){
            Node returnNode = new Node("RETURNTK",getCurrentToken().getValue());
            System.out.println("444");
            stmtNode.addChild(returnNode);
            advance();
            if(!match(TokenType.SEMICN)){
                stmtNode.addChild(parseExp());
            }
            if(match(TokenType.SEMICN)){
            Node semicnNode = new Node("SEMICN", getCurrentToken().getValue());
            stmtNode.addChild(semicnNode);
            advance();
            } else{
                Token.addError(lookBehind().getLine() + 1, "i");
            }
        } else if(match(TokenType.PRINTFTK)){
            Node printfNode = new Node("PRINTFTK", getCurrentToken().getValue());
            stmtNode.addChild(printfNode);
            advance();
            match(TokenType.LPARENT);
            Node lParentNode = new Node("LPARENT", getCurrentToken().getValue());
            stmtNode.addChild(lParentNode);
            advance();
            match(TokenType.STRCON);
            System.out.println(getCurrentToken().getValue());
            Node strNode = new Node("STRCON", getCurrentToken().getValue());
            stmtNode.addChild(strNode);
            advance();
            while(match(TokenType.COMMA)){
                Node commaNode = new Node("COMMA", getCurrentToken().getValue());
                stmtNode.addChild(commaNode);
                advance();
                stmtNode.addChild(parseExp());
            }
            if(match(TokenType.RPARENT)) {
                Node rParentNode = new Node("RPARENT", getCurrentToken().getValue());
                stmtNode.addChild(rParentNode);
                advance();
            } else{
                Token.addError(lookBehind().getLine() + 1, "j");
            }
            if(match(TokenType.SEMICN)) {
                Node semicnNode = new Node("SEMICN", getCurrentToken().getValue());
                stmtNode.addChild(semicnNode);
                advance();
            } else{
                Token.addError(lookBehind().getLine() + 1, "i");
            }
        } else if(match(TokenType.LBRACE)){
            stmtNode.addChild(parseBlock());
        } else{ // 判断LVaL还是Exp
            //先尝试解析LVaL
            int currentIndex = index;
            if(match(TokenType.IDENFR)){
                Node lValNode = parseLVal();
                if(match(TokenType.ASSIGN)){
                    stmtNode.addChild(lValNode);
                    Node assignNode = new Node("ASSIGN", getCurrentToken().getValue());
                    stmtNode.addChild(assignNode);
                    advance();
                    if(match(TokenType.GETINTTK) || match(TokenType.GETCHARTK)) {
                        if (match(TokenType.GETINTTK)) {
                            Node getintNode = new Node("GETINTTK", getCurrentToken().getValue());
                            stmtNode.addChild(getintNode);
                        } else {
                            Node getcharNode = new Node("GETCHARTK", getCurrentToken().getValue());
                            stmtNode.addChild(getcharNode);
                        }
                        advance();
                        if(match(TokenType.LPARENT)) {
                            Node lParentNode = new Node("LPARENT", getCurrentToken().getValue());
                            stmtNode.addChild(lParentNode);
                            advance();
                            if(match(TokenType.RPARENT)) {
                                Node rParentNode = new Node("RPARENT", getCurrentToken().getValue());
                                stmtNode.addChild(rParentNode);
                                advance();
                            } else{
                                Token.addError(lookBehind().getLine() + 1, "j");
                            }
                            if (match(TokenType.SEMICN)) {
                                System.out.println("instmtlval  " + getCurrentToken().getValue());
                                Node semicnNode = new Node("SEMICN", getCurrentToken().getValue());
                                stmtNode.addChild(semicnNode);
                                advance();
                            }else{
                                Token.addError(lookBehind().getLine() + 1, "i");
                            }
                            return stmtNode;
                        }
                    }else {
                        stmtNode.addChild(parseExp());
                        if (match(TokenType.SEMICN)) {
                            System.out.println("instmtlval  " + getCurrentToken().getValue());
                            Node semicnNode = new Node("SEMICN", getCurrentToken().getValue());
                            stmtNode.addChild(semicnNode);
                            advance();
                        } else{
                            Token.addError(lookBehind().getLine() + 1, "i");
                        }
                        return stmtNode;
                    }
                }
            }
                index = currentIndex;
                if (isExp()) {
                    stmtNode.addChild(parseExp());
                    if(match(TokenType.SEMICN)) {
                        Node semicnNode = new Node("SEMICN", getCurrentToken().getValue());
                        stmtNode.addChild(semicnNode);
                        advance();
                    }else{
                        Token.addError(lookBehind().getLine() + 1, "i");
                    }
                }
            }
        return stmtNode;
    }
    private boolean isExp(){
        if (getCurrentToken() == null) {
            return false;
        }
        TokenType currentType = getCurrentToken().getType();
        return currentType == TokenType.INTCON ||
                currentType == TokenType.CHRCON ||
                currentType == TokenType.IDENFR ||
                currentType == TokenType.LPARENT ||
                currentType == TokenType.PLUS ||
                currentType == TokenType.MINU ||
                currentType == TokenType.NOT;
    }
    private Node parseForStmt(){
        System.out.println("FORSTMT");
        Node forStmtCode = new Node("<ForStmt>");
        forStmtCode.addChild(parseLVal());
        match(TokenType.ASSIGN);
        Node assignNode = new Node("ASSIGN", getCurrentToken().getValue());
        forStmtCode.addChild(assignNode);
        advance();
        forStmtCode.addChild(parseExp());
        return forStmtCode;
    }
    private Node parseCond(){
        System.out.println("COND");
        Node condNode = new Node("<Cond>");
        condNode.addChild(parseLOrExp());
        return condNode;
    }
    private Node parseLOrExp(){
        System.out.println("LOREXP");
        Node lOrExpNode = new Node("<LOrExp>");
        lOrExpNode.addChild(parseLAndExp());
        while (match(TokenType.OR)) {
            Node newLOrExpNode = new Node("<LOrExp>");
            newLOrExpNode.addChild(lOrExpNode);
            Node orNode = new Node("OR", getCurrentToken().getValue());
            newLOrExpNode.addChild(orNode);
            advance();
            newLOrExpNode.addChild(parseLAndExp());
            lOrExpNode = newLOrExpNode;
        }
        return lOrExpNode;
    }
    private Node parseLAndExp() {
        System.out.println("LANDEXP");
        Node lAndExpNode = new Node("<LAndExp>");
        lAndExpNode.addChild(parseEqExp());
        while (match(TokenType.AND)) {
            Node newLAndExpNode = new Node("<LAndExp>");
            newLAndExpNode.addChild(lAndExpNode);
            Node andNode = new Node("AND", getCurrentToken().getValue());
            newLAndExpNode.addChild(andNode);
            advance();
            newLAndExpNode.addChild(parseEqExp());
            lAndExpNode = newLAndExpNode;
        }
        return lAndExpNode;
    }
    private Node parseEqExp() {
        System.out.println("EQEXP");
        Node eqExpNode = new Node("<EqExp>");
        eqExpNode.addChild(parseRelExp());
        while (match(TokenType.EQL) || match(TokenType.NEQ)) {
            Node newEqExpNode = new Node("<EqExp>");
            newEqExpNode.addChild(eqExpNode);
            if(match(TokenType.EQL)){
                Node eqlNode = new Node("EQL", getCurrentToken().getValue());
                newEqExpNode.addChild(eqlNode);
            } else{
                Node neqNode = new Node("NEQ", getCurrentToken().getValue());
                newEqExpNode.addChild(neqNode);
            }
            advance();
            newEqExpNode.addChild(parseRelExp());
            eqExpNode = newEqExpNode;
        }
        return eqExpNode;
    }
    private Node parseRelExp() {
        System.out.println("RELEXP");
        Node relExpNode = new Node("<RelExp>");
        relExpNode.addChild(parseAddExp());
        while (match(TokenType.LSS) || match(TokenType.GRE) || match(TokenType.LEQ) || match(TokenType.GEQ)) {
            Node newRelExpNode = new Node("<RelExp>");
            newRelExpNode.addChild(relExpNode);
            if(match(TokenType.LSS)){
                Node lssNode = new Node("LSS", getCurrentToken().getValue());
                newRelExpNode.addChild(lssNode);
            } else if(match(TokenType.GRE)){
                Node greNode = new Node("GRE", getCurrentToken().getValue());
                newRelExpNode.addChild(greNode);
            } else if(match(TokenType.LEQ)){
                Node leqNode = new Node("LEQ", getCurrentToken().getValue());
                newRelExpNode.addChild(leqNode);
            } else{
                Node geqNode = new Node("GEQ", getCurrentToken().getValue());
                newRelExpNode.addChild(geqNode);
            }
            advance();
            newRelExpNode.addChild(parseAddExp());
            relExpNode = newRelExpNode;
        }
        return relExpNode;
    }
    private Node parseMainFuncDef() {
        Node mainFuncDefNode = new Node("<MainFuncDef>");
        match(TokenType.INTTK);
        Node intNode = new Node("INTTK", getCurrentToken().getValue());
        mainFuncDefNode.addChild(intNode);
        advance();
        match(TokenType.MAINTK);
        Node mainNode = new Node("MAINTK", getCurrentToken().getValue());
        mainFuncDefNode.addChild(mainNode);
        advance();
        match(TokenType.LPARENT);
        Node lParentNode = new Node("LPARENT", getCurrentToken().getValue());
        mainFuncDefNode.addChild(lParentNode);
        advance();
        if(match(TokenType.RPARENT)) {
            Node rParentNode = new Node("RPARENT", getCurrentToken().getValue());
            mainFuncDefNode.addChild(rParentNode);
            advance();
        } else{
            Token.addError(lookBehind().getLine() + 1, "j");
        }
        mainFuncDefNode.addChild(parseBlock());
        return mainFuncDefNode;
    }
    private void outputErrors(){
        Token.errorList.sort((s1, s2) -> {
            try {
                // 提取每个字符串中行号部分，允许多个空格
                String[] parts1 = s1.trim().split("\\s+");  // 使用 \\s+ 来处理多个空格
                String[] parts2 = s2.trim().split("\\s+");
                if (parts1.length > 0 && parts2.length > 0) {
                    int num1 = Integer.parseInt(parts1[0]);  // 取出第一个部分并解析为整数
                    int num2 = Integer.parseInt(parts2[0]);
                    return Integer.compare(num1, num2);
                }
            } catch (NumberFormatException e) {
                System.err.println("格式错误: " + e.getMessage());
            }
            return 0;
        });
        for(String error: Token.errorList){
            errorOutput.println(error);
        }
    }
}
