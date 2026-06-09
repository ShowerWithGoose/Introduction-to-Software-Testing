package frontend;

import frontend.trees.*;
import exception.*;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.List;
import java.util.ArrayList;

public class Parser {

    private BufferedReader br;
    private InputStreamReader inputStreamReader;
    public List<Token> tokens;
    public List<Error> errors;

    int currTokenPos = 0;
    private Token currToken;


    public Parser(List<Token> tokens) {
        this.tokens = tokens;
        this.errors = new ArrayList<>();
        //listIterator = tokens.listIterator();
    }

    public Token get_new_Token() {
        currTokenPos++;
        if(currTokenPos < tokens.size()) {
            //System.out.println(tokens.get(currTokenPos).getValue()+" "+tokens.get(currTokenPos).getLineNum());
            return tokens.get(currTokenPos);
        }
        else {
            return null;
        }
    }

    public Token get_cur_Token() {
        if(currTokenPos  < tokens.size()) {
            //System.out.println(tokens.get(currTokenPos).getValue()+" "+tokens.get(currTokenPos).getLineNum());
            return tokens.get(currTokenPos);
        }
        else {
            return null;
        }
    }

    public Token Judge_Error_i()
    {
        if (isMatch(currToken, LexType.SEMICN)) {
            return get_new_Token();
        } else {
            Token beforeToken = tokens.get(currTokenPos-1);
            errors.add(new Error(beforeToken.getLineNum(), ErrorType.i));
            return currToken;
        }
    }

    public Token Judge_Error_j()
    {
        if (isMatch(currToken, LexType.RPARENT)) {
            return get_new_Token();
        } else {
            Token beforeToken = tokens.get(currTokenPos-1);
            errors.add(new Error(beforeToken.getLineNum(), ErrorType.j));
            return currToken;
        }
    }

    public Token Judge_Error_k()
    {
        if (isMatch(currToken, LexType.RBRACK)) {
            return get_new_Token();
        } else {
            Token beforeToken = tokens.get(currTokenPos-1);
            errors.add(new Error(beforeToken.getLineNum(), ErrorType.k));
            return currToken;
        }
    }
    
    public Token getNextToken() {
        if((currTokenPos+1) < tokens.size()) {
            return tokens.get(currTokenPos+1);
        }
        return null;
    }

    public Token getNext_NextToken() {
        if((currTokenPos+2) < tokens.size()) { 
            return tokens.get(currTokenPos+2);
        }
        return null;
    }

    private static boolean isMatch(Token token, LexType type) {
        return token.getLexType() == type;
    }

    private static boolean isNotMatch(Token token, LexType type) {
        return token.getLexType() != type;
    }



    private Token parse_Single_get_new_token(Token token, LexType type, ParserException e) throws ParserException {
        if(isMatch(token, type)) {
            return get_new_Token();
        }
        else {
            throw e;
        }
    }



    public boolean findUntil(LexType find, LexType until){
        for (int i = currTokenPos; i < tokens.size(); i++) {
            if (tokens.get(i).getLexType() == find) {
                return true;
            } else if (tokens.get(i).getLexType() == until) {
                return false;
            }
        }

        for(int i = 0; i < currTokenPos; i++)
        {
            if (tokens.get(i).getLexType() == find) {
                return true;
            } else if (tokens.get(i).getLexType() == until) {
                return false;
            }
        }
//        while (lexer.next()) {
//            var token = lexer.getToken();
//            findBuffer.add(token);
//            if (token.getType() == find) {
//                return true;
//            } else if (token.getType() == until) {
//                return false;
//            }
//        }
        return false;
    }



    public Tree parse() throws ParserException {
        currToken = tokens.get(currTokenPos);
        Tree result = parseCompUnit();
        currToken = get_cur_Token();
        if(currToken != null) {
            throw new ParserException("NOT END");
        }
        return result;

    }

    private Tree parseCompUnit() throws ParserException {
        CompUnitTree subTree = new CompUnitTree();
        Tree result;
        Token next_token, next_Next_token;

        next_token = getNextToken();
        next_Next_token = getNext_NextToken();
        while (isMatch(currToken, LexType.CONSTTK)
                || ((isMatch(currToken, LexType.INTTK)||isMatch(currToken, LexType.CHARTK))
                && isMatch(next_token, LexType.IDENFR)
                && isNotMatch(next_Next_token, LexType.LPARENT))
        ) {
            result = parseDecl();
            currToken = get_cur_Token();
            subTree.declares.add((DeclTree) result);

            next_token = getNextToken();
            next_Next_token = getNext_NextToken();
        }

        next_token = getNextToken();
        while ((isMatch(currToken, LexType.VOIDTK) || isMatch(currToken, LexType.INTTK)|| isMatch(currToken, LexType.CHARTK))
                && isMatch(next_token, LexType.IDENFR)
        )
        {
            result = parseFuncDef();
            currToken = get_cur_Token();
            subTree.funcs.add((FuncDefTree) result);

            next_token = getNextToken();
        }

        result = parseMainFuncDef();
        currToken = get_cur_Token();
        subTree.mainFunc = (MainFuncDefTree) result;

        return subTree;
    }

    private Tree parseDecl() throws ParserException {
        DeclTree subTree;
        Tree result;

        if (isMatch(currToken, LexType.CONSTTK)) {
            var newNode = new DeclTreeForConstDecl();

            result = parseConstDecl();
            currToken = get_cur_Token();
            newNode.constDecl = (ConstDeclTree) result;

            subTree = newNode;
        } else if (isMatch(currToken, LexType.INTTK) || isMatch(currToken, LexType.CHARTK)) {
            var newNode = new DeclTreeForVarDecl();

            result = parseVarDecl();
            currToken = get_cur_Token();
            newNode.varDecl = (VarDeclTree) result;

            subTree = newNode;
        } else {
            throw new ParserException();
        }

        return subTree;
    }

    private Tree parseConstDecl() throws ParserException {
        ConstDeclTree subTree = new ConstDeclTree();
        Tree result;

        currToken = parse_Single_get_new_token(currToken, LexType.CONSTTK, new ParserException());

        result = parseBType();
        currToken = get_cur_Token();
        subTree.type = (BTypeTree) result;

        result = parseConstDef();
        currToken = get_cur_Token();
        subTree.constDefs.add((ConstDefTree) result);

        while (isMatch(currToken, LexType.COMMA)) {
            currToken = get_new_Token();

            result = parseConstDef();
            currToken = get_cur_Token();
            subTree.constDefs.add((ConstDefTree) result);
        }

        currToken = Judge_Error_i();

        return subTree;
    }

    private Tree parseBType() throws ParserException {

        BTypeTree subTree = new BTypeTree();
        if (isMatch(currToken, LexType.INTTK)) {
            subTree.type = LexType.INTTK;
        }
        else if(isMatch(currToken, LexType.CHARTK)) {
            subTree.type = LexType.CHARTK;
        }
        else{
            throw new ParserException();
        }
//        subTree.type = currToken.getLexType();
//        currToken = parse_Single_get_new_token(currToken, LexType.INTTK, new ParserException());

        currToken = get_new_Token();
        return subTree;
    }

    private Tree parseConstDef() throws ParserException {
        ConstDefTree subTree = new ConstDefTree();
        Tree result;

        subTree.ident = currToken.getValue();
        subTree.identLineNum = currToken.getLineNum();
        currToken = parse_Single_get_new_token(currToken, LexType.IDENFR, new ParserException());
        while (isMatch(currToken, LexType.LBRACK)) {
            currToken = get_new_Token();

            result = parseConstExp();
            currToken = get_cur_Token();
            subTree.dimensions.add((ConstExpTree) result);

            currToken = Judge_Error_k();
        }
        currToken = parse_Single_get_new_token(currToken, LexType.ASSIGN, new ParserException());

        result = parseConstInitVal();
        currToken = get_cur_Token();
        subTree.constInitVal = (ConstInitValTree) result;

        return subTree;
    }

    private Tree parseConstInitVal() throws ParserException {
        ConstInitValTree subTree;
        Tree result;

        //System.out.println(currToken.getValue());

        if (isMatch(currToken, LexType.LPARENT)
                || isMatch(currToken, LexType.IDENFR)
                || isMatch(currToken, LexType.INTCON)
                || isMatch(currToken, LexType.CHRCON)
                || isMatch(currToken, LexType.PLUS)
                || isMatch(currToken, LexType.MINU)
        ) {
            var newNode = new ConstInitValTreeForConstExp();

            result = parseConstExp();
            currToken = get_cur_Token();
            newNode.constExp = (ConstExpTree) result;

            subTree = newNode;
        } else if (isMatch(currToken, LexType.LBRACE)) {
            var newNode = new ConstInitValTreeForArrayInit();

            currToken = get_new_Token();
            if (isNotMatch(currToken, LexType.RBRACE)) {
                result = parseConstExp();
                currToken = get_cur_Token();
                newNode.constExpTrees.add((ConstExpTree) result);

                while (isMatch(currToken, LexType.COMMA)) {
                    currToken = get_new_Token();

                    result = parseConstExp();
                    currToken = get_cur_Token();
                    newNode.constExpTrees.add((ConstExpTree) result);
                }

            }
            currToken = parse_Single_get_new_token(currToken, LexType.RBRACE, new ParserException());

            subTree = newNode;
        }

        else if(isMatch(currToken, LexType.STRCON)) {

            var newNode = new ConstInitValTreeForStringConst();
            result = parseString();
            currToken = get_cur_Token();
            newNode.string = (StringTree) result;
            subTree = newNode;
        }
        else {
            throw new ParserException();
        }

        return subTree;
    }

    private Tree parseVarDecl() throws ParserException {

        VarDeclTree subTree = new VarDeclTree();
        Tree result;

        result = parseBType();
        currToken = get_cur_Token();
        subTree.type = (BTypeTree) result;

        result = parseVarDef();
        currToken = get_cur_Token();
        subTree.varDefs.add((VarDefTree) result);

        while (isMatch(currToken, LexType.COMMA)) {
            currToken = get_new_Token();

            result = parseVarDef();
            currToken = get_cur_Token();
            subTree.varDefs.add((VarDefTree) result);
        }

        currToken = Judge_Error_i();

        return subTree;
    }

    private Tree parseVarDef() throws ParserException {
        VarDefTree subTree = new VarDefTree();
        Tree result;

        subTree.ident = currToken.getValue();
        subTree.identLineNum = currToken.getLineNum();
        currToken = parse_Single_get_new_token(currToken, LexType.IDENFR, new ParserException());
        while (isMatch(currToken, LexType.LBRACK)) {
            currToken = get_new_Token();

            result = parseConstExp();
            currToken = get_cur_Token();
            subTree.dimensions.add((ConstExpTree) result);

            currToken = Judge_Error_k();
        }
        if (isMatch(currToken, LexType.ASSIGN)) {
            currToken = get_new_Token();

            result = parseInitVal();
            currToken = get_cur_Token();
            subTree.initVal = (InitValTree) result;
        }

        return subTree;
    }

    private Tree parseInitVal() throws ParserException {
        InitValTree subTree;
        Tree result;

        if (isMatch(currToken, LexType.LPARENT)
                || isMatch(currToken, LexType.IDENFR)
                || isMatch(currToken, LexType.INTCON)
                || isMatch(currToken, LexType.CHRCON)
                || isMatch(currToken, LexType.PLUS)
                || isMatch(currToken, LexType.MINU)
        ) {
            var newNode = new InitValTreeForExp();

            result = parseExp();
            currToken = get_cur_Token();
            newNode.exp = (ExpTree) result;

            subTree = newNode;
        } else if (isMatch(currToken, LexType.LBRACE)) {
            var newNode = new InitValTreeForArray();

            currToken = get_new_Token();
            if (isNotMatch(currToken, LexType.RBRACK)) {
                result = parseExp();
                currToken = get_cur_Token();
                newNode.expTrees.add((ExpTree) result);

                while (isMatch(currToken, LexType.COMMA)) {
                    currToken = get_new_Token();

                    result = parseExp();
                    currToken = get_cur_Token();
                    newNode.expTrees.add((ExpTree) result);
                }
            }
            currToken = parse_Single_get_new_token(currToken, LexType.RBRACE, new ParserException());

            subTree = newNode;
        }

        else if(isMatch(currToken, LexType.STRCON)) {

            var newNode = new InitValTreeForStringConst();
            result = parseString();
            currToken = get_cur_Token();
            newNode.string = (StringTree) result;
            subTree = newNode;
        }

        else {
            throw new ParserException();
        }

        return subTree;
    }

    private Tree parseFuncDef() throws ParserException {
        FuncDefTree subTree = new FuncDefTree();
        Tree result;

        //Functype
        result = parseFuncType();
        currToken = get_cur_Token();
        subTree.funcType = (FuncTypeTree) result;

        subTree.ident = currToken.getValue();
        subTree.identLineNum = currToken.getLineNum();

        //ident 简约判断的同时移动到下一个
        currToken = parse_Single_get_new_token(currToken, LexType.IDENFR, new ParserException());
        //'('
        currToken = parse_Single_get_new_token(currToken, LexType.LPARENT, new ParserException());
        //'FuncFParams'
        if (isMatch(currToken, LexType.INTTK) || isMatch(currToken, LexType.CHARTK)) {
            result = parseFuncFParams();
            currToken = get_cur_Token();
            subTree.params = (FuncFParamsTree) result;
        }

        //')'
        currToken = Judge_Error_j();

        result = parseBlock();
        subTree.block = (BlockTree) result;
        currToken = get_cur_Token();

        return subTree;
    }

    private Tree parseMainFuncDef() throws ParserException {
        MainFuncDefTree subTree = new MainFuncDefTree();
        Tree result;

        currToken = parse_Single_get_new_token(currToken, LexType.INTTK, new ParserException());
        currToken = parse_Single_get_new_token(currToken, LexType.MAINTK, new ParserException());
        currToken = parse_Single_get_new_token(currToken, LexType.LPARENT, new ParserException());

        currToken = Judge_Error_j();

        result = parseBlock();
        currToken = get_cur_Token();
        subTree.mainBlock = (BlockTree) result;

        return subTree;
    }

    private Tree parseFuncType() throws ParserException {
        FuncTypeTree subTree = new FuncTypeTree();

        if (isMatch(currToken, LexType.VOIDTK) || isMatch(currToken, LexType.INTTK) || isMatch(currToken, LexType.CHARTK)) {
            subTree.type = currToken.getLexType();

            currToken = get_new_Token();
        } else {
            throw new ParserException();
        }
        return subTree;
    }

    private Tree parseFuncFParams() throws ParserException {
        Tree result;
        FuncFParamsTree subTree = new FuncFParamsTree();

        result = parseFuncFParam();
        currToken = get_cur_Token();
        subTree.params.add((FuncFParamTree) result);

        while (isMatch(currToken, LexType.COMMA)) {
            currToken = get_new_Token();
            result = parseFuncFParam();
            subTree.params.add((FuncFParamTree) result);

            currToken = get_cur_Token();
        }

        return subTree;
    }

    private Tree parseFuncFParam() throws ParserException {
        FuncFParamTree subTree = new FuncFParamTree();
        Tree result;

        result = parseBType();
        currToken = get_cur_Token();
        subTree.type = (BTypeTree) result;

        subTree.ident = currToken.getValue();
        subTree.identLineNum = currToken.getLineNum();
        currToken = parse_Single_get_new_token(currToken, LexType.IDENFR, new ParserException());
        if (isMatch(currToken, LexType.LBRACK)) {
            subTree.dimensions = new ArrayList<>();
            currToken = get_new_Token();

            currToken = Judge_Error_k();

            //多维数组的可能性
        }
        return subTree;
    }

    private Tree parseBlock() throws ParserException {
        BlockTree subTree = new BlockTree();
        Tree result;

        currToken = parse_Single_get_new_token(currToken, LexType.LBRACE, new ParserException());
        while (isNotMatch(currToken, LexType.RBRACE)) {
            result = parseBlockItem();
            currToken = get_cur_Token();
            subTree.blockItems.add((BlockItemTree) result);
        }
        subTree.blockRLineNum = currToken.getLineNum();
        currToken = get_new_Token();
        return subTree;
    }

    private Tree parseBlockItem() throws ParserException {
        BlockItemTree subTree;
        Tree result;

        if (isMatch(currToken, LexType.INTTK) || isMatch(currToken, LexType.CONSTTK) || isMatch(currToken, LexType.CHARTK)) {
            var newNode = new BlockItemTreeForDecl();

            result = parseDecl();
            currToken = get_cur_Token();
            newNode.decl = (DeclTree) result;

            subTree = newNode;
        } else {
            var newNode = new BlockItemTreeForStmt();

            result = parseStmt();
            currToken = get_cur_Token();
            newNode.stmt = (StmtTree) result;

            subTree = newNode;
        }

        return subTree;
    }

    private Tree parseStmt() throws ParserException {
        StmtTree subTree;
        Tree result;

        //System.out.println(currToken.getValue()+" "+ currToken.getLineNum());
        Token next_token = getNextToken();
        if (isMatch(currToken, LexType.IDENFR)
                && (findUntil(LexType.ASSIGN, LexType.SEMICN))
        ) {
            LValTree tmpLVal;
            result = parseLVal();
            currToken = get_cur_Token();
            tmpLVal = (LValTree) result;

            currToken = parse_Single_get_new_token(currToken, LexType.ASSIGN, new ParserException());

            if (isMatch(currToken, LexType.GETINTTK) || isMatch(currToken, LexType.GETCHARTK)) {
                var newNode = new StmtTreeForGetIntAndChar();

                //新增内容
                if(isMatch(currToken, LexType.GETINTTK)){
                    newNode.type = LexType.GETINTTK;
                }
                else if(isMatch(currToken, LexType.GETCHARTK)){
                    newNode.type = LexType.GETCHARTK;
                }

                newNode.lVal = tmpLVal;

                currToken = get_new_Token();
                currToken = parse_Single_get_new_token(currToken, LexType.LPARENT, new ParserException());

                currToken = Judge_Error_j();

                currToken = Judge_Error_i();

                subTree = newNode;
            }
            else if (isMatch(currToken, LexType.LPARENT)
                    || isMatch(currToken, LexType.IDENFR)
                    || isMatch(currToken, LexType.INTCON)
                    || isMatch(currToken, LexType.CHRCON)
                    || isMatch(currToken, LexType.PLUS)
                    || isMatch(currToken, LexType.MINU)
            ) {
                var newNode = new StmtTreeForAssign();
                result = parseExp();
                currToken = get_cur_Token();
                newNode.exp = (ExpTree) result;
                newNode.lVal = tmpLVal;

                currToken = Judge_Error_i();


                subTree = newNode;
            } else {
                throw new ParserException();
            }
        } else if (isMatch(currToken, LexType.LPARENT)
                || isMatch(currToken, LexType.IDENFR)
                || isMatch(currToken, LexType.INTCON)
                || isMatch(currToken, LexType.CHRCON)
                || isMatch(currToken, LexType.PLUS)
                || isMatch(currToken, LexType.MINU)
        ) {
            var newNode = new StmtTreeForExp();
            result = parseExp();
            currToken = get_cur_Token();
            newNode.exp = (ExpTree) result;

            currToken = Judge_Error_i();


            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.SEMICN)) {
            currToken = get_new_Token();
            subTree = new StmtTreeForExp();
        }
        //BLOCK 左大括号
        else if (isMatch(currToken, LexType.LBRACE)) {
            var newNode = new StmtTreeForBlock();

            result = parseBlock();
            currToken = get_cur_Token();
            newNode.block = (BlockTree) result;

            subTree = newNode;
        }

        else if (isMatch(currToken, LexType.IFTK)) {
            var newNode = new StmtTreeForIfElse();

            currToken = get_new_Token();
            currToken = parse_Single_get_new_token(currToken, LexType.LPARENT, new ParserException());

            result = parseCond();
            currToken = get_cur_Token();
            newNode.cond = (CondTree) result;

            currToken = Judge_Error_j();

            result = parseStmt();
            currToken = get_cur_Token();
            newNode.ifStmt = (StmtTree) result;

            if (isMatch(currToken, LexType.ELSETK)) {
                currToken = get_new_Token();

                result = parseStmt();
                currToken = get_cur_Token();
                newNode.elseStmt = (StmtTree) result;
            }

            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.FORTK)) {
            var newNode = new StmtTreeForLoop();

            currToken = get_new_Token();
            currToken = parse_Single_get_new_token(currToken, LexType.LPARENT, new ParserException());
            if (isMatch(currToken, LexType.IDENFR)) {
                result = parseForStmt();
                currToken = get_cur_Token();
                newNode.forStmt1 = (ForStmtTree) result;
            }

            currToken = parse_Single_get_new_token(currToken, LexType.SEMICN, new ParserException());


            if (isMatch(currToken, LexType.LPARENT)
                    || isMatch(currToken, LexType.IDENFR)
                    || isMatch(currToken, LexType.INTCON)
                    || isMatch(currToken, LexType.CHRCON)
                    || isMatch(currToken, LexType.PLUS)
                    || isMatch(currToken, LexType.MINU)
                    || isMatch(currToken, LexType.NOT)
            ) {
                result = parseCond();
                currToken = get_cur_Token();
                newNode.cond = (CondTree) result;
            }

            currToken = parse_Single_get_new_token(currToken, LexType.SEMICN, new ParserException());

            if (isMatch(currToken, LexType.IDENFR)) {
                result = parseForStmt();
                currToken = get_cur_Token();
                newNode.forStmt2 = (ForStmtTree) result;
            }

            currToken = parse_Single_get_new_token(currToken, LexType.RPARENT, new ParserException());
            result = parseStmt();
            currToken = get_cur_Token();
            newNode.stmt = (StmtTree) result;

            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.BREAKTK)) {
            var newNode = new StmtTreeForContinueBreak();
            newNode.tkLineNum = currToken.getLineNum();
            newNode.type = currToken.getLexType();

            currToken = get_new_Token();

            currToken = Judge_Error_i();


            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.CONTINUETK)) {
            var newNode = new StmtTreeForContinueBreak();
            newNode.tkLineNum = currToken.getLineNum();
            newNode.type = currToken.getLexType();

            currToken = get_new_Token();

            currToken = Judge_Error_i();


            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.RETURNTK)) {
            var newNode = new StmtTreeForReturn();
            newNode.returnLineNum = currToken.getLineNum();

            currToken = get_new_Token();
            if (isMatch(currToken, LexType.LPARENT)
                    || isMatch(currToken, LexType.IDENFR)
                    || isMatch(currToken, LexType.INTCON)
                    || isMatch(currToken, LexType.CHRCON)
                    || isMatch(currToken, LexType.PLUS)
                    || isMatch(currToken, LexType.MINU)
            ) {
                result = parseExp();
                currToken = get_cur_Token();
                newNode.exp = (ExpTree) result;
            }

            currToken = Judge_Error_i();


            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.PRINTFTK)) {
            var newNode = new StmtTreeForPrintf();
            newNode.printfLineNum = currToken.getLineNum();

            currToken = get_new_Token();
            currToken = parse_Single_get_new_token(currToken, LexType.LPARENT, new ParserException());

            newNode.formatString = currToken.getValue();
            currToken = parse_Single_get_new_token(currToken, LexType.STRCON, new ParserException());
            while (isMatch(currToken, LexType.COMMA)) {
                currToken = get_new_Token();

                result = parseExp();
                currToken = get_cur_Token();
                newNode.exps.add((ExpTree) result);
            }

            currToken = Judge_Error_j();

            currToken = Judge_Error_i();

            subTree = newNode;
        }
        else {
            throw new ParserException();
        }

        return subTree;
    }

    private Tree parseForStmt() throws ParserException {
        ForStmtTree subTree = new ForStmtTree();
        Tree result;

        result = parseLVal();
        currToken = get_cur_Token();
        subTree.lVal = (LValTree) result;

        currToken = parse_Single_get_new_token(currToken, LexType.ASSIGN, new ParserException());

        result = parseExp();
        currToken = get_cur_Token();
        subTree.exp = (ExpTree) result;

        return subTree;
    }

    private Tree parseExp() throws ParserException {
        ExpTree subTree = new ExpTree();
        Tree result;

        result = parseAddExp();
        currToken = get_cur_Token();
        subTree.addExp = (AddExpTree) result;

        return subTree;
    }

    private Tree parseCond() throws ParserException {
        CondTree subTree = new CondTree();
        Tree result;

        result = parseLOrExp();
        currToken = get_cur_Token();
        subTree.lOrExp = (LOrExpTree) result;

        return subTree;
    }

    private Tree parseLVal() throws ParserException {
        LValTree subTree = new LValTree();
        Tree result;

        subTree.ident = currToken.getValue();
        subTree.identLineNum = currToken.getLineNum();
        currToken = parse_Single_get_new_token(currToken, LexType.IDENFR, new ParserException());
        while (isMatch(currToken, LexType.LBRACK)) {
            currToken = get_new_Token();

            result = parseExp();
            currToken = get_cur_Token();
            subTree.dimensions.add((ExpTree) result);

            currToken = Judge_Error_k();
        }

        return subTree;
    }

    private Tree parsePrimaryExp() throws ParserException {
        PrimaryExpTree subTree;
        Tree result;

        if (isMatch(currToken, LexType.LPARENT)) {
            currToken = get_new_Token();

            var newNode = new PrimaryExpTreeForExp();
            result = parseExp();
            currToken = get_cur_Token();
            newNode.exp = (ExpTree) result;
            subTree = newNode;

            currToken = Judge_Error_j();
        } else if (isMatch(currToken, LexType.IDENFR)) {
            var newNode = new PrimaryExpTreeForLVal();
            result = parseLVal();
            currToken = get_cur_Token();
            newNode.lVal = (LValTree) result;
            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.INTCON)) {
            var newNode = new PrimaryExpTreeForNumber();
            result = parseNumber();
            currToken = get_cur_Token();
            newNode.number = (NumberTree) result;
            subTree = newNode;
        }

        else if(isMatch(currToken, LexType.CHRCON)) {
            //System.out.println(currToken.getValue());
            var newNode = new PrimaryExpTreeForCharacter();
            result = parseCharacter();
            currToken = get_cur_Token();
            newNode.character = (CharacterTree) result;
            subTree = newNode;
        }

        else {
            throw new ParserException();
        }

        return subTree;
    }

    private Tree parseNumber() throws ParserException {
        NumberTree subTree = new NumberTree();
        subTree.intConst = currToken.getValue();
        currToken = parse_Single_get_new_token(currToken, LexType.INTCON, new ParserException());

        return subTree;
    }

    private Tree parseCharacter() throws ParserException {
        CharacterTree subTree = new CharacterTree();
        subTree.charConst = currToken.getValue();
        currToken = parse_Single_get_new_token(currToken, LexType.CHRCON, new ParserException());

        return subTree;
    }

    private Tree parseString() throws ParserException {
        StringTree subTree = new StringTree();
        subTree.strConst = currToken.getValue();
        currToken = parse_Single_get_new_token(currToken, LexType.STRCON, new ParserException());

        return subTree;
    }

    private Tree parseUnaryExp() throws ParserException {
        UnaryExpTree subTree;
        Tree result;
        Token next_token = getNextToken();
        if (isMatch(currToken, LexType.LPARENT)
                || (isMatch(currToken, LexType.IDENFR)
                && isNotMatch(next_token, LexType.LPARENT))
                || isMatch(currToken, LexType.INTCON)
                || isMatch(currToken, LexType.CHRCON)
        ) {
            var newNode = new UnaryExpTreeForPrimaryExp();

            result = parsePrimaryExp();
            currToken = get_cur_Token();
            newNode.primaryExp = (PrimaryExpTree) result;

            subTree = newNode;
        } else if (isMatch(currToken, LexType.IDENFR) && isMatch(next_token, LexType.LPARENT)) {
            var newNode = new UnaryExpTreeForFuncCall();
            newNode.ident = currToken.getValue();
            newNode.identLineNum = currToken.getLineNum();

            currToken = parse_Single_get_new_token(currToken, LexType.IDENFR, new ParserException());
            currToken = parse_Single_get_new_token(currToken, LexType.LPARENT, new ParserException());
            if (isMatch(currToken, LexType.LPARENT)
                    || isMatch(currToken, LexType.IDENFR)
                    || isMatch(currToken, LexType.INTCON)
                    || isMatch(currToken, LexType.CHRCON)
                    || isMatch(currToken, LexType.PLUS)
                    || isMatch(currToken, LexType.MINU)
            ) {
                result = parseFuncRParams();
                currToken = get_cur_Token();
                newNode.params = (FuncRParamsTree) result;
            }

            currToken = Judge_Error_j();

            subTree = newNode;
        } else if (isMatch(currToken, LexType.PLUS)
                || isMatch(currToken, LexType.MINU)
                || isMatch(currToken, LexType.NOT)
        ) {
            var newNode = new UnaryExpTreeForUnaryOp();

            result = parseUnaryOp();
            currToken = get_cur_Token();
            newNode.op = (UnaryOpTree) result;

            result = parseUnaryExp();
            currToken = get_cur_Token();
            newNode.exp = (UnaryExpTree) result;

            subTree = newNode;
        } else {
            throw new ParserException();
        }

        return subTree;
    }

    private Tree parseUnaryOp() throws ParserException {
        UnaryOpTree subTree = new UnaryOpTree();

        if (isMatch(currToken, LexType.PLUS)
                || isMatch(currToken, LexType.MINU)
                || isMatch(currToken, LexType.NOT)
        ) {
            subTree.opType = currToken.getLexType();
            currToken = get_new_Token();
        } else {
            throw new ParserException();
        }

        return subTree;
    }

    private Tree parseFuncRParams() throws ParserException {
        FuncRParamsTree subTree = new FuncRParamsTree();
        Tree result;

        result = parseExp();
        currToken = get_cur_Token();
        subTree.exps.add((ExpTree) result);

        while (isMatch(currToken, LexType.COMMA)) {
            currToken = get_new_Token();

            result = parseExp();
            currToken = get_cur_Token();
            subTree.exps.add((ExpTree) result);
        }

        return subTree;
    }

    private Tree parseMulExp() throws ParserException {
        MulExpTree subTree = new MulExpTreeForSingle();
        Tree result;

        result = parseUnaryExp();
        currToken = get_cur_Token();
        ((MulExpTreeForSingle) subTree).unaryExp = (UnaryExpTree) result;

        while (isMatch(currToken, LexType.MULT) || isMatch(currToken, LexType.DIV) || isMatch(currToken, LexType.MOD)) {
            LexType op = currToken.getLexType();

            currToken = get_new_Token();
            result = parseUnaryExp();
            MulExpTreeForDouble newNode = new MulExpTreeForDouble();
            newNode.unaryExp = (UnaryExpTree) result;
            newNode.mulExp = subTree;
            newNode.op = op;
            subTree = newNode;

            currToken = get_cur_Token();
        }

        return subTree;
    }

    private Tree parseAddExp() throws ParserException {
        AddExpTree subTree = new AddExpTreeForSingle();
        Tree result;

        result = parseMulExp();
        currToken = get_cur_Token();
        ((AddExpTreeForSingle) subTree).mulExp = (MulExpTree) result;

        while (isMatch(currToken, LexType.PLUS) || isMatch(currToken, LexType.MINU)) {
            LexType op = currToken.getLexType();

            currToken = get_new_Token();
            result = parseMulExp();
            AddExpTreeForDouble newNode = new AddExpTreeForDouble();
            newNode.mulExp = (MulExpTree) result;
            newNode.addExp = subTree;
            newNode.op = op;
            subTree = newNode;

            currToken = get_cur_Token();
        }

        return subTree;
    }

    private Tree parseRelExp() throws ParserException {
        RelExpTree subTree = new RelExpTreeForSingle();
        Tree result;

        result = parseAddExp();
        currToken = get_cur_Token();
        ((RelExpTreeForSingle) subTree).addExp = (AddExpTree) result;

        while (isMatch(currToken, LexType.LSS)
                || isMatch(currToken, LexType.GRE)
                || isMatch(currToken, LexType.LEQ)
                || isMatch(currToken, LexType.GEQ)
        ) {
            LexType op = currToken.getLexType();
            currToken = get_new_Token();

            result = parseAddExp();
            currToken = get_cur_Token();
            RelExpTreeForDouble newNode = new RelExpTreeForDouble();
            newNode.addExp = (AddExpTree) result;
            newNode.relExp = subTree;
            newNode.op = op;
            subTree = newNode;
        }

        return subTree;
    }

    private Tree parseEqExp() throws ParserException {
        EqExpTree subTree = new EqExpTreeForSingle();
        Tree result;

        result = parseRelExp();
        currToken = get_cur_Token();
        ((EqExpTreeForSingle) subTree).relExp = (RelExpTree) result;

        while (isMatch(currToken, LexType.EQL) || isMatch(currToken, LexType.NEQ)) {
            LexType op = currToken.getLexType();
            currToken = get_new_Token();

            result = parseRelExp();
            currToken = get_cur_Token();
            EqExpTreeForDouble newNode = new EqExpTreeForDouble();
            newNode.relExp = (RelExpTree) result;
            newNode.eqExp = subTree;
            newNode.op = op;
            subTree = newNode;
        }

        return subTree;
    }

    private Tree parseLAndExp() throws ParserException {
        LAndExpTree subTree = new LAndExpTreeForSingle();
        Tree result;

        result = parseEqExp();
        currToken = get_cur_Token();
        ((LAndExpTreeForSingle) subTree).eqExp = (EqExpTree) result;

        while (isMatch(currToken, LexType.AND)) {
            currToken = get_new_Token();

            result = parseEqExp();
            currToken = get_cur_Token();
            LAndExpTreeForDouble newNode = new LAndExpTreeForDouble();
            newNode.eqExp = (EqExpTree) result;
            newNode.lAndExp = subTree;
            subTree = newNode;
        }

        return subTree;
    }

    private Tree parseLOrExp() throws ParserException {
        LOrExpTree subTree = new LOrExpTreeForSingle();
        Tree result;

        result = parseLAndExp();
        currToken = get_cur_Token();
        ((LOrExpTreeForSingle) subTree).lAndExp = (LAndExpTree) result;

        while (isMatch(currToken, LexType.OR)) {
            currToken = get_new_Token();

            result = parseLAndExp();
            currToken = get_cur_Token();
            LOrExpTreeForDouble newNode = new LOrExpTreeForDouble();
            newNode.lAndExp = (LAndExpTree) result;
            newNode.lOrExp = subTree;
            subTree = newNode;
        }

        return subTree;
    }

    private Tree parseConstExp() throws ParserException {
        ConstExpTree subTree = new ConstExpTree();
        Tree result;

        result = parseAddExp();
        currToken = get_cur_Token();
        subTree.addExp = (AddExpTree) result;

        return subTree;
    }
    
    

    public List<Error> getErrors() {
        return errors;
    }
}
