package frontend;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;

public class Lexer
{
    private String sourceCode;
    private ArrayList<Token> TokenList;
    private int ErrorLine;
    private HashMap<String, TokenType> stringType;

    public Lexer()
    {
        this.sourceCode = "";
        this.TokenList = new ArrayList<>();
        this.ErrorLine = -1;
        this.stringType = new HashMap<>();
    }

    public void work() throws IOException
    {
        read();
        initStringType();
        TokenAnalysis();
        printResult();
    }

    public void read() throws IOException
    {
        InputStream inputStream = Files.newInputStream(Paths.get("testfile.txt"));
        InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
        while (true)
        {
            String line = bufferedReader.readLine();
            if (line == null)
            {
                break;
            }
            sourceCode = sourceCode + line + "\n";
        }
    }

    public void initStringType()
    {
        stringType.put("main", TokenType.MAINTK);
        stringType.put("const", TokenType.CONSTTK);
        stringType.put("int", TokenType.INTTK);
        stringType.put("char", TokenType.CHARTK);
        stringType.put("void", TokenType.VOIDTK);
        stringType.put("break", TokenType.BREAKTK);
        stringType.put("continue", TokenType.CONTINUETK);
        stringType.put("if", TokenType.IFTK);
        stringType.put("else", TokenType.ELSETK);
        stringType.put("for", TokenType.FORTK);
        stringType.put("getint", TokenType.GETINTTK);
        stringType.put("getchar", TokenType.GETCHARTK);
        stringType.put("printf", TokenType.PRINTFTK);
        stringType.put("return", TokenType.RETURNTK);
    }

    public void TokenAnalysis()
    {
        int codeLength = sourceCode.length();
        int lineNo = 1;
        for (int pos = 0; pos < codeLength;)
        {
            while (sourceCode.charAt(pos) == ' ' || sourceCode.charAt(pos) == '\t')
            {
                pos++;
            }
            if (sourceCode.charAt(pos) == '_' || Character.isLetter(sourceCode.charAt(pos)))
            {
                int newPos = pos;
                while (sourceCode.charAt(newPos) == '_' || Character.isLetter(sourceCode.charAt(newPos)) || Character.isDigit(sourceCode.charAt(newPos)))
                {
                    newPos++;
                }
                String string = sourceCode.substring(pos, newPos);
                Token token = new Token(stringType.getOrDefault(string, TokenType.IDENFR), string, lineNo);
                TokenList.add(token);
                pos = newPos;
            }
            else if (Character.isDigit(sourceCode.charAt(pos)))
            {
                int newPos = pos;
                while (Character.isDigit(sourceCode.charAt(newPos)))
                {
                    newPos++;
                }
                String string = sourceCode.substring(pos, newPos);
                Token token = new Token(TokenType.INTCON, string, lineNo);
                TokenList.add(token);
                pos = newPos;
            }
            else if (sourceCode.charAt(pos) == '\"')
            {
                int newPos = pos + 1;
                while (sourceCode.charAt(newPos) != '\"')
                {
                    newPos++;
                }
                newPos++;
                String string = sourceCode.substring(pos, newPos);
                Token token = new Token(TokenType.STRCON, string, lineNo);
                TokenList.add(token);
                pos = newPos;
            }
            else if (sourceCode.charAt(pos) == '\'')
            {
                int newPos = pos + 3;
                String string = sourceCode.substring(pos, newPos);
                Token token = new Token(TokenType.CHRCON, string, lineNo);
                TokenList.add(token);
                pos = newPos;
            }
            else if (sourceCode.charAt(pos) == '!')
            {
                if (sourceCode.charAt(pos + 1) != '=')
                {
                    Token token = new Token(TokenType.NOT, "!", lineNo);
                    TokenList.add(token);
                    pos++;
                }
                else
                {
                    Token token = new Token(TokenType.NEQ, "!=", lineNo);
                    TokenList.add(token);
                    pos = pos + 2;
                }
            }
            else if (sourceCode.charAt(pos) == '&' || sourceCode.charAt(pos) == '|')
            {
                if (sourceCode.charAt(pos + 1) != sourceCode.charAt(pos))
                {
                    ErrorLine = lineNo;
                    pos++;
                }
                else
                {
                    if (sourceCode.charAt(pos) == '&')
                    {
                        Token token = new Token(TokenType.AND, "&&", lineNo);
                        TokenList.add(token);
                    }
                    else
                    {
                        Token token = new Token(TokenType.OR, "||", lineNo);
                        TokenList.add(token);
                    }
                    pos = pos + 2;
                }
            }
            else if (sourceCode.charAt(pos) == '+' || sourceCode.charAt(pos) == '-' ||
                    sourceCode.charAt(pos) == '*' || sourceCode.charAt(pos) == '%')
            {
                if (sourceCode.charAt(pos) == '+')
                {
                    Token token = new Token(TokenType.PLUS, "+", lineNo);
                    TokenList.add(token);
                }
                else if (sourceCode.charAt(pos) == '-')
                {
                    Token token = new Token(TokenType.MINU, "-", lineNo);
                    TokenList.add(token);
                }
                else if (sourceCode.charAt(pos) == '*')
                {
                    Token token = new Token(TokenType.MULT, "*", lineNo);
                    TokenList.add(token);
                }
                else
                {
                    Token token = new Token(TokenType.MOD, "%", lineNo);
                    TokenList.add(token);
                }
                pos++;
            }
            else if (sourceCode.charAt(pos) == '/')
            {
                if (sourceCode.charAt(pos + 1) == '/')
                {
                    while (sourceCode.charAt(pos) != '\n')
                    {
                        pos++;
                    }
                    pos++;
                    lineNo++;
                }
                else if (sourceCode.charAt(pos + 1) == '*')
                {
                    pos = pos + 2;
                    while (!(sourceCode.charAt(pos) == '*' && sourceCode.charAt(pos + 1) == '/'))
                    {
                        if (sourceCode.charAt(pos) == '\n')
                        {
                            lineNo++;
                        }
                        pos++;
                    }
                    pos = pos + 2;
                }
                else
                {
                    Token token = new Token(TokenType.DIV, "/", lineNo);
                    TokenList.add(token);
                    pos++;
                }
            }
            else if (sourceCode.charAt(pos) == '<' || sourceCode.charAt(pos) == '>')
            {
                if (sourceCode.charAt(pos + 1) == '=')
                {
                    if (sourceCode.charAt(pos) == '<')
                    {
                        Token token = new Token(TokenType.LEQ, "<=", lineNo);
                        TokenList.add(token);
                    }
                    else
                    {
                        Token token = new Token(TokenType.GEQ, ">=", lineNo);
                        TokenList.add(token);
                    }
                    pos = pos + 2;
                }
                else
                {
                    if (sourceCode.charAt(pos) == '<')
                    {
                        Token token = new Token(TokenType.LSS, "<", lineNo);
                        TokenList.add(token);
                    }
                    else
                    {
                        Token token = new Token(TokenType.GRE, ">", lineNo);
                        TokenList.add(token);
                    }
                    pos = pos + 1;
                }
            }
            else if (sourceCode.charAt(pos) == '=')
            {
                if (sourceCode.charAt(pos + 1) == '=')
                {
                    Token token = new Token(TokenType.EQL, "==", lineNo);
                    TokenList.add(token);
                    pos = pos + 2;
                }
                else
                {
                    Token token = new Token(TokenType.ASSIGN, "=", lineNo);
                    TokenList.add(token);
                    pos = pos + 1;
                }
            }
            else if (sourceCode.charAt(pos) == ',')
            {
                TokenList.add(new Token(TokenType.COMMA, ",", lineNo));
                pos++;
            }
            else if (sourceCode.charAt(pos) == ';')
            {
                TokenList.add(new Token(TokenType.SEMICN, ";", lineNo));
                pos++;
            }
            else if (sourceCode.charAt(pos) == '(')
            {
                TokenList.add(new Token(TokenType.LPARENT, "(", lineNo));
                pos++;
            }
            else if (sourceCode.charAt(pos) == ')')
            {
                TokenList.add(new Token(TokenType.RPARENT, ")", lineNo));
                pos++;
            }
            else if (sourceCode.charAt(pos) == '[')
            {
                TokenList.add(new Token(TokenType.LBRACK, "[", lineNo));
                pos++;
            }
            else if (sourceCode.charAt(pos) == ']')
            {
                TokenList.add(new Token(TokenType.RBRACK, "]", lineNo));
                pos++;
            }
            else if (sourceCode.charAt(pos) == '{')
            {
                TokenList.add(new Token(TokenType.LBRACE, "{", lineNo));
                pos++;
            }
            else if (sourceCode.charAt(pos) == '}')
            {
                TokenList.add(new Token(TokenType.RBRACE, "}", lineNo));
                pos++;
            }
            else if (sourceCode.charAt(pos) == '\n')
            {
                lineNo++;
                pos++;
            }
        }
    }

    public void printResult() throws IOException
    {
        if (ErrorLine == -1)
        {
            OutputStream outputStream = new FileOutputStream("lexer.txt");
            int listSize = TokenList.size();
            for (int i = 0; i < listSize; i++)
            {
                outputStream.write((TokenList.get(i).type + " " + TokenList.get(i).value + "\n").getBytes());
            }
        }
        else
        {
            OutputStream outputStream = new FileOutputStream("error.txt");
            outputStream.write((ErrorLine + " a").getBytes());
        }
    }


}
