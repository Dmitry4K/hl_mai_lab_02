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

bool isGet(HTTPServerRequest &request) {
    return request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST;
}

bool isPut(HTTPServerRequest &request) {
    return request.getMethod() == Poco::Net::HTTPRequest::HTTP_PUT;
}

bool isDelete(HTTPServerRequest &request) {
    return request.getMethod() == Poco::Net::HTTPRequest::HTTP_DELETE;
}

bool contains(const std::string& str, const std::string& substr) {
    return str.find(substr) != std::string::npos;
}

void createReponse(
    HTTPServerResponse &response,
    Poco::Net::HTTPResponse::HTTPStatus status,
    Poco::JSON::Object::Ptr content
    ) {
        response.setStatus(status);
        response.setChunkedTransferEncoding(true);
        response.setContentType("application/json");
        std::ostream &ostr = response.send();
        Poco::JSON::Stringifier::stringify(content, ostr);
    }

Poco::JSON::Object::Ptr createError(
    const std::string& title,
    const std::string& type,
    Poco::Net::HTTPResponse::HTTPStatus status,
    const std::string& detail,
    const std::string& instance
) {
    Poco::JSON::Object::Ptr root = new Poco::JSON::Object();
    root->set("type", type);
    root->set("title", title);
    root->set("status", status);
    root->set("detail", detail);
    root->set("instance", instance);
    return root;
}

void badRequest(HTTPServerResponse &response, const std::string& type) {
    createReponse(
        response, Poco::Net::HTTPResponse::HTTPStatus::HTTP_BAD_REQUEST, 
        createError(
            "Internal exception",
            "/errors/bad_request",
            Poco::Net::HTTPResponse::HTTPStatus::HTTP_BAD_REQUEST,
            "bad request",
            type
        )
    );
}

void badRequest(HTTPServerResponse &response, const std::string& type, const std::string& reason) {
    createReponse(
        response, Poco::Net::HTTPResponse::HTTPStatus::HTTP_NOT_FOUND, 
        createError(
            "Internal exception",
            "/errors/bad_request",
            Poco::Net::HTTPResponse::HTTPStatus::HTTP_NOT_FOUND,
            reason,
            type
        )
    );
}

void notFound(HTTPServerResponse &response, const std::string& type) {
    createReponse(
        response, Poco::Net::HTTPResponse::HTTPStatus::HTTP_NOT_FOUND, 
        createError(
            "Internal exception",
            "/errors/not_found",
            Poco::Net::HTTPResponse::HTTPStatus::HTTP_NOT_FOUND,
            "request not found",
            type
        )
    );
}

void ok(HTTPServerResponse &response, Poco::JSON::Object::Ptr& content) {
    createReponse(response, Poco::Net::HTTPResponse::HTTPStatus::HTTP_OK, content);
}