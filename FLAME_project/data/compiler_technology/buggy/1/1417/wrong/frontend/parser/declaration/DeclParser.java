package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.constant.ConstDecl;
import frontend.parser.declaration.constant.ConstDeclParser;
import frontend.parser.declaration.variable.VarDecl;
import frontend.parser.declaration.variable.VarDeclParser;

import java.util.ArrayList;

public class DeclParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public DeclParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public Decl parseDecl() {
        Token first = tokenList.getNextToken();
        tokenList.fallbackToken(1);
        // 如果是ConstDecl
        if (first.getType() == TokenType.CONSTTK) {
            ConstDeclParser constDeclParser = new ConstDeclParser(tokenList);
            ConstDecl constDecl = constDeclParser.parseConstDecl();
            this.nodes.add(constDecl);
        }
        // 如果是VarDecl
        else if (first.getType() == TokenType.INTTK || first.getType() == TokenType.CHARTK) {
            VarDeclParser varDeclParser = new VarDeclParser(tokenList);
            VarDecl varDecl = varDeclParser.parserVarDecl();
            this.nodes.add(varDecl);
        } else {
            // TODO: something wrong
        }
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        Decl decl = new Decl(startLine, endLine, "<Decl>", nodes);
        return decl;
    }
}
