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
    template<typename T>
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

        inline void attach(Observable<T> &target, const T &eventName, AbstractObserver *o) {
            if(target.ptr() == nullptr || *(target.ptr()) == nullptr) return;
            target.attach(eventName, o);
			_observables.emplace(target.ptr());
		}

		inline void update(const T &eventName) const {
			for(auto it = _observables.begin(); it != _observables.end(); ++it) {
                if(**it != nullptr)
				    (**it)->notify(eventName);
			}
		}

		private:
			std::set<Observable<T>**> _observables;
	};
}

#endif