package frontend.nodes;

import frontend.LexType;
import frontend.NodeType;

public class Character extends Node {
    public Character() {
        super(NodeType.CHARACTER);
    }

    public static Node parse() {
        Character character = new Character();
        character.terminalCheck(LexType.CHRCON);
        return character;
    }
}
