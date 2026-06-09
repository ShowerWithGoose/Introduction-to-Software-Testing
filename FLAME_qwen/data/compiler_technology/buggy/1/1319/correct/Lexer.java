import java.util.List;

public class Lexer
{
    private final String input;
    private int pos;
    private char currentChar;
    private int lineno;


    public Lexer(String input)
    {
        this.input = input;
        this.pos = 0;
        this.lineno = 1;
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
                Compiler.tokens.add(new Token("INTCON", intConst(), lineno));
            else if (Character.isLetter(currentChar) || currentChar == '_')
                Compiler.tokens.add(ident());
            else if (currentChar == '"' )
                Compiler.tokens.add(new Token("STRCON", stringConst(), lineno));
            else if (currentChar == '\'')
                Compiler.tokens.add(new Token("CHRCON", charConst(), lineno));
            else
                switch (currentChar)
                {
                    case '+': Compiler.tokens.add(new Token("PLUS", "+", lineno)); advance(); break;
                    case '-': Compiler.tokens.add(new Token("MINU", "-", lineno)); advance(); break;
                    case '*': Compiler.tokens.add(new Token("MULT", "*", lineno)); advance(); break;
                    case '%': Compiler.tokens.add(new Token("MOD", "%", lineno)); advance(); break;
                    case ',': Compiler.tokens.add(new Token("COMMA", ",", lineno)); advance(); break;
                    case ';': Compiler.tokens.add(new Token("SEMICN", ";", lineno)); advance(); break;
                    case '(': Compiler.tokens.add(new Token("LPARENT", "(", lineno)); advance(); break;
                    case ')': Compiler.tokens.add(new Token("RPARENT", ")", lineno)); advance(); break;
                    case '[': Compiler.tokens.add(new Token("LBRACK", "[", lineno)); advance(); break;
                    case ']': Compiler.tokens.add(new Token("RBRACK", "]", lineno)); advance(); break;
                    case '{': Compiler.tokens.add(new Token("LBRACE", "{", lineno)); advance(); break;
                    case '}': Compiler.tokens.add(new Token("RBRACE", "}", lineno)); advance(); break;

                    case '<':
                        advance();
                        if (currentChar == '=')
                        {
                            Compiler.tokens.add(new Token("LEQ", "<=", lineno));
                            advance();
                        }
                        else
                            Compiler.tokens.add(new Token("LSS", "<", lineno));
                        break;
                    case '>':
                        advance();
                        if (currentChar == '=')
                        {
                            Compiler.tokens.add(new Token("GEQ", ">=", lineno));
                            advance();
                        }
                        else
                            Compiler.tokens.add(new Token("GRE", ">", lineno));
                        break;
                    case '=':
                        advance();
                        if (currentChar == '=')
                        {
                            Compiler.tokens.add(new Token("EQL", "==", lineno));
                            advance();
                        }
                        else
                            Compiler.tokens.add(new Token("ASSIGN", "=", lineno));
                        break;
                    case '!':
                        advance();
                        if (currentChar == '=')
                        {
                            Compiler.tokens.add(new Token("NEQ", "!=", lineno));
                            advance();
                        }
                        else
                            Compiler.tokens.add(new Token("NOT", "!", lineno));
                        break;
                    case '|':
                        advance();
                        if (currentChar == '|')
                        {
                            Compiler.tokens.add(new Token("OR", "||", lineno));
                            advance();
                        }
                        else
                        {
                            Compiler.errors.add(new Errors(lineno, 'a'));
                            Compiler.tokens.add(new Token("OR", "||", lineno));
                            Compiler.isError = true;
                        }
                        break;
                    case '&':
                        advance();
                        if (currentChar == '&')
                        {
                            Compiler.tokens.add(new Token("AND", "&&", lineno));
                            advance();
                        }
                        else
                        {
                            Compiler.errors.add(new Errors(lineno, 'a'));
                            Compiler.tokens.add(new Token("AND", "&&", lineno));
                            Compiler.isError = true;
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
                            lineno++;
                        }
                        else if(currentChar == '*')
                        {
                            advance();
                            advance();
                            while (!(currentChar == '/' && input.charAt(pos-1) == '*') && currentChar != '\0')
                                advance();
                            advance();
                        }
                        else
                            Compiler.tokens.add(new Token("DIV", "/", lineno));
                        break;
                    default: advance(); break;
                }
        }
        return Compiler.tokens;
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
        return result.toString();
    }


    private String stringConst() {
        StringBuilder result = new StringBuilder();
        result.append(currentChar);
        advance();
        while (currentChar != '\0' && currentChar != '"')
        {
            result.append(currentChar);
            if (currentChar == '\\'){
                advance();
                if (currentChar != 'n'){
                    Compiler.isError = true;
                    Compiler.errors.add(new Errors(lineno, 'a'));
                    result.append('n');
                }
            }
            else
                advance();
        }

        if (currentChar == '"')
        {
            result.append(currentChar);
            advance();
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
            case "main" -> new Token("MAINTK", s, lineno);
            case "const" -> new Token("CONSTTK", s, lineno);
            case "int" -> new Token("INTTK", s, lineno);
            case "char" -> new Token("CHARTK", s, lineno);
            case "break" -> new Token("BREAKTK", s, lineno);
            case "continue" -> new Token("CONTINUETK", s, lineno);
            case "if" -> new Token("IFTK", s, lineno);
            case "else" -> new Token("ELSETK", s, lineno);
            case "for" -> new Token("FORTK", s, lineno);
            case "getint" -> new Token("GETINTTK", s, lineno);
            case "getchar" -> new Token("GETCHARTK", s, lineno);
            case "printf" -> new Token("PRINTFTK", s, lineno);
            case "return" -> new Token("RETURNTK", s, lineno);
            case "void" -> new Token("VOIDTK", s, lineno);
            default -> new Token("IDENFR", s, lineno);
        };
    }
}
