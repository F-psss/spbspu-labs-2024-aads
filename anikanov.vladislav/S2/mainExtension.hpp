#ifndef MAINEXTENSION_HPP
#define MAINEXTENSION_HPP

#include <string>
#include "elementOfExpression.hpp"
#include "queue.hpp"
#include "operation.hpp"

using elementType = std::shared_ptr< anikanov::ElementOfExpression >;

bool checkPriority(const elementType &first, const std::shared_ptr< anikanov::Operation > &second);

bool checkForward(const elementType &element);

anikanov::Queue< std::shared_ptr< anikanov::ElementOfExpression > > toPostfix(const std::string &expression);

#endif
