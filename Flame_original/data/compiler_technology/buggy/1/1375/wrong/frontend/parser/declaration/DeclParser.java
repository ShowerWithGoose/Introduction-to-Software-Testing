package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.constant.ConstDeclParser;
import frontend.parser.declaration.variable.VarDeclParser;

import java.util.ArrayList;

public class DeclParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    public DeclParser(TokenListIterator iterator , ArrayList<Token> error_tokens) {
        this.iterator = iterator;
        this.error_tokens = error_tokens;
    }
    public Decl parseDecl() {
        Token first = this.iterator.readNextToken();
        this.iterator.unReadToken(1);
        DeclEle declEle = null;
        if (first.type.equals(TokenType.CONSTTK)) {
            ConstDeclParser constDeclParser = new ConstDeclParser(this.iterator,this.error_tokens);
            declEle = constDeclParser.parseConstDecl();
        } else if (first.type.equals(TokenType.INTTK) || first.type.equals(TokenType.CHARTK)) {
            VarDeclParser varDeclParser = new VarDeclParser(this.iterator,this.error_tokens);
            declEle = varDeclParser.parseVarDecl();
        }
        Decl decl = new Decl(declEle);
        return decl;
    }
}
