#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>



namespace ft{
    
    //template < class T, class Alloc = allocator<T> >
    class vector{
        private:

        public:
        //vector (const allocator_type& alloc = allocator_type())
        vector(){std::cout << "hello MTF\n";};
        ~vector(){std::cout <<"By\n";};
    };
}

#endif