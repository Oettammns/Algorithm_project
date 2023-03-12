import java.io.*;
import java.util.*;

public class Main{

	public static void main(String[] args){
        /*creiamo un oggetto Grafo con tipo reale string*/
        Graph<String> graphObject = new Graph<>();
        if(args.length < 1){
            System.out.println("Give file's name first!");
            System.exit(1);
        }
        File file = new File(args[0]);
        String cur_line = "";//cur_line will hold our single field and then in a while loop we can                  //split it
        String [] content = new String[0];
        //creiamo due nodi Disjoint 
        String nodo = "";
        String nodo2 = "";
       int i=0;
        try{
                //leggiamo dal file, mettiamo in nodo la partenza, nodo2 la destinazione
                //creiamo ed aggiungiamo un arco con i due nodi e la distanza tra i due
                BufferedReader br = new BufferedReader(new FileReader(file));
                while((cur_line = br.readLine()) != null ){
                    content = cur_line.split(",");
                    //take each node and add edge.
                    nodo = content[0];
                    nodo2 = content[1];
                    graphObject.biDirectional = false;
                    graphObject.addEdge(nodo, nodo2, Double.parseDouble(content[2]));
                    
                    
                }

        }catch(FileNotFoundException e){
                e.printStackTrace();
                System.out.println("Could not find file!");
        }
        catch(IOException e){
                e.printStackTrace();
        }
        //contiamo numero di vertici e di archi e km coperti dal grafo
        System.out.println(graphObject.countVertices());
        
        System.out.println("Running Kruskal on this graph...");
        Kruskal<String> krus = new Kruskal<>(graphObject);
        krus.calcResults();
        System.out.println(krus.countEdges());

        System.out.println("Cammino minimo del grafo: " + Math.round(krus.getResultWeight()) + "\n");
    }

}
