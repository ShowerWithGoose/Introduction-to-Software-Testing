package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/10
 */
public class ConstDeclParser {
    private TokenListIterator iterator;
    public ConstDeclParser(TokenListIterator iterator)
    {
        this.iterator=iterator;
    }
    private Token Const;
    private BType bType;
    private ConstDef constDef;
    private ArrayList<Token> commas;
    private ArrayList<ConstDef> constDefArrayList;
    private Token semicolon;
    private int errorLine;
    public ConstDecl constDeclParse()
    {
        commas=new ArrayList<>();
        constDefArrayList=new ArrayList<>();
        Token first=iterator.readNextToken();
        if(first.getValue().equals("const"))
        {
            this.Const=first;
            this.errorLine= first.getLine();
            BtypeParser btypeParse=new BtypeParser(iterator);
            bType=btypeParse.BtypeParse();
            ConstDefParser constDefParse=new ConstDefParser(iterator);
            constDef=constDefParse.constDefParse();
            Token next=iterator.readNextToken();
            while(next.getValue().equals(","))
            {
                commas.add(next);
                constDefArrayList.add(constDefParse.constDefParse());
                next=iterator.readNextToken();
            }
            if(next.getValue().equals(";"))
            {
                this.semicolon=next;
            }else{
                iterator.unReadToken(1);
                ErrorP errorP=new ErrorP("i",this.errorLine);
                ErrorPList errorPList=ErrorPList.getInstance();
                errorPList.addErrorP(errorP);
                //错误处理i
            }
            ConstDecl constDecl=new ConstDecl(this.Const,bType,constDef,commas,constDefArrayList,semicolon);
            return constDecl;
        }else {
            return null;
        }
    }
}
