#include "context.hpp"

#include <stdexcept>
#include <utility>

#include "number_parts.hpp"

namespace number_interpreter {
namespace {
constexpr string OUT_OF_RANGE_MSG = "Out of context.";

bool isOutOfRange(size_t index, size_t length, const string& str) {
    return (index + length) > str.size();
}
}  // namespace

ContextImage::ContextImage(size_t index, string exp, string sign,
                           string afterDot, string beforeDot)
    : index_(index), exp_(std::move(exp)), sign_(std::move(sign)),
      afterDot_(std::move(afterDot)), beforeDot_(std::move(beforeDot)) {}

Context::Context(string str) : str_(std::move(str)), index_(0) {};

bool Context::isFinished() const {
    return index_ >= str_.size();
}

ContextImage Context::backup() const {
    return ContextImage(index_, exp_, sign_, afterDot_, beforeDot_);
}

string Context::get(size_t length) const {
    if (isFinished() || isOutOfRange(index_, length, str_)) {
        throw std::out_of_range(OUT_OF_RANGE_MSG);
    }
    return str_.substr(index_, length);
}

NumberParts Context::buildNumberParts() const {
    return NumberParts(sign_, beforeDot_, afterDot_, exp_);
}

void Context::next(size_t length) {
    index_ += length;
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
}
}  // namespace number_interpreter
