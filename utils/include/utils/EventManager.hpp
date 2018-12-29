// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUTMANAGER.HPP_____ 
//================================

#ifndef __EVENTMANAGER__HPP
#define __EVENTMANAGER__HPP

#include <map>
#include <set>
#include <iostream>
#include <utils/Observer.hpp>
#include <utils/Observable.hpp>

namespace utils
{


	/// \class EventManager
	/// \brief class defining the event manager.
    template<typename T, typename U>
	class EventManager
	{
			
		public:
		
        EventManager()
        : _observables()
        {
            //_observables.reserve(100);
            //_observables.fill(nullptr);
        }

        ~EventManager() = default;

        inline void attach(Observable<T, U> &target, const T &eventName, Observer<U> *o) {
            if(target.ptr() == nullptr || *(target.ptr()) == nullptr) return;
            target.attach(eventName, o);
			_observables.emplace(target.ptr());
		}

		inline void attach(Observable<T, U> &target, const T &eventName, const std::function<void(const U&)> &action) {
            if(target.ptr() == nullptr || *(target.ptr()) == nullptr) return;
            target.attach(eventName, new Observer<U>(action));
			_observables.emplace(target.ptr());
		}

		inline void update(const T &eventName, const U &target) const {
			for(auto it = _observables.begin(); it != _observables.end(); ++it) {
                if(**it != nullptr)
				    (**it)->notify(eventName, target);
                else
                    delete *it;
			}
		}

		private:
			std::set<Observable<T, U>**> _observables;
	};
}

#endif