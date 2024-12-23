//
// Created by danilasar on 24.12.2024.
//

#ifndef CPP_04_CROSSROAD_UCPPTR_H
#define CPP_04_CROSSROAD_UCPPTR_H

#include <memory>

namespace Engine {
    namespace Utils {

        template<class T>
        class ucp_ptr {
            std::unique_ptr<T> ptr;
        public:
            ucp_ptr() = default;
            ucp_ptr(T* ptr) :ptr{ ptr }{};
            ucp_ptr(std::unique_ptr<T>&& other) :ptr(std::move(other)){};

            T&        operator*()       { return ptr.get(); }
            T const & operator*()const  { return ptr.get(); }

            T*        operator->()      { return ptr.get(); }
            T const * operator->()const { return ptr.get(); }
        };


    } // Utils
} // Engine

#endif //CPP_04_CROSSROAD_UCPPTR_H
