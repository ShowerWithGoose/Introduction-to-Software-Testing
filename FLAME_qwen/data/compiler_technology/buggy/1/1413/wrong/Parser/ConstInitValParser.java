package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.Exp.ConstExp;
import Parser.Exp.ConstExpParser;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/11
 */
public class ConstInitValParser {
    private TokenListIterator iterator;
    private ConstExp constExp1;
    private int flag;
    private Token leftBrace;
    private ConstExp constExp2;
    private ArrayList<Token> commas;
    private ArrayList<ConstExp> constExpArrayList;
    private Token rightBrace;
    private Token StringConst;
    public ConstInitValParser(TokenListIterator iterator)
    {
        this.iterator=iterator;
    }
    public ConstInitVal constInitialValParse(){
        commas=new ArrayList<>();
        constExpArrayList=new ArrayList<>();
        constExp2=null;
        Token first=iterator.readNextToken();
        if(first.getValue().equals("{"))
        {
            this.flag=2;
            this.leftBrace=first;
            Token next;
            next=iterator.readNextToken();
            if(next.getValue().equals("}"))
            {
                this.rightBrace=next;
            }
            else {
                iterator.unReadToken(1);
                ConstExpParser constExpParser=new ConstExpParser(iterator);
                this.constExp2=constExpParser.parseConstExp();
                next=iterator.readNextToken();
                while(next.getValue().equals(","))
                {
                    this.commas.add(next);
                    ConstExpParser constExpParser2=new ConstExpParser(iterator);
                    this.constExpArrayList.add(constExpParser2.parseConstExp());
                    next=iterator.readNextToken();
                }
                if(next.getValue().equals("}"))
                {
                    this.rightBrace=next;
                }
            }
        } else if (first.getType().equals("STRCON")) {
            this.flag=3;
            this.StringConst=first;
        } else{
            this.flag=1;
            iterator.unReadToken(1);
            ConstExpParser constExpParser=new ConstExpParser(iterator);
            this.constExp1=constExpParser.parseConstExp();
        }
        return new ConstInitVal(constExp1,flag,leftBrace,constExp2,commas,constExpArrayList,rightBrace,StringConst);
    }
}
