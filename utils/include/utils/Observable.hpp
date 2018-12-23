// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ SUBJECT.HPP ___________ 
//================================

#pragma once

#include <set>
#include <algorithm>
#include "Observer.hpp"

namespace utils {
	class Observable {
		public:
            Observable()
            : _observers()
            {};
            ~Observable() = default;

			inline void attach(const AbstractObserver *o) {
                _observers.emplace(o);
            }

            inline void detach() {
                //_observers.erase(event);
            }

            inline void notify() {
                for(auto it = _observers.begin(); it != _observers.end(); ++it) {
                    (*it)->update();
                }
            }

        private:
            std::set<const AbstractObserver*> _observers;

	};
}