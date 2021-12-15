#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        private :

            typedef T           value_type;
            typedef Container   container_type;
            typedef size_t      size_type;

            container_type      _vector;

        public :
            //Member Functions :

            explicit stack (const container_type& ctnr = container_type()) : _vector(ctnr) {}
            
            bool empty() const
            { 
                return (_vector.empty()); 
            }
            
            size_type size() const
            {
                return (_vector.size());
            }
            
            value_type& top()
            {
                return (_vector.back());
            }

            const value_type& top() const
            {
                return (_vector.back());
            }

            void push (const value_type& val)
            {
                _vector.push_back(val);
            }

            void pop()
            {
                _vector.pop_back();
            }
    };
}




#endif