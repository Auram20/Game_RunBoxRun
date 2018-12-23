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

    class AbstractObserver {
        public:
            AbstractObserver() = default;
            ~AbstractObserver() = default;

            virtual void update() const = 0;
    };


    template<typename T>
	class Observer : public AbstractObserver {
		public:
            Observer(T *target, const std::function<void(T*)> &action)
            : AbstractObserver(), _action(action), _target(target)
            {

            }

            Observer(const Observer &o)
            : AbstractObserver(), _action(o._action), _target(o._target)
            {

            }

			void update() const override {
                if(_target != nullptr)
                _action(_target);
            }

        private:
            const std::function<void(T*)> _action;
            T *_target;
	};
}
