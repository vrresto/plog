#pragma once
#include <cassert>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <time.h>

#define PLOG_NSTR(x)    x

namespace plog
{
    namespace util
    {
        typedef std::string nstring;
        typedef std::ostringstream nostringstream;
        typedef std::istringstream nistringstream;
        typedef char nchar;


        struct Time
        {
            time_t time;
            unsigned short millitm;
        };


        void ftime(Time* t);
        void localtime_s(struct tm* t, const time_t* time);
        unsigned int gettid();
        std::string processFuncName(const char* func);
        void gmtime_s(struct tm* t, const time_t* time);


        class NonCopyable
        {
        protected:
            NonCopyable()
            {
            }

        private:
            NonCopyable(const NonCopyable&);
            NonCopyable& operator=(const NonCopyable&);
        };


        template<class T>
        class Singleton : NonCopyable
        {
        public:
            Singleton()
            {
                assert(!m_instance);
                m_instance = static_cast<T*>(this);
            }

            ~Singleton()
            {
                assert(m_instance);
                m_instance = 0;
            }

            static T* getInstance()
            {
                return m_instance;
            }

        private:
            static T* m_instance;
        };

        template<class T>
        T* Singleton<T>::m_instance = NULL;
    }
}
