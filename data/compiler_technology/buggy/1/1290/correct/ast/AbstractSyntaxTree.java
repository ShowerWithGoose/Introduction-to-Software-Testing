package ast;

import error.Logger;
import error.ParsingException;
import lexical.Lexer;

import java.util.ArrayList;

public class AbstractSyntaxTree implements ast {

    private final Lexer lexer;

    private final Logger logger;

    private Symbol symbol;

    public AbstractSyntaxTree(Lexer lexer, Logger logger) {
        this.lexer = lexer;
        this.logger = logger;
    }

    @Override
    public void parse() {
        Symbol.lexer = this.lexer;
        Symbol.logger = this.logger;
        Symbol.token = lexer.nextToken();
        symbol = CompUnit.of();
        if (symbol == null) {
            throw new ParsingException("parsing error");
        }
    }

    @Override
    public void print() {
        print(0, symbol);
    }

    public void print(int depth, Ele ele) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < depth; i++) {
            sb.append("\t");
        }
        sb.append("- ").append(ele.toString());
        logger.log(sb.toString());
        if (ele instanceof Symbol) {
            Symbol symbol1 = (Symbol) ele;
            ArrayList<Ele> list = symbol1.getList();
            for (Ele e : list) {
                print(depth + 1, e);
            }
        }
    }

    @Override
    public void printAns() {
        printAns(symbol);
    }

    public void printAns(Ele ele) {
        StringBuilder sb = new StringBuilder();
        if (ele instanceof Symbol) {
            Symbol symbol1 = (Symbol) ele;
            ArrayList<Ele> list = symbol1.getList();
            for (Ele e : list) {
                printAns(e);
            }
        }
        sb.append(ele.toString());
        logger.log(sb.toString());
    }

    @Override
    public Symbol getSymbol() {
        return symbol;
    }

}
