#ifndef STRUTILS_H
#define STRUTILS_H

// --------------- INCLUDES --------------- //
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <locale>
#include <memory>
#include <stdexcept>
#include <fstream>
#include <iterator>

namespace StrUtils
{
    // ---------------------------------------- //
    template <typename OutputIterator>
    void getWords(const std::string& in_str,
                  OutputIterator     out);

    // ---------------------------------------- //
    std::vector<std::string> split(const std::string& s);

    // ---------------------------------------- //
    std::vector<std::string> split(const std::string& s, char delimiter);

    // ---------------------------------------- //
    bool isPalindrome(const std::string& s);

    // ---------------------------------------- //
    bool endsWith(const std::string& s,
                  const std::string& suffix);

    // ---------------------------------------- //
    bool beginsWith(const std::string& s,
                    const std::string& prefix);

    // ---------------------------------------- //
    bool replaceFirst(      std::string& str,
                      const std::string& from,
                      const std::string& to );

    // ---------------------------------------- //
    bool replaceLast(       std::string& str,
                      const std::string& from,
                      const std::string& to );

    // ---------------------------------------- //
    bool replaceAll(        std::string& str,
                      const std::string& from,
                      const std::string& to );

    // ---------------------------------------- //
    template <class T>
    inline std::string vector_join( const std::vector<T>& v,
                                    const std::string&    token )
    {
        std::ostringstream l_res;
        for ( auto it = v.begin(); it != v.end();  ++it )
        {
          if ( it != v.begin() )
          {
              l_res << token;
          }
          l_res << *it;
        }

        return l_res.str();
    }


    // ---------------------------------------- //
    static inline void ltrim(std::string &s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
        }));
    }

    // ---------------------------------------- //
    static inline void rtrim(std::string &s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    // ---------------------------------------- //
    static inline void trim(std::string &s)
    {
        ltrim(s);
        rtrim(s);
    }

    // ---------------------------------------- //
    template<typename T>
    static inline std::string toString(T value)
    {
        std::ostringstream ss;
        ss << value;
        return ss.str();
    }

    // ---------------------------------------- //
    static inline void toUpper(std::string& s)
    {
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    }

    // ---------------------------------------- //
    static inline void toLower(std::string& s)
    {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    }

    // ---------------------------------------- //
    template<typename ... Args>
    std::string format( const std::string& format, Args ... args )
    {
        size_t size = snprintf( nullptr, 0, format.c_str(), args ... ) + 1;
        if( size <= 0 )
        {
            throw std::runtime_error( "Error during formatting." );
        }
        std::unique_ptr<char[]> buf( new char[ size ] );
        snprintf( buf.get(), size, format.c_str(), args ... );
        return std::string( buf.get(), buf.get() + size - 1 );
    }

    // ---------------------------------------- //
    void drop_empty(std::vector<std::string> & tokens);

    // ---------------------------------------- //
    std::string repeat(const std::string&, unsigned);

    // ---------------------------------------- //
    template<typename T>
    std::size_t countWords( T& p_input ) {
        return std::distance( std::istream_iterator<std::string>{p_input}, {} );
    }

}; // Namespace StrUtils

#endif // STRUTILS_H
