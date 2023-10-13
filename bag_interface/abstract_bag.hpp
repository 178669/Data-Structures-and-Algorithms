#ifndef ABSTRACT_BAG_HPP
#define ABSTRACT_BAG_HPP

#include <cstdlib>

//TODO
    template<typename T> class AbstractBag
        {
            public:
              

                virtual std::size_t getCurrentSize() const=0;

                virtual bool isEmpty() const=0;

                virtual bool add(const T& entry)=0;

                virtual bool remove(const T& entry)=0;

                virtual void clear()=0;

                virtual std::size_t getFrequencyOf(const T& entry) const=0;

                virtual bool contains(const T& entry) const=0;

                static const std::size_t MAXSIZE = 100;
                
            private: 
                // implementation using fixed automatic storage
                std::size_t size;
                
                T data[MAXSIZE];
        };

#endif