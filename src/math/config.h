#ifndef __MATH_CONFIG_H__
#define __MATH_CONFIG_H__

#include <exception>

#define MATH_DEBUG_1_FUNCTION printf("%s\n", __PRETTY_FUNCTION__);

namespace math {
	class DomainError: public std::exception
	{
		public:
			DomainError() {}
			~DomainError() throw() {}
			const char* what() const throw() { return "math domain error"; }

		private:
	};
}

#endif

