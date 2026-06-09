package frontend.parser.declaration.variable;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.BTypeParser;
import frontend.parser.declaration.variable.vardef.VarDef;
import frontend.parser.declaration.variable.vardef.VarDefParser;

import java.util.ArrayList;

public class VarDeclParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* VarDecl Attributes */
    public BType btype = null;
    public VarDef first = null;
    public ArrayList<Token> commas = new ArrayList<>(); // ','
    public ArrayList<VarDef> varDefs = new ArrayList<>();
    public Token semicn; // ';'

    public VarDeclParser(TokenListIterator iterator, ArrayList<Token> error_tokens)
    {
        this.iterator = iterator;
        this.error_tokens = error_tokens;
    }

    public VarDecl parseVarDecl() {
        BTypeParser btypeparser = new BTypeParser(this.iterator,this.error_tokens);
        this.btype = btypeparser.parseBtype();
        VarDefParser varDefParser = new VarDefParser(this.iterator,this.error_tokens);
        this.first = varDefParser.parseVarDef();
        Token token = this.iterator.readNextToken();
        while (token.type.equals(TokenType.COMMA)) { // ','
            this.commas.add(token);
            VarDefParser varDefParser1 = new VarDefParser(this.iterator,this.error_tokens);
            this.varDefs.add(varDefParser1.parseVarDef());
            token = this.iterator.readNextToken();
        }
        if(!token.type.equals(TokenType.SEMICN))
        {
            this.iterator.unReadToken(1);
            this.semicn = new Token(TokenType.SEMICN,this.btype.token.linenum,";");
            this.error_tokens.add(new Token(TokenType.SEMICN, first.my_line_num(), "i"));
        } else{
            this.semicn = token;
        }
        VarDecl varDecl = new VarDecl(this.btype, this.first,
                this.commas, this.varDefs, this.semicn);
        return varDecl;
    }
}
