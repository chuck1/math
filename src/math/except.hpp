#ifndef __MATH_EXCEPT_HPP__
#define __MATH_EXCEPT_HPP__

namespace math {
	namespace except {
		class domain: public std::exception {
			public:
				domain() {}
				~domain() throw() {}
				const char* what() const throw() { return "math domain error"; }

			private:
		};
	}
}

#endif

