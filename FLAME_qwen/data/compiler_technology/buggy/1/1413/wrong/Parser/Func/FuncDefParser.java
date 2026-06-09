package Parser.Func;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.Block;
import Parser.BlockParser;
import Parser.ErrorP;
import Parser.ErrorPList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class FuncDefParser {
    private TokenListIterator iterator;
    private FuncType funcType;
    private Token ident;
    private Token leftParent; // '('
    private FuncFParams funcFParams ; // MAY exist
    private Token rightParent; // ')'
    private Block block;
    private int errorLine;
    public FuncDefParser(TokenListIterator iterator)
    {
        this.iterator=iterator;
    }
    public FuncDef funcDefParse()
    {
        this.funcFParams=null;
        FuncTypeParser funcTypeParser = new FuncTypeParser(this.iterator);
        this.funcType = funcTypeParser.funcTypeParse();
        Token next=iterator.readNextToken();
        this.ident = next;
        next=iterator.readNextToken();
        this.leftParent = next;
        this.errorLine=leftParent.getLine();
        next=iterator.readNextToken();
        if(next.getValue().equals("int")||next.getValue().equals("char"))
        {
            iterator.unReadToken(1);
            FuncFParamsParser funcFParamsParser=new FuncFParamsParser(iterator);
            this.funcFParams=funcFParamsParser.funcFParamsParse();
            //System.out.println(this.funcFParams.print_tree()+"吴安邦是大猪");
            next=iterator.readNextToken();
            if(next.getValue().equals(")"))
            {
                this.rightParent=next;
                BlockParser blockParser=new BlockParser(iterator);
                this.block=blockParser.parseBlock();
            }else {
                iterator.unReadToken(1);
                ErrorP errorP=new ErrorP("j",this.errorLine);
                ErrorPList errorPList=ErrorPList.getInstance();
                errorPList.addErrorP(errorP);
                BlockParser blockParser=new BlockParser(iterator);
                this.block=blockParser.parseBlock();
            }
            return new FuncDef(funcType,ident,leftParent,funcFParams,rightParent,block);
        }
        else if(next.getValue().equals(")"))
        {
            this.rightParent=next;
            BlockParser blockParser=new BlockParser(iterator);
            this.block=blockParser.parseBlock();
            return new FuncDef(funcType,ident,leftParent,funcFParams,rightParent,block);
        }
        else {
            iterator.unReadToken(1);
            ErrorP errorP=new ErrorP("j",this.errorLine);
            ErrorPList errorPList=ErrorPList.getInstance();
            errorPList.addErrorP(errorP);
            BlockParser blockParser=new BlockParser(iterator);
            this.block=blockParser.parseBlock();
            return new FuncDef(funcType,ident,leftParent,funcFParams,rightParent,block);
        }
    }
}
