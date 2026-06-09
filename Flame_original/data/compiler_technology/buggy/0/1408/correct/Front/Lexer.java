package Front;

import CompileError.CompileError;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.SortedMap;


public class Lexer
{
    private final String source;
    private int curPos;
    private int lineNum;
    private final ArrayList<Token> tokens = new ArrayList<>();
    private final HashMap<String, Token.lexToken> reverseWords = new HashMap<>();
    private final ArrayList<CompileError> errors;
    private String reverseChar1 = "+-*%;,()[]{}";
    private String reverseChar2 = "!=><";
    private String reverseChar3 = "&|";

    public Lexer(String program, ArrayList<CompileError> errorList)
    {
        this.source = program;
        this.errors = errorList;
        this.curPos = 0;
        this.lineNum = 1;
        setReverseWords();
    }

    public void setReverseWords()
    {
        String[] words = {
                "main", "getint", "getchar", "printf", "return",
                "const", "int", "char", "void",
                "break", "continue", "if", "else", "for",
                "!", "&&", "||", "+", "-", "*", "/", "%",
                "<", "<=", ">", ">=", "==", "!=", "=",
                ";", ",", "(", ")", "[", "]", "{", "}"
        };
        Token.lexToken[] types = {
                Token.lexToken.MAINTK, Token.lexToken.GETINTTK, Token.lexToken.GETCHARTK,
                Token.lexToken.PRINTFTK, Token.lexToken.RETURNTK, Token.lexToken.CONSTTK,
                Token.lexToken.INTTK, Token.lexToken.CHARTK, Token.lexToken.VOIDTK,
                Token.lexToken.BREAKTK, Token.lexToken.CONTINUETK,
                Token.lexToken.IFTK, Token.lexToken.ELSETK, Token.lexToken.FORTK,
                Token.lexToken.NOT, Token.lexToken.AND, Token.lexToken.OR,
                Token.lexToken.PLUS, Token.lexToken.MINU, Token.lexToken.MULT, Token.lexToken.DIV, Token.lexToken.MOD,
                Token.lexToken.LSS, Token.lexToken.LEQ, Token.lexToken.GRE, Token.lexToken.GEQ,
                Token.lexToken.EQL, Token.lexToken.NEQ, Token.lexToken.ASSIGN,
                Token.lexToken.SEMICN, Token.lexToken.COMMA,
                Token.lexToken.LPARENT, Token.lexToken.RPARENT,
                Token.lexToken.LBRACK, Token.lexToken.RBRACK,
                Token.lexToken.LBRACE, Token.lexToken.RBRACE
        };
        for (int i = 0; i < words.length; i++)
        {
            reverseWords.put(words[i], types[i]);
        }
    }

    public ArrayList<Token> getTokens()
    {
        return tokens;
    }

    public void deal()
    {
        while (curPos < source.length())
        {
            char nowChar = source.charAt(curPos);
            if (Character.isDigit(nowChar)) //纯数字
            {
                StringBuilder tokenBuilder = new StringBuilder();
                while (curPos < source.length() && Character.isDigit(nowChar))
                {
                    tokenBuilder.append(nowChar);
                    curPos++;
                    nowChar = source.charAt(curPos);
                    // if (!Character.isDigit(nowChar)) break;
                }
                String curToken = tokenBuilder.toString();
                Token token = new Token(curToken, lineNum, Token.lexToken.INTCON);
                tokens.add(token);
            }
            else if (Character.isLetter(nowChar) || nowChar == '_') // 字母数字下划线
            {
                StringBuilder tokenBuilder = new StringBuilder();
                while (curPos < source.length() &&
                        (Character.isLetter(nowChar) || Character.isDigit(nowChar) || nowChar == '_'))
                {
                    tokenBuilder.append(nowChar);
                    curPos++;
                    nowChar = source.charAt(curPos);
                }
                String curToken = tokenBuilder.toString();
                if (!reverse(curToken))
                {
                    Token token = new Token(curToken, lineNum, Token.lexToken.IDENFR);
                    tokens.add(token);
                }
                else
                {
                    Token token = reverseToken(curToken, lineNum);
                    tokens.add(token);
                }
            }
            else if (nowChar == '\"' || nowChar == '\'')
            {
                StringBuilder tokenBuilder = new StringBuilder();
                tokenBuilder.append(nowChar);
                curPos++;
                if (nowChar == '\"')
                {
                    nowChar = source.charAt(curPos);
                    while (curPos < source.length() && source.charAt(curPos) != '\"')
                    {
                        tokenBuilder.append(nowChar);
                        curPos++;
                        nowChar = source.charAt(curPos);
                    }
                    tokenBuilder.append(nowChar);
                    String curToken = tokenBuilder.toString();
                    Token token = new Token(curToken, lineNum, Token.lexToken.STRCON);
                    tokens.add(token);
                }
                else
                {
                    nowChar = source.charAt(curPos);
                    while (curPos < source.length() && source.charAt(curPos) != '\'')
                    {
                        tokenBuilder.append(nowChar);
                        curPos++;
                        nowChar = source.charAt(curPos);
                    }
                    tokenBuilder.append(nowChar);
                    String curToken = tokenBuilder.toString();
                    Token token = new Token(curToken, lineNum, Token.lexToken.CHRCON);
                    tokens.add(token);
                }
                curPos++;
                nowChar = source.charAt(curPos);
            }
            else if (reverseChar1.contains(Character.toString(nowChar)))
            {
                Token token = reverseToken(Character.toString(nowChar), lineNum);
                tokens.add(token);
                curPos++;
                nowChar = source.charAt(curPos);
            }
            else if (reverseChar2.contains(Character.toString(nowChar)))
            {
                StringBuilder tokenBuilder = new StringBuilder();
                while (curPos < source.length() && reverseChar2.contains(Character.toString(nowChar)))
                {
                    tokenBuilder.append(nowChar);
                    curPos++;
                    nowChar = source.charAt(curPos);
                }
                String curToken = tokenBuilder.toString();
                Token token = reverseToken(curToken, lineNum);
                tokens.add(token);
            }
            else if (reverseChar3.contains(Character.toString(nowChar)))
            {
                char before = nowChar;
                curPos++;
                nowChar = source.charAt(curPos);
                if (before == nowChar)
                {
                    String curToken = String.valueOf(before) + nowChar;
                    curPos++;
                    Token token = reverseToken(curToken, lineNum);
                    tokens.add(token);
                }
                else
                {
                    CompileError error = new CompileError(lineNum, "a");
                    errors.add(error);
                }
            }
            else if (nowChar == '/')
            {
                curPos++;
                nowChar = source.charAt(curPos);
                if (nowChar == '/')
                {
                    while (curPos < source.length() && nowChar != '\n')
                    {
                        curPos++;
                        nowChar = source.charAt(curPos);
                    }
                }
                else if (nowChar == '*')
                {
                    char nextChar;
                    while (curPos < source.length())
                    {
                        curPos++;
                        nowChar = source.charAt(curPos);
                        nextChar = source.charAt(curPos + 1);
                        if (nowChar == '*' && nextChar == '/') break;
                    }
                    curPos = curPos + 2;
                    nowChar = source.charAt(curPos);
                }
                else
                {
                    Token token = new Token("/", lineNum, Token.lexToken.DIV);
                    tokens.add(token);
                }
            }
            else if (nowChar == '\n')
            {
                addLineNum();
                skipChar();
            }
            else
            {
                skipChar();
            }
        }
    }

    public void skipChar()
    {
        curPos = curPos + 1;
    }

    public void addLineNum()
    {
        lineNum = lineNum + 1;
    }

    public boolean reverse(String word)
    {
        return reverseWords.containsKey(word);
    }

    public Token reverseToken(String word, int line)
    {
        Token.lexToken type = reverseWords.get(word);
        return new Token(word, line, type);
    }
}
