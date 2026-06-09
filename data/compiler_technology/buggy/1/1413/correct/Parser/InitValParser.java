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
public class InitValParser {
    private TokenListIterator iterator;
    private int flag=0;
    private Exp exp;
    private Token leftBrace;
    private Exp exp2=null;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rightBrace;
    private Token stringConst;

    public InitValParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public InitVal initialValParse()
    {
        this.commas=new ArrayList<>();
        this.exps=new ArrayList<>();
        Token first =iterator.readNextToken();
        if(first.getValue().equals("{"))
        {
            this.flag=2;
            this.leftBrace=first;
            Token next=iterator.readNextToken();
            if(next.getValue().equals("}"))
            {
                this.rightBrace=next;
            }else {
                iterator.unReadToken(1);
                ExpParser expParser=new ExpParser(iterator);
                exp2=expParser.expParse();
                next=iterator.readNextToken();
                while(next.getValue().equals(","))
                {
                    this.commas.add(next);
                    ExpParser expParser1=new ExpParser(iterator);
                    this.exps.add(expParser1.expParse());
                    next=iterator.readNextToken();
                }
                if(next.getValue().equals("}"))
                {
                    this.rightBrace=next;
                }
            }
        } else if (first.getType().equals("STRCON")) {
            this.flag=3;
            this.stringConst=first;
        }else {
            this.flag=1;
            iterator.unReadToken(1);
            ExpParser expParser=new ExpParser(iterator);
            this.exp=expParser.expParse();
        }
        return new InitVal(flag,exp,leftBrace,exp2,commas,exps,rightBrace,stringConst);
    }
}
