package app;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.*;

public class KruskalsMSF {

    // -------------------- APP --------------------

    public static void main(String[] args) {
        // Get graph
        Graph graph = GraphDataInput.getGraphFromFile(args[0]);

        // Create and run component
        KruskalsMSFComponent component = new KruskalsMSFComponent(graph);
        component.findKruskalsMSF();
    }

    // -------------------- COMPONENT --------------------

    private static class KruskalsMSFComponent {

        private final Graph graph;
        private final List<Node> unionFind;

        public KruskalsMSFComponent(Graph graph) {
            this.graph = graph;
            this.unionFind = new ArrayList<>();
        }

        public void findKruskalsMSF() {
            // Get all vertices
            unionFind.addAll(getVertices(graph));

            // Get priority queue
            PriorityQueue<Edge> edgePriorityQueue = getEdgePriorityQueue(graph);

            // Loop to find smallest edge at any given point that doesn't create a cycle
            while (edgePriorityQueue.size() > 0 && unionFind.size() > 1) {
                Edge currentEdge = edgePriorityQueue.poll();
                Node source = null;
                Node destination = null;

                for (Node node : unionFind) {
                    if (node.equals(currentEdge.getSourceVertex())) {
                        source = node;
                    } else if (node.equals(currentEdge.getDestinationVertex())) {
                        destination = node;
                    }
                }

                if (!source.getHead().equals(destination.getHead())) {
                    System.out.println(currentEdge.getSourceVertex().getNodeId() + ", "
                            + currentEdge.getDestinationVertex().getNodeId() + ":"
                            + currentEdge.getWeight());

                    weightedUnion(source, destination);
                }
            }
        }
    }

    // -------------------- DAO --------------------

    private static class GraphDataInput {

        private static final String COMMA = ",";
        private static final String COLON = ":";

        static Graph getGraphFromFile(String graphFilename) {
            // Initialize graph
            Graph graph = new Graph();

            try {
                File file = new File(graphFilename);
                FileReader fileReader = new FileReader(file);
                BufferedReader bufferedReader = new BufferedReader(fileReader);
                String line;
                boolean firstLineRead = false;

                // Read lines
                while ((line = bufferedReader.readLine()) != null) {
                    // First line is extraneous data
                    if (firstLineRead == false) {
                        firstLineRead = true;
                    } else {
                        Node sourceVertex = getSourceVertex(line);
                        Node destinationVertex = getDestinationVertex(line);
                        int edgeWeight = getWeight(line);

                        Edge newEdge = new Edge(sourceVertex, destinationVertex, edgeWeight);

                        addEdge(graph, newEdge);
                    }
                }

                fileReader.close();

            } catch (Exception e) {
                e.printStackTrace();
            }

            return graph;
        }

        // Parses line to get source vertex
        private static Node getSourceVertex(String line) {
            int indexOfComma = line.indexOf(COMMA);
            String nodeID = line.substring(0, indexOfComma);

            return new Node(nodeID);
        }

        // Parses line to get destination vertex
        private static Node getDestinationVertex(String line) {
            int indexOfComma = line.indexOf(COMMA) + 1;
            int indexOfColon = line.indexOf(COLON);
            String nodeID = line.substring(indexOfComma, indexOfColon);

            return new Node(nodeID);
        }

        // Parses line to get edge weight
        private static int getWeight(String line) {
            int indexOfColon = line.indexOf(COLON) + 1;
            return Integer.parseInt(line.substring(indexOfColon));
        }
    }

    // -------------------- MODEL --------------------


    // Edge object class
    private static class Edge implements Comparable<Edge> {

        private final Node sourceVertex;
        private final Node destinationVertex;
        private final int weight;

        Edge(Node sourceVertex, Node destinationVertex, int weight) {
            this.sourceVertex = sourceVertex;
            this.destinationVertex = destinationVertex;
            this.weight = weight;
        }

        Node getSourceVertex() {
            return sourceVertex;
        }

        Node getDestinationVertex() {
            return destinationVertex;
        }

        int getWeight() {
            return weight;
        }

        @Override
        public int compareTo(Edge o) {
            if (sourceVertex.compareTo(o.getSourceVertex()) == 0 && destinationVertex.compareTo(o.getDestinationVertex()) == 0) {
                return 0;
            } else {
                return weight - o.getWeight();
            }
        }
    }

    // Graph object class
    private static class Graph {

        private final Map<Node, Set<Edge>> edgeMap;

        Graph() {
            this.edgeMap = new HashMap<>();
        }

        Map<Node, Set<Edge>> getEdgeMap() {
            return edgeMap;
        }

    }

    // Node object class
    private static class Node implements Comparable<Node> {

        private final String nodeId;
        private Node head;
        private Node tail;
        private Node next;
        private int length;

        Node(String nodeId) {
            this.nodeId = nodeId;
            head = this;
            tail = this;
            next = null;
            this.length = 1;
        }

        String getNodeId() {
            return nodeId;
        }

        Node getHead() {
            return head;
        }

        Node getTail() {
            return tail;
        }

        Node getNext() {
            return next;
        }

        int getLength() {
            return length;
        }

        void setHead(Node newHead) {
            head = newHead;
        }

        void setTail(Node newTail) {
            tail = newTail;
        }

        void setNext(Node newNext) {
            next = newNext;
        }

        void setLength(int newLength) {
            length = newLength;
        }

        @Override
        public int compareTo(Node o) {
            return nodeId.compareTo(o.getNodeId());
        }


        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            Node oNode = (Node) o;
            return nodeId.equals(oNode.getNodeId());
        }

        @Override
        public int hashCode() {
            return nodeId.hashCode();
        }

    }

    // -------------------- UTIL --------------------

    private static void addEdge(Graph graph, Edge edge) {
        // Get edge map
        Map<Node, Set<Edge>> edgeMap = graph.getEdgeMap();

        // Get vertices
        Node sourceVertex = edge.getSourceVertex();
        Node destinationVertex = edge.getDestinationVertex();

        // Add source if not already added
        if (!edgeMap.keySet().contains(sourceVertex)) {
            edgeMap.put(sourceVertex, new HashSet<>());
        }

        // Add destination if not already added
        if (!edgeMap.keySet().contains(destinationVertex)) {
            edgeMap.put(destinationVertex, new HashSet<>());
        }

        edgeMap.get(sourceVertex).add(edge);
    }

    // Gets all vertices
    private static Set<Node> getVertices(Graph graph) {
        return graph.getEdgeMap().keySet();
    }

    // Gets priority queue of all the edges
    private static PriorityQueue<Edge> getEdgePriorityQueue(Graph graph) {
        PriorityQueue<Edge> edgePriorityQueue = new PriorityQueue<>();

        Map<Node, Set<Edge>> edgeMap = graph.getEdgeMap();

        Set<Node> graphNodes = edgeMap.keySet();

        // Go through each node
        for (Node node : graphNodes) {
            Set<Edge> edgeSet = edgeMap.get(node);

            // add each edge
            for (Edge edge : edgeSet) {
                edgePriorityQueue.offer(edge);
            }
        }

        return edgePriorityQueue;
    }

    private static void weightedUnion(Node xNode, Node yNode) {
        // Get heads
        Node xPrime = xNode.getHead();
        Node yPrime = yNode.getHead();

        if (xPrime.equals(yPrime)) return;

        // Make sure the weights are correct
        if (xPrime.getLength() >= yPrime.getLength()) {
            xPrime.getTail().setNext(yPrime);
            Node wNode = yPrime;

            // set all subsequent nodes heads to xPrime
            while (wNode != null) {
                wNode.setHead(xPrime);
                wNode = wNode.getNext();
            }

            // Set new length
            int xPrimeLength = xPrime.getLength();
            int yPrimeLength = yPrime.getLength();
            xPrime.setLength(xPrimeLength + yPrimeLength);

            // Set new tail
            xPrime.setTail(yPrime.getTail());
        } else {
            weightedUnion(yNode, xNode);
        }
    }
}
