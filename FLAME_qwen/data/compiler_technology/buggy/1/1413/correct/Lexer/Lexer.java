package Lexer;

import Parser.ErrorP;
import Parser.ErrorPList;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * &#064;Description:词法分析器
 * &#064;date  2024/9/24
 */
public class Lexer {
    private PushbackReader reader;
    private ArrayList<Token> tokens;
    private int currentChar;

    int lineNum=1;
    public Lexer(String sourceFile)
    {
        try {
            FileReader file = new FileReader(sourceFile);
            reader = new PushbackReader(file);
            tokens=new ArrayList<Token>();
            currentChar= reader.read();
        }
        catch(FileNotFoundException e1)
        {
            System.out.println("FileNotFound");
        }
        catch(IOException e2)
        {
            System.out.println("IOException reader.read方法出问题了");
        }
    }

    public ArrayList<Token> tokenize()
    {

        while(currentChar!=-1)
        {
            //System.out.println("p");
            while(isWhiteSpace(currentChar)||isTab(currentChar)||currentChar == 10)
            {
                currentChar=readNextChar();
            }
            if (isLetter(currentChar)||currentChar=='_')//如果是标识符Ident
            {
                StringBuilder sb=new StringBuilder();
                while(isLetter(currentChar)||isDigital(currentChar)||currentChar=='_')
                {
                    sb.append((char)currentChar);
                    currentChar=readNextChar();
                }
                //unReadChar(currentChar);我认为不需要回退
                String currentTokenValue= sb.toString();
                //接下来需要的是进行保留字和标识符的确认
                TokenTypeCheck tkc=new TokenTypeCheck();
                String currentTokenType= tkc.tokenTypeCheck(currentTokenValue);
                Token token=new Token(currentTokenType,currentTokenValue,lineNum);
                tokens.add(token);
                //当然，还是要先存在list里面 毕竟hashmap无序
                //到这以后我有个想法是其实可以把token和其对应的类别码存到hashmap里面
            }
            else if(isDigital(currentChar))
            {
                StringBuilder sb=new StringBuilder();
                while(isDigital(currentChar))
                {
                    sb.append((char)currentChar);
                    currentChar=readNextChar();
                }
                //unReadChar(currentChar);
                String currentTokenValue=sb.toString();
                //int num=Integer.parseInt(currentTokenValue);
                String numType="INTCON";
                Token token=new Token(numType,currentTokenValue,lineNum);
                tokens.add(token);
            }
            else if (currentChar=='!')
            {
                currentChar=readNextChar();
                if(currentChar=='=')
                {
                    Token token=new Token("NEQ","!=",lineNum);
                    tokens.add(token);
                    currentChar=readNextChar();
                }
                else {
                    Token token=new Token("NOT","!",lineNum);//不需要继续往后读了
                    tokens.add(token);
                }
            }
            else if (currentChar=='=')
            {
                currentChar=readNextChar();
                if(currentChar=='=')
                {
                    Token token=new Token("EQL","==",lineNum);
                    tokens.add(token);
                    currentChar=readNextChar();
                }
                else {
                    Token token=new Token("ASSIGN","=",lineNum);//不需要继续往后读了
                    tokens.add(token);
                }
            }
            else if (currentChar=='>')
            {
                currentChar=readNextChar();
                if(currentChar=='=')
                {
                    Token token=new Token("GEQ",">=",lineNum);
                    tokens.add(token);
                    currentChar=readNextChar();
                }
                else {
                    Token token=new Token("GRE",">",lineNum);//不需要继续往后读了
                    tokens.add(token);
                }
            }
            else if (currentChar=='<')
            {
                currentChar=readNextChar();
                if(currentChar=='=')
                {
                    Token token=new Token("LEQ","<=",lineNum);
                    tokens.add(token);
                    currentChar=readNextChar();
                }
                else {
                    Token token=new Token("LSS","<",lineNum);//不需要继续往后读了
                    tokens.add(token);
                }
            }
            else if(currentChar=='&')
            {
                currentChar=readNextChar();
                if(currentChar!='&')
                {
                    ErrorPList errorPList=ErrorPList.getInstance();
                    ErrorP errorP=new ErrorP("a",lineNum);
                    errorPList.addErrorP(errorP);
                    Token token=new Token("AND","&&",lineNum);
                    tokens.add(token);
                }
                else {
                    Token token=new Token("AND","&&",lineNum);
                    tokens.add(token);
                    currentChar=readNextChar();
                }
            }
            else if(currentChar=='|')
            {
                currentChar=readNextChar();
                if(currentChar!='|')
                {
                    ErrorPList errorPList=ErrorPList.getInstance();
                    ErrorP errorP=new ErrorP("a",lineNum);
                    errorPList.addErrorP(errorP);
                    Token token=new Token("OR","||",lineNum);
                    tokens.add(token);
                }
                else {
                    Token token=new Token("OR","||",lineNum);
                    tokens.add(token);
                    currentChar=readNextChar();
                }
            }
            else if (currentChar=='+')
            {
                Token token=new Token("PLUS","+",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            else if (currentChar=='-')
            {
                Token token=new Token("MINU","-",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            else if (currentChar=='*')
            {
                Token token=new Token("MULT","*",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            else if (currentChar=='%')
            {
                Token token=new Token("MOD","%",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            else if (currentChar==';')
            {
                Token token=new Token("SEMICN",";",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            else if (currentChar==',')
            {
                //System.out.println(",,");
                Token token=new Token("COMMA",",",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            else if (currentChar=='(')
            {
                Token token=new Token("LPARENT","(",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            else if (currentChar==')')
            {
                Token token=new Token("RPARENT",")",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            else if (currentChar=='[')
            {
                Token token=new Token("LBRACK","[",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            else if (currentChar==']')
            {
                Token token=new Token("RBRACK","]",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            else if (currentChar=='{')
            {
                Token token=new Token("LBRACE","{",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            else if (currentChar=='}')
            {
                Token token=new Token("RBRACE","}",lineNum);
                tokens.add(token);
                currentChar=readNextChar();
            }
            //下面还有仨，两个‘’ “” 还有一个/
            else if(currentChar=='\'')
            {
                currentChar=readNextChar();
                if(currentChar>=32&&currentChar<=127&&currentChar!=92)
                {
                    int recordChar=currentChar;
                    currentChar=readNextChar();
                    if (currentChar=='\'')
                    {
                        Token token=new Token("CHRCON","'"+(char)recordChar+"'",lineNum);
                        tokens.add(token);
                    }
                }
                else if(currentChar=='\\')
                {
                    currentChar=readNextChar();
                    int recordChar=currentChar;
                    currentChar=readNextChar();
                    if(currentChar=='\'')
                    {
                        if(recordChar=='a') {
                            Token token = new Token("CHRCON", "'\\a'", lineNum);
                            tokens.add(token);
                        }else if(recordChar=='b')
                        {
                            Token token = new Token("CHRCON", "'\\b'", lineNum);
                            tokens.add(token);
                        }else if(recordChar=='t')
                        {
                            Token token = new Token("CHRCON", "'\\t'", lineNum);
                            tokens.add(token);
                        }else if(recordChar=='n')
                        {
                            Token token = new Token("CHRCON", "'\\n'", lineNum);
                            tokens.add(token);
                        }else if(recordChar=='v')
                        {
                            Token token = new Token("CHRCON", "'\\v'", lineNum);
                            tokens.add(token);
                        }else if(recordChar=='f')
                        {
                            Token token = new Token("CHRCON", "'\\f'", lineNum);
                            tokens.add(token);
                        }else if(recordChar=='\"')
                        {
                            Token token = new Token("CHRCON", "'\\\"'", lineNum);
                            tokens.add(token);
                        }else if(recordChar=='\'')
                        {
                            Token token = new Token("CHRCON", "'\\''", lineNum);
                            tokens.add(token);
                        }else if(recordChar=='\\')
                        {
                            Token token = new Token("CHRCON", "'\\\\'", lineNum);
                            tokens.add(token);
                        }else if(recordChar=='0')
                        {
                            Token token = new Token("CHRCON", "'\\0'", lineNum);
                            tokens.add(token);
                        }
                    }
                }
                currentChar=readNextChar();
            }
            else if(currentChar=='\"') {
                StringBuilder sb=new StringBuilder();
                sb.append((char)currentChar);
                currentChar=readNextChar();
                while(true)
                {
                    if(currentChar=='\\')
                    {
                        sb.append((char)currentChar);
                        currentChar=readNextChar();
                        sb.append((char)currentChar);
                        currentChar=readNextChar();
                    }
                    else if(currentChar=='\"')
                    {
                        sb.append((char)currentChar);
                        currentChar=readNextChar();
                        break;
                    }
                    else {
                        sb.append((char)currentChar);
                        currentChar = readNextChar();
                    }
                }
                String stringConstToken=sb.toString();
                Token token=new Token("STRCON",stringConstToken,lineNum);
                tokens.add(token);
            }
            else if (currentChar=='/')
            {
                currentChar=readNextChar();
                if(currentChar=='/')
                {
                    currentChar=readNextChar();
                    while(currentChar!='\n')
                    {
                        if(currentChar==-1)
                        {
                            break;
                        }
                        currentChar=readNextChar();
                    }
                }
                else if(currentChar=='*')
                {
                    currentChar=readNextChar();
                    while(currentChar!='*')
                    {
                        if(currentChar==-1)
                        {
                            break;
                        }
                        currentChar=readNextChar();
                    }
                    while(currentChar=='*')
                    {
                        currentChar=readNextChar();
                        if(currentChar=='/')
                        {
                            currentChar=readNextChar();
                            break;
                        }
                        else if(currentChar==-1)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    Token token=new Token("DIV","/",lineNum);
                    tokens.add(token);
                }
            }else {
                currentChar=readNextChar();
            }

        }
        //System.out.println("end");
        return tokens;
    }
    private int readNextChar()
    {
        try {
            if(currentChar==10)
            {
                lineNum++;
            }
            return reader.read();

        }catch (IOException e)
        {
            System.out.println("IOException reader.read方法出问题了");
            return -1;
        }
    }
    private void unReadChar(int currentChar)
    {
        try {
            reader.unread(currentChar);
        }catch (IOException e)
        {
            System.out.println("IOException reader.unread方法出问题了");
        }
    }

    private boolean isWhiteSpace(int currentChar)
    {
        return Character.isWhitespace(currentChar);
    }
    private boolean isNewLine(int currentChar)
    {
        return currentChar=='\n'||currentChar=='\r';
    }
    private boolean isTab(int currentChar)
    {
        return currentChar=='\t';
    }
    private boolean isLetter(int currentChar)
    {
        return Character.isLetter(currentChar);
    }
    private boolean isDigital(int currentChar)
    {
        return Character.isDigit(currentChar);
    }
}
