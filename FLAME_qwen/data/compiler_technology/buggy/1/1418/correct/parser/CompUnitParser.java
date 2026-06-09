package parser;

import enums.TokenType;
import model.SyntaxTreeNode;
import model.Token;
import model.TokensIterator;

import java.util.ArrayList;
import java.util.List;

public class CompUnitParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        DeclParser declParser = new DeclParser();
        FuncDefParser funcDefParser = new FuncDefParser();
        MainFuncDefParser mainFuncDefParser = new MainFuncDefParser();

        //解析Decl
        while (true) {
            if(!iterator.isEnd()) {
                Token first = iterator.next();
                Token second = iterator.next();
                Token third = iterator.next();
                iterator.unread(3);
                if(first.getType() == TokenType.CONSTTK) {
                    SyntaxTreeNode decl;
                    decl = declParser.run(iterator);
                    children.add(decl);
                }
                else if ((first.getType() == TokenType.INTTK || first.getType() == TokenType.CHARTK) && second.getType() == TokenType.IDENFR && third.getType() != TokenType.LPARENT) {
                    SyntaxTreeNode decl = new SyntaxTreeNode();
                    decl = declParser.run(iterator);
                    children.add(decl);
                }
                else break;
            }
            else break;
        }

        //解析FuncDef
        while (true) {
            if(!iterator.isEnd()) {
                Token first = iterator.next();
                Token second = iterator.next();
                iterator.unread(2);
                if(first.getType() == TokenType.VOIDTK || first.getType() == TokenType.CHARTK) {
                    SyntaxTreeNode funcDef;
                    funcDef = funcDefParser.run(iterator);
                    children.add(funcDef);
                }
                else if(first.getType() == TokenType.INTTK && second.getType() == TokenType.IDENFR) {
                    SyntaxTreeNode funcDef;
                    funcDef = funcDefParser.run(iterator);
                    children.add(funcDef);
                }
                else break;
            }
            else break;
        }

        //解析MainFuncDef
        SyntaxTreeNode mainFuncDef;
        mainFuncDef = mainFuncDefParser.run(iterator);
        children.add(mainFuncDef);
        return new SyntaxTreeNode("<CompUnit>", null, children);
    }
}
