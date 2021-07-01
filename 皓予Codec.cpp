#include <sstream>
#include "function.h"



class Reverse : public BaseCodec {
public:
    virtual std::string encode(const std::string &input) override {
        std::string output = input;
        int len = output.length();
        for (int i = 0; i < len/2; i++) {
            char tmp = output[i];
            output[i] = output[len-i-1];
            output[len-i-1] = tmp;
        }
        return output;
    }
};
class Compress : public BaseCodec {
public:
    virtual std::string encode(const std::string &input) override {
        std::string output;
        int len = input.length();
        int idx = 0;
        while (idx < len) {
            if (input[idx] != input[idx+1]) {
                output.push_back(input[idx]);
                idx++;
            }else if (input[idx] != input[idx+2]) {
                output.push_back(input[idx]);
                output.push_back(input[idx+1]);
                idx += 2;
            }else {
                std::stringstream ss;
                std::string s;
                int count = 1;
                while (input[idx] == input[++idx]) {
                    count++;
                }
                ss << count;
                ss >> s;
                output.append(s);
                output.push_back(input[idx-1]);
            }
        }
        return output;
    }
};
class Delay : public BaseCodec {
public:
    Delay(): last("None") {}
    virtual std::string encode(const std::string &input) override {
        std::string ret = last;
        last = input;
        return ret;
    }
private:
    std::string last;
};

BaseCodec* getCodec(const std::string& name) {
    BaseCodec* ret;
    if (name == "Reverse") {
        ret = new Reverse;
    }else if (name == "Compress") {
        ret = new Compress;
    }else if (name == "Delay") {
        ret = new Delay;
    }
    return ret;
}
