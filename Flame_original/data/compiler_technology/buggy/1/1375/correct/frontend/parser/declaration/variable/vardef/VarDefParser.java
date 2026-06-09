package frontend.parser.declaration.variable.vardef;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.variable.initval.InitVal;
import frontend.parser.declaration.variable.initval.InitValParser;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

public class VarDefParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* VarDef Attributes */
    public Ident ident = null;
    public Token leftBrackets = null;
    public ConstExp constExps = null;
    public Token rightBrackets = null;
    /* Init Val */
    public Token eq = null;
    public InitVal initVal = null;
    /* VarDefEle */
    public VarDefEle varDefEle = null;

    public VarDefParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.iterator = iterator;
        this.error_tokens = error_tokens;
    }

    public VarDef parseVarDef() {
        IdentParser identParser = new IdentParser(this.iterator,this.error_tokens);
        this.ident = identParser.parseIdent();
        Token token = this.iterator.readNextToken();
        if(token.type.equals(TokenType.LBRACK)) {
            this.leftBrackets=token;
            ConstExpParser expParser = new ConstExpParser(this.iterator,this.error_tokens);
            this.constExps=expParser.parseConstExp();
            token = this.iterator.readNextToken();
            if(!token.type.equals(TokenType.RBRACK))
            {
                this.iterator.unReadToken(1);
                this.rightBrackets = new Token(TokenType.SEMICN,this.constExps.my_line_num(),"]");
                this.error_tokens.add(new Token(TokenType.SEMICN,this.constExps.my_line_num(),"k"));
            } else{
                this.rightBrackets=token;
            }
            token = this.iterator.readNextToken();
        }
        if (token.type.equals(TokenType.ASSIGN)) { // '='
            this.eq = token;
            InitValParser initValParser = new InitValParser(this.iterator,this.error_tokens);
            this.initVal = initValParser.parseInitVal();
            this.varDefEle = new VarDefInit(this.ident, this.leftBrackets,
                    this.constExps, this.rightBrackets, this.eq, this.initVal);
        } else {
            // token now is ';', need to backspace
            this.iterator.unReadToken(1);
            this.varDefEle = new VarDefNull(this.ident, this.leftBrackets,
                    this.constExps, this.rightBrackets);
        }
        VarDef varDef = new VarDef(this.varDefEle);
        return varDef;
    }
}
