#pragma once

#include "http_request.h"

#include <string_view>
#include <map>
#include <vector>


using namespace std;

class Stats {
public:
    Stats();

    void AddMethod(string_view method);
    void AddUri(string_view uri);
    const map<string_view, int>& GetMethodStats() const;
    const map<string_view, int>& GetUriStats() const;

private:
    map<string_view, int> uris;
    map<string_view, int> methods;
};

HttpRequest ParseRequest(string_view line);

vector<string_view> SplitIntoWords(string_view line);
