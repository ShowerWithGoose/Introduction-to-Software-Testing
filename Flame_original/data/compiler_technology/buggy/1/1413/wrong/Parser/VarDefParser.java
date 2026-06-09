package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.Exp.ConstExp;
import Parser.Exp.ConstExpParser;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/12
 */
public class VarDefParser {
    private TokenListIterator iterator;
    private Token Ident;
    private ArrayList<Token> leftBrackets;
    private ArrayList<ConstExp> constExpArrayList;
    private ArrayList<Token> rightBrackets;
    private ArrayList<Token> equal;
    private ArrayList<InitVal> initValArrayList;
    private int errorLine;
    public VarDefParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public VarDef varDefParse()
    {
        /*this.leftBrackets = new ArrayList<>();
        this.constExpArrayList = new ArrayList<>();
        this.rightBrackets = new ArrayList<>();
        this.equal=new ArrayList<>();
        this.initValArrayList=new ArrayList<>();
        Token first =iterator.readNextToken();
        if(first.getType().equals("IDENFR"))
        {
            this.Ident=first;
            Token next =iterator.readNextToken();
            if(next.getValue().equals("["))
            {
                this.leftBrackets.add(next);
                ConstExpParser constExpParser=new ConstExpParser(iterator);
                this.constExpArrayList.add(constExpParser.parseConstExp());
                next=iterator.readNextToken();
                if(next.getValue().equals("]"))
                {
                    this.rightBrackets.add(next);
                    Token next_next=iterator.readNextToken();
                    iterator.unReadToken(1);
                    if(next_next.getValue().equals("="))
                    {
                        this.equal.add(next_next);
                        InitValParser initValParser=new InitValParser(iterator);
                        this.initValArrayList.add(initValParser.initialValParse());
                    }else {
                        System.out.println("meiyoudenghao Vardef");
                    }
                }else {
                    System.out.println("cuowuchuli Vardef youkuohao");
                    //错误处理
                }
            } else if (next.getValue().equals("=")) {
                this.equal.add(next);
                //System.out.println(equal.get(0).getValue()+"wuanb");
                InitValParser initValParser=new InitValParser(iterator);
                this.initValArrayList.add(initValParser.initialValParse());
                //System.out.println("lalallal"+initValArrayList.get(0).print_tree());
            }else {
                iterator.unReadToken(1);
            }
        }
        return new VarDef(Ident,leftBrackets,constExpArrayList,rightBrackets,equal,initValArrayList);*/
        this.leftBrackets = new ArrayList<>();
        this.constExpArrayList = new ArrayList<>();
        this.rightBrackets = new ArrayList<>();
        this.Ident= iterator.readNextToken();
        this.initValArrayList=new ArrayList<>();
        this.equal=new ArrayList<>();
        Token token = this.iterator.readNextToken();
        while (token.getType().equals("LBRACK")) {
            this.errorLine= token.getLine();
            this.leftBrackets.add(token);
            ConstExpParser expParser = new ConstExpParser(this.iterator);
            this.constExpArrayList.add(expParser.parseConstExp());
            token = this.iterator.readNextToken();
            if(token.getValue().equals("]")){
                this.rightBrackets.add(token);
            }
            else {
                iterator.unReadToken(1);
                ErrorPList errorPList=ErrorPList.getInstance();
                ErrorP errorP=new ErrorP("k",this.errorLine);
                errorPList.addErrorP(errorP);
            }
            token = this.iterator.readNextToken();
        }
        if (token.getType().equals("ASSIGN")) { // '='
            this.equal.add(token);
            InitValParser initValParser = new InitValParser(this.iterator);
            this.initValArrayList.add(initValParser.initialValParse());
        } else {
            // token now is ';', need to backspace
            this.iterator.unReadToken(1);
        }

        return new VarDef(Ident,leftBrackets,constExpArrayList,rightBrackets,equal,initValArrayList);
    }
}
