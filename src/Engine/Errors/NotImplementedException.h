//
// Created by danilasar on 23.12.2024.
//

#ifndef CPP_04_CROSSROAD_NOTIMPLEMENTEDEXCEPTION_H
#define CPP_04_CROSSROAD_NOTIMPLEMENTEDEXCEPTION_H

#include <stdexcept>

namespace Engine {
    namespace Exceptions {
        class NotImplementedException : public std::logic_error {
        private:

            std::string _text;

            NotImplementedException(const char *message, const char *function)
                    :
                    std::logic_error("Not Implemented") {
                _text = message;
                _text += " : ";
                _text += function;
            };

        public:

            NotImplementedException()
                    :
                    NotImplementedException("Not Implemented", __FUNCTION__) {
            }

            NotImplementedException(const char *message)
                    :
                    NotImplementedException(message, __FUNCTION__) {
            }

            virtual const char *what() const throw() {
                return _text.c_str();
            }
        };
    }
}

#endif //CPP_04_CROSSROAD_NOTIMPLEMENTEDEXCEPTION_H
