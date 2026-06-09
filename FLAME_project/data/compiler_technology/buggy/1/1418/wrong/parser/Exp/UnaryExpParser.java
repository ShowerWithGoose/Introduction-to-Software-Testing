package parser.Exp;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.Normal.FuncRParamsParser;
import parser.LeafParser;
import parser.Normal.UnaryOpParser;
import model.SyntaxTreeNode;
import util.ErrorSave;

import java.util.ArrayList;
import java.util.List;

public class UnaryExpParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        LeafParser leafParser = new LeafParser();

        Token first = iterator.next();
        //UnaryOp UnaryExp
        if(first.getType() == TokenType.PLUS || first.getType() == TokenType.MINU || first.getType() == TokenType.NOT) {
            UnaryOpParser unaryOpParser = new UnaryOpParser();
            children.add(unaryOpParser.run(first));
            UnaryExpParser unaryExpParser = new UnaryExpParser();
            children.add(unaryExpParser.run(iterator));
        }
        else {
            Token second = iterator.next();
            //处理 Ident '(' [ FuncRParams ] ')'
            if(first.getType() == TokenType.IDENFR && second.getType() == TokenType.LPARENT) {
                children.add(leafParser.run(first));
                children.add(leafParser.run(second));
                //处理 [FuncRParams]
                Token tt = iterator.next();
                    //如果有FuncRParams
                if(tt.getType() == TokenType.LPARENT || tt.getType() == TokenType.IDENFR || tt.getType() == TokenType.CHRCON ||
                        tt.getType() == TokenType.INTCON || tt.getType() == TokenType.PLUS || tt.getType() == TokenType.MINU || tt.getType() == TokenType.NOT) {
                    iterator.unread(1);
                    FuncRParamsParser funcRParamsParser = new FuncRParamsParser();
                    children.add(funcRParamsParser.run(iterator));
                    tt = iterator.next();
                }

                if(tt.getType() != TokenType.RPARENT) {
                    iterator.unread(2);
                    tt = iterator.next();
                    ErrorSave.error("Parser", tt.getLineno(), 'j');
                }
                else children.add(leafParser.run(tt));
            }
            //处理 PrimaryExp
            else {
                iterator.unread(2);
                PrimaryExpParser primaryExpParser = new PrimaryExpParser();
                children.add(primaryExpParser.run(iterator));
            }
        }

        return new SyntaxTreeNode("<UnaryExp>", null, children);
    }
}
