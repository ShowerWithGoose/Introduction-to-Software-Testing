import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class Parser {
    private static BufferedWriter os;
    private List<Token> tokenList;
    private List<Error> errorList;
    private int currentTokenIndex=0;

    static {
        try {
            os = new BufferedWriter(new FileWriter("parser.txt"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Parser(List<Token> tokenList,List<Error> errorList){
        this.tokenList=tokenList;
        this.errorList=errorList;
    }

    //编译单元
    public void parseCompUnit(){
        while (currentTokenIndex < tokenList.size()) {
            if (tokenList.get(currentTokenIndex).getType()== TokenType.CONSTTK ) {
                parseDecl();
            } else if (tokenList.get(currentTokenIndex).getType()== TokenType.INTTK) {
                if(currentTokenIndex+1<tokenList.size()&&tokenList.get(currentTokenIndex+1).getType()==TokenType.MAINTK) {
                    parseMainFuncDef();
                    break;
                }
                else if (currentTokenIndex+2<tokenList.size()&&
                        tokenList.get(currentTokenIndex+1).getType()==TokenType.IDENFR&&
                        tokenList.get(currentTokenIndex+2).getType()==TokenType.LPARENT) {
                    parseFuncDef();
                }
                else {
                    parseDecl();
                }
            } else if (tokenList.get(currentTokenIndex).getType()== TokenType.VOIDTK) {
                parseFuncDef();
            }
            else if(tokenList.get(currentTokenIndex).getType()== TokenType.CHARTK){
                if (currentTokenIndex+2<tokenList.size()&&
                        tokenList.get(currentTokenIndex+1).getType()==TokenType.IDENFR&&
                        tokenList.get(currentTokenIndex+2).getType()==TokenType.LPARENT) {
                    parseFuncDef();
                }
                else {
                    parseDecl();
                }
            }
            else
                break;
        }
        writeSyntax("<CompUnit>");
        try {
            os.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //声明
    public void parseDecl(){

        if (currentTokenIndex < tokenList.size() &&
                tokenList.get(currentTokenIndex).getType() == TokenType.CONSTTK) {
            parseConstDecl();
        } else {
            parseVarDecl();
        }
    }

    //常量声明
    public void parseConstDecl(){
        expect(TokenType.CONSTTK);
        parseBType();
        parseConstDef();
        while (currentTokenIndex < tokenList.size()&&
                tokenList.get(currentTokenIndex).getType() == TokenType.COMMA) {
            expect(TokenType.COMMA);
            parseConstDef();
        }
        expect(TokenType.SEMICN);
        writeSyntax("<ConstDecl>");
    }

    //常量定义
    public void parseConstDef(){
        expect(TokenType.IDENFR);
        if (currentTokenIndex < tokenList.size()&&
                tokenList.get(currentTokenIndex).getType() == TokenType.LBRACK) {
            expect(TokenType.LBRACK);
            parseConstExp();
            expect(TokenType.RBRACK);
        }
        expect(TokenType.ASSIGN);
        parseConstInitVal();
        writeSyntax("<ConstDef>");
    }

    //常量初值
    public void parseConstInitVal(){
        if (currentTokenIndex < tokenList.size()) {

            Token currentToken = tokenList.get(currentTokenIndex);
            if (currentToken.getType() == TokenType.LBRACE) {
                expect(TokenType.LBRACE);

                if (currentTokenIndex < tokenList.size() &&
                        tokenList.get(currentTokenIndex).getType() != TokenType.RBRACE) {
                    parseConstExp();
                    while (currentTokenIndex < tokenList.size() &&
                            tokenList.get(currentTokenIndex).getType() == TokenType.COMMA) {
                        expect(TokenType.COMMA);
                        parseConstExp();
                    }
                }
                expect(TokenType.RBRACE);
            } else if (currentToken.getType() == TokenType.STRCON) {
                expect(TokenType.STRCON);
            } else {
                parseConstExp();
            }
        }
        writeSyntax("<ConstInitVal>");
    }

    //常量表达式
    public void parseConstExp(){
        parseAddExp();
        writeSyntax("<ConstExp>");
    }

    //基本类型
    public void parseBType(){
        Token currentToken = tokenList.get(currentTokenIndex);
        if (currentToken.getType() == TokenType.INTTK) {
            expect(TokenType.INTTK);
        } else if (currentToken.getType() == TokenType.CHARTK) {
            expect(TokenType.CHARTK);
        }
    }


    public void parseAddExp() {
        parseMulExp();

        while (currentTokenIndex < tokenList.size()&&
                (tokenList.get(currentTokenIndex).getType() == TokenType.PLUS ||
                tokenList.get(currentTokenIndex).getType() == TokenType.MINU)) {
            writeSyntax("<AddExp>");
            expect(tokenList.get(currentTokenIndex).getType());
            parseMulExp();
        }

        writeSyntax("<AddExp>");
    }

    public void parseMulExp() {
        parseUnaryExp();
        while (currentTokenIndex<tokenList.size()&&(tokenList.get(currentTokenIndex) .getType()== TokenType.MULT ||
                tokenList.get(currentTokenIndex).getType() == TokenType.DIV ||
                tokenList.get(currentTokenIndex).getType()== TokenType.MOD) ){
            writeSyntax("<MulExp>");
            expect(tokenList.get(currentTokenIndex).getType());
            parseUnaryExp();
        }

        writeSyntax("<MulExp>");
    }


    public void parseUnaryExp() {
        Token currentToken = tokenList.get(currentTokenIndex);
        if (currentToken.getType() == TokenType.IDENFR&&tokenList.get(currentTokenIndex+1).getType()==TokenType.LPARENT) {
            expect(TokenType.IDENFR);
            expect(TokenType.LPARENT);
            if(tokenList.get(currentTokenIndex).getType()!=TokenType.RPARENT) {
                parseFuncRParams();
            }
            expect(TokenType.RPARENT);
        }
        else if (currentToken.getType() == TokenType.PLUS || currentToken.getType() == TokenType.MINU || currentToken.getType() == TokenType.NOT) {
            parseUnaryOp(currentToken.getType());
            parseUnaryExp();
        }
        else {
            parsePrimaryExp();
        }

        writeSyntax("<UnaryExp>");
    }

    public void parseUnaryOp(TokenType  type){
        expect(type);
        writeSyntax("<UnaryOp>");
    }

    public void parseFuncRParams() {
        parseExp();

        while (currentTokenIndex<tokenList.size()&&
                tokenList.get(currentTokenIndex).getType() == TokenType.COMMA) {
            expect(TokenType.COMMA);
            parseExp();
        }

        writeSyntax("<FuncRParams>");
    }

    public void parsePrimaryExp() {
        if(currentTokenIndex<tokenList.size()) {
            Token currentToken = tokenList.get(currentTokenIndex);
            if (currentToken.getType() == TokenType.LPARENT) {
                expect(TokenType.LPARENT);
                parseExp();
                expect(TokenType.RPARENT);
            } else if (currentToken.getType() == TokenType.IDENFR) {
                parseLVal();
            } else if (currentToken.getType() == TokenType.INTCON) {
                parseNumber();
            } else if (currentToken.getType() == TokenType.CHRCON) {
                parseCharacter();
            }
        }
        writeSyntax("<PrimaryExp>");
    }

    public void parseNumber(){
        expect(TokenType.INTCON);
        writeSyntax("<Number>");
    }

    public void parseCharacter(){
        expect(TokenType.CHRCON);
        writeSyntax("<Character>");
    }


    public void parseLVal(){
        expect(TokenType.IDENFR);
        if(tokenList.get(currentTokenIndex).getType() == TokenType.LBRACK) {
            expect(TokenType.LBRACK);
            parseExp();
            expect(TokenType.RBRACK);
        }
        writeSyntax("<LVal>");
    }

    public void parseCond() {
        parseLOrExp();
        writeSyntax("<Cond>");
    }



     public void parseLOrExp() {
        parseLAndExp();

        while (currentTokenIndex < tokenList.size()&&
                tokenList.get(currentTokenIndex).getType() == TokenType.OR){
            writeSyntax("<LOrExp>");
            expect(TokenType.OR);
            parseLAndExp();
        }

        writeSyntax("<LOrExp>");
    }


   public void parseLAndExp() {
        parseEqExp();

        while (currentTokenIndex < tokenList.size()&&
                tokenList.get(currentTokenIndex).getType() == TokenType.AND) {
            writeSyntax("<LAndExp>");
            expect(TokenType.AND);
            parseEqExp();
        }

        writeSyntax("<LAndExp>");
    }

     public void parseEqExp() {
        parseRelExp();

        while (currentTokenIndex < tokenList.size()&&
                (tokenList.get(currentTokenIndex).getType() == TokenType.EQL ||
                tokenList.get(currentTokenIndex).getType() == TokenType.NEQ) ){
            writeSyntax("<EqExp>");
            expect(tokenList.get(currentTokenIndex).getType());
            parseRelExp();
        }

        writeSyntax("<EqExp>");
    }

    public void parseRelExp() {

        parseAddExp();

        while (currentTokenIndex < tokenList.size()&&
                (tokenList.get(currentTokenIndex).getType() == TokenType.LSS ||
                tokenList.get(currentTokenIndex).getType() == TokenType.GRE ||
                tokenList.get(currentTokenIndex).getType() == TokenType.LEQ ||
                tokenList.get(currentTokenIndex).getType() == TokenType.GEQ)) {
            writeSyntax("<RelExp>");
            expect(tokenList.get(currentTokenIndex).getType());
            parseAddExp();
        }

        writeSyntax("<RelExp>");
    }

    //变量声明
    public void parseVarDecl(){
        parseBType();
        parseVarDef();

        while (currentTokenIndex < tokenList.size()&&
                tokenList.get(currentTokenIndex).getType() == TokenType.COMMA) {
            expect(TokenType.COMMA);
            parseVarDef();
        }

        expect(TokenType.SEMICN);
        writeSyntax("<VarDecl>");
    }


    public void parseVarDef() {
        expect(TokenType.IDENFR);

        if (tokenList.get(currentTokenIndex).getType() == TokenType.LBRACK) {
            expect(TokenType.LBRACK);
            parseConstExp();
            expect(TokenType.RBRACK);
        }

        if (tokenList.get(currentTokenIndex).getType() == TokenType.ASSIGN) {
            expect(TokenType.ASSIGN);
            parseInitVal();
        }

        writeSyntax("<VarDef>");
    }


    public void parseInitVal() {
        if(currentTokenIndex < tokenList.size()) {
            Token currentToken = tokenList.get(currentTokenIndex);

            if (currentToken.getType() == TokenType.LBRACE) {
                expect(TokenType.LBRACE);

                if (tokenList.get(currentTokenIndex).getType() != TokenType.RBRACE) {
                    parseExp();

                    while (currentTokenIndex < tokenList.size() &&
                            tokenList.get(currentTokenIndex).getType() == TokenType.COMMA) {
                        expect(TokenType.COMMA);
                        parseExp();
                    }
                }
                expect(TokenType.RBRACE);
            } else if (currentToken.getType() == TokenType.STRCON) {
                expect(TokenType.STRCON);
            } else {
                parseExp();
            }
        }
        writeSyntax("<InitVal>");
    }


    public void parseExp() {
        parseAddExp(); // 调用加法表达式解析
        writeSyntax("<Exp>");
    }



    //函数定义
    public void parseFuncDef(){
        parseFuncType();

        expect(TokenType.IDENFR);
        expect(TokenType.LPARENT);

        if (tokenList.get(currentTokenIndex).getType() != TokenType.RPARENT) {
            parseFuncFParams();
        }

        expect(TokenType.RPARENT);

        parseBlock();
        writeSyntax("<FuncDef>");
    }

    public void parseFuncType(){
        Token currentToken = tokenList.get(currentTokenIndex);
        if (currentToken.getType() == TokenType.VOIDTK) {
            expect(TokenType.VOIDTK);
        }
        else if (currentToken.getType() == TokenType.INTTK) {
            expect(TokenType.INTTK);
        }
        else if (currentToken.getType() == TokenType.CHARTK) {
            expect(TokenType.CHARTK);
        }
        writeSyntax("<FuncType>");
    }

    public void parseFuncFParams(){
        parseFuncFParam();

        while (currentTokenIndex < tokenList.size()&&
                tokenList.get(currentTokenIndex).getType() == TokenType.COMMA) {
            expect(TokenType.COMMA);
            parseFuncFParam();
        }

        writeSyntax("<FuncFParams>");
    }

    public void parseFuncFParam(){
        parseBType();

        expect(TokenType.IDENFR);

        Token currentToken = tokenList.get(currentTokenIndex);

        if (currentToken.getType() == TokenType.LBRACK) {
            expect(TokenType.LBRACK);
            expect(TokenType.RBRACK);
        }
        writeSyntax("<FuncFParam>");
    }

    public void parseBlock() {
            expect(TokenType.LBRACE);

             while(currentTokenIndex < tokenList.size()&&
                     tokenList.get(currentTokenIndex).getType() != TokenType.RBRACE) {
                parseBlockItem();
            }

            expect(TokenType.RBRACE);
            writeSyntax("<Block>");
    }

    public void parseBlockItem() {
            Token currentToken = tokenList.get(currentTokenIndex);

            if (currentToken.getType() == TokenType.CONSTTK||
                currentToken.getType() == TokenType.INTTK ||
                 currentToken.getType() == TokenType.CHARTK) {
                parseDecl();
            } else {
                parseStmt();
            }
    }

    public void parseStmt() {
if(currentTokenIndex < tokenList.size()) {
    Token currentToken = tokenList.get(currentTokenIndex);
    if (currentToken.getType() == TokenType.IDENFR) {
        int tempTokenIndex = currentTokenIndex + 1;
        int num = currentToken.getLineNum();
        int flag = 0;
        while (tempTokenIndex < tokenList.size()) {
            if (tokenList.get(tempTokenIndex).getLineNum() == num) {
                if (tokenList.get(tempTokenIndex).getType() == TokenType.ASSIGN) {
                    flag = 1;
                    break;
                }
            } else {
                break;
            }
            tempTokenIndex++;
        }
        if (flag == 1) {
            parseLVal();
            expect(TokenType.ASSIGN);

            if (tokenList.get(currentTokenIndex).getType() == TokenType.GETINTTK) {
                expect(TokenType.GETINTTK);
                expect(TokenType.LPARENT);
                expect(TokenType.RPARENT);
            } else if (tokenList.get(currentTokenIndex).getType() == TokenType.GETCHARTK) {
                expect(TokenType.GETCHARTK);
                expect(TokenType.LPARENT);
                expect(TokenType.RPARENT);
            } else {
                parseExp();
            }

            expect(TokenType.SEMICN);
        } else {
            parseExp();
            expect(TokenType.SEMICN);
        }
    } else if (currentToken.getType() == TokenType.LBRACE) {
        parseBlock();
    } else if (currentToken.getType() == TokenType.IFTK) {
        expect(TokenType.IFTK);
        expect(TokenType.LPARENT);
        parseCond();
        expect(TokenType.RPARENT);
        parseStmt();
        if (tokenList.get(currentTokenIndex).getType() == TokenType.ELSETK) {
            expect(TokenType.ELSETK);
            parseStmt();
        }
    } else if (currentToken.getType() == TokenType.FORTK) {
        expect(TokenType.FORTK);
        expect(TokenType.LPARENT);


        if (tokenList.get(currentTokenIndex).getType() != TokenType.SEMICN) {
            parseForStmt();
        }
        expect(TokenType.SEMICN);

        if (tokenList.get(currentTokenIndex).getType() != TokenType.SEMICN) {
            parseCond();
        }
        expect(TokenType.SEMICN);


        if (tokenList.get(currentTokenIndex).getType() != TokenType.RPARENT) {
            parseForStmt();
        }

        expect(TokenType.RPARENT);
        parseStmt();
    } else if (currentToken.getType() == TokenType.BREAKTK) {
        expect(TokenType.BREAKTK);
        expect(TokenType.SEMICN);
    } else if (currentToken.getType() == TokenType.CONTINUETK) {
        expect(TokenType.CONTINUETK);
        expect(TokenType.SEMICN);
    } else if (currentToken.getType() == TokenType.RETURNTK) {
        expect(TokenType.RETURNTK);
        if (tokenList.get(currentTokenIndex).getType() != TokenType.SEMICN) {
            parseExp();
        }
        expect(TokenType.SEMICN);
    } else if (currentToken.getType() == TokenType.PRINTFTK) {
        expect(TokenType.PRINTFTK);
        expect(TokenType.LPARENT);
        expect(TokenType.STRCON);
        while (tokenList.get(currentTokenIndex).getType() == TokenType.COMMA) {
            expect(TokenType.COMMA);
            parseExp();
        }
        expect(TokenType.RPARENT);
        expect(TokenType.SEMICN);
    } else {
        if (tokenList.get(currentTokenIndex).getType() != TokenType.SEMICN) {
            parseExp();
        }
        expect(TokenType.SEMICN);
    }
}
        writeSyntax("<Stmt>");
    }
    
    public void parseForStmt() {
            parseLVal();
            expect(TokenType.ASSIGN);
            parseExp();
            writeSyntax("<ForStmt>");
    }

    //主函数定义
    public void parseMainFuncDef(){
        expect(TokenType.INTTK);
        expect(TokenType.MAINTK);
        expect(TokenType.LPARENT);
        expect(TokenType.RPARENT);

        parseBlock();

        writeSyntax("<MainFuncDef>");
    }




    private void expect(TokenType type) {
        if (currentTokenIndex < tokenList.size() && tokenList.get(currentTokenIndex).getType() == type) {
            Token  currenttoken = tokenList.get(currentTokenIndex++);
            writeTypeWord(currenttoken.getType(), currenttoken.getWord());
        } else  {
            if(type==TokenType.SEMICN) {
                Error error = new Error(tokenList.get(currentTokenIndex-1).getLineNum(), "i");
                errorList.add(error);
            } else if (type==TokenType.RPARENT) {
                Error error = new Error(tokenList.get(currentTokenIndex-1).getLineNum(), "j");
                errorList.add(error);
            }
            else if(type==TokenType.RBRACK){
                Error error = new Error(tokenList.get(currentTokenIndex-1).getLineNum(), "k");
                errorList.add(error);
            }
        }
    }


    private void writeTypeWord(TokenType type, String word) {
        try {
            os.write(type + " " + word);
            os.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void writeSyntax(String Syntax) {
        try {
            os.write(Syntax);
            os.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static BufferedWriter getOs() {
        return os;
    }

    public static void setOs(BufferedWriter os) {
        Parser.os = os;
    }

    public List<Token> getTokenList() {
        return tokenList;
    }

    public void setTokenList(List<Token> tokenList) {
        this.tokenList = tokenList;
    }

    public List<Error> getErrorList() {
        return errorList;
    }

    public void setErrorList(List<Error> errorList) {
        this.errorList = errorList;
    }

    public int getCurrentTokenIndex() {
        return currentTokenIndex;
    }

    public void setCurrentTokenIndex(int currentTokenIndex) {
        this.currentTokenIndex = currentTokenIndex;
    }
}
