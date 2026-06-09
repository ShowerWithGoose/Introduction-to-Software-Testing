package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.BtypeParser;
import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/10
 */
public class VarDeclParser {
    private TokenListIterator iterator;
    private BType bType;
    private VarDef varDef;
    private ArrayList<Token> commas;
    private ArrayList<VarDef> varDefArrayList;
    private Token semicolon;
    private int errorLine;
    public VarDeclParser(TokenListIterator iterator)
    {
        this.iterator=iterator;
    }
    public VarDecl varDeclParse()
    {
        /*this.commas=new ArrayList<>();
        this.varDefArrayList=new ArrayList<>();
        Token first=iterator.readNextToken();
        iterator.unReadToken(1);
        if(first.getValue().equals("int")||first.getValue().equals("char"))
        {
            BtypeParser btypeParse=new BtypeParser(iterator);
            this.bType=btypeParse.BtypeParse();
            VarDefParser varDefParser=new VarDefParser(iterator);
            this.varDef=varDefParser.varDefParse();
            //System.out.println("Varde错误处理"+varDef.print_tree());
            Token next=iterator.readNextToken();
            while(next.getValue().equals(","))
            {
                this.commas.add(next);
                VarDefParser varDefParser2=new VarDefParser(iterator);
                this.varDefArrayList.add(varDefParser2.varDefParse());
                next=iterator.readNextToken();
            }
            if(next.getValue().equals(";"))
            {
                this.semicolon=next;
            }else {
                System.out.println("错误处理"+next.getValue());
            }
        }else {
            System.out.println("不是BType差评");
        }
        return new VarDecl(this.bType,varDef,commas,varDefArrayList,semicolon);*/
        this.commas = new ArrayList<>();
        this.varDefArrayList = new ArrayList<>();
        Token first=iterator.readNextToken();
        iterator.unReadToken(1);
        this.errorLine= first.getLine();
        BtypeParser btypeparser = new BtypeParser(this.iterator);
        this.bType = btypeparser.BtypeParse();
        VarDefParser varDefParser = new VarDefParser(this.iterator);
        this.varDef = varDefParser.varDefParse();
        Token token = this.iterator.readNextToken();
        while (token.getType().equals("COMMA")) { // ','
            this.commas.add(token);
            this.varDefArrayList.add(varDefParser.varDefParse());
            token = this.iterator.readNextToken();
        }
        if(token.getValue().equals(";"))
        {
            this.semicolon=token;
        }else {
            iterator.unReadToken(1);
            ErrorP errorP=new ErrorP("i",this.errorLine);
            ErrorPList errorPList=ErrorPList.getInstance();
            errorPList.addErrorP(errorP);
        }
        return new VarDecl(bType,varDef,commas,varDefArrayList,semicolon);
    }
}
