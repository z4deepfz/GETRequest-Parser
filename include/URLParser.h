#ifndef URLPARSER_H
#define URLPARSER_H

#include <map>
#include <boost/xpressive/xpressive.hpp>
#include <iostream>

/// Standard URL format： protocol :// hostname[:port] / path / [;parameters][?query]#fragment

/// data structure
struct URLinfo
{
    typedef std::string str_t;
    typedef std::map<str_t,str_t> map;
    str_t  Protocal;       /// 协议
    str_t  HostName;       /// 主机名
    str_t  Port;           /// 端口
    str_t  Path;           /// 路径
    map    GetReqMap;      /// Get请求列表
    str_t  Fragment;       /// 页面锚点编号
};

class URLParser
{
    public:
        URLParser();
        URLParser(const std::string &s);
        virtual ~URLParser();


        /// public API
        void SetURL(const std::string &s);      /// 通过 字符串 设置URL
        void SetURL(const URLinfo& u);          /// 通过 URLinfo 设置URL
        bool IsLegalURL() const;
        std::string GetURL() const;             /// 返回修改过的URL
        URLinfo GetParsedURLinfo() const;       /// 返回解析后的信息

    protected:
        /// internal data
        std::string URLstr;     /// URL
        std::pair<std::string,std::string> parseSingleGetReq(const std::string& s) const;

    private:
        /// regex Core
        const boost::xpressive::sregex url_rex =
            !((boost::xpressive::s1= boost::xpressive::icase("http") | boost::xpressive::icase("https"))
                    >> boost::xpressive::icase("://"))
            >> (boost::xpressive::s2= +~(boost::xpressive::set='/',':'))
            >> !(boost::xpressive::icase(":") >> (boost::xpressive::s3=*boost::xpressive::digit) )
            >> !(boost::xpressive::s4= *~(boost::xpressive::set='#','\\','?') )
            >> !(boost::xpressive::icase("?") >> (boost::xpressive::s5= *~(boost::xpressive::set='#')) )
            >> !(boost::xpressive::icase("#") >> (boost::xpressive::s6= *boost::xpressive::digit) )
        ;
        /// regex to split Get requests
        const boost::xpressive::sregex spGetReq = boost::xpressive::icase("&");
};

#endif // URLPARSER_H
