package frontend.Parser.Val;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Exp.Exp;
import frontend.Parser.Exp.ExpParser;
import frontend.Parser.solid.StringConstParser;

import java.util.ArrayList;

// InitVal â†’ Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
public class InitValParser {
    private TokenListReader reader;
    private Token lbrace;
    private Exp first;
    private ArrayList<Token> commas = new ArrayList<>(); // ','
    private ArrayList<Exp> exps = new ArrayList<>();
    private Token rbrace; // '}'
    private InitValInf initValInf = null;


    public InitValParser(TokenListReader reader) {
        this.reader = reader;
    }

    public InitVal parseInitVal() {
        this.lbrace = this.reader.getnextToken();
        if(this.lbrace.getType().equals(TokenType.STRCON)) {
            this.reader.backward(1);
            StringConstParser strConstParser = new StringConstParser(this.reader);
            this.initValInf = strConstParser.parseStringConst();
        }
        else if (this.lbrace.getType().equals(TokenType.LBRACE)) {
            Token token = this.reader.getnextToken();
            if (!token.getType().equals(TokenType.RBRACE)) {
                this.reader.backward(1);
                ExpParser expParser = new ExpParser(this.reader);
                this.first = expParser.parseExp();
                token = this.reader.getnextToken();
                while (token.getType().equals(TokenType.COMMA)) {
                    this.commas.add(token);
                    this.exps.add(expParser.parseExp());
                    token = this.reader.getnextToken();
                }
            }
            this.rbrace = token;
            initValInf = new InitValExps(this.lbrace, this.first, this.commas, this.exps, this.rbrace);
        } else {
            this.reader.backward(1);
            ExpParser expParser = new ExpParser(this.reader);
            this.initValInf = expParser.parseExp();
        }
        InitVal initVal = new InitVal(this.initValInf);
        return initVal;
    }


}
