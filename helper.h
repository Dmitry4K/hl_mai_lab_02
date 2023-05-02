#pragma once
#include <string>
#include "Poco/Base64Decoder.h"
#include "Poco/Net/HTTPServerRequest.h"
#include <istream>
#include <ostream>

bool get_identity(const std::string identity, std::string &login, std::string &password)
{
    std::istringstream istr(identity);
    std::ostringstream ostr;
    Poco::Base64Decoder b64in(istr);
    copy(std::istreambuf_iterator<char>(b64in),
         std::istreambuf_iterator<char>(),
         std::ostreambuf_iterator<char>(ostr));
    std::string decoded = ostr.str();

    size_t pos = decoded.find(':');
    login = decoded.substr(0, pos);
    password = decoded.substr(pos + 1);
    return true;
}

bool isPost(HTTPServerRequest &request) {
    return request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET;
}

bool isGet() {
    return request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST;
}

bool isPut() {
    return request.getMethod() == Poco::Net::HTTPRequest::HTTP_PUT;
}

bool idDelete() {
    return request.getMethod() == Poco::Net::HTTPRequest::HTTP_DELETE:
}