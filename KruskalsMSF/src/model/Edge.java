package model;

public class Edge implements Comparable<Edge> {

    private final Node sourceVertex;
    private final Node destinationVertex;
    private final int weight;

    public Edge(Node sourceVertex, Node destinationVertex, int weight) {
        this.sourceVertex = sourceVertex;
        this.destinationVertex = destinationVertex;
        this.weight = weight;
    }

    public Node getSourceVertex() {
        return sourceVertex;
    }

    public Node getDestinationVertex() {
        return destinationVertex;
    }

    public int getWeight() {
        return weight;
    }

    @Override
    public int compareTo(Edge o) {
        if(sourceVertex.compareTo(o.getSourceVertex()) == 0 && destinationVertex.compareTo(o.getDestinationVertex()) == 0) {
            return 0;
        } else {
            return weight - o.getWeight();
        }
    }
}
