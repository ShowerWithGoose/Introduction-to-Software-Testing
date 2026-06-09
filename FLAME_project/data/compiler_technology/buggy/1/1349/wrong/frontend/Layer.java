package frontend;

import frontend.Def.Def;

import java.util.ArrayList;

public class Layer {
    private String type;

    public ArrayList<Layer> layers = new ArrayList<>();

    public ArrayList<Def> declares = new ArrayList<>();

    private Layer father;

    public Layer(String type) {
        this.type = type;
        father = null;
    }

    public Layer addNewLayer(String type) {
        Layer layer = new Layer(type);
        this.layers.add(layer);
        layer.father = this;
        return layer;
    }

    public void addDeclare(Def def) {
        this.declares.add(def);
    }

    public String getType() {
        return this.type;
    }

    public Layer getFather() {
        return this.father;
    }
}
