package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.Exp.Exp;
import Parser.Exp.ExpParser;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class LValParser {
    private TokenListIterator iterator;
    /* LVal Attributes */
    private Token ident = null;
    private ArrayList<Token> leftBrackets = new ArrayList<>(); // '['
    private ArrayList<Exp> exps = new ArrayList<>();
    private ArrayList<Token> rightBrackets = new ArrayList<>();
    private int errorLine;
    public LValParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public LVal LValParse()
    {
        this.leftBrackets = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.rightBrackets = new ArrayList<>();
        Token first=iterator.readNextToken();
        this.ident=first;
        Token next=iterator.readNextToken();
        if(next.getValue().equals("["))
        {
            this.errorLine=next.getLine();
            this.leftBrackets.add(next);
            ExpParser expParser=new ExpParser(iterator);
            this.exps.add(expParser.expParse());
            next=iterator.readNextToken();
            if(next.getValue().equals("]"))
            {
                this.rightBrackets.add(next);
            }else {
                iterator.unReadToken(1);
                ErrorPList errorPList=ErrorPList.getInstance();
                ErrorP errorP=new ErrorP("k",this.errorLine);
                errorPList.addErrorP(errorP);
            }
        }else {
            iterator.unReadToken(1);
        }
        return new LVal(ident,leftBrackets,exps,rightBrackets);
    }
}
