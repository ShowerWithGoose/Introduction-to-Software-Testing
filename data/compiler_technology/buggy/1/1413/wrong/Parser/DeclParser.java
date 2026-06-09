package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;

/**
 * @Description:
 * @date 2024/10/10
 */
public class DeclParser {
    private TokenListIterator iterator;
    private ConstDecl constDecl;
    private VarDecl varDecl;

    public DeclParser(TokenListIterator tokenListIterator) {
        this.iterator = tokenListIterator;
    }

    public Decl declParse() {//单遍的
        this.varDecl=null;
        this.constDecl=null;
        Token first = this.iterator.readNextToken();
        this.iterator.unReadToken(1);
        if (first.getValue().equals("const")) {
            ConstDeclParser constDeclParse = new ConstDeclParser(iterator);
            this.constDecl=constDeclParse.constDeclParse();
        } else if (first.getValue().equals("int") || first.getValue().equals("char")) {
            VarDeclParser varDeclParse = new VarDeclParser(iterator);
            this.varDecl=varDeclParse.varDeclParse();
        } else {
            System.out.println("declParse癫了");
        }
        return new Decl(this.constDecl,varDecl);
    }
}
