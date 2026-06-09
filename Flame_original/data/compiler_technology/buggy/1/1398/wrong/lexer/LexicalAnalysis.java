package lexer;

import error.Error;
import error.ErrorList;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class LexicalAnalysis{
    String[] keyword = {"main", "const", "int", "char", "break", "continue", "if", "else", "for", "getint", "getchar", "printf",
            "return", "void"};
//    String[] operation = {"!", "&&", "||", "+", "-", "*", "/", "%", "<", "<=", ">", ">=", "==", "!=", "="};
//    String[] symbol = {",", ";", "(", ")", "[", "]", "{", "}"};
    ArrayList<String> keywords = new ArrayList<>(List.of(keyword));
    HashMap<String,TokenType> keyToToken = new HashMap<>();
    private final ArrayList<Token> tokens = new ArrayList<>();
    public ArrayList<Token> getTokens() {
        return tokens;
    }
    int line, pos;
    String curString;
    char curChar;
    File file = new File("testfile.txt");
    Scanner in;
    {
        try
        {
            in = new Scanner(file);
        } catch (FileNotFoundException e)
        {
            throw new RuntimeException(e);
        }
    }


    public void init() {
        keyToToken.put("main",TokenType.MAIN);
        keyToToken.put("const",TokenType.CONST);
        keyToToken.put("int",TokenType.INT);
        keyToToken.put("char",TokenType.CHAR);
        keyToToken.put("break",TokenType.BREAK);
        keyToToken.put("continue",TokenType.CONTINUE);
        keyToToken.put("if",TokenType.IF);
        keyToToken.put("else",TokenType.ELSE);
        keyToToken.put("for",TokenType.FOR);
        keyToToken.put("getint",TokenType.GETINT);
        keyToToken.put("getchar",TokenType.GETCHAR);
        keyToToken.put("printf",TokenType.PRINTF);
        keyToToken.put("return",TokenType.RETURN);
        keyToToken.put("+",TokenType.PLUS);
        keyToToken.put("-",TokenType.MINU);
        keyToToken.put("!",TokenType.NOT);
        keyToToken.put("&&",TokenType.AND);
        keyToToken.put("||",TokenType.OR);
        keyToToken.put("void",TokenType.VOID);
        keyToToken.put("*",TokenType.MULT);
        keyToToken.put("/",TokenType.DIV);
        keyToToken.put("%",TokenType.MOD);
        keyToToken.put("<",TokenType.LSS);
        keyToToken.put("<=", TokenType.LEQ);
        keyToToken.put(">", TokenType.GRE);
        keyToToken.put(">=", TokenType.GEQ);
        keyToToken.put("==", TokenType.EQL);
        keyToToken.put("!=",TokenType.NEQ);
        keyToToken.put("=", TokenType.ASSIGN);
        keyToToken.put(";",TokenType.SEMICN);
        keyToToken.put(",", TokenType.COMMA);
        keyToToken.put("(",TokenType.LPARENT);
        keyToToken.put(")", TokenType.RPARENT);
        keyToToken.put("[", TokenType.LBRACK);
        keyToToken.put("]", TokenType.RBRACK);
        keyToToken.put("{",TokenType.LBRACE);
        keyToToken.put("}",TokenType.RBRACE);

    }


    public void run() throws FileNotFoundException {
        init();
        line = 1;
        while (in.hasNextLine())
        {
            curString = in.nextLine();
            handleCurrentLine();
            System.out.println(curString);
            line++;
        }
//        print();
    }

    public void print() throws FileNotFoundException {
        PrintStream origin = System.out;
        if (!ErrorList.getInstance().errors.isEmpty())
        {
            PrintStream out = new PrintStream("error.txt");
            System.setOut(out);
            ErrorList.getInstance().print();
        }
        else
        {
            PrintStream out = new PrintStream("lexer.txt");
            System.setOut(out);
            for (Token token : tokens)
            {
                token.print();
            }
        }
        System.setOut(origin);
    }

    private void handleCurrentLine() {
        pos = 0;
        curString = curString.trim();
        while (pos < curString.length())
        {
            curChar = curString.charAt(pos);
            if (Character.isWhitespace(curChar))
            {
                pos++;
            }
            else if (Character.isDigit(curChar))
            {
                handleDigit();
            }
            else if (Character.isLetter(curChar) || curChar == '_')
            {
                handleLetter();
            }
            else if (curChar == '\'')
            {
                handleChar();
            }
            else if (curChar == '\"')
            {
                handleString();
            }
            else
            {
                handleSymbol();
            }
        }
    }

    private void handleChar() {
        StringBuilder value = new StringBuilder();
        value.append("'");
        pos++;
        curChar = curString.charAt(pos);
        value.append(curChar);
        if (curChar == '\\')
        {
            pos++;
            curChar = curString.charAt(pos);
            value.append(curChar);
        }
        value.append("'");
        tokens.add(new Token(TokenType.CHRCON,value.toString(),line));
        pos += 2;
    }

    private void handleString() {
        StringBuilder value = new StringBuilder();
        value.append('"');
        pos++;
        while (pos < curString.length())
        {
            curChar = curString.charAt(pos);
            value.append(curChar);
            if (curChar == '\\')
            {
                curChar = curString.charAt(++pos);
                value.append(curChar);
            }
            else if (curChar == '"')
            {
                pos++;
                break;
            }
            pos++;
        }
        tokens.add(new Token(TokenType.STRCON,value.toString(),line));

    }

    private void handleSymbol() {
        if (curChar == '/')
        {
            if (curString.charAt(pos+1) == '/')
            {
                pos = curString.length();
                return;
            }
            else if (curString.charAt(pos+1) == '*')
            {
                while ( curString.length() < 2 || !curString.substring(curString.length() - 2).equals("*/") )
                {
                    line++;
                    curString = in.nextLine();
                }
                if (in.hasNextLine())
                {
                    curString = in.nextLine();
                    line++;
                    pos = 0;
                }
                else
                {
                    pos = curString.length();
                }
                return;
            }
        }
        StringBuilder value = new StringBuilder();
        value.append(curChar);
        if ((curChar == '<' || curChar == '>' || curChar == '=' || curChar == '!') && curString.charAt(pos+1) == '=')
        {
            value.append('=');
            pos += 2;
        }
        else if (curChar == '&' || curChar == '|')
        {
            if (curString.charAt(pos+1) == curChar)
            {
                value.append(curChar);
                pos += 2;
            }
            else
            {
                value.append(curChar);
                ErrorList.getInstance().errors.add(new Error(line,'a'));
                pos++;
            }
        }
        else
        {
            pos++;
        }
        TokenType type = keyToToken.get(value.toString());
        tokens.add(new Token(type,value.toString(),line));
    }

    private void handleLetter() {
        StringBuilder value = new StringBuilder();
        value.append(curChar);
        pos++;
        while (pos < curString.length())
        {
            curChar = curString.charAt(pos);
            if (Character.isLetter(curChar) || Character.isDigit(curChar) || curChar == '_')
            {
                value.append(curChar);
                pos++;
            }
            else
            {
                break;
            }
        }
        if (keywords.contains(value.toString()))
        {
            TokenType type = keyToToken.get(value.toString());
            tokens.add(new Token(type,value.toString(),line));
        }
        else
        {
            tokens.add(new Token(TokenType.IDENFR, value.toString(), line));
        }

    }

    private void handleDigit() {
        StringBuilder value = new StringBuilder();
        value.append(curChar);
        pos++;
        while (pos < curString.length())
        {
            curChar = curString.charAt(pos);
            if (Character.isDigit(curChar))
            {
                value.append(curChar);
                pos++;
            }
            else
            {
                break;
            }
        }
        tokens.add(new Token(TokenType.INTCON,value.toString(),line));
    }

}
