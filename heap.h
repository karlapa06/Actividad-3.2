#include <string>
#include <sstream>
#include <iostream>

using namespace std; 

template <class T>
class Priority_Queue{
    private: 
    T *data; 
    int size; 
    int count; 

    public:
    Priority_Queue(int);
    ~Priority_Queue();

    bool full() const;
    bool empty() const;
        

    int parent(int) const;
    int left(int) const;
    int right(int) const;

    void swap(int, int);
    void pushDown(int);

    void push (T); 
    void pop ();
    T top(); 
    void empty (); 
    int size () const; 
    string toString() const;

}; 

template <class T>
Priority_Queue<T>::Priority_Queue(int size){
    size = size; 
    data = new T(size); 
    count = 0;
}

template <class T>
Priority_Queue<T>::~Priority_Queue(){
    delete [] = data;
    data = Null; 
    size = 0; 
    count = 0;
}

template <class T>
bool Priority_Queue<T>::full() const{
    return (count == size);
}

template <class T>
bool Priority_Queue<T>::empty() const{
    return (count == 0);
}

template <class T>
int Priority_Queue<T>::parent(int pos) const{
    return ((pos-1)/2);
}

template <class T>
int Priority_Queue<T>::left(int pos) const{
    return ((pos*2)+1);
}

template <class T>
int Priority_Queue<T>::right(int pos) const{
    return ((pos*2)+2);
}

template <class T>
void Priority_Queue<T>::swap(int i,int j) {
    T aux = data[i]; 
    data[i]=data[j]; 
    data[j]= aux;
}

template <class T>
void Priority_Queue<T>::pushDown(int pos) {
    int izquierda = left (pos);
    int derecha = right (pos); 
    int min = pos;

    if (izquierda < count && data[izquierda] > data[min]){
        min = izquierda;
    }
    if (derecha < count && data[derecha] > data[min]){
        min = derecha;
    }

    if(min != pos){
        swap(pos, min);
        pushDown(min);
    }
}

template <class T>
void Priority_Queue<T>::push(T val){
    int = pos; 
    if ( full()){
        throw overflow_error (); 
    }
    pos  = count; 
    count++; 
    while (pos>0 &6 val > data(pos)){
        data [pos]=data[parent(pos)];
        pos = parent (pos);
    }
    data [pos]= val;

}

template <class T>
void Priority_Queue<T>::pop(){
    data [0]=data[--count]; 
    pushDown(0);
    
}

template <class T>
void Priority_Queue<T>::empty(){
    count = 0;
    
}

template <class T>
int Priority_Queue<T>::size() const{
    return count;
}

template<class T>
T Priority_Queue<T>::top(){
    return data[0];
}

template <class T>
string Priority_Queue<T>::toString() const {
	std::stringstream aux;

	aux << "[";
	for (uint i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
	aux << data[i];
	}
	aux << "]";
	return aux.str();
}















