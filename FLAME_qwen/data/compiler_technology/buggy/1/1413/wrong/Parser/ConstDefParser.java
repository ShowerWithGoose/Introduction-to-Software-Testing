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
public class ConstDefParser {
    private TokenListIterator iterator;
    private Token Ident;
    private ArrayList<Token> leftBrack;
    private ArrayList<ConstExp>  constExpArrayList;
    private ArrayList<Token> rightBrack;
    private Token equal;
    private ConstInitVal constInitVal;
    private int errorLine;
    public ConstDefParser(TokenListIterator iterator)
    {
        this.iterator=iterator;
    }
    public ConstDef constDefParse()
    {
        this.leftBrack = new ArrayList<>();
        this.constExpArrayList = new ArrayList<>();
        this.rightBrack = new ArrayList<>();
        Token first=iterator.readNextToken();
        if(first.getType().equals("IDENFR"))
        {
            Token next=iterator.readNextToken();
            Ident=first;
            if(next.getValue().equals("["))
            {
                this.errorLine=next.getLine();
                leftBrack.add(next);
                ConstExpParser constExpParse=new ConstExpParser(iterator);
                constExpArrayList.add(constExpParse.parseConstExp());
                next=iterator.readNextToken();
                if(next.getValue().equals("]"))
                {
                    rightBrack.add(next);
                    next=iterator.readNextToken();
                    if(next.getValue().equals("="))
                    {
                        equal=next;
                        ConstInitValParser constInitValParse=new ConstInitValParser(iterator);
                        constInitVal=constInitValParse.constInitialValParse();
                    }
                }else if(next.getValue().equals("="))
                {
                    //错误处理缺少右括号k
                    ErrorPList errorPList=ErrorPList.getInstance();
                    ErrorP errorP=new ErrorP("k",this.errorLine);
                    errorPList.addErrorP(errorP);
                    equal=next;
                    ConstInitValParser constInitValParse=new ConstInitValParser(iterator);
                    constInitVal=constInitValParse.constInitialValParse();
                }
            }else if(next.getValue().equals("=")){
                this.equal=next;
                ConstInitValParser constInitValParse=new ConstInitValParser(iterator);
                constInitVal=constInitValParse.constInitialValParse();
            }
        }
        return new ConstDef(Ident,leftBrack,constExpArrayList,rightBrack,equal,constInitVal);
    }
}
