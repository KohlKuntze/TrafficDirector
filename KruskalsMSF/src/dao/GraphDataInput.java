package dao;

import model.Edge;
import model.Graph;
import model.Node;
import util.GraphUtilities;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class GraphDataInput {

    private static final String COMMA = ",";
    private static final String COLON = ":";

    public static Graph getGraphFromFile(String graphFilename) {
        Graph graph = new Graph();
        try {
            File file = new File(graphFilename);
            FileReader fileReader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            boolean firstLineRead = false;

            while ((line = bufferedReader.readLine()) != null) {
                if(firstLineRead == false) {
                    firstLineRead = true;
                } else {
                    Node sourceVertex = getSourceVertex(line);
                    Node destinationVertex = getDestinationVertex(line);
                    int edgeWeight = getWeight(line);

                    Edge newEdge = new Edge(sourceVertex, destinationVertex, edgeWeight);

                    GraphUtilities.addEdge(graph, newEdge);
                }
            }

            fileReader.close();

        } catch (Exception e) {
            e.printStackTrace();
        }

        return graph;
    }

    private static Node getSourceVertex(String line) {
        int indexOfComma = line.indexOf(COMMA);
        String nodeID = line.substring(0, indexOfComma);

        return new Node(nodeID);
    }

    private static Node getDestinationVertex(String line) {
        int indexOfComma = line.indexOf(COMMA) + 1;
        int indexOfColon = line.indexOf(COLON);
        String nodeID = line.substring(indexOfComma, indexOfColon);

        return new Node(nodeID);
    }

    private static int getWeight(String line) {
        int indexOfColon = line.indexOf(COLON) + 1;
        return Integer.parseInt(line.substring(indexOfColon));
    }
}
