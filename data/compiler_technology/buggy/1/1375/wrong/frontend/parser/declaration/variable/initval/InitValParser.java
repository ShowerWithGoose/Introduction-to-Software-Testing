package frontend.parser.declaration.variable.initval;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

import java.util.ArrayList;

public class InitValParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* InitVal Attributes */
    public Token leftBrace = null; // '{'
    public Exp first = null;
    public ArrayList<Token> commas = new ArrayList<>(); // ','
    public ArrayList<Exp> exps = new ArrayList<>();
    public Token rightBrace; // '}'
    public InitValEle initValEle = null;

    public InitValParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.iterator = iterator;
        this.error_tokens = error_tokens;
    }

    public InitVal parseInitVal() {
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.leftBrace = this.iterator.readNextToken();
       if (this.leftBrace.type.equals(TokenType.LBRACE)) {
            Token token = this.iterator.readNextToken();
            if (!token.type.equals(TokenType.RBRACE)) {
                this.iterator.unReadToken(1);
                ExpParser expParser = new ExpParser(this.iterator,this.error_tokens);
                this.first = expParser.parseExp();
                token = this.iterator.readNextToken();
                while (token.type.equals(TokenType.COMMA)) {
                    this.commas.add(token);
                    ExpParser expParser1 = new ExpParser(this.iterator,this.error_tokens);
                    this.exps.add(expParser1.parseExp());
                    token = this.iterator.readNextToken();
                }
            }
            this.rightBrace = token;
            this.initValEle = new InitVals(this.leftBrace, this.first, this.commas,
                    this.exps, this.rightBrace);
        } // 第二种
        else if (this.leftBrace.type.equals(TokenType.STRCON)) {

            this.initValEle = new InitValString(this.leftBrace);
       } // 第三种
        else{
           this.iterator.unReadToken(1);
           ExpParser expParser = new ExpParser(this.iterator,this.error_tokens);
           this.initValEle = expParser.parseExp();
       } // 第一种
        InitVal initVal = new InitVal(this.initValEle);
        return initVal;
    }
}
