package Parser.Func;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.BType;
import Parser.BtypeParser;
import Parser.ErrorP;
import Parser.ErrorPList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class FuncFParamParser {
    private TokenListIterator iterator;
    /* FuncFParam Attributes */
    private BType btype = null;
    private Token ident = null;
    private Token leftBracketFirst = null;
    private Token rightBracketFirst = null;
    private int errorLine;

    public FuncFParamParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public FuncFParam funcFParamParse()
    {
        leftBracketFirst = null;
        rightBracketFirst=null;
        BtypeParser btypeParser=new BtypeParser(iterator);
        this.btype=btypeParser.BtypeParse();
        //System.out.println(this.btype.print_tree()+"吴安邦是猪");
        Token next =iterator.readNextToken();
        if(next.getType().equals("IDENFR"))
        {
            this.ident=next;
            next=iterator.readNextToken();
            if(next.getValue().equals("["))
            {
                this.errorLine=next.getLine();
                this.leftBracketFirst=next;
                next=iterator.readNextToken();
                if(next.getValue().equals("]"))
                {
                    this.rightBracketFirst=next;
                }else {
                    iterator.unReadToken(1);
                    ErrorPList errorPList=ErrorPList.getInstance();
                    ErrorP errorP=new ErrorP("k",this.errorLine);
                    errorPList.addErrorP(errorP);
                }
            }else {
                iterator.unReadToken(1);
            }
        }
        return new FuncFParam(btype,ident,leftBracketFirst,rightBracketFirst);
    }
}
