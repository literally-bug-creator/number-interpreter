#pragma once

#include <string>

#include "number_parts.hpp"

using std::string;

class Context {
  public:
    explicit Context(string str);

    [[nodiscard]] bool isFinished() const;
    [[nodiscard]] size_t getCurrentIndex() const;
    [[nodiscard]] string get(size_t index) const;
    [[nodiscard]] NumberParts buildNumberParts() const;

    void next();
    void setExp(string exp);
    void setSign(string sign);
    void setAfterDot(string afterDot);
    void setBeforeDot(string beforeDot);

  private:
    string str_;
    string exp_;
    string sign_;
    size_t index_;
    string afterDot_;
    string beforeDot_;
};
