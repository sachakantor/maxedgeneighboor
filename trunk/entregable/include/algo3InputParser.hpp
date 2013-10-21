#ifndef ALGO3_INPUT_PARSER_H_
#define ALGO3_INPUT_PARSER_H_

#include<iterator>
#include<list>
#include<iostream>
#include<algorithm>

using namespace std;

template<typename T, typename Container = std::list<T> >
class algo3InputParser{
    public:
        /*Constructor y Destructor*/
        algo3InputParser(istream& input);

        /*Metodos publicos*/
        T next();
        void copy_to_container(Container&,const T&);
        void copy_to_container(Container&);
    private:
        std::istream_iterator<T> _input_stream_it;
};

/*Por ser una clase template las implementaciones van aqui*/
template<typename T, typename Container>
algo3InputParser<T,Container>::algo3InputParser(istream& input) : _input_stream_it(input){};

template<typename T, typename Container>
T algo3InputParser<T,Container>::next(){
    T result = *this->_input_stream_it;
    ++this->_input_stream_it;

    return result;
}

template<typename T, typename Container>
void algo3InputParser<T,Container>::copy_to_container(Container& output,const T& termination){
    for(std::back_insert_iterator<Container > back_it (output);
        _input_stream_it != std::istream_iterator<T> () && *_input_stream_it != termination;
        ++_input_stream_it)
        back_it = *_input_stream_it;
}

template<typename T, typename Container>
void algo3InputParser<T,Container>::copy_to_container(Container& output){
    /*Variables Locales*/
    unsigned int dimension_n = *_input_stream_it;
    ++_input_stream_it;
    unsigned int dimension_m = *_input_stream_it;
    //++_input_stream_it;

    /*Comienzo*/
    unsigned int parameters_read = 0;
    while(parameters_read < dimension_n*dimension_m){
        ++_input_stream_it;
        output.push_back(*_input_stream_it);
        ++parameters_read;
    }

    /*Cargo las dimensiones al final*/
    output.push_back(dimension_n);
    output.push_back(dimension_m);

}

#endif //ALGO3_INPUT_PARSER_H_
