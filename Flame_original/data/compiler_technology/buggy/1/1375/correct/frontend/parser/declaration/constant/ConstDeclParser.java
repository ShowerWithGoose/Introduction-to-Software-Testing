package frontend.parser.declaration.constant;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.BTypeParser;

import java.util.ArrayList;

public class ConstDeclParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    public Token constTk=null;
    public BType btype = null;
    public ConstDef first = null;
    public ArrayList<Token> commas = new ArrayList<>();
    public ArrayList<ConstDef> constDefs = new ArrayList<>();
    public Token semicn = null;
    public ConstDeclParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.iterator =  iterator;
        this.error_tokens = error_tokens;
    }
    public ConstDecl parseConstDecl() {
        this.commas = new ArrayList<>();
        this.constDefs = new ArrayList<>();
        Token token = this.iterator.readNextToken();
        if (token.type.equals(TokenType.CONSTTK)) {
            constTk = token;
        }
        BTypeParser btypeParser = new BTypeParser(this.iterator,this.error_tokens);
        btype = btypeParser.parseBtype();
        ConstDefParser constDefParser = new ConstDefParser(this.iterator,this.error_tokens);
        first = constDefParser.parseConstDef();
        token = this.iterator.readNextToken();
        while (token.type.equals(TokenType.COMMA)) {
            /* is ',' */
            this.commas.add(token);
            ConstDefParser constDefParser1 = new ConstDefParser(this.iterator,this.error_tokens);
            this.constDefs.add(constDefParser1.parseConstDef());
            token = this.iterator.readNextToken();
        }
        /* token SHOULD be ';' */
        if(!token.type.equals(TokenType.SEMICN))
        {
            this.iterator.unReadToken(1);
            this.semicn = new Token(TokenType.SEMICN,token.linenum,";");
            this.error_tokens.add(new Token(TokenType.SEMICN, first.my_line_num(), "i"));
        }
        else {
            this.semicn = token;
        }
        ConstDecl constDecl = new ConstDecl(this.constTk, this.btype,
                this.first, this.commas, this.constDefs, this.semicn);
        return constDecl;
    }
}
