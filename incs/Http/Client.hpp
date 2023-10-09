#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "./Request/HttpRequest.hpp"
#include <Http/Response/HttpResponse.hpp>
#include <Http/Utils/HttpMethod.hpp>
#include <Server/VirtualServerManager.hpp>
#include <Server/VirtualServer.hpp>
#include <Http/Utils/RouterUtils.hpp>
#include "../../libs/shared_ptr/shared_ptr.hpp"
#include <queue>
#include <Pattern/PatternProcessor.hpp>

class Client{
private:
    std::queue<ft::shared_ptr<HttpRequest> > requests;
    ft::shared_ptr<HttpResponse> response;

public:
    Client();
    void addRequest(ft::shared_ptr<HttpRequest> request);
    bool isRequestEmpty(void);
    int getQueueSize(void);

private:
    PatternType getPatternType(ft::shared_ptr<VirtualServerManager> vsm);
};

#endif