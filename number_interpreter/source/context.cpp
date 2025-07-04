#include "context.hpp"

#include <utility>

#include "exceptions.hpp"
#include "number_parts.hpp"

namespace number_interpreter {
namespace {
bool isOutOfString(const string& str, size_t index) {
    return index > str.size();
}
}  // namespace

ContextImage::ContextImage(size_t index, string exp, string sign,
                           string afterDot, string beforeDot, bool isInf, bool isNan)
    : index_(index), exp_(std::move(exp)), sign_(std::move(sign)),
      afterDot_(std::move(afterDot)), beforeDot_(std::move(beforeDot)),
      isInf_(isInf), isNan_(isNan) {}

Context::Context(string str)
    : str_(std::move(str)), isInf_(false), isNan_(false), index_(0) {}

bool Context::isFinished() const {
    return index_ >= str_.size();
}

ContextImage Context::backup() const {
    return ContextImage(index_, exp_, sign_, afterDot_, beforeDot_, isInf_, isNan_);
}

string Context::get(size_t length) const {
    if (isFinished() || isOutOfString(str_, index_ + length)) {
        throw OutOfRangeException();
    }
    return str_.substr(index_, length);
}

NumberParts Context::buildNumberParts() const {
    return NumberParts(sign_, beforeDot_, afterDot_, exp_, isInf_, isNan_);
}

void Context::next(size_t length) {
    index_ += length;
}

void Context::setIsInf(bool isInf) {
    isInf_ = isInf;
}

void Context::setIsNan(bool isNan) {
    isNan_ = isNan;
}

void Context::setExp(string exp) {
    exp_ = std::move(exp);
}

void Context::setSign(string sign) {
    sign_ = std::move(sign);
}

void Context::setAfterDot(string afterDot) {
    afterDot_ = std::move(afterDot);
}

void Context::setBeforeDot(string beforeDot) {
    beforeDot_ = std::move(beforeDot);
}

void Context::restore(const ContextImage& img) {
    index_ = img.index_;
    exp_ = img.exp_;
    sign_ = img.sign_;
    afterDot_ = img.afterDot_;
    beforeDot_ = img.beforeDot_;
    isInf_ = img.isInf_;
    isNan_ = img.isNan_;
}
}  // namespace number_interpreter
