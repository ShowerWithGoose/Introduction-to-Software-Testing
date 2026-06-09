package frontend.Parser.Class;

import java.util.ArrayList;

public class Character {
    private String character;

    public Character(String character, ArrayList<String> outputList) {
        this.character = character;
        outputList.add("<Character>");
    }
}
