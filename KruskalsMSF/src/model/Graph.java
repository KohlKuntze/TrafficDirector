package model;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Graph {

    private final Map<Node, Set<Edge>> edgeMap;
//    private final Node sourceVertex;
//    private final Node destinationVertex;

    public Graph() {
        this.edgeMap = new HashMap<>();
    }

    public Map<Node, Set<Edge>> getEdgeMap() {
        return edgeMap;
    }


    public static int getSum(int[] arr) {
        int sum = 0;

        for(int i = 0; i < arr.length; i++) {
            sum += i;
        }

        return sum;
    }

}
