package frontend.declaration;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.declaration.constant.ConstDeclParser;
import frontend.declaration.variable.VarDeclParser;

public class DeclParser {
    private TokenListIterator iterator;

    public DeclParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Decl parseDecl() {
        Token first = this.iterator.readNextToken();
        this.iterator.unReadToken(1);
        DeclEle declEle = null;

        if (first.getType().equals(TokenType.CONSTTK)) {
            // 常量声明
            ConstDeclParser constDeclParser = new ConstDeclParser(this.iterator);
            declEle = constDeclParser.parseConstDecl();
        } else if (first.getType().equals(TokenType.INTTK) || first.getType().equals(TokenType.CHARTK)) {
            // 变量声明（支持 int 和 char 类型）
            VarDeclParser varDeclParser = new VarDeclParser(this.iterator);
            declEle = varDeclParser.parseVarDecl();
        } else {
            // 错误处理
            throw new IllegalArgumentException("READ UNEXPECTED TOKEN: " + first.getContent());
        }

        return new Decl(declEle);
    }
}
