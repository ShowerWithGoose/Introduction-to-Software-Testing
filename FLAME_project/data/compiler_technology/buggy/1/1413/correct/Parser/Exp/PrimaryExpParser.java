package Parser.Exp;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.*;
import Parser.Exp.Exp;

/**
 * @Description:
 * @date 2024/10/13
 */
public class PrimaryExpParser {
    private TokenListIterator iterator;
    private int flag=0;
    private Token leftParentheses;
    private Exp exp;
    private Token rightParentheses;
    private LVal lVal;
    private NumberClass number;
    private CharacterClass character;
    private int errorLine;
    public PrimaryExpParser(TokenListIterator iterator)
    {
        this.iterator=iterator;
    }
    public PrimaryExp primaryExpParse()
    {
        Token first=iterator.readNextToken();
        if(first.getValue().equals("("))
        {
            this.flag=1;
            this.leftParentheses=first;
            this.errorLine=leftParentheses.getLine();
            ExpParser expParser=new ExpParser(iterator);
            this.exp=expParser.expParse();
            Token next=iterator.readNextToken();
            if(next.getValue().equals(")"))
            {
                this.rightParentheses=next;
            }else {
                iterator.unReadToken(1);
                ErrorP errorP=new ErrorP("j",this.errorLine);
                ErrorPList errorPList=ErrorPList.getInstance();
                errorPList.addErrorP(errorP);
            }
        }else if(first.getType().equals("INTCON"))
        {
            this.flag=3;
            iterator.unReadToken(1);
            NumberParser numberParser=new NumberParser(iterator);
            this.number=numberParser.parseNumber();
        }else if(first.getType().equals("CHRCON")){
            this.flag=4;
            iterator.unReadToken(1);
            CharacterParser characterParser=new CharacterParser(iterator);
            this.character=characterParser.characterClassParse();
        }else if(first.getType().equals("IDENFR")){
            this.flag=2;
            iterator.unReadToken(1);
            LValParser lValParser=new LValParser(iterator);
            this.lVal=lValParser.LValParse();
        }else {
            System.out.println("yyyyyyyyyy");
            System.out.println(first.getValue()+first.getLine());
            System.out.println("ggggggggggggg");
        }
        return new PrimaryExp(this.flag,leftParentheses,exp,rightParentheses,lVal,number,character);
    }

}
