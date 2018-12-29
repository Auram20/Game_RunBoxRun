// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ OBSERVER.HPP ___________ 
//================================

#pragma once

#include <cstdlib>
#include <functional>
#include <memory>

namespace utils {

    /*class AbstractObserver {
        public:
            AbstractObserver() = default;
            virtual ~AbstractObserver() = default;

            virtual void update(void *target) const = 0;
    };*/


    template<typename T>
	class Observer /*: public AbstractObserver*/ {
		public:
            Observer(const std::function<void(const T&)> &action)
            : /*AbstractObserver(), */_action(action)
            {

            }

            ~Observer() = default;

			void update(const T &target) const /*override*/ {
                _action(target);
            }

        private:
            const std::function<void(const T&)> _action;
	};
}
