import java.util.Objects;

class Edge<T> implements Comparable<Edge<T>> {
  private final double weight;
  private final Disjoint<T> source;
  private final Disjoint<T> destination;
 /**
   * costruttore
   *
   * @param source
   * @param destination
   * @param weight
   */
  public Edge(T source, T destination, double weight) {
    this(new Disjoint<>(source), new Disjoint<>(destination), weight);
  } 

  /**
   * 
   *
   * @param source
   * @param destination
   * @param weight
   */
  public Edge(Disjoint<T> source, Disjoint<T> destination, double weight) {
    this.source = source;
    this.destination = destination;
    this.weight = weight;
  } 

  /**
   * ritorna nodo source
   *
   * @return
   */
  public T getSource() {
    return this.source.getData();
  } 

  /**
   * ritorna nodo destination
   *
   * @return
   */
  public T getDestination() {
    return this.destination.getData();
  } 

  /**
   * metodo che restituisce il peso di un arco
   *
   * @return
   */
  public double getWeight() {
    return this.weight;
  } 


  /**
   * controlla se gli oggetti sono gli stessi
   *
   *
   * @param toCheck
   * @return
   */
  @Override
  @SuppressWarnings("unchecked")
  public boolean equals(Object o) {
    if (o == null)
      return false;
    if (o == this)
      return true;
    if (!(o instanceof Edge<?>))
      return false;

    Edge<T> edgeToCheck = (Edge<T>) o;
    return Objects.equals(this.source, edgeToCheck.source) && Objects.equals(this.destination, edgeToCheck.destination);
  } 

  /**
   * calcola il codice hash dell'arco
   *
   * @return
   */
  @Override
  public int hashCode() {
    return source.hashCode() + (50*destination.hashCode());
  } 

  /**
   * stampa
   *
   * @return
   */
  @Override
  public String toString() {
    return "Edge{Source: " + this.source.toString() + ", Destination: " + this.destination.toString() + ", Weight: "
        + this.weight + "}";
  } 

  /**
   * compare gli archi in base al peso per ordinarli crescentemente
   *
   * @return
   */
  @Override
  public int compareTo(Edge<T> e) {
    if (this.weight <= e.weight) {
      return -1;
    }
    return 1;
  }

} // class
