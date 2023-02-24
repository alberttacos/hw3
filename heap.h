#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
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

  std::vector<T> heapheap;
  unsigned int _m;
  PComparator _c;

  void heapifyup(int location);
  void heapifydown(int location);
};

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyup(int location){
    if(location == 0){
        return;
    }

    int p = (location + _m - 1)/ _m - 1;

    while(_c(heapheap[location],heapheap[p])&& p >= 0){
        std::swap(heapheap[location],heapheap[p]);
        location = p;
        p = (location + _m - 1)/_m - 1;
        if(p >=(int)heapheap.size() || p<0){
            break;
        }
    }
}

template <typename T, typename PComparator>
 void Heap<T,PComparator>::heapifydown(int location){
    int c = (location + 1) * _m - _m + 1;

    if(c > (int)(Heap<T,PComparator>::size() - 1)){
        return;
    }

    int smallc = c;
    
    for(unsigned int i = 0; i < _m; i++){
        if((c + i)< (int) Heap<T, PComparator>::size() && _c(heapheap[c + i],heapheap[smallc])){
            smallc = c + i;
        }
    }
    if(_c(heapheap[smallc],heapheap[location])){
        std::swap(heapheap[smallc], heapheap[location]);
        heapifydown(smallc);
    }
}


// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
    _m = m;
    _c =c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
    heapheap.push_back(item);
    heapifyup(Heap<T,PComparator>::size()-1);
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
    throw std::underflow_error("Tried to get top of set that was empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heapheap[0];


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
    throw std::underflow_error("Tried to get top of set that was empty");

  }
  std::swap(heapheap[0],heapheap[Heap<T,PComparator>::size()-1]);
  heapheap.pop_back();
  heapifydown(0);
}
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
    if(heapheap.size() == 0){
        return 1;
    }else{
        return 0;
    }
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
    return heapheap.size();
}


#endif
