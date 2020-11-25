// --------------- INCLUDES --------------- //

// Project required inclusions
#include "strutils.h"

// Cxx required inclusions
#include <algorithm>
#include <iterator>

namespace StrUtils
{

// ---------------------------------------- //
template <typename OutputIterator>
void getWords(const std::string& in_str,
              OutputIterator     out)
{
    const auto  bgnW = std::find_if_not( in_str.begin(),
                                         in_str.end  (),
                                         [](char c){ return (c == ' '); } );
    const auto  endW = std::find_if    ( bgnW,
                                         in_str.end  (),
                                         [](char c){ return (c == ' '); } );
    if (bgnW != endW )
    {
        *out = std::string( bgnW, endW );
        ++out;
    }
}

// ---------------------------------------- //
std::vector<std::string> split(const std::string& s)
{
    std::istringstream iss(s);
    return std::vector<std::string>((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());
}

// ---------------------------------------- //
std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> l_res;
   std::string              l_cur;
   std::istringstream       l_stream(s);

   while ( std::getline(l_stream, l_cur, delimiter) )
   {
       if ( l_cur.size() > 0 )
       {
            l_res.push_back(l_cur);
       }
   }
   return l_res;
}

// ---------------------------------------- //
bool isPalindrome(const std::string& s)
{
    return ( std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) );
    // return ( s == std::string(s.rbegin(), s.rend() );
}

// ---------------------------------------- //
bool endsWith(const std::string& s,
              const std::string& suffix)
{
    return ( (s.size() >= suffix.size()) &&
             (s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0) );
}

// ---------------------------------------- //
bool beginsWith(const std::string& s,
                const std::string& prefix)
{
    return ( (s.size() >= prefix.size()) &&
             (s.compare(0, prefix.size(), prefix) == 0) );
}

// ---------------------------------------- //
bool replaceFirst(      std::string& str,
                  const std::string& from,
                  const std::string& to )
{
    size_t spos = str.find(from);
    if( spos == std::string::npos ) { return false; }

    str.replace( spos, from.length(), to );
    return true;
}

// ---------------------------------------- //
bool replaceLast(       std::string& str,
                  const std::string& from,
                  const std::string& to )
{
    size_t spos = str.rfind(from);
    if( spos == std::string::npos ) { return false; }

    str.replace( spos, from.length(), to );
    return true;
}

// ---------------------------------------- //
bool replaceAll(        std::string& str,
                  const std::string& from,
                  const std::string& to )
{
    if( from.empty() ) { return false; }
    size_t start_pos = 0;
    while( (start_pos = str.find(from, start_pos)) != std::string::npos )
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }

    return true;
}

// ---------------------------------------- //
void drop_empty(std::vector<std::string>& tokens)
{
    auto last = std::remove_if(tokens.begin(),
                               tokens.end  (),
                               [](const std::string& s){ return s.empty(); });
    tokens.erase(last, tokens.end());
}

// ---------------------------------------- //
std::string repeat(const std::string& str, unsigned n)
{
    std::string result;

    for ( unsigned i = 0; i < n; ++i ) { result += str; }

    return result;
}

}; // Namespace
