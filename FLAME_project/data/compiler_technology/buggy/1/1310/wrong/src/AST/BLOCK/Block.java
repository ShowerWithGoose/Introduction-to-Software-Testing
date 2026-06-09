package src.AST.BLOCK;

import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class Block {
    private boolean haveBlockItem;
    private Word lBrace;
    private ArrayList<BlockItem> blockItemList;
    private Word rBrace;

    public Block() {
        this.haveBlockItem = false;
        this.blockItemList = new ArrayList<>();
    }

    public Block analyse() {
        this.lBrace = utils.read("{");
        if (utils.preRead(1) != WordType.RBRACE) {
            this.haveBlockItem = true;
            while (utils.preRead(1) != WordType.RBRACE) {
                this.blockItemList.add(new BlockItem().analyse());
            }
        }
        this.rBrace = utils.read("}");
        syntaxList.add("<" + SyntaxType.Block + ">");
        return this;
    }
}
