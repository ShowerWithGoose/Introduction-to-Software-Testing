import java.util.ArrayList;
import java.util.List;

public class Lexer
{
    private final String input;
    private int pos;
    private char currentChar;
    private int lineno;
    public boolean isError;

    public List<Token> tokens = new ArrayList<>();
    public List<Errors> errors = new ArrayList<>();

    public Lexer(String input)
    {
        this.input = input;
        this.pos = 0;
        this.lineno = 1;
        this.isError = false;
        this.currentChar = input.charAt(pos);
    }

    private void advance()
    {
        pos++;
        if (pos >= input.length())
            currentChar = '\0';
        else
            currentChar = input.charAt(pos);
    }

    public List<Token> tokenize()
    {
        while (currentChar != '\0')
        {
            if (Character.isWhitespace(currentChar))
            {
                if (currentChar == '\n')
                    lineno++;
                advance();
            }
            else if (Character.isDigit(currentChar))
                tokens.add(new Token("INTCON", intConst()));
            else if (Character.isLetter(currentChar) || currentChar == '_')
                tokens.add(ident());
            else if (currentChar == '"' )
                tokens.add(new Token("STRCON", stringConst()));
            else if (currentChar == '\'')
                tokens.add(new Token("CHRCON", charConst()));
            else
                switch (currentChar)
                {
                    case '+': tokens.add(new Token("PLUS", "+")); advance(); break;
                    case '-': tokens.add(new Token("MINU", "-")); advance(); break;
                    case '*': tokens.add(new Token("MULT", "*")); advance(); break;
                    case '%': tokens.add(new Token("MOD", "%")); advance(); break;
                    case ',': tokens.add(new Token("COMMA", ",")); advance(); break;
                    case ';': tokens.add(new Token("SEMICN", ";")); advance(); break;
                    case '(': tokens.add(new Token("LPARENT", "(")); advance(); break;
                    case ')': tokens.add(new Token("RPARENT", ")")); advance(); break;
                    case '[': tokens.add(new Token("LBRACK", "[")); advance(); break;
                    case ']': tokens.add(new Token("RBRACK", "]")); advance(); break;
                    case '{': tokens.add(new Token("LBRACE", "{")); advance(); break;
                    case '}': tokens.add(new Token("RBRACE", "}")); advance(); break;

                    case '<':
                        advance();
                        if (currentChar == '=')
                        {
                            tokens.add(new Token("LEQ", "<="));
                            advance();
                        }
                        else
                            tokens.add(new Token("LSS", "<"));
                        break;
                    case '>':
                        advance();
                        if (currentChar == '=')
                        {
                            tokens.add(new Token("GEQ", ">="));
                            advance();
                        }
                        else
                            tokens.add(new Token("GRE", ">"));
                        break;
                    case '=':
                        advance();
                        if (currentChar == '=')
                        {
                            tokens.add(new Token("EQL", "=="));
                            advance();
                        }
                        else
                            tokens.add(new Token("ASSIGN", "="));
                        break;
                    case '!':
                        advance();
                        if (currentChar == '=')
                        {
                            tokens.add(new Token("NEQ", "!="));
                            advance();
                        }
                        else
                            tokens.add(new Token("NOT", "!"));
                        break;
                    case '|':
                        advance();
                        if (currentChar == '|')
                        {
                            tokens.add(new Token("OR", "||"));
                            advance();
                        }
                        else
                        {
                            errors.add(new Errors(lineno, 'a'));
                            isError = true;
                        }
                        break;
                    case '&':
                        advance();
                        if (currentChar == '&')
                        {
                            tokens.add(new Token("AND", "&&"));
                            advance();
                        }
                        else
                        {
                            errors.add(new Errors(lineno, 'a'));
                            isError = true;
                        }
                        break;
                    case '/':
                        advance();
                        if (currentChar == '/')
                        {
                            do {
                                advance();
                            }while (currentChar != '\n' && currentChar != '\0');
                            advance();
                        }
                        else if(currentChar == '*')
                        {
                            do {
                                do {
                                    advance();
                                } while (currentChar != '*' && currentChar != '\0');
                                advance();
                            } while (currentChar != '/' && currentChar != '\0');
                            advance();
                        }
                        else
                        {
                            tokens.add(new Token("DIV", "/"));
                            advance();
                        }
                        break;
                    default: advance(); break;
                }
        }
        return tokens;
    }

    private String intConst()
    {
        StringBuilder result = new StringBuilder();
        while (currentChar != '\0' && Character.isDigit(currentChar))
        {
            result.append(currentChar);
            advance();
        }
        return result.toString();
    }

    private String charConst()
    {
        StringBuilder result = new StringBuilder();
        result.append(currentChar);
        advance();
        if (currentChar == '\\')
        {
            result.append(currentChar);
            advance();
        }
        result.append(currentChar);
        advance();
        if (currentChar == '\'')
        {
            result.append(currentChar);
            advance();
        }
        else
        {
            //erors.add(new Eror(lineno, 'b'));
            //isError = true;
        }
        return result.toString();
    }


    private String stringConst() {
        StringBuilder result = new StringBuilder();
        result.append(currentChar);
        advance();
        while (currentChar != '\0' && currentChar != '"')
        {
            result.append(currentChar);
            advance();
        }

        if (currentChar == '"')
        {
            result.append(currentChar);
            advance();
        }
        else
        {
            //erors.add(new Eror(lineno, 'b'));
            //isError = true;
        }
        return result.toString();
    }


    private Token ident()
    {
        StringBuilder result = new StringBuilder();
        while (currentChar != '\0' && (Character.isLetterOrDigit(currentChar) || currentChar == '_'))
        {
            result.append(currentChar);
            advance();
        }

        String s = result.toString();
        return switch (s) {
            case "main" -> new Token("MAINTK", s);
            case "const" -> new Token("CONSTTK", s);
            case "int" -> new Token("INTTK", s);
            case "char" -> new Token("CHARTK", s);
            case "break" -> new Token("BREAKTK", s);
            case "continue" -> new Token("CONTINUETK", s);
            case "if" -> new Token("IFTK", s);
            case "else" -> new Token("ELSETK", s);
            case "for" -> new Token("FORTK", s);
            case "getint" -> new Token("GETINTTK", s);
            case "getchar" -> new Token("GETCHARTK", s);
            case "printf" -> new Token("PRINTFTK", s);
            case "return" -> new Token("RETURNTK", s);
            case "void" -> new Token("VOIDTK", s);
            default -> new Token("IDENFR", s);
        };
    }
}
