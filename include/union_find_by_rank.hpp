#ifndef UNION_FIND_BY_RANK_
#define UNION_FIND_BY_RANK_

#include<stack>
#include<list>
#include<graph.hpp>

using namespace std;

template<class T>
class union_find_set{
    public:
        /*Constructor y destructor */
        union_find_set();
        union_find_set(const union_find_set&);
        union_find_set(const T&);
        //~union_find_set();

        /*Metodos publicos*/
        void union_by_rank(union_find_set&);
        union_find_set& find_set();

        /* Getter (no estrictamente necesario)
         * para el TP, sino para hacer el template
         * correctamente abstrayéndonos de para
         * que lo usaremos luego
         */
        const T& get_element();

        /* Operadores */
        void operator= (const union_find_set&);
        bool operator== (const union_find_set&) const;
        bool operator!= (const union_find_set&) const;

    private:
        /*Metodos privados*/
        void link(union_find_set&);

        /*Atributos*/
        union_find_set* _father;
        unsigned int _rank;
        const T* _element;

        friend class graph;
};

/*Como es un template conviene implemenarlo aqui en lugar de un .cpp*/
template<class T>
union_find_set<T>::union_find_set() : _element(NULL){
    this->_rank = 0;
    this->_father = this;
}

template<class T>
union_find_set<T>::union_find_set(const T& e) : _element(&e){
    this->_rank = 0;
    this->_father = this;
}

template<class T>
union_find_set<T>::union_find_set(const union_find_set& u) : _element(&u._element){
    this->_rank = u._rank;
    this->_father = u._father;
}

template<class T>
const T& union_find_set<T>::get_element(){
    return this->_element;
}

template<class T>
void union_find_set<T>::union_by_rank(union_find_set& y){
    this->find_set().link(y.find_set());
};

template<class T>
void union_find_set<T>::link(union_find_set& y){
    if(this->_rank > y._rank)
        y._father = this;
    else{
        this->_father = &y;
        if(this->_rank == y._rank)
            ++y._rank;
    }
}

template<class T>
union_find_set<T>& union_find_set<T>::find_set(){
    if(this != this->_father && this->_father != this->_father->_father){
        /* Si this no era su propio representate de clase y
         * su padre tampoco lo era, entonces debemos hacer
         * path-compression
         */
        stack<union_find_set*,list<union_find_set*> > to_update;

        /*Guardo todos los sets que deben ser actualizados por path-compresison*/
        union_find_set* representative = this;
        while(representative->_father != representative){
            to_update.push(representative);
            representative = representative->_father;
        }

        /*Comienzo a actualizar todos los sets que guarde*/
        while(!to_update.empty()){
            to_update.top()->_father = representative;
            to_update.pop();
        }
    }

    /* Como "this" hubiera sido el primer elemento de la pila,
     * seguro que ahora esta actualizado si no era su propio
     * representate de equivalencia
     */
    return *this->_father;
}

template<class T>
void union_find_set<T>::operator= (const union_find_set& u){
    this->_father = u._father;
    this->_rank = u._rank;
    this->_element = u._element;
}

template<class T>
bool union_find_set<T>::operator== (const union_find_set& u) const{
    return this->_father == u._father;
}

template<class T>
bool union_find_set<T>::operator!= (const union_find_set& u) const{
    return !(*this == u);
}

#endif //UNION_FIND_BY_RANK_
