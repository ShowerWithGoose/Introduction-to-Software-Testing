package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;

/**
 * @Description:
 * @date 2024/10/13
 */
public class MainFuncDefParser {
    private TokenListIterator iterator;
    private Token intTk; // 'int'
    private Token mainTk; // 'main'
    private Token leftParent; // '('
    private Token rightParent; // ')'
    private Block block;
    private int errorLine;

    public MainFuncDefParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public MainFuncDef mainFuncDefParse()
    {
        this.intTk = this.iterator.readNextToken();
        this.errorLine=intTk.getLine();
        this.mainTk = this.iterator.readNextToken();
        this.leftParent = this.iterator.readNextToken();
        Token token=iterator.readNextToken();
        if(token.getValue().equals(")"))
        {
            this.rightParent = token;
        }else {
            iterator.unReadToken(1);
            ErrorP errorP=new ErrorP("j",this.errorLine);
            ErrorPList errorPList=ErrorPList.getInstance();
            errorPList.addErrorP(errorP);
        }
        BlockParser blockParser = new BlockParser(this.iterator);
        this.block = blockParser.parseBlock();
        return new MainFuncDef(intTk,mainTk,leftParent,rightParent,block);
    }
}
