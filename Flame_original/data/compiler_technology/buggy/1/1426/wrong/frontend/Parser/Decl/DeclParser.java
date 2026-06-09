package frontend.Parser.Decl;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

public class DeclParser {
    private TokenListReader reader;

    public DeclParser(TokenListReader reader) {
        this.reader = reader;
    }

    public Decl parseDecl() {
        Token first = this.reader.getnextToken();
        this.reader.backward(1);
        DeclInf declInf = null;
        if (first.getType().equals(TokenType.CONSTTK)) {
            ConstDeclParser constDeclParser = new ConstDeclParser(this.reader);
            declInf = constDeclParser.parseConstDecl();
        } else if (first.getType().equals(TokenType.INTTK)) {
            VarDeclParser varDeclParser = new VarDeclParser(this.reader);
            declInf = varDeclParser.parseVarDecl();
        }else if(first.getType().equals(TokenType.CHARTK)){
            VarDeclParser varDeclParser = new VarDeclParser(this.reader);
            declInf = varDeclParser.parseVarDecl();
        }
        else {
            System.out.println("error: invalid decl");
        }
        Decl decl = new Decl(declInf);
        return decl;
    }

}
