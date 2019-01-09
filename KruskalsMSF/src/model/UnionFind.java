package model;

import java.util.ArrayList;
import java.util.List;

public class UnionFind {

    private final List<Node> nodeList;

    public UnionFind() {
        nodeList = new ArrayList<>();
    }

    public List<Node> getNodeList() {
        return nodeList;
    }

    public int size() {
        return nodeList.size();
    }
}
