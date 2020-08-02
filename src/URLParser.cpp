#include "URLParser.h"

URLParser::URLParser()
{
    //ctor
}

URLParser::URLParser(const std::string& s)
{
    SetURL(s);
}

URLParser::~URLParser()
{
    //dtor
}

void URLParser::SetURL(const std::string& s)
{
    URLstr = s;
}

void URLParser::SetURL(const URLinfo& u)
{
    std::string s;
    /// 从URLinfo结构体重构URL
    /// 1. 填写协议，如果有协议要追加 【://】
    if(u.Protocal.size() > 0){
        s = u.Protocal + "://";
    }

    /// 2. 填写域名和端口，原样照抄，追加【/】
    s += u.HostName;
    if(u.Port.size() > 0){
        s += ":" + u.Port;
    }

    /// 3. 路径照抄
    s += u.Path;

    /// 4. 如果有请求，则追加【？】后再逐个追加，如果有多个则用&分割
    auto& m = u.GetReqMap;
    if(m.size() > 0){
        //s += "?" + m.begin()->first + "=" + m.begin()->second;
        for(auto i=m.begin(); i!=m.end(); ++i){
            s += (i==m.begin()?"?":"&") + i->first + "=" + i->second;
        }
    }

    /// 5. 锚点，如果有则追加【#锚点】
    if(u.Fragment.size() > 0){
        s += "#" + u.Fragment;
    }

    /// return
    URLstr = s;
    return;
}

URLinfo URLParser::GetParsedURLinfo() const
{
    /// create tmp structures
    URLinfo r;
    boost::xpressive::smatch what;

    /// match the regex and get values
    if( ! boost::xpressive::regex_match(URLstr, what, url_rex) ){
        throw "Bad regular expression";
    }
    auto uproto  = what[1].str();
    auto uhost   = what[2].str();
    auto uport   = what[3].str();
    auto upath   = what[4].str();
    auto ureq    = what[5].str();
    auto ufrag   = what[6].str();

    /// split the requests and push them into the vector
    boost::xpressive::sregex_token_iterator it(ureq.begin(), ureq.end(), spGetReq, -1);
    for(boost::xpressive::sregex_token_iterator end; it!=end; ++it){
        auto par = parseSingleGetReq(*it);
        r.GetReqMap[par.first] = par.second;
    }

    /// 添加其余信息(protocal, hostname, port, path, frag)
    r.Protocal = uproto;
    r.HostName = uhost;
    r.Port     = uport;
    r.Path     = upath;
    r.Fragment = ufrag;

    return r;
}

std::pair<std::string,std::string> URLParser::parseSingleGetReq(const std::string& s) const
{
    auto p = s.find('=');
    return std::make_pair(s.substr(0, p), s.substr(p+1));
}

bool URLParser::IsLegalURL() const
{
    boost::xpressive::smatch what;
    return boost::xpressive::regex_match(URLstr, what, url_rex);
}

std::string URLParser::GetURL() const { return URLstr; }
