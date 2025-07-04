#pragma once

#include <string>

#include "number_parts.hpp"

using std::string;

namespace number_interpreter {
class ContextImage {
  public:
    explicit ContextImage(size_t index, string exp, string sign,
                          string afterDot, string beforeDot, bool isInf,
                          bool isNan);

  private:
    size_t index_;
    string exp_;
    string sign_;
    string afterDot_;
    string beforeDot_;
    bool isInf_;
    bool isNan_;

    friend class Context;
};

class Context {
  public:
    explicit Context(string str);

    [[nodiscard]] bool isFinished() const;
    [[nodiscard]] ContextImage backup() const;
    [[nodiscard]] string get(size_t length) const;
    [[nodiscard]] NumberParts buildNumberParts() const;

    void next(size_t length);
    void setExp(string exp);
    void setIsInf(bool isInf);
    void setIsNan(bool isNan);
    void setSign(string sign);
    void setAfterDot(string afterDot);
    void setBeforeDot(string beforeDot);
    void restore(const ContextImage& img);

  private:
    string str_;
    string exp_;
    bool isInf_;
    bool isNan_;
    string sign_;
    size_t index_;
    string afterDot_;
    string beforeDot_;
};
}  // namespace number_interpreter
