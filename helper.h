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
    return request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST;
}

bool isGet(HTTPServerRequest &request) {
    return request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET;
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

bool startswith(const std::string& str, const  std::string& substr) {
    return str.find(substr) == 0;
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
    const std::string& detail,
    const std::string& instance
) {
    Poco::JSON::Object::Ptr root = new Poco::JSON::Object();
    root->set("type", type);
    root->set("title", title);
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
            "request not found",
            type
        )
    );
}

void notFound(HTTPServerResponse &response, const std::string& type, const std::string& msg) {
    createReponse(
        response, Poco::Net::HTTPResponse::HTTPStatus::HTTP_NOT_FOUND, 
        createError(
            "Internal exception",
            "/errors/not_found",
            msg,
            type
        )
    );
}

void unauthorized(HTTPServerResponse &response, const std::string& type) {
    createReponse(
        response, Poco::Net::HTTPResponse::HTTPStatus::HTTP_UNAUTHORIZED, 
        createError(
            "Unauthorized",
            "/errors/unauthorized",
            "Unauthorized",
            type
        )
    );
}

void forbidden(HTTPServerResponse &response, const std::string& type) {
    createReponse(
        response, Poco::Net::HTTPResponse::HTTPStatus::HTTP_FORBIDDEN, 
        createError(
            "Forbidden",
            "/errors/forbidden",
            "Forbidden",
            type
        )
    );
}



void internalServerError(HTTPServerResponse &response, const std::string& type) {
    createReponse(
        response, Poco::Net::HTTPResponse::HTTPStatus::HTTP_INTERNAL_SERVER_ERROR, 
        createError(
            "Internal server Error",
            "/errors/forbidden",
            "Internal server Error",
            type
        )
    );
}



void internalServerError(HTTPServerResponse &response, const std::string& type, const std::string& msg) {
    createReponse(
        response, Poco::Net::HTTPResponse::HTTPStatus::HTTP_INTERNAL_SERVER_ERROR, 
        createError(
            "Internal server Error",
            "/errors/forbidden",
            msg,
            type
        )
    );
}

void ok(HTTPServerResponse &response, Poco::JSON::Object::Ptr& content) {
    createReponse(response, Poco::Net::HTTPResponse::HTTPStatus::HTTP_OK, content);
}