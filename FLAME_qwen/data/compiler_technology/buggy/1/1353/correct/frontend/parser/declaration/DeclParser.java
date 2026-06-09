package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.constant.ConstDeclParser;
import frontend.parser.declaration.variable.VarDeclParser;

/**
 * DeclParser 声明解析器类
 * <Decl> -> <ConstDecl> | <VarDecl>
 */
public class DeclParser {
    private TokenListIterator iterator;

    public DeclParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Decl parseDecl() {
        Token first = this.iterator.next();
        this.iterator.unRead(1);
        DeclEle declEle = null;
        /* 预读 */
        /* first -> const => ConstDecl */
        /* first -> int/char => VarDecl */
        if (first.getTokenType().equals(TokenType.CONSTTK)) {
            ConstDeclParser constDeclParser = new ConstDeclParser(this.iterator);
            declEle = constDeclParser.parseConstDecl();
        } else if (first.getTokenType().equals(TokenType.INTTK) || first.getTokenType().equals(TokenType.CHARTK)) {
            VarDeclParser varDeclParser = new VarDeclParser(this.iterator);
            declEle = varDeclParser.parseVarDecl();
        } else {
            /* ERROR */
            System.out.println("READ UNEXPECTED TOKEN ");
        }
        Decl decl = new Decl(declEle);
        return decl;
    }
}
