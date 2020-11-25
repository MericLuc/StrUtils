// Project required includes
#include "strutils.h"

// Cxx required includes
#include <iostream>
#include <string>
#include <vector>

// ---------------------------------------- //
bool tests1( std::string& l_msg )
{
    l_msg = "All tests successfully passed !";
    uint8_t l_num(0);

    if (  (l_num++) && StrUtils::split("word1  word2  "  ) !=
    	std::vector<std::string>{"word1", "word2"} )
    {
        l_msg = "Test 1." + std::to_string(l_num) + " failed !";
    	return false;
    }
    
    if (  (l_num++) && StrUtils::split("  word1  word2  ") !=
    	std::vector<std::string>{"word1", "word2"} )
    {
        l_msg = "Test 1." + std::to_string(l_num) + " failed !";
    	return false;
    }

    if (  (l_num++) && StrUtils::split("  word1  word2") !=
    	std::vector<std::string>{"word1", "word2"} )
    {
        l_msg = "Test 1." + std::to_string(l_num) + " failed !";
    	return false;
    }

    if (  (l_num++) && StrUtils::split("  "              ) !=
    	std::vector<std::string>{                } )
    {
        l_msg = "Test 1." + std::to_string(l_num) + " failed !";
    	return false;
    }

    if (  (l_num++) && StrUtils::split(""                ) !=
    	std::vector<std::string>{                } )
    {
        l_msg = "Test 1." + std::to_string(l_num) + " failed !";
    	return false;
    }

    return true;
}

// ---------------------------------------- //
bool tests2( std::string& l_msg )
{
    l_msg = "All tests successfully passed !";
    uint8_t l_num(0);

    if (  (l_num++) && StrUtils::split("word1     word2  ", ' '  ) !=
        std::vector<std::string>{"word1", "word2"} )
    {
        l_msg = "Test 2." + std::to_string(l_num) + " failed !";
        return false;
    }

    if (  (l_num++) && StrUtils::split("word1:word2: ", ':'  ) !=
        std::vector<std::string>{"word1", "word2", " "} )
    {
        l_msg = "Test 2." + std::to_string(l_num) + " failed !";
        return false;
    }

    return true;
}

// ---------------------------------------- //
bool tests3( std::string& l_msg )
{
    l_msg = "All tests successfully passed !";
    uint8_t l_num(0);

    if (  (l_num++) && !StrUtils::endsWith("le pipeau fonctionne", "nne"  ) )
    {
        l_msg = "Test 3." + std::to_string(l_num) + " failed !";
        return false;
    }

    if (  (l_num++) && StrUtils::endsWith("nne", "onne"  ) )
    {
        l_msg = "Test 3." + std::to_string(l_num) + " failed !";
        return false;
    }

    if (  (l_num++) && !StrUtils::endsWith("nomDeFichier.toto", "toto"  ) )
    {
        l_msg = "Test 3." + std::to_string(l_num) + " failed !";
        return false;
    }

    if (  (l_num++) && !StrUtils::beginsWith("nomDeFichier.toto", "nomD"  ) )
    {
        l_msg = "Test 3." + std::to_string(l_num) + " failed !";
        return false;
    }

    if (  (l_num++) && !StrUtils::beginsWith("  toto", "  "  ) )
    {
        l_msg = "Test 3." + std::to_string(l_num) + " failed !";
        return false;
    }

    if (  (l_num++) && StrUtils::beginsWith("  toto", "t"  ) )
    {
        l_msg = "Test 3." + std::to_string(l_num) + " failed !";
        return false;
    }

    return true;
}

// ---------------------------------------- //
bool tests4( std::string& l_msg )
{
    l_msg = "All tests successfully passed !";
    uint8_t l_num(0);

    std::vector<int> l_vec = { 1, 2, 3, 4};
    std::string      l_res = StrUtils::vector_join(l_vec, ";");
    std::string      l_tok = ";";

    if ( (l_num++) && l_res.compare("1;2;3;4") != 0 )
    {
        std::cout << l_res << std::endl;
        l_msg = "Test 4." + std::to_string(l_num) + " failed !";
        return false;
    }

    l_vec = { 1, 1, -1, 3, 5};
    l_tok = "/*/";
    l_res = StrUtils::vector_join(l_vec, l_tok);

    if (  (l_num++) && l_res.compare("1/*/1/*/-1/*/3/*/5") != 0 )
    {
        l_msg = "Test 4." + std::to_string(l_num) + " failed !";
        return false;
    }

    return true;
}

// ---------------------------------------- //
bool tests5( std::string& l_msg )
{
    l_msg = "All tests successfully passed !";
    uint8_t l_num(0);

    {
        std::string l_res = "   toto ";
        StrUtils::ltrim(l_res);
        if ( (l_num++) && l_res.compare("toto ") != 0 )
        {
            l_msg = "Test 5." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    {
        std::string l_res = "toto ";
        StrUtils::ltrim(l_res);
        if ( (l_num++) && l_res.compare("toto ") != 0 )
        {
            l_msg = "Test 5." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    {
        std::string l_res = "";
        StrUtils::ltrim(l_res);
        if ( (l_num++) && l_res.compare("") != 0 )
        {
            l_msg = "Test 5." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    {
        std::string l_res = "   toto   ";
        StrUtils::rtrim(l_res);
        if ( (l_num++) && l_res.compare("   toto") != 0 )
        {
            l_msg = "Test 5." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    {
        std::string l_res = "   toto   ";
        StrUtils::trim(l_res);
        if ( (l_num++) && l_res.compare("toto") != 0 )
        {
            l_msg = "Test 5." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    return true;
}

// ---------------------------------------- //
bool tests6( std::string& l_msg )
{
    l_msg = "All tests successfully passed !";
    uint8_t l_num(0);

    {
        std::string l_res = "abctoto tutu toto";
        StrUtils::replaceFirst(l_res, "toto", "X");
        if ( (l_num++) && l_res.compare("abcX tutu toto") != 0 )
        {
            l_msg = "Test 6." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    {
        std::string l_res = "abctoto tutu toto toto";
        StrUtils::replaceLast(l_res, " toto", "X");
        if ( (l_num++) && l_res.compare("abctoto tutu totoX") != 0 )
        {
            l_msg = "Test 6." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    {
        std::string l_res = "abcbcbcba";
        StrUtils::replaceAll(l_res, "cb", "");
        if ( (l_num++) && l_res.compare("aba") != 0 )
        {
            l_msg = "Test 6." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    return true;
}

// ---------------------------------------- //
bool tests7( std::string& l_msg )
{
    l_msg = "All tests successfully passed !";
    uint8_t l_num(0);

    {
        std::string l_res = "toto tutu";
        StrUtils::toUpper(l_res);
        if ( (l_num++) && l_res.compare("TOTO TUTU") != 0 )
        {
            l_msg = "Test 7." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    {
        std::string l_res = "";
        StrUtils::toUpper(l_res);
        if ( (l_num++) && l_res.compare("") != 0 )
        {
            l_msg = "Test 7." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    {
        std::string l_res = "TOTo tuTu";
        StrUtils::toLower(l_res);
        if ( (l_num++) && l_res.compare("toto tutu") != 0 )
        {
            l_msg = "Test 7." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    return true;
}

// ---------------------------------------- //
bool tests8( std::string& l_msg )
{
    l_msg = "All tests successfully passed !";
    uint8_t l_num(0);

    {
        std::string l_res = "toto tutu";
        l_res = StrUtils::format("%d %s %d", 1, l_res.c_str(), 2);
        if ( (l_num++) && l_res.compare("1 toto tutu 2") != 0 )
        {
            l_msg = "Test 8." + std::to_string(l_num) + " failed !";
            return false;
        }
    }

    return true;
}

// ---------------------------------------- //
int main()
{
	std::string l_ret;
    bool        l_ok;

    l_ok = tests1(l_ret);
    std::cout << "StrUtils::split(const std::string&) : " << l_ret << std::endl;

    l_ok = l_ok && tests2(l_ret);
    std::cout << "StrUtils::split(const std::string&, char) : " << l_ret << std::endl;

    l_ok = l_ok && tests3(l_ret);
    std::cout << "StrUtils::beginsWith | endsWith : " << l_ret << std::endl;

    l_ok = l_ok && tests4(l_ret);
    std::cout << "StrUtils::vector_join(const std::vector<T>&, const std::string&) : " << l_ret << std::endl;

    l_ok = l_ok && tests5(l_ret);
    std::cout << "StrUtils::trim | ltrim | rtrim : " << l_ret << std::endl;

    l_ok = l_ok && tests6(l_ret);
    std::cout << "StrUtils::replaceFirst | replaceLast | replaceAll : " << l_ret << std::endl;

    l_ok = l_ok && tests7(l_ret);
    std::cout << "StrUtils::toUpper | toLower : " << l_ret << std::endl;

    l_ok = l_ok && tests8(l_ret);
    std::cout << "StrUtils::format : " << l_ret << std::endl;

	return l_ok;
}
