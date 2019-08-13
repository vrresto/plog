#pragma once
#include <plog/Appenders/IAppender.h>
#include <plog/Util.h>
#include <iostream>

namespace plog
{
    template<class Formatter>
    class ConsoleAppender : public IAppender
    {
    public:
        ConsoleAppender() : m_isatty(!!isatty(fileno(stdout))) {}

        virtual void write(const Record& record)
        {
            util::nstring str = Formatter::format(record);
            util::MutexLock lock(m_mutex);

            writestr(str);
        }

    protected:
        void writestr(const util::nstring& str)
        {
            std::cout << str << std::flush;
        }

    private:

    protected:
        util::Mutex m_mutex;
        const bool  m_isatty;
    };
}
