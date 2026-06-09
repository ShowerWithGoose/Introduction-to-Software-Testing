package mainSys;

import static java.lang.Character.*;
import static mainSys.Parser.*;
import static mainSys.StaticValues.*;
import static mainSys.Tools.ParseTool.*;

public class Lexer {
    public static void lex() {
        while (true) {
            if (isEnd()) {break;}
            else if(getChar() == '\n'){
                movePos();
                line++;
                continue;
            }
            else if (getChar() == ' ') {
                movePos();
                continue;
            }
            char c = getChar();
            if (isLetter(c)) {
                parseWord();
            } else if (isDigit(c)) {
                parseINTCON();
            }else {
                switch (c) {
                    case '_':
                        parseIDENFR();
                        break;
                    case '\"':
                        parseSTRCON();
                        break;
                    case '\'':
                        parseCHRCON();
                        break;
                    default:
                        parseSigns();
                        break;
                }
            }
        }

    }

}
