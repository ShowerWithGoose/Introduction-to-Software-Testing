package parser;

import enums.TokenType;
import model.SyntaxTreeNode;
import model.Token;
import model.TokensIterator;
import parser.Const.ConstDeclParser;
import parser.Var.VarDeclParser;

import java.util.ArrayList;
import java.util.List;

public class DeclParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        Token first = iterator.next();
        iterator.unread(1);
        if(first.getType() == TokenType.CONSTTK) {
            ConstDeclParser constDeclParser = new ConstDeclParser();
            SyntaxTreeNode constDecl = constDeclParser.run(iterator);;
            children.add(constDecl);
        }
        else {
            VarDeclParser varDeclParser = new VarDeclParser();
            SyntaxTreeNode varDecl = varDeclParser.run(iterator);
            children.add(varDecl);
        }

        return new SyntaxTreeNode("<Decl>", null, children);
    }
}
