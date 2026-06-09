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


    public Parser(List<Token> tokens) {
        this.tokens = tokens;
        this.errors = new ArrayList<>();
        //listIterator = tokens.listIterator();
    }

    public Token get_new_Token() {
        if(currTokenPos + 1 < tokens.size()) {
            currTokenPos ++;
            //System.out.println(tokens.get(currTokenPos).getValue()+" "+tokens.get(currTokenPos).getLineNum());
            return tokens.get(currTokenPos);
        }
        return null;
    }

    public Token Judge_Error_i(Token currToken)
    {
        if (isMatch(currToken, LexType.SEMICN)) {
            return get_new_Token();
        } else {
            Token beforeToken = tokens.get(currTokenPos-1);
            errors.add(new Error(beforeToken.getLineNum(), ErrorType.i));
//            if(currToken.getLineNum()>beforeToken.getLineNum()) {
//                errors.add(new Error(currToken.getLineNum()-1, ErrorType.i));
//            }
//            else if(currToken.getLineNum()==beforeToken.getLineNum()) {
//                errors.add(new Error(currToken.getLineNum(), ErrorType.i));
//            }
            return currToken;
        }
    }

    public Token Judge_Error_j(Token currToken)
    {
        if (isMatch(currToken, LexType.RPARENT)) {
            return get_new_Token();
        } else {
            Token beforeToken = tokens.get(currTokenPos-1);
            errors.add(new Error(beforeToken.getLineNum(), ErrorType.j));
//            if(currToken.getLineNum()>beforeToken.getLineNum()) {
//                errors.add(new Error(currToken.getLineNum()-1, ErrorType.j));
//            }
//            else if(currToken.getLineNum()==beforeToken.getLineNum()) {
//                errors.add(new Error(currToken.getLineNum(), ErrorType.j));
//            }
            return currToken;
        }
    }

    public Token Judge_Error_k(Token currToken)
    {
        if (isMatch(currToken, LexType.RBRACK)) {
            return get_new_Token();
        } else {
            Token beforeToken = tokens.get(currTokenPos-1);
            errors.add(new Error(beforeToken.getLineNum(), ErrorType.k));
//            if(currToken.getLineNum()>beforeToken.getLineNum()) {
//                errors.add(new Error(currToken.getLineNum()-1, ErrorType.k));
//            }
//            else if(currToken.getLineNum()==beforeToken.getLineNum()) {
//                errors.add(new Error(currToken.getLineNum(), ErrorType.k));
//            }
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



    private Token parse_Single_get_new_token(Token token, LexType type, ParserException e) throws LexerException, ParserException {
        if(isMatch(token, type)) {
            return get_new_Token();
        }
        else {
            throw e;
        }
    }

    private Token parse_Single_for_main(Token token, LexType type) throws LexerException, ParserException {
        if(isMatch(token, type)) {
            return get_new_Token();
        }
        else {
            return null;
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



    public Tree parse() throws LexerException, ParserException {
        Token currToken = tokens.get(currTokenPos);
        ParseResult result = parseCompUnit(currToken);
        currToken = result.getNextToken();
        if(currToken != null)
        {
            throw new ParserException("Unexpected token '" + currToken.getLexType() + "'.");
        }
       // matchOrThrow(currToken, null, new ParserException());  // if not reach end

        return result.getSubtree();

    }

    private ParseResult parseCompUnit(Token currToken) throws LexerException, ParserException {
        CompUnitTree subTree = new CompUnitTree();
        ParseResult result;
        Token preRead, prePreRead;

        preRead = getNextToken();
        prePreRead = getNext_NextToken();
        while (isMatch(currToken, LexType.CONSTTK)
                || (isMatch(currToken, LexType.INTTK)
                && isMatch(preRead, LexType.IDENFR)
                && isNotMatch(prePreRead, LexType.LPARENT)
        )|| isMatch(currToken, LexType.CHARTK)
        ) {
            //为什么要倒一下
            result = parseDecl(currToken);
            currToken = result.getNextToken();
            subTree.declares.add((DeclTree) result.getSubtree());

            preRead = getNextToken();
            prePreRead = getNext_NextToken();
        }

        preRead = getNextToken();
        while (isMatch(currToken, LexType.VOIDTK)
                || (isMatch(currToken, LexType.INTTK)
                && isMatch(preRead, LexType.IDENFR)
                || isMatch(currToken, LexType.CHARTK))
        ) {
            result = parseFuncDef(currToken);
            currToken = result.getNextToken();
            subTree.funcs.add((FuncDefTree) result.getSubtree());

            preRead = getNextToken();
        }

        result = parseMainFuncDef(currToken);
        currToken = result.getNextToken();
        subTree.mainFunc = (MainFuncDefTree) result.getSubtree();

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseFuncDef(Token currToken) throws LexerException, ParserException {
        FuncDefTree subTree = new FuncDefTree();
        ParseResult result;

        //Functype
        result = parseFuncType(currToken);
        currToken = result.getNextToken();
        subTree.funcType = (FuncTypeTree) result.getSubtree();

        subTree.ident = currToken.getValue();
        subTree.identLineNum = currToken.getLineNum();

        //ident 简约判断的同时移动到下一个
        currToken = parse_Single_get_new_token(currToken, LexType.IDENFR, new ParserException());
        //'('
        currToken = parse_Single_get_new_token(currToken, LexType.LPARENT, new ParserException());
        //'FuncFParams'
        if (isMatch(currToken, LexType.INTTK) || isMatch(currToken, LexType.CHARTK)) {
            result = parseFuncFParams(currToken);
            currToken = result.getNextToken();
            subTree.params = (FuncFParamsTree) result.getSubtree();
        }

        //')'
        currToken = Judge_Error_j(currToken);

        result = parseBlock(currToken);
        subTree.block = (BlockTree) result.getSubtree();
        currToken = result.getNextToken();

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseFuncFParams(Token currToken) throws LexerException, ParserException {
        ParseResult result;
        FuncFParamsTree subTree = new FuncFParamsTree();

        result = parseFuncFParam(currToken);
        currToken = result.getNextToken();
        subTree.params.add((FuncFParamTree) result.getSubtree());

        while (isMatch(currToken, LexType.COMMA)) {
            currToken = get_new_Token();
            result = parseFuncFParam(currToken);
            subTree.params.add((FuncFParamTree) result.getSubtree());

            currToken = result.getNextToken();
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseFuncFParam(Token currToken) throws LexerException, ParserException {
        FuncFParamTree subTree = new FuncFParamTree();
        ParseResult result;

        result = parseBType(currToken);
        currToken = result.getNextToken();
        subTree.type = (BTypeTree) result.getSubtree();

        subTree.ident = currToken.getValue();
        subTree.identLineNum = currToken.getLineNum();
        currToken = parse_Single_get_new_token(currToken, LexType.IDENFR, new ParserException());
        if (isMatch(currToken, LexType.LBRACK)) {
            subTree.dimensions = new ArrayList<>();
            currToken = get_new_Token();

            currToken = Judge_Error_k(currToken);

            //多维数组的可能性
        }
        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseConstExp(Token currToken) throws LexerException, ParserException {
        ConstExpTree subTree = new ConstExpTree();
        ParseResult result;

        result = parseAddExp(currToken);
        currToken = result.getNextToken();
        subTree.addExp = (AddExpTree) result.getSubtree();

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseAddExp(Token currToken) throws LexerException, ParserException {
        AddExpTree subTree = new AddExpTreeForSingle();
        ParseResult result;

        result = parseMulExp(currToken);
        currToken = result.getNextToken();
        ((AddExpTreeForSingle) subTree).mulExp = (MulExpTree) result.getSubtree();

        while (isMatch(currToken, LexType.PLUS) || isMatch(currToken, LexType.MINU)) {
            LexType op = currToken.getLexType();

            currToken = get_new_Token();
            result = parseMulExp(currToken);
            AddExpTreeForDouble newNode = new AddExpTreeForDouble();
            newNode.mulExp = (MulExpTree) result.getSubtree();
            newNode.addExp = subTree;
            newNode.op = op;
            subTree = newNode;

            currToken = result.getNextToken();
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseMulExp(Token currToken) throws LexerException, ParserException {
        MulExpTree subTree = new MulExpTreeForSingle();
        ParseResult result;

        result = parseUnaryExp(currToken);
        currToken = result.getNextToken();
        ((MulExpTreeForSingle) subTree).unaryExp = (UnaryExpTree) result.getSubtree();

        while (isMatch(currToken, LexType.MULT) || isMatch(currToken, LexType.DIV) || isMatch(currToken, LexType.MOD)) {
            LexType op = currToken.getLexType();

            currToken = get_new_Token();
            result = parseUnaryExp(currToken);
            MulExpTreeForDouble newNode = new MulExpTreeForDouble();
            newNode.unaryExp = (UnaryExpTree) result.getSubtree();
            newNode.mulExp = subTree;
            newNode.op = op;
            subTree = newNode;

            currToken = result.getNextToken();
        }

        return new ParseResult(currToken, subTree);
    }


    private ParseResult parseUnaryExp(Token currToken) throws LexerException, ParserException {
        UnaryExpTree subTree;
        ParseResult result;
        Token preRead = getNextToken();
        if (isMatch(currToken, LexType.LPARENT)
                || (isMatch(currToken, LexType.IDENFR)
                && isNotMatch(preRead, LexType.LPARENT))
                || isMatch(currToken, LexType.INTCON)
                || isMatch(currToken, LexType.CHRCON)
        ) {
            var newNode = new UnaryExpTreeForPrimaryExp();

            result = parsePrimaryExp(currToken);
            currToken = result.getNextToken();
            newNode.primaryExp = (PrimaryExpTree) result.getSubtree();

            subTree = newNode;
        } else if (isMatch(currToken, LexType.IDENFR) && isMatch(preRead, LexType.LPARENT)) {
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
                result = parseFuncRParams(currToken);
                currToken = result.getNextToken();
                newNode.params = (FuncRParamsTree) result.getSubtree();
            }

            currToken = Judge_Error_j(currToken);

            subTree = newNode;
        } else if (isMatch(currToken, LexType.PLUS)
                || isMatch(currToken, LexType.MINU)
                || isMatch(currToken, LexType.NOT)
        ) {
            var newNode = new UnaryExpTreeForUnaryOp();

            result = parseUnaryOp(currToken);
            currToken = result.getNextToken();
            newNode.op = (UnaryOpTree) result.getSubtree();

            result = parseUnaryExp(currToken);
            currToken = result.getNextToken();
            newNode.exp = (UnaryExpTree) result.getSubtree();

            subTree = newNode;
        } else {
            throw new ParserException();
        }

        return new ParseResult(currToken, subTree);
    }


    private ParseResult parseUnaryOp(Token currToken) throws LexerException, ParserException {
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

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseFuncRParams(Token currToken) throws LexerException, ParserException {
        FuncRParamsTree subTree = new FuncRParamsTree();
        ParseResult result;

        result = parseExp(currToken);
        currToken = result.getNextToken();
        subTree.exps.add((ExpTree) result.getSubtree());

        while (isMatch(currToken, LexType.COMMA)) {
            currToken = get_new_Token();

            result = parseExp(currToken);
            currToken = result.getNextToken();
            subTree.exps.add((ExpTree) result.getSubtree());
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseExp(Token currToken) throws LexerException, ParserException {
        ExpTree subTree = new ExpTree();
        ParseResult result;

        result = parseAddExp(currToken);
        currToken = result.getNextToken();
        subTree.addExp = (AddExpTree) result.getSubtree();

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parsePrimaryExp(Token currToken) throws LexerException, ParserException {
        PrimaryExpTree subTree;
        ParseResult result;

        if (isMatch(currToken, LexType.LPARENT)) {
            currToken = get_new_Token();

            var newNode = new PrimaryExpTreeForExp();
            result = parseExp(currToken);
            currToken = result.getNextToken();
            newNode.exp = (ExpTree) result.getSubtree();
            subTree = newNode;

            currToken = Judge_Error_j(currToken);
        } else if (isMatch(currToken, LexType.IDENFR)) {
            var newNode = new PrimaryExpTreeForLVal();
            result = parseLVal(currToken);
            currToken = result.getNextToken();
            newNode.lVal = (LValTree) result.getSubtree();
            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.INTCON)) {
            var newNode = new PrimaryExpTreeForNumber();
            result = parseNumber(currToken);
            currToken = result.getNextToken();
            newNode.number = (NumberTree) result.getSubtree();
            subTree = newNode;
        }

        else if(isMatch(currToken, LexType.CHRCON)) {
            //System.out.println(currToken.getValue());
            var newNode = new PrimaryExpTreeForCharacter();
            result = parseCharacter(currToken);
            currToken = result.getNextToken();
            newNode.character = (CharacterTree) result.getSubtree();
            subTree = newNode;
        }

        else {
            throw new ParserException();
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseLVal(Token currToken) throws LexerException, ParserException {
        LValTree subTree = new LValTree();
        ParseResult result;

        subTree.ident = currToken.getValue();
        subTree.identLineNum = currToken.getLineNum();
        currToken = parse_Single_get_new_token(currToken, LexType.IDENFR, new ParserException());
        while (isMatch(currToken, LexType.LBRACK)) {
            currToken = get_new_Token();

            result = parseExp(currToken);
            currToken = result.getNextToken();
            subTree.dimensions.add((ExpTree) result.getSubtree());

            currToken = Judge_Error_k(currToken);
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseNumber(Token currToken) throws LexerException, ParserException {
        NumberTree subTree = new NumberTree();
        subTree.intConst = currToken.getValue();
        currToken = parse_Single_get_new_token(currToken, LexType.INTCON, new ParserException());

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseCharacter(Token currToken) throws LexerException, ParserException {
        CharacterTree subTree = new CharacterTree();
        subTree.charConst = currToken.getValue();
        currToken = parse_Single_get_new_token(currToken, LexType.CHRCON, new ParserException());

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseString(Token currToken) throws LexerException, ParserException {
        StringTree subTree = new StringTree();
        subTree.strConst = currToken.getValue();
        currToken = parse_Single_get_new_token(currToken, LexType.STRCON, new ParserException());

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseBType(Token currToken) throws LexerException, ParserException {

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
        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseBlock(Token currToken) throws LexerException, ParserException {
        BlockTree subTree = new BlockTree();
        ParseResult result;

        currToken = parse_Single_get_new_token(currToken, LexType.LBRACE, new ParserException());
        while (isNotMatch(currToken, LexType.RBRACE)) {
            result = parseBlockItem(currToken);
            currToken = result.getNextToken();
            subTree.blockItems.add((BlockItemTree) result.getSubtree());
        }
        subTree.blockRLineNum = currToken.getLineNum();
        currToken = get_new_Token();

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseBlockItem(Token currToken) throws LexerException, ParserException {
        BlockItemTree subTree;
        ParseResult result;

        if (isMatch(currToken, LexType.INTTK) || isMatch(currToken, LexType.CONSTTK) || isMatch(currToken, LexType.CHARTK)) {
            var newNode = new BlockItemTreeForDecl();

            result = parseDecl(currToken);
            currToken = result.getNextToken();
            newNode.decl = (DeclTree) result.getSubtree();

            subTree = newNode;
        } else {
            var newNode = new BlockItemTreeForStmt();

            result = parseStmt(currToken);
            currToken = result.getNextToken();
            newNode.stmt = (StmtTree) result.getSubtree();

            subTree = newNode;
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseStmt(Token currToken) throws LexerException, ParserException {
        StmtTree subTree;
        ParseResult result;

        //System.out.println(currToken.getValue()+" "+ currToken.getLineNum());
        Token preRead = getNextToken();
        if (isMatch(currToken, LexType.IDENFR)
                && (findUntil(LexType.ASSIGN, LexType.SEMICN))
        ) {
            LValTree tmpLVal;
            result = parseLVal(currToken);
            currToken = result.getNextToken();
            tmpLVal = (LValTree) result.getSubtree();

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

                currToken = Judge_Error_j(currToken);

                currToken = Judge_Error_i(currToken);

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
                result = parseExp(currToken);
                currToken = result.getNextToken();
                newNode.exp = (ExpTree) result.getSubtree();
                newNode.lVal = tmpLVal;

                currToken = Judge_Error_i(currToken);


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
            result = parseExp(currToken);
            currToken = result.getNextToken();
            newNode.exp = (ExpTree) result.getSubtree();

            currToken = Judge_Error_i(currToken);


            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.SEMICN)) {
            currToken = get_new_Token();
            subTree = new StmtTreeForExp();
        }
        //BLOCK 左大括号
        else if (isMatch(currToken, LexType.LBRACE)) {
            var newNode = new StmtTreeForBlock();

            result = parseBlock(currToken);
            currToken = result.getNextToken();
            newNode.block = (BlockTree) result.getSubtree();

            subTree = newNode;
        }

        else if (isMatch(currToken, LexType.IFTK)) {
            var newNode = new StmtTreeForIfElse();

            currToken = get_new_Token();
            currToken = parse_Single_get_new_token(currToken, LexType.LPARENT, new ParserException());

            result = parseCond(currToken);
            currToken = result.getNextToken();
            newNode.cond = (CondTree) result.getSubtree();

            currToken = Judge_Error_j(currToken);

            result = parseStmt(currToken);
            currToken = result.getNextToken();
            newNode.ifStmt = (StmtTree) result.getSubtree();

            if (isMatch(currToken, LexType.ELSETK)) {
                currToken = get_new_Token();

                result = parseStmt(currToken);
                currToken = result.getNextToken();
                newNode.elseStmt = (StmtTree) result.getSubtree();
            }

            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.FORTK)) {
            var newNode = new StmtTreeForLoop();

            currToken = get_new_Token();
            currToken = parse_Single_get_new_token(currToken, LexType.LPARENT, new ParserException());
            if (isMatch(currToken, LexType.IDENFR)) {
                result = parseForStmt(currToken);
                currToken = result.getNextToken();
                newNode.forStmt1 = (ForStmtTree) result.getSubtree();
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
                result = parseCond(currToken);
                currToken = result.getNextToken();
                newNode.cond = (CondTree) result.getSubtree();
            }

            currToken = parse_Single_get_new_token(currToken, LexType.SEMICN, new ParserException());

            if (isMatch(currToken, LexType.IDENFR)) {
                result = parseForStmt(currToken);
                currToken = result.getNextToken();
                newNode.forStmt2 = (ForStmtTree) result.getSubtree();
            }

            currToken = parse_Single_get_new_token(currToken, LexType.RPARENT, new ParserException());
            result = parseStmt(currToken);
            currToken = result.getNextToken();
            newNode.stmt = (StmtTree) result.getSubtree();

            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.BREAKTK)) {
            var newNode = new StmtTreeForContinueBreak();
            newNode.tkLineNum = currToken.getLineNum();
            newNode.type = currToken.getLexType();

            currToken = get_new_Token();

            currToken = Judge_Error_i(currToken);


            subTree = newNode;
        }
        else if (isMatch(currToken, LexType.CONTINUETK)) {
            var newNode = new StmtTreeForContinueBreak();
            newNode.tkLineNum = currToken.getLineNum();
            newNode.type = currToken.getLexType();

            currToken = get_new_Token();

            currToken = Judge_Error_i(currToken);


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
                result = parseExp(currToken);
                currToken = result.getNextToken();
                newNode.exp = (ExpTree) result.getSubtree();
            }

            currToken = Judge_Error_i(currToken);


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

                result = parseExp(currToken);
                currToken = result.getNextToken();
                newNode.exps.add((ExpTree) result.getSubtree());
            }

            currToken = Judge_Error_j(currToken);

            currToken = Judge_Error_i(currToken);

            subTree = newNode;
        }
        else {
            throw new ParserException();
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseCond(Token currToken) throws LexerException, ParserException {
        CondTree subTree = new CondTree();
        ParseResult result;

        result = parseLOrExp(currToken);
        currToken = result.getNextToken();
        subTree.lOrExp = (LOrExpTree) result.getSubtree();

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseLOrExp(Token currToken) throws LexerException, ParserException {
        LOrExpTree subTree = new LOrExpTreeForSingle();
        ParseResult result;

        result = parseLAndExp(currToken);
        currToken = result.getNextToken();
        ((LOrExpTreeForSingle) subTree).lAndExp = (LAndExpTree) result.getSubtree();

        while (isMatch(currToken, LexType.OR)) {
            currToken = get_new_Token();

            result = parseLAndExp(currToken);
            currToken = result.getNextToken();
            LOrExpTreeForDouble newNode = new LOrExpTreeForDouble();
            newNode.lAndExp = (LAndExpTree) result.getSubtree();
            newNode.lOrExp = subTree;
            subTree = newNode;
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseLAndExp(Token currToken) throws LexerException, ParserException {
        LAndExpTree subTree = new LAndExpTreeForSingle();
        ParseResult result;

        result = parseEqExp(currToken);
        currToken = result.getNextToken();
        ((LAndExpTreeForSingle) subTree).eqExp = (EqExpTree) result.getSubtree();

        while (isMatch(currToken, LexType.AND)) {
            currToken = get_new_Token();

            result = parseEqExp(currToken);
            currToken = result.getNextToken();
            LAndExpTreeForDouble newNode = new LAndExpTreeForDouble();
            newNode.eqExp = (EqExpTree) result.getSubtree();
            newNode.lAndExp = subTree;
            subTree = newNode;
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseEqExp(Token currToken) throws LexerException, ParserException {
        EqExpTree subTree = new EqExpTreeForSingle();
        ParseResult result;

        result = parseRelExp(currToken);
        currToken = result.getNextToken();
        ((EqExpTreeForSingle) subTree).relExp = (RelExpTree) result.getSubtree();

        while (isMatch(currToken, LexType.EQL) || isMatch(currToken, LexType.NEQ)) {
            LexType op = currToken.getLexType();
            currToken = get_new_Token();

            result = parseRelExp(currToken);
            currToken = result.getNextToken();
            EqExpTreeForDouble newNode = new EqExpTreeForDouble();
            newNode.relExp = (RelExpTree) result.getSubtree();
            newNode.eqExp = subTree;
            newNode.op = op;
            subTree = newNode;
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseRelExp(Token currToken) throws LexerException, ParserException {
        RelExpTree subTree = new RelExpTreeForSingle();
        ParseResult result;

        result = parseAddExp(currToken);
        currToken = result.getNextToken();
        ((RelExpTreeForSingle) subTree).addExp = (AddExpTree) result.getSubtree();

        while (isMatch(currToken, LexType.LSS)
                || isMatch(currToken, LexType.GRE)
                || isMatch(currToken, LexType.LEQ)
                || isMatch(currToken, LexType.GEQ)
        ) {
            LexType op = currToken.getLexType();
            currToken = get_new_Token();

            result = parseAddExp(currToken);
            currToken = result.getNextToken();
            RelExpTreeForDouble newNode = new RelExpTreeForDouble();
            newNode.addExp = (AddExpTree) result.getSubtree();
            newNode.relExp = subTree;
            newNode.op = op;
            subTree = newNode;
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseForStmt(Token currToken) throws LexerException, ParserException {
        ForStmtTree subTree = new ForStmtTree();
        ParseResult result;

        result = parseLVal(currToken);
        currToken = result.getNextToken();
        subTree.lVal = (LValTree) result.getSubtree();

        currToken = parse_Single_get_new_token(currToken, LexType.ASSIGN, new ParserException());

        result = parseExp(currToken);
        currToken = result.getNextToken();
        subTree.exp = (ExpTree) result.getSubtree();

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseFuncType(Token currToken) throws LexerException, ParserException {
        FuncTypeTree subTree = new FuncTypeTree();

        if (isMatch(currToken, LexType.VOIDTK) || isMatch(currToken, LexType.INTTK) || isMatch(currToken, LexType.CHARTK)) {
            subTree.type = currToken.getLexType();

            currToken = get_new_Token();
        } else {
            throw new ParserException();
        }
        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseDecl(Token currToken) throws LexerException, ParserException {
        DeclTree subTree;
        ParseResult result;

        if (isMatch(currToken, LexType.CONSTTK)) {
            var newNode = new DeclTreeForConstDecl();

            result = parseConstDecl(currToken);
            currToken = result.getNextToken();
            newNode.constDecl = (ConstDeclTree) result.getSubtree();

            subTree = newNode;
        } else if (isMatch(currToken, LexType.INTTK) || isMatch(currToken, LexType.CHARTK)) {
            var newNode = new DeclTreeForVarDecl();

            result = parseVarDecl(currToken);
            currToken = result.getNextToken();
            newNode.varDecl = (VarDeclTree) result.getSubtree();

            subTree = newNode;
        } else {
            throw new ParserException();
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseConstDecl(Token currToken) throws LexerException, ParserException {
        ConstDeclTree subTree = new ConstDeclTree();
        ParseResult result;

        currToken = parse_Single_get_new_token(currToken, LexType.CONSTTK, new ParserException());

        result = parseBType(currToken);
        currToken = result.getNextToken();
        subTree.type = (BTypeTree) result.getSubtree();

        result = parseConstDef(currToken);
        currToken = result.getNextToken();
        subTree.constDefs.add((ConstDefTree) result.getSubtree());

        while (isMatch(currToken, LexType.COMMA)) {
            currToken = get_new_Token();

            result = parseConstDef(currToken);
            currToken = result.getNextToken();
            subTree.constDefs.add((ConstDefTree) result.getSubtree());
        }

        currToken = Judge_Error_i(currToken);

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseConstDef(Token currToken) throws LexerException, ParserException {
        ConstDefTree subTree = new ConstDefTree();
        ParseResult result;

        subTree.ident = currToken.getValue();
        subTree.identLineNum = currToken.getLineNum();
        currToken = parse_Single_get_new_token(currToken, LexType.IDENFR, new ParserException());
        while (isMatch(currToken, LexType.LBRACK)) {
            currToken = get_new_Token();

            result = parseConstExp(currToken);
            currToken = result.getNextToken();
            subTree.dimensions.add((ConstExpTree) result.getSubtree());

            currToken = Judge_Error_k(currToken);
        }
        currToken = parse_Single_get_new_token(currToken, LexType.ASSIGN, new ParserException());

        result = parseConstInitVal(currToken);
        currToken = result.getNextToken();
        subTree.constInitVal = (ConstInitValTree) result.getSubtree();

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseConstInitVal(Token currToken) throws LexerException, ParserException {
        ConstInitValTree subTree;
        ParseResult result;

        //System.out.println(currToken.getValue());

        if (isMatch(currToken, LexType.LPARENT)
                || isMatch(currToken, LexType.IDENFR)
                || isMatch(currToken, LexType.INTCON)
                || isMatch(currToken, LexType.CHRCON)
                || isMatch(currToken, LexType.PLUS)
                || isMatch(currToken, LexType.MINU)
        ) {
            var newNode = new ConstInitValTreeForConstExp();

            result = parseConstExp(currToken);
            currToken = result.getNextToken();
            newNode.constExp = (ConstExpTree) result.getSubtree();

            subTree = newNode;
        } else if (isMatch(currToken, LexType.LBRACE)) {
            var newNode = new ConstInitValTreeForArrayInit();

            currToken = get_new_Token();
            if (isNotMatch(currToken, LexType.RBRACE)) {
                result = parseConstExp(currToken);
                currToken = result.getNextToken();
                newNode.constExpTrees.add((ConstExpTree) result.getSubtree());

                while (isMatch(currToken, LexType.COMMA)) {
                    currToken = get_new_Token();

                    result = parseConstExp(currToken);
                    currToken = result.getNextToken();
                    newNode.constExpTrees.add((ConstExpTree) result.getSubtree());
                }

            }
            currToken = parse_Single_get_new_token(currToken, LexType.RBRACE, new ParserException());

            subTree = newNode;
        }

        else if(isMatch(currToken, LexType.STRCON)) {

            var newNode = new ConstInitValTreeForStringConst();
            result = parseString(currToken);
            currToken = result.getNextToken();
            newNode.string = (StringTree) result.getSubtree();
            subTree = newNode;
        }
        else {
            throw new ParserException();
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseVarDecl(Token currToken) throws LexerException, ParserException {

        VarDeclTree subTree = new VarDeclTree();
        ParseResult result;

        result = parseBType(currToken);
        currToken = result.getNextToken();
        subTree.type = (BTypeTree) result.getSubtree();

        result = parseVarDef(currToken);
        currToken = result.getNextToken();
        subTree.varDefs.add((VarDefTree) result.getSubtree());

        while (isMatch(currToken, LexType.COMMA)) {
            currToken = get_new_Token();

            result = parseVarDef(currToken);
            currToken = result.getNextToken();
            subTree.varDefs.add((VarDefTree) result.getSubtree());
        }

        currToken = Judge_Error_i(currToken);

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseVarDef(Token currToken) throws LexerException, ParserException {
        VarDefTree subTree = new VarDefTree();
        ParseResult result;

        subTree.ident = currToken.getValue();
        subTree.identLineNum = currToken.getLineNum();
        currToken = parse_Single_get_new_token(currToken, LexType.IDENFR, new ParserException());
        while (isMatch(currToken, LexType.LBRACK)) {
            currToken = get_new_Token();

            result = parseConstExp(currToken);
            currToken = result.getNextToken();
            subTree.dimensions.add((ConstExpTree) result.getSubtree());

            currToken = Judge_Error_k(currToken);
        }
        if (isMatch(currToken, LexType.ASSIGN)) {
            currToken = get_new_Token();

            result = parseInitVal(currToken);
            currToken = result.getNextToken();
            subTree.initVal = (InitValTree) result.getSubtree();
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseInitVal(Token currToken) throws LexerException, ParserException {
        InitValTree subTree;
        ParseResult result;

        if (isMatch(currToken, LexType.LPARENT)
                || isMatch(currToken, LexType.IDENFR)
                || isMatch(currToken, LexType.INTCON)
                || isMatch(currToken, LexType.CHRCON)
                || isMatch(currToken, LexType.PLUS)
                || isMatch(currToken, LexType.MINU)
        ) {
            var newNode = new InitValTreeForExp();

            result = parseExp(currToken);
            currToken = result.getNextToken();
            newNode.exp = (ExpTree) result.getSubtree();

            subTree = newNode;
        } else if (isMatch(currToken, LexType.LBRACE)) {
            var newNode = new InitValTreeForArray();

            currToken = get_new_Token();
            if (isNotMatch(currToken, LexType.RBRACK)) {
                result = parseExp(currToken);
                currToken = result.getNextToken();
                newNode.expTrees.add((ExpTree) result.getSubtree());

                while (isMatch(currToken, LexType.COMMA)) {
                    currToken = get_new_Token();

                    result = parseExp(currToken);
                    currToken = result.getNextToken();
                    newNode.expTrees.add((ExpTree) result.getSubtree());
                }
            }
            currToken = parse_Single_get_new_token(currToken, LexType.RBRACE, new ParserException());

            subTree = newNode;
        }

        else if(isMatch(currToken, LexType.STRCON)) {

            var newNode = new InitValTreeForStringConst();
            result = parseString(currToken);
            currToken = result.getNextToken();
            newNode.string = (StringTree) result.getSubtree();
            subTree = newNode;
        }

        else {
            throw new ParserException();
        }

        return new ParseResult(currToken, subTree);
    }

    private ParseResult parseMainFuncDef(Token currToken) throws LexerException, ParserException {
        MainFuncDefTree subTree = new MainFuncDefTree();
        ParseResult result;

        currToken = parse_Single_get_new_token(currToken, LexType.INTTK, new ParserException());
        currToken = parse_Single_get_new_token(currToken, LexType.MAINTK, new ParserException());
        currToken = parse_Single_get_new_token(currToken, LexType.LPARENT, new ParserException());

        currToken = Judge_Error_j(currToken);

        result = parseBlock(currToken);
        currToken = result.getNextToken();
        subTree.mainBlock = (BlockTree) result.getSubtree();

        return new ParseResult(currToken, subTree);
    }




    class ParseResult {
        private final Token nextToken;
        private final Tree subtree;

        public ParseResult(Token nextToken, Tree subtree) {
            this.nextToken = nextToken;
            this.subtree = subtree;
        }

        public Token getNextToken() {
            return nextToken;
        }

        public Tree getSubtree() {
            return subtree;
        }
    }

    public List<Error> getErrors() {
        return errors;
    }
}
