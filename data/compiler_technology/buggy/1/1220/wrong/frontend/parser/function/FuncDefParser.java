package frontend.parser.function;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.block.Block;
import frontend.parser.block.BlockParser;

public class FuncDefParser {
    private TokenIterator iterator;
    private FuncType funcType; //void,int,char
    private Token ident;
    private Token leftParent;
    private FuncFParams funcFParams;
    private Token rightParent;
    private Block block;

    public FuncDefParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public FuncDef parseFuncDef() {
        //FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
        // functype->void,int,char
        //FuncFParams → FuncFParam { ',' FuncFParam }
        //FuncFParam → BType Ident ['[' ']']
        funcType = new FuncType(iterator.getNextToken());
        ident = iterator.getNextToken();
        leftParent = iterator.getNextToken();
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.INTTK || t1.getType() == TokenType.CHARTK) {
            //说明是funcparams
            iterator.ungetToken(1);
            FuncFParamsParser funcFParamsParser = new FuncFParamsParser(iterator);
            funcFParams = funcFParamsParser.parseFuncFParams();
        } else {
            funcFParams = null;
            iterator.ungetToken(1);
        }

        Token t2 = iterator.getNextToken();
        if (t2.getType() != TokenType.RPARENT) {
            //缺少右小括号
            iterator.ungetToken(2);
            Token t3 = iterator.getNextToken();
            Error error = new Error(t3.getLineNum(), "j");
            ErrorList.addErrorList(error);
        } else {
            rightParent = t2;
        }
        BlockParser blockParser = new BlockParser(iterator);
        block = blockParser.parseBlock();

        return new FuncDef(funcType, ident, leftParent, funcFParams, rightParent, block);
    }
}
