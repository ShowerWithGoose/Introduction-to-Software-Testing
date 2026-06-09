package frontend.parser;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.cst.CSTNode;
import frontend.parser.cst.TokenNode;

import java.util.ArrayList;

public class ParseSupporter {
    private final ArrayList<Token> tokens;
    private final ArrayList<String> parseLog;
    private int index;
    
    public ParseSupporter(ArrayList<Token> tokens) {
        this.tokens = tokens;
        this.parseLog = new ArrayList<>();
        this.index = 0;
    }
    
    public ParseSupporter(ParseSupporter parseSupporter) {
        this.tokens = new ArrayList<>(parseSupporter.tokens);
        this.parseLog = new ArrayList<>(parseSupporter.parseLog);
        this.index = parseSupporter.index;
    }
    

    public ArrayList<String> getParseLog() {
        return this.parseLog;
    }
    
    public Token lookAhead(int step) {
        if (index + step < tokens.size() && index + step >= 0) {
            return tokens.get(index + step);
        } else {
            return new Token(TokenType.EOF, -1, "");
        }
    }
    
    public void advance(int step) {
        index += step;
    }
    
    public boolean isParseEnd() {
        return index >= tokens.size();
    }
    
    public boolean isDeclFirst() {
        return isConstDecl() || isVarDecl();
    }
    
    public boolean isConstDecl() {
        return lookAhead(0).getType() == TokenType.CONSTTK;
    }
    
    public boolean isVarDecl() {
        return ((lookAhead(0).getType() == TokenType.INTTK) ||
                (lookAhead(0).getType() == TokenType.CHARTK)) &&
                (lookAhead(2).getType() != TokenType.LPARENT);
    }
    
    public boolean isFuncType() {
        return lookAhead(0).getType() == TokenType.INTTK ||
                lookAhead(0).getType() == TokenType.VOIDTK || 
                lookAhead(0).getType() == TokenType.CHARTK;
    }
    
    public boolean isFunDef() {
        return isFuncType() && 
                (lookAhead(2).getType() == TokenType.LPARENT) &&
                (lookAhead(1).getType() != TokenType.MAINTK);
    }
    
    public boolean isMainFuncDef() {
        return (lookAhead(0).getType() == TokenType.INTTK) &&
                (lookAhead(1).getType() == TokenType.MAINTK) &&
                (lookAhead(2).getType() == TokenType.LPARENT);
    }
    
    public boolean isComma() {
        return lookAhead(0).getType() == TokenType.COMMA;
    }
    
    public boolean isLBracket() {
        return lookAhead(0).getType() == TokenType.LBRACK;
    }
    
    public boolean isRBracket() {
        return lookAhead(0).getType() == TokenType.RBRACK;
    }
    
    public boolean isLBrace() {
        return lookAhead(0).getType() == TokenType.LBRACE;
    }
    
    public boolean isRBrace() {
        return lookAhead(0).getType() == TokenType.RBRACE;
    }
    
    public boolean isFuncParaFirst() {
        return lookAhead(0).getType() == TokenType.INTTK || lookAhead(0).getType() == TokenType.CHARTK;
    }

    public boolean isIntTk() {
        return lookAhead(0).getType() == TokenType.INTTK;
    }
    
    public boolean isVoidTk() {
        return lookAhead(0).getType() == TokenType.VOIDTK;
    }
    
    public boolean isAssign() {
        return lookAhead(0).getType() == TokenType.ASSIGN;
    }
    
    public boolean isIfTk() {
        return lookAhead(0).getType() == TokenType.IFTK;
    }
    
    public boolean isForTk() {
        return lookAhead(0).getType() == TokenType.FORTK;
    }
    
    public boolean isBreakTk() {
        return lookAhead(0).getType() == TokenType.BREAKTK;
    }
    
    public boolean isContinueTk() {
        return lookAhead(0).getType() == TokenType.CONTINUETK;
    }
    
    public boolean isReturnTk() {
        return lookAhead(0).getType() == TokenType.RETURNTK;
    }
    
    public boolean isElseTk() {
        return lookAhead(0).getType() == TokenType.ELSETK;
    }
    
    public boolean isPrintfTk() {
        return lookAhead(0).getType() == TokenType.PRINTFTK;
    }
    
    public boolean isSemiColon() {
        return lookAhead(0).getType() == TokenType.SEMICN;
    }
    
    public boolean isLParent() {
        return lookAhead(0).getType() == TokenType.LPARENT;
    }
    
    public boolean isRParent() {
        return lookAhead(0).getType() == TokenType.RPARENT;
    }
    
    public boolean isOr() {
        return lookAhead(0).getType() == TokenType.OR;
    }
    
    public boolean isAnd() {
        return lookAhead(0).getType() == TokenType.AND;
    }
    
    public boolean isEqOp() {
        return lookAhead(0).getType() == TokenType.EQL ||
                lookAhead(0).getType() == TokenType.NEQ;
    }
    
    public boolean isAddOp() {
        return lookAhead(0).getType() == TokenType.PLUS ||
                lookAhead(0).getType() == TokenType.MINU;
    }
    
    public boolean isMulOp() {
        return lookAhead(0).getType() == TokenType.MULT ||
                lookAhead(0).getType() == TokenType.DIV ||
                lookAhead(0).getType() == TokenType.MOD;
    }
    
    public boolean isCharTk() {
        return lookAhead(0).getType() == TokenType.CHARTK;
    }
    
    public boolean isNumber() {
        return lookAhead(0).getType() == TokenType.INTCON;
    }
    
    public boolean isIdentifier() {
        return lookAhead(0).getType() == TokenType.IDENFR;
    }
    
    public boolean isUnaryOp() {
        return lookAhead(0).getType() == TokenType.PLUS ||
                lookAhead(0).getType() == TokenType.MINU ||
                lookAhead(0).getType() == TokenType.NOT;
    }
    
    public boolean isCallee() {
        return lookAhead(0).getType() == TokenType.IDENFR &&
                lookAhead(1).getType() == TokenType.LPARENT;
    }
    
    public boolean isRelOp() {
        return lookAhead(0).getType() == TokenType.LSS ||
                lookAhead(0).getType() == TokenType.GRE ||
                lookAhead(0).getType() == TokenType.LEQ ||
                lookAhead(0).getType() == TokenType.GEQ;
    }
    
    public boolean isStrConst() {
        return lookAhead(0).getType() == TokenType.STRCON;
    }
    
    public CSTNode checkToken(TokenType type) throws RuntimeException {
        Token token = lookAhead(0);
        if (!(token.getType() == type)) {
            throw new RuntimeException("Error!!"); //TODO
        }
       // System.out.println(token.getType() + " " + token.getContent()); // 输出到 控制台
        advance(1);
        return new TokenNode(token);
    }
    
    public int getLineNum() {
        return lookAhead(-1).getLineNum();
    }
    
    public void addParseLog(String procedure)
    {
        parseLog.add("<" + procedure + ">");
    }
    
    public void addComponent(String string)
    {
        parseLog.add(string);
    }
    
    public Token getCurrentToken()
    {
        return lookAhead(-1);
    }
    
}
