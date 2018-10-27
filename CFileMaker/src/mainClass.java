
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class mainClass {



    private static List<String> getFilenames(String filename) {
        PriorityQueue<String> cFileNames = new PriorityQueue<>();
        try {
            File file = new File(filename);
            FileReader fileReader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            StringBuffer stringBuffer = new StringBuffer();
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                cFileNames.offer(line);
                stringBuffer.append("\n");
            }
            fileReader.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        ArrayList<String> cFilenames = new ArrayList<>();

        while (cFileNames.size() > 0) {
            String cFilename = cFileNames.poll();
            System.out.println(cFilename);
            cFilenames.add(cFilename);

        }

        return cFilenames;
    }

    private static void makeMakefile(List<String> cFileNames, String outputFilename) {
        List<String> oFiles = new ArrayList<>();
        List<String> cFiles = new ArrayList<>();

        for(int i = 0; i < cFileNames.size(); i++) {
            String currentFilename = cFileNames.get(i) + ".o";
            oFiles.add(currentFilename);
        }

        for(int i = 0; i < cFileNames.size(); i++) {
            String currentFilename = cFileNames.get(i) + ".c";
            cFiles.add(currentFilename);
        }

        try {
            Writer fileWriter = new FileWriter(outputFilename);

            fileWriter.write("all: lab4\n\n");
            System.out.println("all: lab4\n\n");

            fileWriter.write("lab4: main.o");
            System.out.println("lab4: main.o");
            for(int i = 0; i < oFiles.size(); i++) {
                String currentString = " " + oFiles.get(i);
                System.out.println(currentString);
                fileWriter.write(currentString);
            }

            System.out.println("\n");
            System.out.println("\tgcc main.o");

            for(int i = 0; i < oFiles.size(); i++) {
                String currentString = " " + oFiles.get(i);
                System.out.println(currentString);
                fileWriter.write(currentString);
            }

            System.out.println(" -o lab4\n");

            System.out.println("\n");

            fileWriter.write("main.o: main.c lab4.h\n");
            fileWriter.write("\tgcc -ansi -pedantic -c main.c\n\n");
            for(int i = 0; i < oFiles.size(); i++) {
                fileWriter.write(oFiles.get(i) + ": " + cFiles.get(i) + " lab4.h\n");
                fileWriter.write("\tgcc -ansi -pedantic -c " + cFiles.get(i) + "\n\n");
            }

            fileWriter.write("clean:\n");
            fileWriter.write("\trm -rf *.o lab4");
            fileWriter.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public static void main(String[] args) {
        List<String> cFileNames = getFilenames("/Users/kohlkuntze/Documents/Workspaces/CFileMaker/src/cFileNames");
        makeMakefile(cFileNames, "/Users/kohlkuntze/Documents/Workspaces/CFileMaker/src/Makefile");
    }
}
