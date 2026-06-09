package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Block {
    private Token lbrace;
    private ArrayList<BlockItem> blockItems;
    private Token rbrace;
    private int lineCnt;

    public Block() {
        lbrace = null;
        blockItems = new ArrayList<>();
        rbrace = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        lbrace = lexer.now();
        lexer.move();
        while (lexer.now().getType() != Token.Type.RBRACE) {
            BlockItem blockItem = new BlockItem();
            blockItem.parser(lexer);
            blockItems.add(blockItem);
        }
        rbrace = lexer.now();
        lexer.move();
        lineCnt = lbrace.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyzeFunc(SymbolTable symbolTable, FuncFParams params, boolean hasReturn) {
        symbolTable.addDomainCnt();
        int domainNum = symbolTable.getDomainCnt();
        symbolTable.addDomainNum(domainNum);
        if (params != null) {
            params.analyze(symbolTable);
        }
        for (BlockItem blockItem : blockItems) {
            blockItem.analyze(symbolTable);
        }
        if (hasReturn) {
            if (blockItems.isEmpty()) {
                symbolTable.addError(rbrace.getLineCnt() + " g");
            } else {
                int last = blockItems.size() - 1;
                BlockItem lastBlockItem = blockItems.get(last);
                if (!lastBlockItem.isReturnStmt()) {
                    symbolTable.addError(rbrace.getLineCnt() + " g");
                }
            }
        }
        symbolTable.removeDomainNum();
    }

    public void analyzeMain(SymbolTable symbolTable) {
        symbolTable.addDomainCnt();
        int domainNum = symbolTable.getDomainCnt();
        symbolTable.addDomainNum(domainNum);
        for (BlockItem blockItem : blockItems) {
            blockItem.analyze(symbolTable);
        }
        if (blockItems.isEmpty()) {
            symbolTable.addError(rbrace.getLineCnt() + " g");
        } else {
            int last = blockItems.size() - 1;
            BlockItem lastBlockItem = blockItems.get(last);
            if (!lastBlockItem.isReturnStmt()) {
                symbolTable.addError(rbrace.getLineCnt() + " g");
            }
        }
        symbolTable.removeDomainNum();
    }

    public void analyze(SymbolTable symbolTable) {
        symbolTable.addDomainCnt();
        int domainNum = symbolTable.getDomainCnt();
        symbolTable.addDomainNum(domainNum);
        for (BlockItem blockItem : blockItems) {
            blockItem.analyze(symbolTable);
        }
        symbolTable.removeDomainNum();
    }
}