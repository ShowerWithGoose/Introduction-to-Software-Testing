package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

public class DeclParser {
    //ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    // Decl → ConstDecl | VarDecl
    // VarDecl → BType VarDef { ',' VarDef } ';'
    private TokenIterator iterator;

    public DeclParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public Decl parseDecl() {
        Token t1 = iterator.getNextToken();
        Token t2 = iterator.getNextToken();
        if (t1.getType() == TokenType.CONSTTK &&
                (t2.getType() == TokenType.INTTK ||
                        t2.getType() == TokenType.CHARTK)) {
            iterator.ungetToken(2);
            ConstDeclParser constDeclParser = new ConstDeclParser(iterator);
            return new Decl(constDeclParser.parseConstDecl());
        } else if (t1.getType() == TokenType.INTTK ||
                t1.getType() == TokenType.CHARTK) {
            iterator.ungetToken(2);
            VarDeclParser varDeclParser = new VarDeclParser(iterator);
            return new Decl(varDeclParser.parseVarDecl());
        } else {
            System.out.println("parseDecl WA!");
            return null;
        }
    }
}
