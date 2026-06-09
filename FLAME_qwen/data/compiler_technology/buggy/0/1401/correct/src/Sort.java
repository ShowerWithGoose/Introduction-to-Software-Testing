package src;

public class Sort {
    private Words words;
    private Phrase phrase;
    private Integer line;
private Errors error ;
    public Sort(Phrase phrase, Words words, Errors error) {
        this.words = words;
        this.phrase = phrase;
        line = 1;
        this.error=error;
    }

    public void work() {
        Character character = words.get();
        while (character == ' ') {
            character = words.get();
        }
        Class cl = new Class();
        cl.add(character);
        if (Character.isLetter(character) || character == '_') {
            character = words.get();
            while (Character.isDigit(character) || Character.isLetter(character) || character == '_') {
                cl.add(character);
                character = words.get();
            }
            words.back();
            Words words1 = new Words(cl.getName().toString().replace(",","").replace("[","").replace("]","").replace(" ",""));
            character = words1.get();
            Class cl2 = new Class();
            cl2.add(character);
            switch (character) {
                case 'c':
                    if(c(cl2,words1)){
                        return;
                    }
                    words1.fresh();
                case 'i':
                    if(i(cl2,words1)){
                        return;
                    }
                    words1.fresh();
                case 'm':
                    if(m(cl2,words1)){
                        return;
                    }
                    words1.fresh();
                case 'v':
                    if(v(cl2,words1)){
                        return;
                    }
                    words1.fresh();
                case 'f':
                    if(f(cl2,words1)){
                        return;
                    }
                    words1.fresh();
                case 'e':
                    if(e(cl2,words1)) {
                        return;
                    }
                    words1.fresh();
                case 'b':
                    if(b(cl2,words1)) {
                        return;
                    }
                    words1.fresh();
                case 'r':
                    if(r(cl2,words1)){
                        return;
                    }
                    words1.fresh();
                case 'p':
                    if(p(cl2,words1)){
                        return;
                    }
                    words1.fresh();
                case 'g':
                    if(g(cl2,words1)){
                        return;
                    }
                    words1.fresh();
                default:
                    cl.IDENFR();
                    phrase.addclass(cl);
                    return;
            }
        }
        if (Character.isDigit(character)) {
            character = words.get();
            while (Character.isDigit(character)) {
                cl.add(character);
                character = words.get();
            }
            words.back();
            cl.INTCON();
            phrase.addclass(cl);
            return;
        }
        switch (character) {
            case '!':
                character = words.get();
                if (character == '=') {
                    cl.add(character);

                    cl.NEQ();
                    phrase.addclass(cl);
                } else {
                    words.back();
                    cl.NOT();
                    phrase.addclass(cl);
                }
                break;
            case '+':
                cl.PLUS();
                phrase.addclass(cl);
                break;
            case '-':
                cl.MINU();
                phrase.addclass(cl);
                break;
            case '*':
                cl.MULT();
                phrase.addclass(cl);
                break;
            case '/':
                character = words.get();
                if (character == '/') {
                    while (character != '\n') {
                        character = words.get();
                    }
                    words.back();
                } else if (character == '*') {
                    while (true) {
                        character = words.get();
                        if (character == '\n') {
                            line++;
                        }
                        if (character == '*') {
                            character = words.get();
                            while (character == '*') {
                                character = words.get();
                            }
                            if (character == '/') {
                                break;
                            }
                        }
                    }
                } else {
                    cl.DIV();
                    phrase.addclass(cl);
                    words.back();
                }

                break;
            case '%':
                cl.MOD();
                phrase.addclass(cl);
                break;
            case ';':
                cl.SEMICN();
                phrase.addclass(cl);
                break;
            case ',':
                cl.COMMA();
                phrase.addclass(cl);
                break;
            case '(':
                cl.LPARENT();
                phrase.addclass(cl);
                break;
            case ')':
                cl.RPARENT();
                phrase.addclass(cl);
                break;
            case '{':
                cl.LBRACE();
                phrase.addclass(cl);
                break;
            case '}':
                cl.RBRACE();
                phrase.addclass(cl);
                break;
            case '[':
                cl.LBRACK();
                phrase.addclass(cl);
                break;
            case ']':
                cl.RBRACK();
                phrase.addclass(cl);
                break;
            case '<':
                character = words.get();
                if (character == '=') {
                    cl.add(character);

                    cl.LEQ();
                    phrase.addclass(cl);
                } else {
                    words.back();
                    cl.LSS();
                    phrase.addclass(cl);
                }
                break;
            case '>':
                character = words.get();
                if (character == '=') {
                    cl.add(character);

                    cl.GEQ();
                    phrase.addclass(cl);
                } else {
                    words.back();
                    cl.GRE();
                    phrase.addclass(cl);
                }
                break;
            case '=':
                character = words.get();
                if (character == '=') {
                    cl.add(character);

                    cl.EQL();
                    phrase.addclass(cl);
                } else {
                    words.back();
                    cl.ASSIGN();
                    phrase.addclass(cl);
                }
                break;
            case '|':
                character = words.get();
                if (character == '|') {
                    cl.add(character);

                    cl.OR();
                    phrase.addclass(cl);
                } else {
                    cl.OR();
                    phrase.addclass(cl);
                    words.back();
                    error();
                }
                break;
            case '&':
                character = words.get();
                if (character == '&') {
                    cl.add(character);

                    cl.AND();
                    phrase.addclass(cl);
                } else {
                    cl.AND();
                    phrase.addclass(cl);
                    words.back();
                    error();
                }
                break;
            case '\n':
                line++;
                break;
            case '\"':
                char character1=character;
                character = words.get();
                while (true) {
                    if(character=='\"'&&character1!='\\'){
                        cl.add(character);
                        cl.STRCON();
                        phrase.addclass(cl);
                        break;
                    }
                    cl.add(character);
                    character1=character;
                    character = words.get();
                }
                break;
            case '\'':
                character = words.get();
                cl.add(character);
                if(character=='\\'){
                    character = words.get();
                    cl.add(character);
                }
                character = words.get();
                cl.add(character);
                cl.CHRCON();
                phrase.addclass(cl);
                break;
            default:

        }
    }

    private boolean e(Class cl, Words words) {
        Character character;
        character = words.get();
        if (character == 'l') {
            cl.add(character);
            character = words.get();
            if (character == 's') {
                cl.add(character);
                character = words.get();
                if (character == 'e') {
                    cl.add(character);
                    character = words.get();
                    if (character == '\n') {
                        words.back();
                        cl.ELSETK();
                        phrase.addclass(cl);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean b(Class cl, Words words) {
        Character character;
        character = words.get();
        if (character == 'r') {
            cl.add(character);
            character = words.get();
            if (character == 'e') {
                cl.add(character);
                character = words.get();
                if (character == 'a') {
                    cl.add(character);
                    character = words.get();
                    if (character == 'k') {
                        cl.add(character);
                        character = words.get();
                        if (character == ';' || character == '\n') {
                            words.back();
                            cl.BREAKTK();
                            phrase.addclass(cl);
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    private boolean r(Class cl, Words words) {
        Character character;
        character = words.get();
        if (character == 'e') {
            cl.add(character);
            character = words.get();
            if (character == 't') {
                cl.add(character);
                character = words.get();
                if (character == 'u') {
                    cl.add(character);
                    character = words.get();
                    if (character == 'r') {
                        cl.add(character);
                        character = words.get();
                        if (character == 'n') {
                            cl.add(character);
                            character = words.get();
                            if (character == ';' || character == '\n') {
                                words.back();
                                cl.RETURNTK();
                                phrase.addclass(cl);
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    private boolean p(Class cl, Words words) {
        Character character;
        character = words.get();
        if (character == 'r') {
            cl.add(character);
            character = words.get();
            if (character == 'i') {
                cl.add(character);
                character = words.get();
                if (character == 'n') {
                    cl.add(character);
                    character = words.get();
                    if (character == 't') {
                        cl.add(character);
                        character = words.get();
                        if (character == 'f') {
                            cl.add(character);
                            character = words.get();
                            if (character == '(' || character == '\n') {
                                words.back();
                                cl.PRINTFTK();
                                phrase.addclass(cl);
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    private boolean g(Class cl, Words words) {
        Character character;
        character = words.get();
        if (character == 'e') {
            cl.add(character);
            character = words.get();
            if (character == 't') {
                cl.add(character);
                character = words.get();
                if (character == 'i') {
                    cl.add(character);
                    character = words.get();
                    if (character == 'n') {
                        cl.add(character);
                        character = words.get();
                        if (character == 't') {
                            cl.add(character);
                            character = words.get();
                            if (character == '(' || character == '\n') {
                                words.back();
                                cl.GETINTTK();
                                phrase.addclass(cl);
                                return true;
                            }
                        }
                    }
                } else if (character == 'c') {
                    cl.add(character);
                    character = words.get();
                    if (character == 'h') {
                        cl.add(character);
                        character = words.get();
                        if (character == 'a') {
                            cl.add(character);
                            character = words.get();
                            if (character == 'r') {
                                cl.add(character);
                                character = words.get();
                                if (character == '\n') {
                                    words.back();
                                    cl.GETCHARTK();
                                    phrase.addclass(cl);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    private boolean f(Class cl, Words words) {
        Character character;
        character = words.get();
        if (character == 'o') {
            cl.add(character);
            character = words.get();
            if (character == 'r') {
                cl.add(character);
                character = words.get();
                if (character == '\n') {
                    words.back();
                    cl.FORTK();
                    phrase.addclass(cl);
                    return true;
                }
            }
        }
        return false;
    }

    private boolean v(Class cl, Words words) {
        Character character;
        character = words.get();
        if (character == 'o') {
            cl.add(character);
            character = words.get();
            if (character == 'i') {
                cl.add(character);
                character = words.get();
                if (character == 'd') {
                    cl.add(character);
                    character = words.get();
                    if (character == '\n') {
                        words.back();
                        cl.VOIDTK();
                        phrase.addclass(cl);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean m(Class cl, Words words) {
        Character character;
        character = words.get();
        if (character == 'a') {
            cl.add(character);
            character = words.get();
            if (character == 'i') {
                cl.add(character);
                character = words.get();
                if (character == 'n') {
                    cl.add(character);
                    character = words.get();
                    if (character == '\n') {
                        words.back();
                        cl.MAINTK();
                        phrase.addclass(cl);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean i(Class cl, Words words) {
        Character character;
        character = words.get();
        if (character == 'n') {
            cl.add(character);
            character = words.get();
            if (character == 't') {
                cl.add(character);
                character = words.get();
                if (character == '\n') {
                    words.back();
                    cl.INTTK();
                    phrase.addclass(cl);
                    return true;
                }
            }
        } else if (character == 'f') {
            cl.add(character);
            character = words.get();
            if (character == '\n' || character == '(') {
                words.back();
                cl.IFTK();
                phrase.addclass(cl);
                return true;
            }
        }
        return false;
    }

    private boolean c(Class cl, Words words) {
        Character character;
        character = words.get();
        if (character == 'o') {
            cl.add(character);
            character = words.get();
            if (character == 'n') {
                cl.add(character);
                character = words.get();
                if (character == 's') {
                    cl.add(character);
                    character = words.get();
                    if (character == 't') {
                        cl.add(character);
                        character = words.get();
                        if (character == '\n') {
                            words.back();
                            cl.CONSTTK();
                            phrase.addclass(cl);
                            return true;
                        }
                    }
                } else if (character == 't') {
                    cl.add(character);
                    character = words.get();
                    if (character == 'i') {
                        cl.add(character);
                        character = words.get();
                        if (character == 'n') {
                            cl.add(character);
                            character = words.get();
                            if (character == 'u') {
                                cl.add(character);
                                character = words.get();
                                if (character == 'e') {
                                    cl.add(character);
                                    character = words.get();
                                    if (character == '\n' || character == ';') {
                                        words.back();
                                        cl.CONTINUETK();
                                        phrase.addclass(cl);
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (character == 'h') {
            cl.add(character);
            character = words.get();
            if (character == 'a') {
                cl.add(character);
                character = words.get();
                if (character == 'r') {
                    cl.add(character);
                    character = words.get();
                    if (character == '\n') {
                        words.back();
                        cl.CHARTK();
                        phrase.addclass(cl);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private void error() {
        error.add(new Error(line,Error_Enum.a));
    }
}
