#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
using namespace std;

template <typename T, typename PComparator = less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  vector<T> items;
  int n;
  PComparator c;
  int parent(int i) const;
  int leftChild(int i) const;
  void trickleUp(int i);
  void trickleDown(int i);
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int i, PComparator p) : n(i), c(p){}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return items.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return items.size();
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::parent(int i) const{
  return (i-1)/n;
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::leftChild(int i) const{
  return n*i+1;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int i){
  int p = parent(i);
  while(i>0 && c(items[i], items[p])){
    swap(items[i], items[p]);
    i = p;
    p = parent(i);
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int i){
  int firstChild = leftChild(i);
  while(firstChild < int(items.size())){
    int priority = firstChild;
    for(int j = 1; j < n; j++){
      int child = firstChild + j;
      if(child < int(items.size())){
        if(c(items[child], items[priority])) {
          priority = child;
        }
      }
    }
    if(c(items[priority], items[i])){
      swap(items[i], items[priority]);
      i = priority;
      firstChild = leftChild(i);
    }
    else break;
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  items.push_back(item);
  trickleUp(items.size()-1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw underflow_error("Heap is empty!");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw underflow_error("Heap is empty!");
  }
  int size = items.size();
  items[0] = items[size-1];
  items.pop_back();
  
  if(empty() == false){
    trickleDown(0);
  }
}



#endif

