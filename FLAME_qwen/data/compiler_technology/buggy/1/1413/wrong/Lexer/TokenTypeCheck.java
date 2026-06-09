package Lexer;

/**
 * @Description:
 * @date 2024/9/24
 */
public class TokenTypeCheck {

    public String tokenTypeCheck(String tokenValue)
    {
        if(tokenValue.equals("main"))
            return "MAINTK";
        else if(tokenValue.equals("const"))
            return "CONSTTK";
        else if(tokenValue.equals("int"))
            return "INTTK";
        else if(tokenValue.equals("char"))
            return "CHARTK";
        else if(tokenValue.equals("break"))
            return "BREAKTK";
        else if(tokenValue.equals("continue"))
            return "CONTINUETK";
        else if(tokenValue.equals("if"))
            return "IFTK";
        else if(tokenValue.equals("else"))
            return "ELSETK";
        else if(tokenValue.equals("for"))
            return "FORTK";
        else if(tokenValue.equals("getint"))
            return "GETINTTK";
        else if(tokenValue.equals("getchar"))
            return "GETCHARTK";
        else if(tokenValue.equals("printf"))
            return "PRINTFTK";
        else if(tokenValue.equals("return"))
            return "RETURNTK";
        else if(tokenValue.equals("void"))
            return "VOIDTK";
        else
            return "IDENFR";
    }
}