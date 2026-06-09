package Parser.Exp;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.ErrorP;
import Parser.ErrorPList;
import Parser.Func.FuncRParams;
import Parser.Func.FuncRParamsParser;
import Parser.UnaryOp;
import Parser.UnaryOpParser;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/12
 */
public class UnaryExpParser {
    private TokenListIterator iterator;
    private int flag=0;
    private PrimaryExp primaryExp;
    private Token ident;
    private Token leftParenthesis;
    private FuncRParams funcRParams;
    private Token rightParenthesis;
    private ArrayList<UnaryOp> unaryOpArrayList;
    private UnaryExp unaryExp;
    private int errorLine;
    public UnaryExpParser(TokenListIterator iterator)
    {
        this.iterator=iterator;
    }
    public UnaryExp unaryExpParse()
    {
        this.unaryOpArrayList=new ArrayList<>();
        Token first = this.iterator.readNextToken();
        Token second=this.iterator.readNextToken();
        if(first.getType().equals("IDENFR")&&second.getValue().equals("("))
        {
            this.flag=2;
            this.ident=first;
            this.leftParenthesis=second;
            this.errorLine=leftParenthesis.getLine();
            Token next=this.iterator.readNextToken();
            if(next.getValue().equals(")"))
            {
                this.rightParenthesis=next;
            }else if(next.getValue().equals("(")||next.getType().equals("IDENFR")||next.getType().equals("INTCON")||next.getType().equals("CHRCON")||next.getValue().equals("+")||next.getValue().equals("!")||next.getValue().equals("-")){
                iterator.unReadToken(1);
                FuncRParamsParser funcRParamsParser=new FuncRParamsParser(iterator);
                this.funcRParams=funcRParamsParser.funcRParamsParse();
                //System.out.println("吴安邦变猪"+funcRParams.print_tree());
                next=iterator.readNextToken();
                if(!next.getValue().equals(")")){
                    iterator.unReadToken(1);
                    ErrorP errorP=new ErrorP("j",this.errorLine);
                    ErrorPList errorPList=ErrorPList.getInstance();
                    errorPList.addErrorP(errorP);
                }else {
                    this.rightParenthesis=next;
                }
            }else {
                iterator.unReadToken(1);
                ErrorP errorP=new ErrorP("j",this.errorLine);
                ErrorPList errorPList=ErrorPList.getInstance();
                errorPList.addErrorP(errorP);
            }
                //错误处理？？？？？？？
        } else if(first.getValue().equals("+")||first.getValue().equals("-")||first.getValue().equals("!")){
            this.flag=3;
            iterator.unReadToken(2);
            UnaryOpParser unaryOpParser=new UnaryOpParser(iterator);
            this.unaryOpArrayList.add(unaryOpParser.unaryOpParse());
            UnaryExpParser unaryExpParser=new UnaryExpParser(iterator);
            this.unaryExp=unaryExpParser.unaryExpParse();
        }
        else {
            this.flag=1;
            iterator.unReadToken(2);
            PrimaryExpParser primaryExpParser=new PrimaryExpParser(iterator);
            this.primaryExp=primaryExpParser.primaryExpParse();
        }
        return new UnaryExp(this.flag,this.primaryExp,this.ident,leftParenthesis,funcRParams,rightParenthesis,unaryOpArrayList,unaryExp);
    }

}
