#ifndef CHATHANDLER_H
#define CHATHANDLER_H

#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Exception.h"
#include "Poco/ThreadPool.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include <iostream>
#include <iostream>
#include <fstream>

using Poco::DateTimeFormat;
using Poco::DateTimeFormatter;
using Poco::ThreadPool;
using Poco::Timestamp;
using Poco::Net::HTMLForm;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerParams;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::NameValueCollection;
using Poco::Net::ServerSocket;
using Poco::Util::Application;
using Poco::Util::HelpFormatter;
using Poco::Util::Option;
using Poco::Util::OptionCallback;
using Poco::Util::OptionSet;
using Poco::Util::ServerApplication;

#include "../../../database/chat.h"
#include "../../../database/user_to_chat.h"
#include "../../../helper.h"
#include "../clients/auth_service_client.h"

class ChatHandler : public HTTPRequestHandler
{
private:
    AuthServiceClient _auth_service_client;
public:
    ChatHandler()
    {
    }

    AuthServiceClient& authServiceClient() {
        return _auth_service_client;
    }

    void handleRequest(HTTPServerRequest &request,
                       HTTPServerResponse &response)
    {
        long user_id = authServiceClient().checkAccess(request);

        if (user_id == AuthServiceClient::NOT_AUTHORIZED) {
            unauthorized(response, "/chat");
            return;
        }

        HTMLForm form(request, request.stream());
        try
        {
            // получить чаты по user_id и получить чат по chat_id
            // GET /chat?chat_id={chat_id}
            // GET /chat?user_id={user_id}
            if (isGet(request)) {
                if (form.has("chat_id")) {
                    auto chat = database::Chat::read_by_id(atol(form.get("chat_id").c_str()));
                    if (chat) {
                        auto jsonChat = chat->toJSON();
                        ok(response, jsonChat);
                    } else {
                        notFound(response, "/chat");
                    }
                    return;
                }

                if (form.has("user_id")) {
                    auto users_to_chats = database::UserToChat::read_chats_by_user_id(atol(form.get("user_id").c_str()));
                    auto content = Poco::JSON::Object::Ptr();
                    
                    Poco::JSON::Array arr;
                    for (auto s : users_to_chats)
                        arr.add(s.toJSON());
                    content->set("chats", arr);
                    ok(response, content);
                    return;
                }

                badRequest(response, "/chat", "do not have valid parameters");
                return;
            }
            // POST /chat
            if (isPost(request)) { // создать чат
                return;
            }
            // PUT /chat?chat_id={chat_id}
            if (isPut(request)) { // обновить чат по chat_id
                if (form.has("chat_id")) {

                }
                return;
            }
        }
        catch (...)
        {
        }

        notFound(response, "/chat");
    }
};
#endif