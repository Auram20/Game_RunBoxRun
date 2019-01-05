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
            Observer(const std::function<void(T&)> &action, unsigned int &id)
            : /*AbstractObserver(), */_action(action), _id(id)
            {

            }

            ~Observer() = default;

			void update(T &target) const {
                _action(target);
            }

            inline const unsigned int id() const {
                return _id;
            }

        private:
            const std::function<void(T&)> _action;
            unsigned int _id;
	};

    template<>
	class Observer<void> /*: public AbstractObserver*/ {
		public:
            Observer(const std::function<void(void)> &action, unsigned int &id)
            : /*AbstractObserver(), */_action(action), _id(id)
            {

            }

            ~Observer() = default;

			void update() const {
                _action();
            }

            inline const unsigned int id() const {
                return _id;
            }

        private:
            const std::function<void(void)> _action;
            unsigned int _id;
	};
}
